#pragma once

#include <daScript/daScript.h>
#include <clay_gfx/backend.h>

#define GFX_DAS_STRUCT_COMMON                              \
    virtual bool isLocal() const override { return true; } \
    virtual bool canCopy() const override { return true; } \
    virtual bool canMove() const override { return true; } \
    virtual bool canBePlacedInContainer() const override { return true; }

#define HANDLE_DAS_TYPE_BINDING(DAS_NAME, HANDLE_TYPE)                                                                            \
    MAKE_TYPE_FACTORY(DAS_NAME, clay::gfx::Handle<clay::gfx::HANDLE_TYPE>);                                                       \
    struct DAS_NAME##Annotation : public das::ManagedStructureAnnotation<clay::gfx::Handle<clay::gfx::HANDLE_TYPE>, true, true> { \
        DAS_NAME##Annotation(das::ModuleLibrary& ml)                                                                              \
            : ManagedStructureAnnotation(#DAS_NAME, ml)                                                                           \
        {                                                                                                                         \
            addProperty<DAS_BIND_MANAGED_PROP(is_valid)>("is_valid");                                                             \
            addProperty<DAS_BIND_MANAGED_PROP(get_index)>("get_index");                                                           \
            addProperty<DAS_BIND_MANAGED_PROP(hash)>("hash");                                                                     \
        }                                                                                                                         \
        GFX_DAS_STRUCT_COMMON                                                                                                     \
    };

#define GFX_OPTIONS_STRUCT(TYPE)                                                                    \
    MAKE_TYPE_FACTORY(TYPE, clay::gfx::TYPE);                                                       \
    struct TYPE##Annotation : public das::ManagedStructureAnnotation<clay::gfx::TYPE, true, true> { \
        TYPE##Annotation(das::ModuleLibrary& ml)                                                    \
            : ManagedStructureAnnotation(#TYPE, ml)                                                 \
        {                                                                                           \
        }                                                                                           \
        GFX_DAS_STRUCT_COMMON                                                                       \
    };

#define ADD_ENUM_ANNOTATION(S) addEnumeration(das::make_smart<Enumeration##S>());
#define ADD_STRUCT_ANNOTATION(S) addAnnotation(das::make_smart<S##Annotation>(lib));

#define ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME)>(*this, lib, #FUNC_NAME, das::SideEffects::modifyExternal, #FUNC_NAME);
#define ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME)>(*this, lib, #FUNC_NAME, das::SideEffects::accessExternal, #FUNC_NAME);

#define ADD_FUNC_RET_REF_MODIFY_EXTERNAL(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, #FUNC_NAME, das::SideEffects::modifyExternal, #FUNC_NAME);
#define ADD_FUNC_RET_REF_ACCESS_EXTERNAL(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, #FUNC_NAME, das::SideEffects::accessExternal, #FUNC_NAME);

#define ADD_MEMBER_FUNCTION(STRUCT_NAME, FUNC_NAME)                                                                                                                       \
    {                                                                                                                                                                     \
        using method_##FUNC_NAME = DAS_CALL_MEMBER(clay::gfx::STRUCT_NAME::FUNC_NAME);                                                                                    \
        addExtern<DAS_CALL_METHOD(method_##FUNC_NAME)>(*this, lib, #FUNC_NAME, das::SideEffects::modifyArgument, DAS_CALL_MEMBER_CPP(clay::gfx::STRUCT_NAME::FUNC_NAME)); \
    }

//////////////////////////////////////////////////////////////////////////
//////// define.h

MAKE_TYPE_FACTORY(ClearValue, clay::gfx::ClearValue);
struct ClearValueAnnotation : public das::ManagedStructureAnnotation<clay::gfx::ClearValue, true, true> {
    ClearValueAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("ClearValue", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(color)>("color");
        addField<DAS_BIND_MANAGED_FIELD(depth)>("depth");
        addField<DAS_BIND_MANAGED_FIELD(stencil)>("stencil");
    }
    GFX_DAS_STRUCT_COMMON
};

DAS_BIND_ENUM_CAST(clay::gfx::BackendType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::BackendType::Enum, BackendType, Vulkan, DirectX12, Metal)

DAS_BIND_ENUM_CAST(clay::gfx::QueueType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::QueueType::Enum, QueueType, Graphics, Present, Compute, Transfer)

DAS_BIND_ENUM_CAST(clay::gfx::Format::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::Format::Enum, Format, Undefined, D32_SFLOAT, D32_SFLOAT_S8_UINT, D24_UNORM_S8_UINT, B8G8R8A8_UNORM, B8G8R8A8_SRGB, R8G8B8A8_UNORM, R8G8B8A8_SRGB, B8G8R8_UNORM, B8G8R8_SRGB, R8G8B8_UNORM, R8G8B8_SRGB, R32_SFLOAT, R32G32_SFLOAT, R32G32B32_SFLOAT, R32G32B32A32_SFLOAT)

DAS_BIND_ENUM_CAST(clay::gfx::ImageLayout::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::ImageLayout::Enum, ImageLayout, Undefined, General, ColorAttachmentOptimal, DepthStencilAttachmentOptimal, DepthStencilReadOnlyOptimal, ShaderReadOnlyOptimal, TransferSrcOptimal, TransferDstOptimal, Preinitialized, PresentSrc)

DAS_BIND_ENUM_CAST(clay::gfx::RenderPassLoadOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::RenderPassLoadOp::Enum, RenderPassLoadOp, DontCare, Load, Clear)

DAS_BIND_ENUM_CAST(clay::gfx::RenderPassStoreOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::RenderPassStoreOp::Enum, RenderPassStoreOp, DontCare, Store)

DAS_BIND_ENUM_CAST(clay::gfx::TextureComponentSwizzle::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::TextureComponentSwizzle::Enum, TextureComponentSwizzle, Identity, Zero, One, R, G, B, A)

DAS_BIND_ENUM_CAST(clay::gfx::TextureType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::TextureType::Enum, TextureType, Texture1D, Texture2D, Texture3D)

DAS_BIND_ENUM_CAST(clay::gfx::TextureViewType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::TextureViewType::Enum, TextureViewType, Texture1D, Texture2D, Texture3D, TextureCube, Texture1DArray, Texture2DArray, TextureCubeArray)

DAS_BIND_ENUM_CAST(clay::gfx::FillMode::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::FillMode::Enum, FillMode, Wireframe, Solid, Point)

DAS_BIND_ENUM_CAST(clay::gfx::FrontFace::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::FrontFace::Enum, FrontFace, Clockwise, CounterClockwise)

DAS_BIND_ENUM_CAST(clay::gfx::CullMode::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::CullMode::Enum, CullMode, None, Front, Back, FrontAndBack)

DAS_BIND_ENUM_CAST(clay::gfx::BlendFactor::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::BlendFactor::Enum, BlendFactor, Zero, One, SrcColor, OneMinusSrcColor, DstColor, OneMinusDstColor, SrcAlpha, OneMinusSrcAlpha, DstAlpha, OneMinusDstAlpha, ConstantColor, OneMinusConstantColor, ConstantAlpha, OneMinusConstantAlpha, SrcAlphaSaturate, Src1Color, OneMinusSrc1Color, Src1Alpha, OneMinusSrc1Alpha)

DAS_BIND_ENUM_CAST(clay::gfx::BlendOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::BlendOp::Enum, BlendOp, Add, Subtract, ReverseSubtract, Min, Max)

DAS_BIND_ENUM_CAST(clay::gfx::CompareOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::CompareOp::Enum, CompareOp, Never, Less, Equal, LessOrEqual, Greater, NotEqual, GreaterOrEqual, Always)

DAS_BIND_ENUM_CAST(clay::gfx::StencilOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::StencilOp::Enum, StencilOp, Keep, Zero, Replace, IncrementAndClamp, DecrementAndClamp, Invert, IncrementAndWrap, DecrementAndWrap)

DAS_BIND_ENUM_CAST(clay::gfx::PrimitiveTopology::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::PrimitiveTopology::Enum, PrimitiveTopology, PointList, LineList, LineStrip, TriangleList, TriangleStrip, TriangleFan)

DAS_BIND_ENUM_CAST(clay::gfx::SwapchainStatus::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::SwapchainStatus::Enum, SwapchainStatus, Success, OutOfDate, Suboptimal, Error)

DAS_BIND_ENUM_CAST(clay::gfx::IndexType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::IndexType::Enum, IndexType, Uint16, Uint32)

DAS_BIND_ENUM_CAST(clay::gfx::DescriptorType::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::DescriptorType::Enum, DescriptorType, Sampler, CombinedImageSampler, SampledImage, StorageImage, UniformTexelBuffer, StorageTexelBuffer, UniformBuffer, StorageBuffer, UniformBufferDynamic, StorageBufferDynamic, InputAttachment)

DAS_BIND_ENUM_CAST(clay::gfx::PipelineBindPoint::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::PipelineBindPoint::Enum, PipelineBindPoint, Graphics, Compute)

DAS_BIND_ENUM_CAST(clay::gfx::MemoryUsage::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::MemoryUsage::Enum, MemoryUsage, GpuOnly, CpuOnly, CpuToGpu, GpuToCpu)

inline das::TypeDeclPtr makeTextureAspectFlags()
{
    auto ft      = make_smart<das::TypeDecl>(das::Type::tBitfield);
    ft->alias    = "TextureAspect";
    ft->argNames = { "Color", "Depth", "Stencil" };
    return ft;
}

inline das::TypeDeclPtr makeShaderStageFlags()
{
    auto ft      = make_smart<das::TypeDecl>(das::Type::tBitfield);
    ft->alias    = "ShaderStage";
    ft->argNames = { "Vertex", "Fragment", "Compute" };
    return ft;
}

inline das::TypeDeclPtr makeColorWriteEnabledFlags()
{
    auto ft      = make_smart<das::TypeDecl>(das::Type::tBitfield);
    ft->alias    = "ColorWriteEnabled";
    ft->argNames = { "Red", "Green", "Blue", "Alpha" };
    return ft;
}

inline das::TypeDeclPtr makePipelineStageFlags()
{
    auto ft      = make_smart<das::TypeDecl>(das::Type::tBitfield);
    ft->alias    = "PipelineStage";
    ft->argNames = { "TopOfPipe", "DrawIndirect", "VertexInput", "VertexShader", "TessellationControlShader", "TessellationEvaluationShader", "GeometryShader", "FragmentShader", "EarlyFragmentTests", "LateFragmentTests", "ColorAttachmentOutput", "ComputeShader", "Transfer", "BottomOfPipe", "Host", "AllGraphics", "AllCommands" };
    return ft;
}

inline das::TypeDeclPtr makeBufferUsageFlags()
{
    auto ft      = make_smart<das::TypeDecl>(das::Type::tBitfield);
    ft->alias    = "BufferUsage";
    ft->argNames = { "TransferSrc", "TransferDst", "UniformTexelBuffer", "StorageTexelBuffer", "UniformBuffer", "StorageBuffer", "IndexBuffer", "VertexBuffer", "IndirectBuffer", "ShaderDeviceAddress", "VideoDecodeSrc", "VideoDecodeDst", "TransformFeedbackBuffer", "TransformFeedbackCounterBuffer", "ConditionalRendering", "AccelerationStructureBuildInputReadOnly", "AccelerationStructureStorage", "ShaderBindingTable", "SamplerDescriptorBuffer", "ResourceDescriptorBuffer", "PushDescriptorsDescriptorBuffer", "MicromapBuildInputReadOnly", "MicromapStorage" };
    return ft;
}

//////////////////////////////////////////////////////////////////////////
//////// resource.h

HANDLE_DAS_TYPE_BINDING(HSwapchain, Swapchain)
HANDLE_DAS_TYPE_BINDING(HFence, Fence)
HANDLE_DAS_TYPE_BINDING(HSemaphore, Semaphore)
HANDLE_DAS_TYPE_BINDING(HBuffer, Buffer)
HANDLE_DAS_TYPE_BINDING(HTexture, Texture)
HANDLE_DAS_TYPE_BINDING(HSampler, Sampler)
HANDLE_DAS_TYPE_BINDING(HShader, Shader)
HANDLE_DAS_TYPE_BINDING(HPipelineLayout, PipelineLayout)
HANDLE_DAS_TYPE_BINDING(HGraphicsPipeline, GraphicsPipeline)
HANDLE_DAS_TYPE_BINDING(HComputePipeline, ComputePipeline)
HANDLE_DAS_TYPE_BINDING(HFramebuffer, Framebuffer)
HANDLE_DAS_TYPE_BINDING(HDescriptorSet, DescriptorSet)
HANDLE_DAS_TYPE_BINDING(HDescriptorSetLayout, DescriptorSetLayout)
HANDLE_DAS_TYPE_BINDING(HCommandPool, CommandPool)
HANDLE_DAS_TYPE_BINDING(HCommandBuffer, CommandBuffer)

MAKE_TYPE_FACTORY(SwapchainAcquireResult, clay::gfx::SwapchainAcquireResult);
struct SwapchainAcquireResultAnnotation : public das::ManagedStructureAnnotation<clay::gfx::SwapchainAcquireResult, true, true> {
    SwapchainAcquireResultAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("SwapchainAcquireResult", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(image_index)>("image_index");
        addField<DAS_BIND_MANAGED_FIELD(status)>("status");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(ColorAttachmentDesc, clay::gfx::ColorAttachmentDesc);
struct ColorAttachmentDescAnnotation : public das::ManagedStructureAnnotation<clay::gfx::ColorAttachmentDesc, true, true> {
    ColorAttachmentDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("ColorAttachmentDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout");
        addField<DAS_BIND_MANAGED_FIELD(load_op)>("load_op");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(DepthStencilAttachmentDesc, clay::gfx::DepthStencilAttachmentDesc);
struct DepthStencilAttachmentDescAnnotation : public das::ManagedStructureAnnotation<clay::gfx::DepthStencilAttachmentDesc, true, true> {
    DepthStencilAttachmentDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("DepthStencilAttachmentDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout");
        addField<DAS_BIND_MANAGED_FIELD(depth_op)>("depth_op");
        addField<DAS_BIND_MANAGED_FIELD(stencil_op)>("stencil_op");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(RenderPassLayout, clay::gfx::RenderPassLayout);
struct RenderPassLayoutAnnotation : public das::ManagedStructureAnnotation<clay::gfx::RenderPassLayout, true, true> {
    RenderPassLayoutAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("RenderPassLayout", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(colors)>("colors");
        addField<DAS_BIND_MANAGED_FIELD(depth_stencil)>("depth_stencil");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(BlendState, clay::gfx::BlendState);
struct BlendStateAnnotation : public das::ManagedStructureAnnotation<clay::gfx::BlendState, true, true> {
    BlendStateAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("BlendState", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(blend_enabled)>("blend_enabled");
        addField<DAS_BIND_MANAGED_FIELD(src_color)>("src_color");
        addField<DAS_BIND_MANAGED_FIELD(dst_color)>("dst_color");
        addField<DAS_BIND_MANAGED_FIELD(color_op)>("color_op");
        addField<DAS_BIND_MANAGED_FIELD(src_alpha)>("src_alpha");
        addField<DAS_BIND_MANAGED_FIELD(dst_alpha)>("dst_alpha");
        addField<DAS_BIND_MANAGED_FIELD(alpha_op)>("alpha_op");
        addFieldEx("color_write", "color_write", offsetof(clay::gfx::BlendState, color_write), makeColorWriteEnabledFlags());
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(StencilOperationState, clay::gfx::StencilOperationState);
struct StencilOperationStateAnnotation : public das::ManagedStructureAnnotation<clay::gfx::StencilOperationState, true, true> {
    StencilOperationStateAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("StencilOperationState", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(fail_op)>("fail_op");
        addField<DAS_BIND_MANAGED_FIELD(pass_op)>("pass_op");
        addField<DAS_BIND_MANAGED_FIELD(depth_fail_op)>("depth_fail_op");
        addField<DAS_BIND_MANAGED_FIELD(compare_op)>("compare_op");
        addField<DAS_BIND_MANAGED_FIELD(compare_mask)>("compare_mask");
        addField<DAS_BIND_MANAGED_FIELD(write_mask)>("write_mask");
        addField<DAS_BIND_MANAGED_FIELD(reference)>("reference");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(VertexAttribute, clay::gfx::VertexAttribute);
struct VertexAttributeAnnotation : public das::ManagedStructureAnnotation<clay::gfx::VertexAttribute, true, true> {
    VertexAttributeAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("VertexAttribute", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(byte_offset)>("byte_offset");
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(VertexBufferBinding, clay::gfx::VertexBufferBinding);
struct VertexBufferBindingAnnotation : public das::ManagedStructureAnnotation<clay::gfx::VertexBufferBinding, true, true> {
    VertexBufferBindingAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("VertexBufferBinding", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(byte_stride)>("byte_stride");
        addField<DAS_BIND_MANAGED_FIELD(attributes)>("attributes");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(ShaderInfo, clay::gfx::ShaderInfo);
struct ShaderInfoAnnotation : public das::ManagedStructureAnnotation<clay::gfx::ShaderInfo, true, true> {
    ShaderInfoAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("ShaderInfo", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(compiled_shader)>("compiled_shader");
        addField<DAS_BIND_MANAGED_FIELD(entry_func)>("entry_func");
        addProperty<DAS_BIND_MANAGED_PROP(is_valid)>("is_valid");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(GraphicsState, clay::gfx::GraphicsState);
struct GraphicsStateAnnotation : public das::ManagedStructureAnnotation<clay::gfx::GraphicsState, true, true> {
    GraphicsStateAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("GraphicsState", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(primitive_topology)>("primitive_topology");
        addField<DAS_BIND_MANAGED_FIELD(cull_mode)>("cull_mode");
        addField<DAS_BIND_MANAGED_FIELD(front_face)>("front_face");
        addField<DAS_BIND_MANAGED_FIELD(fill_mode)>("fill_mode");
        addField<DAS_BIND_MANAGED_FIELD(depth_compare_op)>("depth_compare_op");
        addField<DAS_BIND_MANAGED_FIELD(depth_test_enabled)>("depth_test_enabled");
        addField<DAS_BIND_MANAGED_FIELD(depth_write_enabled)>("depth_write_enabled");
        addField<DAS_BIND_MANAGED_FIELD(stencil_test_enabled)>("stencil_test_enabled");
        addField<DAS_BIND_MANAGED_FIELD(front)>("front");
        addField<DAS_BIND_MANAGED_FIELD(back)>("back");
        addField<DAS_BIND_MANAGED_FIELD(blend_states)>("blend_states");
        addField<DAS_BIND_MANAGED_FIELD(vertex_buffer_bindings)>("vertex_buffer_bindings");
        addField<DAS_BIND_MANAGED_FIELD(render_pass_layout)>("render_pass_layout");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(TextureViewDesc, clay::gfx::TextureViewDesc);
struct TextureViewDescAnnotation : public das::ManagedStructureAnnotation<clay::gfx::TextureViewDesc, true, true> {
    TextureViewDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("TextureViewDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(texture)>("texture");
        addField<DAS_BIND_MANAGED_FIELD(view_type)>("view_type");
        addFieldEx("aspect_flags", "aspect_flags", offsetof(clay::gfx::TextureViewDesc, aspect_flags), makeTextureAspectFlags());
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
        addField<DAS_BIND_MANAGED_FIELD(base_mip_level)>("base_mip_level");
        addField<DAS_BIND_MANAGED_FIELD(level_count)>("level_count");
        addField<DAS_BIND_MANAGED_FIELD(base_array_layer)>("base_array_layer");
        addField<DAS_BIND_MANAGED_FIELD(layer_count)>("layer_count");
        addField<DAS_BIND_MANAGED_FIELD(component_r)>("component_r");
        addField<DAS_BIND_MANAGED_FIELD(component_g)>("component_g");
        addField<DAS_BIND_MANAGED_FIELD(component_b)>("component_b");
        addField<DAS_BIND_MANAGED_FIELD(component_a)>("component_a");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(TextureBarrier, clay::gfx::TextureBarrier);
struct TextureBarrierAnnotation : public das::ManagedStructureAnnotation<clay::gfx::TextureBarrier, true, true> {
    TextureBarrierAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("TextureBarrier", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(texture)>("texture");
        addField<DAS_BIND_MANAGED_FIELD(old_layout)>("old_layout");
        addField<DAS_BIND_MANAGED_FIELD(new_layout)>("new_layout");
        addFieldEx("aspect_flags", "aspect_flags", offsetof(clay::gfx::TextureBarrier, aspect_flags), makeTextureAspectFlags());
        addField<DAS_BIND_MANAGED_FIELD(base_mip_level)>("base_mip_level");
        addField<DAS_BIND_MANAGED_FIELD(level_count)>("level_count");
        addField<DAS_BIND_MANAGED_FIELD(base_array_layer)>("base_array_layer");
        addField<DAS_BIND_MANAGED_FIELD(layer_count)>("layer_count");
    }
    GFX_DAS_STRUCT_COMMON
};

//////////////////////////////////////////////////////////////////////////
//////// options.h

MAKE_TYPE_FACTORY(InitBackendOptions, clay::gfx::InitBackendOptions);
struct InitBackendOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::InitBackendOptions, true, true> {
    InitBackendOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("InitBackendOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(type)>("backend_type");
        addField<DAS_BIND_MANAGED_FIELD(window)>("window");
        addField<DAS_BIND_MANAGED_FIELD(app_name)>("app_name");
        addField<DAS_BIND_MANAGED_FIELD(device_id)>("device_id");
        addField<DAS_BIND_MANAGED_FIELD(debug)>("debug");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CreateSwapchainOptions, clay::gfx::CreateSwapchainOptions);
struct CreateSwapchainOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateSwapchainOptions, true, true> {
    CreateSwapchainOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateSwapchainOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
        addField<DAS_BIND_MANAGED_FIELD(vsync)>("vsync");
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CreateShaderOptions, clay::gfx::CreateShaderOptions);
struct CreateShaderOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateShaderOptions, true, true> {
    CreateShaderOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateShaderOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(code)>("code");
        addField<DAS_BIND_MANAGED_FIELD(code_size)>("code_size");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CreateTextureOptions, clay::gfx::CreateTextureOptions);
struct CreateTextureOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateTextureOptions, true, true> {
    CreateTextureOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateTextureOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(name)>("name");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
        addField<DAS_BIND_MANAGED_FIELD(depth)>("depth");
        addField<DAS_BIND_MANAGED_FIELD(array_size)>("array_size");
        addField<DAS_BIND_MANAGED_FIELD(mip_levels)>("mip_levels");
        addField<DAS_BIND_MANAGED_FIELD(format)>("format");
        addField<DAS_BIND_MANAGED_FIELD(texture_type)>("texture_type");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CreateBufferOptions, clay::gfx::CreateBufferOptions);
struct CreateBufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateBufferOptions, true, true> {
    CreateBufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateBufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(size)>("size");
        addFieldEx("usage", "usage", offsetof(clay::gfx::CreateBufferOptions, usage), makeBufferUsageFlags());
        addField<DAS_BIND_MANAGED_FIELD(memory_usage)>("memory_usage");
        addField<DAS_BIND_MANAGED_FIELD(exclusive)>("exclusive");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(AcquireNextImageOptions, clay::gfx::AcquireNextImageOptions);
struct AcquireNextImageOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::AcquireNextImageOptions, true, true> {
    AcquireNextImageOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("AcquireNextImageOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(time_out)>("time_out");
        addField<DAS_BIND_MANAGED_FIELD(semaphore)>("semaphore");
        addField<DAS_BIND_MANAGED_FIELD(fence)>("fence");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(QueueSubmitOptions, clay::gfx::QueueSubmitOptions);
struct QueueSubmitOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::QueueSubmitOptions, true, true> {
    QueueSubmitOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("QueueSubmitOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(command_buffers)>("command_buffers");
        addField<DAS_BIND_MANAGED_FIELD(num_command_buffers)>("num_command_buffers");
        addField<DAS_BIND_MANAGED_FIELD(wait_semaphores)>("wait_semaphores");
        addField<DAS_BIND_MANAGED_FIELD(num_wait_semaphores)>("num_wait_semaphores");
        addField<DAS_BIND_MANAGED_FIELD(signal_semaphores)>("signal_semaphores");
        addField<DAS_BIND_MANAGED_FIELD(num_signal_semaphores)>("num_signal_semaphores");
        addFieldEx("wait_dst_stage", "wait_dst_stage", offsetof(clay::gfx::QueueSubmitOptions, wait_dst_stage), makePipelineStageFlags());
        addField<DAS_BIND_MANAGED_FIELD(fence)>("fence");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(QueuePresentOptions, clay::gfx::QueuePresentOptions);
struct QueuePresentOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::QueuePresentOptions, true, true> {
    QueuePresentOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("QueuePresentOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(swapchain)>("swapchain");
        addField<DAS_BIND_MANAGED_FIELD(image_index)>("image_index");
        addField<DAS_BIND_MANAGED_FIELD(wait_semaphores)>("wait_semaphores");
        addField<DAS_BIND_MANAGED_FIELD(num_wait_semaphores)>("num_wait_semaphores");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CreateFramebufferOptions, clay::gfx::CreateFramebufferOptions);
struct CreateFramebufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateFramebufferOptions, true, true> {
    CreateFramebufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateFramebufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
        addField<DAS_BIND_MANAGED_FIELD(color_attachments)>("color_attachments");
        addField<DAS_BIND_MANAGED_FIELD(depth_stencil_attachment)>("depth_stencil_attachment");
        addField<DAS_BIND_MANAGED_FIELD(render_pass_layout)>("render_pass_layout");
    }
    GFX_DAS_STRUCT_COMMON
};

GFX_OPTIONS_STRUCT(CreatePipelineLayoutOptions)

MAKE_TYPE_FACTORY(CreateGraphicsPipelineOptions, clay::gfx::CreateGraphicsPipelineOptions);
struct CreateGraphicsPipelineOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateGraphicsPipelineOptions, true, true> {
    CreateGraphicsPipelineOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateGraphicsPipelineOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(name)>("name");
        addField<DAS_BIND_MANAGED_FIELD(vertex_shader)>("vertex_shader");
        addField<DAS_BIND_MANAGED_FIELD(pixel_shader)>("pixel_shader");
        addField<DAS_BIND_MANAGED_FIELD(graphics_state)>("graphics_state");
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout");
    }
    GFX_DAS_STRUCT_COMMON
};

GFX_OPTIONS_STRUCT(CreateDescriptorSetLayoutOptions)

MAKE_TYPE_FACTORY(CreateDescriptorSetOptions, clay::gfx::CreateDescriptorSetOptions);
struct CreateDescriptorSetOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateDescriptorSetOptions, true, true> {
    CreateDescriptorSetOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateDescriptorSetOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout");
        addField<DAS_BIND_MANAGED_FIELD(set_index)>("set_index");
    }
    GFX_DAS_STRUCT_COMMON
};

GFX_OPTIONS_STRUCT(UpdateDescriptorSetOptions)

MAKE_TYPE_FACTORY(CmdBeginRenderPassOptions, clay::gfx::CmdBeginRenderPassOptions);
struct CmdBeginRenderPassOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdBeginRenderPassOptions, true, true> {
    CmdBeginRenderPassOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdBeginRenderPassOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(framebuffer)>("framebuffer");
        addField<DAS_BIND_MANAGED_FIELD(render_pass_layout)>("render_pass_layout");
        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
        addField<DAS_BIND_MANAGED_FIELD(extent)>("extent");
        addField<DAS_BIND_MANAGED_FIELD(clear)>("clear");
        addField<DAS_BIND_MANAGED_FIELD(clear_values)>("clear_values");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdSetViewportOptions, clay::gfx::CmdSetViewportOptions);
struct CmdSetViewportOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdSetViewportOptions, true, true> {
    CmdSetViewportOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdSetViewportOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(x)>("x");
        addField<DAS_BIND_MANAGED_FIELD(y)>("y");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
        addField<DAS_BIND_MANAGED_FIELD(min_depth)>("min_depth");
        addField<DAS_BIND_MANAGED_FIELD(max_depth)>("max_depth");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdSetScissorOptions, clay::gfx::CmdSetScissorOptions);
struct CmdSetScissorOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdSetScissorOptions, true, true> {
    CmdSetScissorOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdSetScissorOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
        addField<DAS_BIND_MANAGED_FIELD(extent)>("extent");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdDrawOptions, clay::gfx::CmdDrawOptions);
struct CmdDrawOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdDrawOptions, true, true> {
    CmdDrawOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdDrawOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(vertex_count)>("vertex_count");
        addField<DAS_BIND_MANAGED_FIELD(instance_count)>("instance_count");
        addField<DAS_BIND_MANAGED_FIELD(first_vertex)>("first_vertex");
        addField<DAS_BIND_MANAGED_FIELD(first_instance)>("first_instance");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdDrawIndexedOptions, clay::gfx::CmdDrawIndexedOptions);
struct CmdDrawIndexedOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdDrawIndexedOptions, true, true> {
    CmdDrawIndexedOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdDrawIndexedOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(index_count)>("index_count");
        addField<DAS_BIND_MANAGED_FIELD(instance_count)>("instance_count");
        addField<DAS_BIND_MANAGED_FIELD(first_index)>("first_index");
        addField<DAS_BIND_MANAGED_FIELD(vertex_offset)>("vertex_offset");
        addField<DAS_BIND_MANAGED_FIELD(first_instance)>("first_instance");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdBindVertexBufferOptions, clay::gfx::CmdBindVertexBufferOptions);
struct CmdBindVertexBufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdBindVertexBufferOptions, true, true> {
    CmdBindVertexBufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdBindVertexBufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(binding)>("binding");
        addField<DAS_BIND_MANAGED_FIELD(buffer)>("buffer");
        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdBindVertexBuffersOptions, clay::gfx::CmdBindVertexBuffersOptions);
struct CmdBindVertexBuffersOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdBindVertexBuffersOptions, true, true> {
    CmdBindVertexBuffersOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdBindVertexBuffersOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(first_binding)>("first_binding");
        addField<DAS_BIND_MANAGED_FIELD(binding_count)>("binding_count");
        addField<DAS_BIND_MANAGED_FIELD(buffers)>("buffers");
        addField<DAS_BIND_MANAGED_FIELD(offsets)>("offsets");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdBindIndexBufferOptions, clay::gfx::CmdBindIndexBufferOptions);
struct CmdBindIndexBufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdBindIndexBufferOptions, true, true> {
    CmdBindIndexBufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdBindIndexBufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(buffer)>("buffer");
        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
        addField<DAS_BIND_MANAGED_FIELD(index_type)>("index_type");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdBindDescriptorSetsOptions, clay::gfx::CmdBindDescriptorSetsOptions);
struct CmdBindDescriptorSetsOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdBindDescriptorSetsOptions, true, true> {
    CmdBindDescriptorSetsOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdBindDescriptorSetsOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout");
        addField<DAS_BIND_MANAGED_FIELD(bind_point)>("bind_point");
        addField<DAS_BIND_MANAGED_FIELD(first_set)>("first_set");
        addField<DAS_BIND_MANAGED_FIELD(sets)>("sets");
        addField<DAS_BIND_MANAGED_FIELD(num_sets)>("num_sets");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdCopyBufferOptions, clay::gfx::CmdCopyBufferOptions);
struct CmdCopyBufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdCopyBufferOptions, true, true> {
    CmdCopyBufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdCopyBufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(src_buffer)>("src_buffer");
        addField<DAS_BIND_MANAGED_FIELD(src_offset)>("src_offset");
        addField<DAS_BIND_MANAGED_FIELD(dst_buffer)>("dst_buffer");
        addField<DAS_BIND_MANAGED_FIELD(dst_offset)>("dst_offset");
        addField<DAS_BIND_MANAGED_FIELD(size)>("size");
    }
    GFX_DAS_STRUCT_COMMON
};

MAKE_TYPE_FACTORY(CmdCopyBufferToTextureOptions, clay::gfx::CmdCopyBufferToTextureOptions);
struct CmdCopyBufferToTextureOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdCopyBufferToTextureOptions, true, true> {
    CmdCopyBufferToTextureOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdCopyBufferToTextureOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(buffer)>("buffer");
        addField<DAS_BIND_MANAGED_FIELD(buffer_offset)>("buffer_offset");
        addField<DAS_BIND_MANAGED_FIELD(buffer_row_length)>("buffer_row_length");
        addField<DAS_BIND_MANAGED_FIELD(buffer_texture_height)>("buffer_texture_height");

        addField<DAS_BIND_MANAGED_FIELD(texture)>("texture");
        addField<DAS_BIND_MANAGED_FIELD(texture_offset)>("texture_offset");
        addField<DAS_BIND_MANAGED_FIELD(texture_extent)>("texture_extent");
        addFieldEx("aspect_flags", "aspect_flags", offsetof(clay::gfx::CmdCopyBufferToTextureOptions, aspect_flags), makeTextureAspectFlags());
        addField<DAS_BIND_MANAGED_FIELD(mip_level)>("mip_level");
        addField<DAS_BIND_MANAGED_FIELD(base_array_layer)>("base_array_layer");
        addField<DAS_BIND_MANAGED_FIELD(layer_count)>("layer_count");
        addField<DAS_BIND_MANAGED_FIELD(dst_layout)>("dst_layout");
    }
    GFX_DAS_STRUCT_COMMON
};

GFX_OPTIONS_STRUCT(CmdPipelineBarrierOptions)

class Module_clay_gfx : public das::Module
{
public:
    Module_clay_gfx()
        : das::Module("clay_gfx")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        // bind define.h
        ADD_STRUCT_ANNOTATION(ClearValue)
        ADD_ENUM_ANNOTATION(BackendType)
        ADD_ENUM_ANNOTATION(QueueType)
        ADD_ENUM_ANNOTATION(Format)
        ADD_ENUM_ANNOTATION(ImageLayout)
        ADD_ENUM_ANNOTATION(RenderPassLoadOp)
        ADD_ENUM_ANNOTATION(RenderPassStoreOp)
        ADD_ENUM_ANNOTATION(TextureComponentSwizzle)
        ADD_ENUM_ANNOTATION(TextureType)
        ADD_ENUM_ANNOTATION(TextureViewType)
        ADD_ENUM_ANNOTATION(FillMode)
        ADD_ENUM_ANNOTATION(FrontFace)
        ADD_ENUM_ANNOTATION(CullMode)
        ADD_ENUM_ANNOTATION(BlendFactor)
        ADD_ENUM_ANNOTATION(BlendOp)
        ADD_ENUM_ANNOTATION(CompareOp)
        ADD_ENUM_ANNOTATION(StencilOp)
        ADD_ENUM_ANNOTATION(PrimitiveTopology)
        ADD_ENUM_ANNOTATION(SwapchainStatus)
        ADD_ENUM_ANNOTATION(IndexType)
        ADD_ENUM_ANNOTATION(DescriptorType)
        ADD_ENUM_ANNOTATION(PipelineBindPoint)
        ADD_ENUM_ANNOTATION(MemoryUsage)
        addAlias(makeTextureAspectFlags());
        addAlias(makeShaderStageFlags());
        addAlias(makeColorWriteEnabledFlags());
        addAlias(makePipelineStageFlags());
        addAlias(makeBufferUsageFlags());

        // bind resource.h
        ADD_STRUCT_ANNOTATION(HSwapchain)
        ADD_STRUCT_ANNOTATION(HFence)
        ADD_STRUCT_ANNOTATION(HSemaphore)
        ADD_STRUCT_ANNOTATION(HBuffer)
        ADD_STRUCT_ANNOTATION(HTexture)
        ADD_STRUCT_ANNOTATION(HSampler)
        ADD_STRUCT_ANNOTATION(HShader)
        ADD_STRUCT_ANNOTATION(HPipelineLayout)
        ADD_STRUCT_ANNOTATION(HGraphicsPipeline)
        ADD_STRUCT_ANNOTATION(HComputePipeline)
        ADD_STRUCT_ANNOTATION(HFramebuffer)
        ADD_STRUCT_ANNOTATION(HDescriptorSet)
        ADD_STRUCT_ANNOTATION(HDescriptorSetLayout)
        ADD_STRUCT_ANNOTATION(HCommandPool)
        ADD_STRUCT_ANNOTATION(HCommandBuffer)
        ADD_STRUCT_ANNOTATION(SwapchainAcquireResult)
        ADD_STRUCT_ANNOTATION(ColorAttachmentDesc)
        ADD_STRUCT_ANNOTATION(DepthStencilAttachmentDesc)
        ADD_STRUCT_ANNOTATION(RenderPassLayout)
        ADD_STRUCT_ANNOTATION(BlendState)
        ADD_STRUCT_ANNOTATION(StencilOperationState)
        ADD_STRUCT_ANNOTATION(VertexAttribute)
        ADD_STRUCT_ANNOTATION(VertexBufferBinding)
        ADD_STRUCT_ANNOTATION(ShaderInfo)
        ADD_STRUCT_ANNOTATION(GraphicsState)
        ADD_MEMBER_FUNCTION(GraphicsState, reset)
        ADD_MEMBER_FUNCTION(GraphicsState, set_vertex_buffer_binding)
        ADD_MEMBER_FUNCTION(GraphicsState, set_vertex_buffer_attribute)
        ADD_STRUCT_ANNOTATION(TextureViewDesc)
        ADD_STRUCT_ANNOTATION(TextureBarrier)

        // bind options.h
        ADD_STRUCT_ANNOTATION(InitBackendOptions)
        ADD_STRUCT_ANNOTATION(CreateSwapchainOptions)
        ADD_STRUCT_ANNOTATION(CreateShaderOptions)
        ADD_STRUCT_ANNOTATION(CreateTextureOptions)
        ADD_STRUCT_ANNOTATION(CreateBufferOptions)
        ADD_STRUCT_ANNOTATION(AcquireNextImageOptions)
        ADD_STRUCT_ANNOTATION(QueueSubmitOptions)
        ADD_STRUCT_ANNOTATION(QueuePresentOptions)
        ADD_STRUCT_ANNOTATION(CreateFramebufferOptions)

        ADD_STRUCT_ANNOTATION(CreatePipelineLayoutOptions)
        ADD_MEMBER_FUNCTION(CreatePipelineLayoutOptions, reset)
        ADD_MEMBER_FUNCTION(CreatePipelineLayoutOptions, add_descriptor_set_layout)

        ADD_STRUCT_ANNOTATION(CreateGraphicsPipelineOptions)
        ADD_MEMBER_FUNCTION(CreateGraphicsPipelineOptions, set_pipeline_layout)

        ADD_STRUCT_ANNOTATION(CreateDescriptorSetLayoutOptions)
        ADD_MEMBER_FUNCTION(CreateDescriptorSetLayoutOptions, reset)
        ADD_MEMBER_FUNCTION(CreateDescriptorSetLayoutOptions, set_set_index)
        ADD_MEMBER_FUNCTION(CreateDescriptorSetLayoutOptions, set_name)
        ADD_MEMBER_FUNCTION(CreateDescriptorSetLayoutOptions, add_binding)

        ADD_STRUCT_ANNOTATION(CreateDescriptorSetOptions)

        ADD_STRUCT_ANNOTATION(UpdateDescriptorSetOptions)
        ADD_MEMBER_FUNCTION(UpdateDescriptorSetOptions, reset)
        ADD_MEMBER_FUNCTION(UpdateDescriptorSetOptions, bind_buffer)

        ADD_STRUCT_ANNOTATION(CmdBeginRenderPassOptions)
        ADD_STRUCT_ANNOTATION(CmdSetViewportOptions)
        ADD_STRUCT_ANNOTATION(CmdSetScissorOptions)
        ADD_STRUCT_ANNOTATION(CmdDrawOptions)
        ADD_STRUCT_ANNOTATION(CmdDrawIndexedOptions)
        ADD_STRUCT_ANNOTATION(CmdBindVertexBufferOptions)
        ADD_STRUCT_ANNOTATION(CmdBindVertexBuffersOptions)
        ADD_STRUCT_ANNOTATION(CmdBindIndexBufferOptions)
        ADD_STRUCT_ANNOTATION(CmdBindDescriptorSetsOptions)
        ADD_STRUCT_ANNOTATION(CmdCopyBufferOptions)
        ADD_STRUCT_ANNOTATION(CmdCopyBufferToTextureOptions)
        ADD_STRUCT_ANNOTATION(CmdPipelineBarrierOptions)
        ADD_MEMBER_FUNCTION(CmdPipelineBarrierOptions, add_texture_barrier)

        // bind backend.h
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(init)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(get_type)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(shutdown)

        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(device_wait_idle)

        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(queue_wait_idle)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(queue_submit)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(queue_present)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_swapchain)
        ADD_FUNC_RET_REF_ACCESS_EXTERNAL(acquire_next_image)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(get_swapchain_image_count)
        ADD_FUNC_RET_REF_ACCESS_EXTERNAL(get_swapchain_back_buffer)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_swapchain)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_fence)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(wait_for_fence)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(wait_for_fences)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(reset_fences)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_fence)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_semaphore)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_semaphore)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_shader)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_shader)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_pipeline_layout)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_pipeline_layout)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_graphics_pipeline)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_graphics_pipeline)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_texture)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(get_texture_width)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(get_texture_height)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(destroy_texture)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(map_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(unmap_buffer)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_buffer)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_framebuffer)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_framebuffer)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_descriptor_set_layout)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_descriptor_set_layout)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_descriptor_set)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(update_descriptor_set)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_descriptor_set)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(create_command_pool)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(destroy_command_pool)

        ADD_FUNC_RET_REF_MODIFY_EXTERNAL(allocate_command_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(reset_command_buffer)
        ADD_FUNC_RET_SIMPLE_MODIFY_EXTERNAL(free_command_buffer)

        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_begin)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_end)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_begin_render_pass)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_end_render_pass)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_bind_graphics_pipeline)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_set_viewport)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_set_scissor)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_draw)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_draw_indexed)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_bind_vertex_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_bind_vertex_buffers)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_bind_index_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_bind_descriptor_sets)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_copy_buffer)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_copy_buffer_to_texture)
        ADD_FUNC_RET_SIMPLE_ACCESS_EXTERNAL(cmd_pipeline_barrier)
    }
};