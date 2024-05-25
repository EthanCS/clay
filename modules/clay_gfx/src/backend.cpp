#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_backend.h>

namespace clay
{
namespace gfx
{
bool init(const RenderBackendCreateDesc& desc)
{
    switch (desc.type)
    {
        case BackendType::Vulkan:
            s_backend = new VulkanBackend(desc.type);
            break;
    }

    if (s_backend != nullptr)
    {
        return s_backend->init(desc);
    }

    return false;
}

RenderBackend* backend()
{
    return s_backend;
}

void shutdown()
{
    if (s_backend != nullptr)
    {
        delete s_backend;
        s_backend = nullptr;
    }
}
} // namespace gfx
} // namespace clay