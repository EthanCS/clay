#pragma once

namespace clay
{
namespace app
{
struct Application {
    virtual ~Application()  = default;
    virtual void init()     = 0;
    virtual void update()   = 0;
    virtual void shutdown() = 0;
};
} // namespace app
} // namespace clay