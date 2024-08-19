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

protected:
    PassNode(PassType::Enum type);
};

class RenderPassNode : public PassNode
{
public:
    friend class RenderGraph;
    friend class RenderPassBuilder;
    RenderPassNode();

protected:
    OnRenderPassExecute                on_execute;
    gfx::Handle<gfx::GraphicsPipeline> pipeline;
    gfx::Handle<gfx::PipelineLayout>   layout;
};
} // namespace rg
} // namespace clay