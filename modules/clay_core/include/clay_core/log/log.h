#pragma once

#include <clay_core/macro.h>
#include <spdlog/spdlog.h>

namespace clay
{
namespace core
{

} // namespace core
} // namespace clay

#define CLAY_ASSERT(x, fmt, ...) \
    do                           \
    {                            \
        if (!(x)) [[unlikely]]   \
        {                        \
            CLAY_DEBUG_BREAK     \
        }                        \
    } while (false)