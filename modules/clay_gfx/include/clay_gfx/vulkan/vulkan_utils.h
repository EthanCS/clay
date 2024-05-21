#pragma once

#include <vector>

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

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

} // namespace gfx
} // namespace clay