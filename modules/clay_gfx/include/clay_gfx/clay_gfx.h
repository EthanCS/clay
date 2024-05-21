#pragma once

#include <flecs.h>
#include <clay_core/clay_core.h>

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
        Count
    };
};

struct RenderBackendCreateDesc {
    RenderBackendType::Enum type;
    bool                    debug{ false };
    u32                     device_id{ u32_MAX };
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