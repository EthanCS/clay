#pragma once

#include <clay_gfx/resource.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_header.h>
#include <clay_gfx/vulkan/vulkan_resource.h>

namespace clay
{
namespace gfx
{
class VulkanBackend final : public RenderBackend
{
private:
    VulkanResourcePool res_pool;

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

    Handle<Fence> create_fence(bool signal) override;
    void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout) override;
    void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) override;
    void          destroy_fence(const Handle<Fence>& fence) override;

    Handle<Semaphore> create_semaphore() override;
    void              destroy_semaphore(const Handle<Semaphore>& semaphore) override;

    Handle<Shader> create_shader(const ShaderCreateDesc& desc) override;
    void           destroy_shader(const Handle<Shader>& shader) override;

    Handle<GraphicsPipeline> create_graphics_pipeline(const GraphicsPipelineCreateDesc& desc) override;
    void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline) override;

    void destroy_texture(const Handle<Texture>& texture) override;
};
} // namespace gfx
} // namespace clay