#include <clay_mem/clay_mem.h>
#include <mimalloc.h>

namespace clay
{
namespace mem
{

HeapAllocator::~HeapAllocator() {}

void* HeapAllocator::allocate(size_t size, size_t alignment)
{
    return nullptr;
}

void* HeapAllocator::allocate(size_t size, size_t alignment, const char* file, int32_t line)
{
    return allocate(size, alignment);
}

void HeapAllocator::deallocate(void* ptr)
{
    // free(ptr);
}

} // namespace mem
} // namespace clay