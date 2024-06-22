#pragma once

#include <daScript/daScript.h>
#include <clay_gfx/backend.h>

MAKE_TYPE_FACTORY(HCommandBuffer, clay::gfx::Handle<clay::gfx::CommandBuffer>);
struct HCommandBufferAnnotation : public das::ManagedStructureAnnotation<clay::gfx::Handle<clay::gfx::CommandBuffer>, true, true> {
    HCommandBufferAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("HCommandBuffer", ml)
    {
    }
    virtual bool isLocal() const override { return true; } // this ref-value can appear as local variable in das
    virtual bool canCopy() const override { return true; } // this ref-value can be copied
    virtual bool canMove() const override { return true; } // this ref-value can be moved
};

class Module_clay_gfx : public das::Module
{
public:
    Module_clay_gfx()
        : das::Module("clay_gfx")
    { // module name, when used from das file
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();
        // register custom type annotation
        addAnnotation(das::make_smart<HCommandBufferAnnotation>(lib));
        // note SimNode_ExtFuncCallAndCopyOrMove - this means function returns ref type value,
        //  which needs to be copied or moved
        addExtern<DAS_BIND_FUN(clay::gfx::cmd_begin)>(*this, lib, "cmd_begin", das::SideEffects::modifyExternal, "clay::gfx::cmd_begin");
    }
};