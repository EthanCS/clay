#pragma once

#include <clay_core/macro.h>

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
        return nullptr;
    }

protected:
    template <typename T>
    T* internal_alloc() CLAY_NOEXCEPT
    {
        return (T*)internal_alloc_impl(sizeof(T));
    }

    template <typename T>
    bool internal_free(T* obj) CLAY_NOEXCEPT
    {
        obj->~T();
        return internal_free_impl(obj, sizeof(T));
    }

    virtual bool  internal_free_impl(void* obj, usize size) CLAY_NOEXCEPT = 0;
    virtual void* internal_alloc_impl(usize size) CLAY_NOEXCEPT           = 0;
};
} // namespace rg
} // namespace clay