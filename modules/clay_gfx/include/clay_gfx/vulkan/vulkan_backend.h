#pragma once

#include <clay_gfx/clay_gfx.h>

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

namespace clay
{
namespace gfx
{

class VulkanBackend : public RenderBackend
{
private:
    VkInstance instance;
    VkDevice   device;

public:
    VulkanBackend(const RenderBackendCreateDesc& desc);
    virtual ~VulkanBackend() override;
};

} // namespace gfx
} // namespace clay