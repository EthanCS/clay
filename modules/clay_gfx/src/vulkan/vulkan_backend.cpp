#include <clay_gfx/vulkan/vulkan_backend.h>

namespace clay
{
namespace gfx
{

VulkanBackend::VulkanBackend(const RenderBackendCreateDesc& desc)
{
    VkApplicationInfo app_info  = {};
    app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName   = "Clay";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName        = "Clay";
    app_info.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    app_info.apiVersion         = VK_API_VERSION_1_0;

    VkInstanceCreateInfo create_info = {};
    create_info.sType                = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo     = &app_info;

    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
}

} // namespace gfx
} // namespace clay
