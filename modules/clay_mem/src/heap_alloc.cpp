#include <clay_mem/clay_mem.h>

namespace clay
{
namespace mem
{

HeapAllocator::~HeapAllocator() {}

void HeapAllocator::init(size_t size)
{
    this->heap = mi_heap_new();
}

void HeapAllocator::shutdown()
{
    mi_heap_delete(this->heap);
}

void* HeapAllocator::allocate(size_t size, size_t alignment)
{
    return mi_heap_malloc_aligned(this->heap, size, alignment);
}

void* HeapAllocator::allocate(size_t size, size_t alignment, const char* file, int32_t line)
{
    return mi_heap_malloc_aligned(this->heap, size, alignment);
}

void HeapAllocator::deallocate(void* ptr)
{
    mi_free(ptr);
}

} // namespace mem
} // namespace clay