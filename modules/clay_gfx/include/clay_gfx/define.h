#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace gfx
{
static const u8 MAX_SWAPCHAIN_IMAGES       = 3;
static const u8 MAX_SHADER_STAGES          = 5;
static const u8 MAX_COLOR_ATTACHMENTS      = 8;
static const u8 MAX_ATTACHMENTS            = MAX_COLOR_ATTACHMENTS + 1; // color + depth/stencil
static const u8 MAX_VERTEX_ATTRIBUTES      = 16;
static const u8 MAX_VERTEX_BINDINGS        = 16;
static const u8 MAX_DESCRIPTOR_SET_LAYOUTS = 8;
static const u8 MAX_DESCRIPTORS_PER_SET    = 16;
static const u8 MAX_BARRIERS               = 8;

struct ClearValue {
    f32 color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    f32 depth;
    u32 stencil;
};

////////////////////////////////////////////////////////////////////////
// Enums

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

struct LoadAction {
    enum Enum
    {
        DontCare = 0,
        Load,
        Clear,
    };
};

struct StoreAction {
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

struct TextureType {
    enum Enum
    {
        Texture1D,
        Texture2D,
        Texture3D,
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

struct IndexType {
    enum Enum
    {
        Uint16,
        Uint32,
    };
};

struct DescriptorType {
    enum Enum
    {
        Sampler,
        CombinedImageSampler,
        SampledImage,
        StorageImage,
        UniformTexelBuffer,
        StorageTexelBuffer,
        UniformBuffer,
        StorageBuffer,
        UniformBufferDynamic,
        StorageBufferDynamic,
        InputAttachment,
    };
};

struct PipelineBindPoint {
    enum Enum
    {
        Graphics,
        Compute,
    };
};

struct MemoryUsage {
    enum Enum
    {
        GpuOnly = 1,
        CpuOnly,
        CpuToGpu,
        GpuToCpu,
    };
};

struct FilterType {
    enum Enum
    {
        Nearest,
        Linear,
    };
};

struct MipmapType {
    enum Enum
    {
        Nearest,
        Linear,
    };
};

struct AddressMode {
    enum Enum
    {
        Mirror,
        Repeat,
        ClampToEdge,
        ClampToBorder,
    };
};

////////////////////////////////////////////////////////////////////////
// Flags

struct TextureAspect {
    enum Flag : char
    {
        Color   = 1 << 0,
        Depth   = 1 << 1,
        Stencil = 1 << 2,
    };
};

struct ShaderStage {
    enum Flag
    {
        Vertex   = 1 << 0,
        Fragment = 1 << 1,
        Compute  = 1 << 2,
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

struct BufferUsage {
    enum Flag
    {
        TransferSrc                             = 1 << 0,
        TransferDst                             = 1 << 1,
        UniformTexelBuffer                      = 1 << 2,
        StorageTexelBuffer                      = 1 << 3,
        UniformBuffer                           = 1 << 4,
        StorageBuffer                           = 1 << 5,
        IndexBuffer                             = 1 << 6,
        VertexBuffer                            = 1 << 7,
        IndirectBuffer                          = 1 << 8,
        ShaderDeviceAddress                     = 1 << 9,
        VideoDecodeSrc                          = 1 << 10,
        VideoDecodeDst                          = 1 << 11,
        TransformFeedbackBuffer                 = 1 << 12,
        TransformFeedbackCounterBuffer          = 1 << 13,
        ConditionalRendering                    = 1 << 14,
        AccelerationStructureBuildInputReadOnly = 1 << 15,
        AccelerationStructureStorage            = 1 << 16,
        ShaderBindingTable                      = 1 << 17,
        SamplerDescriptorBuffer                 = 1 << 18,
        ResourceDescriptorBuffer                = 1 << 19,
        PushDescriptorsDescriptorBuffer         = 1 << 20,
        MicromapBuildInputReadOnly              = 1 << 21,
        MicromapStorage                         = 1 << 22,
    };
};

struct TextureUsage {
    enum Flag
    {
        TransferSrc            = 1 << 0,
        TransferDst            = 1 << 1,
        Sampled                = 1 << 2,
        Storage                = 1 << 3,
        ColorAttachment        = 1 << 4,
        DepthStencilAttachment = 1 << 5,
        TransientAttachment    = 1 << 6,
        InputAttachment        = 1 << 7
    };
};

struct AccessMask {
    enum Flag
    {
        IndirectCommandRead         = 1 << 0,
        IndexRead                   = 1 << 1,
        VertexAttributeRead         = 1 << 2,
        UniformRead                 = 1 << 3,
        InputAttachmentRead         = 1 << 4,
        ShaderRead                  = 1 << 5,
        ShaderWrite                 = 1 << 6,
        ColorAttachmentRead         = 1 << 7,
        ColorAttachmentWrite        = 1 << 8,
        DepthStencilAttachmentRead  = 1 << 9,
        DepthStencilAttachmentWrite = 1 << 10,
        TransferRead                = 1 << 11,
        TransferWrite               = 1 << 12,
        HostRead                    = 1 << 13,
        HostWrite                   = 1 << 14,
        MemoryRead                  = 1 << 15,
        MemoryWrite                 = 1 << 16,
    };
};

} // namespace gfx
} // namespace clay