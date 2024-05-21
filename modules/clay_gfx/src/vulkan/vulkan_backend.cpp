#include "stdio.h"
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
    printf(" MessageID: %s %i\nMessage: %s\n\n", callback_data->pMessageIdName, callback_data->messageIdNumber, callback_data->pMessage);
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
    CLAY_ASSERT(result == VK_SUCCESS, "Failed to create Vulkan instance.");

    //////// Pick physcial device.
    uint32_t physical_device_count = 0;
    vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
    CLAY_ASSERT(physical_device_count > 0, "No Vulkan physical devices found.");

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    vkEnumeratePhysicalDevices(instance, &physical_device_count, physical_devices.data());

    VkPhysicalDevice target_device = VK_NULL_HANDLE;
    if (desc.device_id != U32_MAX)
    {
        CLAY_LOG_INFO("Try to create device with id: {}", desc.device_id);
        bool bFoundPreferredDevice = false;
        for (const auto& device : physical_devices)
        {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(device, &properties);
            if (desc.device_id == properties.deviceID)
            {
                target_device         = device;
                bFoundPreferredDevice = true;
                break;
            }
        }

        if (!bFoundPreferredDevice)
        {
            CLAY_LOG_INFO("Preferred device not found. Automatically select device.");
        }
    }

    if (target_device == VK_NULL_HANDLE)
    {
        target_device = physical_devices[0];
    }
    CLAY_ASSERT(target_device != VK_NULL_HANDLE, "Failed to select Vulkan physical device.");

    if (target_device != VK_NULL_HANDLE)
    {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(target_device, &properties);
        CLAY_LOG_INFO("Selected GPU: {}, Device ID: {}, Driver Version: {}", properties.deviceName, properties.deviceID, properties.driverVersion);
    }
}

VulkanBackend::~VulkanBackend()
{
    // vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
}

} // namespace gfx
} // namespace clay
