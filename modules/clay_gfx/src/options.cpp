#include <clay_core/log.h>
#include <clay_gfx/options.h>

namespace clay
{
namespace gfx
{

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::reset()
{
    num_bindings = 0;
    set_index    = 0;
    return *this;
}

CreateDescriptorSetLayoutOptions& CreateDescriptorSetLayoutOptions::add_binding(DescriptorType::Enum type, u32 start, u32 count, const char* name)
{
    if (num_bindings < MAX_DESCRIPTORS_PER_SET)
    {
        bindings[num_bindings].type  = type;
        bindings[num_bindings].start = start;
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

} // namespace gfx
} // namespace clay