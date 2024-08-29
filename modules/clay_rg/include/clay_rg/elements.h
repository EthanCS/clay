#pragma once

#include <clay_rg/types.h>
#include <clay_gfx/resource.h>

namespace clay
{
namespace rg
{

//////////////////////////////////////////////////////////////////////////
// Pass Nodes
//////////////////////////////////////////////////////////////////////////

class PassNode : public RenderGraphNode
{
public:
    const PassType::Enum pass_type;
    const u32            order;

    bool before(const PassNode* other) const { return order < other->order; }
    bool after(const PassNode* other) const { return order > other->order; }

protected:
    PassNode(PassType::Enum type, u32 order);
};

class RenderPassNode : public PassNode
{
public:
    friend class RenderGraph;
    friend class RenderPassBuilder;

    RenderPassNode(u32 order);

protected:
    OnRenderPassExecute on_execute;

    gfx::Handle<gfx::GraphicsPipeline> pipeline;
    gfx::Handle<gfx::PipelineLayout>   layout;

    gfx::LoadAction  color_loads[gfx::MAX_COLOR_ATTACHMENTS];
    gfx::StoreAction color_stores[gfx::MAX_COLOR_ATTACHMENTS];
    gfx::LoadAction  depth_load;
    gfx::StoreAction depth_store;
    gfx::LoadAction  stencil_load;
    gfx::StoreAction stencil_store;
};

class PresentPassNode : public PassNode
{
public:
    friend class PresentPassBuilder;

    PresentPassNode(u32 order);

protected:
    gfx::Handle<gfx::Swapchain> swapchain;
    u32                         image_index;
};

//////////////////////////////////////////////////////////////////////////
// Resource Nodes
//////////////////////////////////////////////////////////////////////////

class ResourceNode : public RenderGraphNode
{
public:
    ResourceNode(ResourceType::Enum type) CLAY_NOEXCEPT;
    virtual ~ResourceNode() CLAY_NOEXCEPT = default;
};

class TextureNode : public ResourceNode
{
public:
    TextureNode() CLAY_NOEXCEPT;
    inline const gfx::TextureDescriptor& get_descriptor() const CLAY_NOEXCEPT { return descriptor; }

protected:
    gfx::TextureDescriptor descriptor = {};
};

class BufferNode : public ResourceNode
{
public:
    BufferNode() CLAY_NOEXCEPT;
    inline const gfx::BufferDescriptor& get_descriptor() const CLAY_NOEXCEPT { return descriptor; }

protected:
    gfx::BufferDescriptor descriptor = {};
};

//////////////////////////////////////////////////////////////////////////
// Resource Edges
//////////////////////////////////////////////////////////////////////////

class TextureEdge : public RenderGraphEdge
{
public:
    TextureEdge(ActionType::Enum action, gfx::TextureUsage usage) CLAY_NOEXCEPT;
    virtual ~TextureEdge() CLAY_NOEXCEPT                           = default;
    virtual TextureNode*    get_texture_node() const CLAY_NOEXCEPT = 0;
    virtual PassNode*       get_pass_node() const CLAY_NOEXCEPT    = 0;
    const gfx::TextureUsage texture_usage;
};

class TextureReadOnlyEdge : public TextureEdge
{
};

class TextureReadWriteEdge : public TextureEdge
{
};

class TextureRenderEdge : public TextureEdge
{
public:
    TextureRenderEdge(u32 attachment_index, gfx::TextureUsage usage) CLAY_NOEXCEPT;
};

class BufferEdge : public RenderGraphEdge
{
};

class BufferReadOnlyEdge : public BufferEdge
{
};

class BufferReadWriteEdge : public BufferEdge
{
};

} // namespace rg
} // namespace clay