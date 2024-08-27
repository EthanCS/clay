#include <clay_rg/builder.h>

namespace clay
{
namespace rg
{

//////////////////////////////////////////////////////////////////////////
// RenderGraphBuilder

RenderGraphBuilder& RenderGraphBuilder::graphics_backend(gfx::BackendType type) CLAY_NOEXCEPT
{
    gfx_backend_type = type;
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// RenderPassBuilder

RenderPassBuilder::RenderPassBuilder(RenderGraph& graph, RenderPassNode& pass) CLAY_NOEXCEPT
    : graph(graph),
      node(pass)
{
}

RenderPassBuilder& RenderPassBuilder::name(const char* name) CLAY_NOEXCEPT
{
    node.name = name;
    return *this;
}

RenderPassBuilder& RenderPassBuilder::pipeline(const gfx::Handle<gfx::GraphicsPipeline>& pipeline) CLAY_NOEXCEPT
{
    node.pipeline = pipeline;
    return *this;
}

RenderPassBuilder& RenderPassBuilder::layout(const gfx::Handle<gfx::PipelineLayout>& layout) CLAY_NOEXCEPT
{
    node.layout = layout;
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// PresentPassBuilder

PresentPassBuilder::PresentPassBuilder(RenderGraph& graph, PresentPassNode& pass) CLAY_NOEXCEPT
    : graph(graph),
      node(pass)
{
}

PresentPassBuilder& PresentPassBuilder::name(const char* name) CLAY_NOEXCEPT
{
    node.name = name;
    return *this;
}

PresentPassBuilder& PresentPassBuilder::swapchain(const gfx::Handle<gfx::Swapchain>& swapchain, u32 image_index) CLAY_NOEXCEPT
{
    node.swapchain   = swapchain;
    node.image_index = image_index;
    return *this;
}

} // namespace rg
} // namespace clay