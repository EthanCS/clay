#pragma once

#include <daScript/daScriptC.h>

namespace clay
{
namespace das
{

struct Module {
    das_module* module;
};

void init();
void run();
void shutdown();

} // namespace das
} // namespace clay