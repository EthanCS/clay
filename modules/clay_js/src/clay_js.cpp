#include <clay_js/clay_js.h>

namespace clay
{
namespace js
{
qjs::Runtime* g_qjs_runtime = nullptr;
qjs::Context* g_qjs_context = nullptr;

void init()
{
    g_qjs_runtime = new qjs::Runtime();
    g_qjs_context = new qjs::Context(*(g_qjs_runtime));
}

qjs::Value eval(std::string_view buffer, const char* filename, int flags)
{
    auto& context = *(g_qjs_context);
    return context.eval(buffer, filename, flags);
}

qjs::Value eval_file(const char* filename, int flags)
{
    auto& context = *(g_qjs_context);
    return context.evalFile(filename, flags);
}

qjs::Context::Module& add_module(const char* name)
{
    auto& context = *(g_qjs_context);
    return context.addModule(name);
}

void shutdown()
{
    if (g_qjs_context != nullptr)
    {
        delete (g_qjs_context);
        g_qjs_context = nullptr;
    }

    if (g_qjs_runtime != nullptr)
    {
        delete (g_qjs_runtime);
        g_qjs_runtime = nullptr;
    }
}

} // namespace js
} // namespace clay