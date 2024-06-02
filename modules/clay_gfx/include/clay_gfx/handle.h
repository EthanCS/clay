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
    Handle()
        : index(0)
        , generation(0)
    {
    }

    bool operator==(const Handle<T>& other) const { return index == other.index && generation == other.generation; }
    bool operator!=(const Handle<T>& other) const { return index != other.index || generation != other.generation; }

    bool is_valid() const { return generation != 0; }
    u16  get_index() const { return index; }
    u32  hash() const { return ((u32)index << 16) + (u32)generation; }

private:
    Handle(u16 _index, u16 _generation)
        : index(_index)
        , generation(_generation)
    {
    }

    template <typename U, typename V>
    friend class Pool;
};
} // namespace gfx
} // namespace clay