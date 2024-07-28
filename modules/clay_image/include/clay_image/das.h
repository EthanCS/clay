#pragma once

#include <daScript/daScript.h>
#include <clay_image/image.h>

DAS_BIND_ENUM_CAST(clay::image::ImageChannel::Enum);
DAS_BASE_BIND_ENUM(clay::image::ImageChannel::Enum, ImageChannel, Grey, GreyAlpha, RGB, RGBAlpha);

MAKE_TYPE_FACTORY(ImagePtr, std::shared_ptr<clay::image::IImage>);
struct ImagePtrAnnotation : public das::ManagedStructureAnnotation<std::shared_ptr<clay::image::IImage>, true, true> {
    ImagePtrAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("ImagePtr", ml)
    {
    }
    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
    virtual bool canBePlacedInContainer() const override { return true; }
};

class Module_clay_image : public das::Module
{
public:
    Module_clay_image()
        : das::Module("clay_image")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        addEnumeration(das::make_smart<EnumerationImageChannel>());
        addAnnotation(das::make_smart<ImagePtrAnnotation>(lib));
        
        addExtern<DAS_BIND_FUN(clay::image::load_image), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "load_image", das::SideEffects::modifyExternal, "clay::image::load_image");
    }
};