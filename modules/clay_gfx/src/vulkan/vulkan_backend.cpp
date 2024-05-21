#include <clay_gfx/vulkan/vulkan_backend.h>
#include <clay_gfx/vulkan/vulkan_utils.h>
#include <vulkan/vk_enum_string_helper.h>

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

VulkanBackend::VulkanBackend(const RenderBackendCreateDesc& desc)
    : RenderBackend(desc.type)
{
    CLAY_LOG_INFO("Initializing Vulkan backend...");

    //////// Init Vulkan instance.
    VkApplicationInfo app_info  = {};
    app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName   = "Clay";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName        = "Clay";
    app_info.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    app_info.apiVersion         = VK_API_VERSION_1_0;

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

    //////// Pick physcial device.
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
    CLAY_ASSERT(adapter != VK_NULL_HANDLE, "Failed to select Vulkan physical device.");

    //////// Create logical device.
    if (adapter != VK_NULL_HANDLE)
    {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(adapter, &properties);
        CLAY_LOG_INFO("Selected GPU: {}, Device ID: {}, Driver Version: {}", properties.deviceName, properties.deviceID, properties.driverVersion);

        // Find Queue Family
        uint32_t queue_family_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(adapter, &queue_family_count, nullptr);
        CLAY_ASSERT(queue_family_count > 0, "No Vulkan queue families found.");
        std::vector<VkQueueFamilyProperties> queue_family_properties(queue_family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(adapter, &queue_family_count, queue_family_properties.data());

        u32 main_queue_family_index     = u32_MAX;
        u32 compute_queue_family_index  = u32_MAX;
        u32 transfer_queue_family_index = u32_MAX;
        u32 compute_queue_index         = u32_MAX;

        for (int i = 0; i < queue_family_count; ++i)
        {
            const auto& q = queue_family_properties[i];
            if (q.queueCount == 0) { continue; }

            if (q.queueFlags & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT))
            {
                main_queue_family_index = i;
                if (q.queueCount > 1)
                {
                    compute_queue_family_index = i;
                    compute_queue_index        = 1;
                }
                continue;
            }

            // Compute queue
            if (q.queueFlags & VK_QUEUE_COMPUTE_BIT && compute_queue_family_index == u32_MAX)
            {
                compute_queue_family_index = i;
                compute_queue_index        = 0;
            }

            // Transfer queue
            if (q.queueFlags & VK_QUEUE_TRANSFER_BIT && !(q.queueFlags & VK_QUEUE_COMPUTE_BIT))
            {
                transfer_queue_family_index = i;
                continue;
            }
        }

        std::vector<VkDeviceQueueCreateInfo> queue_infos;

        VkDeviceQueueCreateInfo main_queue = {};
        main_queue.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        main_queue.queueFamilyIndex        = main_queue_family_index;
        main_queue.queueCount              = main_queue_family_index == compute_queue_family_index ? 2 : 1;
        float queue_priority[]             = { 1.0f, 1.0f };
        main_queue.pQueuePriorities        = queue_priority;
        queue_infos.push_back(main_queue);

        if (main_queue_family_index != compute_queue_family_index)
        {
            VkDeviceQueueCreateInfo compute_queue = {};
            compute_queue.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            compute_queue.queueFamilyIndex        = compute_queue_family_index;
            compute_queue.queueCount              = 1;
            compute_queue.pQueuePriorities        = queue_priority;
            queue_infos.push_back(compute_queue);
        }

        if (transfer_queue_family_index < queue_family_properties.size())
        {
            VkDeviceQueueCreateInfo transfer_queue = {};
            transfer_queue.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            transfer_queue.queueFamilyIndex        = transfer_queue_family_index;
            transfer_queue.queueCount              = 1;
            transfer_queue.pQueuePriorities        = queue_priority;
            queue_infos.push_back(transfer_queue);
        }

        VkDeviceCreateInfo device_info   = {};
        device_info.sType                = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        device_info.queueCreateInfoCount = queue_infos.size();
        device_info.pQueueCreateInfos    = queue_infos.data();

        result = vkCreateDevice(adapter, &device_info, nullptr, &device);
        CLAY_ASSERT(result == VK_SUCCESS, "Failed to create Vulkan logical device. ({})", string_VkResult(result));

        graphics_queue.family_index = main_queue_family_index;
        vkGetDeviceQueue(device, main_queue_family_index, 0, &graphics_queue.queue);
        present_queue = graphics_queue;

        compute_queue.family_index = compute_queue_family_index;
        vkGetDeviceQueue(device, compute_queue_family_index, compute_queue_index, &compute_queue.queue);

        transfer_queue.family_index = transfer_queue_family_index;
        vkGetDeviceQueue(device, transfer_queue_family_index, 0, &transfer_queue.queue);
    }
}

VulkanBackend::~VulkanBackend()
{
    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
}

} // namespace gfx
} // namespace clay
