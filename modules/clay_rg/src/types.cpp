#include <clay_rg/types.h>

namespace clay
{
namespace rg
{
RenderGraphNode::RenderGraphNode(ObjectType::Enum type)
    : node_type(type)
{
}

RenderGraphEdge::RenderGraphEdge(ActionType::Enum type)
    : action_type(type)
{
}
} // namespace rg
} // namespace clay