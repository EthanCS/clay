#pragma once

#include <vector>

#include <clay_core/macro.h>
#include <clay_core/log.h>
#include <clay_gfx/handle.h>

namespace clay
{
namespace gfx
{
template <typename TTag, typename TObject>
class Pool
{
private:
    std::vector<TObject> objects;
    std::vector<u16>     generations;
    std::vector<u16>     free_indices;

public:
    Pool(usize capacity = 32) { grow(capacity); }

    usize capacity() const { return objects.size(); }
    usize size() const { return objects.size() - free_indices.size(); }
    bool  is_handle_valid(const Handle<TTag>& handle) const { return handle.is_valid() && handle.get_index() < objects.size() && generations[handle.get_index()] == handle.generation; }

    void clear()
    {
        objects.clear();
        generations.clear();
        free_indices.clear();
    }

    Handle<TTag> push(const TObject& object)
    {
        if (free_indices.empty()) [[unlikely]] { grow(capacity() > 32 ? capacity() : 32); }

        u16 index = free_indices.back();
        free_indices.pop_back();
        objects[index] = object;

        Handle<TTag> handle = {};
        handle.set_index(index);
        handle.set_generation(generations[index]);
        return handle;
    }

    std::tuple<Handle<TTag>, TObject*> malloc()
    {
        if (free_indices.empty()) [[unlikely]] { grow(capacity() > 32 ? capacity() : 32); }

        u16 index = free_indices.back();
        free_indices.pop_back();

        Handle<TTag> handle = {};
        handle.set_index(index);
        handle.set_generation(generations[index]);

        return { handle, &objects[index] };
    }

    void free(const Handle<TTag>& handle)
    {
        if (is_handle_valid(handle)) [[likely]]
        {
            generations[handle.get_index()]++;
            free_indices.push_back(handle.get_index());
        }
    }

    const TObject* get(const Handle<TTag>& handle) const
    {
        if (!is_handle_valid(handle)) [[unlikely]] { return nullptr; }
        return &objects[handle.get_index()];
    }

    TObject* get_mut(const Handle<TTag>& handle)
    {
        if (!is_handle_valid(handle)) [[unlikely]] { return nullptr; }
        return &objects[handle.get_index()];
    }

    void each(std::function<void(TObject&)> func)
    {
        for (usize i = 0; i < objects.size(); ++i)
        {
            auto f = std::find(free_indices.begin(), free_indices.end(), i);
            if (f == free_indices.end())
            {
                func(objects[i]);
            }
        }
    }

private:
    void grow(usize additional)
    {
        usize old_capacity = capacity();
        usize new_capacity = old_capacity + additional;

        CLAY_ASSERT(new_capacity <= u16_MAX, "Pool capacity exceeded u16 limit.");

        objects.resize(new_capacity);

        generations.resize(new_capacity);
        for (usize i = old_capacity; i < new_capacity; ++i)
        {
            generations[i] = 1;
        }

        free_indices.resize(additional);
        for (usize i = 0; i < additional; ++i)
        {
            free_indices[i] = new_capacity - i - 1;
        }
    }
};
} // namespace gfx
} // namespace clay