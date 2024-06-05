#pragma once

#include <clay_gfx/resource.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_header.h>
#include <clay_gfx/vulkan/vulkan_resource.h>

namespace clay
{
namespace gfx
{
class VulkanBackend
{
private:
    VulkanResources resources;

    VkInstance       instance        = VK_NULL_HANDLE;
    VkDevice         device          = VK_NULL_HANDLE;
    VkPhysicalDevice physical_device = VK_NULL_HANDLE;
    VkSurfaceKHR     surface         = VK_NULL_HANDLE;
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
    bool              init(const RenderBackendCreateDesc& desc);
    void              shutdown();
    BackendType::Enum get_type() noexcept { return BackendType::Vulkan; }

    void device_wait_idle() { vkDeviceWaitIdle(device); }

    void queue_wait_idle(QueueType::Enum queue_type);

    SwapchainAcquireResult acquire_next_image(u64 time_out, Handle<Semaphore> semaphore, Handle<Fence> fence);

    Handle<Fence> create_fence(bool signal);
    void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout);
    void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout);
    void          reset_fences(const Handle<Fence>* fences, int num_fence);
    void          destroy_fence(const Handle<Fence>& fence);

    Handle<Semaphore> create_semaphore();
    void              destroy_semaphore(const Handle<Semaphore>& semaphore);

    Handle<Shader> create_shader(const ShaderCreateDesc& desc);
    void           destroy_shader(const Handle<Shader>& shader);

    Handle<GraphicsPipeline> create_graphics_pipeline(const GraphicsPipelineCreateDesc& desc);
    void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline);

    void destroy_texture(const Handle<Texture>& texture);

    Handle<Framebuffer> create_framebuffer(const FramebufferCreateDesc& desc);
    void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer);

    Handle<CommandPool> create_command_pool(QueueType::Enum queue_type);
    void                destroy_command_pool(const Handle<CommandPool>& pool);

    Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool);
    void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource);
    void                  free_command_buffer(const Handle<CommandBuffer>& buffer);

    void cmd_begin(const Handle<CommandBuffer>& buffer);
    void cmd_end(const Handle<CommandBuffer>& buffer);
    void cmd_begin_render_pass(const Handle<CommandBuffer>& buffer, const CmdBeginRenderPassOptions& options);
    void cmd_end_render_pass(const Handle<CommandBuffer>& buffer);
    void cmd_bind_graphics_pipeline(const Handle<CommandBuffer>& buffer, const Handle<GraphicsPipeline>& pipeline);
    void cmd_set_viewport(const Handle<CommandBuffer>& buffer, const CmdSetViewportOptions& viewport);
    void cmd_set_scissor(const Handle<CommandBuffer>& buffer, const CmdSetScissorOptions& scissor);
    void cmd_draw(const Handle<CommandBuffer>& buffer, const CmdDrawOptions& draw);
};
} // namespace gfx
} // namespace clay