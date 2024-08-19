#pragma once

#include <clay_core/macro.h>
#include <utility>

namespace clay
{
namespace rg
{
struct Factory {
    virtual ~Factory() CLAY_NOEXCEPT = default;
    static Factory* create();
    static void     destroy(Factory* factory);

    template <typename T, typename... Args>
    T* allocate(Args&&... args) CLAY_NOEXCEPT
    {
        if (auto allocated = internal_alloc<T>())
        {
            new (allocated) T(std::forward<Args>(args)...);
            return allocated;
        }
        return new T(std::forward<Args>(args)...);
    }

    template <typename T>
    void deallocate(T* obj) CLAY_NOEXCEPT
    {
        if (internal_deallocate<T>(obj)) return;
        delete obj;
    }

protected:
    template <typename T>
    T* internal_alloc() CLAY_NOEXCEPT
    {
        return (T*)internal_alloc_impl(sizeof(T));
    }

    template <typename T>
    bool internal_deallocate(T* obj) CLAY_NOEXCEPT
    {
        obj->~T();
        return internal_free_impl(obj, sizeof(T));
    }

    virtual bool  internal_deallocate_impl(void* obj, usize size) CLAY_NOEXCEPT = 0;
    virtual void* internal_allocate_impl(usize size) CLAY_NOEXCEPT              = 0;
};
} // namespace rg
} // namespace clay