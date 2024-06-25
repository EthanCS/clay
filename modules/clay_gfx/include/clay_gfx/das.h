#pragma once

#include "daScript/ast/ast_typefactory.h"
#include "resource.h"
#include <daScript/daScript.h>
#include <clay_gfx/backend.h>

#define STRINGIFY(x) #x
#define TOKENPASTE(x, y) STRINGIFY(x##y)

#define GFX_DAS_STRUCT_COMMON                              \
    virtual bool isLocal() const override { return true; } \
    virtual bool canCopy() const override { return true; } \
    virtual bool canMove() const override { return true; }

#define HANDLE_DAS_TYPE_BINDING(DAS_NAME, HANDLE_TYPE)                                                                            \
    MAKE_TYPE_FACTORY(DAS_NAME, clay::gfx::Handle<clay::gfx::HANDLE_TYPE>);                                                       \
    struct DAS_NAME##Annotation : public das::ManagedStructureAnnotation<clay::gfx::Handle<clay::gfx::HANDLE_TYPE>, true, true> { \
        DAS_NAME##Annotation(das::ModuleLibrary& ml)                                                                              \
            : ManagedStructureAnnotation(#DAS_NAME, ml)                                                                           \
        {                                                                                                                         \
            addProperty<DAS_BIND_MANAGED_PROP(is_valid)>("is_valid");                                                             \
        }                                                                                                                         \
        GFX_DAS_STRUCT_COMMON                                                                                                     \
    };

HANDLE_DAS_TYPE_BINDING(HSwapchain, Swapchain)
HANDLE_DAS_TYPE_BINDING(HBuffer, Buffer)
HANDLE_DAS_TYPE_BINDING(HFramebuffer, Framebuffer)
HANDLE_DAS_TYPE_BINDING(HCommandBuffer, CommandBuffer)
HANDLE_DAS_TYPE_BINDING(HGraphicsPipeline, GraphicsPipeline)

DAS_BIND_ENUM_CAST(clay::gfx::BufferUsage::Flag);
DAS_BASE_BIND_ENUM(clay::gfx::BufferUsage::Flag, BufferUsage, TransferSrc, TransferDst, UniformTexelBuffer, StorageTexelBuffer, UniformBuffer, StorageBuffer, IndexBuffer, VertexBuffer, IndirectBuffer, ShaderDeviceAddress, VideoDecodeSrc, VideoDecodeDst, TransformFeedbackBuffer, TransformFeedbackCounterBuffer, ConditionalRendering, AccelerationStructureBuildInputReadOnly, AccelerationStructureStorage, ShaderBindingTable, SamplerDescriptorBuffer, ResourceDescriptorBuffer, PushDescriptorsDescriptorBuffer, MicromapBuildInputReadOnly, MicromapStorage)

DAS_BIND_ENUM_CAST(clay::gfx::RenderPassLoadOp::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::RenderPassLoadOp::Enum, RenderPassLoadOp, DontCare, Load, Clear)

DAS_BIND_ENUM_CAST(clay::gfx::ImageLayout::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::ImageLayout::Enum, ImageLayout, Undefined, General, ColorAttachmentOptimal, DepthStencilAttachmentOptimal, DepthStencilReadOnlyOptimal, ShaderReadOnlyOptimal, TransferSrcOptimal, TransferDstOptimal, Preinitialized, PresentSrc)

DAS_BIND_ENUM_CAST(clay::gfx::Format::Enum);
DAS_BASE_BIND_ENUM(clay::gfx::Format::Enum, Format, Undefined, D32_SFLOAT, D32_SFLOAT_S8_UINT, D24_UNORM_S8_UINT, B8G8R8A8_UNORM, B8G8R8A8_SRGB, R8G8B8A8_UNORM, R8G8B8A8_SRGB, B8G8R8_UNORM, B8G8R8_SRGB, R8G8B8_UNORM, R8G8B8_SRGB, R32_SFLOAT, R32G32_SFLOAT, R32G32B32_SFLOAT, R32G32B32A32_SFLOAT)

MAKE_TYPE_FACTORY(CreateBufferOptions, clay::gfx::CreateBufferOptions);
struct CreateBufferOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CreateBufferOptions, true, true> {
    CreateBufferOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CreateBufferOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(size)>("size");
        addField<DAS_BIND_MANAGED_FIELD(usage)>("usage");
        addField<DAS_BIND_MANAGED_FIELD(exclusive)>("exclusive");
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

#define DAS_BIND_FUNC(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, TOKENPASTE(gfx_, FUNC_NAME), das::SideEffects::modifyExternal, #FUNC_NAME);
#define DAS_BIND_FUNC_NO_RET(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME)>(*this, lib, TOKENPASTE(gfx_, FUNC_NAME), das::SideEffects::modifyExternal, #FUNC_NAME);

class Module_clay_gfx : public das::Module
{
public:
    Module_clay_gfx()
        : das::Module("clay_gfx")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        // bind basic types
        addAnnotation(das::make_smart<ClearValueAnnotation>(lib));

        // bind enums
        addEnumeration(das::make_smart<EnumerationRenderPassLoadOp>());
        addEnumeration(das::make_smart<EnumerationImageLayout>());
        addEnumeration(das::make_smart<EnumerationFormat>());
        addEnumeration(das::make_smart<EnumerationBufferUsage>());

        // bind handle types
        addAnnotation(das::make_smart<HBufferAnnotation>(lib));
        addAnnotation(das::make_smart<HSwapchainAnnotation>(lib));
        addAnnotation(das::make_smart<HFramebufferAnnotation>(lib));
        addAnnotation(das::make_smart<HCommandBufferAnnotation>(lib));
        addAnnotation(das::make_smart<HGraphicsPipelineAnnotation>(lib));

        // bind resource types
        addAnnotation(das::make_smart<ColorAttachmentDescAnnotation>(lib));
        addAnnotation(das::make_smart<DepthStencilAttachmentDescAnnotation>(lib));
        addAnnotation(das::make_smart<RenderPassLayoutAnnotation>(lib));

        // bind normal types
        addAnnotation(das::make_smart<CreateBufferOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdDrawOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdSetScissorOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdSetViewportOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdBeginRenderPassOptionsAnnotation>(lib));

        // bind functions
        DAS_BIND_FUNC(create_buffer)
        DAS_BIND_FUNC_NO_RET(destroy_buffer)

        DAS_BIND_FUNC_NO_RET(cmd_begin)
        DAS_BIND_FUNC_NO_RET(cmd_end)
        DAS_BIND_FUNC_NO_RET(cmd_begin_render_pass)
        DAS_BIND_FUNC_NO_RET(cmd_end_render_pass)
        DAS_BIND_FUNC_NO_RET(cmd_bind_graphics_pipeline)
        DAS_BIND_FUNC_NO_RET(cmd_set_viewport)
        DAS_BIND_FUNC_NO_RET(cmd_set_scissor)
        DAS_BIND_FUNC_NO_RET(cmd_draw)
    }
};