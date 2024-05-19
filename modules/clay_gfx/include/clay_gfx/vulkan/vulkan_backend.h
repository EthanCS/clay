#pragma once

#include <clay_gfx/clay_gfx.h>
#include <vulkan/vulkan.h>

namespace clay
{
namespace gfx
{

class VulkanBackend : public RenderBackend
{
private:
    VkInstance instance;

public:
    VulkanBackend(const RenderBackendCreateDesc& desc);
};

} // namespace gfx
} // namespace clay