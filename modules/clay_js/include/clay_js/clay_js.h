#pragma once

namespace clay
{
namespace js
{
extern void* g_qjs_runtime;
extern void* g_qjs_context;

void init();
void shutdown();
} // namespace js
} // namespace clay