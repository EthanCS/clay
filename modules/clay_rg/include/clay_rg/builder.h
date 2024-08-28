#pragma once

#include <clay_rg/elements.h>
#include <clay_gfx/backend.h>
#include <functional>

namespace clay
{
namespace rg
{

using RenderGraphSetupFunc = std::function<void(class RenderGraphBuilder&)>;
using RenderPassSetupFunc  = std::function<void(class RenderGraph&, class RenderPassBuilder&)>;
using PresentPassSetupFunc = std::function<void(class RenderGraph&, class PresentPassBuilder&)>;

class RenderGraphBuilder
{
public:
    RenderGraphBuilder& graphics_backend(gfx::BackendType type) CLAY_NOEXCEPT;

protected:
    gfx::BackendType gfx_backend_type;
};

class RenderPassBuilder
{
public:
    friend class RenderGraph;

    RenderPassBuilder& name(const char* name) CLAY_NOEXCEPT;
    RenderPassBuilder& pipeline(const gfx::Handle<gfx::GraphicsPipeline>& pipeline) CLAY_NOEXCEPT;
    RenderPassBuilder& layout(const gfx::Handle<gfx::PipelineLayout>& layout) CLAY_NOEXCEPT;

    RenderPassBuilder& color(u32 mrt_index, gfx::Handle<gfx::Texture> handle, gfx::LoadAction load, gfx::StoreAction store) CLAY_NOEXCEPT;
    RenderPassBuilder& depth_stencil(gfx::Handle<gfx::Texture> handle, gfx::LoadAction depth_load, gfx::StoreAction depth_store, gfx::LoadAction stencil_load, gfx::StoreAction stencil_store) CLAY_NOEXCEPT;

protected:
    RenderPassBuilder(RenderGraph& graph, RenderPassNode& node) CLAY_NOEXCEPT;
    RenderGraph&    graph;
    RenderPassNode& node;
};

class PresentPassBuilder
{
public:
    friend class RenderGraph;

    PresentPassBuilder& name(const char* name) CLAY_NOEXCEPT;
    PresentPassBuilder& swapchain(const gfx::Handle<gfx::Swapchain>& swapchain, u32 image_index) CLAY_NOEXCEPT;

protected:
    PresentPassBuilder(RenderGraph& graph, PresentPassNode& node) CLAY_NOEXCEPT;
    RenderGraph&     graph;
    PresentPassNode& node;
};

} // namespace rg
} // namespace clay