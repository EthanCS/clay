#pragma once

#include <vector>

#include <clay_gfx/resource.h>
#include <clay_gfx/define.h>
#include <clay_gfx/vulkan/vulkan_header.h>

namespace flecs
{
struct world;
}

namespace clay
{
namespace gfx
{
struct VulkanQueue {
    VkQueue queue;
    u32     family_index;
};

struct VulkanFence {
    VkFence fence;
};

struct VulkanSemaphore {
    VkSemaphore semaphore;
};

struct VulkanShader {
    VkShaderModule shader_module;
};

struct VulkanSwapchain {
    VkSwapchainKHR swapchain;

    u32           image_count;
    TextureHandle images[MAX_SWAPCHAIN_IMAGES];

    VulkanSwapchain() noexcept;
    bool init(flecs::world* world, VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height, Format::Enum format, bool vsync);
};

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
    VkImage                            image;
    std::vector<VkImageView>           views;
    std::vector<VulkanTextureViewDesc> view_descs;

    VkImageView get_view(const VkDevice& device, const VulkanTextureViewDesc& desc);
    inline void destroy(const VkDevice& device) const
    {
        for (const auto& view : views)
        {
            vkDestroyImageView(device, view, nullptr);
        }
        vkDestroyImage(device, image, nullptr);
    }
};

struct VulkanRenderPass {
    VkRenderPass     render_pass;
    RenderPassLayout output;
};

struct VulkanGraphicsPipeline {
    VkPipeline pipeline = VK_NULL_HANDLE;

    void init(const flecs::world* world, const VkDevice& device, const GraphicsPipelineCreateDesc& desc);
};
} // namespace gfx
} // namespace clay