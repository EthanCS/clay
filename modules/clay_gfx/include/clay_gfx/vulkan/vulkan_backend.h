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

struct VulkanFence {
    VkFence fence;
};

struct VulkanSemaphore {
    VkSemaphore semaphore;
};

class VulkanBackend final : public RenderBackend
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

    void device_wait_idle() override;

    void queue_wait_idle(QueueType::Enum queue_type) override;

    FenceHandle create_fence(bool signal) override;
    void        wait_for_fence(const FenceHandle& fence, bool wait_all, u64 timeout) override;
    void        wait_for_fences(const FenceHandle* fences, int num_fence, bool wait_all, u64 timeout) override;
    void        destroy_fence(const FenceHandle& fence) override;

    SemaphoreHandle create_semaphore() override;
    void            destroy_semaphore(const SemaphoreHandle& semaphore) override;
};
} // namespace gfx
} // namespace clay