#pragma once

#include <clay_gfx/clay_gfx.h>

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

namespace clay
{
namespace gfx
{

struct VulkanQueue {
    VkQueue queue;
    u32     family_index;
};

class VulkanBackend : public RenderBackend
{
private:
    VkInstance instance;
    VkDevice   device;

    VulkanQueue graphics_queue;
    VulkanQueue present_queue;
    VulkanQueue compute_queue;
    VulkanQueue transfer_queue;

    bool                             debug_utils_enabled;
    VkDebugUtilsMessengerEXT         debug_utils_messenger;
    PFN_vkSetDebugUtilsObjectNameEXT pfn_SetDebugUtilsObjectNameEXT;
    PFN_vkCmdBeginDebugUtilsLabelEXT pfn_CmdBeginDebugUtilsLabelEXT;
    PFN_vkCmdEndDebugUtilsLabelEXT   pfn_CmdEndDebugUtilsLabelEXT;

public:
    VulkanBackend(const RenderBackendCreateDesc& desc);
    virtual ~VulkanBackend() override;
};

} // namespace gfx
} // namespace clay