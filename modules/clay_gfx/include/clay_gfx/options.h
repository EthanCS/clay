#pragma once

#include <clay_gfx/define.h>
#include <clay_core/macro.h>
#include <clay_gfx/resource.h>

namespace clay
{
namespace gfx
{
struct InitBackendOptions {
    BackendType::Enum type;
    void*             window; // Maybe SDL_Window* or any other window handle
    const char*       app_name{ nullptr };
    u32               device_id{ u32_MAX };
    bool              debug{ false };
};

struct CreateSwapchainOptions {
    u32          width  = 0;
    u32          height = 0;
    bool         vsync  = false;
    Format::Enum format = Format::Undefined;
};

struct CreateShaderOptions {
    const void* code      = nullptr;
    u32         code_size = 0;
};

struct CreateTextureOptions {
    const char*        name         = nullptr;
    u32                width        = 1;
    u32                height       = 1;
    u32                depth        = 1;
    u32                array_size   = 1;
    u32                mip_levels   = 1;
    Format::Enum       format       = Format::Undefined;
    TextureType::Enum  texture_type = TextureType::Texture2D;
    TextureUsage::Flag usage        = TextureUsage::Sampled;
    MemoryUsage::Enum  memory_usage = MemoryUsage::GpuOnly;
};

struct CreateSamplerOptions {
    FilterType::Enum  min_filter     = FilterType::Linear;
    FilterType::Enum  mag_filter     = FilterType::Linear;
    MipmapType::Enum  mipmap_mode    = MipmapType::Linear;
    AddressMode::Enum address_u      = AddressMode::Repeat;
    AddressMode::Enum address_v      = AddressMode::Repeat;
    AddressMode::Enum address_w      = AddressMode::Repeat;
    float             mip_lod_bias   = 0;
    float             max_anisotropy = 0;
    CompareOp::Enum   compare_op     = CompareOp::Never;
};

struct CreateBufferOptions {
    u64               size = 0;
    BufferUsage::Flag usage;
    MemoryUsage::Enum memory_usage;
    bool              exclusive{ true };
};

struct AcquireNextImageOptions {
    u64               time_out  = u64_MAX;
    Handle<Semaphore> semaphore = {};
    Handle<Fence>     fence     = {};
};

struct QueueSubmitOptions {
    Handle<CommandBuffer>* command_buffers       = nullptr;
    u32                    num_command_buffers   = 0;
    Handle<Semaphore>*     wait_semaphores       = nullptr;
    u32                    num_wait_semaphores   = 0;
    Handle<Semaphore>*     signal_semaphores     = nullptr;
    u32                    num_signal_semaphores = 0;
    PipelineStage::Flag    wait_dst_stage        = PipelineStage::TopOfPipe;
    Handle<Fence>          fence                 = {};
};

struct QueuePresentOptions {
    Handle<Swapchain>  swapchain           = {};
    u32                image_index         = 0;
    Handle<Semaphore>* wait_semaphores     = nullptr;
    u32                num_wait_semaphores = 0;
};

struct CreateFramebufferOptions {
    u32              width  = 0;
    u32              height = 0;
    TextureViewDesc  color_attachments[MAX_COLOR_ATTACHMENTS];
    TextureViewDesc  depth_stencil_attachment;
    RenderPassLayout render_pass_layout;
};

struct CreatePipelineLayoutOptions {
    Handle<DescriptorSetLayout> descriptor_set_layouts[MAX_DESCRIPTOR_SET_LAYOUTS];
    u8                          num_descriptor_set_layouts = 0;

    CreatePipelineLayoutOptions& reset();
    CreatePipelineLayoutOptions& add_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout);
};

struct CreateGraphicsPipelineOptions {
    const char* name = nullptr;

    Handle<PipelineLayout> layout;
    ShaderInfo             vertex_shader;
    ShaderInfo             pixel_shader;

    GraphicsState graphics_state;

    CreateGraphicsPipelineOptions& set_pipeline_layout(const Handle<PipelineLayout>& layout);
};

struct CreateDescriptorSetLayoutOptions {
    struct Binding {
        DescriptorType::Enum type;
        u32                  index;
        u32                  count;
        const char*          name;
    };

    Binding     bindings[MAX_DESCRIPTORS_PER_SET];
    u32         num_bindings = 0;
    u32         set_index    = 0;
    const char* name         = nullptr;

    CreateDescriptorSetLayoutOptions& reset();
    CreateDescriptorSetLayoutOptions& set_set_index(u32 index);
    CreateDescriptorSetLayoutOptions& set_name(const char* name);
    CreateDescriptorSetLayoutOptions& add_binding(DescriptorType::Enum type, u32 index, u32 count, const char* name);
};

struct CreateDescriptorSetOptions {
    Handle<DescriptorSetLayout> layout;
    u32                         set_index;
};

struct UpdateDescriptorSetOptions {
    struct Info {
        u32             binding;
        Handle<Buffer>  buffer;
        Handle<Texture> texture;
        Handle<Sampler> sampler;
    };

    Info infos[MAX_DESCRIPTORS_PER_SET];
    u32  count = 0;

    UpdateDescriptorSetOptions& reset();
    UpdateDescriptorSetOptions& bind_buffer(u32 binding, const Handle<Buffer>& buffer);
    UpdateDescriptorSetOptions& bind_texture(u32 binding, const Handle<Texture>& texture);
    UpdateDescriptorSetOptions& bind_texture_sampler(u32 binding, const Handle<Texture>& texture, const Handle<Sampler>& sampler);
};

struct CmdBeginRenderPassOptions {
    Handle<Framebuffer> framebuffer;
    RenderPassLayout    render_pass_layout;
    i32                 offset[2] = { 0, 0 };
    u32                 extent[2] = { 0, 0 };
    bool                clear     = true;
    ClearValue          clear_values[MAX_ATTACHMENTS];
};

struct CmdSetViewportOptions {
    f32 x         = 0.0f;
    f32 y         = 0.0f;
    f32 width     = 0.0f;
    f32 height    = 0.0f;
    f32 min_depth = 0.0f;
    f32 max_depth = 1.0f;
};

struct CmdSetScissorOptions {
    i32 offset[2] = { 0, 0 };
    u32 extent[2] = { 0, 0 };
};

struct CmdDrawOptions {
    u32 vertex_count   = 0;
    u32 instance_count = 1;
    u32 first_vertex   = 0;
    u32 first_instance = 0;
};

struct CmdDrawIndexedOptions {
    u32 index_count    = 0;
    u32 instance_count = 1;
    u32 first_index    = 0;
    i32 vertex_offset  = 0;
    u32 first_instance = 0;
};

struct CmdBindVertexBufferOptions {
    u32            binding = 0;
    Handle<Buffer> buffer;
    u32            offset = 0;
};

struct CmdBindVertexBuffersOptions {
    u32             first_binding = 0;
    u32             binding_count = 0;
    Handle<Buffer>* buffers       = nullptr;
    u32*            offsets       = nullptr;
};

struct CmdBindIndexBufferOptions {
    Handle<Buffer>  buffer;
    u32             offset = 0;
    IndexType::Enum index_type;
};

struct CmdBindDescriptorSetsOptions {
    Handle<PipelineLayout>  layout;
    PipelineBindPoint::Enum bind_point;
    u32                     first_set;
    Handle<DescriptorSet>*  sets     = nullptr;
    u32                     num_sets = 0;
};

struct CmdCopyBufferOptions {
    Handle<Buffer> src_buffer;
    u64            src_offset;
    Handle<Buffer> dst_buffer;
    u64            dst_offset;
    u64            size;
};

struct CmdCopyBufferToTextureOptions {
    Handle<Buffer> buffer;
    u64            buffer_offset         = 0;
    u32            buffer_row_length     = 0;
    u32            buffer_texture_height = 0;

    Handle<Texture>     texture;
    i32                 texture_offset[3] = { 0, 0, 0 };
    u32                 texture_extent[3] = { 0, 0, 1 };
    TextureAspect::Flag aspect_flags;
    u32                 mip_level        = 0;
    u32                 base_array_layer = 0;
    u32                 layer_count      = 1;

    ImageLayout::Enum dst_layout;
};

struct CmdPipelineBarrierOptions {
    PipelineStage::Flag src_stage;
    PipelineStage::Flag dst_stage;

    TextureBarrier texture_barriers[MAX_BARRIERS];
    u32            num_texture_barriers = 0;

    CmdPipelineBarrierOptions& source_stage(const PipelineStage::Flag& stage);
    CmdPipelineBarrierOptions& destination_stage(const PipelineStage::Flag& stage);
    CmdPipelineBarrierOptions& add_texture_barrier(const TextureBarrier& barrier);
};

} // namespace gfx
} // namespace clay