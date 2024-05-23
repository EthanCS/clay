#include <clay_core/clay_core.h>
#include <clay_gfx/backend.h>
#include <clay_app/window.h>

int main(int argc, char** argv)
{
    using namespace clay;

    app::Window window;
    window.init(app::WindowConfig{ .title = "Clay", .width = 1280, .height = 720 });

    bool bInit = gfx::init({ .type = gfx::RenderBackendType::Vulkan, .window = window.platform_handle, .app_name = "Clay Test", .debug = true });

    while (!window.requested_exit)
    {
        window.handle_events();
    }

    gfx::shutdown();
    window.shutdown();

    return 0;
}