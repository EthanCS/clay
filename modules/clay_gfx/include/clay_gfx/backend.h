#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/handle.h>
#include <clay_gfx/define.h>
#include <clay_gfx/resource.h>
#include <clay_gfx/options.h>

namespace clay
{
namespace gfx
{
struct IRenderBackend {
    virtual ~IRenderBackend() = default;

    /////// General
    virtual bool              initialize(const InitBackendOptions& options) = 0;
    virtual void              finalize()                                    = 0;
    virtual BackendType::Enum get_type() const CLAY_NOEXCEPT                = 0;

    /////// Device
    virtual void device_wait_idle() = 0;

    /////// Queue
    virtual Handle<Queue>         get_queue(const QueueType::Enum& queue_type) CLAY_NOEXCEPT                    = 0;
    virtual void                  queue_wait_idle(const Handle<Queue>& queue)                                   = 0;
    virtual void                  queue_submit(const Handle<Queue>& queue, const QueueSubmitOptions& options)   = 0;
    virtual SwapchainStatus::Enum queue_present(const Handle<Queue>& queue, const QueuePresentOptions& options) = 0;

    /////// Swapchain
    virtual Handle<Swapchain>      create_swapchain(const CreateSwapchainOptions& options)                                        = 0;
    virtual SwapchainAcquireResult acquire_next_image(const Handle<Swapchain>& swapchain, const AcquireNextImageOptions& options) = 0;
    virtual u32                    get_swapchain_image_count(const Handle<Swapchain>& swapchain)                                  = 0;
    virtual Handle<Texture>        get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index)                       = 0;
    virtual void                   destroy_swapchain(const Handle<Swapchain>& swapchain)                                          = 0;

    /////// Fence
    virtual Handle<Fence> create_fence(bool signal)                                                               = 0;
    virtual void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) = 0;
    virtual void          reset_fences(const Handle<Fence>* fences, int num_fence)                                = 0;
    virtual void          destroy_fence(const Handle<Fence>& fence)                                               = 0;
    inline void           wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout) { wait_for_fences(&fence, 1, wait_all, timeout); }
    inline void           reset_fence(const Handle<Fence>& fence) { reset_fences(&fence, 1); }

    /////// Semaphore
    virtual Handle<Semaphore> create_semaphore()                                    = 0;
    virtual void              destroy_semaphore(const Handle<Semaphore>& semaphore) = 0;

    /////// Shader
    virtual Handle<Shader> create_shader(const CreateShaderOptions& options) = 0;
    virtual void           destroy_shader(const Handle<Shader>& shader)      = 0;

    /////// PipelineLayout
    virtual Handle<PipelineLayout> create_pipeline_layout(const CreatePipelineLayoutOptions& options) = 0;
    virtual void                   destroy_pipeline_layout(const Handle<PipelineLayout>& layout)      = 0;

    /////// GraphicsPipeline
    virtual Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& options) = 0;
    virtual void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline)    = 0;

    /////// Texture
    virtual Handle<Texture>   create_texture(const CreateTextureOptions& options)    = 0;
    virtual TextureDescriptor get_texture_descriptor(const Handle<Texture>& texture) = 0;
    virtual void              destroy_texture(const Handle<Texture>& texture)        = 0;

    /////// Sampler
    virtual Handle<Sampler> create_sampler(const CreateSamplerOptions& options) = 0;
    virtual void            destroy_sampler(const Handle<Sampler>& sampler)     = 0;

    /////// Buffer
    virtual Handle<Buffer> create_buffer(const CreateBufferOptions& options) = 0;
    virtual void*          map_buffer(const Handle<Buffer>& buffer)          = 0;
    virtual void           unmap_buffer(const Handle<Buffer>& buffer)        = 0;
    virtual void           destroy_buffer(const Handle<Buffer>& buffer)      = 0;

    /////// Framebuffer
    virtual Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& options) = 0;
    virtual void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer) = 0;

    /////// DescriptorSetLayout
    virtual Handle<DescriptorSetLayout> create_descriptor_set_layout(const CreateDescriptorSetLayoutOptions& options) = 0;
    virtual void                        destroy_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout)      = 0;

    /////// DescriptorSet
    virtual Handle<DescriptorSet> create_descriptor_set(const CreateDescriptorSetOptions& options)                                   = 0;
    virtual void                  update_descriptor_set(const Handle<DescriptorSet>& set, const UpdateDescriptorSetOptions& options) = 0;
    virtual void                  destroy_descriptor_set(const Handle<DescriptorSet>& set)                                           = 0;

    /////// CommandPool
    virtual Handle<CommandPool> create_command_pool(const Handle<Queue>& queue)       = 0;
    virtual void                destroy_command_pool(const Handle<CommandPool>& pool) = 0;

    /////// CommandBuffer
    virtual Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool, bool primary)           = 0;
    virtual void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource) = 0;
    virtual void                  free_command_buffer(const Handle<CommandBuffer>& buffer)                         = 0;

    /////// Command
    virtual void cmd_begin(const Handle<CommandBuffer>& buffer, bool one_time)                                                 = 0;
    virtual void cmd_copy_buffer(const Handle<CommandBuffer>& buffer, const CmdCopyBufferOptions& options)                     = 0;
    virtual void cmd_copy_buffer_to_texture(const Handle<CommandBuffer>& buffer, const CmdCopyBufferToTextureOptions& options) = 0;
    virtual void cmd_pipeline_barrier(const Handle<CommandBuffer>& buffer, const CmdPipelineBarrierOptions& options)           = 0;
    virtual void cmd_end(const Handle<CommandBuffer>& buffer)                                                                  = 0;

    /////// Render Pass
    virtual RenderPassEncoder cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options)    = 0;
    virtual void              cmd_bind_pipeline(const RenderPassEncoder& encoder, const Handle<GraphicsPipeline>& pipeline)           = 0;
    virtual void              cmd_set_viewport(const RenderPassEncoder& encoder, const CmdSetViewportOptions& options)                = 0;
    virtual void              cmd_set_scissor(const RenderPassEncoder& encoder, const CmdSetScissorOptions& options)                  = 0;
    virtual void              cmd_draw(const RenderPassEncoder& encoder, const CmdDrawOptions& options)                               = 0;
    virtual void              cmd_draw_indexed(const RenderPassEncoder& encoder, const CmdDrawIndexedOptions& options)                = 0;
    virtual void              cmd_bind_vertex_buffer(const RenderPassEncoder& encoder, const CmdBindVertexBufferOptions& options)     = 0;
    virtual void              cmd_bind_vertex_buffers(const RenderPassEncoder& encoder, const CmdBindVertexBuffersOptions& options)   = 0;
    virtual void              cmd_bind_index_buffer(const RenderPassEncoder& encoder, const CmdBindIndexBufferOptions& options)       = 0;
    virtual void              cmd_bind_descriptor_sets(const RenderPassEncoder& encoder, const CmdBindDescriptorSetsOptions& options) = 0;
    virtual void              cmd_end_render_pass(const Handle<CommandBuffer>& buffer, const RenderPassEncoder& encoder)              = 0;
};

IRenderBackend* create_render_backend(const InitBackendOptions& desc);
void            destroy_render_backend(IRenderBackend* backend);

} // namespace gfx
} // namespace clay