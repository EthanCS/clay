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

ShaderStateCreateDesc& ShaderStateCreateDesc::add_stage(const ShaderStageDesc& stage_)
{
    // Replace stage if it already exists
    for (u32 s = 0; s < num_stages; ++s)
    {
        if (stages[s].stage == stage_.stage)
        {
            stages[s] = stage_;
            return *this;
        }
    }

    stages[num_stages] = stage_;
    ++num_stages;
    return *this;
}

} // namespace gfx
} // namespace clay