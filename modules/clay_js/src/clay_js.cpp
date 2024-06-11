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

void eval(std::string_view buffer, const char* filename, int flags)
{
    if (g_qjs_context != nullptr)
    {
        auto& context = *(g_qjs_context);
        context.eval(buffer, filename, flags);
    }
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