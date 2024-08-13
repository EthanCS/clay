#include <clay_core/dependency_graph.h>

#include <graaflib/graph.h>
#include <graaflib/types.h>
#include <optional>

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

    virtual DependencyGraphNodeID insert_node(DependencyGraphNode* node) CLAY_NOEXCEPT override
    {
        const DependencyGraphNodeID id = (DependencyGraphNodeID)graph.add_vertex(Vertex{ node });
        node->graph                    = this;
        node->id                       = id;
        return id;
    }

    virtual bool remove_node(DependencyGraphNodeID id) CLAY_NOEXCEPT override
    {
        if (graph.has_vertex((graaf::vertex_id_t)id)) [[likely]]
        {
            const auto& neighbors = graph.get_neighbors((graaf::vertex_id_t)id);
            for (const graaf::vertex_id_t& target_id : neighbors)
            {
                Edge& e = graph.get_edge((graaf::vertex_id_t)id, target_id);
                if (e.value != nullptr) [[likely]]
                {
                    e.value->on_disconnect();
                    e.value->from  = std::nullopt;
                    e.value->to    = std::nullopt;
                    e.value->graph = nullptr;
                }
            }

            Vertex& v = graph.get_vertex((graaf::vertex_id_t)id);
            if (v.value != nullptr) [[likely]]
            {
                v.value->on_remove();
                v.value->id    = std::nullopt;
                v.value->graph = nullptr;
            }

            graph.remove_vertex((graaf::vertex_id_t)id);
            return true;
        }
        return false;
    }

    virtual DependencyGraphNode* access_node(DependencyGraphNodeID id) CLAY_NOEXCEPT override
    {
        if (!graph.has_vertex((graaf::vertex_id_t)id)) [[unlikely]] { return nullptr; }
        return graph.get_vertex((graaf::vertex_id_t)id).value;
    }

    virtual bool connect_node(DependencyGraphNodeID from, DependencyGraphNodeID to, DependencyGraphEdge* edge) CLAY_NOEXCEPT override
    {
        graaf::vertex_id_t from_id = (graaf::vertex_id_t)from;
        graaf::vertex_id_t to_id   = (graaf::vertex_id_t)to;

        if (!graph.has_vertex(from_id) || !graph.has_vertex(to_id) || graph.has_edge(from_id, to_id)) [[unlikely]]
        {
            return false;
        }

        graph.add_edge(from_id, to_id, Edge{ edge });

        // Todo: Check if graph has cycle

        edge->from  = from;
        edge->to    = to;
        edge->graph = this;
        edge->on_connect();

        return true;
    }

    virtual bool disconnect_node(DependencyGraphNodeID from, DependencyGraphNodeID to) CLAY_NOEXCEPT override
    {
        graaf::vertex_id_t from_id = (graaf::vertex_id_t)from;
        graaf::vertex_id_t to_id   = (graaf::vertex_id_t)to;

        if (!graph.has_vertex(from_id) || !graph.has_vertex(to_id) || !graph.has_edge(from_id, to_id)) [[unlikely]]
        {
            return false;
        }

        Edge& e = graph.get_edge((graaf::vertex_id_t)from, (graaf::vertex_id_t)to);
        if (e.value != nullptr) [[likely]]
        {
            e.value->on_disconnect();
            e.value->from  = std::nullopt;
            e.value->to    = std::nullopt;
            e.value->graph = nullptr;
            return true;
        }

        return false;
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