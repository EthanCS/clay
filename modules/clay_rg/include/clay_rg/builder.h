#pragma once

#include <clay_gfx/backend.h>

namespace clay
{
namespace rg
{
class RenderGraphBuilder
{
public:
    RenderGraphBuilder& graphics_backend(gfx::BackendType type) CLAY_NOEXCEPT;

protected:
    gfx::BackendType gfx_backend_type;
};
} // namespace rg
} // namespace clay