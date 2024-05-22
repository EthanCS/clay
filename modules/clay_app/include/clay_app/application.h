#pragma once

#include <clay_core/macro.h>

namespace clay
{
namespace app
{
struct ApplicationConfig {
    const char* title{ nullptr };
    u32         width;
    u32         height;
};

struct Application {
    virtual void init(const ApplicationConfig& config) {}
    virtual void shutdown() {}
    virtual bool main_loop() { return false; }

    void run(const ApplicationConfig& config);
};
} // namespace app
} // namespace clay