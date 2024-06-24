#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace gfx
{
static const u8 MAX_SWAPCHAIN_IMAGES  = 3;
static const u8 MAX_SHADER_STAGES     = 5;
static const u8 MAX_COLOR_ATTACHMENTS = 8;
static const u8 MAX_ATTACHMENTS       = MAX_COLOR_ATTACHMENTS + 1; // color + depth/stencil
static const u8 MAX_VERTEX_ATTRIBUTES = 16;
static const u8 MAX_VERTEX_BINDINGS   = 16;

struct ClearValue {
    f32 color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    f32 depth;
    u32 stencil;
};

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
        Undefined = 0,
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
        Undefined = 0,
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
        DontCare = 0,
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

struct SwapchainStatus {
    enum Enum
    {
        Success = 0,
        OutOfDate,
        Suboptimal,
        Error,
    };
};

struct PipelineStage {
    enum Flag
    {
        TopOfPipe                    = 1 << 0,
        DrawIndirect                 = 1 << 1,
        VertexInput                  = 1 << 2,
        VertexShader                 = 1 << 3,
        TessellationControlShader    = 1 << 4,
        TessellationEvaluationShader = 1 << 5,
        GeometryShader               = 1 << 6,
        FragmentShader               = 1 << 7,
        EarlyFragmentTests           = 1 << 8,
        LateFragmentTests            = 1 << 9,
        ColorAttachmentOutput        = 1 << 10,
        ComputeShader                = 1 << 11,
        Transfer                     = 1 << 12,
        BottomOfPipe                 = 1 << 13,
        Host                         = 1 << 14,
        AllGraphics                  = 1 << 15,
        AllCommands                  = 1 << 16,
    };
};

} // namespace gfx
} // namespace clay