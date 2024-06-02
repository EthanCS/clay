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
VulkanSwapchain::VulkanSwapchain() noexcept
    : swapchain(VK_NULL_HANDLE)
    , image_count(0)
    , images{ Handle<Texture>(), Handle<Texture>(), Handle<Texture>() }
{
}

bool VulkanSwapchain::init(VulkanResourcePool* res_pool, VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height, Format::Enum format, bool vsync)
{
    u32 format_count;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, nullptr);
    std::vector<VkSurfaceFormatKHR> formats = std::vector<VkSurfaceFormatKHR>(format_count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface, &format_count, formats.data());

    VkSurfaceFormatKHR surface_format = VkSurfaceFormatKHR{ .format = VK_FORMAT_B8G8R8A8_UNORM, .colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };
    for (const auto& f : formats)
    {
        if (f.format == to_vk_format(format))
        {
            surface_format = f;
            break;
        }
    }

    VkSurfaceCapabilitiesKHR surface_capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &surface_capabilities);

    VkSurfaceTransformFlagBitsKHR pre_transform = surface_capabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR ? VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR : surface_capabilities.currentTransform;

    u32 desired_image_count = std::max(MAX_SWAPCHAIN_IMAGES, (u8)surface_capabilities.minImageCount);
    if (surface_capabilities.maxImageCount != 0)
    {
        desired_image_count = std::min(desired_image_count, surface_capabilities.maxImageCount);
    }

    VkExtent2D extent = surface_capabilities.currentExtent;
    if (surface_capabilities.currentExtent.width == u32_MAX)
    {
        extent.width  = width;
        extent.height = height;
    }

    std::vector<VkPresentModeKHR> present_mode_preference;
    if (vsync)
    {
        present_mode_preference.push_back(VK_PRESENT_MODE_FIFO_RELAXED_KHR);
        present_mode_preference.push_back(VK_PRESENT_MODE_FIFO_KHR);
    }
    else
    {
        present_mode_preference.push_back(VK_PRESENT_MODE_MAILBOX_KHR);
        present_mode_preference.push_back(VK_PRESENT_MODE_IMMEDIATE_KHR);
    }

    u32 present_mode_count;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, nullptr);
    std::vector<VkPresentModeKHR> present_modes = std::vector<VkPresentModeKHR>(present_mode_count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, &present_mode_count, present_modes.data());

    VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
    for (const auto& p : present_mode_preference)
    {
        if (std::find(present_modes.begin(), present_modes.end(), p) != present_modes.end())
        {
            present_mode = p;
            break;
        }
    }

    VkSwapchainCreateInfoKHR create_info = {};
    create_info.sType                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    create_info.imageUsage               = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.imageSharingMode         = VK_SHARING_MODE_EXCLUSIVE;
    create_info.clipped                  = VK_TRUE;
    create_info.imageArrayLayers         = 1;
    create_info.compositeAlpha           = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    create_info.surface                  = surface;
    create_info.imageFormat              = surface_format.format;
    create_info.imageColorSpace          = surface_format.colorSpace;
    create_info.imageExtent              = extent;
    create_info.minImageCount            = desired_image_count;
    create_info.preTransform             = pre_transform;
    create_info.presentMode              = present_mode;
    create_info.oldSwapchain             = VK_NULL_HANDLE;

    VkResult result = vkCreateSwapchainKHR(device, &create_info, nullptr, &swapchain);
    CLAY_ASSERT(result == VK_SUCCESS, "Failed to create swapchain! ({})", string_VkResult(result));

    // Fetch swapchain images and create image views
    image_count = 0;
    {
        vkGetSwapchainImagesKHR(device, swapchain, &image_count, nullptr);
        std::vector<VkImage> swapchain_images = std::vector<VkImage>(image_count);
        vkGetSwapchainImagesKHR(device, swapchain, &image_count, swapchain_images.data());

        for (int i = 0; i < image_count; i++)
        {
            VulkanTexture texture{ .image = swapchain_images[i] };
            images[i] = res_pool->textures.push(texture);
        }
    }

    return true;
}

VkImageView VulkanTexture::get_view(const VkDevice& device, const VulkanTextureViewDesc& desc)
{
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

VkPipelineShaderStageCreateInfo to_shader_stage_create_info(const VulkanResourcePool* res_pool, const ShaderInfo& shader_info, VkShaderStageFlagBits stage_flag)
{
    VkPipelineShaderStageCreateInfo shader_stage_info = {};

    const VulkanShader* shader = res_pool->shaders.get(shader_info.compiled_shader);
    if (shader == nullptr) [[unlikely]] { return shader_stage_info; }

    shader_stage_info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    shader_stage_info.stage  = stage_flag;
    shader_stage_info.module = shader->shader_module;
    shader_stage_info.pName  = shader_info.entry_func;

    return shader_stage_info;
}

void VulkanGraphicsPipeline::init(VulkanResourcePool* res_pool, const VkDevice& device, const GraphicsPipelineCreateDesc& desc)
{
    if (res_pool == nullptr) { return; }

    //// Render Pass
    VkRenderPass render_pass = VK_NULL_HANDLE;
    {
    }

    //// Shader Stages
    u8                              num_stages = 0;
    VkPipelineShaderStageCreateInfo shader_stages[MAX_SHADER_STAGES];
    if (desc.vertex_shader.is_valid()) { shader_stages[num_stages++] = to_shader_stage_create_info(res_pool, desc.vertex_shader, VK_SHADER_STAGE_VERTEX_BIT); }
    if (desc.pixel_shader.is_valid()) { shader_stages[num_stages++] = to_shader_stage_create_info(res_pool, desc.pixel_shader, VK_SHADER_STAGE_FRAGMENT_BIT); }

    //// Depth Stencil State
    VkPipelineDepthStencilStateCreateInfo depth_stencil = {};
    depth_stencil.sType                                 = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    depth_stencil.depthTestEnable                       = desc.graphics_state.depth_test_enabled ? VK_TRUE : VK_FALSE;
    depth_stencil.depthWriteEnable                      = desc.graphics_state.depth_write_enabled ? VK_TRUE : VK_FALSE;
    depth_stencil.depthCompareOp                        = to_vk_compare_op(desc.graphics_state.depth_compare_op);
    depth_stencil.stencilTestEnable                     = desc.graphics_state.stencil_test_enabled ? VK_TRUE : VK_FALSE;

    //// Rasterizer
    VkPipelineRasterizationStateCreateInfo rasterizer{ VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO };
    rasterizer.depthClampEnable        = VK_FALSE;
    rasterizer.rasterizerDiscardEnable = VK_FALSE;
    rasterizer.polygonMode             = to_vk_polygon_mode(desc.graphics_state.fill_mode);
    rasterizer.lineWidth               = 1.0f;
    rasterizer.cullMode                = to_vk_cull_mode(desc.graphics_state.cull_mode);
    rasterizer.frontFace               = to_vk_front_face(desc.graphics_state.front_face);
    rasterizer.depthBiasEnable         = VK_FALSE;
    rasterizer.depthBiasConstantFactor = 0.0f; // Optional
    rasterizer.depthBiasClamp          = 0.0f; // Optional
    rasterizer.depthBiasSlopeFactor    = 0.0f; // Optional

    //// Input Assembly
    VkPipelineInputAssemblyStateCreateInfo input_assembly = {};
    input_assembly.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly.topology                               = to_vk_primitive_topology(desc.graphics_state.primitive_topology);
    input_assembly.primitiveRestartEnable                 = VK_FALSE;

    VkGraphicsPipelineCreateInfo create_info = {};
    create_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    create_info.stageCount                   = num_stages;
    create_info.pStages                      = shader_stages;
    create_info.pVertexInputState            = nullptr;
    create_info.pInputAssemblyState          = &input_assembly;
    create_info.pViewportState               = nullptr;
    create_info.pRasterizationState          = &rasterizer;
    create_info.pMultisampleState            = nullptr;
    create_info.pDepthStencilState           = &depth_stencil;
    create_info.pColorBlendState             = nullptr;
    create_info.pDynamicState                = nullptr;
    create_info.layout                       = VK_NULL_HANDLE;
    create_info.renderPass                   = render_pass;
    create_info.subpass                      = 0;
    create_info.basePipelineHandle           = VK_NULL_HANDLE;
    create_info.basePipelineIndex            = -1;

    VkResult res = vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &create_info, nullptr, &pipeline);
    if (res != VK_SUCCESS)
    {
        CLAY_LOG_ERROR("Failed to create graphics pipeline! ({})", string_VkResult(res));
    }
}

} // namespace gfx
} // namespace clay