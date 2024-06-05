#include <clay_core/log.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_backend.h>

namespace clay
{
namespace gfx
{
pro::proxy<spec::IRenderBackend> g_backend_proxy;

bool init(const InitBackendOptions& desc)
{
    if (g_backend_proxy.has_value())
    {
        CLAY_LOG_WARNING("Backend already initialized");
        return true;
    }

    switch (desc.type)
    {
        case BackendType::Vulkan: {
            VulkanBackend backend;
            if (!backend.init(desc)) { return false; }
            g_backend_proxy = pro::make_proxy<spec::IRenderBackend>(backend);
            break;
        }
        default:
            return false;
    }

    return g_backend_proxy.has_value();
}

void shutdown()
{
    if (g_backend_proxy.has_value())
    {
        g_backend_proxy.shutdown();
        g_backend_proxy.reset();
    }
}

} // namespace gfx
} // namespace clay