#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require utf8_utils
 // require math
#include "daScript/simulate/aot_builtin_math.h"
 // require strings
#include "daScript/simulate/aot_builtin_string.h"
 // require strings_boost

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4100)   // unreferenced formal parameter
#pragma warning(disable:4189)   // local variable is initialized but not referenced
#pragma warning(disable:4244)   // conversion from 'int32_t' to 'float', possible loss of data
#pragma warning(disable:4114)   // same qualifier more than once
#pragma warning(disable:4623)   // default constructor was implicitly defined as deleted
#pragma warning(disable:4946)   // reinterpret_cast used between related classes
#pragma warning(disable:4269)   // 'const' automatic data initialized with compiler generated default constructor produces unreliable results
#pragma warning(disable:4555)   // result of expression not used
#endif
#if defined(__EDG__)
#pragma diag_suppress 826
#elif defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsubobject-linkage"
#endif
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wwritable-strings"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#pragma clang diagnostic ignored "-Wunsequenced"
#pragma clang diagnostic ignored "-Wunused-function"
#endif

namespace das {
namespace _anon_16314304901688393757 {

extern TypeInfo __type_info__af63e84c860200f0;
extern TypeInfo __type_info__37d36026a6078a42;
extern TypeInfo __type_info__5ee52699b9679f52;
extern TypeInfo __type_info__af63eb4c86020609;
extern TypeInfo __type_info__af5be84c85f468f0;
extern TypeInfo __type_info__4ac1d999a882997b;
extern TypeInfo __type_info__af63ee4c86020b22;
extern VarInfo __var_info__1f33941668547bfd;
extern VarInfo __var_info__3aefdf5fd38bc810;
extern FuncInfo __func_info__2f76c7f7dd4f0b27;
extern FuncInfo __func_info__5f4b6da70ca496e2;

VarInfo __func_info__2f76c7f7dd4f0b27_field_0 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 41058, 24, UINT64_C(0x3aefdf5fd38bc810), "p", 0, 0 };
VarInfo * __func_info__2f76c7f7dd4f0b27_fields[1] =  { &__func_info__2f76c7f7dd4f0b27_field_0 };
FuncInfo __func_info__2f76c7f7dd4f0b27 = {"invoke block<(p:array<uint8> const#):void> const", "", __func_info__2f76c7f7dd4f0b27_fields, 1, 32, &__type_info__af63eb4c86020609, nullptr,0,UINT64_C(0x2f76c7f7dd4f0b27), 0x0 };
VarInfo __func_info__5f4b6da70ca496e2_field_0 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 41058, 24, UINT64_C(0x1f33941668547bfd), "arr", 0, 0 };
VarInfo * __func_info__5f4b6da70ca496e2_fields[1] =  { &__func_info__5f4b6da70ca496e2_field_0 };
FuncInfo __func_info__5f4b6da70ca496e2 = {"invoke block<(arr:array<uint8> const#):void> const", "", __func_info__5f4b6da70ca496e2_fields, 1, 32, &__type_info__af63eb4c86020609, nullptr,0,UINT64_C(0x5f4b6da70ca496e2), 0x0 };
TypeInfo __type_info__af63e84c860200f0 = { Type::tUInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xaf63e84c860200f0) };
TypeInfo __type_info__37d36026a6078a42 = { Type::tHandle, nullptr, nullptr, DAS_MAKE_ANNOTATION("~strings::StringBuilderWriter"), nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 2, 288, UINT64_C(0x37d36026a6078a42) };
TypeInfo __type_info__5ee52699b9679f52 = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af63e84c860200f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 40962, 24, UINT64_C(0x5ee52699b9679f52) };
TypeInfo __type_info__af63eb4c86020609 = { Type::tVoid, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 0, UINT64_C(0xaf63eb4c86020609) };
TypeInfo __type_info__af5be84c85f468f0 = { Type::tUInt8, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0xaf5be84c85f468f0) };
TypeInfo __type_info__4ac1d999a882997b = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 40962, 24, UINT64_C(0x4ac1d999a882997b) };
TypeInfo __type_info__af63ee4c86020b22 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0xaf63ee4c86020b22) };

static void resolveTypeInfoAnnotations()
{
	__type_info__37d36026a6078a42.resolveAnnotation();
}

TypeInfo * __tinfo_0[1] = { &__type_info__4ac1d999a882997b };
TypeInfo * __tinfo_1[1] = { &__type_info__5ee52699b9679f52 };
TypeInfo * __tinfo_2[2] = { &__type_info__37d36026a6078a42, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_3[2] = { &__type_info__37d36026a6078a42, &__type_info__af63ee4c86020b22 };
// unused enumeration ConversionResult

inline int32_t _FuncbuiltinTicklength_59b92f62e07969bc ( Context * __context__, TDim<uint8_t,2> const  & __a_rename_at_267_0 );
inline int32_t _FuncbuiltinTicklength_1cf5c98666586392 ( Context * __context__, TDim<uint8_t,3> const  & __a_rename_at_267_1 );
inline int32_t _FuncbuiltinTicklength_7305224819e13b88 ( Context * __context__, TDim<uint8_t,4> const  & __a_rename_at_267_2 );
inline int32_t _FuncbuiltinTicklength_34e69ed4aa0e945a ( Context * __context__, TDim<uint8_t,1> const  & __a_rename_at_267_3 );
inline TArray<uint8_t> _FuncbuiltinTickto_array_move_bdc5580b138debbb ( Context * __context__, TDim<uint8_t,2> & __a_rename_at_668_4 );
inline TArray<uint8_t> _FuncbuiltinTickto_array_move_e577077924e1c08f ( Context * __context__, TDim<uint8_t,3> & __a_rename_at_668_6 );
inline TArray<uint8_t> _FuncbuiltinTickto_array_move_48ce32e961537be7 ( Context * __context__, TDim<uint8_t,4> & __a_rename_at_668_8 );
inline TArray<uint8_t> _FuncbuiltinTickto_array_move_e86300f468fc8fcb ( Context * __context__, TDim<uint8_t,1> & __a_rename_at_668_10 );
inline TArray<uint8_t> & _FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef ( Context * __context__, TArray<uint8_t> & __a_rename_at_38_12 );
inline TArray<uint32_t> & _FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b ( Context * __context__, TArray<uint32_t> & __a_rename_at_38_13 );
inline void _FuncbuiltinTickpush_96b6a7003d9304b3 ( Context * __context__, TArray<uint8_t> & __Arr_rename_at_79_14, uint8_t __value_rename_at_79_15 );
inline void _FuncbuiltinTickreserve_1163d4031687d985 ( Context * __context__, TArray<uint8_t> & __Arr_rename_at_63_16, int32_t __newSize_rename_at_63_17 );
inline void _FuncbuiltinTickpush_3d8e11693091805e ( Context * __context__, TArray<uint32_t> & __Arr_rename_at_79_18, uint32_t __value_rename_at_79_19 );
inline void _FuncbuiltinTickresize_4c98a9f12906ee43 ( Context * __context__, TArray<uint8_t> & __Arr_rename_at_50_20, int32_t __newSize_rename_at_50_21 );
inline uint32_t utf16_to_utf32_2c85c7ce7b90cf66 ( Context * __context__, uint32_t __high_rename_at_9_22, uint32_t __low_rename_at_9_23 );
inline void utf8_encode_5ea3a6cf711d0b53 ( Context * __context__, TArray<uint8_t> & __dest_array_rename_at_15_24, uint32_t __ch_rename_at_15_25 );
inline TArray<uint8_t> utf8_encode_fe9a2c6d855320bd ( Context * __context__, uint32_t __ch_rename_at_33_26 );
inline void utf8_encode_95f1494bc2b6ed49 ( Context * __context__, TArray<uint8_t> & __dest_array_rename_at_54_27, TArray<uint32_t> const  & __source_utf32_string_rename_at_54_28 );
inline TArray<uint8_t> utf8_encode_2dfdb6c0c0665fee ( Context * __context__, TArray<uint32_t> const  & __source_utf32_string_rename_at_60_30 );
inline int32_t utf8_length_362d2fb098289bdc ( Context * __context__, TArray<uint8_t> const  & __utf8_string_rename_at_69_33 );
inline int32_t utf8_length_1e6f8ee224ef4bd2 ( Context * __context__, char * const  __utf8_string_rename_at_78_36 );
inline bool is_first_byte_of_utf8_char_ec644bb641f9e7a4 ( Context * __context__, uint8_t __ch_rename_at_87_39 );
inline bool contains_utf8_bom_fac11c0fbdbb944f ( Context * __context__, TArray<uint8_t> const  & __utf8_string_rename_at_92_41 );
inline bool contains_utf8_bom_9f371025b0516edc ( Context * __context__, char * const  __utf8_string_rename_at_97_42 );
inline bool is_utf8_string_valid_221552b9eafc590a ( Context * __context__, TArray<uint8_t> const  & __utf8_string_rename_at_133_43 );
inline bool is_utf8_string_valid_c001bdc037b6eb95 ( Context * __context__, char * const  __utf8_string_rename_at_144_49 );
inline void utf8_decode_2bda99fa41022503 ( Context * __context__, TArray<uint32_t> & __dest_utf32_string_rename_at_155_55, TArray<uint8_t> const  & __source_utf8_string_rename_at_155_56 );
inline TArray<uint32_t> utf8_decode_6daf598a4fe1ed4 ( Context * __context__, TArray<uint8_t> const  & __source_utf8_string_rename_at_171_63 );
inline TArray<uint32_t> utf8_decode_9bde921137fa170 ( Context * __context__, char * const  __source_utf8_string_rename_at_178_65 );
inline void utf8_decode_4f7738d23733680a ( Context * __context__, TArray<uint32_t> & __dest_utf32_string_rename_at_186_68, char * const  __source_utf8_string_rename_at_186_69 );
inline char * decode_unicode_escape_e2de811e7f2112f5 ( Context * __context__, char * const  __str_rename_at_191_71 );

void __init_script ( Context * __context__, bool __init_shared )
{
	if ( __init_shared ) das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) = (([&]() -> TDim<uint32_t,364> {
		TDim<uint32_t,364> __mka_109;
		__mka_109(0,__context__) = 0x0u;
		__mka_109(1,__context__) = 0x0u;
		__mka_109(2,__context__) = 0x0u;
		__mka_109(3,__context__) = 0x0u;
		__mka_109(4,__context__) = 0x0u;
		__mka_109(5,__context__) = 0x0u;
		__mka_109(6,__context__) = 0x0u;
		__mka_109(7,__context__) = 0x0u;
		__mka_109(8,__context__) = 0x0u;
		__mka_109(9,__context__) = 0x0u;
		__mka_109(10,__context__) = 0x0u;
		__mka_109(11,__context__) = 0x0u;
		__mka_109(12,__context__) = 0x0u;
		__mka_109(13,__context__) = 0x0u;
		__mka_109(14,__context__) = 0x0u;
		__mka_109(15,__context__) = 0x0u;
		__mka_109(16,__context__) = 0x0u;
		__mka_109(17,__context__) = 0x0u;
		__mka_109(18,__context__) = 0x0u;
		__mka_109(19,__context__) = 0x0u;
		__mka_109(20,__context__) = 0x0u;
		__mka_109(21,__context__) = 0x0u;
		__mka_109(22,__context__) = 0x0u;
		__mka_109(23,__context__) = 0x0u;
		__mka_109(24,__context__) = 0x0u;
		__mka_109(25,__context__) = 0x0u;
		__mka_109(26,__context__) = 0x0u;
		__mka_109(27,__context__) = 0x0u;
		__mka_109(28,__context__) = 0x0u;
		__mka_109(29,__context__) = 0x0u;
		__mka_109(30,__context__) = 0x0u;
		__mka_109(31,__context__) = 0x0u;
		__mka_109(32,__context__) = 0x0u;
		__mka_109(33,__context__) = 0x0u;
		__mka_109(34,__context__) = 0x0u;
		__mka_109(35,__context__) = 0x0u;
		__mka_109(36,__context__) = 0x0u;
		__mka_109(37,__context__) = 0x0u;
		__mka_109(38,__context__) = 0x0u;
		__mka_109(39,__context__) = 0x0u;
		__mka_109(40,__context__) = 0x0u;
		__mka_109(41,__context__) = 0x0u;
		__mka_109(42,__context__) = 0x0u;
		__mka_109(43,__context__) = 0x0u;
		__mka_109(44,__context__) = 0x0u;
		__mka_109(45,__context__) = 0x0u;
		__mka_109(46,__context__) = 0x0u;
		__mka_109(47,__context__) = 0x0u;
		__mka_109(48,__context__) = 0x0u;
		__mka_109(49,__context__) = 0x0u;
		__mka_109(50,__context__) = 0x0u;
		__mka_109(51,__context__) = 0x0u;
		__mka_109(52,__context__) = 0x0u;
		__mka_109(53,__context__) = 0x0u;
		__mka_109(54,__context__) = 0x0u;
		__mka_109(55,__context__) = 0x0u;
		__mka_109(56,__context__) = 0x0u;
		__mka_109(57,__context__) = 0x0u;
		__mka_109(58,__context__) = 0x0u;
		__mka_109(59,__context__) = 0x0u;
		__mka_109(60,__context__) = 0x0u;
		__mka_109(61,__context__) = 0x0u;
		__mka_109(62,__context__) = 0x0u;
		__mka_109(63,__context__) = 0x0u;
		__mka_109(64,__context__) = 0x0u;
		__mka_109(65,__context__) = 0x0u;
		__mka_109(66,__context__) = 0x0u;
		__mka_109(67,__context__) = 0x0u;
		__mka_109(68,__context__) = 0x0u;
		__mka_109(69,__context__) = 0x0u;
		__mka_109(70,__context__) = 0x0u;
		__mka_109(71,__context__) = 0x0u;
		__mka_109(72,__context__) = 0x0u;
		__mka_109(73,__context__) = 0x0u;
		__mka_109(74,__context__) = 0x0u;
		__mka_109(75,__context__) = 0x0u;
		__mka_109(76,__context__) = 0x0u;
		__mka_109(77,__context__) = 0x0u;
		__mka_109(78,__context__) = 0x0u;
		__mka_109(79,__context__) = 0x0u;
		__mka_109(80,__context__) = 0x0u;
		__mka_109(81,__context__) = 0x0u;
		__mka_109(82,__context__) = 0x0u;
		__mka_109(83,__context__) = 0x0u;
		__mka_109(84,__context__) = 0x0u;
		__mka_109(85,__context__) = 0x0u;
		__mka_109(86,__context__) = 0x0u;
		__mka_109(87,__context__) = 0x0u;
		__mka_109(88,__context__) = 0x0u;
		__mka_109(89,__context__) = 0x0u;
		__mka_109(90,__context__) = 0x0u;
		__mka_109(91,__context__) = 0x0u;
		__mka_109(92,__context__) = 0x0u;
		__mka_109(93,__context__) = 0x0u;
		__mka_109(94,__context__) = 0x0u;
		__mka_109(95,__context__) = 0x0u;
		__mka_109(96,__context__) = 0x0u;
		__mka_109(97,__context__) = 0x0u;
		__mka_109(98,__context__) = 0x0u;
		__mka_109(99,__context__) = 0x0u;
		__mka_109(100,__context__) = 0x0u;
		__mka_109(101,__context__) = 0x0u;
		__mka_109(102,__context__) = 0x0u;
		__mka_109(103,__context__) = 0x0u;
		__mka_109(104,__context__) = 0x0u;
		__mka_109(105,__context__) = 0x0u;
		__mka_109(106,__context__) = 0x0u;
		__mka_109(107,__context__) = 0x0u;
		__mka_109(108,__context__) = 0x0u;
		__mka_109(109,__context__) = 0x0u;
		__mka_109(110,__context__) = 0x0u;
		__mka_109(111,__context__) = 0x0u;
		__mka_109(112,__context__) = 0x0u;
		__mka_109(113,__context__) = 0x0u;
		__mka_109(114,__context__) = 0x0u;
		__mka_109(115,__context__) = 0x0u;
		__mka_109(116,__context__) = 0x0u;
		__mka_109(117,__context__) = 0x0u;
		__mka_109(118,__context__) = 0x0u;
		__mka_109(119,__context__) = 0x0u;
		__mka_109(120,__context__) = 0x0u;
		__mka_109(121,__context__) = 0x0u;
		__mka_109(122,__context__) = 0x0u;
		__mka_109(123,__context__) = 0x0u;
		__mka_109(124,__context__) = 0x0u;
		__mka_109(125,__context__) = 0x0u;
		__mka_109(126,__context__) = 0x0u;
		__mka_109(127,__context__) = 0x0u;
		__mka_109(128,__context__) = 0x1u;
		__mka_109(129,__context__) = 0x1u;
		__mka_109(130,__context__) = 0x1u;
		__mka_109(131,__context__) = 0x1u;
		__mka_109(132,__context__) = 0x1u;
		__mka_109(133,__context__) = 0x1u;
		__mka_109(134,__context__) = 0x1u;
		__mka_109(135,__context__) = 0x1u;
		__mka_109(136,__context__) = 0x1u;
		__mka_109(137,__context__) = 0x1u;
		__mka_109(138,__context__) = 0x1u;
		__mka_109(139,__context__) = 0x1u;
		__mka_109(140,__context__) = 0x1u;
		__mka_109(141,__context__) = 0x1u;
		__mka_109(142,__context__) = 0x1u;
		__mka_109(143,__context__) = 0x1u;
		__mka_109(144,__context__) = 0x9u;
		__mka_109(145,__context__) = 0x9u;
		__mka_109(146,__context__) = 0x9u;
		__mka_109(147,__context__) = 0x9u;
		__mka_109(148,__context__) = 0x9u;
		__mka_109(149,__context__) = 0x9u;
		__mka_109(150,__context__) = 0x9u;
		__mka_109(151,__context__) = 0x9u;
		__mka_109(152,__context__) = 0x9u;
		__mka_109(153,__context__) = 0x9u;
		__mka_109(154,__context__) = 0x9u;
		__mka_109(155,__context__) = 0x9u;
		__mka_109(156,__context__) = 0x9u;
		__mka_109(157,__context__) = 0x9u;
		__mka_109(158,__context__) = 0x9u;
		__mka_109(159,__context__) = 0x9u;
		__mka_109(160,__context__) = 0x7u;
		__mka_109(161,__context__) = 0x7u;
		__mka_109(162,__context__) = 0x7u;
		__mka_109(163,__context__) = 0x7u;
		__mka_109(164,__context__) = 0x7u;
		__mka_109(165,__context__) = 0x7u;
		__mka_109(166,__context__) = 0x7u;
		__mka_109(167,__context__) = 0x7u;
		__mka_109(168,__context__) = 0x7u;
		__mka_109(169,__context__) = 0x7u;
		__mka_109(170,__context__) = 0x7u;
		__mka_109(171,__context__) = 0x7u;
		__mka_109(172,__context__) = 0x7u;
		__mka_109(173,__context__) = 0x7u;
		__mka_109(174,__context__) = 0x7u;
		__mka_109(175,__context__) = 0x7u;
		__mka_109(176,__context__) = 0x7u;
		__mka_109(177,__context__) = 0x7u;
		__mka_109(178,__context__) = 0x7u;
		__mka_109(179,__context__) = 0x7u;
		__mka_109(180,__context__) = 0x7u;
		__mka_109(181,__context__) = 0x7u;
		__mka_109(182,__context__) = 0x7u;
		__mka_109(183,__context__) = 0x7u;
		__mka_109(184,__context__) = 0x7u;
		__mka_109(185,__context__) = 0x7u;
		__mka_109(186,__context__) = 0x7u;
		__mka_109(187,__context__) = 0x7u;
		__mka_109(188,__context__) = 0x7u;
		__mka_109(189,__context__) = 0x7u;
		__mka_109(190,__context__) = 0x7u;
		__mka_109(191,__context__) = 0x7u;
		__mka_109(192,__context__) = 0x8u;
		__mka_109(193,__context__) = 0x8u;
		__mka_109(194,__context__) = 0x2u;
		__mka_109(195,__context__) = 0x2u;
		__mka_109(196,__context__) = 0x2u;
		__mka_109(197,__context__) = 0x2u;
		__mka_109(198,__context__) = 0x2u;
		__mka_109(199,__context__) = 0x2u;
		__mka_109(200,__context__) = 0x2u;
		__mka_109(201,__context__) = 0x2u;
		__mka_109(202,__context__) = 0x2u;
		__mka_109(203,__context__) = 0x2u;
		__mka_109(204,__context__) = 0x2u;
		__mka_109(205,__context__) = 0x2u;
		__mka_109(206,__context__) = 0x2u;
		__mka_109(207,__context__) = 0x2u;
		__mka_109(208,__context__) = 0x2u;
		__mka_109(209,__context__) = 0x2u;
		__mka_109(210,__context__) = 0x2u;
		__mka_109(211,__context__) = 0x2u;
		__mka_109(212,__context__) = 0x2u;
		__mka_109(213,__context__) = 0x2u;
		__mka_109(214,__context__) = 0x2u;
		__mka_109(215,__context__) = 0x2u;
		__mka_109(216,__context__) = 0x2u;
		__mka_109(217,__context__) = 0x2u;
		__mka_109(218,__context__) = 0x2u;
		__mka_109(219,__context__) = 0x2u;
		__mka_109(220,__context__) = 0x2u;
		__mka_109(221,__context__) = 0x2u;
		__mka_109(222,__context__) = 0x2u;
		__mka_109(223,__context__) = 0x2u;
		__mka_109(224,__context__) = 0xau;
		__mka_109(225,__context__) = 0x3u;
		__mka_109(226,__context__) = 0x3u;
		__mka_109(227,__context__) = 0x3u;
		__mka_109(228,__context__) = 0x3u;
		__mka_109(229,__context__) = 0x3u;
		__mka_109(230,__context__) = 0x3u;
		__mka_109(231,__context__) = 0x3u;
		__mka_109(232,__context__) = 0x3u;
		__mka_109(233,__context__) = 0x3u;
		__mka_109(234,__context__) = 0x3u;
		__mka_109(235,__context__) = 0x3u;
		__mka_109(236,__context__) = 0x3u;
		__mka_109(237,__context__) = 0x4u;
		__mka_109(238,__context__) = 0x3u;
		__mka_109(239,__context__) = 0x3u;
		__mka_109(240,__context__) = 0xbu;
		__mka_109(241,__context__) = 0x6u;
		__mka_109(242,__context__) = 0x6u;
		__mka_109(243,__context__) = 0x6u;
		__mka_109(244,__context__) = 0x5u;
		__mka_109(245,__context__) = 0x8u;
		__mka_109(246,__context__) = 0x8u;
		__mka_109(247,__context__) = 0x8u;
		__mka_109(248,__context__) = 0x8u;
		__mka_109(249,__context__) = 0x8u;
		__mka_109(250,__context__) = 0x8u;
		__mka_109(251,__context__) = 0x8u;
		__mka_109(252,__context__) = 0x8u;
		__mka_109(253,__context__) = 0x8u;
		__mka_109(254,__context__) = 0x8u;
		__mka_109(255,__context__) = 0x8u;
		__mka_109(256,__context__) = 0x0u;
		__mka_109(257,__context__) = 0xcu;
		__mka_109(258,__context__) = 0x18u;
		__mka_109(259,__context__) = 0x24u;
		__mka_109(260,__context__) = 0x3cu;
		__mka_109(261,__context__) = 0x60u;
		__mka_109(262,__context__) = 0x54u;
		__mka_109(263,__context__) = 0xcu;
		__mka_109(264,__context__) = 0xcu;
		__mka_109(265,__context__) = 0xcu;
		__mka_109(266,__context__) = 0x30u;
		__mka_109(267,__context__) = 0x48u;
		__mka_109(268,__context__) = 0xcu;
		__mka_109(269,__context__) = 0xcu;
		__mka_109(270,__context__) = 0xcu;
		__mka_109(271,__context__) = 0xcu;
		__mka_109(272,__context__) = 0xcu;
		__mka_109(273,__context__) = 0xcu;
		__mka_109(274,__context__) = 0xcu;
		__mka_109(275,__context__) = 0xcu;
		__mka_109(276,__context__) = 0xcu;
		__mka_109(277,__context__) = 0xcu;
		__mka_109(278,__context__) = 0xcu;
		__mka_109(279,__context__) = 0xcu;
		__mka_109(280,__context__) = 0xcu;
		__mka_109(281,__context__) = 0x0u;
		__mka_109(282,__context__) = 0xcu;
		__mka_109(283,__context__) = 0xcu;
		__mka_109(284,__context__) = 0xcu;
		__mka_109(285,__context__) = 0xcu;
		__mka_109(286,__context__) = 0xcu;
		__mka_109(287,__context__) = 0x0u;
		__mka_109(288,__context__) = 0xcu;
		__mka_109(289,__context__) = 0x0u;
		__mka_109(290,__context__) = 0xcu;
		__mka_109(291,__context__) = 0xcu;
		__mka_109(292,__context__) = 0xcu;
		__mka_109(293,__context__) = 0x18u;
		__mka_109(294,__context__) = 0xcu;
		__mka_109(295,__context__) = 0xcu;
		__mka_109(296,__context__) = 0xcu;
		__mka_109(297,__context__) = 0xcu;
		__mka_109(298,__context__) = 0xcu;
		__mka_109(299,__context__) = 0x18u;
		__mka_109(300,__context__) = 0xcu;
		__mka_109(301,__context__) = 0x18u;
		__mka_109(302,__context__) = 0xcu;
		__mka_109(303,__context__) = 0xcu;
		__mka_109(304,__context__) = 0xcu;
		__mka_109(305,__context__) = 0xcu;
		__mka_109(306,__context__) = 0xcu;
		__mka_109(307,__context__) = 0xcu;
		__mka_109(308,__context__) = 0xcu;
		__mka_109(309,__context__) = 0xcu;
		__mka_109(310,__context__) = 0xcu;
		__mka_109(311,__context__) = 0x18u;
		__mka_109(312,__context__) = 0xcu;
		__mka_109(313,__context__) = 0xcu;
		__mka_109(314,__context__) = 0xcu;
		__mka_109(315,__context__) = 0xcu;
		__mka_109(316,__context__) = 0xcu;
		__mka_109(317,__context__) = 0x18u;
		__mka_109(318,__context__) = 0xcu;
		__mka_109(319,__context__) = 0xcu;
		__mka_109(320,__context__) = 0xcu;
		__mka_109(321,__context__) = 0xcu;
		__mka_109(322,__context__) = 0xcu;
		__mka_109(323,__context__) = 0xcu;
		__mka_109(324,__context__) = 0xcu;
		__mka_109(325,__context__) = 0x18u;
		__mka_109(326,__context__) = 0xcu;
		__mka_109(327,__context__) = 0xcu;
		__mka_109(328,__context__) = 0xcu;
		__mka_109(329,__context__) = 0xcu;
		__mka_109(330,__context__) = 0xcu;
		__mka_109(331,__context__) = 0xcu;
		__mka_109(332,__context__) = 0xcu;
		__mka_109(333,__context__) = 0xcu;
		__mka_109(334,__context__) = 0xcu;
		__mka_109(335,__context__) = 0x24u;
		__mka_109(336,__context__) = 0xcu;
		__mka_109(337,__context__) = 0x24u;
		__mka_109(338,__context__) = 0xcu;
		__mka_109(339,__context__) = 0xcu;
		__mka_109(340,__context__) = 0xcu;
		__mka_109(341,__context__) = 0x24u;
		__mka_109(342,__context__) = 0xcu;
		__mka_109(343,__context__) = 0xcu;
		__mka_109(344,__context__) = 0xcu;
		__mka_109(345,__context__) = 0xcu;
		__mka_109(346,__context__) = 0xcu;
		__mka_109(347,__context__) = 0x24u;
		__mka_109(348,__context__) = 0xcu;
		__mka_109(349,__context__) = 0x24u;
		__mka_109(350,__context__) = 0xcu;
		__mka_109(351,__context__) = 0xcu;
		__mka_109(352,__context__) = 0xcu;
		__mka_109(353,__context__) = 0x24u;
		__mka_109(354,__context__) = 0xcu;
		__mka_109(355,__context__) = 0xcu;
		__mka_109(356,__context__) = 0xcu;
		__mka_109(357,__context__) = 0xcu;
		__mka_109(358,__context__) = 0xcu;
		__mka_109(359,__context__) = 0xcu;
		__mka_109(360,__context__) = 0xcu;
		__mka_109(361,__context__) = 0xcu;
		__mka_109(362,__context__) = 0xcu;
		__mka_109(363,__context__) = 0xcu;
		return __mka_109;
	})());/*s_utf8d*/
	das_global<uint32_t,0x32e75a6a55963340>(__context__) = 0x0u;/*UTF8_ACCEPT*/
}

inline int32_t _FuncbuiltinTicklength_59b92f62e07969bc ( Context * __context__, TDim<uint8_t,2> const  &  __a_rename_at_267_0 )
{
	return das_auto_cast<int32_t>::cast(2);
}

inline int32_t _FuncbuiltinTicklength_1cf5c98666586392 ( Context * __context__, TDim<uint8_t,3> const  &  __a_rename_at_267_1 )
{
	return das_auto_cast<int32_t>::cast(3);
}

inline int32_t _FuncbuiltinTicklength_7305224819e13b88 ( Context * __context__, TDim<uint8_t,4> const  &  __a_rename_at_267_2 )
{
	return das_auto_cast<int32_t>::cast(4);
}

inline int32_t _FuncbuiltinTicklength_34e69ed4aa0e945a ( Context * __context__, TDim<uint8_t,1> const  &  __a_rename_at_267_3 )
{
	return das_auto_cast<int32_t>::cast(1);
}

inline TArray<uint8_t> _FuncbuiltinTickto_array_move_bdc5580b138debbb ( Context * __context__, TDim<uint8_t,2> &  __a_rename_at_668_4 )
{
	TArray<uint8_t> __arr_rename_at_670_5; das_zero(__arr_rename_at_670_5);
	_FuncbuiltinTickresize_4c98a9f12906ee43(__context__,das_arg<TArray<uint8_t>>::pass(__arr_rename_at_670_5),2);
	das_copy(das_cast<TDim<uint8_t,2>>::cast(das_ref(__context__,__arr_rename_at_670_5(0,__context__))),__a_rename_at_668_4);
	return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(__arr_rename_at_670_5);
}

inline TArray<uint8_t> _FuncbuiltinTickto_array_move_e577077924e1c08f ( Context * __context__, TDim<uint8_t,3> &  __a_rename_at_668_6 )
{
	TArray<uint8_t> __arr_rename_at_670_7; das_zero(__arr_rename_at_670_7);
	_FuncbuiltinTickresize_4c98a9f12906ee43(__context__,das_arg<TArray<uint8_t>>::pass(__arr_rename_at_670_7),3);
	das_copy(das_cast<TDim<uint8_t,3>>::cast(das_ref(__context__,__arr_rename_at_670_7(0,__context__))),__a_rename_at_668_6);
	return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(__arr_rename_at_670_7);
}

inline TArray<uint8_t> _FuncbuiltinTickto_array_move_48ce32e961537be7 ( Context * __context__, TDim<uint8_t,4> &  __a_rename_at_668_8 )
{
	TArray<uint8_t> __arr_rename_at_670_9; das_zero(__arr_rename_at_670_9);
	_FuncbuiltinTickresize_4c98a9f12906ee43(__context__,das_arg<TArray<uint8_t>>::pass(__arr_rename_at_670_9),4);
	das_copy(das_cast<TDim<uint8_t,4>>::cast(das_ref(__context__,__arr_rename_at_670_9(0,__context__))),__a_rename_at_668_8);
	return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(__arr_rename_at_670_9);
}

inline TArray<uint8_t> _FuncbuiltinTickto_array_move_e86300f468fc8fcb ( Context * __context__, TDim<uint8_t,1> &  __a_rename_at_668_10 )
{
	TArray<uint8_t> __arr_rename_at_670_11; das_zero(__arr_rename_at_670_11);
	_FuncbuiltinTickresize_4c98a9f12906ee43(__context__,das_arg<TArray<uint8_t>>::pass(__arr_rename_at_670_11),1);
	das_copy(das_cast<TDim<uint8_t,1>>::cast(das_ref(__context__,__arr_rename_at_670_11(0,__context__))),__a_rename_at_668_10);
	return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(__arr_rename_at_670_11);
}

inline TArray<uint8_t> & _FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef ( Context * __context__, TArray<uint8_t> &  __a_rename_at_38_12 )
{
	das_call_interop<void>::call(&builtin_verify_locks,__context__,SimNode_AotInterop<1>(__tinfo_0,cast<TArray<uint8_t> &>::from(__a_rename_at_38_12)));
	return das_auto_cast_ref<TArray<uint8_t> &>::cast(__a_rename_at_38_12);
}

inline TArray<uint32_t> & _FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b ( Context * __context__, TArray<uint32_t> &  __a_rename_at_38_13 )
{
	das_call_interop<void>::call(&builtin_verify_locks,__context__,SimNode_AotInterop<1>(__tinfo_1,cast<TArray<uint32_t> &>::from(__a_rename_at_38_13)));
	return das_auto_cast_ref<TArray<uint32_t> &>::cast(__a_rename_at_38_13);
}

inline void _FuncbuiltinTickpush_96b6a7003d9304b3 ( Context * __context__, TArray<uint8_t> &  __Arr_rename_at_79_14, uint8_t __value_rename_at_79_15 )
{
	das_copy(__Arr_rename_at_79_14(builtin_array_push_back(das_arg<TArray<uint8_t>>::pass(__Arr_rename_at_79_14),1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_15);
}

inline void _FuncbuiltinTickreserve_1163d4031687d985 ( Context * __context__, TArray<uint8_t> &  __Arr_rename_at_63_16, int32_t __newSize_rename_at_63_17 )
{
	builtin_array_reserve(das_arg<TArray<uint8_t>>::pass(__Arr_rename_at_63_16),__newSize_rename_at_63_17,1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickpush_3d8e11693091805e ( Context * __context__, TArray<uint32_t> &  __Arr_rename_at_79_18, uint32_t __value_rename_at_79_19 )
{
	das_copy(__Arr_rename_at_79_18(builtin_array_push_back(das_arg<TArray<uint32_t>>::pass(__Arr_rename_at_79_18),4,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_19);
}

inline void _FuncbuiltinTickresize_4c98a9f12906ee43 ( Context * __context__, TArray<uint8_t> &  __Arr_rename_at_50_20, int32_t __newSize_rename_at_50_21 )
{
	builtin_array_resize(das_arg<TArray<uint8_t>>::pass(__Arr_rename_at_50_20),__newSize_rename_at_50_21,1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline uint32_t utf16_to_utf32_2c85c7ce7b90cf66 ( Context * __context__, uint32_t __high_rename_at_9_22, uint32_t __low_rename_at_9_23 )
{
	return das_auto_cast<uint32_t>::cast(((__high_rename_at_9_22 >= 0xd800u) && (__high_rename_at_9_22 <= 0xdbffu)) ? das_auto_cast<uint32_t>::cast(((((__high_rename_at_9_22 - 0xd800u) << 0xau) + (__low_rename_at_9_23 - 0xdc00u)) + 0x10000u)) : das_auto_cast<uint32_t>::cast(__high_rename_at_9_22));
}

inline void utf8_encode_5ea3a6cf711d0b53 ( Context * __context__, TArray<uint8_t> &  __dest_array_rename_at_15_24, uint32_t __ch_rename_at_15_25 )
{
	if ( __ch_rename_at_15_25 < 0x80u )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t(__ch_rename_at_15_25));
	} else if ( __ch_rename_at_15_25 < 0x800u )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 >> 0x6u) + 0xc0u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 & 0x3fu) + 0x80u));
	} else if ( __ch_rename_at_15_25 < 0x10000u )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 >> 0xcu) + 0xe0u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t(((__ch_rename_at_15_25 >> 0x6u) & 0x3fu) + 0x80u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 & 0x3fu) + 0x80u));
	} else {
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 >> 0x12u) + 0xf0u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t(((__ch_rename_at_15_25 >> 0xcu) & 0x3fu) + 0x80u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t(((__ch_rename_at_15_25 >> 0x6u) & 0x3fu) + 0x80u));
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_15_24),uint8_t((__ch_rename_at_15_25 & 0x3fu) + 0x80u));
	};
}

inline TArray<uint8_t> utf8_encode_fe9a2c6d855320bd ( Context * __context__, uint32_t __ch_rename_at_33_26 )
{
	if ( __ch_rename_at_33_26 < 0x80u )
	{
		TArray<uint8_t> _temp_make_local_36_18_32; _temp_make_local_36_18_32;
		TDim<uint8_t,1> _temp_make_local_36_18_64; _temp_make_local_36_18_64;
		return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef(__context__,das_arg<TArray<uint8_t>>::pass((_temp_make_local_36_18_32 = (_FuncbuiltinTickto_array_move_e86300f468fc8fcb(__context__,das_arg<TDim<uint8_t,1>>::pass((([&]() -> TDim<uint8_t,1>& {
			_temp_make_local_36_18_64(0,__context__) = uint8_t(__ch_rename_at_33_26);
			return _temp_make_local_36_18_64;
		})()))))))));
	} else if ( __ch_rename_at_33_26 < 0x800u )
	{
		TArray<uint8_t> _temp_make_local_38_18_80; _temp_make_local_38_18_80;
		TDim<uint8_t,2> _temp_make_local_38_18_112; _temp_make_local_38_18_112;
		return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef(__context__,das_arg<TArray<uint8_t>>::pass((_temp_make_local_38_18_80 = (_FuncbuiltinTickto_array_move_bdc5580b138debbb(__context__,das_arg<TDim<uint8_t,2>>::pass((([&]() -> TDim<uint8_t,2>& {
			_temp_make_local_38_18_112(0,__context__) = uint8_t((__ch_rename_at_33_26 >> 0x6u) + 0xc0u);
			_temp_make_local_38_18_112(1,__context__) = uint8_t((__ch_rename_at_33_26 & 0x3fu) + 0x80u);
			return _temp_make_local_38_18_112;
		})()))))))));
	} else if ( __ch_rename_at_33_26 < 0x10000u )
	{
		TArray<uint8_t> _temp_make_local_42_18_128; _temp_make_local_42_18_128;
		TDim<uint8_t,3> _temp_make_local_42_18_160; _temp_make_local_42_18_160;
		return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef(__context__,das_arg<TArray<uint8_t>>::pass((_temp_make_local_42_18_128 = (_FuncbuiltinTickto_array_move_e577077924e1c08f(__context__,das_arg<TDim<uint8_t,3>>::pass((([&]() -> TDim<uint8_t,3>& {
			_temp_make_local_42_18_160(0,__context__) = uint8_t((__ch_rename_at_33_26 >> 0xcu) + 0xe0u);
			_temp_make_local_42_18_160(1,__context__) = uint8_t(((__ch_rename_at_33_26 >> 0x6u) & 0x3fu) + 0x80u);
			_temp_make_local_42_18_160(2,__context__) = uint8_t((__ch_rename_at_33_26 & 0x3fu) + 0x80u);
			return _temp_make_local_42_18_160;
		})()))))))));
	} else {
		TArray<uint8_t> _temp_make_local_47_18_176; _temp_make_local_47_18_176;
		TDim<uint8_t,4> _temp_make_local_47_18_208; _temp_make_local_47_18_208;
		return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef(__context__,das_arg<TArray<uint8_t>>::pass((_temp_make_local_47_18_176 = (_FuncbuiltinTickto_array_move_48ce32e961537be7(__context__,das_arg<TDim<uint8_t,4>>::pass((([&]() -> TDim<uint8_t,4>& {
			_temp_make_local_47_18_208(0,__context__) = uint8_t((__ch_rename_at_33_26 >> 0x12u) + 0xf0u);
			_temp_make_local_47_18_208(1,__context__) = uint8_t(((__ch_rename_at_33_26 >> 0xcu) & 0x3fu) + 0x80u);
			_temp_make_local_47_18_208(2,__context__) = uint8_t(((__ch_rename_at_33_26 >> 0x6u) & 0x3fu) + 0x80u);
			_temp_make_local_47_18_208(3,__context__) = uint8_t((__ch_rename_at_33_26 & 0x3fu) + 0x80u);
			return _temp_make_local_47_18_208;
		})()))))))));
	};
}

inline void utf8_encode_95f1494bc2b6ed49 ( Context * __context__, TArray<uint8_t> &  __dest_array_rename_at_54_27, TArray<uint32_t> const  &  __source_utf32_string_rename_at_54_28 )
{
	{
		bool __need_loop_56 = true;
		// ch : uint const&
		das_iterator<TArray<uint32_t> const > __ch_iterator(__source_utf32_string_rename_at_54_28);
		uint32_t const  * __ch_rename_at_56_29;
		__need_loop_56 = __ch_iterator.first(__context__,(__ch_rename_at_56_29)) && __need_loop_56;
		for ( ; __need_loop_56 ; __need_loop_56 = __ch_iterator.next(__context__,(__ch_rename_at_56_29)) )
		{
			utf8_encode_5ea3a6cf711d0b53(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_54_27),(*__ch_rename_at_56_29));
		}
		__ch_iterator.close(__context__,(__ch_rename_at_56_29));
	};
}

inline TArray<uint8_t> utf8_encode_2dfdb6c0c0665fee ( Context * __context__, TArray<uint32_t> const  &  __source_utf32_string_rename_at_60_30 )
{
	TArray<uint8_t> __dest_array_rename_at_62_31; das_zero(__dest_array_rename_at_62_31);
	_FuncbuiltinTickreserve_1163d4031687d985(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_62_31),builtin_array_size(__source_utf32_string_rename_at_60_30));
	{
		bool __need_loop_64 = true;
		// ch : uint const&
		das_iterator<TArray<uint32_t> const > __ch_iterator(__source_utf32_string_rename_at_60_30);
		uint32_t const  * __ch_rename_at_64_32;
		__need_loop_64 = __ch_iterator.first(__context__,(__ch_rename_at_64_32)) && __need_loop_64;
		for ( ; __need_loop_64 ; __need_loop_64 = __ch_iterator.next(__context__,(__ch_rename_at_64_32)) )
		{
			utf8_encode_5ea3a6cf711d0b53(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_62_31),(*__ch_rename_at_64_32));
		}
		__ch_iterator.close(__context__,(__ch_rename_at_64_32));
	};
	return /* <- */ das_auto_cast_move<TArray<uint8_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef(__context__,das_arg<TArray<uint8_t>>::pass(__dest_array_rename_at_62_31)));
}

inline int32_t utf8_length_362d2fb098289bdc ( Context * __context__, TArray<uint8_t> const  &  __utf8_string_rename_at_69_33 )
{
	int32_t __length_rename_at_71_34 = 0;
	{
		bool __need_loop_72 = true;
		// ch : uint8 const&
		das_iterator<TArray<uint8_t> const > __ch_iterator(__utf8_string_rename_at_69_33);
		uint8_t const  * __ch_rename_at_72_35;
		__need_loop_72 = __ch_iterator.first(__context__,(__ch_rename_at_72_35)) && __need_loop_72;
		for ( ; __need_loop_72 ; __need_loop_72 = __ch_iterator.next(__context__,(__ch_rename_at_72_35)) )
		{
			if ( (uint32_t((*__ch_rename_at_72_35)) & 0xc0u) != 0x80u )
			{
				++__length_rename_at_71_34;
			};
		}
		__ch_iterator.close(__context__,(__ch_rename_at_72_35));
	};
	return das_auto_cast<int32_t>::cast(__length_rename_at_71_34);
}

inline int32_t utf8_length_1e6f8ee224ef4bd2 ( Context * __context__, char * const  __utf8_string_rename_at_78_36 )
{
	int32_t __length_rename_at_80_37 = 0;
	{
		bool __need_loop_81 = true;
		// ch : int const
		das_iterator<char * const > __ch_iterator(__utf8_string_rename_at_78_36);
		int32_t __ch_rename_at_81_38;
		__need_loop_81 = __ch_iterator.first(__context__,(__ch_rename_at_81_38)) && __need_loop_81;
		for ( ; __need_loop_81 ; __need_loop_81 = __ch_iterator.next(__context__,(__ch_rename_at_81_38)) )
		{
			if ( (uint32_t(__ch_rename_at_81_38) & 0xc0u) != 0x80u )
			{
				++__length_rename_at_80_37;
			};
		}
		__ch_iterator.close(__context__,(__ch_rename_at_81_38));
	};
	return das_auto_cast<int32_t>::cast(__length_rename_at_80_37);
}

inline bool is_first_byte_of_utf8_char_ec644bb641f9e7a4 ( Context * __context__, uint8_t __ch_rename_at_87_39 )
{
	uint32_t __x_rename_at_88_40 = ((uint32_t)uint32_t(__ch_rename_at_87_39));
	return das_auto_cast<bool>::cast((__x_rename_at_88_40 > 0x0u) && ((__x_rename_at_88_40 < 0x80u) || ((__x_rename_at_88_40 & 0xc0u) == 0xc0u)));
}

inline bool contains_utf8_bom_fac11c0fbdbb944f ( Context * __context__, TArray<uint8_t> const  &  __utf8_string_rename_at_92_41 )
{
	return das_auto_cast<bool>::cast((((builtin_array_size(__utf8_string_rename_at_92_41) >= 3) && (uint32_t(__utf8_string_rename_at_92_41(0,__context__)) == 0xefu)) && (uint32_t(__utf8_string_rename_at_92_41(1,__context__)) == 0xbbu)) && (uint32_t(__utf8_string_rename_at_92_41(2,__context__)) == 0xbfu));
}

inline bool contains_utf8_bom_9f371025b0516edc ( Context * __context__, char * const  __utf8_string_rename_at_97_42 )
{
	return das_auto_cast<bool>::cast(((!(builtin_empty(__utf8_string_rename_at_97_42)) && (uint32_t(get_character_uat(__utf8_string_rename_at_97_42,0)) == 0xefu)) && (uint32_t(get_character_uat(__utf8_string_rename_at_97_42,1)) == 0xbbu)) && (uint32_t(get_character_uat(__utf8_string_rename_at_97_42,2)) == 0xbfu));
}

inline bool is_utf8_string_valid_221552b9eafc590a ( Context * __context__, TArray<uint8_t> const  &  __utf8_string_rename_at_133_43 )
{
	uint32_t __codepoint_rename_at_134_44 = 0x0u;
	uint32_t __state_rename_at_135_45 = 0x0u;
	{
		bool __need_loop_136 = true;
		// ch : uint8 const&
		das_iterator<TArray<uint8_t> const > __ch_iterator(__utf8_string_rename_at_133_43);
		uint8_t const  * __ch_rename_at_136_46;
		__need_loop_136 = __ch_iterator.first(__context__,(__ch_rename_at_136_46)) && __need_loop_136;
		for ( ; __need_loop_136 ; __need_loop_136 = __ch_iterator.next(__context__,(__ch_rename_at_136_46)) )
		{
			uint32_t __byte_rename_at_137_47 = ((uint32_t)uint32_t((*__ch_rename_at_136_46)));
			uint32_t __type__rename_at_138_48 = ((uint32_t)das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(__byte_rename_at_137_47,__context__));
			das_copy(__codepoint_rename_at_134_44,(__state_rename_at_135_45 != 0x0u) ? das_auto_cast<uint32_t>::cast(((__byte_rename_at_137_47 & 0x3fu) | (__codepoint_rename_at_134_44 << 0x6u))) : das_auto_cast<uint32_t>::cast(((0xffu >> __type__rename_at_138_48) & __byte_rename_at_137_47)));
			das_copy(__state_rename_at_135_45,das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(((__state_rename_at_135_45 + 0x100u) + __type__rename_at_138_48),__context__));
		}
		__ch_iterator.close(__context__,(__ch_rename_at_136_46));
	};
	return das_auto_cast<bool>::cast(__state_rename_at_135_45 == 0x0u);
}

inline bool is_utf8_string_valid_c001bdc037b6eb95 ( Context * __context__, char * const  __utf8_string_rename_at_144_49 )
{
	uint32_t __codepoint_rename_at_145_50 = 0x0u;
	uint32_t __state_rename_at_146_51 = 0x0u;
	{
		bool __need_loop_147 = true;
		// ch : int const
		das_iterator<char * const > __ch_iterator(__utf8_string_rename_at_144_49);
		int32_t __ch_rename_at_147_52;
		__need_loop_147 = __ch_iterator.first(__context__,(__ch_rename_at_147_52)) && __need_loop_147;
		for ( ; __need_loop_147 ; __need_loop_147 = __ch_iterator.next(__context__,(__ch_rename_at_147_52)) )
		{
			uint32_t __byte_rename_at_148_53 = ((uint32_t)uint32_t(__ch_rename_at_147_52));
			uint32_t __type__rename_at_149_54 = ((uint32_t)das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(__byte_rename_at_148_53,__context__));
			das_copy(__codepoint_rename_at_145_50,(__state_rename_at_146_51 != 0x0u) ? das_auto_cast<uint32_t>::cast(((__byte_rename_at_148_53 & 0x3fu) | (__codepoint_rename_at_145_50 << 0x6u))) : das_auto_cast<uint32_t>::cast(((0xffu >> __type__rename_at_149_54) & __byte_rename_at_148_53)));
			das_copy(__state_rename_at_146_51,das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(((__state_rename_at_146_51 + 0x100u) + __type__rename_at_149_54),__context__));
		}
		__ch_iterator.close(__context__,(__ch_rename_at_147_52));
	};
	return das_auto_cast<bool>::cast(__state_rename_at_146_51 == 0x0u);
}

inline void utf8_decode_2bda99fa41022503 ( Context * __context__, TArray<uint32_t> &  __dest_utf32_string_rename_at_155_55, TArray<uint8_t> const  &  __source_utf8_string_rename_at_155_56 )
{
	uint32_t __codepoint_rename_at_157_57 = 0x0u;
	uint32_t __state_rename_at_158_58 = 0x0u;
	int32_t __length_rename_at_159_59 = ((int32_t)builtin_array_size(__source_utf8_string_rename_at_155_56));
	int32_t __i_rename_at_160_60 = (contains_utf8_bom_fac11c0fbdbb944f(__context__,__source_utf8_string_rename_at_155_56) ? das_auto_cast<int32_t>::cast(3) : das_auto_cast<int32_t>::cast(0));
	while ( __i_rename_at_160_60 < __length_rename_at_159_59 )
	{
		uint32_t __byte_rename_at_163_61 = ((uint32_t)uint32_t(__source_utf8_string_rename_at_155_56(__i_rename_at_160_60++,__context__)));
		uint32_t __type__rename_at_164_62 = ((uint32_t)das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(__byte_rename_at_163_61,__context__));
		das_copy(__codepoint_rename_at_157_57,(__state_rename_at_158_58 != 0x0u) ? das_auto_cast<uint32_t>::cast(((__byte_rename_at_163_61 & 0x3fu) | (__codepoint_rename_at_157_57 << 0x6u))) : das_auto_cast<uint32_t>::cast(((0xffu >> __type__rename_at_164_62) & __byte_rename_at_163_61)));
		das_copy(__state_rename_at_158_58,das_shared<TDim<uint32_t,364>,0x28a2e6c17bde423c>(__context__) /*s_utf8d*/(((__state_rename_at_158_58 + 0x100u) + __type__rename_at_164_62),__context__));
		if ( __state_rename_at_158_58 == 0x0u )
		{
			_FuncbuiltinTickpush_3d8e11693091805e(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_155_55),__codepoint_rename_at_157_57);
		};
	};
}

inline TArray<uint32_t> utf8_decode_6daf598a4fe1ed4 ( Context * __context__, TArray<uint8_t> const  &  __source_utf8_string_rename_at_171_63 )
{
	TArray<uint32_t> __dest_utf32_string_rename_at_173_64; das_zero(__dest_utf32_string_rename_at_173_64);
	utf8_decode_2bda99fa41022503(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_173_64),__source_utf8_string_rename_at_171_63);
	return /* <- */ das_auto_cast_move<TArray<uint32_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_173_64)));
}

inline TArray<uint32_t> utf8_decode_9bde921137fa170 ( Context * __context__, char * const  __source_utf8_string_rename_at_178_65 ) { das_stack_prologue __prologue(__context__,128,"utf8_decode " DAS_FILE_LINE);
{
	TArray<uint32_t> __dest_utf32_string_rename_at_180_66; das_zero(__dest_utf32_string_rename_at_180_66);
	builtin_string_peek(__source_utf8_string_rename_at_178_65,das_make_block<void,TArray<uint8_t> const  &>(__context__,112,0,&__func_info__5f4b6da70ca496e2,[&](TArray<uint8_t> const  & __arr_rename_at_181_67) -> void{
		utf8_decode_2bda99fa41022503(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_180_66),__arr_rename_at_181_67);
	}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<TArray<uint32_t>>::cast(_FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_180_66)));
}}

inline void utf8_decode_4f7738d23733680a ( Context * __context__, TArray<uint32_t> &  __dest_utf32_string_rename_at_186_68, char * const  __source_utf8_string_rename_at_186_69 ) { das_stack_prologue __prologue(__context__,96,"utf8_decode " DAS_FILE_LINE);
{
	builtin_string_peek(__source_utf8_string_rename_at_186_69,das_make_block<void,TArray<uint8_t> const  &>(__context__,80,0,&__func_info__5f4b6da70ca496e2,[&](TArray<uint8_t> const  & __arr_rename_at_188_70) -> void{
		utf8_decode_2bda99fa41022503(__context__,das_arg<TArray<uint32_t>>::pass(__dest_utf32_string_rename_at_186_68),__arr_rename_at_188_70);
	}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}}

inline char * decode_unicode_escape_e2de811e7f2112f5 ( Context * __context__, char * const  __str_rename_at_191_71 ) { das_stack_prologue __prologue(__context__,384,"decode_unicode_escape " DAS_FILE_LINE);
{
	return das_auto_cast<char *>::cast(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_192_72) DAS_AOT_INLINE_LAMBDA -> void{
		builtin_string_peek(__str_rename_at_191_71,das_make_block<void,TArray<uint8_t> const  &>(__context__,144,0,&__func_info__2f76c7f7dd4f0b27,[&](TArray<uint8_t> const  & __p_rename_at_193_73) -> void{
			int32_t __i_rename_at_194_74 = 0;
			int32_t __llen_rename_at_195_75 = ((int32_t)builtin_array_size(__p_rename_at_193_73));
			TArray<uint8_t> __bang_rename_at_196_76; das_zero(__bang_rename_at_196_76);
			_FuncbuiltinTickreserve_1163d4031687d985(__context__,das_arg<TArray<uint8_t>>::pass(__bang_rename_at_196_76),8);
			uint32_t __high_surrogate_rename_at_198_77 = 0x0u;
			while ( __i_rename_at_194_74 < __llen_rename_at_195_75 )
			{
				if ( das_equ_val(__p_rename_at_193_73(__i_rename_at_194_74,__context__),0x5c) )
				{
					int32_t __j_rename_at_201_78 = (__i_rename_at_194_74 + 1);
					int32_t __jlen_rename_at_202_79 = SimPolicy<int32_t>::Min(__llen_rename_at_195_75,__j_rename_at_201_78 + 8,*__context__,nullptr);
					_FuncbuiltinTickresize_4c98a9f12906ee43(__context__,das_arg<TArray<uint8_t>>::pass(__bang_rename_at_196_76),0);
					while ( (__j_rename_at_201_78 < __jlen_rename_at_202_79) && das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),int32_t(__p_rename_at_193_73(__j_rename_at_201_78,__context__))) )
					{
						_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(__bang_rename_at_196_76),__p_rename_at_193_73(__j_rename_at_201_78,__context__));
						++__j_rename_at_201_78;
					};
					if ( builtin_array_size(das_arg<TArray<uint8_t>>::pass(__bang_rename_at_196_76)) == 4 )
					{
						uint32_t __utf32_rename_at_208_80 = ((uint32_t)fast_to_uint(((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass(__bang_rename_at_196_76),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))),true));
						if ( (__utf32_rename_at_208_80 >= 0xd800u) && (__utf32_rename_at_208_80 <= 0xdfffu) )
						{
							if ( __high_surrogate_rename_at_198_77 == 0x0u )
							{
								das_copy(__high_surrogate_rename_at_198_77,__utf32_rename_at_208_80);
							} else {
								TArray<uint8_t> _temp_make_local_216_55_320; _temp_make_local_216_55_320;
								uint32_t __low_surrogate_rename_at_213_81 = ((uint32_t)__utf32_rename_at_208_80);
								uint32_t __pair_rename_at_214_82 = ((uint32_t)((((__high_surrogate_rename_at_198_77 - 0xd800u) << 0xau) + 0x10000u) + (__low_surrogate_rename_at_213_81 - 0xdc00u)));
								das_copy(__high_surrogate_rename_at_198_77,0x0u);
								das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_2,cast<StringBuilderWriter &>::from(__writer_rename_at_192_72),cast<char *>::from(((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass((_temp_make_local_216_55_320 = (utf8_encode_fe9a2c6d855320bd(__context__,__pair_rename_at_214_82)))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))))));
							};
						} else {
							TArray<uint8_t> _temp_make_local_218_51_352; _temp_make_local_218_51_352;
							das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_3,cast<StringBuilderWriter &>::from(__writer_rename_at_192_72),cast<char *>::from(((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass((_temp_make_local_218_51_352 = (utf8_encode_fe9a2c6d855320bd(__context__,__utf32_rename_at_208_80)))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))))));
						};
						das_copy(__i_rename_at_194_74,__j_rename_at_201_78);
						continue;
					};
				};
				write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_192_72),int32_t(__p_rename_at_193_73(__i_rename_at_194_74,__context__)));
				__i_rename_at_194_74 += 1;
			};
		}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncbuiltinTicklength_59b92f62e07969bc
	aotLib[0x7e8fba95796e256a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<uint8_t,2> const  &  ),&_FuncbuiltinTicklength_59b92f62e07969bc>>();
	};
	// _FuncbuiltinTicklength_1cf5c98666586392
	aotLib[0x77b80cb5319c7f7e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<uint8_t,3> const  &  ),&_FuncbuiltinTicklength_1cf5c98666586392>>();
	};
	// _FuncbuiltinTicklength_7305224819e13b88
	aotLib[0xb1593d675c646c3a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<uint8_t,4> const  &  ),&_FuncbuiltinTicklength_7305224819e13b88>>();
	};
	// _FuncbuiltinTicklength_34e69ed4aa0e945a
	aotLib[0xa5538e5cd7c1ddee] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<uint8_t,1> const  &  ),&_FuncbuiltinTicklength_34e69ed4aa0e945a>>();
	};
	// _FuncbuiltinTickto_array_move_bdc5580b138debbb
	aotLib[0xbec4ec5b83d6c152] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, TDim<uint8_t,2> &  ),&_FuncbuiltinTickto_array_move_bdc5580b138debbb>>();
	};
	// _FuncbuiltinTickto_array_move_e577077924e1c08f
	aotLib[0xa81ad3ef81e1ba47] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, TDim<uint8_t,3> &  ),&_FuncbuiltinTickto_array_move_e577077924e1c08f>>();
	};
	// _FuncbuiltinTickto_array_move_48ce32e961537be7
	aotLib[0xf624ca04f791c6c1] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, TDim<uint8_t,4> &  ),&_FuncbuiltinTickto_array_move_48ce32e961537be7>>();
	};
	// _FuncbuiltinTickto_array_move_e86300f468fc8fcb
	aotLib[0xe0ed108c464dc503] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, TDim<uint8_t,1> &  ),&_FuncbuiltinTickto_array_move_e86300f468fc8fcb>>();
	};
	// _FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef
	aotLib[0xbdfb1e7611168f12] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<TArray<uint8_t> & (*) ( Context * __context__, TArray<uint8_t> &  ),&_FuncbuiltinTick_return_with_lockcheck_99cdf7eb3ae1b6ef>>();
	};
	// _FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b
	aotLib[0xabee4aca14a3201e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<TArray<uint32_t> & (*) ( Context * __context__, TArray<uint32_t> &  ),&_FuncbuiltinTick_return_with_lockcheck_3cd49a3451febf4b>>();
	};
	// _FuncbuiltinTickpush_96b6a7003d9304b3
	aotLib[0x4f38c85234eb9e39] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , uint8_t  ),&_FuncbuiltinTickpush_96b6a7003d9304b3>>();
	};
	// _FuncbuiltinTickreserve_1163d4031687d985
	aotLib[0x93efc8d4301923d0] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , int32_t  ),&_FuncbuiltinTickreserve_1163d4031687d985>>();
	};
	// _FuncbuiltinTickpush_3d8e11693091805e
	aotLib[0x9ed51c625cf0e062] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint32_t> & , uint32_t  ),&_FuncbuiltinTickpush_3d8e11693091805e>>();
	};
	// _FuncbuiltinTickresize_4c98a9f12906ee43
	aotLib[0x7ac0476a0b9fc035] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , int32_t  ),&_FuncbuiltinTickresize_4c98a9f12906ee43>>();
	};
	// utf16_to_utf32_2c85c7ce7b90cf66
	aotLib[0x8e978059543f9293] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__, uint32_t , uint32_t  ),&utf16_to_utf32_2c85c7ce7b90cf66>>();
	};
	// utf8_encode_5ea3a6cf711d0b53
	aotLib[0x530399a7c762109] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , uint32_t  ),&utf8_encode_5ea3a6cf711d0b53>>();
	};
	// utf8_encode_fe9a2c6d855320bd
	aotLib[0x385c8daf6fa89683] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, uint32_t  ),&utf8_encode_fe9a2c6d855320bd>>();
	};
	// utf8_encode_95f1494bc2b6ed49
	aotLib[0x1650984bd46b5407] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , TArray<uint32_t> const  &  ),&utf8_encode_95f1494bc2b6ed49>>();
	};
	// utf8_encode_2dfdb6c0c0665fee
	aotLib[0x7a8b4aeeb709804c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint8_t> (*) ( Context * __context__, TArray<uint32_t> const  &  ),&utf8_encode_2dfdb6c0c0665fee>>();
	};
	// utf8_length_362d2fb098289bdc
	aotLib[0xe2c1918c348a836d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TArray<uint8_t> const  &  ),&utf8_length_362d2fb098289bdc>>();
	};
	// utf8_length_1e6f8ee224ef4bd2
	aotLib[0xaa335d1f4423b553] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, char * const   ),&utf8_length_1e6f8ee224ef4bd2>>();
	};
	// is_first_byte_of_utf8_char_ec644bb641f9e7a4
	aotLib[0xa3a74d6e260d850e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, uint8_t  ),&is_first_byte_of_utf8_char_ec644bb641f9e7a4>>();
	};
	// contains_utf8_bom_fac11c0fbdbb944f
	aotLib[0x7f9b530e6639d811] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TArray<uint8_t> const  &  ),&contains_utf8_bom_fac11c0fbdbb944f>>();
	};
	// contains_utf8_bom_9f371025b0516edc
	aotLib[0x670399c16eb5ab27] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, char * const   ),&contains_utf8_bom_9f371025b0516edc>>();
	};
	// is_utf8_string_valid_221552b9eafc590a
	aotLib[0xdd48ec1b4798340e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TArray<uint8_t> const  &  ),&is_utf8_string_valid_221552b9eafc590a>>();
	};
	// is_utf8_string_valid_c001bdc037b6eb95
	aotLib[0xb5dc5fc49ac1815e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, char * const   ),&is_utf8_string_valid_c001bdc037b6eb95>>();
	};
	// utf8_decode_2bda99fa41022503
	aotLib[0x453e4e604f34fed4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint32_t> & , TArray<uint8_t> const  &  ),&utf8_decode_2bda99fa41022503>>();
	};
	// utf8_decode_6daf598a4fe1ed4
	aotLib[0x988bcf0b1e6ecc56] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint32_t> (*) ( Context * __context__, TArray<uint8_t> const  &  ),&utf8_decode_6daf598a4fe1ed4>>();
	};
	// utf8_decode_9bde921137fa170
	aotLib[0x7ee18558e95e8c6c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<uint32_t> (*) ( Context * __context__, char * const   ),&utf8_decode_9bde921137fa170>>();
	};
	// utf8_decode_4f7738d23733680a
	aotLib[0x3aa9aa5c9a7c1f1] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint32_t> & , char * const   ),&utf8_decode_4f7738d23733680a>>();
	};
	// decode_unicode_escape_e2de811e7f2112f5
	aotLib[0x95a62c9bb5c821e3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, char * const   ),&decode_unicode_escape_e2de811e7f2112f5>>();
	};
	// [[ init script ]]
	aotLib[0x79a88bf5abaa802f] = [&](Context & ctx){
		ctx.aotInitScript = ctx.code->makeNode<SimNode_Aot<void (*)(Context *, bool),&__init_script>>();
		return ctx.aotInitScript;
	};
	resolveTypeInfoAnnotations();
};

AotListBase impl(registerAotFunctions);
}
}
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
#if defined(__EDG__)
#pragma diag_default 826
#elif defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
