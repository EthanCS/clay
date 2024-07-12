#pragma once

#include <daScript/daScript.h>
#include <ShaderConductor-clay/ShaderConductor.hpp>

#define DAS_STRUCT_COMMON_OVERRIDE                         \
    virtual bool isLocal() const override { return true; } \
    virtual bool canCopy() const override { return true; } \
    virtual bool canMove() const override { return true; } \
    virtual bool canBePlacedInContainer() const override { return true; }

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
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(Blob, ShaderConductor::Blob);
struct BlobAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Blob, true, true> {
    BlobAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("Blob", ml)
    {
        addProperty<DAS_BIND_MANAGED_PROP(Data)>("Data");
        addProperty<DAS_BIND_MANAGED_PROP(Size)>("Size");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerShaderModel, ShaderConductor::Compiler::ShaderModel);
struct CompilerShaderModelAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::ShaderModel, true, true> {
    CompilerShaderModelAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerShaderModel", ml)
    {
        // addField<DAS_BIND_MANAGED_FIELD(major_ver)>("major_ver");
        // addField<DAS_BIND_MANAGED_FIELD(minor_ver)>("minor_ver");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerSourceDesc, ShaderConductor::Compiler::SourceDesc);
struct CompilerSourceDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::SourceDesc, true, true> {
    CompilerSourceDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerSourceDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(source)>("source");
        addField<DAS_BIND_MANAGED_FIELD(fileName)>("fileName");
        addField<DAS_BIND_MANAGED_FIELD(entryPoint)>("entryPoint");
        addField<DAS_BIND_MANAGED_FIELD(stage)>("stage");
        addField<DAS_BIND_MANAGED_FIELD(defines)>("defines");
        addField<DAS_BIND_MANAGED_FIELD(numDefines)>("numDefines");
        // addField<DAS_BIND_MANAGED_FIELD(loadIncludeCallback)>("loadIncludeCallback");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerOptions, ShaderConductor::Compiler::Options);
struct CompilerOptionsAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::Options, true, true> {
    CompilerOptionsAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerOptions", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(packMatricesInRowMajor)>("packMatricesInRowMajor");
        addField<DAS_BIND_MANAGED_FIELD(enable16bitTypes)>("enable16bitTypes");
        addField<DAS_BIND_MANAGED_FIELD(enableDebugInfo)>("enableDebugInfo");
        addField<DAS_BIND_MANAGED_FIELD(disableOptimizations)>("disableOptimizations");
        addField<DAS_BIND_MANAGED_FIELD(inheritCombinedSamplerBindings)>("inheritCombinedSamplerBindings");
        addField<DAS_BIND_MANAGED_FIELD(optimizationLevel)>("optimizationLevel");
        addField<DAS_BIND_MANAGED_FIELD(shaderModel)>("shaderModel");
        addField<DAS_BIND_MANAGED_FIELD(shiftAllTexturesBindings)>("shiftAllTexturesBindings");
        addField<DAS_BIND_MANAGED_FIELD(shiftAllSamplersBindings)>("shiftAllSamplersBindings");
        addField<DAS_BIND_MANAGED_FIELD(shiftAllCBuffersBindings)>("shiftAllCBuffersBindings");
        addField<DAS_BIND_MANAGED_FIELD(shiftAllUABuffersBindings)>("shiftAllUABuffersBindings");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerTargetDesc, ShaderConductor::Compiler::TargetDesc);
struct CompilerTargetDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::TargetDesc, true, true> {
    CompilerTargetDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerTargetDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(language)>("language");
        addField<DAS_BIND_MANAGED_FIELD(version)>("version");
        addField<DAS_BIND_MANAGED_FIELD(asModule)>("asModule");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerReflectionDesc, ShaderConductor::Compiler::ReflectionDesc);
struct CompilerReflectionDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::ReflectionDesc, true, true> {
    CompilerReflectionDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerReflectionDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(name)>("name");
        addField<DAS_BIND_MANAGED_FIELD(type)>("type");
        addField<DAS_BIND_MANAGED_FIELD(bufferBindPoint)>("bufferBindPoint");
        addField<DAS_BIND_MANAGED_FIELD(bindPoint)>("bindPoint");
        addField<DAS_BIND_MANAGED_FIELD(bindCount)>("bindCount");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerReflectionResultDesc, ShaderConductor::Compiler::ReflectionResultDesc);
struct CompilerReflectionResultDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::ReflectionResultDesc, true, true> {
    CompilerReflectionResultDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerReflectionResultDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(descs)>("descs");
        addField<DAS_BIND_MANAGED_FIELD(descCount)>("descCount");
        addField<DAS_BIND_MANAGED_FIELD(instructionCount)>("instructionCount");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerResultDesc, ShaderConductor::Compiler::ResultDesc);
struct CompilerResultDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::ResultDesc, true, true> {
    CompilerResultDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerResultDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(target)>("target");
        addField<DAS_BIND_MANAGED_FIELD(isText)>("isText");
        addField<DAS_BIND_MANAGED_FIELD(errorWarningMsg)>("errorWarningMsg");
        addField<DAS_BIND_MANAGED_FIELD(hasError)>("hasError");
        addField<DAS_BIND_MANAGED_FIELD(reflection)>("reflection");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerDisassembleDesc, ShaderConductor::Compiler::DisassembleDesc);
struct CompilerDisassembleDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::DisassembleDesc, true, true> {
    CompilerDisassembleDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerDisassembleDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(language)>("language");
        addField<DAS_BIND_MANAGED_FIELD(binary)>("binary");
        addField<DAS_BIND_MANAGED_FIELD(binarySize)>("binarySize");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerModuleDesc, ShaderConductor::Compiler::ModuleDesc);
struct CompilerModuleDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::ModuleDesc, true, true> {
    CompilerModuleDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerModuleDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(name)>("name");
        addField<DAS_BIND_MANAGED_FIELD(target)>("target");
    }
    DAS_STRUCT_COMMON_OVERRIDE
};

MAKE_TYPE_FACTORY(CompilerLinkDesc, ShaderConductor::Compiler::LinkDesc);
struct CompilerLinkDescAnnotation : public das::ManagedStructureAnnotation<ShaderConductor::Compiler::LinkDesc, true, true> {
    CompilerLinkDescAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("CompilerLinkDesc", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(entryPoint)>("entryPoint");
        addField<DAS_BIND_MANAGED_FIELD(stage)>("stage");
        addField<DAS_BIND_MANAGED_FIELD(modules)>("modules");
        addField<DAS_BIND_MANAGED_FIELD(numModules)>("numModules");
    }
    DAS_STRUCT_COMMON_OVERRIDE
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
        addAnnotation(das::make_smart<BlobAnnotation>(lib));

        addAnnotation(das::make_smart<CompilerShaderModelAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerSourceDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerOptionsAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerTargetDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerReflectionDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerReflectionResultDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerResultDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerDisassembleDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerModuleDescAnnotation>(lib));
        addAnnotation(das::make_smart<CompilerLinkDescAnnotation>(lib));

        addExtern<DAS_BIND_FUN(Module_ShaderConductor::Compile), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "Compile", das::SideEffects::modifyExternal, "ShaderConductor::Compiler::Compile");

        addExtern<DAS_BIND_FUN(ShaderConductor::Compiler::LinkSupport)>(*this, lib, "LinkSupport", das::SideEffects::modifyExternal, "ShaderConductor::Compiler::LinkSupport");
        addExtern<DAS_BIND_FUN(ShaderConductor::Compiler::Link), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "Link", das::SideEffects::modifyExternal, "ShaderConductor::Compiler::Link");
    }

    static ShaderConductor::Compiler::ResultDesc Compile(const ShaderConductor::Compiler::SourceDesc& source, const ShaderConductor::Compiler::Options& options, const ShaderConductor::Compiler::TargetDesc& target) { return ShaderConductor::Compiler::Compile(source, options, target); }
};