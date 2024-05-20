#pragma once

#include <clay_core/macro.h>
#include <mimalloc.h>

namespace clay
{
namespace core
{

struct Allocator {
    virtual ~Allocator() {}
    virtual void* allocate(usize size, usize alignment)                             = 0;
    virtual void* allocate(usize size, usize alignment, const char* file, i32 line) = 0;
    virtual void  deallocate(void* ptr)                                             = 0;
};

struct HeapAllocator : public Allocator {
    ~HeapAllocator() override;

    void init(usize size);
    void shutdown();

    void* allocate(usize size, usize alignment) override;
    void* allocate(usize size, usize alignment, const char* file, i32 line) override;
    void  deallocate(void* ptr) override;

private:
    mi_heap_t* heap;
};

} // namespace core
} // namespace clay