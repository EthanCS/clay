#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <clay_gfx/define.h>
#include <clay_core/macro.h>

#include <vector>

namespace clay
{
namespace gfx
{
struct VulkanTextureViewDesc {
    VkImageViewType    view_type;
    VkFormat           format;
    VkImageAspectFlags aspect_flags;
    VkComponentSwizzle component_r;
    VkComponentSwizzle component_g;
    VkComponentSwizzle component_b;
    VkComponentSwizzle component_a;
    u32                base_mip_level;
    u32                level_count;
    u32                base_array_layer;
    u32                layer_count;

    bool operator==(const VulkanTextureViewDesc& rhs) const
    {
        return view_type == rhs.view_type &&
               format == rhs.format &&
               aspect_flags == rhs.aspect_flags &&
               component_r == rhs.component_r &&
               component_g == rhs.component_g &&
               component_b == rhs.component_b &&
               component_a == rhs.component_a &&
               base_mip_level == rhs.base_mip_level &&
               level_count == rhs.level_count &&
               base_array_layer == rhs.base_array_layer &&
               layer_count == rhs.layer_count;
    }
};

struct VulkanTexture {
    VkImage image;

    std::vector<VulkanTextureViewDesc> view_descs;
    std::vector<VkImageView>           views;

    VkImageView get_view(const VkDevice& device, const VulkanTextureViewDesc& desc);
};
} // namespace gfx
} // namespace clay