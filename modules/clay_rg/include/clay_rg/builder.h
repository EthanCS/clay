#pragma once

#include <clay_gfx/backend.h>
#include <clay_rg/pass_node.h>

namespace clay
{
namespace rg
{

class RenderGraphBuilder
{
public:
    RenderGraphBuilder& graphics_backend(gfx::BackendType type) CLAY_NOEXCEPT;

protected:
    gfx::BackendType gfx_backend_type;
};

class RenderPassBuilder
{
public:
    friend class RenderGraph;

    RenderPassBuilder& name(const char* name) CLAY_NOEXCEPT;
    RenderPassBuilder& pipeline(const gfx::Handle<gfx::GraphicsPipeline>& pipeline) CLAY_NOEXCEPT;
    RenderPassBuilder& layout(const gfx::Handle<gfx::PipelineLayout>& layout) CLAY_NOEXCEPT;

protected:
    RenderPassBuilder(RenderGraph& graph, RenderPassNode& node) CLAY_NOEXCEPT;
    RenderGraph&    graph;
    RenderPassNode& node;
};

} // namespace rg
} // namespace clay