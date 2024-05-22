#include <clay_core/clay_core.h>
#include <clay_gfx/clay_gfx.h>
#include <clay_app/window.h>

int main(int argc, char** argv)
{
    using namespace clay;

    bool bInit = gfx::init({ .type = gfx::RenderBackendType::Vulkan, .debug = true });
    gfx::shutdown();

    app::Window window;
    window.init(app::WindowConfig{ .title = "Clay", .width = 1280, .height = 720 });
    while (!window.requested_exit)
    {
        window.handle_events();
    }
    window.shutdown();

    return 0;
}