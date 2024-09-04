#pragma once

#include <clay_gfx/resource.h>
#include <clay_gfx/backend.h>
#include <clay_gfx/vulkan/vulkan_header.h>
#include <clay_gfx/vulkan/vulkan_resource.h>

namespace clay
{
namespace gfx
{

static const u32 MAX_GLOBAL_POOL_ELEMENTS = 128;

class VulkanBackend final : public IRenderBackend
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

    VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;

    bool                             debug_utils_enabled;
    VkDebugUtilsMessengerEXT         debug_utils_messenger;
    PFN_vkSetDebugUtilsObjectNameEXT pfn_SetDebugUtilsObjectNameEXT;
    PFN_vkCmdBeginDebugUtilsLabelEXT pfn_CmdBeginDebugUtilsLabelEXT;
    PFN_vkCmdEndDebugUtilsLabelEXT   pfn_CmdEndDebugUtilsLabelEXT;

public:
    bool init(const InitBackendOptions& desc);
    void shutdown();

    void              initialize(const InitBackendOptions& options) override;
    void              finalize() override;
    BackendType::Enum get_type() const CLAY_NOEXCEPT override { return BackendType::Vulkan; }

    void device_wait_idle() override { vkDeviceWaitIdle(device); }

    Handle<Queue>         get_queue(const QueueType::Enum& queue_type) override;
    void                  queue_wait_idle(const Handle<Queue>& queue) override;
    void                  queue_submit(const Handle<Queue>& queue, const QueueSubmitOptions& options) override;
    SwapchainStatus::Enum queue_present(const Handle<Queue>& queue, const QueuePresentOptions& options) override;

    Handle<Swapchain>      create_swapchain(const CreateSwapchainOptions& desc) override;
    SwapchainAcquireResult acquire_next_image(const Handle<Swapchain>& swapchain, const AcquireNextImageOptions& options) override;
    u32                    get_swapchain_image_count(const Handle<Swapchain>& swapchain) override;
    Handle<Texture>        get_swapchain_back_buffer(const Handle<Swapchain>& swapchain, u32 index) override;
    void                   destroy_swapchain(const Handle<Swapchain>& swapchain) override;

    Handle<Fence> create_fence(bool signal) override;
    void          wait_for_fences(const Handle<Fence>* fences, int num_fence, bool wait_all, u64 timeout) override;
    void          reset_fences(const Handle<Fence>* fences, int num_fence) override;
    void          destroy_fence(const Handle<Fence>& fence) override;

    Handle<Semaphore> create_semaphore() override;
    void              destroy_semaphore(const Handle<Semaphore>& semaphore) override;

    Handle<Shader> create_shader(const CreateShaderOptions& desc) override;
    void           destroy_shader(const Handle<Shader>& shader) override;

    Handle<PipelineLayout> create_pipeline_layout(const CreatePipelineLayoutOptions& desc) override;
    void                   destroy_pipeline_layout(const Handle<PipelineLayout>& layout) override;

    Handle<GraphicsPipeline> create_graphics_pipeline(const CreateGraphicsPipelineOptions& desc) override;
    void                     destroy_graphics_pipeline(const Handle<GraphicsPipeline>& pipeline) override;

    Handle<Texture>   create_texture(const CreateTextureOptions& desc) override;
    TextureDescriptor get_texture_descriptor(const Handle<Texture>& texture) override;
    void              destroy_texture(const Handle<Texture>& texture) override;

    Handle<Sampler> create_sampler(const CreateSamplerOptions& desc) override;
    void            destroy_sampler(const Handle<Sampler>& sampler) override;

    Handle<Buffer> create_buffer(const CreateBufferOptions& desc) override;
    void*          map_buffer(const Handle<Buffer>& buffer) override;
    void           unmap_buffer(const Handle<Buffer>& buffer) override;
    void           destroy_buffer(const Handle<Buffer>& buffer) override;

    Handle<Framebuffer> create_framebuffer(const CreateFramebufferOptions& desc) override;
    void                destroy_framebuffer(const Handle<Framebuffer>& framebuffer) override;

    Handle<DescriptorSetLayout> create_descriptor_set_layout(const CreateDescriptorSetLayoutOptions& desc) override;
    void                        destroy_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout) override;

    Handle<DescriptorSet> create_descriptor_set(const CreateDescriptorSetOptions& desc) override;
    void                  update_descriptor_set(const Handle<DescriptorSet>& set, const UpdateDescriptorSetOptions& desc) override;
    void                  destroy_descriptor_set(const Handle<DescriptorSet>& set) override;

    Handle<CommandPool> create_command_pool(const Handle<Queue>& queue) override;
    void                destroy_command_pool(const Handle<CommandPool>& pool) override;

    Handle<CommandBuffer> allocate_command_buffer(const Handle<CommandPool>& pool, bool primary) override;
    void                  reset_command_buffer(const Handle<CommandBuffer>& buffer, bool release_resource) override;
    void                  free_command_buffer(const Handle<CommandBuffer>& buffer) override;

    void cmd_begin(const Handle<CommandBuffer>& cb, bool one_time) override;
    void cmd_copy_buffer(const Handle<CommandBuffer>& cb, const CmdCopyBufferOptions& options) override;
    void cmd_copy_buffer_to_texture(const Handle<CommandBuffer>& cb, const CmdCopyBufferToTextureOptions& options) override;
    void cmd_pipeline_barrier(const Handle<CommandBuffer>& cb, const CmdPipelineBarrierOptions& options) override;
    void cmd_end(const Handle<CommandBuffer>& cb) override;

    RenderPassEncoder cmd_begin_render_pass(const Handle<CommandBuffer>& cb, const CmdBeginRenderPassOptions& options) override;
    void              cmd_bind_pipeline(const RenderPassEncoder& encoder, const Handle<GraphicsPipeline>& pipeline) override;
    void              cmd_set_viewport(const RenderPassEncoder& encoder, const CmdSetViewportOptions& viewport) override;
    void              cmd_set_scissor(const RenderPassEncoder& encoder, const CmdSetScissorOptions& scissor) override;
    void              cmd_draw(const RenderPassEncoder& encoder, const CmdDrawOptions& draw) override;
    void              cmd_draw_indexed(const RenderPassEncoder& encoder, const CmdDrawIndexedOptions& draw) override;
    void              cmd_bind_vertex_buffer(const RenderPassEncoder& encoder, const CmdBindVertexBufferOptions& options) override;
    void              cmd_bind_vertex_buffers(const RenderPassEncoder& encoder, const CmdBindVertexBuffersOptions& options) override;
    void              cmd_bind_index_buffer(const RenderPassEncoder& encoder, const CmdBindIndexBufferOptions& options) override;
    void              cmd_bind_descriptor_sets(const RenderPassEncoder& encoder, const CmdBindDescriptorSetsOptions& options) override;
    void              cmd_end_render_pass(const Handle<CommandBuffer>& cb, const RenderPassEncoder& encoder) override;
};
} // namespace gfx
} // namespace clay