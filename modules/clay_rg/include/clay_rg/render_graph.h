#pragma once

#include <clay_rg/types.h>
#include <clay_rg/factory.h>
#include <clay_rg/builder.h>
#include <clay_gfx/backend.h>
#include <clay_core/dependency_graph.h>

namespace clay
{
namespace rg
{
static const u8 MAX_FRAME_IN_FLIGHT = 3;

class RenderGraphFrameExecutor
{
public:
    gfx::Handle<gfx::CommandPool>   cmd_pool;
    gfx::Handle<gfx::CommandBuffer> cmd_buffer;
    gfx::Handle<gfx::Fence>         fence;

    RenderGraphFrameExecutor() = default;
    void initialize(gfx::IRenderBackend* backend, const gfx::Handle<gfx::Queue>& queue);
    void finalize();

    void reset_begin();
    void end();
};

class RenderGraph
{
public:
    static RenderGraph* create(const RenderGraphSetupFunc& setup) CLAY_NOEXCEPT;
    static void         destroy(RenderGraph* render_graph) CLAY_NOEXCEPT;

public:
    RenderGraph(const RenderGraphBuilder& builder) CLAY_NOEXCEPT;
    virtual ~RenderGraph() CLAY_NOEXCEPT = default;

    virtual void initialize() CLAY_NOEXCEPT;
    virtual void finalize() CLAY_NOEXCEPT;

    inline u64 get_frame_number() const CLAY_NOEXCEPT { return frame_number; }

    virtual bool compile() CLAY_NOEXCEPT;
    virtual u64  execute() CLAY_NOEXCEPT;

    PassHandle add_render_pass(const RenderPassSetupFunc& setup, const OnRenderPassExecute& on_execute) CLAY_NOEXCEPT;
    PassHandle add_present_pass(const PresentPassSetupFunc& setup) CLAY_NOEXCEPT;

protected:
    u64                    frame_number = 0;
    core::DependencyGraph* graph        = nullptr;
    Factory*               factory      = nullptr;
    std::vector<PassNode*> pass_nodes;

    RenderGraphFrameExecutor frame_executors[MAX_FRAME_IN_FLIGHT];
};

} // namespace rg
} // namespace clay