#pragma once

#include <clay_rg/types.h>
#include <clay_gfx/resource.h>

namespace clay
{
namespace rg
{

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
    OnRenderPassExecute                on_execute;
    gfx::Handle<gfx::GraphicsPipeline> pipeline;
    gfx::Handle<gfx::PipelineLayout>   layout;
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

} // namespace rg
} // namespace clay