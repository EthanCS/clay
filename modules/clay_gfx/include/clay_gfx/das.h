#pragma once

#include "daScript/ast/ast_typefactory.h"
#include <daScript/daScript.h>
#include <clay_gfx/backend.h>

#define STRINGIFY(x) #x
#define TOKENPASTE(x, y) STRINGIFY(x##y)

#define HANDLE_DAS_TYPE_BINDING(DAS_NAME, HANDLE_TYPE)                                                                            \
    MAKE_TYPE_FACTORY(DAS_NAME, clay::gfx::Handle<clay::gfx::HANDLE_TYPE>);                                                       \
    struct DAS_NAME##Annotation : public das::ManagedStructureAnnotation<clay::gfx::Handle<clay::gfx::HANDLE_TYPE>, true, true> { \
        DAS_NAME##Annotation(das::ModuleLibrary& ml)                                                                              \
            : ManagedStructureAnnotation(#DAS_NAME, ml)                                                                           \
        {                                                                                                                         \
        }                                                                                                                         \
        virtual bool isLocal() const override { return true; }                                                                    \
        virtual bool canCopy() const override { return true; }                                                                    \
        virtual bool canMove() const override { return true; }                                                                    \
    };

HANDLE_DAS_TYPE_BINDING(HSwapchain, Swapchain)
HANDLE_DAS_TYPE_BINDING(HCommandBuffer, CommandBuffer)
HANDLE_DAS_TYPE_BINDING(HGraphicsPipeline, GraphicsPipeline)

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
    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
};

MAKE_TYPE_FACTORY(CmdSetScissorOptions, clay::gfx::CmdSetScissorOptions);
struct CmdSetScissorOptionsAnnotation : public das::ManagedStructureAnnotation<clay::gfx::CmdSetScissorOptions, true, true> {
    CmdSetScissorOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CmdSetScissorOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
        addField<DAS_BIND_MANAGED_FIELD(extent)>("extent");
    }
    // virtual bool isLocal() const override { return true; }
    // virtual bool canCopy() const override { return true; }
    // virtual bool canMove() const override { return true; }
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
    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
};

#define DAS_BIND_CMD_FUNC(FUNC_NAME) addExtern<DAS_BIND_FUN(clay::gfx::FUNC_NAME)>(*this, lib, TOKENPASTE(gfx_, FUNC_NAME), das::SideEffects::modifyExternal, #FUNC_NAME);

class Module_clay_gfx : public das::Module
{
public:
    Module_clay_gfx()
        : das::Module("clay_gfx")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        // bind handle types
        addAnnotation(das::make_smart<HSwapchainAnnotation>(lib));
        addAnnotation(das::make_smart<HCommandBufferAnnotation>(lib));
        addAnnotation(das::make_smart<HGraphicsPipelineAnnotation>(lib));

        // bind normal types
        addAnnotation(das::make_smart<CmdDrawOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdSetScissorOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CmdSetViewportOptionsAnnotation>(lib));

        // bind functions
        DAS_BIND_CMD_FUNC(cmd_begin)
        DAS_BIND_CMD_FUNC(cmd_end)
        DAS_BIND_CMD_FUNC(cmd_bind_graphics_pipeline)
        DAS_BIND_CMD_FUNC(cmd_end_render_pass)
        DAS_BIND_CMD_FUNC(cmd_set_viewport)
        DAS_BIND_CMD_FUNC(cmd_set_scissor)
        DAS_BIND_CMD_FUNC(cmd_draw)
    }
};