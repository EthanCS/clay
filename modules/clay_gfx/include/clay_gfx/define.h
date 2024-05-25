#pragma once

namespace clay
{
namespace gfx
{
struct BackendType {
    enum Enum
    {
        Vulkan,
        DirectX12,
        Metal,
        Count
    };
};

struct QueueType {
    enum Enum
    {
        Graphics,
        Present,
        Compute,
        Transfer,
    };
};

struct Format {
    enum Enum
    {
        Unknown,
        D32_SFLOAT,
        D32_SFLOAT_S8_UINT,
        D24_UNORM_S8_UINT,
        B8G8R8A8_UNORM,
        B8G8R8A8_SRGB,
        R8G8B8A8_UNORM,
        R8G8B8A8_SRGB,
        B8G8R8_UNORM,
        B8G8R8_SRGB,
        R8G8B8_UNORM,
        R8G8B8_SRGB,
        R32_SFLOAT,
        R32G32_SFLOAT,
        R32G32B32_SFLOAT,
        R32G32B32A32_SFLOAT,
    };
};

struct TextureComponentSwizzle {
    enum Enum
    {
        Identity,
        Zero,
        One,
        R,
        G,
        B,
        A,
    };
};

struct TextureAspect {
    enum Flag : char
    {
        Color   = 1 << 0,
        Depth   = 1 << 1,
        Stencil = 1 << 2,
    };
};

struct TextureViewType {
    enum Enum
    {
        Texture1D,
        Texture2D,
        Texture3D,
        TextureCube,
        Texture1DArray,
        Texture2DArray,
        TextureCubeArray,
    };
};
} // namespace gfx
} // namespace clay