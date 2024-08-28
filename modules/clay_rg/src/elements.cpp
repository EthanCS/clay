#include <clay_rg/elements.h>

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

//////////////////////////////////////////////////////////////////////////
// ResourceNode

ResourceNode::ResourceNode(ResourceType::Enum type) CLAY_NOEXCEPT
    : RenderGraphNode(type)
{
}

//////////////////////////////////////////////////////////////////////////
// TextureNode

TextureNode::TextureNode() CLAY_NOEXCEPT
    : ResourceNode(ResourceType::Texture)
{
}

//////////////////////////////////////////////////////////////////////////
// BufferNode

BufferNode::BufferNode() CLAY_NOEXCEPT
    : ResourceNode(ResourceType::Buffer)
{
}

} // namespace rg
} // namespace clay