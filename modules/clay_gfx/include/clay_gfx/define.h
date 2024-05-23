#pragma once

namespace clay
{
namespace gfx
{
struct RenderBackendType {
    enum Enum
    {
        Vulkan,
        DirectX12,
        Metal,
        Count
    };
};

struct QueueType {
    enum Enum
    {
        Graphics,
        Present,
        Compute,
        Transfer,
    };
};
} // namespace gfx
} // namespace clay