#include <clay_gfx/vulkan/vulkan_swapchain.h>
#include <clay_core/log.h>
#include <vulkan/vk_enum_string_helper.h>

namespace clay
{
namespace gfx
{
void VulkanSwapchain::init(VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height)
{
    // VkSurfaceCapabilitiesKHR capabilities;
    // vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &capabilities);

    // u32 format_count;
    // vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, nullptr);
    // VkSurfaceFormatKHR* formats = new VkSurfaceFormatKHR[format_count];
    // vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, formats);

    // u32 present_mode_count;
    // vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, nullptr);
    // VkPresentModeKHR* present_modes = new VkPresentModeKHR[present_mode_count];
    // vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, present_modes);

    // VkSurfaceFormatKHR surface_format = formats[0];
    // for (u32 i = 0; i < format_count; ++i)
    // {
    //     if (formats[i].format == VK_FORMAT_B8G8R8A8_SRGB && formats[i].colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
    //     {
    //         surface_format = formats[i];
    //         break;
    //     }
    // }

    // VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
    // for (u32 i = 0; i < present_mode_count; ++i)
    // {
    //     if (present_modes[i] == VK_PRESENT_MODE_MAILBOX_KHR)
    //     {
    //         present_mode = present_modes[i];
    //         break;
    //     }
    // }

    // VkExtent2D extent = { width, height };
    // extent.width      = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, extent.width));
    // extent.height     = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, extent.height));

    // u32 image_count = capabilities.minImageCount + 1;
    // if (capabilities.maxImageCount > 0 && image_count > capabilities.maxImageCount)
    // {
    //     image_count = capabilities.maxImageCount;
    // }

    // VkSwapchainCreateInfoKHR create_info = {};
    // create_info.sType                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    // create_info.surface                  = surface;
    // create_info.minImageCount            = image_count;
    // create_info.imageFormat              = surface_format.format;
    // create_info.imageColorSpace          = surface_format.colorSpace;
    // create_info.imageExtent              = extent;
    // create_info.imageArrayLayers         = 1;

    // u32 queue_family_indices[] = { graphics_queue.family_index, present_queue.family_index };
    // if (graphics_queue.family_index != present_queue.family_index)
    // {
    //     create_info.imageSharingMode      = VK_SHARING_MODE_CONCURRENT;
    //     create_info.queueFamilyIndexCount = 2;
    //     create_info.pQueueFamilyIndices   = queue_family_indices;
    // }
    // else
    // {
    //     create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    // }

    // create_info.preTransform   = capabilities.currentTransform;
    // create_info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    // create_info.presentMode    = present_mode;
    // create_info.clipped        = VK_TRUE;
    // create_info.oldSwapchain   = VK_NULL_HANDLE;

    // VkResult result = vkCreateSwapchainKHR(device, &create_info, nullptr, &swapchain);
    // CLAY_ASSERT(result == VK_SUCCESS, "Failed to create swapchain! ({})", string_VkResult(result));
}

} // namespace gfx
} // namespace clay