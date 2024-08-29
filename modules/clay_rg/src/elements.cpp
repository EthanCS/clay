#include <clay_rg/elements.h>

namespace clay
{
namespace rg
{
PassNode::PassNode(PassType::Enum type, u32 order)
    : RenderGraphNode(ObjectType::Pass)
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

//////////////////////////////////////////////////////////////////////////
// ResourceNode

ResourceNode::ResourceNode(ObjectType::Enum type) CLAY_NOEXCEPT
    : RenderGraphNode(type)
{
}

//////////////////////////////////////////////////////////////////////////
// TextureNode

TextureNode::TextureNode() CLAY_NOEXCEPT
    : ResourceNode(ObjectType::Texture)
{
}

//////////////////////////////////////////////////////////////////////////
// BufferNode

BufferNode::BufferNode() CLAY_NOEXCEPT
    : ResourceNode(ObjectType::Buffer)
{
}

} // namespace rg
} // namespace clay