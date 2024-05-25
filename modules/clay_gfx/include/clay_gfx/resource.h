#pragma once

#include "define.h"
#include <clay_gfx/define.h>
#include <clay_core/macro.h>
#include <optional>

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
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Sampler)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Shader)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Pipeline)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(RenderPass)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Framebuffer)

struct TextureViewDesc {
    std::optional<Format::Enum>   format;
    TextureViewType::Enum         view_type;
    TextureAspect::Flag           aspect_flags;
    u8                            base_mip_level{ 0 };
    u8                            level_count{ 1 };
    u8                            base_array_layer{ 0 };
    u8                            layer_count{ 1 };
    TextureComponentSwizzle::Enum component_r{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_g{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_b{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_a{ TextureComponentSwizzle::Identity };
};
} // namespace gfx
} // namespace clay