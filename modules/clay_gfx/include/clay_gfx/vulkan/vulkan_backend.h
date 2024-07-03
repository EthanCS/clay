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

    VmaAllocator vma_allocator = VK_NULL_HANDLE;

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
    bool              init(const InitBackendOptions& desc);
    void              shutdown();
    BackendType::Enum get_type() noexcept { return BackendType::Vulkan; }

    void device_wait_idle() { vkDeviceWaitIdle(device); }

    void queue_wait_idle(QueueType::Enum queue_type)
    {
        VkQueue queue = get_queue(queue_type);
        if (queue != VK_NULL_HANDLE) [[likely]] { vkQueueWaitIdle(get_queue(queue_type)); }
    }
    void                  queue_submit(QueueType::Enum, const QueueSubmitOptions options);
    SwapchainStatus::Enum queue_present(const QueuePresentOptions& options);

    Handle<Swapchain>      create_swapchain(const CreateSwapchainOptions& desc);
    SwapchainAcquireResult acquire_next_image(const Handle<Swapchain>& swapchain, const AcquireNextImageOptions& options);
    u32                    get_swapchain_image_count(const Handle<Swapchain>& swapchain);
    Handle<Texture>        get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index);
    void                   destroy_swapchain(const Handle<Swapchain>& swapchain);

    Handle<Fence> create_fence(bool signal);
    void          wait_for_fence(const Handle<Fence>& fence, bool wait_all, u64 timeout);
    void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout);
    void          reset_fences(const Handle<Fence>* fences, int num_fence);
    void          destroy_fence(const Handle<Fence>& fence);

    Handle<Semaphore> create_semaphore();
    void              destroy_semaphore(const Handle<Semaphore>& semaphore);

    Handle<Shader> create_shader(const CreateShaderOptions& desc);
    void           destroy_shader(const Handle<Shader>& shader);

    Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc);
    void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline);

    u32  get_texture_width(const Handle<Texture>& texture);
    u32  get_texture_height(const Handle<Texture>& texture);
    void destroy_texture(const Handle<Texture>& texture);

    Handle<Buffer> create_buffer(const CreateBufferOptions& desc);
    void*          map_buffer(const Handle<Buffer>& buffer, u32 offset, u32 size);
    void           unmap_buffer(const Handle<Buffer>& buffer);
    void           destroy_buffer(const Handle<Buffer>& buffer);

    Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& desc);
    void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer);

    Handle<CommandPool> create_command_pool(QueueType::Enum queue_type);
    void                destroy_command_pool(const Handle<CommandPool>& pool);

    Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool);
    void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource);
    void                  free_command_buffer(const Handle<CommandBuffer>& buffer);

    void cmd_begin(const Handle<CommandBuffer>& cb);
    void cmd_end(const Handle<CommandBuffer>& cb);
    void cmd_begin_render_pass(const Handle<CommandBuffer>& cb, const CmdBeginRenderPassOptions& options);
    void cmd_end_render_pass(const Handle<CommandBuffer>& cb);
    void cmd_bind_graphics_pipeline(const Handle<CommandBuffer>& cb, const Handle<GraphicsPipeline>& pipeline);
    void cmd_set_viewport(const Handle<CommandBuffer>& cb, const CmdSetViewportOptions& viewport);
    void cmd_set_scissor(const Handle<CommandBuffer>& cb, const CmdSetScissorOptions& scissor);
    void cmd_draw(const Handle<CommandBuffer>& cb, const CmdDrawOptions& draw);
    void cmd_draw_indexed(const Handle<CommandBuffer>& cb, const CmdDrawIndexedOptions& draw);
    void cmd_bind_vertex_buffer(const Handle<CommandBuffer>& cb, const CmdBindVertexBufferOptions& options);
    void cmd_bind_vertex_buffers(const Handle<CommandBuffer>& cb, const CmdBindVertexBuffersOptions& options);
    void cmd_bind_index_buffer(const Handle<CommandBuffer>& cb, const CmdBindIndexBufferOptions& options);
    void cmd_copy_buffer(const Handle<CommandBuffer>& cb, const CmdCopyBufferOptions& options);

private:
    VkQueue get_queue(QueueType::Enum queue_type)
    {
        switch (queue_type)
        {
            case QueueType::Graphics:
                return graphics_queue.queue;
            case QueueType::Present:
                return present_queue.queue;
            case QueueType::Compute:
                return compute_queue.queue;
            case QueueType::Transfer:
                return transfer_queue.queue;
        }
        return VK_NULL_HANDLE;
    }
};
} // namespace gfx
} // namespace clay