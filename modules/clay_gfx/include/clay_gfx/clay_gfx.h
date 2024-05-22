#pragma once

#include <clay_core/macro.h>
#include <flecs.h>

#define DEFINE_CLAY_GFX_HANDLE(name) \
    struct name##Handle {            \
        flecs::entity entity;        \
    };

namespace clay
{
namespace gfx
{

DEFINE_CLAY_GFX_HANDLE(Buffer)
DEFINE_CLAY_GFX_HANDLE(Texture)
DEFINE_CLAY_GFX_HANDLE(Sampler)
DEFINE_CLAY_GFX_HANDLE(Shader)
DEFINE_CLAY_GFX_HANDLE(Pipeline)
DEFINE_CLAY_GFX_HANDLE(RenderPass)
DEFINE_CLAY_GFX_HANDLE(Framebuffer)

struct RenderBackendType {
    enum Enum
    {
        Vulkan,
        DirectX12,
        Metal,
        Count
    };
};

struct RenderBackendCreateDesc {
    RenderBackendType::Enum type;
    void*                   window; // Maybe SDL_Window* or any other window handle
    u32                     device_id{ u32_MAX };
    bool                    debug{ false };
};

struct RenderBackend {
    RenderBackendType::Enum type;
    flecs::world            world;

    RenderBackend(RenderBackendType::Enum _type)
        : type(_type)
        , world(flecs::world())
    {
    }
    virtual ~RenderBackend() = default;
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
void                  shutdown();

} // namespace gfx
} // namespace clay