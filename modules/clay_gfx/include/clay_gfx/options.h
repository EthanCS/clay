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

struct AcquireNextImageOptions {
    Handle<Swapchain> swapchain = Handle<Swapchain>();
    u64               time_out  = u64_MAX;
    Handle<Semaphore> semaphore = Handle<Semaphore>();
    Handle<Fence>     fence     = Handle<Fence>();
};

struct QueueSubmitOptions {
    Handle<CommandBuffer>* command_buffers       = nullptr;
    u32                    num_command_buffers   = 0;
    Handle<Semaphore>*     wait_semaphores       = nullptr;
    u32                    num_wait_semaphores   = 0;
    Handle<Semaphore>*     signal_semaphores     = nullptr;
    u32                    num_signal_semaphores = 0;
    PipelineStage::Flag    wait_dst_stage        = PipelineStage::TopOfPipe;
    Handle<Fence>          fence                 = Handle<Fence>();
};

struct QueuePresentOptions {
    Handle<Swapchain>  swapchain           = Handle<Swapchain>();
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

struct CmdBeginRenderPassOptions {
    Handle<Framebuffer> framebuffer;
    RenderPassLayout    render_pass_layout;
    i32                 offset[2] = { 0, 0 };
    u32                 extent[2] = { 0, 0 };
    bool                clear     = true;
    ClearValue          clear_values[MAX_ATTACHMENTS];
};

struct CmdSetViewportOptions {
    u32 x         = 0;
    u32 y         = 0;
    u32 width     = 0;
    u32 height    = 0;
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

} // namespace gfx
} // namespace clay