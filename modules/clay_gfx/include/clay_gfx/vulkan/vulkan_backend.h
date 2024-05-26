#pragma once

#include <clay_gfx/vulkan/vulkan_header.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_resource.h>

#include <flecs.h>

namespace clay
{
namespace gfx
{
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

    ShaderStateHandle create_shader_state(const ShaderStateCreateDesc& desc) override;
    void              destroy_shader_state(const ShaderStateHandle& state) override;

    void destroy_texture(const TextureHandle& texture) override;
};
} // namespace gfx
} // namespace clay