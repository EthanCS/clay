#pragma once

#include "clay_core/log.h"
#include "vulkan_utils.h"
#include <vector>

#include <clay_gfx/resource.h>
#include <clay_gfx/define.h>
#include <clay_gfx/vulkan/vulkan_header.h>

namespace flecs
{
struct world;
}

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

struct VulkanShaderState {
    const char*                     name       = nullptr;
    u32                             num_stages = 0;
    VkPipelineShaderStageCreateInfo shader_stage_info[MAX_SHADER_STAGES];

    inline bool init(const VkDevice& device, const ShaderStateCreateDesc& desc)
    {
        name       = desc.name;
        num_stages = desc.num_stages;
        for (u32 i = 0; i < num_stages; ++i)
        {
            VkShaderModuleCreateInfo shader_create_info = {};
            shader_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            shader_create_info.codeSize                 = desc.stages[i].code_size;
            shader_create_info.pCode                    = reinterpret_cast<const u32*>(desc.stages[i].code);

            VkShaderModule shader_module;
            VkResult       res = vkCreateShaderModule(device, &shader_create_info, nullptr, &shader_module);
            if (res != VK_SUCCESS)
            {
                CLAY_LOG_ERROR("Failed to create shader module. ({})", string_VkResult(res));
                // Destroy created shader modules
                for (u32 j = 0; j < i; ++j)
                {
                    vkDestroyShaderModule(device, shader_stage_info[j].module, nullptr);
                }
                return false;
            }

            shader_stage_info[i].sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shader_stage_info[i].stage               = to_vk_shader_stage_flag_bits(desc.stages[i].stage);
            shader_stage_info[i].module              = shader_module;
            shader_stage_info[i].pName               = desc.stages[i].entry_point;
            shader_stage_info[i].pSpecializationInfo = nullptr;
        }
        return true;
    }

    inline void destroy(const VkDevice& device) const
    {
        for (u32 i = 0; i < num_stages; ++i)
        {
            vkDestroyShaderModule(device, shader_stage_info[i].module, nullptr);
        }
    }
};

struct VulkanSwapchain {
    VkSwapchainKHR swapchain;

    u32           image_count;
    TextureHandle images[MAX_SWAPCHAIN_IMAGES];

    VulkanSwapchain() noexcept;
    bool init(flecs::world* world, VkDevice device, VkPhysicalDevice physical_device, VkSurfaceKHR surface, u32 width, u32 height, Format::Enum format, bool vsync);
};

struct VulkanTextureViewDesc {
    VkImageViewType    view_type;
    VkFormat           format;
    VkImageAspectFlags aspect_flags;
    VkComponentSwizzle component_r;
    VkComponentSwizzle component_g;
    VkComponentSwizzle component_b;
    VkComponentSwizzle component_a;
    u32                base_mip_level;
    u32                level_count;
    u32                base_array_layer;
    u32                layer_count;

    bool operator==(const VulkanTextureViewDesc& rhs) const
    {
        return view_type == rhs.view_type &&
               format == rhs.format &&
               aspect_flags == rhs.aspect_flags &&
               component_r == rhs.component_r &&
               component_g == rhs.component_g &&
               component_b == rhs.component_b &&
               component_a == rhs.component_a &&
               base_mip_level == rhs.base_mip_level &&
               level_count == rhs.level_count &&
               base_array_layer == rhs.base_array_layer &&
               layer_count == rhs.layer_count;
    }
};

struct VulkanTexture {
    VkImage                            image;
    std::vector<VkImageView>           views;
    std::vector<VulkanTextureViewDesc> view_descs;

    VkImageView get_view(const VkDevice& device, const VulkanTextureViewDesc& desc);
    inline void destroy(const VkDevice& device) const
    {
        for (const auto& view : views)
        {
            vkDestroyImageView(device, view, nullptr);
        }
        vkDestroyImage(device, image, nullptr);
    }
};
} // namespace gfx
} // namespace clay