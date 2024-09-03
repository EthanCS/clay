#pragma once

#include <clay_core/macro.h>
#include <clay_gfx/handle.h>
#include <clay_gfx/define.h>

#define DEFINE_CLAY_GFX_RESOURCE_TAG(name) \
    struct name {                          \
    };

namespace clay
{
namespace gfx
{

DEFINE_CLAY_GFX_RESOURCE_TAG(Device)
DEFINE_CLAY_GFX_RESOURCE_TAG(Queue)
DEFINE_CLAY_GFX_RESOURCE_TAG(Swapchain)
DEFINE_CLAY_GFX_RESOURCE_TAG(Fence)
DEFINE_CLAY_GFX_RESOURCE_TAG(Semaphore)
DEFINE_CLAY_GFX_RESOURCE_TAG(Buffer)
DEFINE_CLAY_GFX_RESOURCE_TAG(Texture)
DEFINE_CLAY_GFX_RESOURCE_TAG(Sampler)
DEFINE_CLAY_GFX_RESOURCE_TAG(Shader)
DEFINE_CLAY_GFX_RESOURCE_TAG(PipelineLayout)
DEFINE_CLAY_GFX_RESOURCE_TAG(GraphicsPipeline)
DEFINE_CLAY_GFX_RESOURCE_TAG(ComputePipeline)
DEFINE_CLAY_GFX_RESOURCE_TAG(Framebuffer)
DEFINE_CLAY_GFX_RESOURCE_TAG(DescriptorSetLayout)
DEFINE_CLAY_GFX_RESOURCE_TAG(DescriptorSet)
DEFINE_CLAY_GFX_RESOURCE_TAG(CommandPool)
DEFINE_CLAY_GFX_RESOURCE_TAG(CommandBuffer)

struct SwapchainAcquireResult {
    u8                    image_index;
    SwapchainStatus::Enum status;
};

struct ColorAttachmentDesc {
    Format::Enum      format  = Format::Undefined;
    ImageLayout::Enum layout  = ImageLayout::Undefined;
    LoadAction::Enum  load_op = LoadAction::DontCare;

    bool operator==(const ColorAttachmentDesc& rhs) const
    {
        return format == rhs.format && layout == rhs.layout && load_op == rhs.load_op;
    }
};

struct DepthStencilAttachmentDesc {
    Format::Enum      format     = Format::Undefined;
    ImageLayout::Enum layout     = ImageLayout::Undefined;
    LoadAction::Enum  depth_op   = LoadAction::DontCare;
    LoadAction::Enum  stencil_op = LoadAction::DontCare;

    bool operator==(const DepthStencilAttachmentDesc& rhs) const
    {
        return format == rhs.format && layout == rhs.layout && depth_op == rhs.depth_op && stencil_op == rhs.stencil_op;
    }
};

struct RenderPassLayout {
    ColorAttachmentDesc        colors[MAX_COLOR_ATTACHMENTS] = {};
    DepthStencilAttachmentDesc depth_stencil                 = {};

    constexpr bool has_depth_stencil() const { return depth_stencil.format != Format::Undefined; }
    constexpr u8   num_colors() const
    {
        u8 count = 0;
        for (u8 i = 0; i < MAX_COLOR_ATTACHMENTS; ++i)
        {
            if (colors[i].format == Format::Undefined) [[unlikely]] { break; }
            else { ++count; }
        }
        return count;
    }
};

struct BlendState {
    bool blend_enabled = false;

    BlendFactor::Enum src_color = BlendFactor::One;
    BlendFactor::Enum dst_color = BlendFactor::One;
    BlendOp::Enum     color_op  = BlendOp::Add;

    BlendFactor::Enum src_alpha = BlendFactor::One;
    BlendFactor::Enum dst_alpha = BlendFactor::One;
    BlendOp::Enum     alpha_op  = BlendOp::Add;

    ColorWriteEnabled::Flag color_write = ColorWriteEnabled::All;
};

struct StencilOperationState {
    StencilOp::Enum fail_op       = StencilOp::Keep;
    StencilOp::Enum pass_op       = StencilOp::Keep;
    StencilOp::Enum depth_fail_op = StencilOp::Keep;
    CompareOp::Enum compare_op    = CompareOp::Always;
    u32             compare_mask  = 0xff;
    u32             write_mask    = 0xff;
    u32             reference     = 0xff;
};

struct VertexAttribute {
    u16          byte_offset = u16_MAX;
    Format::Enum format      = Format::Undefined;
};

struct VertexBufferBinding {
    u16             byte_stride = u16_MAX;
    VertexAttribute attributes[MAX_VERTEX_ATTRIBUTES];
};

struct ShaderInfo {
    Handle<Shader> compiled_shader = {};
    const char*    entry_func      = nullptr;

    inline bool is_valid() const { return compiled_shader.is_valid() && entry_func != nullptr; }
};

struct GraphicsState {
    /////// Topology
    PrimitiveTopology::Enum primitive_topology = PrimitiveTopology::TriangleList;

    /////// Rasterizer
    CullMode::Enum  cull_mode  = CullMode::None;
    FrontFace::Enum front_face = FrontFace::CounterClockwise;
    FillMode::Enum  fill_mode  = FillMode::Solid;

    /////// Depth
    CompareOp::Enum depth_compare_op    = CompareOp::Less;
    bool            depth_test_enabled  = true;
    bool            depth_write_enabled = true;

    /////// Stencil
    bool                  stencil_test_enabled = false;
    StencilOperationState front;
    StencilOperationState back;

    /////// Blend States
    BlendState blend_states[MAX_COLOR_ATTACHMENTS];

    /////// Vertex Input
    VertexBufferBinding vertex_buffer_bindings[MAX_VERTEX_BINDINGS];

    /////// Render Pass Layout
    RenderPassLayout render_pass_layout;

    void reset() { *this = {}; }

    void set_vertex_buffer_binding(u8 binding, u16 byte_stride)
    {
        vertex_buffer_bindings[binding].byte_stride = byte_stride;
    }

    void set_vertex_buffer_attribute(u8 binding, u8 attribute, u16 byte_offset, Format::Enum format)
    {
        vertex_buffer_bindings[binding].attributes[attribute].byte_offset = byte_offset;
        vertex_buffer_bindings[binding].attributes[attribute].format      = format;
    }
};

struct TextureViewDesc {
    Handle<Texture>               texture;
    TextureViewType::Enum         view_type;
    TextureAspect::Flag           aspect_flags;
    Format::Enum                  format = Format::Undefined; // means use the format of the texture
    u8                            base_mip_level{ 0 };
    u8                            level_count{ 1 };
    u8                            base_array_layer{ 0 };
    u8                            layer_count{ 1 };
    TextureComponentSwizzle::Enum component_r{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_g{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_b{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_a{ TextureComponentSwizzle::Identity };
};

struct DescriptorBinding {
    DescriptorType::Enum type;
    u16                  index;
    u16                  count;
    const char*          name;
};

struct TextureBarrier {
    Handle<Texture>     texture;
    ImageLayout::Enum   old_layout;
    ImageLayout::Enum   new_layout;
    TextureAspect::Flag aspect_flags;
    AccessMask::Flag    src_access;
    AccessMask::Flag    dst_access;
    u32                 base_mip_level   = 0;
    u32                 level_count      = 1;
    u32                 base_array_layer = 0;
    u32                 layer_count      = 1;
};

struct RenderPassEncoder {
    Handle<CommandBuffer> cmd;
};

struct ComputePassEncoder {
    Handle<CommandBuffer> cmd;
};

} // namespace gfx
} // namespace clay