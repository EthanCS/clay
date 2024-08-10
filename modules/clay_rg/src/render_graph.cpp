#include <clay_rg/render_graph.h>
#include <clay_rg/builder.h>

namespace clay
{
namespace rg
{
RenderGraph* RenderGraph::create(const RenderGraphBuilderFunc& func) CLAY_NOEXCEPT
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

void RenderGraph::initialize() CLAY_NOEXCEPT
{
}

void RenderGraph::finalize() CLAY_NOEXCEPT
{
}



} // namespace rg
} // namespace clay