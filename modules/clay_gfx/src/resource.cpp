#define __IMPL_INVALID_HANDLE
#include <clay_gfx/resource.h>

namespace clay
{
namespace gfx
{
ShaderStateCreateDesc& ShaderStateCreateDesc::reset()
{
    this->num_stages = 0;
    return *this;
}

ShaderStateCreateDesc& ShaderStateCreateDesc::set_name(const char* name)
{
    this->name = name;
    return *this;
}

ShaderStateCreateDesc& ShaderStateCreateDesc::add_stage(const ShaderStage::Flag& stage_, const char* code_, u32 code_size_, const char* entry_point_)
{
    // Replace stage if it already exists
    for (u32 s = 0; s < num_stages; ++s)
    {
        if (stages[s].stage == stage_)
        {
            stages[s].stage       = stage_;
            stages[s].code        = code_;
            stages[s].code_size   = code_size_;
            stages[s].entry_point = entry_point_;
            return *this;
        }
    }

    stages[num_stages].stage       = stage_;
    stages[num_stages].code        = code_;
    stages[num_stages].code_size   = code_size_;
    stages[num_stages].entry_point = entry_point_;
    ++num_stages;
    return *this;
}

} // namespace gfx
} // namespace clay