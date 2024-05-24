#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

namespace clay
{
namespace gfx
{
struct VulkanTexture {
    VkImage image;
};
} // namespace gfx
} // namespace clay