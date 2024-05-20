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

#if defined(_MSC_VER)
    #define CLAY_DEBUG_BREAK __debugbreak();
#else
    #define CLAY_DEBUG_BREAK raise(SIGTRAP);
#endif // MSVC