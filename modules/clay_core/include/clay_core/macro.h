#pragma once

#include <cstdint>

#if !defined(_MSC_VER)
    #include <signal.h>
#endif

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

typedef size_t usize;

static const u64 u64_MAX = UINT64_MAX;
static const i64 i64_MAX = INT64_MAX;
static const u32 u32_MAX = UINT32_MAX;
static const i32 i32_MAX = INT32_MAX;
static const u16 u16_MAX = UINT16_MAX;
static const i16 i16_MAX = INT16_MAX;
static const u8  u8_MAX  = UINT8_MAX;
static const i8  i8_MAX  = INT8_MAX;

static const i64 i64_MIN = INT64_MIN;
static const i32 i32_MIN = INT32_MIN;
static const i16 i16_MIN = INT16_MIN;
static const i8  i8_MIN  = INT8_MIN;

#define PP_THIRD_ARG(a, b, c, ...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(, ), true, false, )
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)

#if defined(_MSC_VER)
    #define CLAY_DEBUG_BREAK __debugbreak();
#else
    #define CLAY_DEBUG_BREAK raise(SIGTRAP);
#endif // MSVC

#define CLAY_NOEXCEPT noexcept