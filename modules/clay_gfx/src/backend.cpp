#include <clay_core/log.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_backend.h>

namespace clay
{
namespace gfx
{

IRenderBackend* create_render_backend(const InitBackendOptions& desc)
{
    switch (desc.type)
    {
        case BackendType::Vulkan: {
            VulkanBackend* backend = new VulkanBackend();
            if (backend->initialize(desc)) { return backend; }
            else
            {
                delete backend;
                return nullptr;
            }
            break;
        }
        default:
            return nullptr;
    }

    return nullptr;
}

void destroy_render_backend(IRenderBackend* backend)
{
    if (backend)
    {
        backend->finalize();
        delete backend;
    }
}

} // namespace gfx
} // namespace clay