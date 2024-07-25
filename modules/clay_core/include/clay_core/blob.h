#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace core
{
struct IBlob {
    virtual u8* get_data() const noexcept = 0;
    virtual u64 get_size() const noexcept = 0;
    virtual ~IBlob() noexcept             = default;
};
} // namespace core
} // namespace clay