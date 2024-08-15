#pragma once

#include <clay_gfx/resource.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_header.h>
#include <clay_gfx/vulkan/vulkan_resource.h>

namespace clay
{
namespace gfx
{

static const u32 MAX_GLOBAL_POOL_ELEMENTS = 128;

class VulkanBackend
{
private:
    VulkanResources resources;

    VkInstance       instance        = VK_NULL_HANDLE;
    VkDevice         device          = VK_NULL_HANDLE;
    VkPhysicalDevice physical_device = VK_NULL_HANDLE;
    VkSurfaceKHR     surface         = VK_NULL_HANDLE;

    VmaAllocator vma_allocator = VK_NULL_HANDLE;

    VulkanQueue graphics_queue;
    VulkanQueue present_queue;
    VulkanQueue compute_queue;
    VulkanQueue transfer_queue;

    VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;

    bool                             debug_utils_enabled;
    VkDebugUtilsMessengerEXT         debug_utils_messenger;
    PFN_vkSetDebugUtilsObjectNameEXT pfn_SetDebugUtilsObjectNameEXT;
    PFN_vkCmdBeginDebugUtilsLabelEXT pfn_CmdBeginDebugUtilsLabelEXT;
    PFN_vkCmdEndDebugUtilsLabelEXT   pfn_CmdEndDebugUtilsLabelEXT;

public:
    bool              init(const InitBackendOptions& desc);
    void              shutdown();
    BackendType::Enum get_type() noexcept { return BackendType::Vulkan; }

    void device_wait_idle() { vkDeviceWaitIdle(device); }

    void queue_wait_idle(QueueType::Enum queue_type)
    {
        VkQueue queue = get_queue(queue_type);
        if (queue != VK_NULL_HANDLE) [[likely]] { vkQueueWaitIdle(get_queue(queue_type)); }
    }
    void                  queue_submit(QueueType::Enum, const QueueSubmitOptions options);
    SwapchainStatus::Enum queue_present(const QueuePresentOptions& options);

    Handle<Swapchain>      create_swapchain(const CreateSwapchainOptions& desc);
    SwapchainAcquireResult acquire_next_image(const Handle<Swapchain>& swapchain, const AcquireNextImageOptions& options);
    u32                    get_swapchain_image_count(const Handle<Swapchain>& swapchain);
    Handle<Texture>        get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index);
    void                   destroy_swapchain(const Handle<Swapchain>& swapchain);

    Handle<Fence> create_fence(bool signal);
    void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout);
    void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout);
    void          reset_fences(const Handle<Fence>* fences, int num_fence);
    void          destroy_fence(const Handle<Fence>& fence);

    Handle<Semaphore> create_semaphore();
    void              destroy_semaphore(const Handle<Semaphore>& semaphore);

    Handle<Shader> create_shader(const CreateShaderOptions& desc);
    void           destroy_shader(const Handle<Shader>& shader);

    Handle<PipelineLayout> create_pipeline_layout(const CreatePipelineLayoutOptions& desc);
    void                   destroy_pipeline_layout(const Handle<PipelineLayout>& layout);

    Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc);
    void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline);

    Handle<Texture> create_texture(const CreateTextureOptions& desc);
    u32             get_texture_width(const Handle<Texture>& texture);
    u32             get_texture_height(const Handle<Texture>& texture);
    void            destroy_texture(const Handle<Texture>& texture);

    Handle<Sampler> create_sampler(const CreateSamplerOptions& desc);
    void            destroy_sampler(const Handle<Sampler>& sampler);

    Handle<Buffer> create_buffer(const CreateBufferOptions& desc);
    void*          map_buffer(const Handle<Buffer>& buffer);
    void           unmap_buffer(const Handle<Buffer>& buffer);
    void           destroy_buffer(const Handle<Buffer>& buffer);

    Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& desc);
    void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer);

    Handle<DescriptorSetLayout> create_descriptor_set_layout(const CreateDescriptorSetLayoutOptions& desc);
    void                        destroy_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout);

    Handle<DescriptorSet> create_descriptor_set(const CreateDescriptorSetOptions& desc);
    void                  update_descriptor_set(const Handle<DescriptorSet>& set, const UpdateDescriptorSetOptions& desc);
    void                  destroy_descriptor_set(const Handle<DescriptorSet>& set);

    Handle<CommandPool> create_command_pool(QueueType::Enum queue_type);
    void                destroy_command_pool(const Handle<CommandPool>& pool);

    Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool);
    void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource);
    void                  free_command_buffer(const Handle<CommandBuffer>& buffer);

    void cmd_begin(const Handle<CommandBuffer>& cb, bool one_time);
    void cmd_copy_buffer(const Handle<CommandBuffer>& cb, const CmdCopyBufferOptions& options);
    void cmd_copy_buffer_to_texture(const Handle<CommandBuffer>& cb, const CmdCopyBufferToTextureOptions& options);
    void cmd_pipeline_barrier(const Handle<CommandBuffer>& cb, const CmdPipelineBarrierOptions& options);
    void cmd_end(const Handle<CommandBuffer>& cb);

    RenderPassEncoder cmd_begin_render_pass(const Handle<CommandBuffer>& cb, const CmdBeginRenderPassOptions& options);
    void              cmd_bind_pipeline(const RenderPassEncoder& encoder, const Handle<GraphicsPipeline>& pipeline);
    void              cmd_set_viewport(const RenderPassEncoder& encoder, const CmdSetViewportOptions& viewport);
    void              cmd_set_scissor(const RenderPassEncoder& encoder, const CmdSetScissorOptions& scissor);
    void              cmd_draw(const RenderPassEncoder& encoder, const CmdDrawOptions& draw);
    void              cmd_draw_indexed(const RenderPassEncoder& encoder, const CmdDrawIndexedOptions& draw);
    void              cmd_bind_vertex_buffer(const RenderPassEncoder& encoder, const CmdBindVertexBufferOptions& options);
    void              cmd_bind_vertex_buffers(const RenderPassEncoder& encoder, const CmdBindVertexBuffersOptions& options);
    void              cmd_bind_index_buffer(const RenderPassEncoder& encoder, const CmdBindIndexBufferOptions& options);
    void              cmd_bind_descriptor_sets(const RenderPassEncoder& encoder, const CmdBindDescriptorSetsOptions& options);
    void              cmd_end_render_pass(const Handle<CommandBuffer>& cb, const RenderPassEncoder& encoder);

private:
    VkQueue get_queue(QueueType::Enum queue_type)
    {
        switch (queue_type)
        {
            case QueueType::Graphics:
                return graphics_queue.queue;
            case QueueType::Present:
                return present_queue.queue;
            case QueueType::Compute:
                return compute_queue.queue;
            case QueueType::Transfer:
                return transfer_queue.queue;
        }
        return VK_NULL_HANDLE;
    }
};
} // namespace gfx
} // namespace clay