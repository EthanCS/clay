#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

#include <clay_core/file.h>
#include <clay_core/clay_core.h>
#include <clay_app/window.h>

#ifdef CLAY_GFX_ENABLE
    #include <clay_gfx/das.h>
REGISTER_MODULE(Module_clay_gfx);
#endif

using namespace clay;
using namespace das;

const int   MAX_FRAMES_IN_FLIGHT = 2;
const u32   WIDTH                = 1280;
const u32   HEIGHT               = 720;
const char* TITLE                = "Hello Clay!";

class Application
{
private:
    TextPrinter     das_logs;
    das::ProgramPtr das_program = nullptr;
    das::Context*   das_context = nullptr;

    das::SimFunction* das_on_init    = nullptr;
    das::SimFunction* das_on_update  = nullptr;
    das::SimFunction* das_on_destroy = nullptr;

public:
    bool prepare(const char* script_path)
    {
        das::CodeOfPolicies policies;    // default policies
        policies.persistent_heap = true; // enable persistent heap for GC

        // read script
        auto das_script = core::read_file(script_path);
        auto fileInfo   = make_unique<das::TextFileInfo>(das_script.data(), (u32)das_script.size(), false);
        auto fAccess    = make_smart<FsFileAccess>();
        fAccess->setFileInfo("dummy.das", das::move(fileInfo));

        // compile script
        ModuleGroup dummyLibGroup;
        das_program = compileDaScript("dummy.das", fAccess, das_logs, dummyLibGroup, policies);

        if (das_program->failed())
        {
            das_logs << "failed to compile\n";
            for (auto& err : das_program->errors)
            {
                das_logs << reportError(err.at, err.what, err.extra, err.fixme, err.cerr);
            }
            return false;
        }

        das_context = new das::Context(das_program->getContextStackSize());
        if (!das_program->simulate(*das_context, das_logs))
        {
            // if interpretation failed, report errors
            das_logs << "failed to simulate\n";
            for (auto& err : das_program->errors)
            {
                das_logs << reportError(err.at, err.what, err.extra, err.fixme, err.cerr);
            }
            return false;
        }

        das_on_init    = das_context->findFunction("on_init");
        das_on_update  = das_context->findFunction("on_update");
        das_on_destroy = das_context->findFunction("on_destroy");

        return true;
    }

    void run()
    {
        init();
        main_loop();
        shutdown();
    }

    void destroy()
    {
        if (das_context != nullptr)
        {
            delete das_context;
        }
    }

private:
    app::Window window;

    gfx::Handle<gfx::Shader> hello_vs;
    gfx::Handle<gfx::Shader> hello_fs;

    void init()
    {
        window.init({ .title = TITLE, .width = WIDTH, .height = HEIGHT });

        bool bInit = gfx::init({ .type     = gfx::BackendType::Vulkan,
                                 .window   = window.platform_handle,
                                 .app_name = TITLE,
                                 .debug    = true });
        if (!bInit) { throw std::runtime_error("failed to initialize clay gfx!"); }

        // Shader
        auto vert_shader_code = core::read_file("../../../../assets/shader/vert.spv");
        auto frag_shader_code = core::read_file("../../../../assets/shader/frag.spv");
        hello_vs              = gfx::create_shader({ .code = vert_shader_code.data(), .code_size = (u32)vert_shader_code.size() });
        hello_fs              = gfx::create_shader({ .code = frag_shader_code.data(), .code_size = (u32)frag_shader_code.size() });

        auto idx_hello_vs = das_context->findVariable("hello_vs");
        memcpy(das_context->getVariable(idx_hello_vs), &hello_vs, sizeof(gfx::Handle<gfx::Shader>));

        auto idx_hello_fs = das_context->findVariable("hello_fs");
        memcpy(das_context->getVariable(idx_hello_fs), &hello_fs, sizeof(gfx::Handle<gfx::Shader>));

        if (das_on_init != nullptr) { das_context->eval(das_on_init, nullptr); }
    }

    void main_loop()
    {
        while (!window.requested_exit)
        {
            window.handle_events();

            if (das_on_update != nullptr)
            {
                das_context->collectHeap(nullptr, true, true);
                das_context->eval(das_on_update, nullptr);
            }
        }
    }

    void shutdown()
    {
        if (das_on_init != nullptr) { das_context->eval(das_on_destroy, nullptr); }
        window.shutdown();
    }
};

int main(int argc, char** argv)
{
    NEED_ALL_DEFAULT_MODULES;

#ifdef CLAY_GFX_ENABLE
    NEED_MODULE(Module_clay_gfx);
#endif

    das::Module::Initialize();

    Application app;

    if (app.prepare("../../../../assets/script/hello_triangle.das"))
    {
        try
        {
            app.run();
        } catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }

    app.destroy();
    das::Module::Shutdown();

    return EXIT_SUCCESS;
}