#pragma once

#include <vector>
#include <clay_gfx/resource.h>
#include <clay_gfx/define.h>
#include <clay_gfx/pool.h>
#include <clay_gfx/options.h>

#include <clay_gfx/vulkan/vulkan_header.h>
#include <vk_mem_alloc.h>

namespace clay
{
namespace gfx
{
struct VulkanResources;

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
    VkSwapchainKHR  swapchain   = VK_NULL_HANDLE;
    u32             image_count = 0;
    Handle<Texture> images[MAX_SWAPCHAIN_IMAGES];
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
    VkFormat                           format;
    u32                                width;
    u32                                height;
    std::vector<VkImageView>           views;
    std::vector<VulkanTextureViewDesc> view_descs;

    VmaAllocation  allocation    = VK_NULL_HANDLE;
    VkDeviceMemory device_memory = VK_NULL_HANDLE;

    VkImageView get_view(const VkDevice& device, VulkanTextureViewDesc desc);
    inline void destroy(const VkDevice& device, VmaAllocator vma_allocator) const
    {
        for (const auto& view : views)
        {
            vkDestroyImageView(device, view, nullptr);
        }

        if (allocation != nullptr) { vmaDestroyImage(vma_allocator, image, allocation); }
        else { vkDestroyImage(device, image, nullptr); }
    }
};

struct VulkanPipelineLayout {
    VkPipelineLayout layout = VK_NULL_HANDLE;
};

struct VulkanGraphicsPipeline {
    VkPipeline pipeline = VK_NULL_HANDLE;

    bool init(VulkanResources* res, const VkDevice& device, const CreateGraphicsPipelineOptions& desc);
};

struct VulkanRenderPass {
    VkRenderPass     render_pass;
    RenderPassLayout output;

    bool is_compatible(const RenderPassLayout& layout) const;
};

struct VulkanCommandPool {
    VkCommandPool command_pool = VK_NULL_HANDLE;
};

struct VulkanCommandBuffer {
    VkCommandBuffer     command_buffer = VK_NULL_HANDLE;
    Handle<CommandPool> pool;
};

struct VulkanFramebuffer {
    VkFramebuffer framebuffer = VK_NULL_HANDLE;
};

struct VulkanBuffer {
    VkBuffer       buffer        = VK_NULL_HANDLE;
    VmaAllocation  allocation    = VK_NULL_HANDLE;
    VkDeviceMemory device_memory = VK_NULL_HANDLE;
    u32            size          = 0;
};

struct VulkanDescriptorSetLayout {
    VkDescriptorSetLayout layout = VK_NULL_HANDLE;

    u32                          num_bindings = 0;
    VkDescriptorSetLayoutBinding bindings[MAX_DESCRIPTOR_SET_LAYOUTS];
    u32                          binding_to_index[MAX_DESCRIPTOR_SET_LAYOUTS];
};

struct VulkanDescriptorSet {
    VkDescriptorSet             set;
    Handle<DescriptorSetLayout> layout;
};

struct VulkanResources {
    Pool<Swapchain, VulkanSwapchain>                     swapchains;
    Pool<Fence, VulkanFence>                             fences;
    Pool<Semaphore, VulkanSemaphore>                     semaphores;
    Pool<Shader, VulkanShader>                           shaders;
    Pool<Texture, VulkanTexture>                         textures;
    Pool<PipelineLayout, VulkanPipelineLayout>           pipeline_layouts;
    Pool<GraphicsPipeline, VulkanGraphicsPipeline>       graphics_pipelines;
    Pool<CommandPool, VulkanCommandPool>                 command_pools;
    Pool<CommandBuffer, VulkanCommandBuffer>             command_buffers;
    Pool<Framebuffer, VulkanFramebuffer>                 framebuffers;
    Pool<Buffer, VulkanBuffer>                           buffers;
    Pool<DescriptorSetLayout, VulkanDescriptorSetLayout> descriptor_set_layouts;
    Pool<DescriptorSet, VulkanDescriptorSet>             descriptor_sets;

    std::vector<VulkanRenderPass> render_passes;

    VulkanResources()
        : swapchains(2)
        , fences(4)
        , semaphores(16)
        , shaders(32)
        , textures(32)
        , pipeline_layouts(32)
        , graphics_pipelines(32)
        , command_pools(4)
        , command_buffers(8)
        , framebuffers(4)
        , buffers(16)
        , descriptor_set_layouts(32)
        , descriptor_sets(64)
    {
    }

    VkRenderPass get_or_create_render_pass(const VkDevice& device, const RenderPassLayout& layout);
    void         destroy(const VkDevice& device, const VmaAllocator& vma_allocator);
};

} // namespace gfx
} // namespace clay