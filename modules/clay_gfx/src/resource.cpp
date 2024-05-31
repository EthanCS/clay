#define __IMPL_INVALID_HANDLE
#include <clay_gfx/resource.h>

#include <clay_gfx/define.h>

namespace clay
{
namespace gfx
{

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