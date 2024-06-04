#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/handle.h>
#include <clay_gfx/define.h>
#include <clay_gfx/resource.h>

namespace clay
{
namespace gfx
{
struct RenderBackendCreateDesc {
    BackendType::Enum type;
    void*             window; // Maybe SDL_Window* or any other window handle
    u32               width;
    u32               height;
    bool              vsync;
    Format::Enum      format;
    const char*       app_name{ nullptr };
    u32               device_id{ u32_MAX };
    bool              debug{ false };
};

struct RenderBackend {
private:
    BackendType::Enum type;

public:
    RenderBackend(BackendType::Enum _type)
        : type(_type)
    {
    }
    virtual ~RenderBackend()                               = default;
    virtual bool init(const RenderBackendCreateDesc& desc) = 0;

    /////// API ///////
public:
    inline BackendType::Enum get_type() const { return type; }

    /////// Device
    virtual void device_wait_idle() = 0;

    /////// Queue
    virtual void queue_wait_idle(QueueType::Enum queue_type) = 0;

    /////// Fence
    virtual Handle<Fence> create_fence(bool signal)                                                               = 0;
    virtual void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout)                  = 0;
    virtual void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) = 0;
    virtual void          destroy_fence(const Handle<Fence>& fence)                                               = 0;

    /////// Semaphore
    virtual Handle<Semaphore> create_semaphore()                                    = 0;
    virtual void              destroy_semaphore(const Handle<Semaphore>& semaphore) = 0;

    /////// Shader
    virtual Handle<Shader> create_shader(const ShaderCreateDesc& desc)  = 0;
    virtual void           destroy_shader(const Handle<Shader>& shader) = 0;

    /////// Pipeline
    virtual Handle<GraphicsPipeline> create_graphics_pipeline(const GraphicsPipelineCreateDesc& desc)    = 0;
    virtual void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline) = 0;

    /////// Texture
    virtual void destroy_texture(const Handle<Texture>& texture) = 0;

    /////// Command Pool
    virtual Handle<CommandPool> create_command_pool(QueueType::Enum queue_type)       = 0;
    virtual void                destroy_command_pool(const Handle<CommandPool>& pool) = 0;

    /////// Command Buffer
    virtual Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool) = 0;
    virtual void                  free_command_buffer(const Handle<CommandBuffer>& buffer) = 0;

    /////// CMDs
    virtual void cmd_begin(const Handle<CommandBuffer>& buffer)                                                            = 0;
    virtual void cmd_end(const Handle<CommandBuffer>& buffer)                                                              = 0;
    virtual void cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options)      = 0;
    virtual void cmd_end_render_pass(const Handle<CommandBuffer>& buffer)                                                  = 0;
    virtual void cmd_bind_graphics_pipeline(const Handle<CommandBuffer>& buffer, const Handle<GraphicsPipeline>& pipeline) = 0;
    virtual void cmd_set_viewport(const Handle<CommandBuffer>& buffer, const CmdSetViewportOptions& viewport)              = 0;
    virtual void cmd_set_scissor(const Handle<CommandBuffer>& buffer, const CmdSetScissorOptions& scissor)                 = 0;
    virtual void cmd_draw(const Handle<CommandBuffer>& buffer, const CmdDrawOptions& draw)                                 = 0;
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
RenderBackend*        backend();
void                  shutdown();

} // namespace gfx
} // namespace clay