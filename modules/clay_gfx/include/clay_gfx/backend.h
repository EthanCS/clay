#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/handle.h>
#include <clay_gfx/define.h>
#include <clay_gfx/resource.h>
#include <clay_gfx/options.h>

#include <proxy.h>

namespace clay
{
namespace gfx
{
namespace spec
{
/////// General
PRO_DEF_MEMBER_DISPATCH(init, bool(const InitBackendOptions&));
PRO_DEF_MEMBER_DISPATCH(shutdown, void());
PRO_DEF_MEMBER_DISPATCH(get_type, BackendType::Enum() noexcept);

/////// Device
PRO_DEF_MEMBER_DISPATCH(device_wait_idle, void());

/////// Queue
PRO_DEF_MEMBER_DISPATCH(queue_wait_idle, void(QueueType::Enum));
PRO_DEF_MEMBER_DISPATCH(queue_submit, void(QueueType::Enum, const QueueSubmitOptions&));
PRO_DEF_MEMBER_DISPATCH(queue_present, SwapchainStatus::Enum(const QueuePresentOptions&));

/////// Swapchain
PRO_DEF_MEMBER_DISPATCH(create_swapchain, Handle<Swapchain>(const CreateSwapchainOptions&));
PRO_DEF_MEMBER_DISPATCH(acquire_next_image, SwapchainAcquireResult(const Handle<Swapchain>&, const AcquireNextImageOptions&));
PRO_DEF_MEMBER_DISPATCH(get_swapchain_image_count, u32(const Handle<Swapchain>&));
PRO_DEF_MEMBER_DISPATCH(get_swapchain_back_buffer, Handle<Texture>(const Handle<Swapchain>&, u32));
PRO_DEF_MEMBER_DISPATCH(destroy_swapchain, void(const Handle<Swapchain>&));

/////// Fence
PRO_DEF_MEMBER_DISPATCH(create_fence, Handle<Fence>(bool));
PRO_DEF_MEMBER_DISPATCH(wait_for_fence, void(const Handle<Fence>&, bool, u64));
PRO_DEF_MEMBER_DISPATCH(wait_for_fences, void(const Handle<Fence>*, int, bool, u64));
PRO_DEF_MEMBER_DISPATCH(reset_fences, void(const Handle<Fence>*, int));
PRO_DEF_MEMBER_DISPATCH(destroy_fence, void(const Handle<Fence>&));

/////// Semaphore
PRO_DEF_MEMBER_DISPATCH(create_semaphore, Handle<Semaphore>());
PRO_DEF_MEMBER_DISPATCH(destroy_semaphore, void(const Handle<Semaphore>&));

/////// Shader
PRO_DEF_MEMBER_DISPATCH(create_shader, Handle<Shader>(const CreateShaderOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_shader, void(const Handle<Shader>&));

/////// PipelineLayout
PRO_DEF_MEMBER_DISPATCH(create_pipeline_layout, Handle<PipelineLayout>(const CreatePipelineLayoutOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_pipeline_layout, void(const Handle<PipelineLayout>&));

/////// GraphicsPipeline
PRO_DEF_MEMBER_DISPATCH(create_graphics_pipeline, Handle<GraphicsPipeline>(const CreateGraphicsPipelineOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_graphics_pipeline, void(const Handle<GraphicsPipeline>&));

/////// Texture
PRO_DEF_MEMBER_DISPATCH(create_texture, Handle<Texture>(const CreateTextureOptions&));
PRO_DEF_MEMBER_DISPATCH(get_texture_width, u32(const Handle<Texture>&));
PRO_DEF_MEMBER_DISPATCH(get_texture_height, u32(const Handle<Texture>&));
PRO_DEF_MEMBER_DISPATCH(destroy_texture, void(const Handle<Texture>&));

/////// Sampler
PRO_DEF_MEMBER_DISPATCH(create_sampler, Handle<Sampler>(const CreateSamplerOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_sampler, void(const Handle<Sampler>&));

/////// Buffer
PRO_DEF_MEMBER_DISPATCH(create_buffer, Handle<Buffer>(const CreateBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(map_buffer, void*(const Handle<Buffer>&));
PRO_DEF_MEMBER_DISPATCH(unmap_buffer, void(const Handle<Buffer>&));
PRO_DEF_MEMBER_DISPATCH(destroy_buffer, void(const Handle<Buffer>&));

/////// Framebuffer
PRO_DEF_MEMBER_DISPATCH(create_framebuffer, Handle<Framebuffer>(const CreateFramebufferOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_framebuffer, void(const Handle<Framebuffer>&));

/////// DescriptorSetLayout
PRO_DEF_MEMBER_DISPATCH(create_descriptor_set_layout, Handle<DescriptorSetLayout>(const CreateDescriptorSetLayoutOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_descriptor_set_layout, void(const Handle<DescriptorSetLayout>&));

/////// DescriptorSet
PRO_DEF_MEMBER_DISPATCH(create_descriptor_set, Handle<DescriptorSet>(const CreateDescriptorSetOptions&));
PRO_DEF_MEMBER_DISPATCH(update_descriptor_set, void(const Handle<DescriptorSet>&, const UpdateDescriptorSetOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_descriptor_set, void(const Handle<DescriptorSet>&));

/////// CommandPool
PRO_DEF_MEMBER_DISPATCH(create_command_pool, Handle<CommandPool>(QueueType::Enum));
PRO_DEF_MEMBER_DISPATCH(destroy_command_pool, void(const Handle<CommandPool>&));

/////// CommandBuffer
PRO_DEF_MEMBER_DISPATCH(allocate_command_buffer, Handle<CommandBuffer>(const Handle<CommandPool>&));
PRO_DEF_MEMBER_DISPATCH(reset_command_buffer, void(const Handle<CommandBuffer>&, bool));
PRO_DEF_MEMBER_DISPATCH(free_command_buffer, void(const Handle<CommandBuffer>&));

/////// Command
PRO_DEF_MEMBER_DISPATCH(cmd_begin, void(const Handle<CommandBuffer>&, bool));
PRO_DEF_MEMBER_DISPATCH(cmd_copy_buffer, void(const Handle<CommandBuffer>&, const CmdCopyBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_copy_buffer_to_texture, void(const Handle<CommandBuffer>&, const CmdCopyBufferToTextureOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_pipeline_barrier, void(const Handle<CommandBuffer>&, const CmdPipelineBarrierOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_end, void(const Handle<CommandBuffer>&));

/////// Render Pass
PRO_DEF_MEMBER_DISPATCH(cmd_begin_render_pass, RenderPassEncoder(const Handle<CommandBuffer>&, const CmdBeginRenderPassOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_pipeline, void(const RenderPassEncoder&, const Handle<GraphicsPipeline>&));
PRO_DEF_MEMBER_DISPATCH(cmd_set_viewport, void(const RenderPassEncoder&, const CmdSetViewportOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_set_scissor, void(const RenderPassEncoder&, const CmdSetScissorOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_draw, void(const RenderPassEncoder&, const CmdDrawOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_draw_indexed, void(const RenderPassEncoder&, const CmdDrawIndexedOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_vertex_buffer, void(const RenderPassEncoder&, const CmdBindVertexBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_vertex_buffers, void(const RenderPassEncoder&, const CmdBindVertexBuffersOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_index_buffer, void(const RenderPassEncoder&, const CmdBindIndexBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_descriptor_sets, void(const RenderPassEncoder&, const CmdBindDescriptorSetsOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_end_render_pass, void(const Handle<CommandBuffer>&, const RenderPassEncoder&));

PRO_DEF_FACADE(IRenderBackend, PRO_MAKE_DISPATCH_PACK(
                               init,
                               shutdown,
                               get_type,
                               device_wait_idle,
                               queue_wait_idle,
                               queue_submit,
                               queue_present,
                               create_swapchain,
                               acquire_next_image,
                               get_swapchain_image_count,
                               get_swapchain_back_buffer,
                               destroy_swapchain,
                               create_fence,
                               wait_for_fence,
                               wait_for_fences,
                               reset_fences,
                               destroy_fence,
                               create_semaphore,
                               destroy_semaphore,
                               create_shader,
                               destroy_shader,
                               create_pipeline_layout,
                               destroy_pipeline_layout,
                               create_graphics_pipeline,
                               destroy_graphics_pipeline,
                               create_texture,
                               get_texture_width,
                               get_texture_height,
                               destroy_texture,
                               create_sampler,
                               destroy_sampler,
                               create_buffer,
                               map_buffer,
                               unmap_buffer,
                               destroy_buffer,
                               create_framebuffer,
                               destroy_framebuffer,
                               create_descriptor_set_layout,
                               destroy_descriptor_set_layout,
                               create_descriptor_set,
                               update_descriptor_set,
                               destroy_descriptor_set,
                               create_command_pool,
                               destroy_command_pool,
                               allocate_command_buffer,
                               reset_command_buffer,
                               free_command_buffer,

                               cmd_begin,
                               cmd_copy_buffer,
                               cmd_copy_buffer_to_texture,
                               cmd_end,
                               cmd_pipeline_barrier,

                               cmd_begin_render_pass,
                               cmd_bind_pipeline,
                               cmd_set_viewport,
                               cmd_set_scissor,
                               cmd_draw,
                               cmd_draw_indexed,
                               cmd_bind_vertex_buffer,
                               cmd_bind_vertex_buffers,
                               cmd_bind_index_buffer,
                               cmd_bind_descriptor_sets,
                               cmd_end_render_pass));
} // namespace spec

struct IRenderBackend {
    virtual ~IRenderBackend() = default;

    /////// General
    virtual void              initialize(const InitBackendOptions& options) = 0;
    virtual void              finalize()                                    = 0;
    virtual BackendType::Enum get_type() const CLAY_NOEXCEPT                = 0;

    /////// Device
    virtual void device_wait_idle() = 0;

    /////// Queue
    virtual Handle<Queue>         get_queue(const QueueType::Enum& queue_type)                                  = 0;
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
    virtual Handle<Fence> create_fence(bool signal) = 0;
    inline void           wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout) { wait_for_fences(&fence, 1, wait_all, timeout); }
    virtual void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) = 0;
    inline void           reset_fence(const Handle<Fence>& fence) { reset_fences(&fence, 1); }
    virtual void          reset_fences(const Handle<Fence>* fences, int num_fence) = 0;
    virtual void          destroy_fence(const Handle<Fence>& fence)                = 0;

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
    virtual Handle<CommandPool> create_command_pool(const Handle<Queue> queue)        = 0;
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

extern pro::proxy<spec::IRenderBackend> g_backend_proxy;

bool                     init(const InitBackendOptions& desc);
void                     shutdown();
inline BackendType::Enum get_type() { return g_backend_proxy.get_type(); }

inline void device_wait_idle() { g_backend_proxy.device_wait_idle(); }

inline void                  queue_wait_idle(QueueType::Enum queue_type) { g_backend_proxy.queue_wait_idle(queue_type); }
inline void                  queue_submit(QueueType::Enum queue_type, const QueueSubmitOptions& options) { g_backend_proxy.queue_submit(queue_type, options); }
inline SwapchainStatus::Enum queue_present(const QueuePresentOptions& options) { return g_backend_proxy.queue_present(options); }

inline Handle<Swapchain>      create_swapchain(const CreateSwapchainOptions& desc) { return g_backend_proxy.create_swapchain(desc); }
inline SwapchainAcquireResult acquire_next_image(const Handle<Swapchain>& swapchain, const AcquireNextImageOptions& desc) { return g_backend_proxy.acquire_next_image(swapchain, desc); }
inline u32                    get_swapchain_image_count(const Handle<Swapchain>& swapchain) { return g_backend_proxy.get_swapchain_image_count(swapchain); }
inline Handle<Texture>        get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index) { return g_backend_proxy.get_swapchain_back_buffer(swapchain, index); }
inline void                   destroy_swapchain(const Handle<Swapchain>& swapchain) { g_backend_proxy.destroy_swapchain(swapchain); }

inline Handle<Fence> create_fence(bool signal) { return g_backend_proxy.create_fence(signal); }
inline void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout) { g_backend_proxy.wait_for_fence(fence, wait_all, timeout); }
inline void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) { g_backend_proxy.wait_for_fences(fences, num_fence, wait_all, timeout); }
inline void          reset_fences(const Handle<Fence>* fences, int num_fence) { g_backend_proxy.reset_fences(fences, num_fence); }
inline void          destroy_fence(const Handle<Fence>& fence) { g_backend_proxy.destroy_fence(fence); }

inline Handle<Semaphore> create_semaphore() { return g_backend_proxy.create_semaphore(); }
inline void              destroy_semaphore(const Handle<Semaphore>& semaphore) { g_backend_proxy.destroy_semaphore(semaphore); }

inline Handle<Shader> create_shader(const CreateShaderOptions& desc) { return g_backend_proxy.create_shader(desc); }
inline void           destroy_shader(const Handle<Shader>& shader) { g_backend_proxy.destroy_shader(shader); }

inline Handle<PipelineLayout> create_pipeline_layout(const CreatePipelineLayoutOptions& desc) { return g_backend_proxy.create_pipeline_layout(desc); }
inline void                   destroy_pipeline_layout(const Handle<PipelineLayout>& layout) { g_backend_proxy.destroy_pipeline_layout(layout); }

inline Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc) { return g_backend_proxy.create_graphics_pipeline(desc); }
inline void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline) { g_backend_proxy.destroy_graphics_pipeline(pipeline); }

inline Handle<Texture> create_texture(const CreateTextureOptions& desc) { return g_backend_proxy.create_texture(desc); }
inline u32             get_texture_width(const Handle<Texture>& texture) { return g_backend_proxy.get_texture_width(texture); }
inline u32             get_texture_height(const Handle<Texture>& texture) { return g_backend_proxy.get_texture_height(texture); }
inline void            destroy_texture(const Handle<Texture>& texture) { g_backend_proxy.destroy_texture(texture); }

inline Handle<Sampler> create_sampler(const CreateSamplerOptions& desc) { return g_backend_proxy.create_sampler(desc); }
inline void            destroy_sampler(const Handle<Sampler>& sampler) { g_backend_proxy.destroy_sampler(sampler); }

inline Handle<Buffer> create_buffer(const CreateBufferOptions& desc) { return g_backend_proxy.create_buffer(desc); }
inline void*          map_buffer(const Handle<Buffer>& buffer) { return g_backend_proxy.map_buffer(buffer); }
inline void           unmap_buffer(const Handle<Buffer>& buffer) { g_backend_proxy.unmap_buffer(buffer); }
inline void           destroy_buffer(const Handle<Buffer>& buffer) { g_backend_proxy.destroy_buffer(buffer); }

inline Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& desc) { return g_backend_proxy.create_framebuffer(desc); }
inline void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer) { g_backend_proxy.destroy_framebuffer(framebuffer); }

inline Handle<DescriptorSetLayout> create_descriptor_set_layout(const CreateDescriptorSetLayoutOptions& desc) { return g_backend_proxy.create_descriptor_set_layout(desc); }
inline void                        destroy_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout) { g_backend_proxy.destroy_descriptor_set_layout(layout); }

inline Handle<DescriptorSet> create_descriptor_set(const CreateDescriptorSetOptions& desc) { return g_backend_proxy.create_descriptor_set(desc); }
inline void                  update_descriptor_set(const Handle<DescriptorSet>& set, const UpdateDescriptorSetOptions& desc) { g_backend_proxy.update_descriptor_set(set, desc); }
inline void                  destroy_descriptor_set(const Handle<DescriptorSet>& set) { g_backend_proxy.destroy_descriptor_set(set); }

inline Handle<CommandPool> create_command_pool(QueueType::Enum queue_type) { return g_backend_proxy.create_command_pool(queue_type); }
inline void                destroy_command_pool(const Handle<CommandPool>& pool) { g_backend_proxy.destroy_command_pool(pool); }

inline Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool) { return g_backend_proxy.allocate_command_buffer(pool); }
inline void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource) { g_backend_proxy.reset_command_buffer(buffer, release_resource); }
inline void                  free_command_buffer(const Handle<CommandBuffer>& buffer) { g_backend_proxy.free_command_buffer(buffer); }

inline void cmd_begin(const Handle<CommandBuffer>& buffer, bool one_time) { g_backend_proxy.cmd_begin(buffer, one_time); }
inline void cmd_end(const Handle<CommandBuffer>& buffer) { g_backend_proxy.cmd_end(buffer); }
inline void cmd_copy_buffer(const Handle<CommandBuffer>& buffer, const CmdCopyBufferOptions& copy_buffer) { g_backend_proxy.cmd_copy_buffer(buffer, copy_buffer); }
inline void cmd_copy_buffer_to_texture(const Handle<CommandBuffer>& buffer, const CmdCopyBufferToTextureOptions& copy_buffer) { g_backend_proxy.cmd_copy_buffer_to_texture(buffer, copy_buffer); }
inline void cmd_pipeline_barrier(const Handle<CommandBuffer>& buffer, const CmdPipelineBarrierOptions& barrier) { g_backend_proxy.cmd_pipeline_barrier(buffer, barrier); }

inline RenderPassEncoder cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options) { return g_backend_proxy.cmd_begin_render_pass(buffer, options); }
inline void              cmd_bind_pipeline(const RenderPassEncoder& encoder, const Handle<GraphicsPipeline>& pipeline) { g_backend_proxy.cmd_bind_pipeline(encoder, pipeline); }
inline void              cmd_set_viewport(const RenderPassEncoder& encoder, const CmdSetViewportOptions& viewport) { g_backend_proxy.cmd_set_viewport(encoder, viewport); }
inline void              cmd_set_scissor(const RenderPassEncoder& encoder, const CmdSetScissorOptions& scissor) { g_backend_proxy.cmd_set_scissor(encoder, scissor); }
inline void              cmd_draw(const RenderPassEncoder& encoder, const CmdDrawOptions& draw) { g_backend_proxy.cmd_draw(encoder, draw); }
inline void              cmd_draw_indexed(const RenderPassEncoder& encoder, const CmdDrawIndexedOptions& draw) { g_backend_proxy.cmd_draw_indexed(encoder, draw); }
inline void              cmd_bind_vertex_buffer(const RenderPassEncoder& encoder, const CmdBindVertexBufferOptions& vertex_buffer) { g_backend_proxy.cmd_bind_vertex_buffer(encoder, vertex_buffer); }
inline void              cmd_bind_vertex_buffers(const RenderPassEncoder& encoder, const CmdBindVertexBuffersOptions& vertex_buffers) { g_backend_proxy.cmd_bind_vertex_buffers(encoder, vertex_buffers); }
inline void              cmd_bind_index_buffer(const RenderPassEncoder& encoder, const CmdBindIndexBufferOptions& index_buffer) { g_backend_proxy.cmd_bind_index_buffer(encoder, index_buffer); }
inline void              cmd_bind_descriptor_sets(const RenderPassEncoder& encoder, const CmdBindDescriptorSetsOptions& descriptor_sets) { g_backend_proxy.cmd_bind_descriptor_sets(encoder, descriptor_sets); }
inline void              cmd_end_render_pass(const Handle<CommandBuffer>& buffer, const RenderPassEncoder& encoder) { g_backend_proxy.cmd_end_render_pass(buffer, encoder); }

} // namespace gfx
} // namespace clay