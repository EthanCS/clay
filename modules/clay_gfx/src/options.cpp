#include <clay_core/log.h>
#include <clay_gfx/options.h>

namespace clay
{
namespace gfx
{
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

CreateGraphicsPipelineOptions& CreateGraphicsPipelineOptions::set_pipeline_layout(const Handle<PipelineLayout>& layout)
{
    this->layout = layout;
    return *this;
}

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

CreateDescriptorSetOptions& CreateDescriptorSetOptions::reset()
{
    layout       = Handle<DescriptorSetLayout>::invalid();
    num_bindings = 0;
    return *this;
}

CreateDescriptorSetOptions& CreateDescriptorSetOptions::set_layout(const Handle<DescriptorSetLayout>& layout)
{
    this->layout = layout;
    return *this;
}

CreateDescriptorSetOptions& CreateDescriptorSetOptions::bind_buffer(u32 binding, const Handle<Buffer>& buffer)
{
    if (num_bindings < MAX_DESCRIPTORS_PER_SET)
    {
        bindings[num_bindings].binding = binding;
        bindings[num_bindings].buffer  = buffer;
        num_bindings++;
        return *this;
    }
    else
    {
        CLAY_LOG_ERROR("Exceeded maximum number of descriptor bindings per set");
        return *this;
    }
}

} // namespace gfx
} // namespace clay