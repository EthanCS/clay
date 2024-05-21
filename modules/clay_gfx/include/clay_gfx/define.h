#pragma once

namespace clay
{
namespace gfx
{

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