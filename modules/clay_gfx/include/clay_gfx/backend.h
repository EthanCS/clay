#pragma once

#include <clay_core/macro.h>
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
    virtual FenceHandle create_fence(bool signal)                                                             = 0;
    virtual void        wait_for_fence(const FenceHandle& fence, bool wait_all, u64 timeout)                  = 0;
    virtual void        wait_for_fences(const FenceHandle* fences, int num_fence, bool wait_all, u64 timeout) = 0;
    virtual void        destroy_fence(const FenceHandle& fence)                                               = 0;

    /////// Semaphore
    virtual SemaphoreHandle create_semaphore()                                  = 0;
    virtual void            destroy_semaphore(const SemaphoreHandle& semaphore) = 0;

    /////// Shader
    virtual ShaderHandle create_shader(const ShaderCreateDesc& desc) = 0;
    virtual void         destroy_shader(const ShaderHandle& shader)  = 0;

    /////// Pipeline
    virtual GraphicsPipelineHandle create_graphics_pipeline(const GraphicsPipelineCreateDesc& desc)  = 0;
    virtual void                   destroy_graphics_pipeline(const GraphicsPipelineHandle& pipeline) = 0;

    /////// Texture
    virtual void destroy_texture(const TextureHandle& texture) = 0;
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
RenderBackend*        backend();
void                  shutdown();

} // namespace gfx
} // namespace clay