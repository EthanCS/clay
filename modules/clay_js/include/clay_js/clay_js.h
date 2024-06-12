#pragma once

#include <string_view>
#include <clay_js/quickjspp.hpp>

namespace clay
{
namespace js
{
extern qjs::Runtime* g_qjs_runtime;
extern qjs::Context* g_qjs_context;

void       init();
qjs::Value eval(std::string_view buffer, const char* filename = "<eval>", int flags = 0);
qjs::Value eval_file(const char* filename, int flags = 0);
void       shutdown();

////// Module Binding //////
qjs::Context::Module& add_module(const char* name);

} // namespace js
} // namespace clay