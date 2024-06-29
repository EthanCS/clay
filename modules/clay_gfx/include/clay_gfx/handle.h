#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace gfx
{
template <typename T>
class Handle
{
private:
    u16 index;
    u16 generation;

public:
    bool operator==(const Handle<T>& other) const { return index == other.index && generation == other.generation; }
    bool operator!=(const Handle<T>& other) const { return index != other.index || generation != other.generation; }

    bool is_valid() const { return generation != 0; }
    u16  get_index() const { return index; }
    u32  hash() const { return ((u32)index << 16) + (u32)generation; }

    static Handle<T> invalid() noexcept { return {}; }

private:
    void set_index(u16 index) noexcept { this->index = index; }
    void set_generation(u16 generation) noexcept { this->generation = generation; }

    template <typename U, typename V>
    friend class Pool;
};
} // namespace gfx
} // namespace clay