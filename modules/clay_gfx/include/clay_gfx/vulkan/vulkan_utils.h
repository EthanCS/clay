#pragma once

#include <vector>
#include <clay_gfx/define.h>
#include <clay_gfx/vulkan/vulkan_resource.h>
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

inline VkComponentSwizzle to_vk_component_swizzle(TextureComponentSwizzle::Enum swizzle)
{
    switch (swizzle)
    {
        case TextureComponentSwizzle::Identity:
            return VK_COMPONENT_SWIZZLE_IDENTITY;
        case TextureComponentSwizzle::Zero:
            return VK_COMPONENT_SWIZZLE_ZERO;
        case TextureComponentSwizzle::One:
            return VK_COMPONENT_SWIZZLE_ONE;
        case TextureComponentSwizzle::R:
            return VK_COMPONENT_SWIZZLE_R;
        case TextureComponentSwizzle::G:
            return VK_COMPONENT_SWIZZLE_G;
        case TextureComponentSwizzle::B:
            return VK_COMPONENT_SWIZZLE_B;
        case TextureComponentSwizzle::A:
            return VK_COMPONENT_SWIZZLE_A;
    }
    return VK_COMPONENT_SWIZZLE_IDENTITY;
}

inline VkImageViewType to_vk_image_view_type(TextureViewType::Enum view_type)
{
    switch (view_type)
    {
        case TextureViewType::Texture1D:
            return VK_IMAGE_VIEW_TYPE_1D;
        case TextureViewType::Texture2D:
            return VK_IMAGE_VIEW_TYPE_2D;
        case TextureViewType::Texture3D:
            return VK_IMAGE_VIEW_TYPE_3D;
        case TextureViewType::TextureCube:
            return VK_IMAGE_VIEW_TYPE_CUBE;
        case TextureViewType::Texture1DArray:
            return VK_IMAGE_VIEW_TYPE_1D_ARRAY;
        case TextureViewType::Texture2DArray:
            return VK_IMAGE_VIEW_TYPE_2D_ARRAY;
        case TextureViewType::TextureCubeArray:
            return VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
    }
    return VK_IMAGE_VIEW_TYPE_2D;
}

inline VkImageAspectFlags to_vk_image_aspect_flags(const TextureAspect::Flag& aspect_flags)
{
    VkImageAspectFlags flags = 0;
    if (aspect_flags & TextureAspect::Color) { flags |= VK_IMAGE_ASPECT_COLOR_BIT; }
    if (aspect_flags & TextureAspect::Depth) { flags |= VK_IMAGE_ASPECT_DEPTH_BIT; }
    if (aspect_flags & TextureAspect::Stencil) { flags |= VK_IMAGE_ASPECT_STENCIL_BIT; }
    return flags;
}

inline VulkanTextureViewDesc to_vulkan_texture_view_desc(const TextureViewDesc& desc)
{
    VulkanTextureViewDesc view_desc = {};
    view_desc.view_type             = to_vk_image_view_type(desc.view_type);
    view_desc.format                = to_vk_format(desc.format);
    view_desc.component_r           = to_vk_component_swizzle(desc.component_r);
    view_desc.component_g           = to_vk_component_swizzle(desc.component_g);
    view_desc.component_b           = to_vk_component_swizzle(desc.component_b);
    view_desc.component_a           = to_vk_component_swizzle(desc.component_a);
    view_desc.aspect_flags          = to_vk_image_aspect_flags(desc.aspect_flags);
    view_desc.base_mip_level        = desc.base_mip_level;
    view_desc.level_count           = desc.level_count;
    view_desc.base_array_layer      = desc.base_array_layer;
    view_desc.layer_count           = desc.layer_count;
    return view_desc;
}

inline VkPipelineStageFlags to_vk_pipeline_stage_flags(PipelineStage::Flag stage)
{
    VkPipelineStageFlags flags = 0;
    if (stage & PipelineStage::TopOfPipe)
    {
        flags |= VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    }
    if (stage & PipelineStage::DrawIndirect)
    {
        flags |= VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT;
    }
    if (stage & PipelineStage::VertexInput)
    {
        flags |= VK_PIPELINE_STAGE_VERTEX_INPUT_BIT;
    }
    if (stage & PipelineStage::VertexShader)
    {
        flags |= VK_PIPELINE_STAGE_VERTEX_SHADER_BIT;
    }
    if (stage & PipelineStage::TessellationControlShader)
    {
        flags |= VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT;
    }
    if (stage & PipelineStage::TessellationEvaluationShader)
    {
        flags |= VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT;
    }
    if (stage & PipelineStage::GeometryShader)
    {
        flags |= VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT;
    }
    if (stage & PipelineStage::FragmentShader)
    {
        flags |= VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
    }
    if (stage & PipelineStage::EarlyFragmentTests)
    {
        flags |= VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
    }
    if (stage & PipelineStage::LateFragmentTests)
    {
        flags |= VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
    }
    if (stage & PipelineStage::ColorAttachmentOutput)
    {
        flags |= VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    }
    if (stage & PipelineStage::ComputeShader)
    {
        flags |= VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
    }
    if (stage & PipelineStage::Transfer)
    {
        flags |= VK_PIPELINE_STAGE_TRANSFER_BIT;
    }
    if (stage & PipelineStage::BottomOfPipe)
    {
        flags |= VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    }
    if (stage & PipelineStage::Host)
    {
        flags |= VK_PIPELINE_STAGE_HOST_BIT;
    }
    if (stage & PipelineStage::AllGraphics)
    {
        flags |= VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT;
    }
    if (stage & PipelineStage::AllCommands)
    {
        flags |= VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
    }
    return flags;
}

inline VkBufferUsageFlags to_vk_buffer_usage_flags(BufferUsage::Flag usage)
{
    VkBufferUsageFlags flags = 0;
    if (usage & BufferUsage::TransferSrc) { flags |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT; }
    if (usage & BufferUsage::TransferDst) { flags |= VK_BUFFER_USAGE_TRANSFER_DST_BIT; }
    if (usage & BufferUsage::UniformTexelBuffer) { flags |= VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT; }
    if (usage & BufferUsage::StorageTexelBuffer) { flags |= VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT; }
    if (usage & BufferUsage::UniformBuffer) { flags |= VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT; }
    if (usage & BufferUsage::StorageBuffer) { flags |= VK_BUFFER_USAGE_STORAGE_BUFFER_BIT; }
    if (usage & BufferUsage::IndexBuffer) { flags |= VK_BUFFER_USAGE_INDEX_BUFFER_BIT; }
    if (usage & BufferUsage::VertexBuffer) { flags |= VK_BUFFER_USAGE_VERTEX_BUFFER_BIT; }
    if (usage & BufferUsage::IndirectBuffer) { flags |= VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT; }
    if (usage & BufferUsage::ShaderDeviceAddress) { flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT; }
    if (usage & BufferUsage::VideoDecodeSrc) { flags |= VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR; }
    if (usage & BufferUsage::VideoDecodeDst) { flags |= VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR; }
    if (usage & BufferUsage::TransformFeedbackBuffer) { flags |= VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT; }
    if (usage & BufferUsage::TransformFeedbackCounterBuffer) { flags |= VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT; }
    if (usage & BufferUsage::ConditionalRendering) { flags |= VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT; }
    if (usage & BufferUsage::AccelerationStructureBuildInputReadOnly) { flags |= VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR; }
    if (usage & BufferUsage::AccelerationStructureStorage) { flags |= VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR; }
    if (usage & BufferUsage::ShaderBindingTable) { flags |= VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR; }
    if (usage & BufferUsage::SamplerDescriptorBuffer) { flags |= VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT; }
    if (usage & BufferUsage::ResourceDescriptorBuffer) { flags |= VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT; }
    if (usage & BufferUsage::PushDescriptorsDescriptorBuffer) { flags |= VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT; }
    if (usage & BufferUsage::MicromapBuildInputReadOnly) { flags |= VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT; }
    if (usage & BufferUsage::MicromapStorage) { flags |= VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT; }
    return flags;
}

inline VkIndexType to_vk_index_type(IndexType::Enum index_type)
{
    switch (index_type)
    {
        case IndexType::Uint16:
            return VK_INDEX_TYPE_UINT16;
        case IndexType::Uint32:
            return VK_INDEX_TYPE_UINT32;
    }
    return VK_INDEX_TYPE_UINT16;
}

inline VkDescriptorType to_vk_descriptor_type(DescriptorType::Enum type)
{
    switch (type)
    {
        case DescriptorType::Sampler:
            return VK_DESCRIPTOR_TYPE_SAMPLER;
        case DescriptorType::CombinedImageSampler:
            return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        case DescriptorType::SampledImage:
            return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
        case DescriptorType::StorageImage:
            return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
        case DescriptorType::UniformTexelBuffer:
            return VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;
        case DescriptorType::StorageTexelBuffer:
            return VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;
        case DescriptorType::UniformBuffer:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        case DescriptorType::StorageBuffer:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        case DescriptorType::UniformBufferDynamic:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
        case DescriptorType::StorageBufferDynamic:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC;
        case DescriptorType::InputAttachment:
            return VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;
    }
    return VK_DESCRIPTOR_TYPE_SAMPLER;
}

inline VkPipelineBindPoint to_vk_pipeline_bind_point(PipelineBindPoint::Enum bind_point)
{
    switch (bind_point)
    {
        case PipelineBindPoint::Graphics:
            return VK_PIPELINE_BIND_POINT_GRAPHICS;
        case PipelineBindPoint::Compute:
            return VK_PIPELINE_BIND_POINT_COMPUTE;
    }
    return VK_PIPELINE_BIND_POINT_GRAPHICS;
}

inline VkImageType to_vk_image_type(TextureType::Enum type)
{
    switch (type)
    {
        case TextureType::Texture1D:
            return VK_IMAGE_TYPE_1D;
        case TextureType::Texture2D:
            return VK_IMAGE_TYPE_2D;
        case TextureType::Texture3D:
            return VK_IMAGE_TYPE_3D;
    }
    return VK_IMAGE_TYPE_2D;
}

inline VkFilter to_vk_filter(FilterType::Enum filter)
{
    switch (filter)
    {
        case FilterType::Nearest:
            return VK_FILTER_NEAREST;
        case FilterType::Linear:
            return VK_FILTER_LINEAR;
    }
    return VK_FILTER_NEAREST;
}

inline VkSamplerMipmapMode to_vk_mipmap_mode(MipmapType::Enum mipmap)
{
    switch (mipmap)
    {
        case MipmapType::Nearest:
            return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        case MipmapType::Linear:
            return VK_SAMPLER_MIPMAP_MODE_LINEAR;
    }
    return VK_SAMPLER_MIPMAP_MODE_NEAREST;
}

inline VkSamplerAddressMode to_vk_address_mode(AddressMode::Enum address)
{
    switch (address)
    {
        case AddressMode::Repeat:
            return VK_SAMPLER_ADDRESS_MODE_REPEAT;
        case AddressMode::Mirror:
            return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
        case AddressMode::ClampToBorder:
            return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
        case AddressMode::ClampToEdge:
            return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    }
    return VK_SAMPLER_ADDRESS_MODE_REPEAT;
}

inline VkImageUsageFlags to_vk_image_usage_flags(TextureUsage::Flag usage)
{
    VkImageUsageFlags flags = 0;
    if (usage & TextureUsage::TransferSrc) { flags |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT; }
    if (usage & TextureUsage::TransferDst) { flags |= VK_IMAGE_USAGE_TRANSFER_DST_BIT; }
    if (usage & TextureUsage::Sampled) { flags |= VK_IMAGE_USAGE_SAMPLED_BIT; }
    if (usage & TextureUsage::Storage) { flags |= VK_IMAGE_USAGE_STORAGE_BIT; }
    if (usage & TextureUsage::ColorAttachment) { flags |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; }
    if (usage & TextureUsage::DepthStencilAttachment) { flags |= VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT; }
    if (usage & TextureUsage::TransientAttachment) { flags |= VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT; }
    if (usage & TextureUsage::InputAttachment) { flags |= VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT; }
    return flags;
}

inline VkAccessFlags to_vk_access_flags(AccessMask::Flag access)
{
    VkAccessFlags flags = 0;
    if (access & AccessMask::IndirectCommandRead) { flags |= VK_ACCESS_INDIRECT_COMMAND_READ_BIT; }
    if (access & AccessMask::IndexRead) { flags |= VK_ACCESS_INDEX_READ_BIT; }
    if (access & AccessMask::VertexAttributeRead) { flags |= VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT; }
    if (access & AccessMask::UniformRead) { flags |= VK_ACCESS_UNIFORM_READ_BIT; }
    if (access & AccessMask::InputAttachmentRead) { flags |= VK_ACCESS_INPUT_ATTACHMENT_READ_BIT; }
    if (access & AccessMask::ShaderRead) { flags |= VK_ACCESS_SHADER_READ_BIT; }
    if (access & AccessMask::ShaderWrite) { flags |= VK_ACCESS_SHADER_WRITE_BIT; }
    if (access & AccessMask::ColorAttachmentRead) { flags |= VK_ACCESS_COLOR_ATTACHMENT_READ_BIT; }
    if (access & AccessMask::ColorAttachmentWrite) { flags |= VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT; }
    if (access & AccessMask::DepthStencilAttachmentRead) { flags |= VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT; }
    if (access & AccessMask::DepthStencilAttachmentWrite) { flags |= VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT; }
    if (access & AccessMask::TransferRead) { flags |= VK_ACCESS_TRANSFER_READ_BIT; }
    if (access & AccessMask::TransferWrite) { flags |= VK_ACCESS_TRANSFER_WRITE_BIT; }
    if (access & AccessMask::HostRead) { flags |= VK_ACCESS_HOST_READ_BIT; }
    if (access & AccessMask::HostWrite) { flags |= VK_ACCESS_HOST_WRITE_BIT; }
    if (access & AccessMask::MemoryRead) { flags |= VK_ACCESS_MEMORY_READ_BIT; }
    if (access & AccessMask::MemoryWrite) { flags |= VK_ACCESS_MEMORY_WRITE_BIT; }
    return flags;
}

} // namespace gfx
} // namespace clay