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

#define PP_THIRD_ARG(a, b, c, ...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(, ), true, false, )
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)

#if defined(_MSC_VER)
    #define CLAY_DEBUG_BREAK __debugbreak();
#else
    #define CLAY_DEBUG_BREAK raise(SIGTRAP);
#endif // MSVC