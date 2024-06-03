#include <SDL.h>
#include <SDL_vulkan.h>
#include <clay_core/log.h>
#include <clay_core/macro.h>

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
    , resources()
    , instance(VK_NULL_HANDLE)
    , device(VK_NULL_HANDLE)
    , physical_device(VK_NULL_HANDLE)
    , surface(VK_NULL_HANDLE)
{
}

VulkanBackend::~VulkanBackend()
{
    for (int i = 0; i < swapchain.image_count; i++)
    {
        resources.textures.free(swapchain.images[i]);
    }
    vkDestroySwapchainKHR(device, swapchain.swapchain, nullptr);

    vkDestroySurfaceKHR(instance, surface, nullptr);

    if (debug_utils_messenger != VK_NULL_HANDLE)
    {
        auto vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        vkDestroyDebugUtilsMessengerEXT(instance, debug_utils_messenger, nullptr);
    }

    resources.destroy(device);

    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
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
        swapchain.init(&resources, device, physical_device, surface, desc.width, desc.height, desc.format, desc.vsync);
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
        return Handle<Fence>();
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
        return Handle<Semaphore>();
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

Handle<Shader> VulkanBackend::create_shader(const ShaderCreateDesc& desc)
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
        return Handle<Shader>();
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

Handle<GraphicsPipeline> VulkanBackend::create_graphics_pipeline(const GraphicsPipelineCreateDesc& desc)
{
    VulkanGraphicsPipeline pipeline;
    if (pipeline.init(&resources, device, desc)) [[likely]]
    {
        return resources.graphics_pipelines.push(pipeline);
    }
    return Handle<GraphicsPipeline>();
}

void VulkanBackend::destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline)
{
    const VulkanGraphicsPipeline* vulkan_pipeline = resources.graphics_pipelines.get(pipeline);
    if (vulkan_pipeline == nullptr) [[unlikely]] { return; }
    vkDestroyPipeline(device, vulkan_pipeline->pipeline, nullptr);
    resources.graphics_pipelines.free(pipeline);
}

void VulkanBackend::destroy_texture(const Handle<Texture>& texture)
{
    const VulkanTexture* vulkan_texture = resources.textures.get(texture);
    if (vulkan_texture == nullptr) [[unlikely]] { return; }
    vulkan_texture->destroy(device);
    resources.textures.free(texture);
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
        return Handle<CommandPool>();
    }

    return resources.command_pools.push(VulkanCommandPool{ .command_pool = command_pool });
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
    if (vulkan_pool == nullptr) [[unlikely]] { return Handle<CommandBuffer>(); }

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
        return Handle<CommandBuffer>();
    }

    return resources.command_buffers.push(VulkanCommandBuffer{ .command_buffer = command_buffer, .pool = pool });
}

void VulkanBackend::free_command_buffer(const Handle<CommandBuffer>& buffer)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    const VulkanCommandPool*   vulkan_pool   = resources.command_pools.get(vulkan_buffer->pool);
    if (vulkan_buffer == nullptr || vulkan_pool == nullptr) [[unlikely]] { return; }
    vkFreeCommandBuffers(device, vulkan_pool->command_pool, 1, &vulkan_buffer->command_buffer);
    resources.command_buffers.free(buffer);
}

void VulkanBackend::cmd_begin(const Handle<CommandBuffer>& buffer)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    // begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(vulkan_buffer->command_buffer, &begin_info);
}

void VulkanBackend::cmd_end(const Handle<CommandBuffer>& buffer)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }

    vkEndCommandBuffer(vulkan_buffer->command_buffer);
}

void VulkanBackend::cmd_set_viewport(const Handle<CommandBuffer>& buffer, const CmdSetViewportOptions& viewport)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }

    VkViewport vk_viewport = {};
    vk_viewport.x          = viewport.x;
    vk_viewport.y          = viewport.y;
    vk_viewport.width      = viewport.width;
    vk_viewport.height     = viewport.height;
    vk_viewport.minDepth   = viewport.min_depth;
    vk_viewport.maxDepth   = viewport.max_depth;

    vkCmdSetViewport(vulkan_buffer->command_buffer, 0, 1, &vk_viewport);
}

void VulkanBackend::cmd_set_scissor(const Handle<CommandBuffer>& buffer, const CmdSetScissorOptions& scissor)
{
    const VulkanCommandBuffer* vulkan_buffer = resources.command_buffers.get(buffer);
    if (vulkan_buffer == nullptr) [[unlikely]] { return; }

    VkRect2D vk_scissor = {};
    vk_scissor.offset   = { scissor.offset[0], scissor.offset[1] };
    vk_scissor.extent   = { scissor.extent[0], scissor.extent[1] };

    vkCmdSetScissor(vulkan_buffer->command_buffer, 0, 1, &vk_scissor);
}

} // namespace gfx
} // namespace clay
