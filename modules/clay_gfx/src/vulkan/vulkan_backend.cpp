#include <vector>

#include <SDL.h>
#include <SDL_vulkan.h>

#include <clay_core/log.h>
#include <clay_core/macro.h>

#define VMA_IMPLEMENTATION
#include <clay_gfx/resource.h>
#include <clay_gfx/vulkan/vulkan_backend.h>
#include <clay_gfx/vulkan/vulkan_utils.h>

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

static inline VmaMemoryUsage to_vma_memory_usage(const MemoryUsage::Enum& usage)
{
    VmaMemoryUsage vma_usage = VMA_MEMORY_USAGE_UNKNOWN;
    switch (usage)
    {
        case MemoryUsage::GpuOnly:
            vma_usage = VMA_MEMORY_USAGE_GPU_ONLY;
            break;
        case MemoryUsage::CpuToGpu:
            vma_usage = VMA_MEMORY_USAGE_CPU_TO_GPU;
            break;
        case MemoryUsage::GpuToCpu:
            vma_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
            break;
        case MemoryUsage::CpuOnly:
            vma_usage = VMA_MEMORY_USAGE_CPU_ONLY;
            break;
    }
    return vma_usage;
}

VkDebugUtilsMessengerCreateInfoEXT create_debug_utils_messenger_info()
{
    VkDebugUtilsMessengerCreateInfoEXT creation_info = { VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT };
    creation_info.pfnUserCallback                    = debug_utils_callback;
    creation_info.messageSeverity                    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    creation_info.messageType                        = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;

    return creation_info;
}

bool VulkanBackend::init(const InitBackendOptions& desc)
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

    VkDebugUtilsMessengerCreateInfoEXT debug_info = {};
    if (desc.debug)
    {
        debug_info        = create_debug_utils_messenger_info();
        create_info.pNext = &debug_info;
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

    //////// Init VMA.
    {
        VmaAllocatorCreateInfo allocator_info = {};
        allocator_info.physicalDevice         = physical_device;
        allocator_info.device                 = device;
        allocator_info.instance               = instance;

        VkResult r = vmaCreateAllocator(&allocator_info, &vma_allocator);
        if (r != VK_SUCCESS)
        {
            CLAY_LOG_ERROR("Failed to create VMA allocator. ({})", string_VkResult(r));
            return false;
        }
    }

    ////////  Create Descriptor Pools
    {
        VkDescriptorPoolSize pool_sizes[] = {
            { VK_DESCRIPTOR_TYPE_SAMPLER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, MAX_GLOBAL_POOL_ELEMENTS },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, MAX_GLOBAL_POOL_ELEMENTS }
        };
        u32 pool_sizes_count = sizeof(pool_sizes) / sizeof((pool_sizes)[0]);

        VkDescriptorPoolCreateInfo pool_info = {};
        pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        pool_info.flags                      = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
        pool_info.maxSets                    = MAX_GLOBAL_POOL_ELEMENTS * pool_sizes_count;
        pool_info.poolSizeCount              = pool_sizes_count;
        pool_info.pPoolSizes                 = pool_sizes;

        VkResult r = vkCreateDescriptorPool(device, &pool_info, nullptr, &descriptor_pool);
        if (r != VK_SUCCESS)
        {
            CLAY_LOG_ERROR("Failed to create Vulkan descriptor pool. ({})", string_VkResult(r));
            return false;
        }
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
        CLAY_LOG_ERROR("Failed to create Vulkan surface.");
        return false;
    }

    return true;
}

void VulkanBackend::shutdown()
{
    resources.destroy(device, vma_allocator);

    vkDestroySurfaceKHR(instance, surface, nullptr);

    if (debug_utils_messenger != VK_NULL_HANDLE)
    {
        auto vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        vkDestroyDebugUtilsMessengerEXT(instance, debug_utils_messenger, nullptr);
    }

    vmaDestroyAllocator(vma_allocator);
    vkDestroyDescriptorPool(device, descriptor_pool, nullptr);

    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);

    CLAY_LOG_INFO("Vulkan backend shutdown.");
}

void VulkanBackend::queue_submit(QueueType::Enum queue_type, const QueueSubmitOptions options)
{
    VkQueue queue = get_queue(queue_type);
    if (queue == VK_NULL_HANDLE) [[unlikely]] { return; }

    std::vector<VkCommandBuffer> command_buffers;
    command_buffers.reserve(options.num_command_buffers);
    for (int i = 0; i < options.num_command_buffers; i++)
    {
        const VulkanCommandBuffer* vulkan_command_buffer = resources.command_buffers.get(options.command_buffers[i]);
        if (vulkan_command_buffer == nullptr) [[unlikely]] { continue; }
        command_buffers.push_back(vulkan_command_buffer->command_buffer);
    }

    std::vector<VkSemaphore> signal_semaphores;
    signal_semaphores.reserve(options.num_signal_semaphores);
    for (int i = 0; i < options.num_signal_semaphores; i++)
    {
        const VulkanSemaphore* vulkan_semaphore = resources.semaphores.get(options.signal_semaphores[i]);
        if (vulkan_semaphore == nullptr) [[unlikely]] { continue; }
        signal_semaphores.push_back(vulkan_semaphore->semaphore);
    }

    std::vector<VkSemaphore> wait_semaphores;
    wait_semaphores.reserve(options.num_wait_semaphores);
    for (int i = 0; i < options.num_wait_semaphores; i++)
    {
        const VulkanSemaphore* vulkan_semaphore = resources.semaphores.get(options.wait_semaphores[i]);
        if (vulkan_semaphore == nullptr) [[unlikely]] { continue; }
        wait_semaphores.push_back(vulkan_semaphore->semaphore);
    }

    VkPipelineStageFlags waitStages[] = { to_vk_pipeline_stage_flags(options.wait_dst_stage) };

    VkSubmitInfo submit_info         = {};
    submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount   = command_buffers.size();
    submit_info.pCommandBuffers      = command_buffers.data();
    submit_info.signalSemaphoreCount = signal_semaphores.size();
    submit_info.pSignalSemaphores    = signal_semaphores.data();
    submit_info.waitSemaphoreCount   = wait_semaphores.size();
    submit_info.pWaitSemaphores      = wait_semaphores.data();
    submit_info.pWaitDstStageMask    = waitStages;

    const VulkanFence* vulkan_fence = resources.fences.get(options.fence);
    VkFence            fence        = vulkan_fence != nullptr ? vulkan_fence->fence : VK_NULL_HANDLE;

    vkQueueSubmit(queue, 1, &submit_info, fence);
}

SwapchainStatus::Enum VulkanBackend::queue_present(const QueuePresentOptions& options)
{
    VkPresentInfoKHR present_info = {};
    present_info.sType            = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    std::vector<VkSemaphore> wait_semaphores;
    wait_semaphores.reserve(options.num_wait_semaphores);
    for (int i = 0; i < options.num_wait_semaphores; i++)
    {
        const VulkanSemaphore* vulkan_semaphore = resources.semaphores.get(options.wait_semaphores[i]);
        if (vulkan_semaphore == nullptr) [[unlikely]] { continue; }
        wait_semaphores.push_back(vulkan_semaphore->semaphore);
    }

    present_info.waitSemaphoreCount = wait_semaphores.size();
    present_info.pWaitSemaphores    = wait_semaphores.data();

    const VulkanSwapchain* swapchain = resources.swapchains.get(options.swapchain);
    if (swapchain == nullptr) [[unlikely]] { return SwapchainStatus::Error; }

    VkSwapchainKHR swapchains[] = { swapchain->swapchain };
    present_info.swapchainCount = 1;
    present_info.pSwapchains    = swapchains;
    present_info.pImageIndices  = &options.image_index;

    VkQueue  queue  = get_queue(QueueType::Present);
    VkResult result = vkQueuePresentKHR(queue, &present_info);

    if (result == VK_SUCCESS) [[likely]] { return SwapchainStatus::Success; }
    else if (result == VK_ERROR_OUT_OF_DATE_KHR) { return SwapchainStatus::OutOfDate; }
    else if (result == VK_SUBOPTIMAL_KHR) { return SwapchainStatus::Suboptimal; }
    else
    {
        CLAY_LOG_ERROR("Failed to present Vulkan swapchain image. ({})", string_VkResult(result));
        return SwapchainStatus::Error;
    }
}

Handle<Swapchain> VulkanBackend::create_swapchain(const CreateSwapchainOptions& options)
{
    VkBool32 is_surface_support = false;
    vkGetPhysicalDeviceSurfaceSupportKHR(physical_device, graphics_queue.family_index, surface, &is_surface_support);

    if (!is_surface_support)
    {
        CLAY_LOG_ERROR("Surface is not supported by the selected physical device.");
        return Handle<Swapchain>::invalid();
    }

    u32 format_count;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, nullptr);
    std::vector<VkSurfaceFormatKHR> formats = std::vector<VkSurfaceFormatKHR>(format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, formats.data());

    VkSurfaceFormatKHR surface_format = VkSurfaceFormatKHR{ .format = VK_FORMAT_B8G8R8A8_UNORM, .colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };
    for (const auto& f : formats)
    {
        if (f.format == to_vk_format(options.format))
        {
            surface_format = f;
            break;
        }
    }

    VkSurfaceCapabilitiesKHR surface_capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &surface_capabilities);

    VkSurfaceTransformFlagBitsKHR pre_transform = surface_capabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR ? VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR : surface_capabilities.currentTransform;

    u32 desired_image_count = surface_capabilities.minImageCount + 1;
    if (surface_capabilities.maxImageCount > 0 && desired_image_count > surface_capabilities.maxImageCount)
    {
        desired_image_count = surface_capabilities.maxImageCount;
    }

    VkExtent2D extent = surface_capabilities.currentExtent;
    if (surface_capabilities.currentExtent.width == u32_MAX)
    {
        extent.width  = options.width;
        extent.height = options.height;
    }

    std::vector<VkPresentModeKHR> present_mode_preference;
    if (options.vsync)
    {
        present_mode_preference.push_back(VK_PRESENT_MODE_FIFO_RELAXED_KHR);
        present_mode_preference.push_back(VK_PRESENT_MODE_FIFO_KHR);
    }
    else
    {
        present_mode_preference.push_back(VK_PRESENT_MODE_MAILBOX_KHR);
        present_mode_preference.push_back(VK_PRESENT_MODE_IMMEDIATE_KHR);
    }

    u32 present_mode_count;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, nullptr);
    std::vector<VkPresentModeKHR> present_modes = std::vector<VkPresentModeKHR>(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, present_modes.data());

    VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
    for (const auto& p : present_mode_preference)
    {
        if (std::find(present_modes.begin(), present_modes.end(), p) != present_modes.end())
        {
            present_mode = p;
            break;
        }
    }

    VkSwapchainCreateInfoKHR create_info = {};
    create_info.sType                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    create_info.imageUsage               = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    create_info.imageSharingMode         = VK_SHARING_MODE_EXCLUSIVE;
    create_info.clipped                  = VK_TRUE;
    create_info.imageArrayLayers         = 1;
    create_info.compositeAlpha           = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    create_info.surface                  = surface;
    create_info.imageFormat              = surface_format.format;
    create_info.imageColorSpace          = surface_format.colorSpace;
    create_info.imageExtent              = extent;
    create_info.minImageCount            = desired_image_count;
    create_info.preTransform             = pre_transform;
    create_info.presentMode              = present_mode;
    create_info.oldSwapchain             = VK_NULL_HANDLE;

    VulkanSwapchain swapchain = {};

    VkResult result = vkCreateSwapchainKHR(device, &create_info, nullptr, &swapchain.swapchain);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create swapchain! ({})", string_VkResult(result));
        return Handle<Swapchain>::invalid();
    }

    // Fetch swapchain images and create image views
    {
        vkGetSwapchainImagesKHR(device, swapchain.swapchain, &swapchain.image_count, nullptr);
        std::vector<VkImage> swapchain_images = std::vector<VkImage>(swapchain.image_count);
        vkGetSwapchainImagesKHR(device, swapchain.swapchain, &swapchain.image_count, swapchain_images.data());

        for (int i = 0; i < swapchain.image_count; i++)
        {
            VulkanTexture texture{ .image = swapchain_images[i], .format = surface_format.format, .width = extent.width, .height = extent.height };
            swapchain.images[i] = resources.textures.push(texture);
        }
    }

    return resources.swapchains.push(swapchain);
}

SwapchainAcquireResult VulkanBackend::acquire_next_image(const Handle<Swapchain>& h, const AcquireNextImageOptions& options)
{
    const VulkanSwapchain* swapchain = resources.swapchains.get(h);
    if (swapchain == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to acquire Vulkan swapchain image. Swapchain not found.");
        return SwapchainAcquireResult{ .image_index = 0, .status = SwapchainStatus::Error };
    }

    const VulkanSemaphore* vulkan_semaphore = resources.semaphores.get(options.semaphore);
    const VulkanFence*     vulkan_fence     = resources.fences.get(options.fence);

    u32      image_index = 0;
    VkResult result      = vkAcquireNextImageKHR(device, swapchain->swapchain, options.time_out, vulkan_semaphore != nullptr ? vulkan_semaphore->semaphore : VK_NULL_HANDLE, vulkan_fence != nullptr ? vulkan_fence->fence : VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR) { return SwapchainAcquireResult{ .image_index = (u8)image_index, .status = SwapchainStatus::OutOfDate }; }
    else if (result == VK_SUBOPTIMAL_KHR) { return SwapchainAcquireResult{ .image_index = (u8)image_index, .status = SwapchainStatus::Suboptimal }; }
    else if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to acquire Vulkan swapchain image. ({})", string_VkResult(result));
        return SwapchainAcquireResult{ .image_index = (u8)image_index, .status = SwapchainStatus::Error };
    }

    return SwapchainAcquireResult{ .image_index = (u8)image_index, .status = SwapchainStatus::Success };
}

u32 VulkanBackend::get_swapchain_image_count(const Handle<Swapchain>& swapchain)
{
    const VulkanSwapchain* vulkan_swapchain = resources.swapchains.get(swapchain);
    if (vulkan_swapchain == nullptr) [[unlikely]] { return 0; }

    return vulkan_swapchain->image_count;
}

Handle<Texture> VulkanBackend::get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index)
{
    const VulkanSwapchain* vulkan_swapchain = resources.swapchains.get(swapchain);
    if (vulkan_swapchain == nullptr) [[unlikely]] { return Handle<Texture>::invalid(); }

    return vulkan_swapchain->images[index];
}

void VulkanBackend::destroy_swapchain(const Handle<Swapchain>& swapchain)
{
    const VulkanSwapchain* vulkan_swapchain = resources.swapchains.get(swapchain);
    if (vulkan_swapchain == nullptr) [[unlikely]] { return; }

    for (int i = 0; i < vulkan_swapchain->image_count; i++)
    {
        VulkanTexture* texture = resources.textures.get_mut(vulkan_swapchain->images[i]);
        if (texture == nullptr) [[unlikely]] { continue; }

        for (VkImageView view : texture->views)
        {
            vkDestroyImageView(device, view, nullptr);
        }
        texture->views.clear();
        texture->view_descs.clear();

        resources.textures.free(vulkan_swapchain->images[i]);
    }

    vkDestroySwapchainKHR(device, vulkan_swapchain->swapchain, nullptr);
    resources.swapchains.free(swapchain);
}

Handle<Fence> VulkanBackend::create_fence(bool signal)
{
    VkFenceCreateInfo create_info = {};
    create_info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    create_info.flags             = signal ? VK_FENCE_CREATE_SIGNALED_BIT : 0;

    VkFence  fence  = VK_NULL_HANDLE;
    VkResult result = vkCreateFence(device, &create_info, nullptr, &fence);

    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan fence. ({})", string_VkResult(result));
        return Handle<Fence>::invalid();
    }

    return resources.fences.push(VulkanFence{ .fence = fence });
}

void VulkanBackend::wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout)
{
    const VulkanFence* vulkan_fence = resources.fences.get(fence);
    if (vulkan_fence == nullptr) [[unlikely]] { return; }
    vkWaitForFences(device, 1, &vulkan_fence->fence, wait_all, timeout);
}

void VulkanBackend::wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout)
{
    if (num_fence == 0) { return; }

    std::vector<VkFence> vk_fences;
    vk_fences.reserve(num_fence);
    for (int i = 0; i < num_fence; i++)
    {
        const VulkanFence* vulkan_fence = resources.fences.get(fences[i]);
        if (vulkan_fence == nullptr) [[unlikely]] { continue; }
        vk_fences.push_back(vulkan_fence->fence);
    }

    if (!vk_fences.empty())
    {
        vkWaitForFences(device, vk_fences.size(), vk_fences.data(), wait_all, timeout);
    }
}

void VulkanBackend::reset_fences(const Handle<Fence>* fences, int num_fence)
{
    if (num_fence == 0) { return; }

    std::vector<VkFence> vk_fences;
    vk_fences.reserve(num_fence);
    for (int i = 0; i < num_fence; i++)
    {
        const VulkanFence* vulkan_fence = resources.fences.get(fences[i]);
        if (vulkan_fence == nullptr) [[unlikely]] { continue; }
        vk_fences.push_back(vulkan_fence->fence);
    }

    if (!vk_fences.empty())
    {
        vkResetFences(device, vk_fences.size(), vk_fences.data());
    }
}

void VulkanBackend::destroy_fence(const Handle<Fence>& fence)
{
    const VulkanFence* vulkan_fence = resources.fences.get(fence);
    if (vulkan_fence == nullptr) [[unlikely]] { return; }
    vkDestroyFence(device, vulkan_fence->fence, nullptr);
    resources.fences.free(fence);
}

Handle<Semaphore> VulkanBackend::create_semaphore()
{
    VkSemaphoreCreateInfo create_info = {};
    create_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkSemaphore semaphore = VK_NULL_HANDLE;
    VkResult    result    = vkCreateSemaphore(device, &create_info, nullptr, &semaphore);

    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan semaphore. ({})", string_VkResult(result));
        return Handle<Semaphore>::invalid();
    }

    return resources.semaphores.push(VulkanSemaphore{ .semaphore = semaphore });
}

void VulkanBackend::destroy_semaphore(const Handle<Semaphore>& semaphore)
{
    const VulkanSemaphore* vulkan_semaphore = resources.semaphores.get(semaphore);
    if (vulkan_semaphore == nullptr) [[unlikely]] { return; }
    vkDestroySemaphore(device, vulkan_semaphore->semaphore, nullptr);
    resources.semaphores.free(semaphore);
}

Handle<Shader> VulkanBackend::create_shader(const CreateShaderOptions& desc)
{
    VkShaderModuleCreateInfo shader_create_info = {};
    shader_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_create_info.codeSize                 = desc.code_size;
    shader_create_info.pCode                    = reinterpret_cast<const u32*>(desc.code);

    VkShaderModule shader_module;
    VkResult       result = vkCreateShaderModule(device, &shader_create_info, nullptr, &shader_module);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create shader module. ({})", string_VkResult(result));
        return Handle<Shader>::invalid();
    }

    return resources.shaders.push(VulkanShader{ .shader_module = shader_module });
}

void VulkanBackend::destroy_shader(const Handle<Shader>& shader)
{
    const VulkanShader* vulkan_shader = resources.shaders.get(shader);
    if (vulkan_shader == nullptr) [[unlikely]] { return; }
    vkDestroyShaderModule(device, vulkan_shader->shader_module, nullptr);
    resources.shaders.free(shader);
}

Handle<PipelineLayout> VulkanBackend::create_pipeline_layout(const CreatePipelineLayoutOptions& desc)
{
    VkDescriptorSetLayout set_layouts[MAX_DESCRIPTOR_SET_LAYOUTS];
    for (u8 i = 0; i < desc.num_descriptor_set_layouts; i++)
    {
        const VulkanDescriptorSetLayout* layout = resources.descriptor_set_layouts.get(desc.descriptor_set_layouts[i]);
        if (layout == nullptr) [[unlikely]]
        {
            CLAY_LOG_ERROR("Failed to find descriptor set layout!");
            return Handle<PipelineLayout>::invalid();
        }
        set_layouts[i] = layout->layout;
    }

    VkPipelineLayout           pipeline_layout;
    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.pushConstantRangeCount     = 0;
    pipeline_layout_info.pPushConstantRanges        = nullptr;
    pipeline_layout_info.setLayoutCount             = desc.num_descriptor_set_layouts;
    pipeline_layout_info.pSetLayouts                = set_layouts;
    {
        VkResult res = vkCreatePipelineLayout(device, &pipeline_layout_info, nullptr, &pipeline_layout);
        if (res != VK_SUCCESS) [[unlikely]]
        {
            CLAY_LOG_ERROR("Failed to create pipeline layout! ({})", string_VkResult(res));
            return Handle<PipelineLayout>::invalid();
        }
    }

    return resources.pipeline_layouts.push(VulkanPipelineLayout{ .layout = pipeline_layout });
}

void VulkanBackend::destroy_pipeline_layout(const Handle<PipelineLayout>& layout)
{
    const VulkanPipelineLayout* vulkan_layout = resources.pipeline_layouts.get(layout);
    if (vulkan_layout == nullptr) [[unlikely]] { return; }
    vkDestroyPipelineLayout(device, vulkan_layout->layout, nullptr);
    resources.pipeline_layouts.free(layout);
}

Handle<GraphicsPipeline> VulkanBackend::create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc)
{
    VulkanGraphicsPipeline pipeline;
    if (pipeline.init(&resources, device, desc)) [[likely]]
    {
        return resources.graphics_pipelines.push(pipeline);
    }
    return Handle<GraphicsPipeline>::invalid();
}

void VulkanBackend::destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline)
{
    const VulkanGraphicsPipeline* vulkan_pipeline = resources.graphics_pipelines.get(pipeline);
    if (vulkan_pipeline == nullptr) [[unlikely]] { return; }
    vkDestroyPipeline(device, vulkan_pipeline->pipeline, nullptr);
    resources.graphics_pipelines.free(pipeline);
}

Handle<Texture> VulkanBackend::create_texture(const CreateTextureOptions& desc)
{
    VulkanTexture texture = {};
    texture.width         = desc.width;
    texture.height        = desc.height;
    texture.format        = to_vk_format(desc.format);

    VkImageCreateInfo image_info = {};
    image_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType         = to_vk_image_type(desc.texture_type);
    image_info.extent.width      = desc.width;
    image_info.extent.height     = desc.height;
    image_info.extent.depth      = desc.depth;
    image_info.mipLevels         = desc.mip_levels;
    image_info.arrayLayers       = desc.array_size;
    image_info.format            = texture.format;
    image_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
    image_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    image_info.usage             = to_vk_image_usage_flags(desc.usage);
    image_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    image_info.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;

    VmaAllocationCreateInfo memory_info = {};
    memory_info.flags                   = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT;
    memory_info.usage                   = to_vma_memory_usage(desc.memory_usage);

    VmaAllocationInfo allocation_info = {};
    VkResult          res             = vmaCreateImage(vma_allocator, &image_info, &memory_info, &texture.image, &texture.allocation, &allocation_info);

    if (res != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan image. ({})", string_VkResult(res));
        return Handle<Texture>::invalid();
    }

    texture.device_memory = allocation_info.deviceMemory;

    VkImageAspectFlags aspect_flags = VK_IMAGE_ASPECT_COLOR_BIT;
    if (texture.format == VK_FORMAT_D16_UNORM || texture.format == VK_FORMAT_D32_SFLOAT)
    {
        aspect_flags = VK_IMAGE_ASPECT_DEPTH_BIT;
    }
    else if (texture.format == VK_FORMAT_D24_UNORM_S8_UINT)
    {
        aspect_flags = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
    }
    else if (texture.format == VK_FORMAT_S8_UINT)
    {
        aspect_flags = VK_IMAGE_ASPECT_STENCIL_BIT;
    }

    VulkanTextureViewDesc view_desc = {};
    view_desc.format                = texture.format;
    view_desc.aspect_flags          = aspect_flags;
    view_desc.component_r           = VK_COMPONENT_SWIZZLE_IDENTITY;
    view_desc.component_g           = VK_COMPONENT_SWIZZLE_IDENTITY;
    view_desc.component_b           = VK_COMPONENT_SWIZZLE_IDENTITY;
    view_desc.component_a           = VK_COMPONENT_SWIZZLE_IDENTITY;
    view_desc.base_mip_level        = 0;
    view_desc.level_count           = desc.mip_levels;
    view_desc.base_array_layer      = 0;
    view_desc.layer_count           = desc.array_size;

    if (image_info.imageType == VK_IMAGE_TYPE_1D && desc.array_size == 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_1D; }
    else if (image_info.imageType == VK_IMAGE_TYPE_1D && desc.array_size > 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_1D_ARRAY; }
    else if (image_info.imageType == VK_IMAGE_TYPE_2D && desc.array_size == 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_2D; }
    else if (image_info.imageType == VK_IMAGE_TYPE_2D && desc.array_size > 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_2D_ARRAY; }
    else if (image_info.imageType == VK_IMAGE_TYPE_3D && desc.array_size == 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_3D; }
    else if (image_info.imageType == VK_IMAGE_TYPE_3D && desc.array_size > 1) { view_desc.view_type = VK_IMAGE_VIEW_TYPE_CUBE_ARRAY; }

    texture.get_view(device, view_desc);

    return resources.textures.push(texture);
}

u32 VulkanBackend::get_texture_width(const Handle<Texture>& texture)
{
    const VulkanTexture* vulkan_texture = resources.textures.get(texture);
    if (vulkan_texture == nullptr) [[unlikely]] { return 0; }
    return vulkan_texture->width;
}

u32 VulkanBackend::get_texture_height(const Handle<Texture>& texture)
{
    const VulkanTexture* vulkan_texture = resources.textures.get(texture);
    if (vulkan_texture == nullptr) [[unlikely]] { return 0; }
    return vulkan_texture->height;
}

void VulkanBackend::destroy_texture(const Handle<Texture>& texture)
{
    const VulkanTexture* vulkan_texture = resources.textures.get(texture);
    if (vulkan_texture == nullptr) [[unlikely]] { return; }
    vulkan_texture->destroy(device, vma_allocator);
    resources.textures.free(texture);
}

Handle<Sampler> VulkanBackend::create_sampler(const CreateSamplerOptions& desc)
{
    VkSamplerCreateInfo sampler_info     = {};
    sampler_info.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    sampler_info.magFilter               = to_vk_filter(desc.mag_filter);
    sampler_info.minFilter               = to_vk_filter(desc.min_filter);
    sampler_info.mipmapMode              = to_vk_mipmap_mode(desc.mipmap_mode);
    sampler_info.addressModeU            = to_vk_address_mode(desc.address_u);
    sampler_info.addressModeV            = to_vk_address_mode(desc.address_v);
    sampler_info.addressModeW            = to_vk_address_mode(desc.address_w);
    sampler_info.mipLodBias              = desc.mip_lod_bias;
    sampler_info.anisotropyEnable        = (desc.max_anisotropy > 0.0f) ? VK_TRUE : VK_FALSE;
    sampler_info.maxAnisotropy           = desc.max_anisotropy;
    sampler_info.compareEnable           = desc.compare_op != CompareOp::Never;
    sampler_info.compareOp               = to_vk_compare_op(desc.compare_op);
    sampler_info.minLod                  = 0.0f;
    sampler_info.maxLod                  = ((desc.mipmap_mode == MipmapType::Linear) ? FLT_MAX : 0.0f);
    sampler_info.borderColor             = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
    sampler_info.unnormalizedCoordinates = VK_FALSE;

    VkSampler sampler = VK_NULL_HANDLE;
    VkResult  result  = vkCreateSampler(device, &sampler_info, nullptr, &sampler);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan sampler. ({})", string_VkResult(result));
        return Handle<Sampler>::invalid();
    }

    return resources.samplers.push(VulkanSampler{ .sampler = sampler });
}

void VulkanBackend::destroy_sampler(const Handle<Sampler>& sampler)
{
    const VulkanSampler* vulkan_sampler = resources.samplers.get(sampler);
    if (vulkan_sampler == nullptr) [[unlikely]] { return; }
    vkDestroySampler(device, vulkan_sampler->sampler, nullptr);
    resources.samplers.free(sampler);
}

Handle<Buffer> VulkanBackend::create_buffer(const CreateBufferOptions& desc)
{
    VulkanBuffer buffer = {};
    buffer.size         = desc.size;

    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = desc.size;
    buffer_info.usage              = to_vk_buffer_usage_flags(desc.usage);
    buffer_info.sharingMode        = desc.exclusive ? VK_SHARING_MODE_EXCLUSIVE : VK_SHARING_MODE_CONCURRENT;

    VmaAllocationCreateInfo memory_info = {};
    memory_info.flags                   = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT;
    memory_info.usage                   = to_vma_memory_usage(desc.memory_usage);

    VmaAllocationInfo allocation_info = {};
    VkResult          res             = vmaCreateBuffer(vma_allocator, &buffer_info, &memory_info,
                                                        &buffer.buffer, &buffer.allocation, &allocation_info);

    if (res != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan buffer. ({})", string_VkResult(res));
        return Handle<Buffer>::invalid();
    }

    buffer.device_memory = allocation_info.deviceMemory;

    return resources.buffers.push(buffer);
}

void* VulkanBackend::map_buffer(const Handle<Buffer>& buffer)
{
    const VulkanBuffer* vulkan_buffer = resources.buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return nullptr; }

    void* data;
    vmaMapMemory(vma_allocator, vulkan_buffer->allocation, &data);
    return data;
}

void VulkanBackend::unmap_buffer(const Handle<Buffer>& buffer)
{
    const VulkanBuffer* vulkan_buffer = resources.buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }
    vmaUnmapMemory(vma_allocator, vulkan_buffer->allocation);
}

void VulkanBackend::destroy_buffer(const Handle<Buffer>& buffer)
{
    const VulkanBuffer* vulkan_buffer = resources.buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }
    vmaDestroyBuffer(vma_allocator, vulkan_buffer->buffer, vulkan_buffer->allocation);
    resources.buffers.free(buffer);
}

Handle<Framebuffer> VulkanBackend::create_framebuffer(const CreateFramebufferOptions& desc)
{
    u32         num_attachments              = 0;
    VkImageView attachments[MAX_ATTACHMENTS] = {};

    u8 num_colors = desc.render_pass_layout.num_colors();
    for (u8 i = 0; i < num_colors; i++)
    {
        VulkanTexture* vulkan_texture = resources.textures.get_mut(desc.color_attachments[i].texture);
        if (vulkan_texture == nullptr) [[unlikely]] { return Handle<Framebuffer>::invalid(); }
        attachments[num_attachments++] = vulkan_texture->get_view(device, to_vulkan_texture_view_desc(desc.color_attachments[i]));
    }

    if (desc.render_pass_layout.has_depth_stencil())
    {
        VulkanTexture* vulkan_texture = resources.textures.get_mut(desc.depth_stencil_attachment.texture);
        if (vulkan_texture == nullptr) [[unlikely]] { return Handle<Framebuffer>::invalid(); }
        attachments[num_attachments++] = vulkan_texture->get_view(device, to_vulkan_texture_view_desc(desc.depth_stencil_attachment));
    }

    VkFramebufferCreateInfo create_info = {};
    create_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    create_info.renderPass              = resources.get_or_create_render_pass(device, desc.render_pass_layout);
    create_info.attachmentCount         = num_attachments;
    create_info.pAttachments            = attachments;
    create_info.width                   = desc.width;
    create_info.height                  = desc.height;
    create_info.layers                  = 1;

    VkFramebuffer framebuffer = VK_NULL_HANDLE;
    VkResult      result      = vkCreateFramebuffer(device, &create_info, nullptr, &framebuffer);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan framebuffer. ({})", string_VkResult(result));
        return Handle<Framebuffer>::invalid();
    }

    return resources.framebuffers.push(VulkanFramebuffer{ .framebuffer = framebuffer });
}

void VulkanBackend::destroy_framebuffer(const Handle<Framebuffer>& framebuffer)
{
    const VulkanFramebuffer* vulkan_framebuffer = resources.framebuffers.get(framebuffer);
    if (vulkan_framebuffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find framebuffer.");
        return;
    }
    vkDestroyFramebuffer(device, vulkan_framebuffer->framebuffer, nullptr);
    resources.framebuffers.free(framebuffer);
}

Handle<DescriptorSetLayout> VulkanBackend::create_descriptor_set_layout(const CreateDescriptorSetLayoutOptions& desc)
{
    VulkanDescriptorSetLayout layout = {};
    layout.num_bindings              = desc.num_bindings;

    for (u32 i = 0; i < desc.num_bindings; i++)
    {
        layout.bindings[i].binding            = desc.bindings[i].index;
        layout.bindings[i].descriptorType     = to_vk_descriptor_type(desc.bindings[i].type);
        layout.bindings[i].descriptorCount    = desc.bindings[i].count;
        layout.bindings[i].stageFlags         = VK_SHADER_STAGE_ALL;
        layout.bindings[i].pImmutableSamplers = nullptr;

        layout.binding_to_index[desc.bindings[i].index] = i;
    }

    VkDescriptorSetLayoutCreateInfo create_info = {};
    create_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    create_info.bindingCount                    = desc.num_bindings;
    create_info.pBindings                       = layout.bindings;

    VkResult result = vkCreateDescriptorSetLayout(device, &create_info, nullptr, &layout.layout);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan descriptor set layout. ({})", string_VkResult(result));
        return Handle<DescriptorSetLayout>::invalid();
    }

    return resources.descriptor_set_layouts.push(layout);
}

void VulkanBackend::destroy_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout)
{
    const VulkanDescriptorSetLayout* vulkan_layout = resources.descriptor_set_layouts.get(layout);
    if (vulkan_layout == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find descriptor set layout.");
        return;
    }
    vkDestroyDescriptorSetLayout(device, vulkan_layout->layout, nullptr);
    resources.descriptor_set_layouts.free(layout);
}

Handle<DescriptorSet> VulkanBackend::create_descriptor_set(const CreateDescriptorSetOptions& desc)
{
    const VulkanDescriptorSetLayout* vulkan_layout = resources.descriptor_set_layouts.get(desc.layout);
    if (vulkan_layout == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find descriptor set layout.");
        return Handle<DescriptorSet>::invalid();
    }

    VkDescriptorSetAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocate_info.descriptorPool              = descriptor_pool;
    allocate_info.descriptorSetCount          = 1;
    allocate_info.pSetLayouts                 = &vulkan_layout->layout;

    VkDescriptorSet descriptor_set = VK_NULL_HANDLE;
    VkResult        result         = vkAllocateDescriptorSets(device, &allocate_info, &descriptor_set);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan descriptor set. ({})", string_VkResult(result));
        return Handle<DescriptorSet>::invalid();
    }

    return resources.descriptor_sets.push(VulkanDescriptorSet{ .set = descriptor_set, .layout = desc.layout });
}

void VulkanBackend::update_descriptor_set(const Handle<DescriptorSet>& set, const UpdateDescriptorSetOptions& desc)
{
    const VulkanDescriptorSet* vulkan_set = resources.descriptor_sets.get(set);
    if (vulkan_set == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find descriptor set.");
        return;
    }

    const VulkanDescriptorSetLayout* vulkan_layout = resources.descriptor_set_layouts.get(vulkan_set->layout);
    if (vulkan_layout == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find descriptor set layout.");
        return;
    }

    VkWriteDescriptorSet   writes[MAX_DESCRIPTORS_PER_SET];
    VkDescriptorBufferInfo buffer_infos[MAX_DESCRIPTORS_PER_SET];
    VkDescriptorImageInfo  image_infos[MAX_DESCRIPTORS_PER_SET];

    for (u32 i = 0; i < desc.count; i++)
    {
        const UpdateDescriptorSetOptions::Info& info = desc.infos[i];

        u32 binding         = info.binding;
        u32 index_in_layout = vulkan_layout->binding_to_index[binding];

        VkDescriptorSetLayoutBinding vk_binding = vulkan_layout->bindings[index_in_layout];

        VkWriteDescriptorSet& w = writes[i];
        w                       = {};
        w.sType                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        w.dstSet                = vulkan_set->set;
        w.dstBinding            = info.binding;
        w.dstArrayElement       = 0;
        w.descriptorCount       = 1;
        w.descriptorType        = vk_binding.descriptorType;

        switch (vk_binding.descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER: {
                const VulkanBuffer* vulkan_buffer = resources.buffers.get(info.buffer);
                if (vulkan_buffer == nullptr) [[unlikely]] { continue; }

                buffer_infos[i]        = {};
                buffer_infos[i].buffer = vulkan_buffer->buffer;
                buffer_infos[i].offset = 0;
                buffer_infos[i].range  = vulkan_buffer->size;

                w.pBufferInfo = &buffer_infos[i];
            }
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: {
                const VulkanTexture* vulkan_texture = resources.textures.get(info.texture);
                if (vulkan_texture == nullptr) [[unlikely]] { continue; }

                const VulkanSampler* vulkan_sampler = resources.samplers.get(info.sampler);
                if (vulkan_sampler == nullptr) [[unlikely]] { continue; }

                image_infos[i]             = {};
                image_infos[i].imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                image_infos[i].imageView   = vulkan_texture->get_default_view();
                image_infos[i].sampler     = vulkan_sampler->sampler;

                w.pImageInfo = &image_infos[i];
            }
            break;
            default:
                CLAY_LOG_ERROR("Unsupported descriptor type.");
                break;
        }
    }

    vkUpdateDescriptorSets(device, desc.count, writes, 0, nullptr);
}

void VulkanBackend::destroy_descriptor_set(const Handle<DescriptorSet>& set)
{
    const VulkanDescriptorSet* vulkan_set = resources.descriptor_sets.get(set);
    if (vulkan_set == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find descriptor set.");
        return;
    }
    vkFreeDescriptorSets(device, descriptor_pool, 1, &vulkan_set->set);
    resources.descriptor_sets.free(set);
}

Handle<CommandPool> VulkanBackend::create_command_pool(QueueType::Enum queue_type)
{
    u32 family_index = 0;
    switch (queue_type)
    {
        case QueueType::Graphics:
            family_index = graphics_queue.family_index;
            break;
        case QueueType::Transfer:
            family_index = transfer_queue.family_index;
            break;
        case QueueType::Compute:
            family_index = compute_queue.family_index;
            break;
        case QueueType::Present:
            family_index = present_queue.family_index;
            break;
    }

    VkCommandPoolCreateInfo create_info = {};
    create_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = family_index;

    VkCommandPool command_pool = VK_NULL_HANDLE;
    VkResult      result       = vkCreateCommandPool(device, &create_info, nullptr, &command_pool);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create Vulkan command pool. ({})", string_VkResult(result));
        return Handle<CommandPool>::invalid();
    }

    return resources.command_pools.push(VulkanCommandPool{ .command_pool = command_pool, .queue_type = queue_type });
}

void VulkanBackend::destroy_command_pool(const Handle<CommandPool>& pool)
{
    const VulkanCommandPool* vulkan_pool = resources.command_pools.get(pool);
    if (vulkan_pool == nullptr) [[unlikely]] { return; }
    vkDestroyCommandPool(device, vulkan_pool->command_pool, nullptr);
    resources.command_pools.free(pool);
}

Handle<CommandBuffer> VulkanBackend::allocate_command_buffer(const Handle<CommandPool>& pool)
{
    const VulkanCommandPool* vulkan_pool = resources.command_pools.get(pool);
    if (vulkan_pool == nullptr) [[unlikely]] { return Handle<CommandBuffer>::invalid(); }

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandPool                 = vulkan_pool->command_pool;
    allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocate_info.commandBufferCount          = 1;

    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    VkResult        result         = vkAllocateCommandBuffers(device, &allocate_info, &command_buffer);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to allocate Vulkan command buffer. ({})", string_VkResult(result));
        return Handle<CommandBuffer>::invalid();
    }

    return resources.command_buffers.push(VulkanCommandBuffer{ .command_buffer = command_buffer, .pool = pool });
}

void VulkanBackend::reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    vkResetCommandBuffer(vulkan_buffer->command_buffer, release_resource ? VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT : 0);
}

void VulkanBackend::free_command_buffer(const Handle<CommandBuffer>& buffer)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    const VulkanCommandPool*   vulkan_pool   = resources.command_pools.get(vulkan_buffer->pool);
    if (vulkan_buffer == nullptr || vulkan_pool == nullptr) [[unlikely]] { return; }
    vkFreeCommandBuffers(device, vulkan_pool->command_pool, 1, &vulkan_buffer->command_buffer);
    resources.command_buffers.free(buffer);
}

void VulkanBackend::cmd_begin(const Handle<CommandBuffer>& buffer, bool one_time)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    if (one_time) { begin_info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; }
    vkBeginCommandBuffer(vulkan_buffer->command_buffer, &begin_info);
}

void VulkanBackend::cmd_end(const Handle<CommandBuffer>& buffer)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    vkEndCommandBuffer(vulkan_buffer->command_buffer);
}

RenderPassEncoder VulkanBackend::cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return {};
    }

    const VulkanFramebuffer* vulkan_framebuffer = resources.framebuffers.get(options.framebuffer);
    if (vulkan_framebuffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find framebuffer.");
        return {};
    }

    VkRenderPassBeginInfo begin_info = {};
    begin_info.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    begin_info.renderPass            = resources.get_or_create_render_pass(device, options.render_pass_layout);
    begin_info.framebuffer           = vulkan_framebuffer->framebuffer;
    begin_info.renderArea.offset     = { options.offset[0], options.offset[1] };
    begin_info.renderArea.extent     = { options.extent[0], options.extent[1] };
    begin_info.clearValueCount       = 0;
    begin_info.pClearValues          = nullptr;

    if (options.clear)
    {
        u32          num_clear_values = 0;
        VkClearValue clear_values[MAX_ATTACHMENTS];
        u8           num_colors = options.render_pass_layout.num_colors();
        for (u8 i = 0; i < num_colors; i++)
        {
            clear_values[num_clear_values].color = {
                options.clear_values[num_clear_values].color[0],
                options.clear_values[num_clear_values].color[1],
                options.clear_values[num_clear_values].color[2],
                options.clear_values[num_clear_values].color[3]
            };
            num_clear_values++;
        }
        if (options.render_pass_layout.has_depth_stencil())
        {
            clear_values[num_clear_values].depthStencil = {
                options.clear_values[num_clear_values].depth,
                options.clear_values[num_clear_values].stencil
            };
            num_clear_values++;
        }
        begin_info.clearValueCount = num_clear_values;
        begin_info.pClearValues    = clear_values;
    }

    vkCmdBeginRenderPass(vulkan_buffer->command_buffer, &begin_info, VK_SUBPASS_CONTENTS_INLINE);
    return RenderPassEncoder{ .cmd = buffer };
}

void VulkanBackend::cmd_end_render_pass(const Handle<CommandBuffer>& buffer, const RenderPassEncoder& encoder)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    vkCmdEndRenderPass(vulkan_buffer->command_buffer);
}

void VulkanBackend::cmd_bind_pipeline(const RenderPassEncoder& encoder, const Handle<GraphicsPipeline>& pipeline)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(encoder.cmd);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    const VulkanGraphicsPipeline* vulkan_pipeline = resources.graphics_pipelines.get(pipeline);
    if (vulkan_pipeline == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find graphics pipeline.");
        return;
    }

    vkCmdBindPipeline(vulkan_buffer->command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vulkan_pipeline->pipeline);
}

void VulkanBackend::cmd_set_viewport(const RenderPassEncoder& encoder, const CmdSetViewportOptions& viewport)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(encoder.cmd);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    VkViewport vk_viewport = {};
    vk_viewport.x          = viewport.x;
    vk_viewport.y          = viewport.y;
    vk_viewport.width      = viewport.width;
    vk_viewport.height     = viewport.height;
    vk_viewport.minDepth   = viewport.min_depth;
    vk_viewport.maxDepth   = viewport.max_depth;
    vkCmdSetViewport(vulkan_buffer->command_buffer, 0, 1, &vk_viewport);
}

void VulkanBackend::cmd_set_scissor(const RenderPassEncoder& encoder, const CmdSetScissorOptions& scissor)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(encoder.cmd);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    VkRect2D vk_scissor = {};
    vk_scissor.offset   = { scissor.offset[0], scissor.offset[1] };
    vk_scissor.extent   = { scissor.extent[0], scissor.extent[1] };
    vkCmdSetScissor(vulkan_buffer->command_buffer, 0, 1, &vk_scissor);
}

void VulkanBackend::cmd_draw(const RenderPassEncoder& encoder, const CmdDrawOptions& draw)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(encoder.cmd);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    vkCmdDraw(vulkan_buffer->command_buffer, draw.vertex_count, draw.instance_count, draw.first_vertex, draw.first_instance);
}

void VulkanBackend::cmd_draw_indexed(const RenderPassEncoder& encoder, const CmdDrawIndexedOptions& draw)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(encoder.cmd);
    if (vulkan_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    vkCmdDrawIndexed(vulkan_buffer->command_buffer, draw.index_count, draw.instance_count, draw.first_index, draw.vertex_offset, draw.first_instance);
}

void VulkanBackend::cmd_bind_vertex_buffer(const RenderPassEncoder& encoder, const CmdBindVertexBufferOptions& options)
{
    const VulkanCommandBuffer* vk_cb     = resources.command_buffers.get(encoder.cmd);
    const VulkanBuffer*        vk_buffer = resources.buffers.get(options.buffer);
    if (vk_cb == nullptr || vk_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer or buffer.");
        return;
    }

    VkDeviceSize offsets[] = { options.offset };
    vkCmdBindVertexBuffers(vk_cb->command_buffer, options.binding, 1, &vk_buffer->buffer, offsets);
}

void VulkanBackend::cmd_bind_vertex_buffers(const RenderPassEncoder& encoder, const CmdBindVertexBuffersOptions& options)
{
    const VulkanCommandBuffer* vk_cb = resources.command_buffers.get(encoder.cmd);
    if (vk_cb == nullptr || options.buffers == nullptr || options.offsets == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    std::vector<VkDeviceSize> vk_offsets;
    std::vector<VkBuffer>     vk_buffers;
    vk_offsets.reserve(options.binding_count);
    vk_buffers.reserve(options.binding_count);

    for (u32 i = 0; i < options.binding_count; i++)
    {
        const VulkanBuffer* vk_buffer = resources.buffers.get(options.buffers[i]);
        if (vk_buffer == nullptr) [[unlikely]] { continue; }

        vk_offsets.push_back(options.offsets[i]);
        vk_buffers.push_back(vk_buffer->buffer);
    }

    vkCmdBindVertexBuffers(vk_cb->command_buffer, options.first_binding, options.binding_count, vk_buffers.data(), vk_offsets.data());
}

void VulkanBackend::cmd_bind_index_buffer(const RenderPassEncoder& encoder, const CmdBindIndexBufferOptions& options)
{
    const VulkanCommandBuffer* vk_cb     = resources.command_buffers.get(encoder.cmd);
    const VulkanBuffer*        vk_buffer = resources.buffers.get(options.buffer);
    if (vk_cb == nullptr || vk_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer or buffer.");
        return;
    }

    vkCmdBindIndexBuffer(vk_cb->command_buffer, vk_buffer->buffer, options.offset, to_vk_index_type(options.index_type));
}

void VulkanBackend::cmd_bind_descriptor_sets(const RenderPassEncoder& encoder, const CmdBindDescriptorSetsOptions& options)
{
    const VulkanCommandBuffer* vk_cb = resources.command_buffers.get(encoder.cmd);
    if (vk_cb == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    const VulkanPipelineLayout* vk_layout = resources.pipeline_layouts.get(options.layout);
    if (vk_layout == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find pipeline layout.");
        return;
    }

    std::vector<VkDescriptorSet> vk_sets;
    vk_sets.reserve(options.num_sets);
    for (u32 i = 0; i < options.num_sets; i++)
    {
        const VulkanDescriptorSet* vk_set = resources.descriptor_sets.get(options.sets[i]);
        if (vk_set == nullptr) [[unlikely]]
        {
            CLAY_LOG_ERROR("Failed to find descriptor set at {}.", i);
            return;
        }
        vk_sets.push_back(vk_set->set);
    }

    vkCmdBindDescriptorSets(vk_cb->command_buffer, to_vk_pipeline_bind_point(options.bind_point), vk_layout->layout, options.first_set, vk_sets.size(), vk_sets.data(), 0, nullptr);
}

void VulkanBackend::cmd_copy_buffer(const Handle<CommandBuffer>& cb, const CmdCopyBufferOptions& options)
{
    const VulkanCommandBuffer* vk_cb = resources.command_buffers.get(cb);
    if (vk_cb == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    const VulkanBuffer* src_buffer = resources.buffers.get(options.src_buffer);
    const VulkanBuffer* dst_buffer = resources.buffers.get(options.dst_buffer);
    if (src_buffer == nullptr || dst_buffer == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find source or destination buffer.");
        return;
    }

    VkBufferCopy copy_region = {};
    copy_region.srcOffset    = options.src_offset;
    copy_region.dstOffset    = options.dst_offset;
    copy_region.size         = options.size;

    vkCmdCopyBuffer(vk_cb->command_buffer, src_buffer->buffer, dst_buffer->buffer, 1, &copy_region);
}

void VulkanBackend::cmd_copy_buffer_to_texture(const Handle<CommandBuffer>& cb, const CmdCopyBufferToTextureOptions& options)
{
    const VulkanCommandBuffer* vk_cb = resources.command_buffers.get(cb);
    if (vk_cb == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    const VulkanBuffer*  src_buffer  = resources.buffers.get(options.buffer);
    const VulkanTexture* dst_texture = resources.textures.get(options.texture);
    if (src_buffer == nullptr || dst_texture == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find source buffer or destination texture.");
        return;
    }

    VkBufferImageCopy copy_region               = {};
    copy_region.bufferOffset                    = options.buffer_offset;
    copy_region.bufferRowLength                 = options.buffer_row_length;
    copy_region.bufferImageHeight               = options.buffer_texture_height;
    copy_region.imageSubresource                = {};
    copy_region.imageSubresource.aspectMask     = to_vk_image_aspect_flags(options.aspect_flags);
    copy_region.imageSubresource.mipLevel       = options.mip_level;
    copy_region.imageSubresource.baseArrayLayer = options.base_array_layer;
    copy_region.imageSubresource.layerCount     = options.layer_count;
    copy_region.imageOffset                     = { options.texture_offset[0], options.texture_offset[1], options.texture_offset[2] };
    copy_region.imageExtent                     = { options.texture_extent[0], options.texture_extent[1], options.texture_extent[2] };

    vkCmdCopyBufferToImage(vk_cb->command_buffer, src_buffer->buffer, dst_texture->image, to_vk_image_layout(options.dst_layout), 1, &copy_region);
}

void VulkanBackend::cmd_pipeline_barrier(const Handle<CommandBuffer>& cb, const CmdPipelineBarrierOptions& options)
{
    const VulkanCommandBuffer* vk_cb = resources.command_buffers.get(cb);
    if (vk_cb == nullptr) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to find command buffer.");
        return;
    }

    VkImageMemoryBarrier image_memory_barriers[MAX_BARRIERS];
    for (u32 i = 0; i < options.num_texture_barriers; i++)
    {
        const TextureBarrier& barrier = options.texture_barriers[i];
        const VulkanTexture*  texture = resources.textures.get(barrier.texture);
        if (texture == nullptr) [[unlikely]]
        {
            CLAY_LOG_ERROR("Failed to find texture.");
            continue;
        }

        VkImageMemoryBarrier& image_barrier           = image_memory_barriers[i];
        image_barrier                                 = {};
        image_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        image_barrier.srcAccessMask                   = to_vk_access_flags(barrier.src_access);
        image_barrier.dstAccessMask                   = to_vk_access_flags(barrier.dst_access);
        image_barrier.oldLayout                       = to_vk_image_layout(barrier.old_layout);
        image_barrier.newLayout                       = to_vk_image_layout(barrier.new_layout);
        image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.image                           = texture->image;
        image_barrier.subresourceRange.aspectMask     = to_vk_image_aspect_flags(barrier.aspect_flags);
        image_barrier.subresourceRange.baseMipLevel   = barrier.base_mip_level;
        image_barrier.subresourceRange.levelCount     = barrier.level_count;
        image_barrier.subresourceRange.baseArrayLayer = barrier.base_array_layer;
        image_barrier.subresourceRange.layerCount     = barrier.layer_count;
    }

    vkCmdPipelineBarrier(vk_cb->command_buffer, to_vk_pipeline_stage_flags(options.src_stage), to_vk_pipeline_stage_flags(options.dst_stage), 0, 0, nullptr, 0, nullptr, options.num_texture_barriers, image_memory_barriers);
}

} // namespace gfx
} // namespace clay
