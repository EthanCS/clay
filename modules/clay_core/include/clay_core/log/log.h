#pragma once

#include <clay_core/macro.h>
#include <spdlog/spdlog.h>

namespace clay
{
namespace core
{
using Logger = spdlog::logger;
Logger& default_logger() noexcept;

template <typename... Args>
inline void log_verbose(Args&&... args) noexcept
{
    default_logger().debug(std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_info(Args&&... args) noexcept
{
    default_logger().info(std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_warning(Args&&... args) noexcept
{
    default_logger().warn(std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_error(Args&&... args) noexcept
{
    default_logger().error(std::forward<Args>(args)...);
}

void set_log_level_verbose();
void set_log_level_info();
void set_log_level_warning();
void set_log_level_error();

} // namespace core
} // namespace clay

#define CLAY_LOG_VERBOSE(fmt, ...) \
    ::clay::core::log_verbose(FMT_STRING(fmt) __VA_OPT__(, ) __VA_ARGS__)
    
#define CLAY_LOG_INFO(fmt, ...) ::clay::core::log_info(FMT_STRING(fmt) __VA_OPT__(, ) __VA_ARGS__)
#define CLAY_LOG_WARNING(fmt, ...) ::clay::core::log_warning(FMT_STRING(fmt) __VA_OPT__(, ) __VA_ARGS__)
#define CLAY_LOG_ERROR(fmt, ...) ::clay::core::log_error(FMT_STRING(fmt) __VA_OPT__(, ) __VA_ARGS__)

#define CLAY_LOG_VERBOSE_LOCATION(fmt, ...) CLAY_LOG_VERBOSE(fmt " [{}:{}]" __VA_OPT__(, ) __VA_ARGS__, __FILE__, __LINE__)
#define CLAY_LOG_INFO_LOCATION(fmt, ...) CLAY_LOG_INFO(fmt " [{}:{}]" __VA_OPT__(, ) __VA_ARGS__, __FILE__, __LINE__)
#define CLAY_LOG_WARNING_LOCATION(fmt, ...) CLAY_LOG_WARNING(fmt " [{}:{}]" __VA_OPT__(, ) __VA_ARGS__, __FILE__, __LINE__)
#define CLAY_LOG_ERROR_LOCATION(fmt, ...) CLAY_LOG_ERROR(fmt " [{}:{}]" __VA_OPT__(, ) __VA_ARGS__, __FILE__, __LINE__)

#define CLAY_ASSERT(x, fmt, ...) \
    do                           \
    {                            \
        if (!(x)) [[unlikely]]   \
        {                        \
            CLAY_DEBUG_BREAK     \
        }                        \
    } while (false)