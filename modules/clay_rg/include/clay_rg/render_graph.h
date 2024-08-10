#pragma once

#include <clay_gfx/backend.h>
#include <functional>

namespace clay
{
namespace rg
{
static const u8 MAX_FRAME_IN_FLIGHT = 3;

class RenderGraph
{
public:
    using RenderGraphBuilderFunc = std::function<void(class RenderGraphBuilder&)>;
    static RenderGraph* create(const RenderGraphBuilderFunc& func) CLAY_NOEXCEPT;
    static void         destroy(RenderGraph* render_graph) CLAY_NOEXCEPT;

    inline u64 get_frame_index() const CLAY_NOEXCEPT { return frame_index; }

public:
    RenderGraph(const RenderGraphBuilder& builder) CLAY_NOEXCEPT;
    virtual ~RenderGraph() CLAY_NOEXCEPT = default;

    virtual void initialize() CLAY_NOEXCEPT;
    virtual void finalize() CLAY_NOEXCEPT;

    virtual bool compile() CLAY_NOEXCEPT;
    virtual void execute() CLAY_NOEXCEPT;

protected:
    u64 frame_index = 0;
};

} // namespace rg
} // namespace clay