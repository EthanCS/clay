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
    RenderBackendType::Enum type;

    RenderBackend(RenderBackendType::Enum _type)
        : type(_type)
    {
    }

    virtual ~RenderBackend() = default;
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
void                  shutdown();

} // namespace gfx
} // namespace clay