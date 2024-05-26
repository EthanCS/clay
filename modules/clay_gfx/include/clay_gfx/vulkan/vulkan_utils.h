#pragma once

#include <vector>
#include <clay_gfx/define.h>
#include <clay_gfx/vulkan/vulkan_header.h>

namespace clay
{
namespace gfx
{
inline std::vector<const char*> vulkan_get_layer_names(bool debug)
{
    std::vector<const char*> layerNames;
    if (debug)
    {
        layerNames.push_back("VK_LAYER_KHRONOS_validation");
    }
    return layerNames;
}

inline std::vector<const char*> vulkan_get_extension_names(bool debug)
{
    std::vector<const char*> extensionNames;
    extensionNames.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    extensionNames.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#endif
    if (debug)
    {
        extensionNames.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
        extensionNames.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }
    return extensionNames;
}

inline VkShaderStageFlags to_vk_shader_stage_flags(const ShaderStage::Flag& stage)
{
    VkShaderStageFlags flags = 0;
    if (stage & ShaderStage::Vertex)
    {
        flags |= VK_SHADER_STAGE_VERTEX_BIT;
    }
    if (stage & ShaderStage::Fragment)
    {
        flags |= VK_SHADER_STAGE_FRAGMENT_BIT;
    }
    if (stage & ShaderStage::Compute)
    {
        flags |= VK_SHADER_STAGE_COMPUTE_BIT;
    }
    return flags;
}

inline VkShaderStageFlagBits to_vk_shader_stage_flag_bits(const ShaderStage::Flag& stage)
{
    if (stage & ShaderStage::Vertex)
    {
        return VK_SHADER_STAGE_VERTEX_BIT;
    }
    if (stage & ShaderStage::Fragment)
    {
        return VK_SHADER_STAGE_FRAGMENT_BIT;
    }
    if (stage & ShaderStage::Compute)
    {
        return VK_SHADER_STAGE_COMPUTE_BIT;
    }
    return VK_SHADER_STAGE_ALL;
}

inline VkFormat to_vk_format(Format::Enum format)
{
    switch (format)
    {
        case Format::Unknown:
            return VK_FORMAT_UNDEFINED;
        case Format::D32_SFLOAT:
            return VK_FORMAT_D32_SFLOAT;
        case Format::D32_SFLOAT_S8_UINT:
            return VK_FORMAT_D32_SFLOAT_S8_UINT;
        case Format::D24_UNORM_S8_UINT:
            return VK_FORMAT_D24_UNORM_S8_UINT;
        case Format::B8G8R8A8_UNORM:
            return VK_FORMAT_B8G8R8A8_UNORM;
        case Format::B8G8R8A8_SRGB:
            return VK_FORMAT_B8G8R8A8_SRGB;
        case Format::R8G8B8A8_UNORM:
            return VK_FORMAT_R8G8B8A8_UNORM;
        case Format::R8G8B8A8_SRGB:
            return VK_FORMAT_R8G8B8A8_SRGB;
        case Format::B8G8R8_UNORM:
            return VK_FORMAT_B8G8R8_UNORM;
        case Format::B8G8R8_SRGB:
            return VK_FORMAT_B8G8R8_SRGB;
        case Format::R8G8B8_UNORM:
            return VK_FORMAT_R8G8B8_UNORM;
        case Format::R8G8B8_SRGB:
            return VK_FORMAT_R8G8B8_SRGB;
        case Format::R32_SFLOAT:
            return VK_FORMAT_R32_SFLOAT;
        case Format::R32G32_SFLOAT:
            return VK_FORMAT_R32G32_SFLOAT;
        case Format::R32G32B32_SFLOAT:
            return VK_FORMAT_R32G32B32_SFLOAT;
        case Format::R32G32B32A32_SFLOAT:
            return VK_FORMAT_R32G32B32A32_SFLOAT;
    }
    return VK_FORMAT_UNDEFINED;
}
} // namespace gfx
} // namespace clay