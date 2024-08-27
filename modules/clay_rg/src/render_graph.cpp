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

void RenderGraph::initialize() CLAY_NOEXCEPT
{
    graph   = core::DependencyGraph::create();
    factory = Factory::create();
}

void RenderGraph::finalize() CLAY_NOEXCEPT
{
    core::DependencyGraph::destroy(graph);
    Factory::destroy(factory);
}

PassHandle RenderGraph::add_render_pass(const RenderPassSetupFunc& setup, const OnRenderPassExecute& on_execute) CLAY_NOEXCEPT
{
    RenderPassNode* pass_node = factory->allocate<RenderPassNode>(pass_nodes.size());
    pass_nodes.push_back(pass_node);
    RenderPassBuilder builder(*this, *pass_node);
    setup(*this, builder);
    pass_node->on_execute = on_execute;
    return PassHandle(graph->insert_node(pass_node));
}

PassHandle RenderGraph::add_present_pass(const PresentPassSetupFunc& setup) CLAY_NOEXCEPT
{
    PresentPassNode* pass_node = factory->allocate<PresentPassNode>(pass_nodes.size());
    pass_nodes.push_back(pass_node);
    PresentPassBuilder builder(*this, *pass_node);
    setup(*this, builder);
    return PassHandle(graph->insert_node(pass_node));
}

} // namespace rg
} // namespace clay