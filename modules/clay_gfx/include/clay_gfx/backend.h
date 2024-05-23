#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/define.h>

namespace clay
{
namespace gfx
{
struct RenderBackendCreateDesc {
    RenderBackendType::Enum type;
    void*                   window; // Maybe SDL_Window* or any other window handle
    const char*             app_name{ nullptr };
    u32                     device_id{ u32_MAX };
    bool                    debug{ false };
};

struct RenderBackend {
private:
    RenderBackendType::Enum type;

public:
    RenderBackend(RenderBackendType::Enum _type)
        : type(_type)
    {
    }
    virtual ~RenderBackend() = default;

    /////// API ///////
public:
    virtual bool                   init(const RenderBackendCreateDesc& desc) = 0;
    inline RenderBackendType::Enum get_type() const { return type; }
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
RenderBackend*        get_backend();
void                  shutdown();

} // namespace gfx
} // namespace clay