#include <clay_rg/pass_node.h>

namespace clay
{
namespace rg
{
PassNode::PassNode(PassType::Enum type)
    : RenderGraphNode(ResourceType::Pass)
    , pass_type(type)
{
}

//////////////////////////////////////////////////////////////////////////
// RenderPassNode

RenderPassNode::RenderPassNode()
    : PassNode(PassType::Render)
{
}

} // namespace rg
} // namespace clay