#include <clay_gfx/clay_gfx.h>

int main(int argc, char** argv)
{
    using namespace clay;

    bool bInit = gfx::init({ .type = gfx::RenderBackendType::Vulkan, .debug = true });
    gfx::shutdown();

    return 0;
}