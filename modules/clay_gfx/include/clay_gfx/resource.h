#pragma once

#include <clay_core/macro.h>

#ifdef __IMPL_INVALID_HANDLE
    #define DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name) \
        const name##Handle name##Handle::Invalid = { u64_MAX };
#else
    #define DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name)
#endif

#define DEFINE_CLAY_GFX_RESOURCE_HANDLE(name)          \
    struct name##Handle {                              \
        u64                       id;                  \
        static const name##Handle Invalid;             \
                                                       \
        bool operator==(const name##Handle& rhs) const \
        {                                              \
            return id == rhs.id;                       \
        }                                              \
    };                                                 \
    DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name)

namespace clay
{
namespace gfx
{
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Fence)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Semaphore)
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