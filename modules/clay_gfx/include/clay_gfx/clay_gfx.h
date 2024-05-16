#pragma once

namespace clay
{
namespace gfx
{

struct BackendType {
    enum Enum
    {
        Vulkan,
        Count
    };
};

struct Init {
    BackendType::Enum type;
    bool              debug{ false };
};

bool init(const Init& desc);
void shutdown();

} // namespace gfx
} // namespace clay