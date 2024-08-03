#include "clay_gfx/define.h"
#include <clay_core/log.h>
#include <clay_gfx/options.h>

namespace clay
{
namespace gfx
{

//////////////////////////////////////////////////////////////////////////
// CreatePipelineLayoutOptions

CreatePipelineLayoutOptions& CreatePipelineLayoutOptions::reset()
{
    num_descriptor_set_layouts = 0;
    return *this;
}

CreatePipelineLayoutOptions& CreatePipelineLayoutOptions::add_descriptor_set_layout(const Handle<DescriptorSetLayout>& layout)
{
    if (num_descriptor_set_layouts < MAX_DESCRIPTOR_SET_LAYOUTS)
    {
        descriptor_set_layouts[num_descriptor_set_layouts] = layout;
        num_descriptor_set_layouts++;
        return *this;
    }
    CLAY_LOG_ERROR("Exceeded maximum number of descriptor set layouts per pipeline layout");
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// CreateGraphicsPipelineOptions

CreateGraphicsPipelineOptions& CreateGraphicsPipelineOptions::set_pipeline_layout(const Handle<PipelineLayout>& layout)
{
    this->layout = layout;
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// CreateDescriptorSetLayoutOptions

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::reset()
{
    num_bindings = 0;
    set_index    = 0;
    return *this;
}

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::add_binding(DescriptorType::Enum type, u32 index, u32 count, const char* name)
{
    if (num_bindings < MAX_DESCRIPTORS_PER_SET)
    {
        bindings[num_bindings].type  = type;
        bindings[num_bindings].index = index;
        bindings[num_bindings].count = count;
        bindings[num_bindings].name  = name;
        num_bindings++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of descriptor bindings per set");
        return *this;
    }
}

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::set_set_index(u32 index)
{
    set_index = index;
    return *this;
}

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::set_name(const char* name)
{
    this->name = name;
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// UpdateDescriptorSetOptions

UpdateDescriptorSetOptions& UpdateDescriptorSetOptions::reset()
{
    count = 0;
    return *this;
}

UpdateDescriptorSetOptions& UpdateDescriptorSetOptions::bind_buffer(u32 binding, const Handle<Buffer>& buffer)
{
    if (count < MAX_DESCRIPTORS_PER_SET)
    {
        infos[count].binding = binding;
        infos[count].buffer  = buffer;
        count++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of descriptor bindings per set");
        return *this;
    }
}

UpdateDescriptorSetOptions& UpdateDescriptorSetOptions::bind_texture(u32 binding, const Handle<Texture>& texture)
{
    if (count < MAX_DESCRIPTORS_PER_SET)
    {
        infos[count].binding = binding;
        infos[count].texture = texture;
        count++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of descriptor bindings per set");
        return *this;
    }
}

UpdateDescriptorSetOptions& UpdateDescriptorSetOptions::bind_texture_sampler(u32 binding, const Handle<Texture>& texture, const Handle<Sampler>& sampler)
{
    if (count < MAX_DESCRIPTORS_PER_SET)
    {
        infos[count].binding = binding;
        infos[count].texture = texture;
        infos[count].sampler = sampler;
        count++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of descriptor bindings per set");
        return *this;
    }
}

//////////////////////////////////////////////////////////////////////////
// CmdPipelineBarrierOptions

CmdPipelineBarrierOptions& CmdPipelineBarrierOptions::source_stage(const PipelineStage::Flag& stage)
{
    src_stage = stage;
    return *this;
}

CmdPipelineBarrierOptions& CmdPipelineBarrierOptions::destination_stage(const PipelineStage::Flag& stage)
{
    dst_stage = stage;
    return *this;
}

CmdPipelineBarrierOptions& CmdPipelineBarrierOptions::add_texture_barrier(const TextureBarrier& barrier)
{
    if (num_texture_barriers < MAX_BARRIERS)
    {
        texture_barriers[num_texture_barriers] = barrier;
        num_texture_barriers++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of texture barriers per pipeline barrier");
        return *this;
    }
}

} // namespace gfx
} // namespace clay