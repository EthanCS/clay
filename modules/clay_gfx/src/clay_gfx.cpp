#include <clay_gfx/clay_gfx.h>
#include <clay_gfx/vulkan/vulkan_backend.h>

namespace clay
{
namespace gfx
{

bool init(const RenderBackendCreateDesc& desc)
{
    switch (desc.type)
    {
        case RenderBackendType::Vulkan:
            s_backend = new VulkanBackend(desc);
            break;
    }
    return true;
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