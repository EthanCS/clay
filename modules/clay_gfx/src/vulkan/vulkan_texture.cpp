#include <clay_core/log.h>
#include <clay_gfx/vulkan/vulkan_texture.h>

namespace clay
{
namespace gfx
{
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
} // namespace gfx
} // namespace clay