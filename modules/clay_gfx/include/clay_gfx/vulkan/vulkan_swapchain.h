#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <clay_core/macro.h>
#include <clay_gfx/resource.h>
#include <clay_gfx/define.h>

namespace clay
{
namespace gfx
{
static const u32 MAX_SWAPCHAIN_IMAGES = 3;

struct VulkanSwapchain {
    VkSwapchainKHR swapchain;

    u32               image_count;
    TextureHandle     images[MAX_SWAPCHAIN_IMAGES];
    TextureViewHandle image_views[MAX_SWAPCHAIN_IMAGES];

    VulkanSwapchain() noexcept;
    bool init(VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height, Format::Enum format, bool vsync);
};
} // namespace gfx
} // namespace clay