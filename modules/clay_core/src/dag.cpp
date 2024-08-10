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

    virtual bool remove(DAG_NodeHandle handle) CLAY_NOEXCEPT override
    {
        return false;
    }

    virtual DAG_Node* access_node(DAG_NodeHandle handle) CLAY_NOEXCEPT override
    {
        return nullptr;
    }
};

DAG* DAG::create() CLAY_NOEXCEPT
{
    return new DAG_Impl();
}

} // namespace core
} // namespace clay