#pragma once

#include <daScript/daScript.h>
#include <clay_app/window.h>

MAKE_TYPE_FACTORY(WindowConfig, clay::app::WindowConfig);
struct WindowConfigAnnotation : public das::ManagedStructureAnnotation<clay::app::WindowConfig, true, true> {
    WindowConfigAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("WindowConfig", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(title)>("title");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
    }

    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
    virtual bool canBePlacedInContainer() const override { return true; }
};

MAKE_TYPE_FACTORY(Window, clay::app::Window);
struct WindowAnnotation : public das::ManagedStructureAnnotation<clay::app::Window, true, true> {
    WindowAnnotation(das::ModuleLibrary& ml)
        : ManagedStructureAnnotation("Window", ml)
    {
        addField<DAS_BIND_MANAGED_FIELD(platform_handle)>("platform_handle");
        addField<DAS_BIND_MANAGED_FIELD(requested_exit)>("requested_exit");
        addField<DAS_BIND_MANAGED_FIELD(resized)>("resized");
        addField<DAS_BIND_MANAGED_FIELD(minimized)>("minimized");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height");
    }

    virtual bool isLocal() const override { return true; }
    virtual bool canCopy() const override { return true; }
    virtual bool canMove() const override { return true; }
    virtual bool canBePlacedInContainer() const override { return true; }
};

class Module_clay_app : public das::Module
{
public:
    Module_clay_app()
        : das::Module("clay_app")
    {
        das::ModuleLibrary lib(this);
        lib.addBuiltInModule();

        addAnnotation(das::make_smart<WindowConfigAnnotation>(lib));
        addAnnotation(das::make_smart<WindowAnnotation>(lib));

        using method_window_init = DAS_CALL_MEMBER(clay::app::Window::init);
        addExtern<DAS_CALL_METHOD(method_window_init)>(*this, lib, "init", das::SideEffects::modifyArgument, DAS_CALL_MEMBER_CPP(clay::app::Window::init));

        using method_window_handle_events = DAS_CALL_MEMBER(clay::app::Window::handle_events);
        addExtern<DAS_CALL_METHOD(method_window_handle_events)>(*this, lib, "handle_events", das::SideEffects::modifyArgument, DAS_CALL_MEMBER_CPP(clay::app::Window::handle_events));

        using method_window_shutdown = DAS_CALL_MEMBER(clay::app::Window::shutdown);
        addExtern<DAS_CALL_METHOD(method_window_shutdown)>(*this, lib, "shutdown", das::SideEffects::modifyArgument, DAS_CALL_MEMBER_CPP(clay::app::Window::shutdown));
    }
};