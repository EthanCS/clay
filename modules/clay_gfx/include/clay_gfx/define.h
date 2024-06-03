#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace gfx
{
static const u8 MAX_SWAPCHAIN_IMAGES  = 3;
static const u8 MAX_SHADER_STAGES     = 5;
static const u8 MAX_COLOR_ATTACHMENTS = 8;
static const u8 MAX_VERTEX_ATTRIBUTES = 16;
static const u8 MAX_VERTEX_BINDINGS   = 16;

struct BackendType {
    enum Enum
    {
        Vulkan,
        DirectX12,
        Metal,
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

struct ShaderStage {
    enum Flag
    {
        Vertex   = 1 << 0,
        Fragment = 1 << 4,
        Compute  = 1 << 5,
    };
};

struct Format {
    enum Enum
    {
        Undefined,
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

struct ImageLayout {
    enum Enum
    {
        Undefined,
        General,
        ColorAttachmentOptimal,
        DepthStencilAttachmentOptimal,
        DepthStencilReadOnlyOptimal,
        ShaderReadOnlyOptimal,
        TransferSrcOptimal,
        TransferDstOptimal,
        Preinitialized,
        PresentSrc,
    };
};

struct RenderPassLoadOp {
    enum Enum
    {
        DontCare,
        Load,
        Clear,
    };
};

struct RenderPassStoreOp {
    enum Enum
    {
        DontCare,
        Store,
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

struct FillMode {
    enum Enum
    {
        Wireframe,
        Solid,
        Point,
    };
};

struct FrontFace {
    enum Enum
    {
        CounterClockwise,
        Clockwise,
    };
};

struct CullMode {
    enum Enum
    {
        None,
        Front,
        Back,
        FrontAndBack
    };
};

struct BlendFactor {
    enum Enum
    {
        Zero,
        One,
        SrcColor,
        OneMinusSrcColor,
        DstColor,
        OneMinusDstColor,
        SrcAlpha,
        OneMinusSrcAlpha,
        DstAlpha,
        OneMinusDstAlpha,
        ConstantColor,
        OneMinusConstantColor,
        ConstantAlpha,
        OneMinusConstantAlpha,
        SrcAlphaSaturate,
        Src1Color,
        OneMinusSrc1Color,
        Src1Alpha,
        OneMinusSrc1Alpha,
    };
};

struct BlendOp {
    enum Enum
    {
        Add,
        Subtract,
        ReverseSubtract,
        Min,
        Max,
    };
};

struct CompareOp {
    enum Enum
    {
        Never,
        Less,
        Equal,
        LessOrEqual,
        Greater,
        NotEqual,
        GreaterOrEqual,
        Always,
    };
};

struct StencilOp {
    enum Enum
    {
        Keep,
        Zero,
        Replace,
        IncrementAndClamp,
        DecrementAndClamp,
        Invert,
        IncrementAndWrap,
        DecrementAndWrap,
    };
};

struct ColorWriteEnabled {
    enum Flag : char
    {
        Red   = 1 << 0,
        Green = 1 << 1,
        Blue  = 1 << 2,
        Alpha = 1 << 3,
        All   = Red | Green | Blue | Alpha,
    };
};

struct PrimitiveTopology {
    enum Enum
    {
        PointList,
        LineList,
        LineStrip,
        TriangleList,
        TriangleStrip,
        TriangleFan,
    };
};
} // namespace gfx
} // namespace clay