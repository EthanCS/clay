#pragma once

#include <clay_gfx/define.h>
#include <clay_core/macro.h>
#include <optional>

#ifdef __IMPL_INVALID_HANDLE
    #define DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name) \
        const name##Handle name##Handle::Invalid = { u64_MAX };
#else
    #define DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name)
#endif

#define DEFINE_CLAY_GFX_RESOURCE_HANDLE(name)          \
    struct name##Handle {                              \
        u64                       id;                  \
        static const name##Handle Invalid;             \
                                                       \
        bool operator==(const name##Handle& rhs) const \
        {                                              \
            return id == rhs.id;                       \
        }                                              \
    };                                                 \
    DEFINE_CLAY_GFX_RESOURCE_INVALID_HANDLE(name)

namespace clay
{
namespace gfx
{
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Fence)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Semaphore)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Buffer)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Texture)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Sampler)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(ShaderState)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Pipeline)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(RenderPass)
DEFINE_CLAY_GFX_RESOURCE_HANDLE(Framebuffer)

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

struct ShaderStageDesc {
    ShaderStage::Flag stage;
    const char*       code        = nullptr;
    u32               code_size   = 0;
    const char*       entry_point = nullptr;
};

struct ShaderStateCreateDesc {
    const char*     name       = nullptr;
    u32             num_stages = 0;
    ShaderStageDesc stages[MAX_SHADER_STAGES];

    ShaderStateCreateDesc& reset();
    ShaderStateCreateDesc& set_name(const char* name);
    ShaderStateCreateDesc& add_stage(const ShaderStage::Flag& stage, const char* code, u32 code_size, const char* entry);
};

struct RenderPassOutput {
    u32                    num_colors = 0;
    Format::Enum           color_formats[MAX_COLOR_ATTACHMENTS];
    ImageLayout::Enum      color_layouts[MAX_COLOR_ATTACHMENTS];
    RenderPassLoadOp::Enum color_ops[MAX_COLOR_ATTACHMENTS];

    Format::Enum           depth_stencil_format;
    ImageLayout::Enum      depth_stencil_layout;
    RenderPassLoadOp::Enum depth_op   = RenderPassLoadOp::DontCare;
    RenderPassLoadOp::Enum stencil_op = RenderPassLoadOp::DontCare;

    RenderPassOutput& reset();
    RenderPassOutput& add_color(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum load_op);
    RenderPassOutput& set_depth(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum depth_op, RenderPassLoadOp::Enum stencil_op);
};

struct RasterizerState {
    CullMode::Enum  cull_mode  = CullMode::None;
    FrontFace::Enum front_face = FrontFace::CounterClockwise;
    FillMode::Enum  fill_mode  = FillMode::Solid;
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

struct BlendStates {
    BlendState blend_states[MAX_COLOR_ATTACHMENTS];
    u32        num_blend_states = 0;

    BlendStates& reset();
    BlendStates& add_blend_state(const BlendState& state);
};

struct GraphicsPipelineCreateDesc {
    RasterizerState rasterizer_state;
    BlendStates     blend_states;
};

} // namespace gfx
} // namespace clay