#pragma once

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
        Count
    };
};

struct RenderBackendCreateDesc {
    RenderBackendType::Enum type;
    bool                    debug{ false };
};

class RenderBackend
{
protected:
    flecs::world world;
};

static RenderBackend* s_backend = nullptr;
bool                  init(const RenderBackendCreateDesc& desc);
void                  shutdown();

} // namespace gfx
} // namespace clay