#include <clay_app/application.h>

namespace clay
{
namespace app
{
void Application::run(const ApplicationConfig& config)
{
    init(config);
    main_loop();
    shutdown();
}
} // namespace app
} // namespace clay
