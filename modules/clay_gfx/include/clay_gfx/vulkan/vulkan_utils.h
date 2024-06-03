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

struct RenderPassOperation {
    enum Enum
    {
        DontCare,
        Load,
        Clear,
    };
};

inline VkImageLayout to_vk_image_layout(ImageLayout::Enum image_layout)
{
    switch (image_layout)
    {
        case ImageLayout::Undefined:
            return VK_IMAGE_LAYOUT_UNDEFINED;
        case ImageLayout::General:
            return VK_IMAGE_LAYOUT_GENERAL;
        case ImageLayout::ColorAttachmentOptimal:
            return VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        case ImageLayout::DepthStencilAttachmentOptimal:
            return VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
        case ImageLayout::DepthStencilReadOnlyOptimal:
            return VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL;
        case ImageLayout::ShaderReadOnlyOptimal:
            return VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        case ImageLayout::TransferSrcOptimal:
            return VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        case ImageLayout::TransferDstOptimal:
            return VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        case ImageLayout::Preinitialized:
            return VK_IMAGE_LAYOUT_PREINITIALIZED;
        case ImageLayout::PresentSrc:
            return VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
    }
    return VK_IMAGE_LAYOUT_UNDEFINED;
}

inline VkAttachmentLoadOp to_vk_attachment_load_op(RenderPassLoadOp::Enum load_op)
{
    switch (load_op)
    {
        case RenderPassLoadOp::DontCare:
            return VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        case RenderPassLoadOp::Load:
            return VK_ATTACHMENT_LOAD_OP_LOAD;
        case RenderPassLoadOp::Clear:
            return VK_ATTACHMENT_LOAD_OP_CLEAR;
    }
    return VK_ATTACHMENT_LOAD_OP_DONT_CARE;
}

inline VkAttachmentStoreOp to_vk_attachment_store_op(RenderPassStoreOp::Enum store_op)
{
    switch (store_op)
    {
        case RenderPassStoreOp::DontCare:
            return VK_ATTACHMENT_STORE_OP_DONT_CARE;
        case RenderPassStoreOp::Store:
            return VK_ATTACHMENT_STORE_OP_STORE;
    }
    return VK_ATTACHMENT_STORE_OP_DONT_CARE;
}

inline VkFormat to_vk_format(Format::Enum format)
{
    switch (format)
    {
        case Format::Undefined:
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

inline VkCompareOp to_vk_compare_op(CompareOp::Enum compare)
{
    switch (compare)
    {
        case CompareOp::Never:
            return VK_COMPARE_OP_NEVER;
        case CompareOp::Less:
            return VK_COMPARE_OP_LESS;
        case CompareOp::Equal:
            return VK_COMPARE_OP_EQUAL;
        case CompareOp::LessOrEqual:
            return VK_COMPARE_OP_LESS_OR_EQUAL;
        case CompareOp::Greater:
            return VK_COMPARE_OP_GREATER;
        case CompareOp::NotEqual:
            return VK_COMPARE_OP_NOT_EQUAL;
        case CompareOp::GreaterOrEqual:
            return VK_COMPARE_OP_GREATER_OR_EQUAL;
        case CompareOp::Always:
            return VK_COMPARE_OP_ALWAYS;
    }
    return VK_COMPARE_OP_NEVER;
}

inline VkPrimitiveTopology to_vk_primitive_topology(PrimitiveTopology::Enum primitive_topology)
{
    switch (primitive_topology)
    {
        case PrimitiveTopology::PointList:
            return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
        case PrimitiveTopology::LineList:
            return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
        case PrimitiveTopology::LineStrip:
            return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
        case PrimitiveTopology::TriangleList:
            return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
        case PrimitiveTopology::TriangleStrip:
            return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
        case PrimitiveTopology::TriangleFan:
            return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
    }
    return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
}

inline VkPolygonMode to_vk_polygon_mode(FillMode::Enum fill_mode)
{
    switch (fill_mode)
    {
        case FillMode::Solid:
            return VK_POLYGON_MODE_FILL;
        case FillMode::Wireframe:
            return VK_POLYGON_MODE_LINE;
        case FillMode::Point:
            return VK_POLYGON_MODE_POINT;
    }
    return VK_POLYGON_MODE_FILL;
}

inline VkCullModeFlags to_vk_cull_mode(CullMode::Enum cull_mode)
{
    switch (cull_mode)
    {
        case CullMode::None:
            return VK_CULL_MODE_NONE;
        case CullMode::Front:
            return VK_CULL_MODE_FRONT_BIT;
        case CullMode::Back:
            return VK_CULL_MODE_BACK_BIT;
        case CullMode::FrontAndBack:
            return VK_CULL_MODE_FRONT_AND_BACK;
    }
    return VK_CULL_MODE_NONE;
}

inline VkFrontFace to_vk_front_face(FrontFace::Enum front_face)
{
    switch (front_face)
    {
        case FrontFace::Clockwise:
            return VK_FRONT_FACE_CLOCKWISE;
        case FrontFace::CounterClockwise:
            return VK_FRONT_FACE_COUNTER_CLOCKWISE;
    }
    return VK_FRONT_FACE_COUNTER_CLOCKWISE;
}

inline VkBlendFactor to_vk_blend_factor(BlendFactor::Enum factor)
{
    switch (factor)
    {
        case BlendFactor::Zero:
            return VK_BLEND_FACTOR_ZERO;
        case BlendFactor::One:
            return VK_BLEND_FACTOR_ONE;
        case BlendFactor::SrcColor:
            return VK_BLEND_FACTOR_SRC_COLOR;
        case BlendFactor::OneMinusSrcColor:
            return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
        case BlendFactor::DstColor:
            return VK_BLEND_FACTOR_DST_COLOR;
        case BlendFactor::OneMinusDstColor:
            return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
        case BlendFactor::SrcAlpha:
            return VK_BLEND_FACTOR_SRC_ALPHA;
        case BlendFactor::OneMinusSrcAlpha:
            return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        case BlendFactor::DstAlpha:
            return VK_BLEND_FACTOR_DST_ALPHA;
        case BlendFactor::OneMinusDstAlpha:
            return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
        case BlendFactor::ConstantColor:
            return VK_BLEND_FACTOR_CONSTANT_COLOR;
        case BlendFactor::OneMinusConstantColor:
            return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR;
        case BlendFactor::ConstantAlpha:
            return VK_BLEND_FACTOR_CONSTANT_ALPHA;
        case BlendFactor::OneMinusConstantAlpha:
            return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
        case BlendFactor::SrcAlphaSaturate:
            return VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
        case BlendFactor::Src1Color:
            return VK_BLEND_FACTOR_SRC1_COLOR;
        case BlendFactor::OneMinusSrc1Color:
            return VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR;
        case BlendFactor::Src1Alpha:
            return VK_BLEND_FACTOR_SRC1_ALPHA;
        case BlendFactor::OneMinusSrc1Alpha:
            return VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA;
    }
    return VK_BLEND_FACTOR_ZERO;
}

inline VkBlendOp to_vk_blend_op(BlendOp::Enum op)
{
    switch (op)
    {
        case BlendOp::Add:
            return VK_BLEND_OP_ADD;
        case BlendOp::Subtract:
            return VK_BLEND_OP_SUBTRACT;
        case BlendOp::ReverseSubtract:
            return VK_BLEND_OP_REVERSE_SUBTRACT;
        case BlendOp::Min:
            return VK_BLEND_OP_MIN;
        case BlendOp::Max:
            return VK_BLEND_OP_MAX;
    }
    return VK_BLEND_OP_ADD;
}

inline VkColorComponentFlags to_vk_color_component_flags(ColorWriteEnabled::Flag color_write)
{
    VkColorComponentFlags flags = 0;
    if (color_write & ColorWriteEnabled::Red)
    {
        flags |= VK_COLOR_COMPONENT_R_BIT;
    }
    if (color_write & ColorWriteEnabled::Green)
    {
        flags |= VK_COLOR_COMPONENT_G_BIT;
    }
    if (color_write & ColorWriteEnabled::Blue)
    {
        flags |= VK_COLOR_COMPONENT_B_BIT;
    }
    if (color_write & ColorWriteEnabled::Alpha)
    {
        flags |= VK_COLOR_COMPONENT_A_BIT;
    }
    return flags;
}

} // namespace gfx
} // namespace clay