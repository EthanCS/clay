#include <clay_rg/builder.h>

namespace clay
{
namespace rg
{
    
//////////////////////////////////////////////////////////////////////////
// RenderGraphBuilder

RenderGraphBuilder& RenderGraphBuilder::graphics_backend(gfx::BackendType type) CLAY_NOEXCEPT
{
    gfx_backend_type = type;
    return *this;
}

} // namespace rg
} // namespace clay