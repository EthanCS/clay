#include <clay_core/macro.h>
#include <clay_core/log.h>
#include <clay_rg/factory.h>
#include <unordered_map>
#include <queue>

namespace clay
{
namespace rg
{
struct FactoryPool {
    usize             size;
    std::queue<void*> blocks;

    FactoryPool(usize size) CLAY_NOEXCEPT
        : size(size)
    {
    }

    ~FactoryPool() CLAY_NOEXCEPT
    {
        while (!blocks.empty())
        {
            free(blocks.front());
            blocks.pop();
        }
    }

    void* allocate()
    {
        if (!blocks.empty())
        {
            void* block = blocks.front();
            blocks.pop();
            return block;
        }
        return malloc(size);
    }

    void deallocate(void* block)
    {
        blocks.push(block);
    }
};

struct FactoryImpl final : public Factory {
    FactoryImpl() CLAY_NOEXCEPT {}
    ~FactoryImpl() CLAY_NOEXCEPT override
    {
        for (auto& pool : pools)
        {
            delete pool.second;
        }
    }

    void* internal_allocate_impl(usize size) CLAY_NOEXCEPT override
    {
        auto pool = pools.find(size);
        if (pool == pools.end())
        {
            pool = pools.emplace(size, new FactoryPool(size)).first;
        }
        return pool->second->allocate();
    }

    bool internal_deallocate_impl(void* obj, usize size) CLAY_NOEXCEPT override
    {
        auto pool = pools.find(size);
        if (pool == pools.end())
        {
            CLAY_LOG_ERROR("Object size {} not found in factory pool", size);
            return false;
        }
        pool->second->deallocate(obj);
        return true;
    }

private:
    std::unordered_map<usize, FactoryPool*> pools;
};

Factory* Factory::create()
{
    return new FactoryImpl();
}

void Factory::destroy(Factory* factory)
{
    delete factory;
}

} // namespace rg
} // namespace clay