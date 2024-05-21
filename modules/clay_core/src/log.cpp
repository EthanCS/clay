#include <clay_core/log.h>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace clay
{
namespace core
{

Logger& default_logger() noexcept
{
    static Logger logger = [] {
        auto           sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        spdlog::logger _logger{ "console", sink };
        _logger.flush_on(spdlog::level::err);
        _logger.set_level(spdlog::level::info);
        return _logger;
    }();
    return logger;
}

void set_log_level_verbose()
{
    default_logger().set_level(spdlog::level::debug);
}

void set_log_level_info()
{
    default_logger().set_level(spdlog::level::info);
}

void set_log_level_warning()
{
    default_logger().set_level(spdlog::level::warn);
}

void set_log_level_error()
{
    default_logger().set_level(spdlog::level::err);
}

} // namespace core
} // namespace clay