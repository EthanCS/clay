#pragma once

#include <cstddef>
#include <cstdint>

#include <mimalloc.h>

namespace clay
{
namespace mem
{

struct Allocator {
    virtual ~Allocator() {}
    virtual void* allocate(size_t size, size_t alignment)                                 = 0;
    virtual void* allocate(size_t size, size_t alignment, const char* file, int32_t line) = 0;
    virtual void  deallocate(void* ptr)                                                   = 0;
};

struct HeapAllocator : public Allocator {
    ~HeapAllocator() override;

    void init(size_t size);
    void shutdown();

    void* allocate(size_t size, size_t alignment) override;
    void* allocate(size_t size, size_t alignment, const char* file, int32_t line) override;
    void  deallocate(void* ptr) override;

private:
    mi_heap_t* heap;
};

} // namespace mem
} // namespace clay