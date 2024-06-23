#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

#include <clay_gfx/backend.h>
#include <clay_core/file.h>
#include <clay_core/clay_core.h>
#include <clay_app/window.h>

#include <clay_gfx/das.h>
REGISTER_MODULE(Module_clay_gfx);

const char* DAS_CODE = R""""(
require clay_gfx

[export]
def record_commands(cb: HCommandBuffer)
    gfx_cmd_set_viewport(cb, [[CmdSetViewportOptions x = 0.0, y = 0.0, width = 1280.0, height = 720.0, min_depth = 0.0, max_depth = 1.0]])
    // let scissor : CmdSetScissorOptions
    // scissor.offset[0] = 0
    // scissor.offset[1] = 0
    // scissor.extent[0] = 1280
    // scissor.extent[1] = 720
    // gfx_cmd_set_scissor(cb, scissor)

[export]
def test
    print("this is nano tutorial\n")
)"""";

using namespace clay;
using namespace das;

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

    gfx::RenderPassLayout              render_pass_layout;
    gfx::Handle<gfx::GraphicsPipeline> pipeline;

    gfx::Handle<gfx::CommandPool>                command_pool;
    std::vector<gfx::Handle<gfx::CommandBuffer>> command_buffers;

    u32 swapchain_width  = 0;
    u32 swapchain_height = 0;

    das::ProgramPtr das_program;
    TextPrinter     das_logs;

    void init()
    {
        NEED_ALL_DEFAULT_MODULES;
        NEED_MODULE(Module_clay_gfx);

        das::Module::Initialize();
        {
            // make file access, introduce string as if it was a file
            auto fileInfo = make_unique<das::TextFileInfo>(DAS_CODE, uint32_t(strlen(DAS_CODE)), false);
            auto fAccess  = make_smart<FsFileAccess>();
            fAccess->setFileInfo("dummy.das", das::move(fileInfo));

            // compile script
            ModuleGroup dummyLibGroup;
            das_program = compileDaScript("dummy.das", fAccess, das_logs, dummyLibGroup);
        }

        window.init({ .title = TITLE, .width = WIDTH, .height = HEIGHT });

        bool bInit = gfx::init({ .type     = gfx::BackendType::Vulkan,
                                 .window   = window.platform_handle,
                                 .app_name = TITLE,
                                 .debug    = true });
        if (!bInit) { throw std::runtime_error("failed to initialize clay gfx!"); }

        // Render pass layout
        render_pass_layout           = {};
        render_pass_layout.colors[0] = {
            .format  = gfx::Format::B8G8R8A8_UNORM,
            .layout  = gfx::ImageLayout::PresentSrc,
            .load_op = gfx::RenderPassLoadOp::Clear
        };

        // Create pipeline
        auto vert_shader_code = core::read_file("../../../../assets/shader/vert.spv");
        auto frag_shader_code = core::read_file("../../../../assets/shader/frag.spv");
        hello_vs              = gfx::create_shader({ .code = vert_shader_code.data(), .code_size = (u32)vert_shader_code.size() });
        hello_fs              = gfx::create_shader({ .code = frag_shader_code.data(), .code_size = (u32)frag_shader_code.size() });
        pipeline              = gfx::create_graphics_pipeline(
        { .name           = "triangle",
                       .vertex_shader  = { .compiled_shader = hello_vs, .entry_func = "main" },
                       .pixel_shader   = { .compiled_shader = hello_fs, .entry_func = "main" },
                       .graphics_state = { .depth_test_enabled = false, .render_pass_layout = render_pass_layout } });

        // Command
        command_pool = gfx::create_command_pool(gfx::QueueType::Graphics);
        command_buffers.resize(MAX_FRAMES_IN_FLIGHT);
        for (usize i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
        {
            command_buffers[i] = gfx::allocate_command_buffer(command_pool);
        }

        // Sync objects
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
            draw_frame();
        }
        gfx::device_wait_idle();
    }

    void draw_frame()
    {
        gfx::wait_for_fence(in_flight_fences[current_frame], true, u64_MAX);

        gfx::SwapchainAcquireResult acquire_swapchain = gfx::acquire_next_image(swapchain, { .semaphore = image_available_semaphores[current_frame] });
        if (acquire_swapchain.status == gfx::SwapchainStatus::OutOfDate)
        {
            recreate_swapchain();
            return;
        }

        gfx::reset_fences(&in_flight_fences[current_frame], 1);

        gfx::reset_command_buffer(command_buffers[current_frame], false);
        record_commands(command_buffers[current_frame], acquire_swapchain.image_index);

        gfx::QueueSubmitOptions submit_options = {};
        submit_options.command_buffers         = &command_buffers[current_frame];
        submit_options.num_command_buffers     = 1;
        submit_options.wait_semaphores         = &image_available_semaphores[current_frame];
        submit_options.num_wait_semaphores     = 1;
        submit_options.signal_semaphores       = &render_finished_semaphores[current_frame];
        submit_options.num_signal_semaphores   = 1;
        submit_options.wait_dst_stage          = gfx::PipelineStage::ColorAttachmentOutput;
        submit_options.fence                   = in_flight_fences[current_frame];
        gfx::queue_submit(gfx::QueueType::Graphics, submit_options);

        gfx::SwapchainStatus::Enum present_status = gfx::queue_present({ .swapchain = swapchain, .image_index = acquire_swapchain.image_index, .wait_semaphores = &render_finished_semaphores[current_frame], .num_wait_semaphores = 1 });

        if (present_status == gfx::SwapchainStatus::OutOfDate || present_status == gfx::SwapchainStatus::Suboptimal || window.resized)
        {
            window.resized = false;
            recreate_swapchain();
        }
        else if (present_status != gfx::SwapchainStatus::Success)
        {
            throw std::runtime_error("failed to present swapchain image!");
        }

        current_frame = (current_frame + 1) % MAX_FRAMES_IN_FLIGHT;
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
            { .width              = width,
              .height             = height,
              .color_attachments  = { { .texture = gfx::get_swapchain_back_buffer(swapchain, i), .view_type = gfx::TextureViewType::Texture2D, .aspect_flags = gfx::TextureAspect::Color } },
              .render_pass_layout = { .colors = { { .format = gfx::Format::B8G8R8A8_UNORM, .layout = gfx::ImageLayout::PresentSrc, .load_op = gfx::RenderPassLoadOp::Clear } } } });
        }

        swapchain_width  = width;
        swapchain_height = height;
    }

    void record_commands(gfx::Handle<gfx::CommandBuffer> cmd, u32 image_index)
    {
        gfx::cmd_begin(cmd);
        gfx::cmd_begin_render_pass(cmd,
                                   { .framebuffer        = swapchain_framebuffers[image_index],
                                     .render_pass_layout = render_pass_layout,
                                     .extent             = { swapchain_width, swapchain_height },
                                     .clear              = true,
                                     .clear_values       = { { .color = { .r = 0.0f, .g = 0.0f, .b = 1.0f, .a = 1.0f } } } });
        gfx::cmd_bind_graphics_pipeline(cmd, pipeline);

        if (!das_program->failed())
        {
            // create context
            Context ctx(das_program->getContextStackSize());
            if (das_program->simulate(ctx, das_logs))
            {
                // find function. its up to application to check, if function is not null
                auto function = ctx.findFunction("record_commands");
                if (function)
                {
                    // call context function
                    vec4f args[1];
                    args[0] = cast<const gfx::Handle<gfx::CommandBuffer>&>::from(cmd);
                    ctx.evalWithCatch(function, args);
                }
            }
        }

        // gfx::cmd_set_viewport(cmd, { .x = 0.0f, .y = 0.0f, .width = (f32)swapchain_width, .height = (f32)swapchain_height, .min_depth = 0.0f, .max_depth = 1.0f });

        gfx::cmd_set_scissor(cmd, { .offset = { 0, 0 }, .extent = { swapchain_width, window.height } });
        gfx::cmd_draw(cmd, { .vertex_count = 3, .instance_count = 1, .first_vertex = 0, .first_instance = 0 });
        gfx::cmd_end_render_pass(cmd);
        gfx::cmd_end(cmd);
    }

    void shutdown()
    {
        das::Module::Shutdown();
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