#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require json
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
namespace _anon_18065093014248764701 {

extern StructInfo __struct_info__6719ce5de130c0d3;
extern StructInfo __struct_info__6883e30bf583dbcb;
extern StructInfo __struct_info__69e2ef6fbeda51a0;
extern TypeInfo __type_info__e796e1d4af74511c;
extern TypeInfo __type_info__3fb2f51b6ebec3f2;
extern TypeInfo __type_info__37d36026a6078a42;
extern TypeInfo __type_info__12283e04d98e7c73;
extern TypeInfo __type_info__fa1aceb92701bc9a;
extern TypeInfo __type_info__af8afe4c86446b52;
extern TypeInfo __type_info__af63eb4c86020609;
extern TypeInfo __type_info__af63e44c8601fa24;
extern TypeInfo __type_info__425e24cd375abb7f;
extern TypeInfo __type_info__79b1744635bfe2be;
extern TypeInfo __type_info__af5be84c85f468f0;
extern TypeInfo __type_info__8dbbd9827382f56f;
extern TypeInfo __type_info__2012934da3706857;
extern TypeInfo __type_info__af87fe4c863f5252;
extern TypeInfo __type_info__994066f681df7bcd;
extern TypeInfo __type_info__af63df4c8601f1a5;
extern TypeInfo __type_info__af63ee4c86020b22;
extern TypeInfo __type_info__af90fe4c864e9d52;
extern TypeInfo __type_info__af81fe4c86352052;
extern TypeInfo __type_info__790033b1854b444b;
extern TypeInfo __type_info__af63d94c8601e773;
extern VarInfo __var_info__4bf6bb78ce9673af;
extern VarInfo __var_info__625a9b11bd57decf;
extern VarInfo __var_info__fac8b32671fee393;
extern VarInfo __var_info__718b12b73ad21765;
extern VarInfo __var_info__54639b16da862704;
extern VarInfo __var_info__326e780a5da2adf8;
extern VarInfo __var_info__a798e985ff4af814;
extern VarInfo __var_info__eeae79bd86a73b7b;
extern VarInfo __var_info__325d780a5d407f20;
extern VarInfo __var_info__bd409e4745b09701;
extern VarInfo __var_info__1e2ccdbd721c356;
extern VarInfo __var_info__7d8e784a55e384;
extern VarInfo __var_info__5e95860a82d2006f;
extern VarInfo __var_info__b4968aa0cbc56b24;
extern VarInfo __var_info__46c7810a6e97f019;
extern VarInfo __var_info__e594f64fe0622abc;
extern VarInfo __var_info__a981854735365000;
extern FuncInfo __func_info__5a16898e20f97124;

TypeInfo * __type_info__e594f64fe0622abc_arg_types_var_7429195962929692883[2] = { &__type_info__79b1744635bfe2be, &__type_info__fa1aceb92701bc9a };
const char * __type_info__e594f64fe0622abc_arg_names_var_7429195962929692883[2] = { "__this", "_yield_83" };
VarInfo __struct_info__6719ce5de130c0d3_field_0 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__af81fe4c86352052, nullptr, (TypeInfo **)__type_info__e594f64fe0622abc_arg_types_var_7429195962929692883, __type_info__e594f64fe0622abc_arg_names_var_7429195962929692883, 2, 0, nullptr, 12, 8, UINT64_C(0xe594f64fe0622abc), "__lambda", 0, 0 };
TypeInfo * __type_info__718b12b73ad21765_arg_types_var_7429195962929692883[1] = { &__type_info__425e24cd375abb7f };
const char * __type_info__718b12b73ad21765_arg_names_var_7429195962929692883[1] = { "__this" };
VarInfo __struct_info__6719ce5de130c0d3_field_1 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__af63eb4c86020609, nullptr, (TypeInfo **)__type_info__718b12b73ad21765_arg_types_var_7429195962929692883, __type_info__718b12b73ad21765_arg_names_var_7429195962929692883, 1, 0, nullptr, 12, 8, UINT64_C(0x718b12b73ad21765), "__finalize", 8, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_2 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x4bf6bb78ce9673af), "__yield", 16, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_3 =  { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16516, 8, UINT64_C(0x1e2ccdbd721c356), "stext", 24, 4 };
VarInfo __struct_info__6719ce5de130c0d3_field_4 =  { Type::tIterator, nullptr, nullptr, nullptr, &__type_info__af63e44c8601fa24, nullptr, nullptr, nullptr, 0, 0, nullptr, 24602, 8, UINT64_C(0x325d780a5d407f20), "tin", 32, 6 };
VarInfo __struct_info__6719ce5de130c0d3_field_5 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xb4968aa0cbc56b24), "ahead", 40, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_6 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 40962, 24, UINT64_C(0x5e95860a82d2006f), "str", 48, 10 };
VarInfo __struct_info__6719ce5de130c0d3_field_7 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x326e780a5da2adf8), "line", 72, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_8 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x46c7810a6e97f019), "row", 76, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_9 =  { Type::tBool, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0x54639b16da862704), "__anyNumbers_rename_at_128", 80, 0 };
VarInfo __struct_info__6719ce5de130c0d3_field_10 =  { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0x7d8e784a55e384), "__num_rename_at_145", 88, 11 };
VarInfo __struct_info__6719ce5de130c0d3_field_11 =  { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0x625a9b11bd57decf), "__name_rename_at_157", 96, 12 };
VarInfo * __struct_info__6719ce5de130c0d3_fields[12] =  { &__struct_info__6719ce5de130c0d3_field_0, &__struct_info__6719ce5de130c0d3_field_1, &__struct_info__6719ce5de130c0d3_field_2, &__struct_info__6719ce5de130c0d3_field_3, &__struct_info__6719ce5de130c0d3_field_4, &__struct_info__6719ce5de130c0d3_field_5, &__struct_info__6719ce5de130c0d3_field_6, &__struct_info__6719ce5de130c0d3_field_7, &__struct_info__6719ce5de130c0d3_field_8, &__struct_info__6719ce5de130c0d3_field_9, &__struct_info__6719ce5de130c0d3_field_10, &__struct_info__6719ce5de130c0d3_field_11 };
StructInfo __struct_info__6719ce5de130c0d3 = {"_lambda_json_83_8_1", "json", 30, __struct_info__6719ce5de130c0d3_fields, 12, 104, UINT64_C(0x0), nullptr, UINT64_C(0x6719ce5de130c0d3), 3 };
TypeInfo * __type_info__fac8b32671fee393_arg_types_var_7531112642396806091[6] = { &__type_info__af63ee4c86020b22, &__type_info__af63d94c8601e773, &__type_info__af63df4c8601f1a5, &__type_info__12283e04d98e7c73, &__type_info__af63e44c8601fa24, &__type_info__af63ee4c86020b22 };
const char * __type_info__fac8b32671fee393_arg_names_var_7531112642396806091[6] = { "_string", "_number", "_bool", "_null", "_symbol", "_error" };
VarInfo __struct_info__6883e30bf583dbcb_field_0 =  { Type::tVariant, nullptr, nullptr, nullptr, nullptr, nullptr, (TypeInfo **)__type_info__fac8b32671fee393_arg_types_var_7531112642396806091, __type_info__fac8b32671fee393_arg_names_var_7531112642396806091, 6, 0, nullptr, 24582, 16, UINT64_C(0xfac8b32671fee393), "value", 0, 3 };
VarInfo __struct_info__6883e30bf583dbcb_field_1 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xa981854735365000), "line", 16, 0 };
VarInfo __struct_info__6883e30bf583dbcb_field_2 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xbd409e4745b09701), "row", 20, 0 };
VarInfo * __struct_info__6883e30bf583dbcb_fields[3] =  { &__struct_info__6883e30bf583dbcb_field_0, &__struct_info__6883e30bf583dbcb_field_1, &__struct_info__6883e30bf583dbcb_field_2 };
StructInfo __struct_info__6883e30bf583dbcb = {"TokenAt", "json", 12, __struct_info__6883e30bf583dbcb_fields, 3, 24, UINT64_C(0x0), nullptr, UINT64_C(0x6883e30bf583dbcb), 0 };
TypeInfo * __type_info__a798e985ff4af814_arg_types_var_7629923981941428640[6] = { &__type_info__e796e1d4af74511c, &__type_info__994066f681df7bcd, &__type_info__af63ee4c86020b22, &__type_info__af63d94c8601e773, &__type_info__af63df4c8601f1a5, &__type_info__12283e04d98e7c73 };
const char * __type_info__a798e985ff4af814_arg_names_var_7629923981941428640[6] = { "_object", "_array", "_string", "_number", "_bool", "_null" };
VarInfo __struct_info__69e2ef6fbeda51a0_field_0 =  { Type::tVariant, nullptr, nullptr, nullptr, nullptr, nullptr, (TypeInfo **)__type_info__a798e985ff4af814_arg_types_var_7629923981941428640, __type_info__a798e985ff4af814_arg_names_var_7629923981941428640, 6, 0, nullptr, 57346, 56, UINT64_C(0xa798e985ff4af814), "value", 0, 1 };
VarInfo * __struct_info__69e2ef6fbeda51a0_fields[1] =  { &__struct_info__69e2ef6fbeda51a0_field_0 };
StructInfo __struct_info__69e2ef6fbeda51a0 = {"JsonValue", "json", 28, __struct_info__69e2ef6fbeda51a0_fields, 1, 56, UINT64_C(0x0), nullptr, UINT64_C(0x69e2ef6fbeda51a0), 0 };
VarInfo __func_info__5a16898e20f97124_field_0 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 41058, 24, UINT64_C(0xeeae79bd86a73b7b), "str", 0, 0 };
VarInfo * __func_info__5a16898e20f97124_fields[1] =  { &__func_info__5a16898e20f97124_field_0 };
FuncInfo __func_info__5a16898e20f97124 = {"invoke block<(str:array<uint8> const#):void> const", "", __func_info__5a16898e20f97124_fields, 1, 32, &__type_info__af63eb4c86020609, nullptr,0,UINT64_C(0x5a16898e20f97124), 0x0 };
TypeInfo __type_info__e796e1d4af74511c = { Type::tTable, nullptr, nullptr, nullptr, &__type_info__af63ee4c86020b22, &__type_info__3fb2f51b6ebec3f2, nullptr, nullptr, 0, 0, nullptr, 57346, 48, UINT64_C(0xe796e1d4af74511c) };
TypeInfo __type_info__3fb2f51b6ebec3f2 = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__790033b1854b444b, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x3fb2f51b6ebec3f2) };
TypeInfo __type_info__37d36026a6078a42 = { Type::tHandle, nullptr, nullptr, DAS_MAKE_ANNOTATION("~strings::StringBuilderWriter"), nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 2, 288, UINT64_C(0x37d36026a6078a42) };
TypeInfo __type_info__12283e04d98e7c73 = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__af63eb4c86020609, nullptr, nullptr, nullptr, 0, 0, nullptr, 8204, 8, UINT64_C(0x12283e04d98e7c73) };
TypeInfo __type_info__fa1aceb92701bc9a = { Type::tStructure, &__struct_info__6883e30bf583dbcb, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 24582, 24, UINT64_C(0xfa1aceb92701bc9a) };
TypeInfo __type_info__af8afe4c86446b52 = { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 4, UINT64_C(0xaf8afe4c86446b52) };
TypeInfo __type_info__af63eb4c86020609 = { Type::tVoid, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 0, UINT64_C(0xaf63eb4c86020609) };
TypeInfo __type_info__af63e44c8601fa24 = { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xaf63e44c8601fa24) };
TypeInfo __type_info__425e24cd375abb7f = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__79b1744635bfe2be, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x425e24cd375abb7f) };
TypeInfo __type_info__79b1744635bfe2be = { Type::tStructure, &__struct_info__6719ce5de130c0d3, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 104, UINT64_C(0x79b1744635bfe2be) };
TypeInfo __type_info__af5be84c85f468f0 = { Type::tUInt8, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0xaf5be84c85f468f0) };
TypeInfo __type_info__8dbbd9827382f56f = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__790033b1854b444b, nullptr, nullptr, nullptr, 0, 0, nullptr, 24620, 8, UINT64_C(0x8dbbd9827382f56f) };
TypeInfo * __type_info__2012934da3706857_arg_types[6] = { &__type_info__af63ee4c86020b22, &__type_info__af63d94c8601e773, &__type_info__af63df4c8601f1a5, &__type_info__12283e04d98e7c73, &__type_info__af63e44c8601fa24, &__type_info__af63ee4c86020b22 };
const char * __type_info__2012934da3706857_arg_names[6] = { "_string", "_number", "_bool", "_null", "_symbol", "_error" };
TypeInfo __type_info__2012934da3706857 = { Type::tVariant, nullptr, nullptr, nullptr, nullptr, nullptr, (TypeInfo **)__type_info__2012934da3706857_arg_types, __type_info__2012934da3706857_arg_names, 6, 0, nullptr, 24838, 16, UINT64_C(0x2012934da3706857) };
TypeInfo __type_info__af87fe4c863f5252 = { Type::tDouble, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 8, UINT64_C(0xaf87fe4c863f5252) };
TypeInfo __type_info__994066f681df7bcd = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__3fb2f51b6ebec3f2, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 24, UINT64_C(0x994066f681df7bcd) };
TypeInfo __type_info__af63df4c8601f1a5 = { Type::tBool, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0xaf63df4c8601f1a5) };
TypeInfo __type_info__af63ee4c86020b22 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0xaf63ee4c86020b22) };
TypeInfo __type_info__af90fe4c864e9d52 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16420, 8, UINT64_C(0xaf90fe4c864e9d52) };
TypeInfo __type_info__af81fe4c86352052 = { Type::tBool, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 1, UINT64_C(0xaf81fe4c86352052) };
TypeInfo __type_info__790033b1854b444b = { Type::tStructure, &__struct_info__69e2ef6fbeda51a0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 56, UINT64_C(0x790033b1854b444b) };
TypeInfo __type_info__af63d94c8601e773 = { Type::tDouble, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 8, UINT64_C(0xaf63d94c8601e773) };

static void resolveTypeInfoAnnotations()
{
	__type_info__37d36026a6078a42.resolveAnnotation();
}

TypeInfo * __tinfo_0[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_1[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_2[4] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_3[8] = { &__type_info__af90fe4c864e9d52, &__type_info__2012934da3706857, &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_4[6] = { &__type_info__af90fe4c864e9d52, &__type_info__2012934da3706857, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_5[10] = { &__type_info__af90fe4c864e9d52, &__type_info__2012934da3706857, &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_6[4] = { &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_7[8] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_8[6] = { &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_9[8] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_10[8] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_11[5] = { &__type_info__2012934da3706857, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24, &__type_info__af90fe4c864e9d52, &__type_info__af63e44c8601fa24 };
TypeInfo * __tinfo_12[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_13[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_14[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_15[2] = { &__type_info__37d36026a6078a42, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_16[2] = { &__type_info__37d36026a6078a42, &__type_info__af87fe4c863f5252 };
TypeInfo * __tinfo_17[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_18[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_19[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_20[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_21[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_22[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_23[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_24[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_25[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_26[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_27[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_28[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_29[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_30[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_31[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_32[2] = { &__type_info__af90fe4c864e9d52, &__type_info__8dbbd9827382f56f };
TypeInfo * __tinfo_33[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_34[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_35[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
namespace json { struct JsonValue; };
namespace json { struct TokenAt; };
namespace json { struct _lambda_json_83_8_1; };
// unused enumeration ConversionResult
namespace json {

struct JsonValue {
	TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> value;
};
static_assert(sizeof(JsonValue)==56,"structure size mismatch with DAS");
static_assert(offsetof(JsonValue,value)==0,"structure field offset mismatch with DAS");
}
namespace json {

struct TokenAt {
	TVariant<16,8,char *,double,bool,void *,int32_t,char *> value;
	int32_t line;
	int32_t row;
};
static_assert(sizeof(TokenAt)==24,"structure size mismatch with DAS");
static_assert(offsetof(TokenAt,value)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(TokenAt,line)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(TokenAt,row)==20,"structure field offset mismatch with DAS");
}
namespace json {

struct _lambda_json_83_8_1 {
	Func DAS_COMMENT((bool,json::_lambda_json_83_8_1,json::TokenAt)) __lambda;
	Func DAS_COMMENT((void,json::_lambda_json_83_8_1 *)) __finalize;
	int32_t __yield;
	char * stext;
	Sequence DAS_COMMENT((int32_t)) tin;
	int32_t ahead;
	TArray<uint8_t> str;
	int32_t line;
	int32_t row;
	bool __anyNumbers_rename_at_128;
	char * __num_rename_at_145;
	char * __name_rename_at_157;
};
static_assert(sizeof(_lambda_json_83_8_1)==104,"structure size mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__lambda)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__yield)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,stext)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,tin)==32,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,ahead)==40,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,str)==48,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,line)==72,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,row)==76,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__anyNumbers_rename_at_128)==80,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__num_rename_at_145)==88,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_json_83_8_1,__name_rename_at_157)==96,"structure field offset mismatch with DAS");
}

inline void _FuncbuiltinTickfinalize_fc512ae94293239c ( Context * __context__, TArray<uint8_t> & __a_rename_at_544_0 );
inline void finalize_82f08cc1e896a8bd ( Context * __context__, json::_lambda_json_83_8_1 & ____this_rename_at_83_1 );
inline Sequence DAS_COMMENT((json::TokenAt)) _FuncbuiltinTickeach_27d16e1262d1b229 ( Context * __context__, Lambda DAS_COMMENT((bool,json::TokenAt)) const  __lam_rename_at_626_2 );
inline bool _FuncbuiltinTicknext_6a3c01874ce3fb9a ( Context * __context__, Sequence DAS_COMMENT((int32_t)) const  & __it_rename_at_573_4, int32_t & __value_rename_at_573_5 );
inline Sequence DAS_COMMENT((int32_t)) _FuncbuiltinTickeach_8318d56a25a6cc77 ( Context * __context__, char * const  __str_rename_at_599_6 );
inline void _FuncbuiltinTickpush_96b6a7003d9304b3 ( Context * __context__, TArray<uint8_t> & __Arr_rename_at_79_8, uint8_t __value_rename_at_79_9 );
inline bool _Func_lambda_json_83_8_1Tickfunction_37d151c582262773 ( Context * __context__, json::_lambda_json_83_8_1 & ____this_rename_at_83_10, json::TokenAt & ___yield_83_rename_at_83_11 );
inline void _Func_lambda_json_83_8_1Tickfinalizer_dcd53e507a1a3c40 ( Context * __context__, json::_lambda_json_83_8_1 * ____this_rename_at_83_12 );
inline bool _FuncbuiltinTicknext_855e99bab709e1b2 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) const  & __it_rename_at_573_13, json::TokenAt & __value_rename_at_573_14 );
inline void _FuncbuiltinTickpush_3e00b4846594a0ae ( Context * __context__, TArray<json::JsonValue *> & __Arr_rename_at_79_15, json::JsonValue * const  __value_rename_at_79_16 );
inline bool _FuncbuiltinTickkey_exists_cf25dd2b3c15ad2 ( Context * __context__, TTable<char *,json::JsonValue *> const  & __Tab_rename_at_446_17, char * const  __at_rename_at_446_18 );
inline Sequence DAS_COMMENT((char * &)) _FuncbuiltinTickkeys_4c23b7ded3f2ea80 ( Context * __context__, TTable<char *,json::JsonValue *> const  & __a_rename_at_513_19 );
inline Sequence DAS_COMMENT((json::JsonValue * &)) _FuncbuiltinTickvalues_3e6d35dc6759defe ( Context * __context__, TTable<char *,json::JsonValue *> const  & __a_rename_at_525_21 );
inline json::JsonValue * JV_329cd26089c5824a ( Context * __context__, char * const  __v_rename_at_42_23 );
inline json::JsonValue * JV_ee50ad9073b68df9 ( Context * __context__, double __v_rename_at_46_24 );
inline json::JsonValue * JV_24a62d4c91875cf ( Context * __context__, bool __v_rename_at_49_25 );
inline json::JsonValue * JVNull_f69e3effb8bc1460 ( Context * __context__ );
inline json::JsonValue * JV_f17b12e37633850f ( Context * __context__, TTable<char *,json::JsonValue *> & __v_rename_at_56_26 );
inline json::JsonValue * JV_bfd94f47b31832f5 ( Context * __context__, TArray<json::JsonValue *> & __v_rename_at_59_27 );
inline Sequence DAS_COMMENT((json::TokenAt)) lexer_39488dd6989f2b17 ( Context * __context__, char * const  __text_rename_at_62_28 );
inline Sequence DAS_COMMENT((json::TokenAt)) lexer_8ed723004bb8d8ed ( Context * __context__, TArray<uint8_t> const  & __text_rename_at_66_30 );
inline bool next_9642357cb214e878 ( Context * __context__, Sequence DAS_COMMENT((int32_t)) & __text_rename_at_70_32, int32_t & __character_rename_at_70_33, int32_t & __line_rename_at_70_34, int32_t & __row_rename_at_70_35 );
inline Sequence DAS_COMMENT((json::TokenAt)) _lexer_4f11d386d9c23d9f ( Context * __context__, char * __stext_rename_at_81_36 );
inline bool expect_token_635976e4db59827c ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & __itv_rename_at_178_37, json::TokenAt & __ahead_rename_at_178_38, int32_t __vindex_rename_at_178_39, char * & __error_rename_at_178_40 );
inline bool expect_symbol_30e11ef1fad447a4 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & __itv_rename_at_188_41, json::TokenAt & __ahead_rename_at_188_42, int32_t __sym_rename_at_188_43, char * & __error_rename_at_188_44 );
inline json::JsonValue * parse_value_52c7c3cc5fbcb5d9 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & __itv_rename_at_201_45, char * & __error_rename_at_201_46 );
inline json::JsonValue * read_json_219e262ed6d50eb2 ( Context * __context__, char * const  __text_rename_at_277_56, char * & __error_rename_at_277_57 );
inline json::JsonValue * read_json_54b09556094ae79b ( Context * __context__, TArray<uint8_t> const  & __text_rename_at_286_60, char * & __error_rename_at_286_61 );
inline bool set_no_trailing_zeros_15990b1c21051684 ( Context * __context__, bool __value_rename_at_295_64 );
inline bool set_no_empty_arrays_b9b9e410fb9ff5d4 ( Context * __context__, bool __value_rename_at_303_66 );
inline bool set_allow_duplicate_keys_c19ac8de276f7450 ( Context * __context__, bool __value_rename_at_311_68 );
inline void write_value_af1db3433ead5c99 ( Context * __context__, StringBuilderWriter & __writer_rename_at_318_70, json::JsonValue * const  __jsv_rename_at_318_71, int32_t __depth_rename_at_318_72 );
inline char * write_json_1409f758946db648 ( Context * __context__, json::JsonValue * const  __val_rename_at_379_80 );
inline char * write_json_60bd09829b393a34 ( Context * __context__, json::JsonValue * const  __val_rename_at_385_83 );
inline char * try_fixing_broken_json_fc38694030c41593 ( Context * __context__, char * __bad_rename_at_390_84 );

void __init_script ( Context * __context__, bool __init_shared )
{
	das_global<int32_t,0xc713ddb3e835448d>(__context__) = 0;/*Token_string*/
	das_global<int32_t,0x96ac244c9265d269>(__context__) = 4;/*Token_symbol*/
	das_global<bool,0xd3b8b85b9bf19183>(__context__) = false;/*no_trailing_zeros*/
	das_global<bool,0xab7f08dbdeea5c03>(__context__) = false;/*no_empty_arrays*/
	das_global<bool,0x30e401a8d3210d31>(__context__) = false;/*allow_duplicate_keys*/
}

inline void _FuncbuiltinTickfinalize_fc512ae94293239c ( Context * __context__, TArray<uint8_t> &  __a_rename_at_544_0 )
{
	builtin_array_free(das_arg<TArray<uint8_t>>::pass(__a_rename_at_544_0),1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void finalize_82f08cc1e896a8bd ( Context * __context__, json::_lambda_json_83_8_1 &  ____this_rename_at_83_1 )
{
	builtin_iterator_delete(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_1.tin),__context__);
	_FuncbuiltinTickfinalize_fc512ae94293239c(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_1.str));
	memset(&(____this_rename_at_83_1), 0, 104);
}

inline Sequence DAS_COMMENT((json::TokenAt)) _FuncbuiltinTickeach_27d16e1262d1b229 ( Context * __context__, Lambda DAS_COMMENT((bool,json::TokenAt)) const  __lam_rename_at_626_2 )
{
	Sequence DAS_COMMENT((json::TokenAt)) __it_rename_at_628_3; das_zero(__it_rename_at_628_3);
	builtin_make_lambda_iterator(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__it_rename_at_628_3),__lam_rename_at_626_2,24,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((json::TokenAt))>::cast(__it_rename_at_628_3);
}

inline bool _FuncbuiltinTicknext_6a3c01874ce3fb9a ( Context * __context__, Sequence DAS_COMMENT((int32_t)) const  &  __it_rename_at_573_4, int32_t & __value_rename_at_573_5 )
{
	return das_auto_cast<bool>::cast(builtin_iterator_iterate(__it_rename_at_573_4,das_auto_cast<void * const >::cast(das_ref(__context__,__value_rename_at_573_5)),__context__));
}

inline Sequence DAS_COMMENT((int32_t)) _FuncbuiltinTickeach_8318d56a25a6cc77 ( Context * __context__, char * const  __str_rename_at_599_6 )
{
	Sequence DAS_COMMENT((int32_t)) __it_rename_at_600_7; das_zero(__it_rename_at_600_7);
	builtin_make_string_iterator(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(__it_rename_at_600_7),__str_rename_at_599_6,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((int32_t))>::cast(__it_rename_at_600_7);
}

inline void _FuncbuiltinTickpush_96b6a7003d9304b3 ( Context * __context__, TArray<uint8_t> &  __Arr_rename_at_79_8, uint8_t __value_rename_at_79_9 )
{
	das_copy(__Arr_rename_at_79_8(builtin_array_push_back(das_arg<TArray<uint8_t>>::pass(__Arr_rename_at_79_8),1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_9);
}

inline bool _Func_lambda_json_83_8_1Tickfunction_37d151c582262773 ( Context * __context__, json::_lambda_json_83_8_1 &  ____this_rename_at_83_10, json::TokenAt &  ___yield_83_rename_at_83_11 )
{
	switch (____this_rename_at_83_10.__yield) {
	case 0: goto label_0;
	case 34: goto label_34;
	case 1: goto label_1;
	case 32: goto label_32;
	case 7: goto label_7;
	case 3: goto label_3;
	case 2: goto label_2;
	case 4: goto label_4;
	case 5: goto label_5;
	case 6: goto label_6;
	case 8: goto label_8;
	case 9: goto label_9;
	case 10: goto label_10;
	case 11: goto label_11;
	case 30: goto label_30;
	case 12: goto label_12;
	case 13: goto label_13;
	case 14: goto label_14;
	case 28: goto label_28;
	case 15: goto label_15;
	case 23: goto label_23;
	case 16: goto label_16;
	case 21: goto label_21;
	case 17: goto label_17;
	case 19: goto label_19;
	case 18: goto label_18;
	case 20: goto label_20;
	case 22: goto label_22;
	case 24: goto label_24;
	case 26: goto label_26;
	case 25: goto label_25;
	case 27: goto label_27;
	case 29: goto label_29;
	case 31: goto label_31;
	case 33: goto label_33;
	case 35: goto label_35;
	default: __context__->throw_error("invalid label");
	};
	label_0:;;
	memset(&(____this_rename_at_83_10.tin), 0, 8);
	das_move(____this_rename_at_83_10.tin,_FuncbuiltinTickeach_8318d56a25a6cc77(__context__,____this_rename_at_83_10.stext));
	das_copy(____this_rename_at_83_10.ahead,32);
	memset(&(____this_rename_at_83_10.str), 0, 24);
	das_copy(____this_rename_at_83_10.line,1);
	das_copy(____this_rename_at_83_10.row,0);
	label_34:;;
	if ( !!(builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin))) )
	{
		goto label_35;
	};
	while ( is_white_space(____this_rename_at_83_10.ahead) && next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) )
	{
	};
	if ( builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin)) )
	{
		return das_auto_cast<bool>::cast(false);
	};
	if ( !((((((____this_rename_at_83_10.ahead == 91) || (____this_rename_at_83_10.ahead == 93)) || (____this_rename_at_83_10.ahead == 123)) || (____this_rename_at_83_10.ahead == 125)) || (____this_rename_at_83_10.ahead == 58)) || (____this_rename_at_83_10.ahead == 44)) )
	{
		goto label_32;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_96;
		das_zero(__mks_96);
		das_copy((__mks_96.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_96;
			das_get_variant_field<int32_t,8,4>::set(__mkv_96) = ____this_rename_at_83_10.ahead;
			return __mkv_96;
		})())));
		das_copy((__mks_96.line),(____this_rename_at_83_10.line));
		das_copy((__mks_96.row),(____this_rename_at_83_10.row));
		return __mks_96;
	})()));
	das_copy(____this_rename_at_83_10.__yield,1);
	return das_auto_cast<bool>::cast(true);
	label_1:;;
	_FuncbuiltinTicknext_6a3c01874ce3fb9a(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead);
	goto label_33;
	label_32:;;
	if ( !(____this_rename_at_83_10.ahead == 34) )
	{
		goto label_30;
	};
	label_7:;;
	if ( !(next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) && (____this_rename_at_83_10.ahead != 34)) )
	{
		goto label_8;
	};
	if ( !(____this_rename_at_83_10.ahead == 92) )
	{
		goto label_5;
	};
	if ( !next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) )
	{
		goto label_3;
	};
	if ( ____this_rename_at_83_10.ahead == 98 )
	{
		das_copy(____this_rename_at_83_10.ahead,8);
	} else if ( ____this_rename_at_83_10.ahead == 102 )
	{
		das_copy(____this_rename_at_83_10.ahead,12);
	} else if ( ____this_rename_at_83_10.ahead == 110 )
	{
		das_copy(____this_rename_at_83_10.ahead,10);
	} else if ( ____this_rename_at_83_10.ahead == 114 )
	{
		das_copy(____this_rename_at_83_10.ahead,13);
	} else if ( ____this_rename_at_83_10.ahead == 116 )
	{
		das_copy(____this_rename_at_83_10.ahead,9);
	} else if ( ____this_rename_at_83_10.ahead == 117 )
	{
		das_copy(____this_rename_at_83_10.ahead,92);
	};
	_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
	goto label_4;
	label_3:;;
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_116;
		das_zero(__mks_116);
		das_copy((__mks_116.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_116;
			das_get_variant_field<char *,8,5>::set(__mkv_116) = ((char *) "string escape sequence exceeds text");
			return __mkv_116;
		})())));
		das_copy((__mks_116.line),(____this_rename_at_83_10.line));
		das_copy((__mks_116.row),(____this_rename_at_83_10.row));
		return __mks_116;
	})()));
	das_copy(____this_rename_at_83_10.__yield,2);
	return das_auto_cast<bool>::cast(true);
	label_2:;;
	return das_auto_cast<bool>::cast(false);
	label_4:;;
	goto label_6;
	label_5:;;
	_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
	label_6:;;
	goto label_7;
	label_8:;;
	if ( !builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin)) )
	{
		goto label_10;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_121;
		das_zero(__mks_121);
		das_copy((__mks_121.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_121;
			das_get_variant_field<char *,8,5>::set(__mkv_121) = ((char *) "string exceeds text");
			return __mkv_121;
		})())));
		das_copy((__mks_121.line),(____this_rename_at_83_10.line));
		das_copy((__mks_121.row),(____this_rename_at_83_10.row));
		return __mks_121;
	})()));
	das_copy(____this_rename_at_83_10.__yield,9);
	return das_auto_cast<bool>::cast(true);
	label_9:;;
	return das_auto_cast<bool>::cast(false);
	label_10:;;
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_123;
		das_zero(__mks_123);
		das_copy((__mks_123.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_123;
			das_get_variant_field<char *,8,0>::set(__mkv_123) = ((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))));
			return __mkv_123;
		})())));
		das_copy((__mks_123.line),(____this_rename_at_83_10.line));
		das_copy((__mks_123.row),(____this_rename_at_83_10.row));
		return __mks_123;
	})()));
	das_copy(____this_rename_at_83_10.__yield,11);
	return das_auto_cast<bool>::cast(true);
	label_11:;;
	builtin_array_clear(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	_FuncbuiltinTicknext_6a3c01874ce3fb9a(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead);
	goto label_31;
	label_30:;;
	if ( !(((____this_rename_at_83_10.ahead == 43) || (____this_rename_at_83_10.ahead == 45)) || is_number(____this_rename_at_83_10.ahead)) )
	{
		goto label_28;
	};
	_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
	das_copy(____this_rename_at_83_10.__anyNumbers_rename_at_128,is_number(____this_rename_at_83_10.ahead));
	while ( next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) && is_number(____this_rename_at_83_10.ahead) )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
		das_copy(____this_rename_at_83_10.__anyNumbers_rename_at_128,true);
	};
	if ( !(builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin))) && (____this_rename_at_83_10.ahead == 46) )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
		while ( next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) && is_number(____this_rename_at_83_10.ahead) )
		{
			_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
			das_copy(____this_rename_at_83_10.__anyNumbers_rename_at_128,true);
		};
	};
	if ( !(builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin))) && ((____this_rename_at_83_10.ahead == 101) || (____this_rename_at_83_10.ahead == 69)) )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
		next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row);
		if ( ((____this_rename_at_83_10.ahead == 43) || (____this_rename_at_83_10.ahead == 45)) || is_number(____this_rename_at_83_10.ahead) )
		{
			_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
		};
		while ( next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) && is_number(____this_rename_at_83_10.ahead) )
		{
			_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
			das_copy(____this_rename_at_83_10.__anyNumbers_rename_at_128,true);
		};
	};
	das_copy(____this_rename_at_83_10.__num_rename_at_145,((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
	if ( !!(____this_rename_at_83_10.__anyNumbers_rename_at_128) )
	{
		goto label_13;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_147;
		das_zero(__mks_147);
		das_copy((__mks_147.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_147;
			das_get_variant_field<char *,8,5>::set(__mkv_147) = das_string_builder(__context__,SimNode_AotInterop<2>(__tinfo_0, cast<char * const >::from(((char *) "invalid number ")), cast<char *>::from(____this_rename_at_83_10.__num_rename_at_145)));
			return __mkv_147;
		})())));
		das_copy((__mks_147.line),(____this_rename_at_83_10.line));
		das_copy((__mks_147.row),(____this_rename_at_83_10.row));
		return __mks_147;
	})()));
	das_copy(____this_rename_at_83_10.__yield,12);
	return das_auto_cast<bool>::cast(true);
	label_12:;;
	return das_auto_cast<bool>::cast(false);
	label_13:;;
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_149;
		das_zero(__mks_149);
		das_copy((__mks_149.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_149;
			das_get_variant_field<double,8,1>::set(__mkv_149) = string_to_double(____this_rename_at_83_10.__num_rename_at_145,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
			return __mkv_149;
		})())));
		das_copy((__mks_149.line),(____this_rename_at_83_10.line));
		das_copy((__mks_149.row),(____this_rename_at_83_10.row));
		return __mks_149;
	})()));
	das_copy(____this_rename_at_83_10.__yield,14);
	return das_auto_cast<bool>::cast(true);
	label_14:;;
	builtin_array_clear(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	delete_string(____this_rename_at_83_10.__num_rename_at_145,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	goto label_29;
	label_28:;;
	if ( !is_alpha(____this_rename_at_83_10.ahead) )
	{
		goto label_26;
	};
	_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
	while ( next_9642357cb214e878(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(____this_rename_at_83_10.tin),____this_rename_at_83_10.ahead,____this_rename_at_83_10.line,____this_rename_at_83_10.row) && is_alpha(____this_rename_at_83_10.ahead) )
	{
		_FuncbuiltinTickpush_96b6a7003d9304b3(__context__,das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),uint8_t(____this_rename_at_83_10.ahead));
	};
	das_copy(____this_rename_at_83_10.__name_rename_at_157,((char *)(builtin_string_from_array(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
	if ( !(SimPolicy<char *>::Equ(cast<char *>::from(____this_rename_at_83_10.__name_rename_at_157),cast<char *>::from(((char *) "true")),*__context__,nullptr)) )
	{
		goto label_23;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_159;
		das_zero(__mks_159);
		das_copy((__mks_159.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_159;
			das_get_variant_field<bool,8,2>::set(__mkv_159) = true;
			return __mkv_159;
		})())));
		das_copy((__mks_159.line),(____this_rename_at_83_10.line));
		das_copy((__mks_159.row),(____this_rename_at_83_10.row));
		return __mks_159;
	})()));
	das_copy(____this_rename_at_83_10.__yield,15);
	return das_auto_cast<bool>::cast(true);
	label_15:;;
	goto label_24;
	label_23:;;
	if ( !(SimPolicy<char *>::Equ(cast<char *>::from(____this_rename_at_83_10.__name_rename_at_157),cast<char *>::from(((char *) "false")),*__context__,nullptr)) )
	{
		goto label_21;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_161;
		das_zero(__mks_161);
		das_copy((__mks_161.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_161;
			das_get_variant_field<bool,8,2>::set(__mkv_161) = false;
			return __mkv_161;
		})())));
		das_copy((__mks_161.line),(____this_rename_at_83_10.line));
		das_copy((__mks_161.row),(____this_rename_at_83_10.row));
		return __mks_161;
	})()));
	das_copy(____this_rename_at_83_10.__yield,16);
	return das_auto_cast<bool>::cast(true);
	label_16:;;
	goto label_22;
	label_21:;;
	if ( !(SimPolicy<char *>::Equ(cast<char *>::from(____this_rename_at_83_10.__name_rename_at_157),cast<char *>::from(((char *) "null")),*__context__,nullptr)) )
	{
		goto label_19;
	};
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_163;
		das_zero(__mks_163);
		das_copy((__mks_163.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_163;
			das_get_variant_field<void *,8,3>::set(__mkv_163) = nullptr;
			return __mkv_163;
		})())));
		das_copy((__mks_163.line),(____this_rename_at_83_10.line));
		das_copy((__mks_163.row),(____this_rename_at_83_10.row));
		return __mks_163;
	})()));
	das_copy(____this_rename_at_83_10.__yield,17);
	return das_auto_cast<bool>::cast(true);
	label_17:;;
	goto label_20;
	label_19:;;
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_165;
		das_zero(__mks_165);
		das_copy((__mks_165.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_165;
			das_get_variant_field<char *,8,5>::set(__mkv_165) = das_string_builder(__context__,SimNode_AotInterop<2>(__tinfo_1, cast<char * const >::from(((char *) "invalid name ")), cast<char *>::from(____this_rename_at_83_10.__name_rename_at_157)));
			return __mkv_165;
		})())));
		das_copy((__mks_165.line),(____this_rename_at_83_10.line));
		das_copy((__mks_165.row),(____this_rename_at_83_10.row));
		return __mks_165;
	})()));
	das_copy(____this_rename_at_83_10.__yield,18);
	return das_auto_cast<bool>::cast(true);
	label_18:;;
	return das_auto_cast<bool>::cast(false);
	label_20:;;
	label_22:;;
	label_24:;;
	delete_string(____this_rename_at_83_10.__name_rename_at_157,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	builtin_array_clear(das_arg<TArray<uint8_t>>::pass(____this_rename_at_83_10.str),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	goto label_27;
	label_26:;;
	das_copy(___yield_83_rename_at_83_11,(([&]() -> json::TokenAt {
		json::TokenAt __mks_171;
		das_zero(__mks_171);
		das_copy((__mks_171.value),((([&]() -> TVariant<16,8,char *,double,bool,void *,int32_t,char *> {
			TVariant<16,8,char *,double,bool,void *,int32_t,char *> __mkv_171;
			das_get_variant_field<char *,8,5>::set(__mkv_171) = das_string_builder(__context__,SimNode_AotInterop<4>(__tinfo_2, cast<char * const >::from(((char *) "invalid character `")), cast<char *>::from(((char *)(to_string_char(____this_rename_at_83_10.ahead,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) "` aka ASCII ")), cast<int32_t>::from(____this_rename_at_83_10.ahead)));
			return __mkv_171;
		})())));
		das_copy((__mks_171.line),(____this_rename_at_83_10.line));
		das_copy((__mks_171.row),(____this_rename_at_83_10.row));
		return __mks_171;
	})()));
	das_copy(____this_rename_at_83_10.__yield,25);
	return das_auto_cast<bool>::cast(true);
	label_25:;;
	return das_auto_cast<bool>::cast(false);
	label_27:;;
	label_29:;;
	label_31:;;
	label_33:;;
	goto label_34;
	label_35:;;
	return das_auto_cast<bool>::cast(false);
}

inline void _Func_lambda_json_83_8_1Tickfinalizer_dcd53e507a1a3c40 ( Context * __context__, json::_lambda_json_83_8_1 * ____this_rename_at_83_12 )
{
	delete_string(das_deref(__context__,____this_rename_at_83_12).stext,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	finalize_82f08cc1e896a8bd(__context__,das_arg<json::_lambda_json_83_8_1>::pass(das_deref(__context__,____this_rename_at_83_12)));
	das_delete_lambda_struct<json::_lambda_json_83_8_1 *>::clear(__context__,____this_rename_at_83_12);
}

inline bool _FuncbuiltinTicknext_855e99bab709e1b2 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) const  &  __it_rename_at_573_13, json::TokenAt &  __value_rename_at_573_14 )
{
	return das_auto_cast<bool>::cast(builtin_iterator_iterate(__it_rename_at_573_13,das_auto_cast<void * const >::cast(das_ref(__context__,__value_rename_at_573_14)),__context__));
}

inline void _FuncbuiltinTickpush_3e00b4846594a0ae ( Context * __context__, TArray<json::JsonValue *> &  __Arr_rename_at_79_15, json::JsonValue * const  __value_rename_at_79_16 )
{
	das_copy(__Arr_rename_at_79_15(builtin_array_push_back(das_arg<TArray<json::JsonValue *>>::pass(__Arr_rename_at_79_15),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_16);
}

inline bool _FuncbuiltinTickkey_exists_cf25dd2b3c15ad2 ( Context * __context__, TTable<char *,json::JsonValue *> const  &  __Tab_rename_at_446_17, char * const  __at_rename_at_446_18 )
{
	return das_auto_cast<bool>::cast(__builtin_table_key_exists(__context__,__Tab_rename_at_446_17,__at_rename_at_446_18));
}

inline Sequence DAS_COMMENT((char * &)) _FuncbuiltinTickkeys_4c23b7ded3f2ea80 ( Context * __context__, TTable<char *,json::JsonValue *> const  &  __a_rename_at_513_19 )
{
	Sequence DAS_COMMENT((char * *)) __it_rename_at_514_20; das_zero(__it_rename_at_514_20);
	builtin_table_keys(das_arg<Sequence DAS_COMMENT((char * const ))>::pass(__it_rename_at_514_20),__a_rename_at_513_19,8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((char * &))>::cast(__it_rename_at_514_20);
}

inline Sequence DAS_COMMENT((json::JsonValue * &)) _FuncbuiltinTickvalues_3e6d35dc6759defe ( Context * __context__, TTable<char *,json::JsonValue *> const  &  __a_rename_at_525_21 )
{
	Sequence DAS_COMMENT((json::JsonValue * *)) __it_rename_at_526_22; das_zero(__it_rename_at_526_22);
	builtin_table_values(das_arg<Sequence DAS_COMMENT((json::JsonValue * const ))>::pass(__it_rename_at_526_22),__a_rename_at_525_21,8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((json::JsonValue * &))>::cast(__it_rename_at_526_22);
}

inline json::JsonValue * JV_329cd26089c5824a ( Context * __context__, char * const  __v_rename_at_42_23 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_44;
		das_zero(__mks_44);
		das_move((__mks_44.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_44;
			das_get_variant_field<char *,8,2>::set(__mkv_44) = __v_rename_at_42_23;
			return __mkv_44;
		})())));
		return __mks_44;
	})())));
}

inline json::JsonValue * JV_ee50ad9073b68df9 ( Context * __context__, double __v_rename_at_46_24 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_47;
		das_zero(__mks_47);
		das_move((__mks_47.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_47;
			das_get_variant_field<double,8,3>::set(__mkv_47) = __v_rename_at_46_24;
			return __mkv_47;
		})())));
		return __mks_47;
	})())));
}

inline json::JsonValue * JV_24a62d4c91875cf ( Context * __context__, bool __v_rename_at_49_25 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_50;
		das_zero(__mks_50);
		das_move((__mks_50.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_50;
			das_get_variant_field<bool,8,4>::set(__mkv_50) = __v_rename_at_49_25;
			return __mkv_50;
		})())));
		return __mks_50;
	})())));
}

inline json::JsonValue * JVNull_f69e3effb8bc1460 ( Context * __context__ )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_54;
		das_zero(__mks_54);
		das_move((__mks_54.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_54;
			das_get_variant_field<void *,8,5>::set(__mkv_54) = nullptr;
			return __mkv_54;
		})())));
		return __mks_54;
	})())));
}

inline json::JsonValue * JV_f17b12e37633850f ( Context * __context__, TTable<char *,json::JsonValue *> &  __v_rename_at_56_26 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_57;
		das_zero(__mks_57);
		das_move((__mks_57.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_57;
			das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::set(__mkv_57) = __v_rename_at_56_26;
			return __mkv_57;
		})())));
		return __mks_57;
	})())));
}

inline json::JsonValue * JV_bfd94f47b31832f5 ( Context * __context__, TArray<json::JsonValue *> &  __v_rename_at_59_27 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_60;
		das_zero(__mks_60);
		das_move((__mks_60.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_60;
			das_get_variant_field<TArray<json::JsonValue *>,8,1>::set(__mkv_60) = __v_rename_at_59_27;
			return __mkv_60;
		})())));
		return __mks_60;
	})())));
}

inline Sequence DAS_COMMENT((json::TokenAt)) lexer_39488dd6989f2b17 ( Context * __context__, char * const  __text_rename_at_62_28 )
{
	char * __stext_rename_at_63_29 = ((char *)(char *)(((char *)(builtin_string_clone(__text_rename_at_62_28,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((json::TokenAt))>::cast(_lexer_4f11d386d9c23d9f(__context__,__stext_rename_at_63_29));
}

inline Sequence DAS_COMMENT((json::TokenAt)) lexer_8ed723004bb8d8ed ( Context * __context__, TArray<uint8_t> const  &  __text_rename_at_66_30 )
{
	char * __stext_rename_at_67_31 = ((char *)(char *)(((char *)(builtin_string_from_array(__text_rename_at_66_30,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((json::TokenAt))>::cast(_lexer_4f11d386d9c23d9f(__context__,__stext_rename_at_67_31));
}

inline bool next_9642357cb214e878 ( Context * __context__, Sequence DAS_COMMENT((int32_t)) &  __text_rename_at_70_32, int32_t & __character_rename_at_70_33, int32_t & __line_rename_at_70_34, int32_t & __row_rename_at_70_35 )
{
	if ( _FuncbuiltinTicknext_6a3c01874ce3fb9a(__context__,das_arg<Sequence DAS_COMMENT((int32_t))>::pass(__text_rename_at_70_32),__character_rename_at_70_33) )
	{
		if ( is_new_line(__character_rename_at_70_33) )
		{
			++__line_rename_at_70_34;
			das_copy(__row_rename_at_70_35,0);
		} else {
			++__row_rename_at_70_35;
		};
		return das_auto_cast<bool>::cast(true);
	} else {
		return das_auto_cast<bool>::cast(false);
	};
}

inline Sequence DAS_COMMENT((json::TokenAt)) _lexer_4f11d386d9c23d9f ( Context * __context__, char * __stext_rename_at_81_36 )
{
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((json::TokenAt))>::cast(_FuncbuiltinTickeach_27d16e1262d1b229(__context__,das_ascend<bool,json::_lambda_json_83_8_1>::make(__context__,&__type_info__79b1744635bfe2be,(([&]() -> json::_lambda_json_83_8_1 {
		json::_lambda_json_83_8_1 __mks_82;
		das_zero(__mks_82);
		das_copy((__mks_82.__lambda),(Func(__context__->fnByMangledName(/*@json::_lambda_json_83_8_1`function XS<json::_lambda_json_83_8_1> S<json::TokenAt>*/ 2473681099651568987u))));
		das_copy((__mks_82.__finalize),(Func(__context__->fnByMangledName(/*@json::_lambda_json_83_8_1`finalizer X1<S<json::_lambda_json_83_8_1>>?*/ 13364147595872202849u))));
		das_copy((__mks_82.stext),(__stext_rename_at_81_36));
		return __mks_82;
	})()))));
}

inline bool expect_token_635976e4db59827c ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) &  __itv_rename_at_178_37, json::TokenAt &  __ahead_rename_at_178_38, int32_t __vindex_rename_at_178_39, char * & __error_rename_at_178_40 )
{
	if ( !_FuncbuiltinTicknext_855e99bab709e1b2(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_178_37),das_arg<json::TokenAt>::pass(__ahead_rename_at_178_38)) )
	{
		das_copy(__error_rename_at_178_40,((char *) "unexected eos"));
		return das_auto_cast<bool>::cast(false);
	} else if ( variant_index(das_arg<TVariant<16,8,char *,double,bool,void *,int32_t,char *>>::pass(__ahead_rename_at_178_38.value)) != __vindex_rename_at_178_39 )
	{
		das_copy(__error_rename_at_178_40,das_string_builder(__context__,SimNode_AotInterop<8>(__tinfo_3, cast<char * const >::from(((char *) "unexpected ")), cast<TVariant<16,8,char *,double,bool,void *,int32_t,char *> &>::from(__ahead_rename_at_178_38.value), cast<char * const >::from(((char *) ", expecting variant ")), cast<int32_t>::from(__vindex_rename_at_178_39), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_178_38.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_178_38.row))));
		return das_auto_cast<bool>::cast(false);
	} else {
		return das_auto_cast<bool>::cast(true);
	};
}

inline bool expect_symbol_30e11ef1fad447a4 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) &  __itv_rename_at_188_41, json::TokenAt &  __ahead_rename_at_188_42, int32_t __sym_rename_at_188_43, char * & __error_rename_at_188_44 )
{
	if ( !_FuncbuiltinTicknext_855e99bab709e1b2(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_188_41),das_arg<json::TokenAt>::pass(__ahead_rename_at_188_42)) )
	{
		das_copy(__error_rename_at_188_44,((char *) "unexected eos"));
		return das_auto_cast<bool>::cast(false);
	} else if ( !das_get_variant_field<int32_t,8,4>::is(__ahead_rename_at_188_42.value) )
	{
		das_copy(__error_rename_at_188_44,das_string_builder(__context__,SimNode_AotInterop<6>(__tinfo_4, cast<char * const >::from(((char *) "unexpected ")), cast<TVariant<16,8,char *,double,bool,void *,int32_t,char *> &>::from(__ahead_rename_at_188_42.value), cast<char * const >::from(((char *) ", expecting symbol at ")), cast<int32_t>::from(__ahead_rename_at_188_42.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_188_42.row))));
		return das_auto_cast<bool>::cast(false);
	} else if ( !(das_get_variant_field<int32_t,8,4>::as(__ahead_rename_at_188_42.value,__context__) == __sym_rename_at_188_43) )
	{
		das_copy(__error_rename_at_188_44,das_string_builder(__context__,SimNode_AotInterop<10>(__tinfo_5, cast<char * const >::from(((char *) "unexpected ")), cast<TVariant<16,8,char *,double,bool,void *,int32_t,char *> &>::from(__ahead_rename_at_188_42.value), cast<char * const >::from(((char *) ", expecting symbol `")), cast<char *>::from(((char *)(to_string_char(__sym_rename_at_188_43,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) "` aka ASCII ")), cast<int32_t>::from(__sym_rename_at_188_43), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_188_42.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_188_42.row))));
		return das_auto_cast<bool>::cast(true);
	} else {
		return das_auto_cast<bool>::cast(true);
	};
}

inline json::JsonValue * parse_value_52c7c3cc5fbcb5d9 ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) &  __itv_rename_at_201_45, char * & __error_rename_at_201_46 )
{
	json::TokenAt __ahead_rename_at_202_47; das_zero(__ahead_rename_at_202_47);
	if ( !_FuncbuiltinTicknext_855e99bab709e1b2(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),das_arg<json::TokenAt>::pass(__ahead_rename_at_202_47)) )
	{
		return das_auto_cast<json::JsonValue *>::cast(nullptr);
	} else {
		if ( das_get_variant_field<int32_t,8,4>::is(__ahead_rename_at_202_47.value) )
		{
			int32_t __sym_rename_at_206_48 = ((int32_t)das_get_variant_field<int32_t,8,4>::as(__ahead_rename_at_202_47.value,__context__));
			if ( __sym_rename_at_206_48 == 93 )
			{
				das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<4>(__tinfo_6, cast<char * const >::from(((char *) "unexpected ] at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
				return das_auto_cast<json::JsonValue *>::cast(nullptr);
			} else {
				if ( __sym_rename_at_206_48 == 91 )
				{
					TArray<json::JsonValue *> __arr_rename_at_211_49; das_zero(__arr_rename_at_211_49);
					while ( !builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45)) )
					{
						json::JsonValue * __value_rename_at_213_50 = ((json::JsonValue *)parse_value_52c7c3cc5fbcb5d9(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),__error_rename_at_201_46));
						if ( __value_rename_at_213_50 == nullptr )
						{
							if ( builtin_string_startswith(__error_rename_at_201_46,((char *) "unexpected ]"),__context__) && (builtin_array_size(das_arg<TArray<json::JsonValue *>>::pass(__arr_rename_at_211_49)) == 0) )
							{
								das_copy(__error_rename_at_201_46,nullptr);
								return das_auto_cast<json::JsonValue *>::cast(JV_bfd94f47b31832f5(__context__,das_arg<TArray<json::JsonValue *>>::pass(__arr_rename_at_211_49)));
							} else {
								return das_auto_cast<json::JsonValue *>::cast(nullptr);
							};
						};
						_FuncbuiltinTickpush_3e00b4846594a0ae(__context__,das_arg<TArray<json::JsonValue *>>::pass(__arr_rename_at_211_49),__value_rename_at_213_50);
						if ( !expect_token_635976e4db59827c(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),das_arg<json::TokenAt>::pass(__ahead_rename_at_202_47),4,__error_rename_at_201_46) )
						{
							return das_auto_cast<json::JsonValue *>::cast(nullptr);
						} else {
							int32_t __sepsym_rename_at_222_51 = ((int32_t)das_get_variant_field<int32_t,8,4>::as(__ahead_rename_at_202_47.value,__context__));
							if ( __sepsym_rename_at_222_51 == 93 )
							{
								break;
							} else if ( __sepsym_rename_at_222_51 != 44 )
							{
								das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<8>(__tinfo_7, cast<char * const >::from(((char *) "unsepected array seaprator symbol `")), cast<char *>::from(((char *)(to_string_char(__sepsym_rename_at_222_51,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) "` aka ASCII ")), cast<int32_t>::from(__sepsym_rename_at_222_51), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
								return das_auto_cast<json::JsonValue *>::cast(nullptr);
							};
						};
					};
					if ( builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45)) )
					{
						das_copy(__error_rename_at_201_46,((char *) "unexpected eos"));
						return das_auto_cast<json::JsonValue *>::cast(nullptr);
					} else {
						return das_auto_cast<json::JsonValue *>::cast(JV_bfd94f47b31832f5(__context__,das_arg<TArray<json::JsonValue *>>::pass(__arr_rename_at_211_49)));
					};
				} else if ( __sym_rename_at_206_48 == 123 )
				{
					TTable<char *,json::JsonValue *> __tab_rename_at_233_52; das_zero(__tab_rename_at_233_52);
					while ( !builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45)) )
					{
						if ( !expect_token_635976e4db59827c(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),das_arg<json::TokenAt>::pass(__ahead_rename_at_202_47),0,__error_rename_at_201_46) )
						{
							if ( (das_get_variant_field<int32_t,8,4>::is(__ahead_rename_at_202_47.value) && (das_get_variant_field<int32_t,8,4>::as(__ahead_rename_at_202_47.value,__context__) == 125)) && (builtin_table_size(das_arg<TTable<char *,json::JsonValue *>>::pass(__tab_rename_at_233_52)) == 0) )
							{
								das_copy(__error_rename_at_201_46,nullptr);
								return das_auto_cast<json::JsonValue *>::cast(JV_f17b12e37633850f(__context__,das_arg<TTable<char *,json::JsonValue *>>::pass(__tab_rename_at_233_52)));
							} else {
								return das_auto_cast<json::JsonValue *>::cast(nullptr);
							};
						};
						char * __key_rename_at_240_53 = ((char *)(char *)(das_get_variant_field<char *,8,0>::as(__ahead_rename_at_202_47.value,__context__)));
						if ( !expect_symbol_30e11ef1fad447a4(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),das_arg<json::TokenAt>::pass(__ahead_rename_at_202_47),58,__error_rename_at_201_46) )
						{
							return das_auto_cast<json::JsonValue *>::cast(nullptr);
						} else {
							json::JsonValue * __value_rename_at_243_54 = ((json::JsonValue *)parse_value_52c7c3cc5fbcb5d9(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),__error_rename_at_201_46));
							if ( __value_rename_at_243_54 == nullptr )
							{
								return das_auto_cast<json::JsonValue *>::cast(nullptr);
							} else {
								if ( !das_global<bool,0x30e401a8d3210d31>(__context__) /*allow_duplicate_keys*/ && _FuncbuiltinTickkey_exists_cf25dd2b3c15ad2(__context__,das_arg<TTable<char *,json::JsonValue *>>::pass(__tab_rename_at_233_52),__key_rename_at_240_53) )
								{
									das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<6>(__tinfo_8, cast<char * const >::from(((char *) "duplicate key ")), cast<char * const >::from(__key_rename_at_240_53), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
									return das_auto_cast<json::JsonValue *>::cast(nullptr);
								} else {
									das_copy(__tab_rename_at_233_52(__key_rename_at_240_53,__context__),__value_rename_at_243_54);
									if ( !expect_token_635976e4db59827c(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45),das_arg<json::TokenAt>::pass(__ahead_rename_at_202_47),4,__error_rename_at_201_46) )
									{
										return das_auto_cast<json::JsonValue *>::cast(nullptr);
									} else {
										int32_t __sepsym_rename_at_252_55 = ((int32_t)das_get_variant_field<int32_t,8,4>::as(__ahead_rename_at_202_47.value,__context__));
										if ( __sepsym_rename_at_252_55 == 125 )
										{
											break;
										} else if ( __sepsym_rename_at_252_55 != 44 )
										{
											das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<8>(__tinfo_9, cast<char * const >::from(((char *) "unsepected object seaprator symbol `")), cast<char *>::from(((char *)(to_string_char(__sepsym_rename_at_252_55,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) "` aka ASCII ")), cast<int32_t>::from(__sepsym_rename_at_252_55), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
											return das_auto_cast<json::JsonValue *>::cast(nullptr);
										};
									};
								};
							};
						};
					};
					if ( builtin_iterator_empty(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__itv_rename_at_201_45)) )
					{
						das_copy(__error_rename_at_201_46,((char *) "unexpected eos"));
						return das_auto_cast<json::JsonValue *>::cast(nullptr);
					} else {
						return das_auto_cast<json::JsonValue *>::cast(JV_f17b12e37633850f(__context__,das_arg<TTable<char *,json::JsonValue *>>::pass(__tab_rename_at_233_52)));
					};
				} else {
					das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<8>(__tinfo_10, cast<char * const >::from(((char *) "unexpected symbol `")), cast<char *>::from(((char *)(to_string_char(__sym_rename_at_206_48,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) "` aka ASCII ")), cast<int32_t>::from(__sym_rename_at_206_48), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
					return das_auto_cast<json::JsonValue *>::cast(nullptr);
				};
			};
		} else if ( das_get_variant_field<char *,8,0>::is(__ahead_rename_at_202_47.value) )
		{
			return das_auto_cast<json::JsonValue *>::cast(JV_329cd26089c5824a(__context__,das_get_variant_field<char *,8,0>::as(__ahead_rename_at_202_47.value,__context__)));
		} else if ( das_get_variant_field<double,8,1>::is(__ahead_rename_at_202_47.value) )
		{
			return das_auto_cast<json::JsonValue *>::cast(JV_ee50ad9073b68df9(__context__,das_get_variant_field<double,8,1>::as(__ahead_rename_at_202_47.value,__context__)));
		} else if ( das_get_variant_field<bool,8,2>::is(__ahead_rename_at_202_47.value) )
		{
			return das_auto_cast<json::JsonValue *>::cast(JV_24a62d4c91875cf(__context__,das_get_variant_field<bool,8,2>::as(__ahead_rename_at_202_47.value,__context__)));
		} else if ( das_get_variant_field<void *,8,3>::is(__ahead_rename_at_202_47.value) )
		{
			return das_auto_cast<json::JsonValue *>::cast(JVNull_f69e3effb8bc1460(__context__));
		} else {
			das_copy(__error_rename_at_201_46,das_string_builder(__context__,SimNode_AotInterop<5>(__tinfo_11, cast<TVariant<16,8,char *,double,bool,void *,int32_t,char *> &>::from(__ahead_rename_at_202_47.value), cast<char * const >::from(((char *) " at ")), cast<int32_t>::from(__ahead_rename_at_202_47.line), cast<char * const >::from(((char *) ":")), cast<int32_t>::from(__ahead_rename_at_202_47.row))));
			return das_auto_cast<json::JsonValue *>::cast(nullptr);
		};
	};
}

inline json::JsonValue * read_json_219e262ed6d50eb2 ( Context * __context__, char * const  __text_rename_at_277_56, char * & __error_rename_at_277_57 )
{
	das_copy(__error_rename_at_277_57,nullptr);
	Sequence DAS_COMMENT((json::TokenAt)) __lex_rename_at_281_58; das_zero(__lex_rename_at_281_58); das_move(__lex_rename_at_281_58, lexer_39488dd6989f2b17(__context__,__text_rename_at_277_56));
	json::JsonValue * __res_rename_at_282_59 = ((json::JsonValue *)parse_value_52c7c3cc5fbcb5d9(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__lex_rename_at_281_58),__error_rename_at_277_57));
	builtin_iterator_delete(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__lex_rename_at_281_58),__context__);
	return das_auto_cast<json::JsonValue *>::cast(__res_rename_at_282_59);
}

inline json::JsonValue * read_json_54b09556094ae79b ( Context * __context__, TArray<uint8_t> const  &  __text_rename_at_286_60, char * & __error_rename_at_286_61 )
{
	das_copy(__error_rename_at_286_61,nullptr);
	Sequence DAS_COMMENT((json::TokenAt)) __lex_rename_at_288_62; das_zero(__lex_rename_at_288_62); das_move(__lex_rename_at_288_62, lexer_8ed723004bb8d8ed(__context__,__text_rename_at_286_60));
	json::JsonValue * __res_rename_at_289_63 = ((json::JsonValue *)parse_value_52c7c3cc5fbcb5d9(__context__,das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__lex_rename_at_288_62),__error_rename_at_286_61));
	builtin_iterator_delete(das_arg<Sequence DAS_COMMENT((json::TokenAt))>::pass(__lex_rename_at_288_62),__context__);
	return das_auto_cast<json::JsonValue *>::cast(__res_rename_at_289_63);
}

inline bool set_no_trailing_zeros_15990b1c21051684 ( Context * __context__, bool __value_rename_at_295_64 )
{
	bool __old_ntz_rename_at_297_65 = ((bool)das_global<bool,0xd3b8b85b9bf19183>(__context__) /*no_trailing_zeros*/);
	das_copy(das_global<bool,0xd3b8b85b9bf19183>(__context__) /*no_trailing_zeros*/,__value_rename_at_295_64);
	return das_auto_cast<bool>::cast(__old_ntz_rename_at_297_65);
}

inline bool set_no_empty_arrays_b9b9e410fb9ff5d4 ( Context * __context__, bool __value_rename_at_303_66 )
{
	bool __old_nea_rename_at_305_67 = ((bool)das_global<bool,0xab7f08dbdeea5c03>(__context__) /*no_empty_arrays*/);
	das_copy(das_global<bool,0xab7f08dbdeea5c03>(__context__) /*no_empty_arrays*/,__value_rename_at_303_66);
	return das_auto_cast<bool>::cast(__old_nea_rename_at_305_67);
}

inline bool set_allow_duplicate_keys_c19ac8de276f7450 ( Context * __context__, bool __value_rename_at_311_68 )
{
	bool __old_adc_rename_at_313_69 = ((bool)das_global<bool,0x30e401a8d3210d31>(__context__) /*allow_duplicate_keys*/);
	das_copy(das_global<bool,0x30e401a8d3210d31>(__context__) /*allow_duplicate_keys*/,__value_rename_at_311_68);
	return das_auto_cast<bool>::cast(__old_adc_rename_at_313_69);
}

inline void write_value_af1db3433ead5c99 ( Context * __context__, StringBuilderWriter &  __writer_rename_at_318_70, json::JsonValue * const  __jsv_rename_at_318_71, int32_t __depth_rename_at_318_72 )
{
	if ( __jsv_rename_at_318_71 == nullptr )
	{
		das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_12,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "null"))));
	} else if ( das_get_variant_field<char *,8,2>::is(__jsv_rename_at_318_71->value) )
	{
		das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_13,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\""))));
		write_escape_string(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),das_get_variant_field<char *,8,2>::as(__jsv_rename_at_318_71->value,__context__));
		das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_14,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\""))));
	} else if ( das_get_variant_field<double,8,3>::is(__jsv_rename_at_318_71->value) )
	{
		if ( das_global<bool,0xd3b8b85b9bf19183>(__context__) /*no_trailing_zeros*/ )
		{
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_15,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char *>::from(((char *)(builtin_string_rtrim_ts(((char *)(builtin_string_rtrim_ts(((char *)(fmt<double>(((char *) ":.17f"),das_get_variant_field<double,8,3>::as(__jsv_rename_at_318_71->value,__context__),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))),((char *) "0"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))),((char *) "."),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))))));
		} else {
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_16,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<double>::from(das_get_variant_field<double,8,3>::as(__jsv_rename_at_318_71->value,__context__))));
		};
	} else if ( das_get_variant_field<TArray<json::JsonValue *>,8,1>::is(__jsv_rename_at_318_71->value) )
	{
		if ( builtin_array_size(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__jsv_rename_at_318_71->value,__context__)) == 0 )
		{
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_17,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "[]"))));
		} else {
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_18,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "[\n"))));
			bool __first_rename_at_335_73 = true;
			{
				bool __need_loop_336 = true;
				// elem : json::JsonValue? const&
				das_iterator<TArray<json::JsonValue *> const > __elem_iterator(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__jsv_rename_at_318_71->value,__context__));
				json::JsonValue * const  * __elem_rename_at_336_74;
				__need_loop_336 = __elem_iterator.first(__context__,(__elem_rename_at_336_74)) && __need_loop_336;
				for ( ; __need_loop_336 ; __need_loop_336 = __elem_iterator.next(__context__,(__elem_rename_at_336_74)) )
				{
					if ( __first_rename_at_335_73 )
					{
						das_copy(__first_rename_at_335_73,false);
					} else {
						das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_19,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) ",\n"))));
					};
					write_string_chars(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),9,__depth_rename_at_318_72 + 1);
					write_value_af1db3433ead5c99(__context__,das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),(*__elem_rename_at_336_74),__depth_rename_at_318_72 + 1);
				}
				__elem_iterator.close(__context__,(__elem_rename_at_336_74));
			};
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_20,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\n"))));
			write_string_chars(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),9,__depth_rename_at_318_72);
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_21,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "]"))));
		};
	} else if ( das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__jsv_rename_at_318_71->value) )
	{
		if ( builtin_table_size(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__jsv_rename_at_318_71->value,__context__)) == 0 )
		{
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_22,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "{}"))));
		} else {
			Sequence DAS_COMMENT((char * *)) _temp_make_local_352_32_80; _temp_make_local_352_32_80;
			Sequence DAS_COMMENT((json::JsonValue * *)) _temp_make_local_352_60_96; _temp_make_local_352_60_96;
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_23,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "{\n"))));
			bool __first_rename_at_351_75 = true;
			{
				bool __need_loop_352 = true;
				// elemK : string const&
				das_iterator<Sequence DAS_COMMENT((char * const ))> __elemK_iterator((_temp_make_local_352_32_80 = (_FuncbuiltinTickkeys_4c23b7ded3f2ea80(__context__,das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__jsv_rename_at_318_71->value,__context__)))));
				char * const  * __elemK_rename_at_352_78;
				__need_loop_352 = __elemK_iterator.first(__context__,(__elemK_rename_at_352_78)) && __need_loop_352;
				// elemV : json::JsonValue? const&
				das_iterator<Sequence DAS_COMMENT((json::JsonValue * const ))> __elemV_iterator((_temp_make_local_352_60_96 = (_FuncbuiltinTickvalues_3e6d35dc6759defe(__context__,das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__jsv_rename_at_318_71->value,__context__)))));
				json::JsonValue * const  * __elemV_rename_at_352_79;
				__need_loop_352 = __elemV_iterator.first(__context__,(__elemV_rename_at_352_79)) && __need_loop_352;
				for ( ; __need_loop_352 ; __need_loop_352 = __elemK_iterator.next(__context__,(__elemK_rename_at_352_78)) && __elemV_iterator.next(__context__,(__elemV_rename_at_352_79)) )
				{
					if ( das_global<bool,0xab7f08dbdeea5c03>(__context__) /*no_empty_arrays*/ )
					{
						if ( das_get_variant_field<TArray<json::JsonValue *>,8,1>::is((*__elemV_rename_at_352_79)->value) )
						{
							if ( builtin_array_size(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as((*__elemV_rename_at_352_79)->value,__context__)) == 0 )
							{
								continue;
							};
						};
					};
					if ( __first_rename_at_351_75 )
					{
						das_copy(__first_rename_at_351_75,false);
					} else {
						das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_24,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) ",\n"))));
					};
					write_string_chars(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),9,__depth_rename_at_318_72 + 1);
					das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_25,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\""))));
					write_escape_string(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),(*__elemK_rename_at_352_78));
					das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_26,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\" : "))));
					write_value_af1db3433ead5c99(__context__,das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),(*__elemV_rename_at_352_79),__depth_rename_at_318_72 + 1);
				}
				__elemK_iterator.close(__context__,(__elemK_rename_at_352_78));
				__elemV_iterator.close(__context__,(__elemV_rename_at_352_79));
			};
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_27,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "\n"))));
			write_string_chars(das_arg<StringBuilderWriter>::pass(__writer_rename_at_318_70),9,__depth_rename_at_318_72);
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_28,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "}"))));
		};
	} else if ( das_get_variant_field<bool,8,4>::is(__jsv_rename_at_318_71->value) )
	{
		if ( das_get_variant_field<bool,8,4>::as(__jsv_rename_at_318_71->value,__context__) )
		{
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_29,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "true"))));
		} else {
			das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_30,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "false"))));
		};
	} else if ( das_get_variant_field<void *,8,5>::is(__jsv_rename_at_318_71->value) )
	{
		das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_31,cast<StringBuilderWriter &>::from(__writer_rename_at_318_70),cast<char * const >::from(((char *) "null"))));
	} else {
		builtin_throw(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_32, cast<char * const >::from(((char *) "unexpected ")), cast<json::JsonValue * const >::from(__jsv_rename_at_318_71))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
}

inline char * write_json_1409f758946db648 ( Context * __context__, json::JsonValue * const  __val_rename_at_379_80 )
{
	char * __st_rename_at_381_81 = ((char *)(char *)(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_381_82) DAS_AOT_INLINE_LAMBDA -> void{
		write_value_af1db3433ead5c99(__context__,das_arg<StringBuilderWriter>::pass(__writer_rename_at_381_82),__val_rename_at_379_80,0);
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
	return das_auto_cast<char *>::cast(__st_rename_at_381_81);
}

inline char * write_json_60bd09829b393a34 ( Context * __context__, json::JsonValue * const  __val_rename_at_385_83 )
{
	return das_auto_cast<char *>::cast(write_json_1409f758946db648(__context__,das_cast<json::JsonValue *>::cast(__val_rename_at_385_83)));
}

inline char * try_fixing_broken_json_fc38694030c41593 ( Context * __context__, char * __bad_rename_at_390_84 ) { das_stack_prologue __prologue(__context__,272,"try_fixing_broken_json " DAS_FILE_LINE);
{
	return das_auto_cast<char *>::cast(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_396_85) DAS_AOT_INLINE_LAMBDA -> void{
		builtin_string_peek(__bad_rename_at_390_84,das_make_block<void,TArray<uint8_t> const  &>(__context__,144,0,&__func_info__5a16898e20f97124,[&](TArray<uint8_t> const  & __str_rename_at_397_86) -> void{
			int32_t __i_rename_at_398_87 = 0;
			int32_t __lstr_rename_at_399_88 = ((int32_t)builtin_array_size(__str_rename_at_397_86));
			while ( __i_rename_at_398_87 < __lstr_rename_at_399_88 )
			{
				while ( (__i_rename_at_398_87 < __lstr_rename_at_399_88) && (das_nequ_val(__str_rename_at_397_86(__i_rename_at_398_87,__context__),0x22)) )
				{
					if ( das_equ_val(__str_rename_at_397_86(__i_rename_at_398_87,__context__),0x2c) )
					{
						int32_t __j_rename_at_404_89 = (__i_rename_at_398_87 + 1);
						while ( (__j_rename_at_404_89 < __lstr_rename_at_399_88) && is_white_space(int32_t(__str_rename_at_397_86(__j_rename_at_404_89,__context__))) )
						{
							++__j_rename_at_404_89;
						};
						if ( (__j_rename_at_404_89 < __lstr_rename_at_399_88) && ((das_equ_val(__str_rename_at_397_86(__j_rename_at_404_89,__context__),0x7d)) || (das_equ_val(__str_rename_at_397_86(__j_rename_at_404_89,__context__),0x5d))) )
						{
							das_copy(__i_rename_at_398_87,__j_rename_at_404_89);
							continue;
						};
					};
					if ( (das_equ_val(__str_rename_at_397_86(__i_rename_at_398_87,__context__),0x5c)) && (das_equ_val(__str_rename_at_397_86((__i_rename_at_398_87 + 1),__context__),0x75)) )
					{
						__i_rename_at_398_87 += 2;
						while ( (__i_rename_at_398_87 < __lstr_rename_at_399_88) && das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),int32_t(__str_rename_at_397_86(__i_rename_at_398_87,__context__))) )
						{
							++__i_rename_at_398_87;
						};
						continue;
					} else {
						write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),int32_t(__str_rename_at_397_86(__i_rename_at_398_87,__context__)));
						++__i_rename_at_398_87;
					};
				};
				if ( __i_rename_at_398_87 >= __lstr_rename_at_399_88 )
				{
					break;
				} else {
					write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
					++__i_rename_at_398_87;
					label_0:;;
					while ( (__i_rename_at_398_87 < __lstr_rename_at_399_88) && (das_nequ_val(__str_rename_at_397_86(__i_rename_at_398_87,__context__),0x22)) )
					{
						write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),int32_t(__str_rename_at_397_86(__i_rename_at_398_87,__context__)));
						++__i_rename_at_398_87;
					};
					if ( __i_rename_at_398_87 >= __lstr_rename_at_399_88 )
					{
						write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
						break;
					} else {
						int32_t __nested_rename_at_431_90 = ((int32_t)__i_rename_at_398_87);
						int32_t __j_rename_at_432_91 = (__i_rename_at_398_87 + 1);
						bool __any_white_space_rename_at_433_92 = ((bool)((__j_rename_at_432_91 < __lstr_rename_at_399_88) && is_white_space(int32_t(__str_rename_at_397_86(__j_rename_at_432_91,__context__)))));
						while ( (__j_rename_at_432_91 < __lstr_rename_at_399_88) && is_white_space(int32_t(__str_rename_at_397_86(__j_rename_at_432_91,__context__))) )
						{
							++__j_rename_at_432_91;
						};
						if ( __j_rename_at_432_91 >= __lstr_rename_at_399_88 )
						{
							write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
							break;
						} else {
							int32_t __strj_rename_at_440_93 = ((int32_t)int32_t(__str_rename_at_397_86(__j_rename_at_432_91,__context__)));
							if ( (((__strj_rename_at_440_93 == 58) || (__strj_rename_at_440_93 == 125)) || (__strj_rename_at_440_93 == 93)) || (__strj_rename_at_440_93 == 44) )
							{
								write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
								++__i_rename_at_398_87;
								continue;
							} else {
								if ( __strj_rename_at_440_93 == 43 )
								{
									++__j_rename_at_432_91;
									while ( (__j_rename_at_432_91 < __lstr_rename_at_399_88) && is_white_space(int32_t(__str_rename_at_397_86(__j_rename_at_432_91,__context__))) )
									{
										++__j_rename_at_432_91;
									};
									if ( (__j_rename_at_432_91 < __lstr_rename_at_399_88) && (das_equ_val(__str_rename_at_397_86(__j_rename_at_432_91,__context__),0x22)) )
									{
										write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),32);
										das_copy(__i_rename_at_398_87,__j_rename_at_432_91 + 1);
										goto label_0;
									};
								};
								if ( __any_white_space_rename_at_433_92 )
								{
									write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
									write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),44);
									das_copy(__i_rename_at_398_87,__nested_rename_at_431_90 + 1);
									continue;
								} else {
									das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_33,cast<StringBuilderWriter &>::from(__writer_rename_at_396_85),cast<char * const >::from(((char *) "`"))));
									das_copy(__i_rename_at_398_87,__nested_rename_at_431_90 + 1);
									while ( (__i_rename_at_398_87 < __lstr_rename_at_399_88) && (das_nequ_val(__str_rename_at_397_86(__i_rename_at_398_87,__context__),0x22)) )
									{
										write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),int32_t(__str_rename_at_397_86(__i_rename_at_398_87,__context__)));
										++__i_rename_at_398_87;
									};
									if ( __i_rename_at_398_87 >= __lstr_rename_at_399_88 )
									{
										das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_34,cast<StringBuilderWriter &>::from(__writer_rename_at_396_85),cast<char * const >::from(((char *) "`"))));
										write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_396_85),34);
										break;
									} else {
										das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_35,cast<StringBuilderWriter &>::from(__writer_rename_at_396_85),cast<char * const >::from(((char *) "`"))));
										++__i_rename_at_398_87;
										goto label_0;
									};
								};
							};
						};
					};
				};
			};
		}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncbuiltinTickfinalize_fc512ae94293239c
	aotLib[0x1870a6cbc501096] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> &  ),&_FuncbuiltinTickfinalize_fc512ae94293239c>>();
	};
	// finalize_82f08cc1e896a8bd
	aotLib[0x71c10e40a84956f9] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, json::_lambda_json_83_8_1 &  ),&finalize_82f08cc1e896a8bd>>();
	};
	// _FuncbuiltinTickeach_27d16e1262d1b229
	aotLib[0xc4c423b5a27b6d07] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((json::TokenAt)) (*) ( Context * __context__, Lambda DAS_COMMENT((bool,json::TokenAt)) const   ),&_FuncbuiltinTickeach_27d16e1262d1b229>>();
	};
	// _FuncbuiltinTicknext_6a3c01874ce3fb9a
	aotLib[0x216a1c03c5a0e75f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((int32_t)) const  & , int32_t &  ),&_FuncbuiltinTicknext_6a3c01874ce3fb9a>>();
	};
	// _FuncbuiltinTickeach_8318d56a25a6cc77
	aotLib[0xd13e774344d548f4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((int32_t)) (*) ( Context * __context__, char * const   ),&_FuncbuiltinTickeach_8318d56a25a6cc77>>();
	};
	// _FuncbuiltinTickpush_96b6a7003d9304b3
	aotLib[0x4f38c85234eb9e39] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<uint8_t> & , uint8_t  ),&_FuncbuiltinTickpush_96b6a7003d9304b3>>();
	};
	// _Func_lambda_json_83_8_1Tickfunction_37d151c582262773
	aotLib[0xa27f58fe62311546] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, json::_lambda_json_83_8_1 & , json::TokenAt &  ),&_Func_lambda_json_83_8_1Tickfunction_37d151c582262773>>();
	};
	// _Func_lambda_json_83_8_1Tickfinalizer_dcd53e507a1a3c40
	aotLib[0x824c1c6688b5e853] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, json::_lambda_json_83_8_1 *  ),&_Func_lambda_json_83_8_1Tickfinalizer_dcd53e507a1a3c40>>();
	};
	// _FuncbuiltinTicknext_855e99bab709e1b2
	aotLib[0x2eed2673f980dec9] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) const  & , json::TokenAt &  ),&_FuncbuiltinTicknext_855e99bab709e1b2>>();
	};
	// _FuncbuiltinTickpush_3e00b4846594a0ae
	aotLib[0xff36febeacb0769b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<json::JsonValue *> & , json::JsonValue * const   ),&_FuncbuiltinTickpush_3e00b4846594a0ae>>();
	};
	// _FuncbuiltinTickkey_exists_cf25dd2b3c15ad2
	aotLib[0x746253a5db4da9fb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TTable<char *,json::JsonValue *> const  & , char * const   ),&_FuncbuiltinTickkey_exists_cf25dd2b3c15ad2>>();
	};
	// _FuncbuiltinTickkeys_4c23b7ded3f2ea80
	aotLib[0x589af9fae5dd95d1] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((char * &)) (*) ( Context * __context__, TTable<char *,json::JsonValue *> const  &  ),&_FuncbuiltinTickkeys_4c23b7ded3f2ea80>>();
	};
	// _FuncbuiltinTickvalues_3e6d35dc6759defe
	aotLib[0x25cbfe4b2591fcf3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((json::JsonValue * &)) (*) ( Context * __context__, TTable<char *,json::JsonValue *> const  &  ),&_FuncbuiltinTickvalues_3e6d35dc6759defe>>();
	};
	// JV_329cd26089c5824a
	aotLib[0xdc34c0ab5602f245] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, char * const   ),&JV_329cd26089c5824a>>();
	};
	// JV_ee50ad9073b68df9
	aotLib[0x11da2620b9a6b94a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, double  ),&JV_ee50ad9073b68df9>>();
	};
	// JV_24a62d4c91875cf
	aotLib[0x799f3e518c245520] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, bool  ),&JV_24a62d4c91875cf>>();
	};
	// JVNull_f69e3effb8bc1460
	aotLib[0xd6d00aa7ff992147] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__ ),&JVNull_f69e3effb8bc1460>>();
	};
	// JV_f17b12e37633850f
	aotLib[0x1df0439ae2fe450e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, TTable<char *,json::JsonValue *> &  ),&JV_f17b12e37633850f>>();
	};
	// JV_bfd94f47b31832f5
	aotLib[0x389e43cdfc902a10] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, TArray<json::JsonValue *> &  ),&JV_bfd94f47b31832f5>>();
	};
	// lexer_39488dd6989f2b17
	aotLib[0xb44c08d60a3559bc] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((json::TokenAt)) (*) ( Context * __context__, char * const   ),&lexer_39488dd6989f2b17>>();
	};
	// lexer_8ed723004bb8d8ed
	aotLib[0x623fff43f90295a3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((json::TokenAt)) (*) ( Context * __context__, TArray<uint8_t> const  &  ),&lexer_8ed723004bb8d8ed>>();
	};
	// next_9642357cb214e878
	aotLib[0x5abc7e7572892803] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((int32_t)) & , int32_t & , int32_t & , int32_t &  ),&next_9642357cb214e878>>();
	};
	// _lexer_4f11d386d9c23d9f
	aotLib[0xdc2d7520d2217ed6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((json::TokenAt)) (*) ( Context * __context__, char *  ),&_lexer_4f11d386d9c23d9f>>();
	};
	// expect_token_635976e4db59827c
	aotLib[0x92e378bc6d746955] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & , json::TokenAt & , int32_t , char * &  ),&expect_token_635976e4db59827c>>();
	};
	// expect_symbol_30e11ef1fad447a4
	aotLib[0x2563550db3195d39] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & , json::TokenAt & , int32_t , char * &  ),&expect_symbol_30e11ef1fad447a4>>();
	};
	// parse_value_52c7c3cc5fbcb5d9
	aotLib[0xe667477e2b4eb87d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, Sequence DAS_COMMENT((json::TokenAt)) & , char * &  ),&parse_value_52c7c3cc5fbcb5d9>>();
	};
	// read_json_219e262ed6d50eb2
	aotLib[0x37f29610dc194471] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, char * const  , char * &  ),&read_json_219e262ed6d50eb2>>();
	};
	// read_json_54b09556094ae79b
	aotLib[0x761469f3af5a0ac6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, TArray<uint8_t> const  & , char * &  ),&read_json_54b09556094ae79b>>();
	};
	// set_no_trailing_zeros_15990b1c21051684
	aotLib[0x5690883c16749df9] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, bool  ),&set_no_trailing_zeros_15990b1c21051684>>();
	};
	// set_no_empty_arrays_b9b9e410fb9ff5d4
	aotLib[0xcd97d3c6da8749bf] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, bool  ),&set_no_empty_arrays_b9b9e410fb9ff5d4>>();
	};
	// set_allow_duplicate_keys_c19ac8de276f7450
	aotLib[0xc3c51f7ccccdf15f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, bool  ),&set_allow_duplicate_keys_c19ac8de276f7450>>();
	};
	// write_value_af1db3433ead5c99
	aotLib[0x818903bc7ece0c25] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, StringBuilderWriter & , json::JsonValue * const  , int32_t  ),&write_value_af1db3433ead5c99>>();
	};
	// write_json_1409f758946db648
	aotLib[0x2e2e6527769d422] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, json::JsonValue * const   ),&write_json_1409f758946db648>>();
	};
	// write_json_60bd09829b393a34
	aotLib[0xae904d151624f433] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, json::JsonValue * const   ),&write_json_60bd09829b393a34>>();
	};
	// try_fixing_broken_json_fc38694030c41593
	aotLib[0x3d89b5dbf10ea05b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, char *  ),&try_fixing_broken_json_fc38694030c41593>>();
	};
	// [[ init script ]]
	aotLib[0x9b6e94d9f096d966] = [&](Context & ctx){
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
