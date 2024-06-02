#include "clay_gfx/resource.h"
#include <fstream>
#include <vector>
#include <string>

#include <clay_gfx/backend.h>
#include <clay_core/clay_core.h>
#include <clay_app/window.h>

static std::vector<char> read_file(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file!");
    }

    size_t            fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();

    return buffer;
}

int main(int argc, char** argv)
{
    using namespace clay;

    auto vert_shader_code = read_file("assets/shader/vert.spv");
    auto frag_shader_code = read_file("assets/shader/frag.spv");

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

    gfx::RenderBackend* rb = gfx::backend();

    gfx::Handle<gfx::Shader> hello_vs = rb->create_shader({ .code = vert_shader_code.data(), .code_size = (u32)vert_shader_code.size() });
    gfx::Handle<gfx::Shader> hello_fs = rb->create_shader({ .code = frag_shader_code.data(), .code_size = (u32)frag_shader_code.size() });

    while (!window.requested_exit)
    {

        gfx::Handle<gfx::Fence> fence = rb->create_fence(true);
        rb->destroy_fence(fence);

        gfx::Handle<gfx::Semaphore> semaphore = rb->create_semaphore();
        rb->destroy_semaphore(semaphore);

        window.handle_events();
    }

    gfx::shutdown();
    window.shutdown();

    return 0;
}