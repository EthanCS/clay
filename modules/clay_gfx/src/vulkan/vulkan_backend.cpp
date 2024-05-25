#include <clay_gfx/resource.h>
#include <clay_core/log.h>
#include <clay_core/macro.h>
#include <clay_gfx/vulkan/vulkan_backend.h>
#include <clay_gfx/vulkan/vulkan_utils.h>
#include <vulkan/vk_enum_string_helper.h>
#include <SDL.h>
#include <SDL_vulkan.h>
#include <flecs.h>

namespace clay
{
namespace gfx
{
static VkBool32 debug_utils_callback(VkDebugUtilsMessageSeverityFlagBitsEXT      severity,
                                     VkDebugUtilsMessageTypeFlagsEXT             types,
                                     const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
                                     void*                                       user_data)
{
    switch (severity)
    {
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
            CLAY_LOG_VERBOSE("{}", callback_data->pMessage);
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
            CLAY_LOG_INFO("{}", callback_data->pMessage);
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
            CLAY_LOG_WARNING("{}", callback_data->pMessage);
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
            CLAY_LOG_ERROR("{}", callback_data->pMessage);
            break;
        default:
            break;
    }
    return VK_FALSE;
}

VkDebugUtilsMessengerCreateInfoEXT create_debug_utils_messenger_info()
{
    VkDebugUtilsMessengerCreateInfoEXT creation_info = { VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT };
    creation_info.pfnUserCallback                    = debug_utils_callback;
    creation_info.messageSeverity                    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    creation_info.messageType                        = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;

    return creation_info;
}

VulkanBackend::VulkanBackend(BackendType::Enum type_)
    : RenderBackend(type_)
    , world(flecs::world())
    , instance(VK_NULL_HANDLE)
    , device(VK_NULL_HANDLE)
    , physical_device(VK_NULL_HANDLE)
    , surface(VK_NULL_HANDLE)
{
}

bool VulkanBackend::init(const RenderBackendCreateDesc& desc)
{
    CLAY_LOG_INFO("Initializing Vulkan backend...");

    //////// Init Vulkan instance.
    VkApplicationInfo app_info  = {};
    app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName   = desc.app_name == nullptr ? "Clay Default Game" : desc.app_name;
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName        = "Clay";
    app_info.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    app_info.apiVersion         = VK_API_VERSION_1_3;

    std::vector<const char*> extensions = vulkan_get_extension_names(desc.debug);
    std::vector<const char*> layers     = vulkan_get_layer_names(desc.debug);

    VkInstanceCreateInfo create_info    = {};
    create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo        = &app_info;
    create_info.enabledExtensionCount   = static_cast<uint32_t>(extensions.size());
    create_info.ppEnabledExtensionNames = extensions.data();
    create_info.enabledLayerCount       = static_cast<uint32_t>(layers.size());
    create_info.ppEnabledLayerNames     = layers.data();

    if (desc.debug)
    {
        VkDebugUtilsMessengerCreateInfoEXT debug_info = create_debug_utils_messenger_info();
        create_info.pNext                             = &debug_info;
    }

    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
    CLAY_ASSERT(result == VK_SUCCESS, "Failed to create Vulkan instance. ({})", string_VkResult(result));

    //////// Init debug utils.
    if (desc.debug)
    {
        u32 num_instance_extensions;
        vkEnumerateInstanceExtensionProperties(nullptr, &num_instance_extensions, nullptr);
        std::vector<VkExtensionProperties> extensions(num_instance_extensions);
        vkEnumerateInstanceExtensionProperties(nullptr, &num_instance_extensions, extensions.data());
        for (usize i = 0; i < num_instance_extensions; i++)
        {
            if (!strcmp(extensions[i].extensionName, VK_EXT_DEBUG_UTILS_EXTENSION_NAME))
            {
                debug_utils_enabled = true;
                break;
            }
        }

        if (debug_utils_enabled)
        {
            // Create new debug utils callback
            auto vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
            auto debug_messenger_create_info    = create_debug_utils_messenger_info();
            vkCreateDebugUtilsMessengerEXT(instance, &debug_messenger_create_info, nullptr, &debug_utils_messenger);
        }
        else
        {
            CLAY_LOG_WARNING("Debug utils extension not found. Debug messages will not be displayed.");
        }
    }

    //////// Pick physcial device.
    physical_device = VK_NULL_HANDLE;
    {
        uint32_t physical_device_count = 0;
        vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
        CLAY_ASSERT(physical_device_count > 0, "No Vulkan physical devices found.");

        std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
        vkEnumeratePhysicalDevices(instance, &physical_device_count, physical_devices.data());

        VkPhysicalDevice adapter = VK_NULL_HANDLE;
        if (desc.device_id != u32_MAX)
        {
            CLAY_LOG_INFO("Try to create device with id: {}", desc.device_id);
            bool bFoundDevice = false;
            for (const auto& device : physical_devices)
            {
                VkPhysicalDeviceProperties properties;
                vkGetPhysicalDeviceProperties(device, &properties);
                if (desc.device_id == properties.deviceID)
                {
                    adapter      = device;
                    bFoundDevice = true;
                    break;
                }
            }

            if (!bFoundDevice) { CLAY_LOG_INFO("Preferred device not found. Automatically select device."); }
        }

        if (adapter == VK_NULL_HANDLE)
        {
            adapter = physical_devices[0];
        }

        physical_device = adapter;
    }
    CLAY_ASSERT(physical_device != VK_NULL_HANDLE, "Failed to select Vulkan physical device.");

    //////// Create logical device.
    if (physical_device != VK_NULL_HANDLE)
    {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(physical_device, &properties);
        CLAY_LOG_INFO("Selected GPU: {}, Device ID: {}, Driver Version: {}", properties.deviceName, properties.deviceID, properties.driverVersion);

        //////// Handle queue families.
        u32 queue_family_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_family_count, nullptr);
        CLAY_ASSERT(queue_family_count > 0, "No Vulkan queue families found.");
        std::vector<VkQueueFamilyProperties> queue_family_properties(queue_family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_family_count, queue_family_properties.data());

        u32 main_queue_family_index = u32_MAX, transfer_queue_family_index = u32_MAX, compute_queue_family_index = u32_MAX, present_queue_family_index = u32_MAX;
        u32 compute_queue_index = u32_MAX;
        for (u32 fi = 0; fi < queue_family_count; ++fi)
        {
            VkQueueFamilyProperties queue_family = queue_family_properties[fi];

            if (queue_family.queueCount == 0) { continue; }

            // Search for main queue that should be able to do all work (graphics, compute and transfer)
            if ((queue_family.queueFlags & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT)) == (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT))
            {
                main_queue_family_index = fi;

                if (queue_family.queueCount > 1)
                {
                    compute_queue_family_index = fi;
                    compute_queue_index        = 1;
                }

                continue;
            }

            // Search for another compute queue if graphics queue exposes only one queue
            if ((queue_family.queueFlags & VK_QUEUE_COMPUTE_BIT) && compute_queue_index == u32_MAX)
            {
                compute_queue_family_index = fi;
                compute_queue_index        = 0;
            }

            // Search for transfer queue
            if ((queue_family.queueFlags & VK_QUEUE_COMPUTE_BIT) == 0 && (queue_family.queueFlags & VK_QUEUE_TRANSFER_BIT))
            {
                transfer_queue_family_index = fi;
                continue;
            }
        }

        const float             queue_priority[] = { 1.0f, 1.0f };
        VkDeviceQueueCreateInfo queue_info[3]    = {};
        u32                     queue_count      = 0;

        VkDeviceQueueCreateInfo& main_queue = queue_info[queue_count++];
        main_queue.sType                    = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        main_queue.queueFamilyIndex         = main_queue_family_index;
        main_queue.queueCount               = compute_queue_family_index == main_queue_family_index ? 2 : 1;
        main_queue.pQueuePriorities         = queue_priority;

        if (compute_queue_family_index != main_queue_family_index)
        {
            VkDeviceQueueCreateInfo& compute_queue = queue_info[queue_count++];
            compute_queue.queueFamilyIndex         = compute_queue_family_index;
            compute_queue.sType                    = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            compute_queue.queueCount               = 1;
            compute_queue.pQueuePriorities         = queue_priority;
        }

        if (transfer_queue_family_index < queue_family_count)
        {
            VkDeviceQueueCreateInfo& transfer_queue_info = queue_info[queue_count++];
            transfer_queue_info.sType                    = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            transfer_queue_info.queueFamilyIndex         = transfer_queue_family_index;
            transfer_queue_info.queueCount               = 1;
            transfer_queue_info.pQueuePriorities         = queue_priority;
        }

        //////// Handle device extensions.
        std::vector<const char*> device_extensions;
        device_extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

        //////// Create VKDevice.
        VkDeviceCreateInfo device_info      = {};
        device_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        device_info.queueCreateInfoCount    = queue_count;
        device_info.pQueueCreateInfos       = queue_info;
        device_info.enabledExtensionCount   = device_extensions.size();
        device_info.ppEnabledExtensionNames = device_extensions.data();

        result = vkCreateDevice(physical_device, &device_info, nullptr, &device);
        CLAY_ASSERT(result == VK_SUCCESS, "Failed to create Vulkan logical device. ({})", string_VkResult(result));

        //////// Get queues.
        graphics_queue.family_index = main_queue_family_index;
        vkGetDeviceQueue(device, main_queue_family_index, 0, &graphics_queue.queue);
        present_queue = graphics_queue;

        compute_queue.family_index = compute_queue_family_index;
        vkGetDeviceQueue(device, compute_queue_family_index, compute_queue_index, &compute_queue.queue);

        transfer_queue.family_index = transfer_queue_family_index;
        vkGetDeviceQueue(device, transfer_queue_family_index, 0, &transfer_queue.queue);
    }

    //////// Init debug utils function pointers.
    if (debug_utils_enabled)
    {
        pfn_SetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectNameEXT");
        pfn_CmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkCmdBeginDebugUtilsLabelEXT");
        pfn_CmdEndDebugUtilsLabelEXT   = (PFN_vkCmdEndDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkCmdEndDebugUtilsLabelEXT");
    }

    //////// Create surface
    SDL_Window* window = static_cast<SDL_Window*>(desc.window);
    if (SDL_Vulkan_CreateSurface(window, instance, &surface) == SDL_FALSE)
    {
        CLAY_ASSERT(false, "Failed to create Vulkan surface.");
    }

    //////// Create swapchain
    VkBool32 is_surface_support = false;
    vkGetPhysicalDeviceSurfaceSupportKHR(physical_device, graphics_queue.family_index, surface, &is_surface_support);
    CLAY_ASSERT(is_surface_support, "Surface is not supported by the selected physical device.");
    if (is_surface_support)
    {
        swapchain.init(&world, device, physical_device, surface, desc.width, desc.height, desc.format, desc.vsync);
    }

    return true;
}

void VulkanBackend::device_wait_idle()
{
    vkDeviceWaitIdle(device);
}

void VulkanBackend::queue_wait_idle(QueueType::Enum queue_type)
{
    switch (queue_type)
    {
        case QueueType::Graphics:
            vkQueueWaitIdle(graphics_queue.queue);
            break;
        case QueueType::Present:
            vkQueueWaitIdle(present_queue.queue);
            break;
        case QueueType::Compute:
            vkQueueWaitIdle(compute_queue.queue);
            break;
        case QueueType::Transfer:
            vkQueueWaitIdle(transfer_queue.queue);
            break;
        default:
            break;
    }
}

FenceHandle VulkanBackend::create_fence(bool signal)
{
    VkFenceCreateInfo create_info = {};
    create_info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    create_info.flags             = signal ? VK_FENCE_CREATE_SIGNALED_BIT : 0;

    VkFence  fence  = VK_NULL_HANDLE;
    VkResult result = vkCreateFence(device, &create_info, nullptr, &fence);

    if (result != VK_SUCCESS)
    {
        CLAY_LOG_ERROR("Failed to create Vulkan fence. ({})", string_VkResult(result));
        return FenceHandle::Invalid;
    }
    else
    {
        flecs::entity fence_entity = world.entity();
        fence_entity.set<VulkanFence>({ .fence = fence });
        return FenceHandle{ .id = fence_entity.id() };
    }
}

void VulkanBackend::wait_for_fence(const FenceHandle& fence, bool wait_all, u64 timeout)
{
    if (fence == FenceHandle::Invalid) { return; }
    flecs::entity entity = flecs::entity(world.m_world, fence.id);
    if (!entity.is_alive() || !entity.has<VulkanFence>()) { return; }
    vkWaitForFences(device, 1, &entity.get<VulkanFence>()->fence, wait_all, timeout);
}

void VulkanBackend::wait_for_fences(const FenceHandle* fences, int num_fence, bool wait_all, u64 timeout)
{
    if (num_fence == 0) { return; }
    std::vector<VkFence> vk_fences;
    vk_fences.reserve(num_fence);
    for (int i = 0; i < num_fence; i++)
    {
        flecs::entity entity = flecs::entity(world.m_world, fences[i].id);
        if (!entity.is_alive() || !entity.has<VulkanFence>()) { continue; }
        vk_fences.push_back(entity.get<VulkanFence>()->fence);
    }
    vkWaitForFences(device, vk_fences.size(), vk_fences.data(), wait_all, timeout);
}

void VulkanBackend::destroy_fence(const FenceHandle& fence)
{
    if (fence == FenceHandle::Invalid) { return; }
    flecs::entity entity = flecs::entity(world.m_world, fence.id);
    if (!entity.is_alive() || !entity.has<VulkanFence>()) { return; }
    vkDestroyFence(device, entity.get<VulkanFence>()->fence, nullptr);
    entity.destruct();
}

SemaphoreHandle VulkanBackend::create_semaphore()
{
    VkSemaphoreCreateInfo create_info = {};
    create_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkSemaphore semaphore = VK_NULL_HANDLE;
    VkResult    result    = vkCreateSemaphore(device, &create_info, nullptr, &semaphore);

    if (result != VK_SUCCESS)
    {
        CLAY_LOG_ERROR("Failed to create Vulkan semaphore. ({})", string_VkResult(result));
        return SemaphoreHandle::Invalid;
    }
    else
    {
        flecs::entity semaphore_entity = world.entity();
        semaphore_entity.set<VulkanSemaphore>({ .semaphore = semaphore });
        return SemaphoreHandle{ .id = semaphore_entity.id() };
    }
}

void VulkanBackend::destroy_semaphore(const SemaphoreHandle& semaphore)
{
    if (semaphore == SemaphoreHandle::Invalid) { return; }
    flecs::entity entity = flecs::entity(world.m_world, semaphore.id);
    if (!entity.is_alive() || !entity.has<VulkanSemaphore>()) { return; }
    vkDestroySemaphore(device, entity.get<VulkanSemaphore>()->semaphore, nullptr);
    entity.destruct();
}

VulkanBackend::~VulkanBackend()
{
    vkDestroySwapchainKHR(device, swapchain.swapchain, nullptr);
    vkDestroySurfaceKHR(instance, surface, nullptr);

    if (debug_utils_messenger != VK_NULL_HANDLE)
    {
        auto vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        vkDestroyDebugUtilsMessengerEXT(instance, debug_utils_messenger, nullptr);
    }

    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
}
} // namespace gfx
} // namespace clay
