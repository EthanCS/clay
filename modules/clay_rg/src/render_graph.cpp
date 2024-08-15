#include <clay_rg/render_graph.h>
#include <clay_rg/builder.h>

namespace clay
{
namespace rg
{
RenderGraph* RenderGraph::create(const RenderGraphSetupFunc& func) CLAY_NOEXCEPT
{
    RenderGraphBuilder builder = {};
    func(builder);
    RenderGraph* render_graph = new RenderGraph(builder);
    render_graph->initialize();
    return render_graph;
}

void RenderGraph::destroy(RenderGraph* render_graph) CLAY_NOEXCEPT
{
    if (render_graph)
    {
        render_graph->finalize();
        delete render_graph;
    }
}

// PassHandle RenderGraph::add_render_pass(const RenderPassSetupFunc& setup, const OnRenderPassExecute& on_execute) CLAY_NOEXCEPT
// {
//     RenderPassNode    pass = {};
//     RenderPassBuilder builder(*this, pass);
//     setup(*this, builder);
// }

void RenderGraph::initialize() CLAY_NOEXCEPT
{
    graph = core::DependencyGraph::create();
}

void RenderGraph::finalize() CLAY_NOEXCEPT
{
    core::DependencyGraph::destroy(graph);
}

} // namespace rg
} // namespace clay