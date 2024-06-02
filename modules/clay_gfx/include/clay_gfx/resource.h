#pragma once

#include <optional>
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
DEFINE_CLAY_GFX_RESOURCE_TAG(Fence)
DEFINE_CLAY_GFX_RESOURCE_TAG(Semaphore)
DEFINE_CLAY_GFX_RESOURCE_TAG(Buffer)
DEFINE_CLAY_GFX_RESOURCE_TAG(Texture)
DEFINE_CLAY_GFX_RESOURCE_TAG(Sampler)
DEFINE_CLAY_GFX_RESOURCE_TAG(Shader)
DEFINE_CLAY_GFX_RESOURCE_TAG(GraphicsPipeline)
DEFINE_CLAY_GFX_RESOURCE_TAG(ComputePipeline)
DEFINE_CLAY_GFX_RESOURCE_TAG(Framebuffer)

struct TextureViewDesc {
    std::optional<Format::Enum>   format;
    TextureViewType::Enum         view_type;
    TextureAspect::Flag           aspect_flags;
    u8                            base_mip_level{ 0 };
    u8                            level_count{ 1 };
    u8                            base_array_layer{ 0 };
    u8                            layer_count{ 1 };
    TextureComponentSwizzle::Enum component_r{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_g{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_b{ TextureComponentSwizzle::Identity };
    TextureComponentSwizzle::Enum component_a{ TextureComponentSwizzle::Identity };
};

struct ShaderCreateDesc {
    const char* code      = nullptr;
    u32         code_size = 0;
};

struct RenderPassLayout {
    u32                    num_colors = 0;
    Format::Enum           color_formats[MAX_COLOR_ATTACHMENTS];
    ImageLayout::Enum      color_layouts[MAX_COLOR_ATTACHMENTS];
    RenderPassLoadOp::Enum color_ops[MAX_COLOR_ATTACHMENTS];

    Format::Enum           depth_stencil_format;
    ImageLayout::Enum      depth_stencil_layout;
    RenderPassLoadOp::Enum depth_op   = RenderPassLoadOp::DontCare;
    RenderPassLoadOp::Enum stencil_op = RenderPassLoadOp::DontCare;

    RenderPassLayout& reset();
    RenderPassLayout& add_color(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum load_op);
    RenderPassLayout& set_depth(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum depth_op, RenderPassLoadOp::Enum stencil_op);
};

struct BlendState {
    BlendFactor::Enum src_color = BlendFactor::One;
    BlendFactor::Enum dst_color = BlendFactor::One;
    BlendOp::Enum     color_op  = BlendOp::Add;

    BlendFactor::Enum src_alpha = BlendFactor::One;
    BlendFactor::Enum dst_alpha = BlendFactor::One;
    BlendOp::Enum     alpha_op  = BlendOp::Add;

    ColorWriteEnabled::Flag color_write = ColorWriteEnabled::All;

    bool blend_enabled          = false;
    bool separate_blend_enabled = false;
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
    Handle<Shader> compiled_shader = Handle<Shader>();
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
};

struct GraphicsPipelineCreateDesc {
    const char* name = nullptr;

    ShaderInfo vertex_shader;
    ShaderInfo pixel_shader;

    GraphicsState graphics_state;
};

} // namespace gfx
} // namespace clay