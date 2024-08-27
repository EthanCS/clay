#include <clay_rg/pass_node.h>

namespace clay
{
namespace rg
{
PassNode::PassNode(PassType::Enum type, u32 order)
    : RenderGraphNode(ResourceType::Pass)
    , pass_type(type)
    , order(order)
{
}

//////////////////////////////////////////////////////////////////////////
// RenderPassNode

RenderPassNode::RenderPassNode(u32 order)
    : PassNode(PassType::Render, order)
{
}

//////////////////////////////////////////////////////////////////////////
// PresentPassNode

PresentPassNode::PresentPassNode(u32 order)
    : PassNode(PassType::Present, order)
{
}

} // namespace rg
} // namespace clay