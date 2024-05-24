#pragma once

#include <clay_core/macro.h>

#define DEFINE_CLAY_GFX_RESOURCE_HANDLE(name) \
    struct name##Handle {                     \
        u64 id;                               \
    };                                        \
    static const name##Handle Invalid##name##Handle = { u64_MAX };

namespace clay
{
namespace gfx
{
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Buffer)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Texture)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(TextureView)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Sampler)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Shader)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Pipeline)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(RenderPass)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Framebuffer)
} // namespace gfx
} // namespace clay