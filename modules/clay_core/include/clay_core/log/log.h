#pragma once

#include <clay_core/macro.h>
#include <spdlog/spdlog.h>

namespace clay
{
namespace core
{
using Logger = spdlog::logger;
Logger& default_logger() noexcept;

void set_log_level_verbose();
void set_log_level_info();
void set_log_level_warning();
void set_log_level_error();

} // namespace core
} // namespace clay

#define CLAY_LOG_VERBOSE(...) (::clay::core::default_logger()).log(spdlog::level::debug, __VA_ARGS__)
#define CLAY_LOG_INFO(...) (::clay::core::default_logger()).log(spdlog::level::debug, __VA_ARGS__)
#define CLAY_LOG_WARNING(...) (::clay::core::default_logger()).log(spdlog::level::debug, __VA_ARGS__)
#define CLAY_LOG_ERROR(...) (::clay::core::default_logger()).log(spdlog::level::debug, __VA_ARGS__)

#define CLAY_LOG_VERBOSE_LOCATION(...) \
    (::clay::core::default_logger()).log(spdlog::source_loc{ __FILE__, __LINE__, SPDLOG_FUNCTION }, spdlog::level::debug, __VA_ARGS__)
#define CLAY_LOG_INFO_LOCATION(...) \
    (::clay::core::default_logger()).log(spdlog::source_loc{ __FILE__, __LINE__, SPDLOG_FUNCTION }, spdlog::level::info, __VA_ARGS__)
#define CLAY_LOG_WARNING_LOCATION(...) \
    (::clay::core::default_logger()).log(spdlog::source_loc{ __FILE__, __LINE__, SPDLOG_FUNCTION }, spdlog::level::warn, __VA_ARGS__)
#define CLAY_LOG_ERROR_LOCATION(...) \
    (::clay::core::default_logger()).log(spdlog::source_loc{ __FILE__, __LINE__, SPDLOG_FUNCTION }, spdlog::level::err, __VA_ARGS__)

#define CLAY_ASSERT(x, msg, ...)                                      \
    do                                                                \
    {                                                                 \
        if (!(x)) [[unlikely]]                                        \
        {                                                             \
            auto m = fmt::format(msg, __VA_ARGS__);                   \
            CLAY_LOG_ERROR_LOCATION("Assertion: {}, Msg: {}", #x, m); \
            CLAY_DEBUG_BREAK                                          \
        }                                                             \
    } while (false)