#include <clay_gfx/resource.h>
#include <clay_core/clay_core.h>
#include <clay_gfx/backend.h>
#include <clay_app/window.h>

int main(int argc, char** argv)
{
    using namespace clay;

    app::Window window;
    window.init(app::WindowConfig{ .title = "Clay", .width = 1280, .height = 720 });

    bool bInit = gfx::init({ .type     = gfx::BackendType::Vulkan,
                             .window   = window.platform_handle,
                             .width    = 1280,
                             .height   = 720,
                             .vsync    = true,
                             .format   = gfx::Format::B8G8R8A8_UNORM,
                             .app_name = "Clay Test",
                             .debug    = true });

    while (!window.requested_exit)
    {
        gfx::RenderBackend* rb = gfx::get_backend();

        gfx::FenceHandle fence = rb->create_fence(true);
        rb->destroy_fence(fence);

        gfx::SemaphoreHandle semaphore = rb->create_semaphore();
        rb->destroy_semaphore(semaphore);

        window.handle_events();
    }

    gfx::shutdown();
    window.shutdown();

    return 0;
}