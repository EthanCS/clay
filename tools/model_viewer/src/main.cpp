#include <iostream>
#include <stdexcept>
#include <chrono>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <unordered_map>

#include <ShaderConductor-clay/ShaderConductor.hpp>
#include <clay_app/window.h>
#include <clay_gfx/backend.h>
#include <clay_image/image.h>

#include <rtm/camera_utilsf.h>
#include <rtm/matrix3x4f.h>
#include <rtm/matrix4x4f.h>
#include <rtm/math.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

//////////////////////////////////////////////////////////////////////////
// Assets

const char* VERTEX_SHADER = R"(
#pragma target 6.0

[[vk::binding(0)]]
cbuffer UBO : register(b0) {
  float4x4 model;
  float4x4 view;
  float4x4 proj;
};

struct VSInput {
  float3 inPosition : POSITION;
  float3 inColor : COLOR;
  float2 inUV : TEXCOORD0;
};

struct VSOutput {
  float3 fragColor : COLOR;
  float2 uv : TEXCOORD0;
  float4 outPosition : SV_Position;
};

VSOutput main(VSInput input) {
  VSOutput output;
  output.outPosition = mul(mul(mul(float4(input.inPosition, 1.0), model), view), proj);
  output.fragColor = input.inColor;
  output.uv = input.inUV;
  return output;
}
)";

const char* FRAGMENT_SHADER = R"(
#pragma target 6.0

[[vk::combinedImageSampler]][[vk::binding(1)]]
Texture2D<float4> myTexture : register(t0);

[[vk::combinedImageSampler]][[vk::binding(1)]]
SamplerState mySampler;

struct PSInput {
  float3 fragColor : COLOR;
  float2 uv : TEXCOORD0;
};

float4 main(PSInput input) : SV_Target {
  return float4(input.fragColor, 1.0f) * myTexture.Sample(mySampler, input.uv);
}
)";

//////////////////////////////////////////////////////////////////////////

using namespace clay;
using namespace ShaderConductor;

const int   MAX_FRAMES_IN_FLIGHT = 3;
const u32   WIDTH                = 1280;
const u32   HEIGHT               = 720;
const char* TITLE                = "Model Viewer";

const char* MODEL_PATH = "E:/clay/test/gfx/viking_room.obj";

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;

    bool operator==(const Vertex& other) const { return position == other.position && color == other.color && uv == other.uv; }
};

namespace std
{
template <>
struct hash<glm::vec2> {
    size_t operator()(glm::vec2 const& k) const { return std::hash<float>()(k.x) ^ std::hash<float>()(k.y); }
};
template <>
struct hash<glm::vec3> {
    size_t operator()(glm::vec3 const& k) const { return std::hash<float>()(k.x) ^ std::hash<float>()(k.y) ^ std::hash<float>()(k.z); }
};
template <>
struct hash<Vertex> {
    size_t operator()(Vertex const& vertex) const { return ((hash<glm::vec3>()(vertex.position) ^ (hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^ (hash<glm::vec2>()(vertex.uv) << 1); }
};
} // namespace std

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<u32>    indices;
};

struct UBO {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

class ModelViewerApp
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

    //////////////////////////////////////////////////////////////////////////
    // Per frame data
    u32                                          current_frame = 0;
    std::vector<gfx::Handle<gfx::Framebuffer>>   swapchain_framebuffers;
    std::vector<gfx::Handle<gfx::Fence>>         in_flight_fences;
    std::vector<gfx::Handle<gfx::Semaphore>>     image_available_semaphores;
    std::vector<gfx::Handle<gfx::Semaphore>>     render_finished_semaphores;
    std::vector<gfx::Handle<gfx::CommandBuffer>> command_buffers;

    std::vector<gfx::Handle<gfx::Buffer>>        uniform_buffers;
    std::vector<gfx::Handle<gfx::DescriptorSet>> descriptor_sets;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // Common
    gfx::RenderPassLayout         render_pass_layout;
    gfx::Handle<gfx::CommandPool> command_pool;

    gfx::Handle<gfx::Swapchain> swapchain;
    u32                         swapchain_width  = 0;
    u32                         swapchain_height = 0;
    gfx::Handle<gfx::Texture>   depth_texture;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // Assets
    gfx::Handle<gfx::Shader> hello_vs;
    gfx::Handle<gfx::Shader> hello_fs;

    std::shared_ptr<Mesh>    mesh;
    gfx::Handle<gfx::Buffer> model_vb;
    gfx::Handle<gfx::Buffer> model_ib;

    std::shared_ptr<image::IImage> image;
    gfx::Handle<gfx::Texture>      model_tex;
    gfx::Handle<gfx::Sampler>      model_sampler;

    gfx::Handle<gfx::DescriptorSetLayout> descriptor_set_layout;
    gfx::Handle<gfx::PipelineLayout>      pipeline_layout;
    gfx::Handle<gfx::GraphicsPipeline>    pipeline;
    //////////////////////////////////////////////////////////////////////////

    void init()
    {
        window.init({ .title = TITLE, .width = WIDTH, .height = HEIGHT });

        bool bInit = gfx::init({ .type     = gfx::BackendType::Vulkan,
                                 .window   = window.platform_handle,
                                 .app_name = TITLE,
                                 .debug    = true });
        if (!bInit) { throw std::runtime_error("failed to initialize clay gfx!"); }

        command_pool = gfx::create_command_pool(gfx::QueueType::Graphics);

        create_assets();

        command_buffers.resize(MAX_FRAMES_IN_FLIGHT);
        for (usize i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
        {
            command_buffers[i] = gfx::allocate_command_buffer(command_pool);
        }

        in_flight_fences.resize(MAX_FRAMES_IN_FLIGHT);
        image_available_semaphores.resize(MAX_FRAMES_IN_FLIGHT);
        render_finished_semaphores.resize(MAX_FRAMES_IN_FLIGHT);
        for (usize i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
        {
            in_flight_fences[i]           = gfx::create_fence(true);
            image_available_semaphores[i] = gfx::create_semaphore();
            render_finished_semaphores[i] = gfx::create_semaphore();
        }

        uniform_buffers.resize(MAX_FRAMES_IN_FLIGHT);
        descriptor_sets.resize(MAX_FRAMES_IN_FLIGHT);
        for (usize i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
        {
            uniform_buffers[i] = gfx::create_buffer({ .size = sizeof(UBO), .usage = gfx::BufferUsage::UniformBuffer, .memory_usage = gfx::MemoryUsage::CpuToGpu });
            descriptor_sets[i] = gfx::create_descriptor_set({ .layout = descriptor_set_layout });

            gfx::UpdateDescriptorSetOptions update_info = {};
            update_info.bind_buffer(0u, uniform_buffers[i]);
            update_info.bind_texture_sampler(1u, model_tex, model_sampler);
            gfx::update_descriptor_set(descriptor_sets[i], update_info);
        }

        create_swapchain(window.width, window.height);
    }

    void create_assets()
    {
        // Load model
        mesh = std::make_shared<Mesh>();
        {
            tinyobj::attrib_t                attrib;
            std::vector<tinyobj::shape_t>    shapes;
            std::vector<tinyobj::material_t> materials;
            std::string                      warn, err;

            if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, MODEL_PATH))
            {
                throw std::runtime_error(warn + err);
            }

            std::unordered_map<Vertex, u32> uniqueVertices = {};

            for (const auto& shape : shapes)
            {
                for (const auto& index : shape.mesh.indices)
                {
                    Vertex vertex = {};

                    vertex.position = {
                        attrib.vertices[3 * index.vertex_index + 0],
                        attrib.vertices[3 * index.vertex_index + 1],
                        attrib.vertices[3 * index.vertex_index + 2]
                    };

                    vertex.uv = {
                        attrib.texcoords[2 * index.texcoord_index + 0],
                        1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
                    };

                    vertex.color = { 1.0f, 1.0f, 1.0f };

                    if (uniqueVertices.count(vertex) == 0)
                    {
                        uniqueVertices[vertex] = static_cast<u32>(mesh->vertices.size());
                        mesh->vertices.push_back(vertex);
                    }

                    mesh->indices.push_back(uniqueVertices[vertex]);
                }
            }
        }

        auto vert_shader_code = Compiler::Compile({ .source = VERTEX_SHADER, .fileName = "vert.hlsl", .entryPoint = "main", .stage = ShaderStage::VertexShader }, {}, { .language = ShadingLanguage::SpirV });
        auto frag_shader_code = Compiler::Compile({ .source = FRAGMENT_SHADER, .fileName = "frag.hlsl", .entryPoint = "main", .stage = ShaderStage::PixelShader }, {}, { .language = ShadingLanguage::SpirV });
        hello_vs              = gfx::create_shader({ .code = vert_shader_code.target.Data(), .code_size = (u32)vert_shader_code.target.Size() });
        hello_fs              = gfx::create_shader({ .code = frag_shader_code.target.Data(), .code_size = (u32)frag_shader_code.target.Size() });

        model_vb = create_vertex_buffer(command_pool, mesh->vertices.data(), mesh->vertices.size() * sizeof(Vertex));
        model_ib = create_index_buffer(command_pool, mesh->indices.data(), mesh->indices.size() * sizeof(u32));

        image         = image::load_image("E:/clay/test/gfx/clay_cat.jpg", image::ImageChannel::RGBAlpha);
        model_tex     = create_texture(command_pool, image.get());
        model_sampler = gfx::create_sampler({});

        // Create descriptor set layout
        gfx::CreateDescriptorSetLayoutOptions layout_options = {};
        layout_options
        .add_binding(gfx::DescriptorType::UniformBuffer, 0u, 1u, "UBO")
        .add_binding(gfx::DescriptorType::CombinedImageSampler, 1u, 1u, "myTexture");
        descriptor_set_layout = gfx::create_descriptor_set_layout(layout_options);

        // Render pass layout
        render_pass_layout           = {};
        render_pass_layout.colors[0] = {
            .format  = gfx::Format::B8G8R8A8_UNORM,
            .layout  = gfx::ImageLayout::PresentSrc,
            .load_op = gfx::RenderPassLoadOp::Clear
        };
        render_pass_layout.depth_stencil = {
            .format   = gfx::Format::D32_SFLOAT,
            .layout   = gfx::ImageLayout::DepthStencilAttachmentOptimal,
            .depth_op = gfx::RenderPassLoadOp::Clear
        };

        // Pipeline layout
        gfx::CreatePipelineLayoutOptions pipeline_layout_options = {};
        pipeline_layout_options.add_descriptor_set_layout(descriptor_set_layout);
        pipeline_layout = gfx::create_pipeline_layout(pipeline_layout_options);

        // Create pipeline
        gfx::CreateGraphicsPipelineOptions pipeline_options = { .name           = "triangle",
                                                                .layout         = pipeline_layout,
                                                                .vertex_shader  = { .compiled_shader = hello_vs, .entry_func = "main" },
                                                                .pixel_shader   = { .compiled_shader = hello_fs, .entry_func = "main" },
                                                                .graphics_state = { .depth_test_enabled = true, .render_pass_layout = render_pass_layout } };
        pipeline_options.graphics_state.set_vertex_buffer_binding(0, sizeof(Vertex));
        pipeline_options.graphics_state.set_vertex_buffer_attribute(0, 0, offsetof(Vertex, position), gfx::Format::R32G32B32_SFLOAT);
        pipeline_options.graphics_state.set_vertex_buffer_attribute(0, 1, offsetof(Vertex, color), gfx::Format::R32G32B32_SFLOAT);
        pipeline_options.graphics_state.set_vertex_buffer_attribute(0, 2, offsetof(Vertex, uv), gfx::Format::R32G32_SFLOAT);
        pipeline = gfx::create_graphics_pipeline(pipeline_options);
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

        update_uniform_buffer(current_frame);

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
        gfx::destroy_texture(depth_texture);
        gfx::destroy_swapchain(swapchain);

        create_swapchain(window.width, window.height);
    }

    void create_swapchain(u32 width, u32 height)
    {
        swapchain      = gfx::create_swapchain({ .width = width, .height = height, .vsync = true, .format = gfx::Format::B8G8R8A8_UNORM });
        u32 num_images = gfx::get_swapchain_image_count(swapchain);

        depth_texture = gfx::create_texture({ .width = width, .height = height, .format = gfx::Format::D32_SFLOAT, .usage = gfx::TextureUsage::DepthStencilAttachment, .memory_usage = gfx::MemoryUsage::GpuOnly });

        gfx::RenderPassLayout swapchain_render_pass_layout = {};
        swapchain_render_pass_layout.colors[0]             = {
                        .format  = gfx::Format::B8G8R8A8_UNORM,
                        .layout  = gfx::ImageLayout::PresentSrc,
                        .load_op = gfx::RenderPassLoadOp::Clear
        };
        swapchain_render_pass_layout.depth_stencil = {
            .format   = gfx::Format::D32_SFLOAT,
            .layout   = gfx::ImageLayout::DepthStencilAttachmentOptimal,
            .depth_op = gfx::RenderPassLoadOp::Clear
        };

        swapchain_framebuffers.resize(num_images);
        for (u32 i = 0; i < num_images; i++)
        {
            swapchain_framebuffers[i] = gfx::create_framebuffer(
            { .width                    = width,
              .height                   = height,
              .color_attachments        = { { .texture = gfx::get_swapchain_back_buffer(swapchain, i), .view_type = gfx::TextureViewType::Texture2D, .aspect_flags = gfx::TextureAspect::Color } },
              .depth_stencil_attachment = { .texture = depth_texture, .view_type = gfx::TextureViewType::Texture2D, .aspect_flags = gfx::TextureAspect::Depth },
              .render_pass_layout       = swapchain_render_pass_layout });
        }

        swapchain_width  = width;
        swapchain_height = height;
    }

    void update_uniform_buffer(u32 image_index)
    {
        static auto startTime = std::chrono::high_resolution_clock::now();

        auto  currentTime = std::chrono::high_resolution_clock::now();
        float time        = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

        UBO ubo   = {};
        ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        ubo.view  = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        ubo.proj  = glm::perspective(glm::radians(45.0f), swapchain_width / (float)swapchain_height, 0.1f, 10.0f);
        ubo.proj[1][1] *= -1;

        void* data = gfx::map_buffer(uniform_buffers[image_index]);
        memcpy(data, &ubo, sizeof(UBO));
        gfx::unmap_buffer(uniform_buffers[image_index]);
    }

    void record_commands(gfx::Handle<gfx::CommandBuffer> cmd, u32 image_index)
    {
        gfx::cmd_begin(cmd, false);
        gfx::cmd_begin_render_pass(cmd,
                                   { .framebuffer        = swapchain_framebuffers[image_index],
                                     .render_pass_layout = render_pass_layout,
                                     .extent             = { swapchain_width, swapchain_height },
                                     .clear              = true,
                                     .clear_values       = { { .color = { 0.0f, 0.0f, 1.0f, 1.0f } }, { .depth = 1.0f } } });
        gfx::cmd_bind_graphics_pipeline(cmd, pipeline);
        gfx::cmd_set_viewport(cmd, { .x = 0.0f, .y = 0.0f, .width = (f32)swapchain_width, .height = (f32)swapchain_height, .min_depth = 0.0f, .max_depth = 1.0f });
        gfx::cmd_set_scissor(cmd, { .offset = { 0, 0 }, .extent = { swapchain_width, window.height } });
        gfx::cmd_bind_vertex_buffer(cmd, { .binding = 0, .buffer = model_vb, .offset = 0 });
        gfx::cmd_bind_index_buffer(cmd, { .buffer = model_ib, .offset = 0, .index_type = gfx::IndexType::Uint32 });
        gfx::cmd_bind_descriptor_sets(cmd, { .layout = pipeline_layout, .bind_point = gfx::PipelineBindPoint::Graphics, .first_set = 0, .sets = &descriptor_sets[current_frame], .num_sets = 1 });
        gfx::cmd_draw_indexed(cmd, { .index_count = (u32)mesh->indices.size(), .instance_count = 1, .first_index = 0, .vertex_offset = 0, .first_instance = 0 });
        gfx::cmd_end_render_pass(cmd);
        gfx::cmd_end(cmd);
    }

    static void copy_buffer(const gfx::Handle<gfx::CommandPool>& pool, const gfx::Handle<gfx::Buffer>& src, const gfx::Handle<gfx::Buffer>& dst, u64 size)
    {
        gfx::Handle<gfx::CommandBuffer> cb = begin_single_command(pool);
        {
            gfx::cmd_copy_buffer(cb, { .src_buffer = src, .src_offset = 0, .dst_buffer = dst, .dst_offset = 0, .size = size });
        }
        end_single_command(cb);
    }

    static void copy_buffer_to_image(const gfx::Handle<gfx::CommandPool>& pool, const gfx::Handle<gfx::Buffer>& buffer, const gfx::Handle<gfx::Texture>& image, u32 width, u32 height)
    {
        gfx::Handle<gfx::CommandBuffer> cb = begin_single_command(pool);
        gfx::cmd_copy_buffer_to_texture(cb, { .buffer         = buffer,
                                              .texture        = image,
                                              .texture_extent = { width, height, 1 },
                                              .aspect_flags   = gfx::TextureAspect::Color,
                                              .dst_layout     = gfx::ImageLayout::TransferDstOptimal });
        end_single_command(cb);
    }

    static gfx::Handle<gfx::Buffer> create_vertex_buffer(const gfx::Handle<gfx::CommandPool>& pool, const void* data, usize size)
    {
        gfx::Handle<gfx::Buffer> staging_buffer = gfx::create_buffer({ .size = size, .usage = gfx::BufferUsage::TransferSrc, .memory_usage = gfx::MemoryUsage::CpuToGpu });
        void*                    mapped_data    = gfx::map_buffer(staging_buffer);
        memcpy(mapped_data, data, size);
        gfx::unmap_buffer(staging_buffer);

        gfx::Handle<gfx::Buffer> vertex_buffer = gfx::create_buffer({ .size = size, .usage = (gfx::BufferUsage::Flag)(gfx::BufferUsage::VertexBuffer | gfx::BufferUsage::TransferDst), .memory_usage = gfx::MemoryUsage::GpuOnly });
        copy_buffer(pool, staging_buffer, vertex_buffer, size);

        gfx::destroy_buffer(staging_buffer);
        return vertex_buffer;
    }

    static gfx::Handle<gfx::Buffer> create_index_buffer(const gfx::Handle<gfx::CommandPool>& pool, const void* data, usize size)
    {
        gfx::Handle<gfx::Buffer> staging_buffer = gfx::create_buffer({ .size = size, .usage = gfx::BufferUsage::TransferSrc, .memory_usage = gfx::MemoryUsage::CpuToGpu });
        void*                    mapped_data    = gfx::map_buffer(staging_buffer);
        memcpy(mapped_data, data, size);
        gfx::unmap_buffer(staging_buffer);

        gfx::Handle<gfx::Buffer> index_buffer = gfx::create_buffer({ .size = size, .usage = (gfx::BufferUsage::Flag)(gfx::BufferUsage::IndexBuffer | gfx::BufferUsage::TransferDst), .memory_usage = gfx::MemoryUsage::GpuOnly });
        copy_buffer(pool, staging_buffer, index_buffer, size);

        gfx::destroy_buffer(staging_buffer);
        return index_buffer;
    }

    static gfx::Handle<gfx::Texture> create_texture(const gfx::Handle<gfx::CommandPool>& pool, const image::IImage* pImage)
    {
        gfx::Handle<gfx::Buffer> staging_buffer = gfx::create_buffer({ .size = pImage->get_size(), .usage = gfx::BufferUsage::TransferSrc, .memory_usage = gfx::MemoryUsage::CpuToGpu });
        void*                    mapped_data    = gfx::map_buffer(staging_buffer);
        memcpy(mapped_data, pImage->get_data(), pImage->get_size());
        gfx::unmap_buffer(staging_buffer);

        gfx::Handle<gfx::Texture> image = gfx::create_texture({ .width        = pImage->get_width(),
                                                                .height       = pImage->get_height(),
                                                                .format       = gfx::Format::R8G8B8A8_UNORM,
                                                                .usage        = (gfx::TextureUsage::Flag)(gfx::TextureUsage::Sampled | gfx::TextureUsage::TransferDst),
                                                                .memory_usage = gfx::MemoryUsage::GpuOnly });

        transition_image_layout(pool, image, gfx::ImageLayout::Undefined, gfx::ImageLayout::TransferDstOptimal);
        copy_buffer_to_image(pool, staging_buffer, image, pImage->get_width(), pImage->get_height());
        transition_image_layout(pool, image, gfx::ImageLayout::TransferDstOptimal, gfx::ImageLayout::ShaderReadOnlyOptimal);

        gfx::destroy_buffer(staging_buffer);
        return image;
    }

    static inline gfx::Handle<gfx::CommandBuffer> begin_single_command(const gfx::Handle<gfx::CommandPool>& pool)
    {
        gfx::Handle<gfx::CommandBuffer> cb = gfx::allocate_command_buffer(pool);
        gfx::cmd_begin(cb, true);
        return cb;
    }

    static inline void end_single_command(gfx::Handle<gfx::CommandBuffer> cb)
    {
        gfx::cmd_end(cb);
        gfx::queue_submit(gfx::QueueType::Graphics, { .command_buffers = &cb, .num_command_buffers = 1 });
        gfx::queue_wait_idle(gfx::QueueType::Graphics);
        gfx::free_command_buffer(cb);
    }

    static void transition_image_layout(const gfx::Handle<gfx::CommandPool>& pool, gfx::Handle<gfx::Texture> image, gfx::ImageLayout::Enum old_layout, gfx::ImageLayout::Enum new_layout)
    {
        gfx::Handle<gfx::CommandBuffer> cb = begin_single_command(pool);
        {
            gfx::CmdPipelineBarrierOptions barrier_options = {};
            if (old_layout == gfx::ImageLayout::Undefined && new_layout == gfx::ImageLayout::TransferDstOptimal)
            {
                barrier_options
                .source_stage(gfx::PipelineStage::TopOfPipe)
                .destination_stage(gfx::PipelineStage::Transfer)
                .add_texture_barrier({ .texture = image, .old_layout = old_layout, .new_layout = new_layout, .aspect_flags = gfx::TextureAspect::Color, .dst_access = gfx::AccessMask::TransferWrite });
            }
            else if (old_layout == gfx::ImageLayout::TransferDstOptimal && new_layout == gfx::ImageLayout::ShaderReadOnlyOptimal)
            {
                barrier_options
                .source_stage(gfx::PipelineStage::Transfer)
                .destination_stage(gfx::PipelineStage::FragmentShader)
                .add_texture_barrier({ .texture = image, .old_layout = old_layout, .new_layout = new_layout, .aspect_flags = gfx::TextureAspect::Color, .src_access = gfx::AccessMask::TransferWrite, .dst_access = gfx::AccessMask::ShaderRead });
            }
            else
            {
                throw std::runtime_error("unsupported layout transition!");
            }

            gfx::cmd_pipeline_barrier(cb, barrier_options);
        }
        end_single_command(cb);
    }

    void shutdown()
    {
        gfx::shutdown();
        window.shutdown();
    }
};

int main(int argc, char** argv)
{
    ModelViewerApp app;
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