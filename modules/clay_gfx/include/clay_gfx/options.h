#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/resource.h>

namespace clay
{
namespace gfx
{
struct InitBackendOptions {
    BackendType::Enum type;
    void*             window; // Maybe SDL_Window* or any other window handle
    const char*       app_name{ nullptr };
    u32               device_id{ u32_MAX };
    bool              debug{ false };
};

struct CreateSwapchainOptions {
    u32          width  = 0;
    u32          height = 0;
    bool         vsync  = false;
    Format::Enum format = Format::Undefined;
};

struct CreateShaderOptions {
    const char* code        = nullptr;
    u32         code_size   = 0;
};

struct CreateBufferOptions {
    u64               size = 0;
    BufferUsage::Flag usage;
    bool              exclusive{ true };
};

struct AcquireNextImageOptions {
    u64               time_out  = u64_MAX;
    Handle<Semaphore> semaphore = {};
    Handle<Fence>     fence     = {};
};

struct QueueSubmitOptions {
    Handle<CommandBuffer>* command_buffers       = nullptr;
    u32                    num_command_buffers   = 0;
    Handle<Semaphore>*     wait_semaphores       = nullptr;
    u32                    num_wait_semaphores   = 0;
    Handle<Semaphore>*     signal_semaphores     = nullptr;
    u32                    num_signal_semaphores = 0;
    PipelineStage::Flag    wait_dst_stage        = PipelineStage::TopOfPipe;
    Handle<Fence>          fence                 = {};
};

struct QueuePresentOptions {
    Handle<Swapchain>  swapchain           = {};
    u32                image_index         = 0;
    Handle<Semaphore>* wait_semaphores     = nullptr;
    u32                num_wait_semaphores = 0;
};

struct CreateFramebufferOptions {
    u32              width  = 0;
    u32              height = 0;
    TextureViewDesc  color_attachments[MAX_COLOR_ATTACHMENTS];
    TextureViewDesc  depth_stencil_attachment;
    RenderPassLayout render_pass_layout;
};

struct CreateGraphicsPipelineOptions {
    const char* name = nullptr;

    ShaderInfo vertex_shader;
    ShaderInfo pixel_shader;

    GraphicsState graphics_state;
};

struct CmdBeginRenderPassOptions {
    Handle<Framebuffer> framebuffer;
    RenderPassLayout    render_pass_layout;
    i32                 offset[2] = { 0, 0 };
    u32                 extent[2] = { 0, 0 };
    bool                clear     = true;
    ClearValue          clear_values[MAX_ATTACHMENTS];
};

struct CmdSetViewportOptions {
    f32 x         = 0.0f;
    f32 y         = 0.0f;
    f32 width     = 0.0f;
    f32 height    = 0.0f;
    f32 min_depth = 0.0f;
    f32 max_depth = 1.0f;
};

struct CmdSetScissorOptions {
    i32 offset[2] = { 0, 0 };
    u32 extent[2] = { 0, 0 };
};

struct CmdDrawOptions {
    u32 vertex_count   = 0;
    u32 instance_count = 1;
    u32 first_vertex   = 0;
    u32 first_instance = 0;
};

struct CmdDrawIndexedOptions {
    u32 index_count    = 0;
    u32 instance_count = 1;
    u32 first_index    = 0;
    i32 vertex_offset  = 0;
    u32 first_instance = 0;
};

struct CmdBindVertexBufferOptions {
    u32            binding = 0;
    Handle<Buffer> buffer;
    u32            offset = 0;
};

struct CmdBindVertexBuffersOptions {
    u32             first_binding = 0;
    u32             binding_count = 0;
    Handle<Buffer>* buffers       = nullptr;
    u32*            offsets       = nullptr;
};

struct CmdBindIndexBufferOptions {
    Handle<Buffer>  buffer;
    u32             offset = 0;
    IndexType::Enum index_type;
};

struct CmdCopyBufferOptions {
    Handle<Buffer> src_buffer;
    u64            src_offset;
    Handle<Buffer> dst_buffer;
    u64            dst_offset;
    u64            size;
};

} // namespace gfx
} // namespace clay