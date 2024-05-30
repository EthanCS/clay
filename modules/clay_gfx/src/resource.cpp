#define __IMPL_INVALID_HANDLE
#include <clay_gfx/resource.h>

#include <clay_gfx/define.h>

namespace clay
{
namespace gfx
{
ShaderStateCreateDesc& ShaderStateCreateDesc::reset()
{
    this->num_stages = 0;
    return *this;
}

ShaderStateCreateDesc& ShaderStateCreateDesc::set_name(const char* name)
{
    this->name = name;
    return *this;
}

ShaderStateCreateDesc& ShaderStateCreateDesc::add_stage(const ShaderStage::Flag& stage_, const char* code_, u32 code_size_, const char* entry_point_)
{
    // Replace stage if it already exists
    for (u32 s = 0; s < num_stages; ++s)
    {
        if (stages[s].stage == stage_)
        {
            stages[s].stage       = stage_;
            stages[s].code        = code_;
            stages[s].code_size   = code_size_;
            stages[s].entry_point = entry_point_;
            return *this;
        }
    }

    stages[num_stages].stage       = stage_;
    stages[num_stages].code        = code_;
    stages[num_stages].code_size   = code_size_;
    stages[num_stages].entry_point = entry_point_;
    ++num_stages;
    return *this;
}

RenderPassLayout& RenderPassLayout::reset()
{
    num_colors = 0;
    for (u32 i = 0; i < MAX_COLOR_ATTACHMENTS; ++i)
    {
        color_formats[i] = Format::Undefined;
        color_layouts[i] = ImageLayout::Undefined;
        color_ops[i]     = RenderPassLoadOp::DontCare;
    }
    depth_stencil_format = Format::Undefined;
    depth_op             = RenderPassLoadOp::DontCare;
    stencil_op           = RenderPassLoadOp::DontCare;
    return *this;
}

RenderPassLayout& RenderPassLayout::add_color(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum load_op)
{
    color_formats[num_colors] = format;
    color_layouts[num_colors] = layout;
    color_ops[num_colors]     = load_op;
    ++num_colors;
    return *this;
}

RenderPassLayout& RenderPassLayout::set_depth(Format::Enum format, ImageLayout::Enum layout, RenderPassLoadOp::Enum depth_op, RenderPassLoadOp::Enum stencil_op)
{
    depth_stencil_format = format;
    depth_stencil_layout = layout;
    this->depth_op       = depth_op;
    this->stencil_op     = stencil_op;
    return *this;
}

} // namespace gfx
} // namespace clay