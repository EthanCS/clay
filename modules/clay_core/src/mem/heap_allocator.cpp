#include <mimalloc.h>
#include <clay_core/mem/allocator.h>

namespace clay
{
namespace core
{

HeapAllocator::~HeapAllocator() {}

void HeapAllocator::init(usize size)
{
    this->heap = mi_heap_new();
}

void HeapAllocator::shutdown()
{
    mi_heap_delete((mi_heap_t*)this->heap);
}

void* HeapAllocator::allocate(usize size, usize alignment)
{
    return mi_heap_malloc_aligned((mi_heap_t*)this->heap, size, alignment);
}

void* HeapAllocator::allocate(usize size, usize alignment, const char* file, i32 line)
{
    return mi_heap_malloc_aligned((mi_heap_t*)this->heap, size, alignment);
}

void HeapAllocator::deallocate(void* ptr)
{
    mi_free(ptr);
}

} // namespace core
} // namespace clay