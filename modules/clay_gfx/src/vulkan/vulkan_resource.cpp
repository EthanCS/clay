#include "clay_gfx/resource.h"
#define NOMINMAX

#include <vector>
#include <algorithm>

#include <clay_core/log.h>
#include <clay_core/macro.h>

#include <clay_gfx/vulkan/vulkan_resource.h>
#include <clay_gfx/vulkan/vulkan_utils.h>

namespace clay
{
namespace gfx
{
VkImageView VulkanTexture::get_view(const VkDevice& device, VulkanTextureViewDesc desc)
{
    if (desc.format == VK_FORMAT_UNDEFINED) { desc.format = format; }

    auto it = std::find(view_descs.begin(), view_descs.end(), desc);
    if (it != view_descs.end())
    {
        return views[it - view_descs.begin()];
    }

    VkImageViewCreateInfo view_create_info           = {};
    view_create_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_create_info.image                           = image;
    view_create_info.viewType                        = desc.view_type;
    view_create_info.format                          = desc.format;
    view_create_info.components.r                    = desc.component_r;
    view_create_info.components.g                    = desc.component_g;
    view_create_info.components.b                    = desc.component_b;
    view_create_info.components.a                    = desc.component_a;
    view_create_info.subresourceRange.aspectMask     = desc.aspect_flags;
    view_create_info.subresourceRange.baseMipLevel   = desc.base_mip_level;
    view_create_info.subresourceRange.levelCount     = desc.level_count;
    view_create_info.subresourceRange.baseArrayLayer = desc.base_array_layer;
    view_create_info.subresourceRange.layerCount     = desc.layer_count;

    VkImageView view;
    if (vkCreateImageView(device, &view_create_info, nullptr, &view) != VK_SUCCESS)
    {
        CLAY_LOG_ERROR("Failed to create image view!");
        return VK_NULL_HANDLE;
    }

    view_descs.push_back(desc);
    views.push_back(view);

    return view;
}

bool VulkanRenderPass::is_compatible(const RenderPassLayout& layout) const
{
    u8 num_colors       = output.num_colors();
    u8 other_num_colors = layout.num_colors();
    if (num_colors != other_num_colors) { return false; }

    for (u32 i = 0; i < num_colors; i++)
    {
        ColorAttachmentDesc output_color = output.colors[i];
        ColorAttachmentDesc other_color  = layout.colors[i];
        if (output_color != other_color) { return false; }
    }

    return output.depth_stencil == layout.depth_stencil;
}

VkPipelineShaderStageCreateInfo to_shader_stage_create_info(const VulkanResources* resources, const ShaderInfo& shader_info, VkShaderStageFlagBits stage_flag)
{
    VkPipelineShaderStageCreateInfo shader_stage_info = {};

    const VulkanShader* shader = resources->shaders.get(shader_info.compiled_shader);
    if (shader == nullptr) [[unlikely]] { return shader_stage_info; }

    shader_stage_info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    shader_stage_info.stage  = stage_flag;
    shader_stage_info.module = shader->shader_module;
    shader_stage_info.pName  = shader_info.entry_func;

    return shader_stage_info;
}

bool VulkanGraphicsPipeline::init(VulkanResources* resources, const VkDevice& device, const GraphicsPipelineCreateDesc& desc)
{
    if (resources == nullptr) { return false; }

    //// Render Pass
    VkRenderPass render_pass = resources->get_or_create_render_pass(device, desc.graphics_state.render_pass_layout);
    if (render_pass == VK_NULL_HANDLE) [[unlikely]] { return false; }

    //// Vertex buffer bindings
    VkVertexInputBindingDescription   vertex_bindings[MAX_VERTEX_BINDINGS];
    VkVertexInputAttributeDescription vertex_attributes[MAX_VERTEX_ATTRIBUTES];

    usize num_vertex_bindings   = 0;
    usize num_vertex_attributes = 0;

    for (usize i = 0; i < MAX_VERTEX_BINDINGS; i++)
    {
        const auto& binding = desc.graphics_state.vertex_buffer_bindings[i];
        if (binding.byte_stride == u16_MAX) { break; }

        vertex_bindings[num_vertex_bindings].binding   = i;
        vertex_bindings[num_vertex_bindings].stride    = binding.byte_stride;
        vertex_bindings[num_vertex_bindings].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        for (usize j = 0; j < MAX_VERTEX_ATTRIBUTES; j++)
        {
            const auto& attribute = binding.attributes[j];
            if (attribute.byte_offset == u16_MAX) { break; }

            vertex_attributes[num_vertex_attributes].binding  = i;
            vertex_attributes[num_vertex_attributes].location = j;
            vertex_attributes[num_vertex_attributes].format   = to_vk_format(attribute.format);
            vertex_attributes[num_vertex_attributes].offset   = attribute.byte_offset;

            num_vertex_attributes++;
        }

        num_vertex_bindings++;
    }

    VkPipelineVertexInputStateCreateInfo vertex_input_state = {};
    vertex_input_state.sType                                = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_state.pVertexBindingDescriptions           = vertex_bindings;
    vertex_input_state.vertexBindingDescriptionCount        = num_vertex_bindings;
    vertex_input_state.pVertexAttributeDescriptions         = vertex_attributes;
    vertex_input_state.vertexAttributeDescriptionCount      = num_vertex_attributes;

    //// Shader Stages
    u8                              num_stages = 0;
    VkPipelineShaderStageCreateInfo shader_stages[MAX_SHADER_STAGES];
    if (desc.vertex_shader.is_valid()) { shader_stages[num_stages++] = to_shader_stage_create_info(resources, desc.vertex_shader, VK_SHADER_STAGE_VERTEX_BIT); }
    if (desc.pixel_shader.is_valid()) { shader_stages[num_stages++] = to_shader_stage_create_info(resources, desc.pixel_shader, VK_SHADER_STAGE_FRAGMENT_BIT); }

    //// Depth Stencil State
    VkPipelineDepthStencilStateCreateInfo depth_stencil = {};
    depth_stencil.sType                                 = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    depth_stencil.depthTestEnable                       = desc.graphics_state.depth_test_enabled ? VK_TRUE : VK_FALSE;
    depth_stencil.depthWriteEnable                      = desc.graphics_state.depth_write_enabled ? VK_TRUE : VK_FALSE;
    depth_stencil.depthCompareOp                        = to_vk_compare_op(desc.graphics_state.depth_compare_op);
    depth_stencil.stencilTestEnable                     = desc.graphics_state.stencil_test_enabled ? VK_TRUE : VK_FALSE;

    //// Rasterizer
    VkPipelineRasterizationStateCreateInfo rasterizer = {};
    rasterizer.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterizer.depthClampEnable                       = VK_FALSE;
    rasterizer.rasterizerDiscardEnable                = VK_FALSE;
    rasterizer.polygonMode                            = to_vk_polygon_mode(desc.graphics_state.fill_mode);
    rasterizer.lineWidth                              = 1.0f;
    rasterizer.cullMode                               = to_vk_cull_mode(desc.graphics_state.cull_mode);
    rasterizer.frontFace                              = to_vk_front_face(desc.graphics_state.front_face);
    rasterizer.depthBiasEnable                        = VK_FALSE;
    rasterizer.depthBiasConstantFactor                = 0.0f; // Optional
    rasterizer.depthBiasClamp                         = 0.0f; // Optional
    rasterizer.depthBiasSlopeFactor                   = 0.0f; // Optional

    //// Input Assembly
    VkPipelineInputAssemblyStateCreateInfo input_assembly = {};
    input_assembly.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly.topology                               = to_vk_primitive_topology(desc.graphics_state.primitive_topology);
    input_assembly.primitiveRestartEnable                 = VK_FALSE;

    //// Color Blend State
    VkPipelineColorBlendAttachmentState color_blend_attachments[MAX_COLOR_ATTACHMENTS];
    u8                                  num_color = desc.graphics_state.render_pass_layout.num_colors();
    for (usize i = 0; i < num_color; i++)
    {
        const BlendState& blend_state                  = desc.graphics_state.blend_states[i];
        color_blend_attachments[i].colorWriteMask      = to_vk_color_component_flags(blend_state.color_write);
        color_blend_attachments[i].blendEnable         = blend_state.blend_enabled ? VK_TRUE : VK_FALSE;
        color_blend_attachments[i].srcColorBlendFactor = to_vk_blend_factor(blend_state.src_color);
        color_blend_attachments[i].dstColorBlendFactor = to_vk_blend_factor(blend_state.dst_color);
        color_blend_attachments[i].colorBlendOp        = to_vk_blend_op(blend_state.color_op);
        color_blend_attachments[i].srcAlphaBlendFactor = to_vk_blend_factor(blend_state.src_alpha);
        color_blend_attachments[i].dstAlphaBlendFactor = to_vk_blend_factor(blend_state.dst_alpha);
        color_blend_attachments[i].alphaBlendOp        = to_vk_blend_op(blend_state.alpha_op);
    }

    VkPipelineColorBlendStateCreateInfo color_blending = {};
    color_blending.sType                               = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    color_blending.logicOpEnable                       = VK_FALSE;
    color_blending.logicOp                             = VK_LOGIC_OP_COPY;
    color_blending.attachmentCount                     = num_color;
    color_blending.pAttachments                        = color_blend_attachments;

    //// Multi Sample State
    VkPipelineMultisampleStateCreateInfo multisampling = {};
    multisampling.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable                  = VK_FALSE;
    multisampling.rasterizationSamples                 = VK_SAMPLE_COUNT_1_BIT;

    //// Viewport State
    VkPipelineViewportStateCreateInfo viewport = {};
    viewport.sType                             = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport.viewportCount                     = 1;
    viewport.scissorCount                      = 1;

    //// Dynamic State
    VkDynamicState dynamic_states[] = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

    VkPipelineDynamicStateCreateInfo dynamic_state = {};
    dynamic_state.sType                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_state.dynamicStateCount                = 2;
    dynamic_state.pDynamicStates                   = dynamic_states;

    //// Dummy pipeline layout
    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pSetLayouts                = nullptr;
    pipeline_layout_info.pushConstantRangeCount     = 0;
    pipeline_layout_info.pPushConstantRanges        = nullptr;

    VkPipelineLayout pipeline_layout;
    {
        VkResult res = vkCreatePipelineLayout(device, &pipeline_layout_info, nullptr, &pipeline_layout);
        if (res != VK_SUCCESS) [[unlikely]]
        {
            CLAY_LOG_ERROR("Failed to create pipeline layout! ({})", string_VkResult(res));
            return false;
        }
        resources->pipeline_layouts.push({ .pipeline_layout = pipeline_layout });
    }

    //// Create Pipeline
    VkGraphicsPipelineCreateInfo create_info = {};
    create_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    create_info.stageCount                   = num_stages;
    create_info.pStages                      = shader_stages;
    create_info.pVertexInputState            = &vertex_input_state;
    create_info.pInputAssemblyState          = &input_assembly;
    create_info.pViewportState               = &viewport;
    create_info.pRasterizationState          = &rasterizer;
    create_info.pMultisampleState            = &multisampling;
    create_info.pDepthStencilState           = &depth_stencil;
    create_info.pColorBlendState             = &color_blending;
    create_info.pDynamicState                = &dynamic_state;
    create_info.layout                       = pipeline_layout;
    create_info.renderPass                   = render_pass;
    create_info.subpass                      = 0;
    create_info.basePipelineHandle           = VK_NULL_HANDLE;
    create_info.basePipelineIndex            = -1;

    VkResult res = vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &create_info, nullptr, &pipeline);
    if (res != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create graphics pipeline! ({})", string_VkResult(res));
        return false;
    }

    return true;
}

VkRenderPass VulkanResources::get_or_create_render_pass(const VkDevice& device, const RenderPassLayout& layout)
{
    for (const auto& pass : render_passes)
    {
        if (pass.is_compatible(layout))
        {
            return pass.render_pass;
        }
    }

    usize num_colors      = layout.num_colors();
    usize depth_index     = num_colors;
    usize num_attachments = num_colors + (layout.has_depth_stencil() ? 1 : 0);

    VkAttachmentDescription attachments[MAX_ATTACHMENTS];
    for (usize i = 0; i < num_colors; i++)
    {
        attachments[i]                = {};
        attachments[i].format         = to_vk_format(layout.colors[i].format);
        attachments[i].samples        = VK_SAMPLE_COUNT_1_BIT;
        attachments[i].loadOp         = to_vk_attachment_load_op(layout.colors[i].load_op);
        attachments[i].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
        attachments[i].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attachments[i].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        attachments[i].initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
        attachments[i].finalLayout    = to_vk_image_layout(layout.colors[i].layout);
    }

    if (layout.has_depth_stencil())
    {
        VkAttachmentDescription depth_attachment = {};
        depth_attachment.format                  = to_vk_format(layout.depth_stencil.format);
        depth_attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
        depth_attachment.loadOp                  = to_vk_attachment_load_op(layout.depth_stencil.depth_op);
        depth_attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
        depth_attachment.stencilLoadOp           = to_vk_attachment_load_op(layout.depth_stencil.stencil_op);
        depth_attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_STORE;
        depth_attachment.initialLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
        depth_attachment.finalLayout             = to_vk_image_layout(layout.depth_stencil.layout);

        attachments[depth_index] = depth_attachment;
    }

    VkAttachmentReference color_attachment_refs[MAX_COLOR_ATTACHMENTS];
    for (usize i = 0; i < num_colors; i++)
    {
        color_attachment_refs[i]            = {};
        color_attachment_refs[i].attachment = i;
        color_attachment_refs[i].layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }

    VkAttachmentReference depth_attachment_ref = {};
    if (layout.has_depth_stencil())
    {
        depth_attachment_ref.attachment = depth_index;
        depth_attachment_ref.layout     = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    }

    VkSubpassDescription subpass    = {};
    subpass.pipelineBindPoint       = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount    = num_colors;
    subpass.pColorAttachments       = color_attachment_refs;
    subpass.pDepthStencilAttachment = layout.has_depth_stencil() ? &depth_attachment_ref : nullptr;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount        = num_attachments;
    render_pass_info.pAttachments           = attachments;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;
    render_pass_info.dependencyCount        = 0;
    render_pass_info.pDependencies          = nullptr;

    VkRenderPass render_pass;
    VkResult     res = vkCreateRenderPass(device, &render_pass_info, nullptr, &render_pass);
    if (res != VK_SUCCESS) [[unlikely]]
    {
        CLAY_LOG_ERROR("Failed to create render pass! ({})", string_VkResult(res));
        return VK_NULL_HANDLE;
    }

    render_passes.push_back({ .render_pass = render_pass, .output = layout });
    return render_pass;
}

void VulkanResources::destroy(const VkDevice& device)
{
    swapchains.each([&](VulkanSwapchain& s) {
        for (const Handle<Texture>& image : s.images)
        {
            const VulkanTexture* texture = textures.get(image);
            if (texture != nullptr)
            {
                for (const VkImageView& view : texture->views)
                {
                    vkDestroyImageView(device, view, nullptr);
                }
            }
            textures.free(image);
        }
        vkDestroySwapchainKHR(device, s.swapchain, nullptr);
    });

    fences.each([&](VulkanFence& f) { vkDestroyFence(device, f.fence, nullptr); });
    semaphores.each([&](VulkanSemaphore& s) { vkDestroySemaphore(device, s.semaphore, nullptr); });
    textures.each([&](VulkanTexture& t) { t.destroy(device); });
    shaders.each([&](VulkanShader& s) { vkDestroyShaderModule(device, s.shader_module, nullptr); });
    pipeline_layouts.each([&](VulkanPipelineLayout& p) { vkDestroyPipelineLayout(device, p.pipeline_layout, nullptr); });
    graphics_pipelines.each([&](VulkanGraphicsPipeline& p) { vkDestroyPipeline(device, p.pipeline, nullptr); });
    command_pools.each([&](VulkanCommandPool& p) { vkDestroyCommandPool(device, p.command_pool, nullptr); });
    framebuffers.each([&](VulkanFramebuffer& f) { vkDestroyFramebuffer(device, f.framebuffer, nullptr); });
    buffers.each([&](VulkanBuffer& b) { vkDestroyBuffer(device, b.buffer, nullptr); });

    std::for_each(render_passes.begin(), render_passes.end(), [&](VulkanRenderPass& r) {
        vkDestroyRenderPass(device, r.render_pass, nullptr);
    });

    fences.clear();
    semaphores.clear();
    shaders.clear();
    textures.clear();
    pipeline_layouts.clear();
    graphics_pipelines.clear();
    command_pools.clear();
    command_buffers.clear();
    framebuffers.clear();
    buffers.clear();

    render_passes.clear();
}

} // namespace gfx
} // namespace clay