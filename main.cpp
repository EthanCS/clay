#include "clay_core/macro.h"
#include "clay_gfx/define.h"
#include "clay_gfx/handle.h"
#include "clay_gfx/resource.h"
#include "modules/clay_gfx/include/clay_gfx/define.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>

#include <clay_gfx/backend.h>
#include <clay_core/clay_core.h>
#include <clay_app/window.h>

std::vector<char> read_file(const std::string& filename);

using namespace clay;

const int   MAX_FRAMES_IN_FLIGHT = 2;
const u32   WIDTH                = 1280;
const u32   HEIGHT               = 720;
const char* TITLE                = "Hello Clay!";

class HelloTriangleApplication
{
public:
    void run()
    {
        init();
        main_loop();
        shutdown();
    }

private:
    app::Window window;

    u32                                        current_frame = 0;
    gfx::Handle<gfx::Swapchain>                swapchain;
    std::vector<gfx::Handle<gfx::Framebuffer>> swapchain_framebuffers;
    std::vector<gfx::Handle<gfx::Fence>>       in_flight_fences;
    std::vector<gfx::Handle<gfx::Semaphore>>   image_available_semaphores;
    std::vector<gfx::Handle<gfx::Semaphore>>   render_finished_semaphores;

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

        auto vert_shader_code = read_file("assets/shader/vert.spv");
        auto frag_shader_code = read_file("assets/shader/frag.spv");

        hello_vs = gfx::create_shader({ .code = vert_shader_code.data(), .code_size = (u32)vert_shader_code.size() });
        hello_fs = gfx::create_shader({ .code = frag_shader_code.data(), .code_size = (u32)frag_shader_code.size() });

        in_flight_fences.resize(MAX_FRAMES_IN_FLIGHT);
        image_available_semaphores.resize(MAX_FRAMES_IN_FLIGHT);
        render_finished_semaphores.resize(MAX_FRAMES_IN_FLIGHT);
        for (usize i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
        {
            in_flight_fences[i]           = gfx::create_fence(true);
            image_available_semaphores[i] = gfx::create_semaphore();
            render_finished_semaphores[i] = gfx::create_semaphore();
        }

        create_swapchain(window.width, window.height);
    }

    void main_loop()
    {
        while (!window.requested_exit)
        {
            window.handle_events();
            // draw_frame();
        }
        gfx::device_wait_idle();
    }

    void draw_frame()
    {
        gfx::wait_for_fence(in_flight_fences[current_frame], true, u64_MAX);
        gfx::SwapchainAcquireResult acquire_swapchain = gfx::acquire_next_image({ .semaphore = image_available_semaphores[current_frame] });

        if (acquire_swapchain.status == gfx::SwapchainStatus::OutOfDate)
        {
            recreate_swapchain();
            return;
        }
    }

    void recreate_swapchain()
    {
        gfx::device_wait_idle();

        for (const auto& framebuffer : swapchain_framebuffers)
        {
            gfx::destroy_framebuffer(framebuffer);
        }
        gfx::destroy_swapchain(swapchain);

        create_swapchain(window.width, window.height);
    }

    void create_swapchain(u32 width, u32 height)
    {
        swapchain      = gfx::create_swapchain({ .width = width, .height = height, .vsync = true, .format = gfx::Format::B8G8R8A8_UNORM });
        u32 num_images = gfx::get_swapchain_image_count(swapchain);
        swapchain_framebuffers.resize(num_images);
        for (u32 i = 0; i < num_images; i++)
        {
            swapchain_framebuffers[i] = gfx::create_framebuffer(
            { .width              = WIDTH,
              .height             = HEIGHT,
              .color_attachments  = { { .texture = gfx::get_swapchain_back_buffer(swapchain, i), .view_type = gfx::TextureViewType::Texture2D, .format = gfx::Format::B8G8R8A8_UNORM } },
              .render_pass_layout = { .colors = { { .format = gfx::Format::B8G8R8A8_UNORM, .layout = gfx::ImageLayout::PresentSrc, .load_op = gfx::RenderPassLoadOp::Clear } } } });
        }
    }

    void shutdown()
    {
        gfx::shutdown();
        window.shutdown();
    }
};

int main(int argc, char** argv)
{
    HelloTriangleApplication app;
    try
    {
        app.run();
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

std::vector<char> read_file(const std::string& filename)
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