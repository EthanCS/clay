#include <clay_core/dependency_graph.h>

#include <graaflib/graph.h>
#include <graaflib/types.h>

namespace clay
{
namespace core
{

class DependencyGraphImpl : public DependencyGraph
{
    struct Vertex {
        DependencyGraphNode* value;
    };

    struct Edge {
        DependencyGraphEdge* value;
    };

    graaf::directed_graph<Vertex, Edge> graph;

    virtual DependencyGraphNodeID insert(DependencyGraphNode* node) CLAY_NOEXCEPT override
    {
        const auto id = (DependencyGraphNodeID)graph.add_vertex(Vertex{ node });
        node->graph   = this;
        node->handle  = id;
        return id;
    }

    virtual bool remove(DependencyGraphNodeID id) CLAY_NOEXCEPT override
    {
        // const auto& node = graph.getNode(name);
        // if (node.has_value())
        // {
        //     DAG_Node* data = node.value()->getData();
        //     if (data == nullptr) { return false; }

        //     data->on_remove();
        //     graph.removeNode(name);
        //     return true;
        // }
        return false;
    }

    virtual DependencyGraphNode* access_node(DependencyGraphNodeID id) CLAY_NOEXCEPT override
    {
        if (!graph.has_vertex((graaf::vertex_id_t)id)) { return nullptr; }
        return graph.get_vertex((graaf::vertex_id_t)id).value;
    }
};

DependencyGraph* DependencyGraph::create() CLAY_NOEXCEPT
{
    return new DependencyGraphImpl();
}

void DependencyGraph::destroy(DependencyGraph* graph) CLAY_NOEXCEPT
{
    delete (DependencyGraphImpl*)graph;
}

} // namespace core
} // namespace clay