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

/////// GraphicsPipeline
PRO_DEF_MEMBER_DISPATCH(create_graphics_pipeline, Handle<GraphicsPipeline>(const CreateGraphicsPipelineOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_graphics_pipeline, void(const Handle<GraphicsPipeline>&));

/////// Texture
PRO_DEF_MEMBER_DISPATCH(get_texture_width, u32(const Handle<Texture>&));
PRO_DEF_MEMBER_DISPATCH(get_texture_height, u32(const Handle<Texture>&));
PRO_DEF_MEMBER_DISPATCH(destroy_texture, void(const Handle<Texture>&));

/////// Buffer
PRO_DEF_MEMBER_DISPATCH(create_buffer, Handle<Buffer>(const CreateBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(map_buffer, void*(const Handle<Buffer>&, u32, u32));
PRO_DEF_MEMBER_DISPATCH(unmap_buffer, void(const Handle<Buffer>&));
PRO_DEF_MEMBER_DISPATCH(destroy_buffer, void(const Handle<Buffer>&));

/////// Framebuffer
PRO_DEF_MEMBER_DISPATCH(create_framebuffer, Handle<Framebuffer>(const CreateFramebufferOptions&));
PRO_DEF_MEMBER_DISPATCH(destroy_framebuffer, void(const Handle<Framebuffer>&));

/////// CommandPool
PRO_DEF_MEMBER_DISPATCH(create_command_pool, Handle<CommandPool>(QueueType::Enum));
PRO_DEF_MEMBER_DISPATCH(destroy_command_pool, void(const Handle<CommandPool>&));

/////// CommandBuffer
PRO_DEF_MEMBER_DISPATCH(allocate_command_buffer, Handle<CommandBuffer>(const Handle<CommandPool>&));
PRO_DEF_MEMBER_DISPATCH(reset_command_buffer, void(const Handle<CommandBuffer>&, bool));
PRO_DEF_MEMBER_DISPATCH(free_command_buffer, void(const Handle<CommandBuffer>&));

/////// Command
PRO_DEF_MEMBER_DISPATCH(cmd_begin, void(const Handle<CommandBuffer>&));
PRO_DEF_MEMBER_DISPATCH(cmd_end, void(const Handle<CommandBuffer>&));
PRO_DEF_MEMBER_DISPATCH(cmd_begin_render_pass, void(const Handle<CommandBuffer>&, const CmdBeginRenderPassOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_end_render_pass, void(const Handle<CommandBuffer>&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_graphics_pipeline, void(const Handle<CommandBuffer>&, const Handle<GraphicsPipeline>&));
PRO_DEF_MEMBER_DISPATCH(cmd_set_viewport, void(const Handle<CommandBuffer>&, const CmdSetViewportOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_set_scissor, void(const Handle<CommandBuffer>&, const CmdSetScissorOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_draw, void(const Handle<CommandBuffer>&, const CmdDrawOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_vertex_buffer, void(const Handle<CommandBuffer>&, const CmdBindVertexBufferOptions&));
PRO_DEF_MEMBER_DISPATCH(cmd_bind_vertex_buffers, void(const Handle<CommandBuffer>&, const CmdBindVertexBuffersOptions&));

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
                               create_graphics_pipeline,
                               destroy_graphics_pipeline,
                               get_texture_width,
                               get_texture_height,
                               destroy_texture,
                               create_buffer,
                               map_buffer,
                               unmap_buffer,
                               destroy_buffer,
                               create_framebuffer,
                               destroy_framebuffer,
                               create_command_pool,
                               destroy_command_pool,
                               allocate_command_buffer,
                               reset_command_buffer,
                               free_command_buffer,
                               cmd_begin,
                               cmd_end,
                               cmd_begin_render_pass,
                               cmd_end_render_pass,
                               cmd_bind_graphics_pipeline,
                               cmd_set_viewport,
                               cmd_set_scissor,
                               cmd_draw,
                               cmd_bind_vertex_buffer,
                               cmd_bind_vertex_buffers));
} // namespace spec

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

inline Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc) { return g_backend_proxy.create_graphics_pipeline(desc); }
inline void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline) { g_backend_proxy.destroy_graphics_pipeline(pipeline); }

inline u32  get_texture_width(const Handle<Texture>& texture) { return g_backend_proxy.get_texture_width(texture); }
inline u32  get_texture_height(const Handle<Texture>& texture) { return g_backend_proxy.get_texture_height(texture); }
inline void destroy_texture(const Handle<Texture>& texture) { g_backend_proxy.destroy_texture(texture); }

inline Handle<Buffer> create_buffer(const CreateBufferOptions& desc) { return g_backend_proxy.create_buffer(desc); }
inline void*          map_buffer(const Handle<Buffer>& buffer, u32 offset, u32 size) { return g_backend_proxy.map_buffer(buffer, offset, size); }
inline void           unmap_buffer(const Handle<Buffer>& buffer) { g_backend_proxy.unmap_buffer(buffer); }
inline void           destroy_buffer(const Handle<Buffer>& buffer) { g_backend_proxy.destroy_buffer(buffer); }

inline Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& desc) { return g_backend_proxy.create_framebuffer(desc); }
inline void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer) { g_backend_proxy.destroy_framebuffer(framebuffer); }

inline Handle<CommandPool> create_command_pool(QueueType::Enum queue_type) { return g_backend_proxy.create_command_pool(queue_type); }
inline void                destroy_command_pool(const Handle<CommandPool>& pool) { g_backend_proxy.destroy_command_pool(pool); }

inline Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool) { return g_backend_proxy.allocate_command_buffer(pool); }
inline void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource) { g_backend_proxy.reset_command_buffer(buffer, release_resource); }
inline void                  free_command_buffer(const Handle<CommandBuffer>& buffer) { g_backend_proxy.free_command_buffer(buffer); }

inline void cmd_begin(const Handle<CommandBuffer>& buffer) { g_backend_proxy.cmd_begin(buffer); }
inline void cmd_end(const Handle<CommandBuffer>& buffer) { g_backend_proxy.cmd_end(buffer); }
inline void cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options) { g_backend_proxy.cmd_begin_render_pass(buffer, options); }
inline void cmd_end_render_pass(const Handle<CommandBuffer>& buffer) { g_backend_proxy.cmd_end_render_pass(buffer); }
inline void cmd_bind_graphics_pipeline(const Handle<CommandBuffer>& buffer, const Handle<GraphicsPipeline>& pipeline) { g_backend_proxy.cmd_bind_graphics_pipeline(buffer, pipeline); }
inline void cmd_set_viewport(const Handle<CommandBuffer>& buffer, const CmdSetViewportOptions& viewport) { g_backend_proxy.cmd_set_viewport(buffer, viewport); }
inline void cmd_set_scissor(const Handle<CommandBuffer>& buffer, const CmdSetScissorOptions& scissor) { g_backend_proxy.cmd_set_scissor(buffer, scissor); }
inline void cmd_draw(const Handle<CommandBuffer>& buffer, const CmdDrawOptions& draw) { g_backend_proxy.cmd_draw(buffer, draw); }
inline void cmd_bind_vertex_buffer(const Handle<CommandBuffer>& buffer, const CmdBindVertexBufferOptions& vertex_buffer) { g_backend_proxy.cmd_bind_vertex_buffer(buffer, vertex_buffer); }
inline void cmd_bind_vertex_buffers(const Handle<CommandBuffer>& buffer, const CmdBindVertexBuffersOptions& vertex_buffers) { g_backend_proxy.cmd_bind_vertex_buffers(buffer, vertex_buffers); }

} // namespace gfx
} // namespace clay