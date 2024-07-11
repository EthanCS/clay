#pragma once

#include <daScript/daScript.h>
#include <ShaderConductor-clay/ShaderConductor.hpp>

DAS_BIND_ENUM_CAST(ShaderConductor::ShaderStage);
DAS_BASE_BIND_ENUM(ShaderConductor::ShaderStage, ShaderStage, VertexShader, PixelShader, GeometryShader, HullShader, DomainShader, ComputeShader)

DAS_BIND_ENUM_CAST(ShaderConductor::ShadingLanguage);
DAS_BASE_BIND_ENUM(ShaderConductor::ShadingLanguage, ShadingLanguage, Dxil, SpirV, Hlsl, Glsl, Essl, Msl_macOS, Msl_iOS)

DAS_BIND_ENUM_CAST(ShaderConductor::ShaderResourceType);
DAS_BASE_BIND_ENUM(ShaderConductor::ShaderResourceType, ShaderResourceType, ConstantBuffer, Parameter, Texture, Sampler, ShaderResourceView, UnorderedAccessView)

MAKE_TYPE_FACTORY(MacroDefine, ShaderConductor::MacroDefine);
struct MacroDefineAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::MacroDefine, true, true> {
    MacroDefineAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("MacroDefine", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(name)>("name");
        addField<DAS_BIND_MANAGED_FIELD(value)>("value");
    }
    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
    virtual bool canBePlacedInContainer() const override { return true; }
};

class Module_ShaderConductor : public das::Module
{
public:
    Module_ShaderConductor()
        : das::Module("ShaderConductor")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        addEnumeration(das::make_smart<EnumerationShaderStage>());
        addEnumeration(das::make_smart<EnumerationShadingLanguage>());
        addEnumeration(das::make_smart<EnumerationShaderResourceType>());

        addAnnotation(das::make_smart<MacroDefineAnnotation>(lib));

        addExtern<DAS_BIND_FUN(ShaderConductor::Compiler::LinkSupport)>(*this, lib, "LinkSupport", das::SideEffects::modifyExternal, "ShaderConductor::Compiler::LinkSupport");
    }
};