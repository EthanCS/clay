#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_swapchain.h>

#include <flecs.h>

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
    flecs::world world;

    VkInstance       instance;
    VkDevice         device;
    VkPhysicalDevice physical_device;
    VkSurfaceKHR     surface;
    VulkanSwapchain  swapchain;

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
    VulkanBackend(BackendType::Enum type);
    virtual ~VulkanBackend() override;

    bool init(const RenderBackendCreateDesc& desc) override;
};
} // namespace gfx
} // namespace clay