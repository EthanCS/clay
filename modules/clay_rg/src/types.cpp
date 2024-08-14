#include <clay_rg/types.h>

namespace clay
{
namespace rg
{

RenderGraphNode::RenderGraphNode(ResourceType::Enum type)
    : node_type(type)
{
}

RenderGraphEdge::RenderGraphEdge(ActionType::Enum type)
    : action_type(type)
{
}

} // namespace rg
} // namespace clay