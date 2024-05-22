#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace app
{

struct Window {
    void init();
    void shutdown();

    void handle_events();

    void* platform_handle = nullptr;
    bool  requested_exit  = false;
    bool  resized         = false;
    bool  minimized       = false;
    u32   width           = 0;
    u32   height          = 0;
};

} // namespace app
} // namespace clay