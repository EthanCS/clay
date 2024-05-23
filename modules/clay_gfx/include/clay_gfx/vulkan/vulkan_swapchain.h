#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <clay_core/macro.h>

namespace clay
{
namespace gfx
{
struct VulkanSwapchain {
    VkSwapchainKHR swapchain;
    VkFormat       format;
    VkExtent2D     extent;
    u32            image_count;
    VkImage*       images;
    VkImageView*   image_views;
    VkSemaphore*   image_available_semaphores;
    VkSemaphore*   render_finished_semaphores;
    VkFence*       in_flight_fences;
    VkFence*       images_in_flight;
    u32            current_frame;
    bool           framebuffer_resized;

    void init(VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height);
};
} // namespace gfx
} // namespace clay