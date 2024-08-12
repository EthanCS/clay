#include <clay_core/dag.h>
#include <CXXGraph/CXXGraph.hpp>

namespace clay
{
namespace core
{

class DAG_Impl : public DAG
{
    CXXGraph::Graph<DAG_Node*> graph;

    virtual DAG_NodeHandle insert(DAG_Node* node) CLAY_NOEXCEPT override
    {
        CXXGraph::Node<DAG_Node*> new_node("0", node);
        graph.addNode(make_shared<CXXGraph::Node<DAG_Node*>>(new_node));
        return new_node.getId();
    }

    virtual bool remove(const std::string& name) CLAY_NOEXCEPT override
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

    virtual DAG_Node* access_node(const std::string& name) CLAY_NOEXCEPT override
    {
        const auto& node = graph.getNode(name);
        return node.has_value() ? node.value()->getData() : nullptr;
    }
};

DAG* DAG::create() CLAY_NOEXCEPT
{
    return new DAG_Impl();
}

} // namespace core
} // namespace clay