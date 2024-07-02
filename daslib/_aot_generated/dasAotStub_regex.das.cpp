#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require regex
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
namespace _anon_13599512127358541634 {

extern StructInfo __struct_info__a442c67b1b45039e;
extern StructInfo __struct_info__739e0aa00b63f5bf;
extern TypeInfo __type_info__af63e84c860200f0;
extern TypeInfo __type_info__e68681b2b99a9c9a;
extern TypeInfo __type_info__37d36026a6078a42;
extern TypeInfo __type_info__d83b8da409a209eb;
extern TypeInfo __type_info__8cbf7e31d94517eb;
extern TypeInfo __type_info__646c01d58047ed68;
extern TypeInfo __type_info__21ea97d8ca8ffd5;
extern TypeInfo __type_info__af8afe4c86446b52;
extern TypeInfo __type_info__af63eb4c86020609;
extern TypeInfo __type_info__af5be84c85f468f0;
extern TypeInfo __type_info__9c60f9702c7c9014;
extern TypeInfo __type_info__26743f04eabb8f4f;
extern TypeInfo __type_info__af63ee4c86020b22;
extern TypeInfo __type_info__af90fe4c864e9d52;
extern TypeInfo __type_info__634d658d3d3c73e9;
extern TypeInfo __type_info__6efe4a274318358b;
extern TypeInfo __type_info__af63ef4c86020cd5;
extern VarInfo __var_info__f06990a7cd9b8e8c;
extern VarInfo __var_info__552745cc023ad889;
extern VarInfo __var_info__e2757da7c183c939;
extern VarInfo __var_info__c248c77e17cca11a;
extern VarInfo __var_info__90ed0cbd06831825;
extern VarInfo __var_info__7ce5b1477861b3d1;
extern VarInfo __var_info__9be1db3446ee3f1b;
extern VarInfo __var_info__4f1b9e3acf383cbd;
extern VarInfo __var_info__553347cc024f3fef;
extern VarInfo __var_info__125ea9a7ea60fe3a;
extern VarInfo __var_info__f02e80a7cd1d35eb;
extern VarInfo __var_info__6eee618b86e51341;
extern VarInfo __var_info__55374dcc02561621;
extern VarInfo __var_info__7df7ea7e12e9cd7;
extern VarInfo __var_info__aa30cda461a0c553;
extern VarInfo __var_info__5f2ead14c0ff50c1;
extern VarInfo __var_info__26a69ea7fb7ba40e;
extern VarInfo __var_info__f05876a7cd78b90c;
extern VarInfo __var_info__f05d8ca7cd9876b6;
extern VarInfo __var_info__37de19b6affa3dd6;
extern VarInfo __var_info__5fe75b5def0592e0;
extern FuncInfo __func_info__8b6d6c464a360a4f;
extern EnumInfo __enum_info__f5eadb7b60b9c74d;

EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_0 = { "Char", 0 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_1 = { "Set", 1 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_2 = { "Any", 2 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_3 = { "Eos", 3 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_4 = { "Group", 4 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_5 = { "Plus", 5 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_6 = { "Star", 6 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_7 = { "Question", 7 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_8 = { "Concat", 8 };
EnumValueInfo __enum_info__f5eadb7b60b9c74d_value_9 = { "Union", 9 };
EnumValueInfo * __enum_info__f5eadb7b60b9c74d_values [] = { &__enum_info__f5eadb7b60b9c74d_value_0, &__enum_info__f5eadb7b60b9c74d_value_1, &__enum_info__f5eadb7b60b9c74d_value_2, &__enum_info__f5eadb7b60b9c74d_value_3, &__enum_info__f5eadb7b60b9c74d_value_4, &__enum_info__f5eadb7b60b9c74d_value_5, &__enum_info__f5eadb7b60b9c74d_value_6, &__enum_info__f5eadb7b60b9c74d_value_7, &__enum_info__f5eadb7b60b9c74d_value_8, &__enum_info__f5eadb7b60b9c74d_value_9 };
EnumInfo __enum_info__f5eadb7b60b9c74d = { "ReOp", "regex", __enum_info__f5eadb7b60b9c74d_values, 10, UINT64_C(0xf5eadb7b60b9c74d) };
VarInfo __struct_info__a442c67b1b45039e_field_0 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x37de19b6affa3dd6), "root", 0, 1 };
VarInfo __struct_info__a442c67b1b45039e_field_1 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 8204, 8, UINT64_C(0x90ed0cbd06831825), "match", 8, 2 };
VarInfo __struct_info__a442c67b1b45039e_field_2 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__6efe4a274318358b, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 24, UINT64_C(0x6eee618b86e51341), "groups", 16, 5 };
uint32_t __type_info__aa30cda461a0c553_dim_var_11836241002723869598[1] = { 8 };
VarInfo __struct_info__a442c67b1b45039e_field_3 =  { Type::tUInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 1, __type_info__aa30cda461a0c553_dim_var_11836241002723869598, 30, 32, UINT64_C(0xaa30cda461a0c553), "earlyOut", 40, 0 };
VarInfo __struct_info__a442c67b1b45039e_field_4 =  { Type::tBool, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0x7ce5b1477861b3d1), "canEarlyOut", 72, 0 };
VarInfo * __struct_info__a442c67b1b45039e_fields[5] =  { &__struct_info__a442c67b1b45039e_field_0, &__struct_info__a442c67b1b45039e_field_1, &__struct_info__a442c67b1b45039e_field_2, &__struct_info__a442c67b1b45039e_field_3, &__struct_info__a442c67b1b45039e_field_4 };
StructInfo __struct_info__a442c67b1b45039e = {"Regex", "regex", 28, __struct_info__a442c67b1b45039e_fields, 5, 80, UINT64_C(0x0), nullptr, UINT64_C(0xa442c67b1b45039e), 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_0 =  { Type::tEnumeration, nullptr, &__enum_info__f5eadb7b60b9c74d, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x553347cc024f3fef), "op", 0, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_1 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x552745cc023ad889), "id", 4, 0 };
TypeInfo * __type_info__26a69ea7fb7ba40e_arg_types_var_8331108043184141759[3] = { &__type_info__21ea97d8ca8ffd5, &__type_info__8cbf7e31d94517eb, &__type_info__d83b8da409a209eb };
const char * __type_info__26a69ea7fb7ba40e_arg_names_var_8331108043184141759[3] = { "regex", "node", "str" };
VarInfo __struct_info__739e0aa00b63f5bf_field_2 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__26743f04eabb8f4f, nullptr, (TypeInfo **)__type_info__26a69ea7fb7ba40e_arg_types_var_8331108043184141759, __type_info__26a69ea7fb7ba40e_arg_names_var_8331108043184141759, 3, 0, nullptr, 12, 8, UINT64_C(0x26a69ea7fb7ba40e), "fun2", 8, 0 };
TypeInfo * __type_info__f02e80a7cd1d35eb_arg_types_var_8331108043184141759[3] = { &__type_info__8cbf7e31d94517eb, &__type_info__646c01d58047ed68, &__type_info__37d36026a6078a42 };
const char * __type_info__f02e80a7cd1d35eb_arg_names_var_8331108043184141759[3] = { "node", "rnd", "str" };
VarInfo __struct_info__739e0aa00b63f5bf_field_3 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__af63eb4c86020609, nullptr, (TypeInfo **)__type_info__f02e80a7cd1d35eb_arg_types_var_8331108043184141759, __type_info__f02e80a7cd1d35eb_arg_names_var_8331108043184141759, 3, 0, nullptr, 12, 8, UINT64_C(0xf02e80a7cd1d35eb), "gen2", 16, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_4 =  { Type::tRange, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 8, UINT64_C(0x55374dcc02561621), "at", 24, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_5 =  { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0xf05d8ca7cd9876b6), "text", 32, 7 };
VarInfo __struct_info__739e0aa00b63f5bf_field_6 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x5fe75b5def0592e0), "textLen", 40, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_7 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__8cbf7e31d94517eb, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 24, UINT64_C(0x7df7ea7e12e9cd7), "all", 48, 8 };
VarInfo __struct_info__739e0aa00b63f5bf_field_8 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0xf05876a7cd78b90c), "left", 72, 9 };
VarInfo __struct_info__739e0aa00b63f5bf_field_9 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x9be1db3446ee3f1b), "right", 80, 10 };
VarInfo __struct_info__739e0aa00b63f5bf_field_10 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x5f2ead14c0ff50c1), "subexpr", 88, 11 };
VarInfo __struct_info__739e0aa00b63f5bf_field_11 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0xf06990a7cd9b8e8c), "next", 96, 14 };
uint32_t __type_info__125ea9a7ea60fe3a_dim_var_8331108043184141759[1] = { 8 };
VarInfo __struct_info__739e0aa00b63f5bf_field_12 =  { Type::tUInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 1, __type_info__125ea9a7ea60fe3a_dim_var_8331108043184141759, 30, 32, UINT64_C(0x125ea9a7ea60fe3a), "cset", 104, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_13 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x4f1b9e3acf383cbd), "index", 136, 0 };
VarInfo __struct_info__739e0aa00b63f5bf_field_14 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 8204, 8, UINT64_C(0xe2757da7c183c939), "tail", 144, 15 };
VarInfo * __struct_info__739e0aa00b63f5bf_fields[15] =  { &__struct_info__739e0aa00b63f5bf_field_0, &__struct_info__739e0aa00b63f5bf_field_1, &__struct_info__739e0aa00b63f5bf_field_2, &__struct_info__739e0aa00b63f5bf_field_3, &__struct_info__739e0aa00b63f5bf_field_4, &__struct_info__739e0aa00b63f5bf_field_5, &__struct_info__739e0aa00b63f5bf_field_6, &__struct_info__739e0aa00b63f5bf_field_7, &__struct_info__739e0aa00b63f5bf_field_8, &__struct_info__739e0aa00b63f5bf_field_9, &__struct_info__739e0aa00b63f5bf_field_10, &__struct_info__739e0aa00b63f5bf_field_11, &__struct_info__739e0aa00b63f5bf_field_12, &__struct_info__739e0aa00b63f5bf_field_13, &__struct_info__739e0aa00b63f5bf_field_14 };
StructInfo __struct_info__739e0aa00b63f5bf = {"ReNode", "regex", 28, __struct_info__739e0aa00b63f5bf_fields, 15, 152, UINT64_C(0x0), nullptr, UINT64_C(0x739e0aa00b63f5bf), 5 };
VarInfo __func_info__8b6d6c464a360a4f_field_0 =  { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0xc248c77e17cca11a), "node", 0, 0 };
VarInfo * __func_info__8b6d6c464a360a4f_fields[1] =  { &__func_info__8b6d6c464a360a4f_field_0 };
FuncInfo __func_info__8b6d6c464a360a4f = {"invoke block<(var node:regex::ReNode?):void> const", "", __func_info__8b6d6c464a360a4f_fields, 1, 32, &__type_info__af63eb4c86020609, nullptr,0,UINT64_C(0x8b6d6c464a360a4f), 0x0 };
TypeInfo __type_info__af63e84c860200f0 = { Type::tUInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xaf63e84c860200f0) };
TypeInfo __type_info__e68681b2b99a9c9a = { Type::tStructure, &__struct_info__739e0aa00b63f5bf, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 152, UINT64_C(0xe68681b2b99a9c9a) };
TypeInfo __type_info__37d36026a6078a42 = { Type::tHandle, nullptr, nullptr, DAS_MAKE_ANNOTATION("~strings::StringBuilderWriter"), nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 2, 288, UINT64_C(0x37d36026a6078a42) };
TypeInfo __type_info__d83b8da409a209eb = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 8236, 8, UINT64_C(0xd83b8da409a209eb) };
TypeInfo __type_info__8cbf7e31d94517eb = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__e68681b2b99a9c9a, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x8cbf7e31d94517eb) };
TypeInfo __type_info__646c01d58047ed68 = { Type::tIterator, nullptr, nullptr, nullptr, &__type_info__af63e84c860200f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 24602, 8, UINT64_C(0x646c01d58047ed68) };
TypeInfo __type_info__21ea97d8ca8ffd5 = { Type::tStructure, &__struct_info__a442c67b1b45039e, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 80, UINT64_C(0x21ea97d8ca8ffd5) };
TypeInfo __type_info__af8afe4c86446b52 = { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 4, UINT64_C(0xaf8afe4c86446b52) };
TypeInfo __type_info__af63eb4c86020609 = { Type::tVoid, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 0, UINT64_C(0xaf63eb4c86020609) };
TypeInfo __type_info__af5be84c85f468f0 = { Type::tUInt8, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 1, UINT64_C(0xaf5be84c85f468f0) };
TypeInfo __type_info__9c60f9702c7c9014 = { Type::tEnumeration, nullptr, &__enum_info__f5eadb7b60b9c74d, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x9c60f9702c7c9014) };
TypeInfo __type_info__26743f04eabb8f4f = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__af5be84c85f468f0, nullptr, nullptr, nullptr, 0, 0, nullptr, 8204, 8, UINT64_C(0x26743f04eabb8f4f) };
TypeInfo __type_info__af63ee4c86020b22 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0xaf63ee4c86020b22) };
TypeInfo __type_info__af90fe4c864e9d52 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16420, 8, UINT64_C(0xaf90fe4c864e9d52) };
TypeInfo __type_info__634d658d3d3c73e9 = { Type::tStructure, &__struct_info__a442c67b1b45039e, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 80, UINT64_C(0x634d658d3d3c73e9) };
TypeInfo * __type_info__6efe4a274318358b_arg_types[2] = { &__type_info__af63ef4c86020cd5, &__type_info__af63ee4c86020b22 };
TypeInfo __type_info__6efe4a274318358b = { Type::tTuple, nullptr, nullptr, nullptr, nullptr, nullptr, (TypeInfo **)__type_info__6efe4a274318358b_arg_types, nullptr, 2, 0, nullptr, 16390, 16, UINT64_C(0x6efe4a274318358b) };
TypeInfo __type_info__af63ef4c86020cd5 = { Type::tRange, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 8, UINT64_C(0xaf63ef4c86020cd5) };

static void resolveTypeInfoAnnotations()
{
	__type_info__37d36026a6078a42.resolveAnnotation();
}

TypeInfo * __tinfo_0[1] = { &__type_info__634d658d3d3c73e9 };
TypeInfo * __tinfo_1[5] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e84c860200f0 };
TypeInfo * __tinfo_2[4] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e84c860200f0 };
TypeInfo * __tinfo_3[5] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e84c860200f0 };
TypeInfo * __tinfo_4[4] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e84c860200f0 };
TypeInfo * __tinfo_5[4] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52, &__type_info__af63e84c860200f0 };
TypeInfo * __tinfo_6[1] = { &__type_info__af8afe4c86446b52 };
TypeInfo * __tinfo_7[2] = { &__type_info__af90fe4c864e9d52, &__type_info__9c60f9702c7c9014 };
TypeInfo * __tinfo_8[3] = { &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_9[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_10[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_11[3] = { &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_12[1] = { &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_13[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52 };
TypeInfo * __tinfo_14[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52 };
TypeInfo * __tinfo_15[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af8afe4c86446b52 };
TypeInfo * __tinfo_16[3] = { &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_17[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_18[2] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_19[3] = { &__type_info__af90fe4c864e9d52, &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_20[1] = { &__type_info__af63ee4c86020b22 };
TypeInfo * __tinfo_21[2] = { &__type_info__af63ee4c86020b22, &__type_info__af90fe4c864e9d52 };
TypeInfo * __tinfo_22[2] = { &__type_info__37d36026a6078a42, &__type_info__af63ee4c86020b22 };
namespace regex { struct ReNode; };
namespace regex { struct Regex; };
// unused enumeration ConversionResult
namespace regex {

enum class ReOp : int32_t {
	Char = int32_t(0),
	Set = int32_t(1),
	Any = int32_t(2),
	Eos = int32_t(3),
	Group = int32_t(4),
	Plus = int32_t(5),
	Star = int32_t(6),
	Question = int32_t(7),
	Concat = int32_t(8),
	Union = int32_t(9),
};
}
}
template <> struct cast< das::_anon_13599512127358541634::regex::ReOp > : cast_enum < das::_anon_13599512127358541634::regex::ReOp > {};
namespace _anon_13599512127358541634 {
namespace regex {

struct ReNode {
	DAS_COMMENT(enum) regex::ReOp op;
	int32_t id;
	Func DAS_COMMENT((uint8_t *,regex::Regex,regex::ReNode *,uint8_t * const )) fun2;
	Func DAS_COMMENT((void,regex::ReNode *,Sequence DAS_COMMENT((uint32_t)),StringBuilderWriter)) gen2;
	range at;
	char * text;
	int32_t textLen;
	TArray<regex::ReNode *> all;
	regex::ReNode * left;
	regex::ReNode * right;
	regex::ReNode * subexpr;
	regex::ReNode * next;
	TDim<uint32_t,8> cset;
	int32_t index;
	uint8_t * tail;
};
static_assert(sizeof(ReNode)==152,"structure size mismatch with DAS");
static_assert(offsetof(ReNode,op)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,id)==4,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,fun2)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,gen2)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,at)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,text)==32,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,textLen)==40,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,all)==48,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,left)==72,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,right)==80,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,subexpr)==88,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,next)==96,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,cset)==104,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,index)==136,"structure field offset mismatch with DAS");
static_assert(offsetof(ReNode,tail)==144,"structure field offset mismatch with DAS");
}
namespace regex {

struct Regex {
	regex::ReNode * root;
	uint8_t * match;
	TArray<TTuple<16,range,char *>> groups;
	TDim<uint32_t,8> earlyOut;
	bool canEarlyOut;
};
static_assert(sizeof(Regex)==80,"structure size mismatch with DAS");
static_assert(offsetof(Regex,root)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(Regex,match)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(Regex,groups)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(Regex,earlyOut)==40,"structure field offset mismatch with DAS");
static_assert(offsetof(Regex,canEarlyOut)==72,"structure field offset mismatch with DAS");
}

inline void _FuncbuiltinTickresize_648390880f9db2f3 ( Context * __context__, TArray<regex::ReNode *> & __Arr_rename_at_50_0, int32_t __newSize_rename_at_50_1 );
inline void _FuncbuiltinTickfinalize_c949f429586500db ( Context * __context__, TArray<regex::ReNode *> & __a_rename_at_544_2 );
inline int32_t _FuncbuiltinTicklength_7938efcc1bc3eff1 ( Context * __context__, TDim<regex::ReNode *,2> const  & __a_rename_at_267_4 );
inline void finalize_bfa54b0105e1d809 ( Context * __context__, regex::ReNode & ____this_rename_at_27_5 );
inline void _FuncbuiltinTickpush_1336ab62a70ec972 ( Context * __context__, TArray<TTuple<16,range,char *>> & __Arr_rename_at_79_6, TTuple<16,range,char *> const  & __value_rename_at_79_7 );
inline regex::Regex & _FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55 ( Context * __context__, regex::Regex & __a_rename_at_38_8 );
inline int32_t _FuncregexTickfrom_hex_4f3a3d7adb464151 ( Context * __context__, int32_t __ch1_rename_at_196_9, int32_t __ch2_rename_at_196_10 );
inline void finalize_2abcbb928def4524 ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> & ____this_rename_at_342_11 );
inline void finalize_b8b6319fe678761c ( Context * __context__, regex::ReNode * & ____this_rename_at_417_12 );
inline void _FuncbuiltinTickpush_362eabc9d9f1c608 ( Context * __context__, TArray<regex::ReNode *> & __Arr_rename_at_79_13, regex::ReNode * const  __value_rename_at_79_14 );
inline TArray<regex::ReNode *> _FuncbuiltinTickto_array_move_610602215d8cf914 ( Context * __context__, TDim<regex::ReNode *,2> & __a_rename_at_668_15 );
inline bool _FuncbuiltinTicknext_160159e214cdd056 ( Context * __context__, Sequence DAS_COMMENT((uint32_t)) const  & __it_rename_at_573_17, uint32_t & __value_rename_at_573_18 );
inline uint32_t re_gen_get_rep_limit_3aaf29e074018c44 ( Context * __context__ );
inline void trace_89f6695f8909b072 ( Context * __context__, char * const  __msg_rename_at_73_19, int32_t __offset_rename_at_73_20 );
inline void note_89f6695f8909b072 ( Context * __context__, char * const  __msg_rename_at_78_21, int32_t __offset_rename_at_78_22 );
inline void trace_backtrack_c77fe5b3ac1a6a7c ( Context * __context__ );
inline void trace_value_4739abdd3b0a7208 ( Context * __context__, regex::ReNode * const  __value_rename_at_87_23 );
inline TVariant<16,8,regex::ReNode *,void *> nada_5086bd0a540f8186 ( Context * __context__ );
inline TVariant<16,8,regex::ReNode *,void *> maybe_d7a4f325999cb99b ( Context * __context__, regex::ReNode * const  __value_rename_at_98_24 );
inline bool eos_dde6e11fd3802ac8 ( Context * __context__, char * const  __expr_rename_at_102_25, int32_t __offset_rename_at_102_26 );
inline int32_t at_c9bade5ff7edd57d ( Context * __context__, char * const  __expr_rename_at_105_27, int32_t __offset_rename_at_105_28 );
inline int32_t next_1bd07c8c346bbbc2 ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> const  & __re_rename_at_120_29 );
inline bool is_set_empty_fb12252b2129800d ( Context * __context__, TDim<uint32_t,8> const  & __cset_rename_at_126_30 );
inline void set_or_char_471888d9ed78efab ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_132_32, int32_t __ch_rename_at_132_33 );
inline void set_or_range_6e993851d775263 ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_135_34, range __bits_rename_at_135_35 );
inline void set_invert_be791c77bc6b6a11 ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_139_37 );
inline void set_or_set_9609a9e932b32815 ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_143_39, TDim<uint32_t,8> const  & __eset_rename_at_143_40 );
inline void set_negative_7a1fcd94df7d5358 ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_147_45 );
inline void set_meta_cc349e8f6f2b739 ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_151_47, int32_t __che_rename_at_151_48 );
inline bool is_meta_character_24d3d25015b1373f ( Context * __context__, int32_t __ch_rename_at_180_52 );
inline bool is_set_character_11f8fcca4329c870 ( Context * __context__, int32_t __ch_rename_at_183_53 );
inline int32_t from_hex_aec816dc2407436 ( Context * __context__, int32_t __ch_rename_at_186_54 );
inline char * string_from_hex_d2d056a03cdfae17 ( Context * __context__, int32_t __ch1_rename_at_199_55 );
inline char * string_from_hex_58ccb558a2a0b0ed ( Context * __context__, int32_t __ch1_rename_at_202_56, int32_t __ch2_rename_at_202_57 );
inline TVariant<16,8,regex::ReNode *,void *> re_char_dc689de6efe3e576 ( Context * __context__, char * const  __expr_rename_at_206_58, int32_t __offset_rename_at_206_59 );
inline TVariant<16,8,regex::ReNode *,void *> re_set_items_9fb85eb4dd2de0ce ( Context * __context__, char * const  __expr_rename_at_245_66, int32_t __offset_rename_at_245_67 );
inline TVariant<16,8,regex::ReNode *,void *> re_set_60109875d3448735 ( Context * __context__, char * const  __expr_rename_at_328_78, int32_t __offset_rename_at_328_79 );
inline TVariant<16,8,regex::ReNode *,void *> re_any_f6446c9dabb991e5 ( Context * __context__, char * const  __expr_rename_at_354_83, int32_t __offset_rename_at_354_84 );
inline TVariant<16,8,regex::ReNode *,void *> re_eos_ce6b3dba83357e14 ( Context * __context__, char * const  __expr_rename_at_363_85, int32_t __offset_rename_at_363_86 );
inline TVariant<16,8,regex::ReNode *,void *> re_group_73b2a2ffd8d6e095 ( Context * __context__, char * const  __expr_rename_at_372_87, int32_t __offset_rename_at_372_88 );
inline TVariant<16,8,regex::ReNode *,void *> re_elementary_9f9a7e4e2c98fef1 ( Context * __context__, char * const  __expr_rename_at_387_90, int32_t __offset_rename_at_387_91 );
inline regex::ReNode * mk_concat_7baa59a4cd5a0a70 ( Context * __context__, regex::ReNode * __left_rename_at_408_97, regex::ReNode * __right_rename_at_408_98 );
inline regex::ReNode * mk_union_ef2057df16785333 ( Context * __context__, regex::ReNode * __left_rename_at_432_100, regex::ReNode * __right_rename_at_432_101 );
inline TVariant<16,8,regex::ReNode *,void *> re_re_36eba07f5043127c ( Context * __context__, char * const  __expr_rename_at_454_103, int32_t __offset_rename_at_454_104 );
inline TVariant<16,8,regex::ReNode *,void *> re_basic_16364ce684bfd02f ( Context * __context__, char * const  __expr_rename_at_482_109, int32_t __offset_rename_at_482_110 );
inline regex::ReNode * re_parse_dcac85ee353b9cd1 ( Context * __context__, char * const  __expr_rename_at_498_113 );
inline void visit_top_down_ac16ba95cc2d1c98 ( Context * __context__, regex::ReNode * __node_rename_at_508_116, Block DAS_COMMENT((void,regex::ReNode *)) const  & __blk_rename_at_508_117 );
inline void re_assign_next_3b4ea73434aed381 ( Context * __context__, regex::Regex & __re_rename_at_519_119 );
inline void re_assign_groups_6a6962661f0751e2 ( Context * __context__, regex::Regex & __re_rename_at_532_123 );
inline void re_assign_match_functions_8f6d5df970baf66a ( Context * __context__, regex::Regex & __re_rename_at_544_126 );
inline uint8_t * re_match2_single_char_ec4bd67a88d6c383 ( Context * __context__, regex::Regex & __regex_rename_at_588_128, regex::ReNode * __node_rename_at_588_129, uint8_t * const  __str_rename_at_588_130 );
inline uint8_t * re_match2_char_e7712649ef04ae7d ( Context * __context__, regex::Regex & __regex_rename_at_603_133, regex::ReNode * __node_rename_at_603_134, uint8_t * const  __str_rename_at_603_135 );
inline uint8_t * re_match2_union_29c921f92bb6c013 ( Context * __context__, regex::Regex & __regex_rename_at_620_138, regex::ReNode * __node_rename_at_620_139, uint8_t * const  __str_rename_at_620_140 );
inline uint8_t * re_match2_set_a7d14982d3d94062 ( Context * __context__, regex::Regex & __regex_rename_at_631_143, regex::ReNode * __node_rename_at_631_144, uint8_t * const  __str_rename_at_631_145 );
inline uint8_t * re_match2_any_145e1cb203d4af15 ( Context * __context__, regex::Regex & __regex_rename_at_646_148, regex::ReNode * __node_rename_at_646_149, uint8_t * const  __str_rename_at_646_150 );
inline uint8_t * re_match2_concat_aa5a3133a76ae77 ( Context * __context__, regex::Regex & __regex_rename_at_661_153, regex::ReNode * __node_rename_at_661_154, uint8_t * const  __str_rename_at_661_155 );
inline uint8_t * re_match2_eos_e54e018f6fdc2874 ( Context * __context__, regex::Regex & __regex_rename_at_672_158, regex::ReNode * __node_rename_at_672_159, uint8_t * const  __str_rename_at_672_160 );
inline uint8_t * re_match2_question_c6073fc7d021f681 ( Context * __context__, regex::Regex & __regex_rename_at_685_162, regex::ReNode * __node_rename_at_685_163, uint8_t * const  __str_rename_at_685_164 );
inline uint8_t * re_match2_plus_6caa18e9465405bd ( Context * __context__, regex::Regex & __regex_rename_at_700_168, regex::ReNode * __node_rename_at_700_169, uint8_t * const  __str_rename_at_700_170 );
inline uint8_t * re_match2_plus_set_a77e502c2ce10da5 ( Context * __context__, regex::Regex & __regex_rename_at_725_176, regex::ReNode * __node_rename_at_725_177, uint8_t * const  __str_rename_at_725_178 );
inline uint8_t * re_match2_star_9bdcb86ac2e0b3b3 ( Context * __context__, regex::Regex & __regex_rename_at_755_183, regex::ReNode * __node_rename_at_755_184, uint8_t * const  __str_rename_at_755_185 );
inline uint8_t * re_match2_group_64e1ead31a846f3e ( Context * __context__, regex::Regex & __regex_rename_at_778_191, regex::ReNode * __node_rename_at_778_192, uint8_t * const  __str_rename_at_778_193 );
inline bool re_early_out_922d27d5b993b87c ( Context * __context__, TDim<uint32_t,8> & __cset_rename_at_792_196, regex::ReNode * const  __node_rename_at_792_197 );
inline bool is_valid_f341200a6f682e5a ( Context * __context__, regex::Regex & __re_rename_at_831_202 );
inline bool regex_compile_18db32cc7aeccc78 ( Context * __context__, regex::Regex & __re_rename_at_835_203, char * const  __expr_rename_at_835_204 );
inline regex::Regex regex_compile_de8b67e813d240c6 ( Context * __context__, char * const  __expr_rename_at_847_205 );
inline regex::Regex regex_compile_6869b0e89f8c00b1 ( Context * __context__, regex::Regex & __re_rename_at_853_207 );
inline int32_t regex_match_270cb942810fc6f1 ( Context * __context__, regex::Regex & __regex_rename_at_859_208, char * const  __str_rename_at_859_209, int32_t __offset_rename_at_859_210 );
inline char * regex_group_53f438f6c88fd53d ( Context * __context__, regex::Regex const  & __regex_rename_at_873_212, int32_t __index_rename_at_873_213, char * const  __match_rename_at_873_214 );
inline void regex_foreach_31d894777e8f6051 ( Context * __context__, regex::Regex & __regex_rename_at_879_216, char * const  __str_rename_at_879_217, Block DAS_COMMENT((bool,range)) const  & __blk_rename_at_879_218 );
inline char * regex_replace_406545def8f63efd ( Context * __context__, regex::Regex & __regex_rename_at_915_225, char * const  __str_rename_at_915_226, Block DAS_COMMENT((char *,char * const )) const  & __blk_rename_at_915_227 );
inline void regex_debug_1a2f3227d12bb74b ( Context * __context__, regex::Regex const  & __regex_rename_at_958_237 );
inline void debug_set_5bfd1461cc2bf4d3 ( Context * __context__, TDim<uint32_t,8> const  & __cset_rename_at_971_239 );
inline void debug_re_8aa07286a87ace73 ( Context * __context__, regex::ReNode * const  __node_rename_at_980_241, int32_t __tab_rename_at_980_242 );
inline int32_t rnd_set_character_f49e90c9ced30293 ( Context * __context__, TDim<uint32_t,8> const  & __cset_rename_at_1036_244, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1036_245 );
inline void re_gen2_fail_83869989d4feff33 ( Context * __context__, regex::ReNode * __node_rename_at_1043_248, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1043_249, StringBuilderWriter & __str_rename_at_1043_250 );
inline void re_gen2_char_f50387c056fd98bf ( Context * __context__, regex::ReNode * __node_rename_at_1048_251, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1048_252, StringBuilderWriter & __str_rename_at_1048_253 );
inline void re_gen2_union_9643fdb28fe9f09d ( Context * __context__, regex::ReNode * __node_rename_at_1056_255, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1056_256, StringBuilderWriter & __str_rename_at_1056_257 );
inline void re_gen2_set_687ad6fcb132e4de ( Context * __context__, regex::ReNode * __node_rename_at_1065_260, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1065_261, StringBuilderWriter & __str_rename_at_1065_262 );
inline void re_gen2_any_998ffcd284a238dd ( Context * __context__, regex::ReNode * __node_rename_at_1073_264, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1073_265, StringBuilderWriter & __str_rename_at_1073_266 );
inline void re_gen2_concat_2acaded76c0d6fe4 ( Context * __context__, regex::ReNode * __node_rename_at_1083_269, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1083_270, StringBuilderWriter & __str_rename_at_1083_271 );
inline void re_gen2_eos_b4ed344d74735b22 ( Context * __context__, regex::ReNode * __node_rename_at_1089_273, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1089_274, StringBuilderWriter & __str_rename_at_1089_275 );
inline void re_gen2_question_23526c1a36f227c7 ( Context * __context__, regex::ReNode * __node_rename_at_1096_277, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1096_278, StringBuilderWriter & __str_rename_at_1096_279 );
inline void re_gen2_plus_76879af5add2064f ( Context * __context__, regex::ReNode * __node_rename_at_1109_283, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1109_284, StringBuilderWriter & __str_rename_at_1109_285 );
inline void re_gen2_star_2b17ac0e3bbfc0b0 ( Context * __context__, regex::ReNode * __node_rename_at_1123_290, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1123_291, StringBuilderWriter & __str_rename_at_1123_292 );
inline void re_gen2_group_220ee7b205b18ab6 ( Context * __context__, regex::ReNode * __node_rename_at_1137_297, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1137_298, StringBuilderWriter & __str_rename_at_1137_299 );
inline char * re_gen_782e537f3d526983 ( Context * __context__, regex::Regex & __re_rename_at_1147_302, Sequence DAS_COMMENT((uint32_t)) & __rnd_rename_at_1147_303 );

void __init_script ( Context * __context__, bool __init_shared )
{
	das_global<bool,0xef68509581809424>(__context__) = false;/*log_parse_enabled*/
	das_global<bool,0xa970cdba254dba34>(__context__) = false;/*log_match_enabled*/
	das_global<bool,0xa65624a8416952c2>(__context__) = false;/*range_check_enabled*/
	das_global<bool,0x79de6c82fae2b617>(__context__) = false;/*log_gen_enabled*/
	das_global<int32_t,0x3cc0153fc83ffc69>(__context__) = 0;/*trace_tab*/
	das_global<uint32_t,0x8ce995ce57e18608>(__context__) = 0x8u;/*re_gen_rep_limit*/
	das_global<char *,0xa1ce201dbf46e0ab>(__context__) = ((char *) "\\+-*.()[]|^");/*meta*/
	das_global<char *,0x39690c1b5c6d7b5a>(__context__) = ((char *) "wWsSdD");/*meta_set*/
}

inline void _FuncbuiltinTickresize_648390880f9db2f3 ( Context * __context__, TArray<regex::ReNode *> &  __Arr_rename_at_50_0, int32_t __newSize_rename_at_50_1 )
{
	builtin_array_resize(das_arg<TArray<regex::ReNode *>>::pass(__Arr_rename_at_50_0),__newSize_rename_at_50_1,8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickfinalize_c949f429586500db ( Context * __context__, TArray<regex::ReNode *> &  __a_rename_at_544_2 )
{
	{
		bool __need_loop_546 = true;
		// aV : regex::ReNode? aka TT&
		das_iterator<TArray<regex::ReNode *>> __aV_iterator(__a_rename_at_544_2);
		regex::ReNode * * __aV_rename_at_546_3;
		__need_loop_546 = __aV_iterator.first(__context__,(__aV_rename_at_546_3)) && __need_loop_546;
		for ( ; __need_loop_546 ; __need_loop_546 = __aV_iterator.next(__context__,(__aV_rename_at_546_3)) )
		{
			finalize_b8b6319fe678761c(__context__,(*__aV_rename_at_546_3));
		}
		__aV_iterator.close(__context__,(__aV_rename_at_546_3));
	};
	builtin_array_free(das_arg<TArray<regex::ReNode *>>::pass(__a_rename_at_544_2),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline int32_t _FuncbuiltinTicklength_7938efcc1bc3eff1 ( Context * __context__, TDim<regex::ReNode *,2> const  &  __a_rename_at_267_4 )
{
	return das_auto_cast<int32_t>::cast(2);
}

inline void finalize_bfa54b0105e1d809 ( Context * __context__, regex::ReNode &  ____this_rename_at_27_5 )
{
	_FuncbuiltinTickfinalize_c949f429586500db(__context__,das_arg<TArray<regex::ReNode *>>::pass(____this_rename_at_27_5.all));
	finalize_b8b6319fe678761c(__context__,____this_rename_at_27_5.left);
	finalize_b8b6319fe678761c(__context__,____this_rename_at_27_5.right);
	finalize_b8b6319fe678761c(__context__,____this_rename_at_27_5.subexpr);
	memset(&(____this_rename_at_27_5), 0, 152);
}

inline void _FuncbuiltinTickpush_1336ab62a70ec972 ( Context * __context__, TArray<TTuple<16,range,char *>> &  __Arr_rename_at_79_6, TTuple<16,range,char *> const  &  __value_rename_at_79_7 )
{
	das_copy(__Arr_rename_at_79_6(builtin_array_push_back(das_arg<TArray<TTuple<16,range,char *>>>::pass(__Arr_rename_at_79_6),16,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_7);
}

inline regex::Regex & _FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55 ( Context * __context__, regex::Regex &  __a_rename_at_38_8 )
{
	das_call_interop<void>::call(&builtin_verify_locks,__context__,SimNode_AotInterop<1>(__tinfo_0,cast<regex::Regex &>::from(__a_rename_at_38_8)));
	return das_auto_cast_ref<regex::Regex &>::cast(__a_rename_at_38_8);
}

inline int32_t _FuncregexTickfrom_hex_4f3a3d7adb464151 ( Context * __context__, int32_t __ch1_rename_at_196_9, int32_t __ch2_rename_at_196_10 )
{
	return das_auto_cast<int32_t>::cast((from_hex_aec816dc2407436(__context__,__ch1_rename_at_196_9) * 16) + from_hex_aec816dc2407436(__context__,__ch2_rename_at_196_10));
}

inline void finalize_2abcbb928def4524 ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> &  ____this_rename_at_342_11 )
{
	if ( das_get_variant_field<regex::ReNode *,8,0>::is(____this_rename_at_342_11) )
	{
		finalize_b8b6319fe678761c(__context__,das_get_variant_field<regex::ReNode *,8,0>::get(____this_rename_at_342_11));
	};
	memset(&(____this_rename_at_342_11), 0, 16);
}

inline void finalize_b8b6319fe678761c ( Context * __context__, regex::ReNode * & ____this_rename_at_417_12 )
{
	if ( ____this_rename_at_417_12 != nullptr )
	{
		finalize_bfa54b0105e1d809(__context__,das_arg<regex::ReNode>::pass(das_deref(__context__,____this_rename_at_417_12)));
		das_delete<regex::ReNode *>::clear(__context__,____this_rename_at_417_12);
		das_copy(____this_rename_at_417_12,nullptr);
	};
}

inline void _FuncbuiltinTickpush_362eabc9d9f1c608 ( Context * __context__, TArray<regex::ReNode *> &  __Arr_rename_at_79_13, regex::ReNode * const  __value_rename_at_79_14 )
{
	das_copy(__Arr_rename_at_79_13(builtin_array_push_back(das_arg<TArray<regex::ReNode *>>::pass(__Arr_rename_at_79_13),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_14);
}

inline TArray<regex::ReNode *> _FuncbuiltinTickto_array_move_610602215d8cf914 ( Context * __context__, TDim<regex::ReNode *,2> &  __a_rename_at_668_15 )
{
	TArray<regex::ReNode *> __arr_rename_at_670_16; das_zero(__arr_rename_at_670_16);
	_FuncbuiltinTickresize_648390880f9db2f3(__context__,das_arg<TArray<regex::ReNode *>>::pass(__arr_rename_at_670_16),2);
	das_copy(das_cast<TDim<regex::ReNode *,2>>::cast(das_ref(__context__,__arr_rename_at_670_16(0,__context__))),__a_rename_at_668_15);
	return /* <- */ das_auto_cast_move<TArray<regex::ReNode *>>::cast(__arr_rename_at_670_16);
}

inline bool _FuncbuiltinTicknext_160159e214cdd056 ( Context * __context__, Sequence DAS_COMMENT((uint32_t)) const  &  __it_rename_at_573_17, uint32_t & __value_rename_at_573_18 )
{
	return das_auto_cast<bool>::cast(builtin_iterator_iterate(__it_rename_at_573_17,das_auto_cast<void * const >::cast(das_ref(__context__,__value_rename_at_573_18)),__context__));
}

inline uint32_t re_gen_get_rep_limit_3aaf29e074018c44 ( Context * __context__ )
{
	return das_auto_cast<uint32_t>::cast(das_global<uint32_t,0x8ce995ce57e18608>(__context__) /*re_gen_rep_limit*/);
}

inline void trace_89f6695f8909b072 ( Context * __context__, char * const  __msg_rename_at_73_19, int32_t __offset_rename_at_73_20 )
{
}

inline void note_89f6695f8909b072 ( Context * __context__, char * const  __msg_rename_at_78_21, int32_t __offset_rename_at_78_22 )
{
}

inline void trace_backtrack_c77fe5b3ac1a6a7c ( Context * __context__ )
{
}

inline void trace_value_4739abdd3b0a7208 ( Context * __context__, regex::ReNode * const  __value_rename_at_87_23 )
{
}

inline TVariant<16,8,regex::ReNode *,void *> nada_5086bd0a540f8186 ( Context * __context__ )
{
	return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast((([&]() -> TVariant<16,8,regex::ReNode *,void *> {
		TVariant<16,8,regex::ReNode *,void *> __mkv_96;
		das_get_variant_field<void *,8,1>::set(__mkv_96) = nullptr;
		return __mkv_96;
	})()));
}

inline TVariant<16,8,regex::ReNode *,void *> maybe_d7a4f325999cb99b ( Context * __context__, regex::ReNode * const  __value_rename_at_98_24 )
{
	return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast((([&]() -> TVariant<16,8,regex::ReNode *,void *> {
		TVariant<16,8,regex::ReNode *,void *> __mkv_100;
		das_get_variant_field<regex::ReNode *,8,0>::set(__mkv_100) = __value_rename_at_98_24;
		return __mkv_100;
	})()));
}

inline bool eos_dde6e11fd3802ac8 ( Context * __context__, char * const  __expr_rename_at_102_25, int32_t __offset_rename_at_102_26 )
{
	return das_auto_cast<bool>::cast(__offset_rename_at_102_26 >= builtin_string_length(__expr_rename_at_102_25,__context__));
}

inline int32_t at_c9bade5ff7edd57d ( Context * __context__, char * const  __expr_rename_at_105_27, int32_t __offset_rename_at_105_28 )
{
	return das_auto_cast<int32_t>::cast(get_character_uat(__expr_rename_at_105_27,__offset_rename_at_105_28));
}

inline int32_t next_1bd07c8c346bbbc2 ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> const  &  __re_rename_at_120_29 )
{
	if ( !das_get_variant_field<regex::ReNode *,8,0>::is(__re_rename_at_120_29) )
	{
		builtin_stackwalk(true,true,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		builtin_throw(((char *) "expecting value"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
	return das_auto_cast<int32_t>::cast(v_extract_yi(v_cast_vec4i(das_get_variant_field<regex::ReNode *,8,0>::as(__re_rename_at_120_29,__context__)->at)) /*y*/);
}

inline bool is_set_empty_fb12252b2129800d ( Context * __context__, TDim<uint32_t,8> const  &  __cset_rename_at_126_30 )
{
	{
		bool __need_loop_127 = true;
		// x : uint aka CharSet const&
		das_iterator<TDim<uint32_t,8> const > __x_iterator(__cset_rename_at_126_30);
		uint32_t const  * __x_rename_at_127_31;
		__need_loop_127 = __x_iterator.first(__context__,(__x_rename_at_127_31)) && __need_loop_127;
		for ( ; __need_loop_127 ; __need_loop_127 = __x_iterator.next(__context__,(__x_rename_at_127_31)) )
		{
			if ( (*__x_rename_at_127_31) != 0x0u )
			{
				return das_auto_cast<bool>::cast(false);
			};
		}
		__x_iterator.close(__context__,(__x_rename_at_127_31));
	};
	return das_auto_cast<bool>::cast(true);
}

inline void set_or_char_471888d9ed78efab ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_132_32, int32_t __ch_rename_at_132_33 )
{
	__cset_rename_at_132_32((__ch_rename_at_132_33 >> 5),__context__) |= uint32_t(1 << (__ch_rename_at_132_33 & 31));
}

inline void set_or_range_6e993851d775263 ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_135_34, range __bits_rename_at_135_35 )
{
	{
		bool __need_loop_136 = true;
		// ch : int const
		das_iterator<range> __ch_iterator(range(v_extract_xi(v_cast_vec4i(__bits_rename_at_135_35)) /*x*/,v_extract_yi(v_cast_vec4i(__bits_rename_at_135_35)) /*y*/ + 1));
		int32_t __ch_rename_at_136_36;
		__need_loop_136 = __ch_iterator.first(__context__,(__ch_rename_at_136_36)) && __need_loop_136;
		for ( ; __need_loop_136 ; __need_loop_136 = __ch_iterator.next(__context__,(__ch_rename_at_136_36)) )
		{
			__cset_rename_at_135_34((__ch_rename_at_136_36 >> 5),__context__) |= uint32_t(1 << (__ch_rename_at_136_36 & 31));
		}
		__ch_iterator.close(__context__,(__ch_rename_at_136_36));
	};
}

inline void set_invert_be791c77bc6b6a11 ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_139_37 )
{
	{
		bool __need_loop_140 = true;
		// x : uint aka CharSet& -const
		das_iterator<TDim<uint32_t,8>> __x_iterator(__cset_rename_at_139_37);
		uint32_t * __x_rename_at_140_38;
		__need_loop_140 = __x_iterator.first(__context__,(__x_rename_at_140_38)) && __need_loop_140;
		for ( ; __need_loop_140 ; __need_loop_140 = __x_iterator.next(__context__,(__x_rename_at_140_38)) )
		{
			(*__x_rename_at_140_38) ^= 0xffffffffu;
		}
		__x_iterator.close(__context__,(__x_rename_at_140_38));
	};
}

inline void set_or_set_9609a9e932b32815 ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_143_39, TDim<uint32_t,8> const  &  __eset_rename_at_143_40 )
{
	{
		bool __need_loop_144 = true;
		// x : uint aka CharSet& -const
		das_iterator<TDim<uint32_t,8>> __x_iterator(__cset_rename_at_143_39);
		uint32_t * __x_rename_at_144_43;
		__need_loop_144 = __x_iterator.first(__context__,(__x_rename_at_144_43)) && __need_loop_144;
		// y : uint aka CharSet const&
		das_iterator<TDim<uint32_t,8> const > __y_iterator(__eset_rename_at_143_40);
		uint32_t const  * __y_rename_at_144_44;
		__need_loop_144 = __y_iterator.first(__context__,(__y_rename_at_144_44)) && __need_loop_144;
		for ( ; __need_loop_144 ; __need_loop_144 = __x_iterator.next(__context__,(__x_rename_at_144_43)) && __y_iterator.next(__context__,(__y_rename_at_144_44)) )
		{
			(*__x_rename_at_144_43) |= (*__y_rename_at_144_44);
		}
		__x_iterator.close(__context__,(__x_rename_at_144_43));
		__y_iterator.close(__context__,(__y_rename_at_144_44));
	};
}

inline void set_negative_7a1fcd94df7d5358 ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_147_45 )
{
	{
		bool __need_loop_148 = true;
		// x : uint aka CharSet& -const
		das_iterator<TDim<uint32_t,8>> __x_iterator(__cset_rename_at_147_45);
		uint32_t * __x_rename_at_148_46;
		__need_loop_148 = __x_iterator.first(__context__,(__x_rename_at_148_46)) && __need_loop_148;
		for ( ; __need_loop_148 ; __need_loop_148 = __x_iterator.next(__context__,(__x_rename_at_148_46)) )
		{
			das_copy((*__x_rename_at_148_46),~(*__x_rename_at_148_46));
		}
		__x_iterator.close(__context__,(__x_rename_at_148_46));
	};
}

inline void set_meta_cc349e8f6f2b739 ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_151_47, int32_t __che_rename_at_151_48 )
{
	if ( __che_rename_at_151_48 == 119 )
	{
		set_or_range_6e993851d775263(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),range(97,122));
		set_or_range_6e993851d775263(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),range(65,90));
		set_or_range_6e993851d775263(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),range(48,57));
		set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),95);
	} else if ( __che_rename_at_151_48 == 87 )
	{
		TDim<uint32_t,8> __eset_rename_at_158_49; das_zero(__eset_rename_at_158_49);
		set_meta_cc349e8f6f2b739(__context__,das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_158_49),119);
		set_or_set_9609a9e932b32815(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_158_49));
	} else if ( __che_rename_at_151_48 == 115 )
	{
		set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),32);
		set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),9);
	} else if ( __che_rename_at_151_48 == 83 )
	{
		TDim<uint32_t,8> __eset_rename_at_165_50; das_zero(__eset_rename_at_165_50);
		set_meta_cc349e8f6f2b739(__context__,das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_165_50),115);
		set_or_set_9609a9e932b32815(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_165_50));
	} else if ( __che_rename_at_151_48 == 100 )
	{
		set_or_range_6e993851d775263(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),range(48,57));
	} else if ( __che_rename_at_151_48 == 68 )
	{
		TDim<uint32_t,8> __eset_rename_at_171_51; das_zero(__eset_rename_at_171_51);
		set_meta_cc349e8f6f2b739(__context__,das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_171_51),100);
		set_or_set_9609a9e932b32815(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),das_arg<TDim<uint32_t,8>>::pass(__eset_rename_at_171_51));
	} else {
		set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_151_47),__che_rename_at_151_48);
	};
}

inline bool is_meta_character_24d3d25015b1373f ( Context * __context__, int32_t __ch_rename_at_180_52 )
{
	return das_auto_cast<bool>::cast(builtin_find_first_char_of(((char *) "\\+-*.()[]|^"),__ch_rename_at_180_52,__context__) != -1);
}

inline bool is_set_character_11f8fcca4329c870 ( Context * __context__, int32_t __ch_rename_at_183_53 )
{
	return das_auto_cast<bool>::cast(builtin_find_first_char_of(((char *) "wWsSdD"),__ch_rename_at_183_53,__context__) != -1);
}

inline int32_t from_hex_aec816dc2407436 ( Context * __context__, int32_t __ch_rename_at_186_54 )
{
	if ( (__ch_rename_at_186_54 >= 48) && (__ch_rename_at_186_54 <= 57) )
	{
		return das_auto_cast<int32_t>::cast(__ch_rename_at_186_54 - 48);
	} else {
		if ( (__ch_rename_at_186_54 >= 97) && (__ch_rename_at_186_54 <= 102) )
		{
			return das_auto_cast<int32_t>::cast((__ch_rename_at_186_54 - 97) + 10);
		} else {
			if ( (__ch_rename_at_186_54 >= 65) && (__ch_rename_at_186_54 <= 70) )
			{
				return das_auto_cast<int32_t>::cast((__ch_rename_at_186_54 - 65) + 10);
			} else {
				builtin_throw(((char *) "from_hex"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
				return das_auto_cast<int32_t>::cast(0);
			};
		};
	};
}

inline char * string_from_hex_d2d056a03cdfae17 ( Context * __context__, int32_t __ch1_rename_at_199_55 )
{
	return das_auto_cast<char *>::cast(((char *)(to_string_char(from_hex_aec816dc2407436(__context__,__ch1_rename_at_199_55),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}

inline char * string_from_hex_58ccb558a2a0b0ed ( Context * __context__, int32_t __ch1_rename_at_202_56, int32_t __ch2_rename_at_202_57 )
{
	return das_auto_cast<char *>::cast(((char *)(to_string_char(_FuncregexTickfrom_hex_4f3a3d7adb464151(__context__,__ch1_rename_at_202_56,__ch2_rename_at_202_57),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}

inline TVariant<16,8,regex::ReNode *,void *> re_char_dc689de6efe3e576 ( Context * __context__, char * const  __expr_rename_at_206_58, int32_t __offset_rename_at_206_59 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_206_58,__offset_rename_at_206_59) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		int32_t __ch_rename_at_210_60 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_206_58,__offset_rename_at_206_59));
		if ( __ch_rename_at_210_60 == 92 )
		{
			int32_t __ech_rename_at_212_61 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_206_58,__offset_rename_at_206_59 + 1));
			if ( __ech_rename_at_212_61 == 0 )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
			} else {
				if ( __ech_rename_at_212_61 == 120 )
				{
					int32_t __len_rename_at_217_62 = ((int32_t)builtin_string_length(__expr_rename_at_206_58,__context__));
					if ( (__offset_rename_at_206_59 + 2) >= __len_rename_at_217_62 )
					{
						return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
					} else {
						int32_t __hex1_rename_at_221_63 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_206_58,__offset_rename_at_206_59 + 2));
						if ( !das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),__hex1_rename_at_221_63) )
						{
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
						} else {
							if ( (__offset_rename_at_206_59 + 2) < __len_rename_at_217_62 )
							{
								int32_t __hex2_rename_at_226_64 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_206_58,__offset_rename_at_206_59 + 3));
								if ( das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),__hex2_rename_at_226_64) )
								{
									note_89f6695f8909b072(__context__,das_string_builder_temp(__context__,SimNode_AotInterop<5>(__tinfo_1, cast<char * const >::from(((char *) "hex \\")), cast<char *>::from(((char *)(to_string_char(__hex1_rename_at_221_63,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char *>::from(((char *)(to_string_char(__hex2_rename_at_226_64,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) " ")), cast<uint32_t>::from(uint32_t(_FuncregexTickfrom_hex_4f3a3d7adb464151(__context__,__hex1_rename_at_221_63,__hex2_rename_at_226_64))))),__offset_rename_at_206_59);
									return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
										regex::ReNode __mks_229;
										das_zero(__mks_229);
										das_copy((__mks_229.op),(DAS_COMMENT(enum) regex::ReOp::Char));
										das_copy((__mks_229.text),(string_from_hex_58ccb558a2a0b0ed(__context__,__hex1_rename_at_221_63,__hex2_rename_at_226_64)));
										das_copy((__mks_229.textLen),(1));
										das_copy((__mks_229.at),(range(__offset_rename_at_206_59,__offset_rename_at_206_59 + 3)));
										return __mks_229;
									})()))));
								};
							};
							note_89f6695f8909b072(__context__,das_string_builder_temp(__context__,SimNode_AotInterop<4>(__tinfo_2, cast<char * const >::from(((char *) "hex \\")), cast<char *>::from(((char *)(to_string_char(__hex1_rename_at_221_63,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) " ")), cast<uint32_t>::from(uint32_t(from_hex_aec816dc2407436(__context__,__hex1_rename_at_221_63))))),__offset_rename_at_206_59);
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
								regex::ReNode __mks_231;
								das_zero(__mks_231);
								das_copy((__mks_231.op),(DAS_COMMENT(enum) regex::ReOp::Char));
								das_copy((__mks_231.text),(string_from_hex_d2d056a03cdfae17(__context__,__hex1_rename_at_221_63)));
								das_copy((__mks_231.textLen),(1));
								das_copy((__mks_231.at),(range(__offset_rename_at_206_59,__offset_rename_at_206_59 + 2)));
								return __mks_231;
							})()))));
						};
					};
				};
				if ( is_set_character_11f8fcca4329c870(__context__,__ech_rename_at_212_61) )
				{
					TDim<uint32_t,8> __cset_rename_at_233_65; das_zero(__cset_rename_at_233_65);
					set_meta_cc349e8f6f2b739(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_233_65),__ech_rename_at_212_61);
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
						regex::ReNode __mks_235;
						das_zero(__mks_235);
						das_copy((__mks_235.op),(DAS_COMMENT(enum) regex::ReOp::Set));
						das_copy((__mks_235.cset),(__cset_rename_at_233_65));
						das_copy((__mks_235.at),(range(__offset_rename_at_206_59,__offset_rename_at_206_59 + 2)));
						return __mks_235;
					})()))));
				} else {
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
						regex::ReNode __mks_236;
						das_zero(__mks_236);
						das_copy((__mks_236.op),(DAS_COMMENT(enum) regex::ReOp::Char));
						das_copy((__mks_236.text),(((char *)(to_string_char(__ech_rename_at_212_61,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
						das_copy((__mks_236.textLen),(1));
						das_copy((__mks_236.at),(range(__offset_rename_at_206_59,__offset_rename_at_206_59 + 2)));
						return __mks_236;
					})()))));
				};
			};
		} else if ( is_meta_character_24d3d25015b1373f(__context__,__ch_rename_at_210_60) )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		};
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
			regex::ReNode __mks_239;
			das_zero(__mks_239);
			das_copy((__mks_239.op),(DAS_COMMENT(enum) regex::ReOp::Char));
			das_copy((__mks_239.text),(((char *)(to_string_char(__ch_rename_at_210_60,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
			das_copy((__mks_239.textLen),(1));
			das_copy((__mks_239.at),(range(__offset_rename_at_206_59,__offset_rename_at_206_59 + 1)));
			return __mks_239;
		})()))));
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_set_items_9fb85eb4dd2de0ce ( Context * __context__, char * const  __expr_rename_at_245_66, int32_t __offset_rename_at_245_67 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_245_66,__offset_rename_at_245_67) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		TDim<uint32_t,8> __cset_rename_at_249_68; das_zero(__cset_rename_at_249_68);
		int32_t __iofs_rename_at_250_69 = __offset_rename_at_245_67;
		int32_t __prev_char_rename_at_251_70 = -1;
		bool __next_range_rename_at_252_71 = false;
		while ( !eos_dde6e11fd3802ac8(__context__,__expr_rename_at_245_66,__iofs_rename_at_250_69) )
		{
			int32_t __ch_rename_at_254_72 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_245_66,__iofs_rename_at_250_69));
			int32_t __next_char_rename_at_255_73 = -1;
			if ( __ch_rename_at_254_72 == 93 )
			{
				break;
			} else if ( __ch_rename_at_254_72 == 92 )
			{
				int32_t __che_rename_at_260_74 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_245_66,__iofs_rename_at_250_69 + 1));
				if ( __che_rename_at_260_74 == 0 )
				{
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
				} else {
					if ( __che_rename_at_260_74 == 120 )
					{
						int32_t __len_rename_at_265_75 = ((int32_t)builtin_string_length(__expr_rename_at_245_66,__context__));
						if ( (__iofs_rename_at_250_69 + 2) >= __len_rename_at_265_75 )
						{
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
						} else {
							int32_t __hex1_rename_at_269_76 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_245_66,__iofs_rename_at_250_69 + 2));
							if ( !das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),__hex1_rename_at_269_76) )
							{
								return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
							} else {
								if ( (__iofs_rename_at_250_69 + 2) < __len_rename_at_265_75 )
								{
									int32_t __hex2_rename_at_274_77 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_245_66,__iofs_rename_at_250_69 + 3));
									if ( das_invoke_function<bool>::invoke<int32_t>(__context__,nullptr,Func(__context__->fnByMangledName(/*@strings_boost::is_hex Ci*/ 13255244687218186342u)),__hex2_rename_at_274_77) )
									{
										das_copy(__next_char_rename_at_255_73,_FuncregexTickfrom_hex_4f3a3d7adb464151(__context__,__hex1_rename_at_269_76,__hex2_rename_at_274_77));
										note_89f6695f8909b072(__context__,das_string_builder_temp(__context__,SimNode_AotInterop<5>(__tinfo_3, cast<char * const >::from(((char *) "set hex \\")), cast<char *>::from(((char *)(to_string_char(__hex1_rename_at_269_76,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char *>::from(((char *)(to_string_char(__hex2_rename_at_274_77,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) " ")), cast<uint32_t>::from(uint32_t(_FuncregexTickfrom_hex_4f3a3d7adb464151(__context__,__hex1_rename_at_269_76,__hex2_rename_at_274_77))))),__iofs_rename_at_250_69);
										__iofs_rename_at_250_69 += 4;
									} else {
										das_copy(__next_char_rename_at_255_73,from_hex_aec816dc2407436(__context__,__hex1_rename_at_269_76));
										note_89f6695f8909b072(__context__,das_string_builder_temp(__context__,SimNode_AotInterop<4>(__tinfo_4, cast<char * const >::from(((char *) "set hex \\")), cast<char *>::from(((char *)(to_string_char(__hex1_rename_at_269_76,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) " ")), cast<uint32_t>::from(uint32_t(from_hex_aec816dc2407436(__context__,__hex1_rename_at_269_76))))),__iofs_rename_at_250_69);
										__iofs_rename_at_250_69 += 3;
									};
								} else {
									das_copy(__next_char_rename_at_255_73,from_hex_aec816dc2407436(__context__,__hex1_rename_at_269_76));
									note_89f6695f8909b072(__context__,das_string_builder_temp(__context__,SimNode_AotInterop<4>(__tinfo_5, cast<char * const >::from(((char *) "set hex \\")), cast<char *>::from(((char *)(to_string_char(__hex1_rename_at_269_76,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) " ")), cast<uint32_t>::from(uint32_t(from_hex_aec816dc2407436(__context__,__hex1_rename_at_269_76))))),__offset_rename_at_245_67);
									__iofs_rename_at_250_69 += 3;
								};
							};
						};
					} else {
						if ( __next_range_rename_at_252_71 )
						{
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
						} else {
							if ( is_set_character_11f8fcca4329c870(__context__,__che_rename_at_260_74) )
							{
								das_copy(__next_char_rename_at_255_73,-1);
								set_meta_cc349e8f6f2b739(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_249_68),__che_rename_at_260_74);
							} else {
								das_copy(__next_char_rename_at_255_73,__che_rename_at_260_74);
							};
							__iofs_rename_at_250_69 += 2;
						};
					};
				};
			} else if ( __ch_rename_at_254_72 == 45 )
			{
				if ( __prev_char_rename_at_251_70 == -1 )
				{
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
				} else {
					das_copy(__next_range_rename_at_252_71,true);
					__iofs_rename_at_250_69 += 1;
				};
			} else {
				das_copy(__next_char_rename_at_255_73,__ch_rename_at_254_72);
				__iofs_rename_at_250_69 += 1;
			};
			if ( __next_char_rename_at_255_73 != -1 )
			{
				if ( __next_range_rename_at_252_71 )
				{
					set_or_range_6e993851d775263(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_249_68),range(__prev_char_rename_at_251_70,__next_char_rename_at_255_73));
					das_copy(__next_range_rename_at_252_71,false);
					das_copy(__prev_char_rename_at_251_70,-1);
				} else {
					set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_249_68),__next_char_rename_at_255_73);
					das_copy(__prev_char_rename_at_251_70,__next_char_rename_at_255_73);
				};
			} else if ( !__next_range_rename_at_252_71 )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
			};
		};
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
			regex::ReNode __mks_323;
			das_zero(__mks_323);
			das_copy((__mks_323.op),(DAS_COMMENT(enum) regex::ReOp::Set));
			das_copy((__mks_323.cset),(__cset_rename_at_249_68));
			das_copy((__mks_323.at),(range(__offset_rename_at_245_67,__iofs_rename_at_250_69)));
			return __mks_323;
		})()))));
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_set_60109875d3448735 ( Context * __context__, char * const  __expr_rename_at_328_78, int32_t __offset_rename_at_328_79 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_328_78,__offset_rename_at_328_79) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_328_78,__offset_rename_at_328_79) != 91 )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		} else {
			bool __negative_rename_at_334_80 = false;
			if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_328_78,__offset_rename_at_328_79 + 1) == 94 )
			{
				das_copy(__negative_rename_at_334_80,true);
			};
			TVariant<16,8,regex::ReNode *,void *> __oset_rename_at_337_81 = re_set_items_9fb85eb4dd2de0ce(__context__,__expr_rename_at_328_78,__negative_rename_at_334_80 ? das_auto_cast<int32_t>::cast((__offset_rename_at_328_79 + 2)) : das_auto_cast<int32_t>::cast((__offset_rename_at_328_79 + 1)));
			if ( das_get_variant_field<void *,8,1>::is(__oset_rename_at_337_81) )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
			} else {
				if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_328_78,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oset_rename_at_337_81))) != 93 )
				{
					finalize_2abcbb928def4524(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oset_rename_at_337_81));
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
				} else {
					regex::ReNode * __oval_rename_at_344_82 = das_get_variant_field<regex::ReNode *,8,0>::as(__oset_rename_at_337_81,__context__);
					das_copy(das_swizzle_ref<int32_t,range,0>::swizzle(__oval_rename_at_344_82->at) /*x*/,__offset_rename_at_328_79);
					++das_swizzle_ref<int32_t,range,1>::swizzle(__oval_rename_at_344_82->at) /*y*/;
					das_copy(__oval_rename_at_344_82->op,DAS_COMMENT(enum) regex::ReOp::Set);
					if ( __negative_rename_at_334_80 )
					{
						set_negative_7a1fcd94df7d5358(__context__,das_arg<TDim<uint32_t,8>>::pass(__oval_rename_at_344_82->cset));
					};
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__oset_rename_at_337_81);
				};
			};
		};
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_any_f6446c9dabb991e5 ( Context * __context__, char * const  __expr_rename_at_354_83, int32_t __offset_rename_at_354_84 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_354_83,__offset_rename_at_354_84) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_354_83,__offset_rename_at_354_84) == 46 )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
				regex::ReNode __mks_359;
				das_zero(__mks_359);
				das_copy((__mks_359.op),(DAS_COMMENT(enum) regex::ReOp::Any));
				das_copy((__mks_359.at),(range(__offset_rename_at_354_84,__offset_rename_at_354_84 + 1)));
				return __mks_359;
			})()))));
		} else {
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		};
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_eos_ce6b3dba83357e14 ( Context * __context__, char * const  __expr_rename_at_363_85, int32_t __offset_rename_at_363_86 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_363_85,__offset_rename_at_363_86) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_363_85,__offset_rename_at_363_86) == 36 )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
				regex::ReNode __mks_368;
				das_zero(__mks_368);
				das_copy((__mks_368.op),(DAS_COMMENT(enum) regex::ReOp::Eos));
				das_copy((__mks_368.at),(range(__offset_rename_at_363_86,__offset_rename_at_363_86 + 1)));
				return __mks_368;
			})()))));
		} else {
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		};
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_group_73b2a2ffd8d6e095 ( Context * __context__, char * const  __expr_rename_at_372_87, int32_t __offset_rename_at_372_88 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_372_87,__offset_rename_at_372_88) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_372_87,__offset_rename_at_372_88) != 40 )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		} else {
			TVariant<16,8,regex::ReNode *,void *> __ore_rename_at_378_89 = re_re_36eba07f5043127c(__context__,__expr_rename_at_372_87,__offset_rename_at_372_88 + 1);
			if ( das_get_variant_field<void *,8,1>::is(__ore_rename_at_378_89) )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
			} else {
				if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_372_87,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__ore_rename_at_378_89))) != 41 )
				{
					finalize_2abcbb928def4524(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__ore_rename_at_378_89));
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
				} else {
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
						regex::ReNode __mks_384;
						das_zero(__mks_384);
						das_copy((__mks_384.op),(DAS_COMMENT(enum) regex::ReOp::Group));
						das_copy((__mks_384.subexpr),(das_get_variant_field<regex::ReNode *,8,0>::as(__ore_rename_at_378_89,__context__)));
						das_copy((__mks_384.at),(range(__offset_rename_at_372_88,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__ore_rename_at_378_89)) + 1)));
						return __mks_384;
					})()))));
				};
			};
		};
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_elementary_9f9a7e4e2c98fef1 ( Context * __context__, char * const  __expr_rename_at_387_90, int32_t __offset_rename_at_387_91 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		TVariant<16,8,regex::ReNode *,void *> __ogr_rename_at_391_92 = re_group_73b2a2ffd8d6e095(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91);
		if ( das_get_variant_field<regex::ReNode *,8,0>::is(__ogr_rename_at_391_92) )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__ogr_rename_at_391_92);
		} else {
			TVariant<16,8,regex::ReNode *,void *> __oany_rename_at_394_93 = re_any_f6446c9dabb991e5(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91);
			if ( das_get_variant_field<regex::ReNode *,8,0>::is(__oany_rename_at_394_93) )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__oany_rename_at_394_93);
			} else {
				TVariant<16,8,regex::ReNode *,void *> __oeos_rename_at_397_94 = re_eos_ce6b3dba83357e14(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91);
				if ( das_get_variant_field<regex::ReNode *,8,0>::is(__oeos_rename_at_397_94) )
				{
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__oeos_rename_at_397_94);
				} else {
					TVariant<16,8,regex::ReNode *,void *> __oset_rename_at_400_95 = re_set_60109875d3448735(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91);
					if ( das_get_variant_field<regex::ReNode *,8,0>::is(__oset_rename_at_400_95) )
					{
						return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__oset_rename_at_400_95);
					} else {
						TVariant<16,8,regex::ReNode *,void *> __ochr_rename_at_403_96 = re_char_dc689de6efe3e576(__context__,__expr_rename_at_387_90,__offset_rename_at_387_91);
						if ( das_get_variant_field<regex::ReNode *,8,0>::is(__ochr_rename_at_403_96) )
						{
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__ochr_rename_at_403_96);
						} else {
							return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
						};
					};
				};
			};
		};
	};
}

inline regex::ReNode * mk_concat_7baa59a4cd5a0a70 ( Context * __context__, regex::ReNode * __left_rename_at_408_97, regex::ReNode * __right_rename_at_408_98 )
{
	if ( __left_rename_at_408_97 == nullptr )
	{
		return das_auto_cast<regex::ReNode *>::cast(__right_rename_at_408_98);
	} else if ( (__left_rename_at_408_97->op == DAS_COMMENT(enum) regex::ReOp::Char) && (__right_rename_at_408_98->op == DAS_COMMENT(enum) regex::ReOp::Char) )
	{
		das_copy(das_swizzle_ref<int32_t,range,1>::swizzle(__left_rename_at_408_97->at) /*y*/,das_swizzle_ref<int32_t,range,1>::swizzle(__right_rename_at_408_98->at) /*y*/);
		SimPolicy<char *>::SetAdd((char *)&(__left_rename_at_408_97->text),cast<char *>::from(__right_rename_at_408_98->text),*__context__,nullptr);
		__left_rename_at_408_97->textLen += __right_rename_at_408_98->textLen;
		finalize_b8b6319fe678761c(__context__,__right_rename_at_408_98);
		return das_auto_cast<regex::ReNode *>::cast(__left_rename_at_408_97);
	} else if ( ((__left_rename_at_408_97->op == DAS_COMMENT(enum) regex::ReOp::Concat) && (__left_rename_at_408_97->right->op == DAS_COMMENT(enum) regex::ReOp::Char)) && (__right_rename_at_408_98->op == DAS_COMMENT(enum) regex::ReOp::Char) )
	{
		regex::ReNode * __lor_rename_at_421_99 = __left_rename_at_408_97->right;
		das_copy(das_swizzle_ref<int32_t,range,1>::swizzle(__left_rename_at_408_97->at) /*y*/,das_swizzle_ref<int32_t,range,1>::swizzle(__right_rename_at_408_98->at) /*y*/);
		das_copy(das_swizzle_ref<int32_t,range,1>::swizzle(__lor_rename_at_421_99->at) /*y*/,das_swizzle_ref<int32_t,range,1>::swizzle(__right_rename_at_408_98->at) /*y*/);
		SimPolicy<char *>::SetAdd((char *)&(__lor_rename_at_421_99->text),cast<char *>::from(__right_rename_at_408_98->text),*__context__,nullptr);
		__lor_rename_at_421_99->textLen += __right_rename_at_408_98->textLen;
		finalize_b8b6319fe678761c(__context__,__right_rename_at_408_98);
		return das_auto_cast<regex::ReNode *>::cast(__left_rename_at_408_97);
	} else {
		return das_auto_cast<regex::ReNode *>::cast(das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
			regex::ReNode __mks_430;
			das_zero(__mks_430);
			das_copy((__mks_430.op),(DAS_COMMENT(enum) regex::ReOp::Concat));
			das_copy((__mks_430.left),(__left_rename_at_408_97));
			das_copy((__mks_430.right),(__right_rename_at_408_98));
			das_copy((__mks_430.at),(range(v_extract_xi(v_cast_vec4i(__left_rename_at_408_97->at)) /*x*/,v_extract_yi(v_cast_vec4i(__right_rename_at_408_98->at)) /*y*/)));
			return __mks_430;
		})())));
	};
}

inline regex::ReNode * mk_union_ef2057df16785333 ( Context * __context__, regex::ReNode * __left_rename_at_432_100, regex::ReNode * __right_rename_at_432_101 )
{
	if ( __left_rename_at_432_100->op == DAS_COMMENT(enum) regex::ReOp::Union )
	{
		das_copy(das_swizzle_ref<int32_t,range,1>::swizzle(__left_rename_at_432_100->at) /*y*/,das_swizzle_ref<int32_t,range,1>::swizzle(__right_rename_at_432_101->at) /*y*/);
		if ( __right_rename_at_432_101->op == DAS_COMMENT(enum) regex::ReOp::Union )
		{
			{
				bool __need_loop_436 = true;
				// x : regex::ReNode?&
				das_iterator<TArray<regex::ReNode *>> __x_iterator(__right_rename_at_432_101->all);
				regex::ReNode * * __x_rename_at_436_102;
				__need_loop_436 = __x_iterator.first(__context__,(__x_rename_at_436_102)) && __need_loop_436;
				for ( ; __need_loop_436 ; __need_loop_436 = __x_iterator.next(__context__,(__x_rename_at_436_102)) )
				{
					_FuncbuiltinTickpush_362eabc9d9f1c608(__context__,das_arg<TArray<regex::ReNode *>>::pass(__left_rename_at_432_100->all),(*__x_rename_at_436_102));
				}
				__x_iterator.close(__context__,(__x_rename_at_436_102));
			};
			finalize_b8b6319fe678761c(__context__,__right_rename_at_432_101);
		} else {
			_FuncbuiltinTickpush_362eabc9d9f1c608(__context__,das_arg<TArray<regex::ReNode *>>::pass(__left_rename_at_432_100->all),__right_rename_at_432_101);
		};
		return das_auto_cast<regex::ReNode *>::cast(__left_rename_at_432_100);
	} else if ( __right_rename_at_432_101->op == DAS_COMMENT(enum) regex::ReOp::Union )
	{
		das_copy(das_swizzle_ref<int32_t,range,0>::swizzle(__right_rename_at_432_101->at) /*x*/,das_swizzle_ref<int32_t,range,0>::swizzle(__left_rename_at_432_100->at) /*x*/);
		_FuncbuiltinTickpush_362eabc9d9f1c608(__context__,das_arg<TArray<regex::ReNode *>>::pass(__right_rename_at_432_101->all),__left_rename_at_432_100);
		return das_auto_cast<regex::ReNode *>::cast(__right_rename_at_432_101);
	} else {
		TDim<regex::ReNode *,2> _temp_make_local_448_50_64; _temp_make_local_448_50_64;
		return das_auto_cast<regex::ReNode *>::cast(das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
			regex::ReNode __mks_448;
			das_zero(__mks_448);
			das_copy((__mks_448.op),(DAS_COMMENT(enum) regex::ReOp::Union));
			das_move((__mks_448.all),(_FuncbuiltinTickto_array_move_610602215d8cf914(__context__,das_arg<TDim<regex::ReNode *,2>>::pass((([&]() -> TDim<regex::ReNode *,2>& {
				_temp_make_local_448_50_64(0,__context__) = __left_rename_at_432_100;
				_temp_make_local_448_50_64(1,__context__) = __right_rename_at_432_101;
				return _temp_make_local_448_50_64;
			})())))));
			das_copy((__mks_448.at),(range(v_extract_xi(v_cast_vec4i(__left_rename_at_432_100->at)) /*x*/,v_extract_yi(v_cast_vec4i(__right_rename_at_432_101->at)) /*y*/)));
			return __mks_448;
		})())));
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_re_36eba07f5043127c ( Context * __context__, char * const  __expr_rename_at_454_103, int32_t __offset_rename_at_454_104 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_454_103,__offset_rename_at_454_104) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		int32_t __cofs_rename_at_458_105 = __offset_rename_at_454_104;
		regex::ReNode * __last_rename_at_459_106 = 0;
		while ( !eos_dde6e11fd3802ac8(__context__,__expr_rename_at_454_103,__cofs_rename_at_458_105) )
		{
			if ( at_c9bade5ff7edd57d(__context__,__expr_rename_at_454_103,__cofs_rename_at_458_105) == 124 )
			{
				if ( __last_rename_at_459_106 == nullptr )
				{
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
				} else {
					TVariant<16,8,regex::ReNode *,void *> __oright_rename_at_465_107 = re_re_36eba07f5043127c(__context__,__expr_rename_at_454_103,__cofs_rename_at_458_105 + 1);
					if ( das_get_variant_field<void *,8,1>::is(__oright_rename_at_465_107) )
					{
						return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
					} else {
						das_copy(__last_rename_at_459_106,mk_union_ef2057df16785333(__context__,__last_rename_at_459_106,das_get_variant_field<regex::ReNode *,8,0>::as(__oright_rename_at_465_107,__context__)));
						das_copy(__cofs_rename_at_458_105,das_swizzle_ref<int32_t,range,1>::swizzle(__last_rename_at_459_106->at) /*y*/);
					};
				};
			} else {
				TVariant<16,8,regex::ReNode *,void *> __onext_rename_at_472_108 = re_basic_16364ce684bfd02f(__context__,__expr_rename_at_454_103,__cofs_rename_at_458_105);
				if ( das_get_variant_field<void *,8,1>::is(__onext_rename_at_472_108) )
				{
					TVariant<16,8,regex::ReNode *,void *> _temp_make_local_474_35_96; _temp_make_local_474_35_96;
					TVariant<16,8,regex::ReNode *,void *> _temp_make_local_474_44_112; _temp_make_local_474_44_112;
					return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast((__last_rename_at_459_106 == nullptr) ? das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast((_temp_make_local_474_35_96 = (nada_5086bd0a540f8186(__context__)))) : das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast((_temp_make_local_474_44_112 = (maybe_d7a4f325999cb99b(__context__,__last_rename_at_459_106)))));
				} else {
					das_copy(__last_rename_at_459_106,mk_concat_7baa59a4cd5a0a70(__context__,__last_rename_at_459_106,das_get_variant_field<regex::ReNode *,8,0>::as(__onext_rename_at_472_108,__context__)));
					das_copy(__cofs_rename_at_458_105,das_swizzle_ref<int32_t,range,1>::swizzle(__last_rename_at_459_106->at) /*y*/);
				};
			};
		};
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,__last_rename_at_459_106));
	};
}

inline TVariant<16,8,regex::ReNode *,void *> re_basic_16364ce684bfd02f ( Context * __context__, char * const  __expr_rename_at_482_109, int32_t __offset_rename_at_482_110 )
{
	if ( eos_dde6e11fd3802ac8(__context__,__expr_rename_at_482_109,__offset_rename_at_482_110) )
	{
		return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
	} else {
		TVariant<16,8,regex::ReNode *,void *> __oelem_rename_at_486_111 = re_elementary_9f9a7e4e2c98fef1(__context__,__expr_rename_at_482_109,__offset_rename_at_482_110);
		if ( das_get_variant_field<void *,8,1>::is(__oelem_rename_at_486_111) )
		{
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(nada_5086bd0a540f8186(__context__));
		} else {
			int32_t __ch_rename_at_489_112 = ((int32_t)at_c9bade5ff7edd57d(__context__,__expr_rename_at_482_109,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oelem_rename_at_486_111))));
			if ( __ch_rename_at_489_112 == 42 )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
					regex::ReNode __mks_491;
					das_zero(__mks_491);
					das_copy((__mks_491.op),(DAS_COMMENT(enum) regex::ReOp::Star));
					das_copy((__mks_491.subexpr),(das_get_variant_field<regex::ReNode *,8,0>::as(__oelem_rename_at_486_111,__context__)));
					das_copy((__mks_491.at),(range(__offset_rename_at_482_110,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oelem_rename_at_486_111)) + 1)));
					return __mks_491;
				})()))));
			} else if ( __ch_rename_at_489_112 == 43 )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
					regex::ReNode __mks_493;
					das_zero(__mks_493);
					das_copy((__mks_493.op),(DAS_COMMENT(enum) regex::ReOp::Plus));
					das_copy((__mks_493.subexpr),(das_get_variant_field<regex::ReNode *,8,0>::as(__oelem_rename_at_486_111,__context__)));
					das_copy((__mks_493.at),(range(__offset_rename_at_482_110,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oelem_rename_at_486_111)) + 1)));
					return __mks_493;
				})()))));
			} else if ( __ch_rename_at_489_112 == 63 )
			{
				return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(maybe_d7a4f325999cb99b(__context__,das_ascend<regex::ReNode,regex::ReNode>::make(__context__,nullptr,(([&]() -> regex::ReNode {
					regex::ReNode __mks_495;
					das_zero(__mks_495);
					das_copy((__mks_495.op),(DAS_COMMENT(enum) regex::ReOp::Question));
					das_copy((__mks_495.subexpr),(das_get_variant_field<regex::ReNode *,8,0>::as(__oelem_rename_at_486_111,__context__)));
					das_copy((__mks_495.at),(range(__offset_rename_at_482_110,next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__oelem_rename_at_486_111)) + 1)));
					return __mks_495;
				})()))));
			};
			return das_auto_cast_ref<TVariant<16,8,regex::ReNode *,void *>>::cast(__oelem_rename_at_486_111);
		};
	};
}

inline regex::ReNode * re_parse_dcac85ee353b9cd1 ( Context * __context__, char * const  __expr_rename_at_498_113 )
{
	TVariant<16,8,regex::ReNode *,void *> __ore_rename_at_499_114 = re_re_36eba07f5043127c(__context__,__expr_rename_at_498_113,0);
	if ( das_get_variant_field<void *,8,1>::is(__ore_rename_at_499_114) )
	{
		return das_auto_cast<regex::ReNode *>::cast(nullptr);
	} else {
		int32_t __at_rename_at_502_115 = ((int32_t)next_1bd07c8c346bbbc2(__context__,das_arg<TVariant<16,8,regex::ReNode *,void *>>::pass(__ore_rename_at_499_114)));
		return das_auto_cast<regex::ReNode *>::cast((__at_rename_at_502_115 != builtin_string_length(__expr_rename_at_498_113,__context__)) ? das_auto_cast<void * const >::cast(nullptr) : das_auto_cast<void * const >::cast(das_get_variant_field<regex::ReNode *,8,0>::as(__ore_rename_at_499_114,__context__)));
	};
}

inline void visit_top_down_ac16ba95cc2d1c98 ( Context * __context__, regex::ReNode * __node_rename_at_508_116, Block DAS_COMMENT((void,regex::ReNode *)) const  &  __blk_rename_at_508_117 )
{
	das_invoke<void>::invoke<regex::ReNode *>(__context__,nullptr,__blk_rename_at_508_117,__node_rename_at_508_116);
	{
		bool __need_loop_510 = true;
		// x : regex::ReNode?&
		das_iterator<TArray<regex::ReNode *>> __x_iterator(__node_rename_at_508_116->all);
		regex::ReNode * * __x_rename_at_510_118;
		__need_loop_510 = __x_iterator.first(__context__,(__x_rename_at_510_118)) && __need_loop_510;
		for ( ; __need_loop_510 ; __need_loop_510 = __x_iterator.next(__context__,(__x_rename_at_510_118)) )
		{
			visit_top_down_ac16ba95cc2d1c98(__context__,(*__x_rename_at_510_118),__blk_rename_at_508_117);
		}
		__x_iterator.close(__context__,(__x_rename_at_510_118));
	};
	if ( __node_rename_at_508_116->subexpr != nullptr )
	{
		visit_top_down_ac16ba95cc2d1c98(__context__,__node_rename_at_508_116->subexpr,__blk_rename_at_508_117);
	};
	if ( __node_rename_at_508_116->left != nullptr )
	{
		visit_top_down_ac16ba95cc2d1c98(__context__,__node_rename_at_508_116->left,__blk_rename_at_508_117);
	};
	if ( __node_rename_at_508_116->right != nullptr )
	{
		visit_top_down_ac16ba95cc2d1c98(__context__,__node_rename_at_508_116->right,__blk_rename_at_508_117);
	};
}

inline void re_assign_next_3b4ea73434aed381 ( Context * __context__, regex::Regex &  __re_rename_at_519_119 ) { das_stack_prologue __prologue(__context__,128,"re_assign_next " DAS_FILE_LINE);
{
	int32_t __id_rename_at_520_120 = 0;
	visit_top_down_ac16ba95cc2d1c98(__context__,__re_rename_at_519_119.root,das_make_block<void,regex::ReNode *>(__context__,96,0,&__func_info__8b6d6c464a360a4f,[&](regex::ReNode * __node_rename_at_521_121) -> void{
		das_copy(__node_rename_at_521_121->id,__id_rename_at_520_120++);
		if ( __node_rename_at_521_121->op == DAS_COMMENT(enum) regex::ReOp::Concat )
		{
			das_copy(__node_rename_at_521_121->left->next,__node_rename_at_521_121->right);
			das_copy(__node_rename_at_521_121->right->next,__node_rename_at_521_121->next);
		} else if ( __node_rename_at_521_121->op == DAS_COMMENT(enum) regex::ReOp::Group )
		{
			das_copy(__node_rename_at_521_121->subexpr->next,__node_rename_at_521_121->next);
		} else if ( __node_rename_at_521_121->op == DAS_COMMENT(enum) regex::ReOp::Union )
		{
			{
				bool __need_loop_529 = true;
				// sub : regex::ReNode?&
				das_iterator<TArray<regex::ReNode *>> __sub_iterator(__node_rename_at_521_121->all);
				regex::ReNode * * __sub_rename_at_529_122;
				__need_loop_529 = __sub_iterator.first(__context__,(__sub_rename_at_529_122)) && __need_loop_529;
				for ( ; __need_loop_529 ; __need_loop_529 = __sub_iterator.next(__context__,(__sub_rename_at_529_122)) )
				{
					das_copy((*__sub_rename_at_529_122)->next,__node_rename_at_521_121->next);
				}
				__sub_iterator.close(__context__,(__sub_rename_at_529_122));
			};
		};
	}));
}}

inline void re_assign_groups_6a6962661f0751e2 ( Context * __context__, regex::Regex &  __re_rename_at_532_123 ) { das_stack_prologue __prologue(__context__,144,"re_assign_groups " DAS_FILE_LINE);
{
	TTuple<16,range,char *> _temp_make_local_533_27_32; _temp_make_local_533_27_32;
	_FuncbuiltinTickpush_1336ab62a70ec972(__context__,das_arg<TArray<TTuple<16,range,char *>>>::pass(__re_rename_at_532_123.groups),das_arg<TTuple<16,range,char *>>::pass((([&]() -> TTuple<16,range,char *>& {
		das_get_tuple_field<range,0>::get(_temp_make_local_533_27_32) = range(0,0);
		das_get_tuple_field<char *,8>::get(_temp_make_local_533_27_32) = nullptr;
		return _temp_make_local_533_27_32;
	})())));
	visit_top_down_ac16ba95cc2d1c98(__context__,__re_rename_at_532_123.root,das_make_block<void,regex::ReNode *>(__context__,96,0,&__func_info__8b6d6c464a360a4f,[&](regex::ReNode * __node_rename_at_534_124) -> void{
		if ( __node_rename_at_534_124->op == DAS_COMMENT(enum) regex::ReOp::Group )
		{
			TTuple<16,range,char *> _temp_make_local_538_35_128; _temp_make_local_538_35_128;
			int32_t __index_rename_at_536_125 = ((int32_t)builtin_array_size(das_arg<TArray<TTuple<16,range,char *>>>::pass(__re_rename_at_532_123.groups)));
			das_copy(__node_rename_at_534_124->index,__index_rename_at_536_125);
			_FuncbuiltinTickpush_1336ab62a70ec972(__context__,das_arg<TArray<TTuple<16,range,char *>>>::pass(__re_rename_at_532_123.groups),das_arg<TTuple<16,range,char *>>::pass((([&]() -> TTuple<16,range,char *>& {
				das_get_tuple_field<range,0>::get(_temp_make_local_538_35_128) = range(0,0);
				das_get_tuple_field<char *,8>::get(_temp_make_local_538_35_128) = das_string_builder(__context__,SimNode_AotInterop<1>(__tinfo_6, cast<int32_t>::from(__index_rename_at_536_125)));
				return _temp_make_local_538_35_128;
			})())));
		};
	}));
}}

inline void re_assign_match_functions_8f6d5df970baf66a ( Context * __context__, regex::Regex &  __re_rename_at_544_126 ) { das_stack_prologue __prologue(__context__,96,"re_assign_match_functions " DAS_FILE_LINE);
{
	visit_top_down_ac16ba95cc2d1c98(__context__,__re_rename_at_544_126.root,das_make_block<void,regex::ReNode *>(__context__,80,0,&__func_info__8b6d6c464a360a4f,[&](regex::ReNode * __node_rename_at_545_127) -> void{
		if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Char )
		{
			if ( __node_rename_at_545_127->textLen == 1 )
			{
				das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_single_char S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 9263101160919794936u)));
			} else {
				das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_char S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 4374412885798547878u)));
			};
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_char 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 3380980448633920250u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Union )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_union S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 4059838716073513882u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_union 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 14178999509996687488u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Set )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_set S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 17391331121226462953u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_set 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 122017286083467237u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Any )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_any S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 11105899789605245532u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_any 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 6084357162673744672u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Eos )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_eos S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 6818713739336395946u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_eos 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 9020662661764102338u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Concat )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_concat S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 16362821702557166674u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_concat 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 15857368836291994000u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Plus )
		{
			if ( __node_rename_at_545_127->subexpr->op == DAS_COMMENT(enum) regex::ReOp::Set )
			{
				das_copy(__node_rename_at_545_127->cset,__node_rename_at_545_127->subexpr->cset);
				das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_plus_set S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 10593971137675990283u)));
			} else {
				das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_plus S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 16627588155794449179u)));
			};
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_plus S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 16627588155794449179u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_plus 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 5937276475435012011u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Star )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_star S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 8468813470221047798u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_star 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 14644857912298426154u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Question )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_question S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 15181338593348622083u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_question 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 16449961801252633731u)));
		} else if ( __node_rename_at_545_127->op == DAS_COMMENT(enum) regex::ReOp::Group )
		{
			das_copy(__node_rename_at_545_127->fun2,Func(__context__->fnByMangledName(/*@regex::re_match2_group S<regex::Regex> 1<S<regex::ReNode>>? C1<u8>?*/ 4955995622992578248u)));
			das_copy(__node_rename_at_545_127->gen2,Func(__context__->fnByMangledName(/*@regex::re_gen2_group 1<S<regex::ReNode>>? Y<ReGenRandom>1<u>G H<strings::StringBuilderWriter>*/ 14186960190802327978u)));
		} else {
			builtin_throw(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_7, cast<char * const >::from(((char *) "unsupported ")), cast<DAS_COMMENT(enum) regex::ReOp>::from(__node_rename_at_545_127->op))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		};
	}));
}}

inline uint8_t * re_match2_single_char_ec4bd67a88d6c383 ( Context * __context__, regex::Regex &  __regex_rename_at_588_128, regex::ReNode * __node_rename_at_588_129, uint8_t * const  __str_rename_at_588_130 )
{
	if ( get_character_uat(__node_rename_at_588_129->text,0) != int32_t((*(__str_rename_at_588_130))) )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __tail_rename_at_594_131 = das_ptr_add(__str_rename_at_588_130,1,1);
		das_copy(__node_rename_at_588_129->tail,__tail_rename_at_594_131);
		regex::ReNode * __node2_rename_at_596_132 = __node_rename_at_588_129->next;
		return das_auto_cast<uint8_t *>::cast((__node2_rename_at_596_132 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_596_132->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_588_128),__node2_rename_at_596_132,__tail_rename_at_594_131)) : das_auto_cast<uint8_t *>::cast(__tail_rename_at_594_131));
	};
}

inline uint8_t * re_match2_char_e7712649ef04ae7d ( Context * __context__, regex::Regex &  __regex_rename_at_603_133, regex::ReNode * __node_rename_at_603_134, uint8_t * const  __str_rename_at_603_135 )
{
	if ( das_memcmp(das_auto_cast<void * const >::cast(das_cast<uint8_t *>::cast(__node_rename_at_603_134->text)),das_auto_cast<void * const >::cast(__str_rename_at_603_135),__node_rename_at_603_134->textLen) != 0 )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __tail_rename_at_609_136 = das_ptr_add(__str_rename_at_603_135,__node_rename_at_603_134->textLen,1);
		das_copy(__node_rename_at_603_134->tail,__tail_rename_at_609_136);
		regex::ReNode * __node2_rename_at_611_137 = __node_rename_at_603_134->next;
		return das_auto_cast<uint8_t *>::cast((__node2_rename_at_611_137 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_611_137->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_603_133),__node2_rename_at_611_137,__tail_rename_at_609_136)) : das_auto_cast<uint8_t *>::cast(__tail_rename_at_609_136));
	};
}

inline uint8_t * re_match2_union_29c921f92bb6c013 ( Context * __context__, regex::Regex &  __regex_rename_at_620_138, regex::ReNode * __node_rename_at_620_139, uint8_t * const  __str_rename_at_620_140 )
{
	{
		bool __need_loop_623 = true;
		// sub : regex::ReNode?&
		das_iterator<TArray<regex::ReNode *>> __sub_iterator(__node_rename_at_620_139->all);
		regex::ReNode * * __sub_rename_at_623_141;
		__need_loop_623 = __sub_iterator.first(__context__,(__sub_rename_at_623_141)) && __need_loop_623;
		for ( ; __need_loop_623 ; __need_loop_623 = __sub_iterator.next(__context__,(__sub_rename_at_623_141)) )
		{
			uint8_t * __osub_rename_at_624_142 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,(*__sub_rename_at_623_141)->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_620_138),(*__sub_rename_at_623_141),__str_rename_at_620_140));
			if ( __osub_rename_at_624_142 != nullptr )
			{
				das_copy(__node_rename_at_620_139->tail,(*__sub_rename_at_623_141)->tail);
				return das_auto_cast<uint8_t *>::cast(__osub_rename_at_624_142);
			};
		}
		__sub_iterator.close(__context__,(__sub_rename_at_623_141));
	};
	return das_auto_cast<uint8_t *>::cast(nullptr);
}

inline uint8_t * re_match2_set_a7d14982d3d94062 ( Context * __context__, regex::Regex &  __regex_rename_at_631_143, regex::ReNode * __node_rename_at_631_144, uint8_t * const  __str_rename_at_631_145 )
{
	if ( !is_char_in_set(int32_t((*(__str_rename_at_631_145))),das_arg<TDim<uint32_t,8>>::pass(__node_rename_at_631_144->cset),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __tail_rename_at_637_146 = das_ptr_add(__str_rename_at_631_145,1,1);
		das_copy(__node_rename_at_631_144->tail,__tail_rename_at_637_146);
		regex::ReNode * __node2_rename_at_639_147 = __node_rename_at_631_144->next;
		return das_auto_cast<uint8_t *>::cast((__node2_rename_at_639_147 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_639_147->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_631_143),__node2_rename_at_639_147,__tail_rename_at_637_146)) : das_auto_cast<uint8_t *>::cast(__tail_rename_at_637_146));
	};
}

inline uint8_t * re_match2_any_145e1cb203d4af15 ( Context * __context__, regex::Regex &  __regex_rename_at_646_148, regex::ReNode * __node_rename_at_646_149, uint8_t * const  __str_rename_at_646_150 )
{
	if ( int32_t((*(__str_rename_at_646_150))) == 0 )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __tail_rename_at_652_151 = das_ptr_add(__str_rename_at_646_150,1,1);
		das_copy(__node_rename_at_646_149->tail,__tail_rename_at_652_151);
		regex::ReNode * __node2_rename_at_654_152 = __node_rename_at_646_149->next;
		return das_auto_cast<uint8_t *>::cast((__node2_rename_at_654_152 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_654_152->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_646_148),__node2_rename_at_654_152,__tail_rename_at_652_151)) : das_auto_cast<uint8_t *>::cast(__tail_rename_at_652_151));
	};
}

inline uint8_t * re_match2_concat_aa5a3133a76ae77 ( Context * __context__, regex::Regex &  __regex_rename_at_661_153, regex::ReNode * __node_rename_at_661_154, uint8_t * const  __str_rename_at_661_155 )
{
	regex::ReNode * __left_rename_at_664_156 = __node_rename_at_661_154->left;
	uint8_t * __oleft_rename_at_665_157 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,__left_rename_at_664_156->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_661_153),__left_rename_at_664_156,__str_rename_at_661_155));
	if ( __oleft_rename_at_665_157 == nullptr )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		das_copy(__node_rename_at_661_154->tail,__node_rename_at_661_154->right->tail);
		return das_auto_cast<uint8_t *>::cast(__oleft_rename_at_665_157);
	};
}

inline uint8_t * re_match2_eos_e54e018f6fdc2874 ( Context * __context__, regex::Regex &  __regex_rename_at_672_158, regex::ReNode * __node_rename_at_672_159, uint8_t * const  __str_rename_at_672_160 )
{
	if ( int32_t((*(__str_rename_at_672_160))) != 0 )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		das_copy(__node_rename_at_672_159->tail,__str_rename_at_672_160);
		regex::ReNode * __node2_rename_at_678_161 = __node_rename_at_672_159->next;
		return das_auto_cast<uint8_t *>::cast((__node2_rename_at_678_161 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,__node2_rename_at_678_161->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_672_158),__node2_rename_at_678_161,__str_rename_at_672_160)) : das_auto_cast<uint8_t *>::cast(__str_rename_at_672_160));
	};
}

inline uint8_t * re_match2_question_c6073fc7d021f681 ( Context * __context__, regex::Regex &  __regex_rename_at_685_162, regex::ReNode * __node_rename_at_685_163, uint8_t * const  __str_rename_at_685_164 )
{
	regex::ReNode * __nsub_rename_at_688_165 = __node_rename_at_685_163->subexpr;
	uint8_t * __tail_rename_at_689_166 = das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,__nsub_rename_at_688_165->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_685_162),__nsub_rename_at_688_165,__str_rename_at_685_164);
	if ( __tail_rename_at_689_166 == nullptr )
	{
		das_copy(__tail_rename_at_689_166,__str_rename_at_685_164);
	};
	das_copy(__node_rename_at_685_163->tail,__tail_rename_at_689_166);
	regex::ReNode * __node2_rename_at_693_167 = __node_rename_at_685_163->next;
	return das_auto_cast<uint8_t *>::cast((__node2_rename_at_693_167 != nullptr) ? das_auto_cast<uint8_t *>::cast(das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_693_167->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_685_162),__node2_rename_at_693_167,__tail_rename_at_689_166)) : das_auto_cast<uint8_t *>::cast(__tail_rename_at_689_166));
}

inline uint8_t * re_match2_plus_6caa18e9465405bd ( Context * __context__, regex::Regex &  __regex_rename_at_700_168, regex::ReNode * __node_rename_at_700_169, uint8_t * const  __str_rename_at_700_170 )
{
	regex::ReNode * __nsub_rename_at_703_171 = __node_rename_at_700_169->subexpr;
	uint8_t * __osym_rename_at_704_172 = das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,__nsub_rename_at_703_171->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_700_168),__nsub_rename_at_703_171,__str_rename_at_700_170);
	if ( __osym_rename_at_704_172 == nullptr )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __ofs_rename_at_707_173 = __osym_rename_at_704_172;
		regex::ReNode * __node2_rename_at_708_174 = __node_rename_at_700_169->next;
		if ( __node2_rename_at_708_174 != nullptr )
		{
			while ( __osym_rename_at_704_172 != nullptr )
			{
				das_copy(__node_rename_at_700_169->tail,__osym_rename_at_704_172);
				uint8_t * __otail_rename_at_712_175 = das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_708_174->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_700_168),__node2_rename_at_708_174,__osym_rename_at_704_172);
				if ( __otail_rename_at_712_175 != nullptr )
				{
					return das_auto_cast<uint8_t *>::cast(__otail_rename_at_712_175);
				} else {
					das_copy(__osym_rename_at_704_172,das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__nsub_rename_at_703_171->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_700_168),__nsub_rename_at_703_171,__osym_rename_at_704_172));
				};
			};
			return das_auto_cast<uint8_t *>::cast(nullptr);
		} else {
			while ( __osym_rename_at_704_172 != nullptr )
			{
				das_copy(__ofs_rename_at_707_173,__osym_rename_at_704_172);
				das_copy(__osym_rename_at_704_172,das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__nsub_rename_at_703_171->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_700_168),__nsub_rename_at_703_171,__ofs_rename_at_707_173));
			};
			das_copy(__node_rename_at_700_169->tail,__ofs_rename_at_707_173);
			return das_auto_cast<uint8_t *>::cast(__ofs_rename_at_707_173);
		};
	};
}

inline uint8_t * re_match2_plus_set_a77e502c2ce10da5 ( Context * __context__, regex::Regex &  __regex_rename_at_725_176, regex::ReNode * __node_rename_at_725_177, uint8_t * const  __str_rename_at_725_178 )
{
	if ( !is_char_in_set(int32_t((*(__str_rename_at_725_178))),das_arg<TDim<uint32_t,8>>::pass(__node_rename_at_725_177->cset),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __ofs_rename_at_732_179 = das_ptr_add(__str_rename_at_725_178,1,1);
		uint8_t * __osym_rename_at_733_180 = __ofs_rename_at_732_179;
		regex::ReNode * __node2_rename_at_734_181 = __node_rename_at_725_177->next;
		if ( __node2_rename_at_734_181 != nullptr )
		{
			while ( __osym_rename_at_733_180 != nullptr )
			{
				das_copy(__node_rename_at_725_177->tail,__osym_rename_at_733_180);
				uint8_t * __otail_rename_at_738_182 = das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_734_181->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_725_176),__node2_rename_at_734_181,__osym_rename_at_733_180);
				if ( __otail_rename_at_738_182 != nullptr )
				{
					return das_auto_cast<uint8_t *>::cast(__otail_rename_at_738_182);
				} else {
					if ( !is_char_in_set(int32_t((*(__osym_rename_at_733_180))),das_arg<TDim<uint32_t,8>>::pass(__node_rename_at_725_177->cset),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
					{
						return das_auto_cast<uint8_t *>::cast(nullptr);
					} else {
						das_ptr_inc(__osym_rename_at_733_180,1);
					};
				};
			};
			return das_auto_cast<uint8_t *>::cast(nullptr);
		} else {
			while ( __osym_rename_at_733_180 != nullptr )
			{
				das_copy(__ofs_rename_at_732_179,__osym_rename_at_733_180);
				if ( !is_char_in_set(int32_t((*(__osym_rename_at_733_180))),das_arg<TDim<uint32_t,8>>::pass(__node_rename_at_725_177->cset),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
				{
					break;
				} else {
					das_ptr_inc(__osym_rename_at_733_180,1);
				};
			};
			das_copy(__node_rename_at_725_177->tail,__ofs_rename_at_732_179);
			return das_auto_cast<uint8_t *>::cast(__ofs_rename_at_732_179);
		};
	};
}

inline uint8_t * re_match2_star_9bdcb86ac2e0b3b3 ( Context * __context__, regex::Regex &  __regex_rename_at_755_183, regex::ReNode * __node_rename_at_755_184, uint8_t * const  __str_rename_at_755_185 )
{
	uint8_t * __ofs_rename_at_758_186 = __str_rename_at_755_185;
	regex::ReNode * __node2_rename_at_759_187 = __node_rename_at_755_184->next;
	regex::ReNode * __nsub_rename_at_760_188 = __node_rename_at_755_184->subexpr;
	if ( __node2_rename_at_759_187 != nullptr )
	{
		while ( __ofs_rename_at_758_186 != nullptr )
		{
			das_copy(__node_rename_at_755_184->tail,__ofs_rename_at_758_186);
			uint8_t * __oany_rename_at_764_189 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__node2_rename_at_759_187->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_755_183),__node2_rename_at_759_187,__ofs_rename_at_758_186));
			if ( __oany_rename_at_764_189 != nullptr )
			{
				return das_auto_cast<uint8_t *>::cast(__oany_rename_at_764_189);
			} else {
				das_copy(__ofs_rename_at_758_186,das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__nsub_rename_at_760_188->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_755_183),__nsub_rename_at_760_188,__ofs_rename_at_758_186));
			};
		};
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		uint8_t * __osym_rename_at_770_190 = __ofs_rename_at_758_186;
		while ( __osym_rename_at_770_190 != nullptr )
		{
			das_copy(__ofs_rename_at_758_186,__osym_rename_at_770_190);
			das_copy(__osym_rename_at_770_190,das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__nsub_rename_at_760_188->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_755_183),__nsub_rename_at_760_188,__ofs_rename_at_758_186));
		};
		das_copy(__node_rename_at_755_184->tail,__ofs_rename_at_758_186);
		return das_auto_cast<uint8_t *>::cast(__ofs_rename_at_758_186);
	};
}

inline uint8_t * re_match2_group_64e1ead31a846f3e ( Context * __context__, regex::Regex &  __regex_rename_at_778_191, regex::ReNode * __node_rename_at_778_192, uint8_t * const  __str_rename_at_778_193 )
{
	regex::ReNode * __nsub_rename_at_781_194 = __node_rename_at_778_192->subexpr;
	uint8_t * __osub_rename_at_782_195 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t * const >(__context__,nullptr,__nsub_rename_at_781_194->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_778_191),__nsub_rename_at_781_194,__str_rename_at_778_193));
	if ( __osub_rename_at_782_195 == nullptr )
	{
		return das_auto_cast<uint8_t *>::cast(nullptr);
	} else {
		das_copy(das_get_tuple_field<range,0>::get(__regex_rename_at_778_191.groups(__node_rename_at_778_192->index,__context__)),range(int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__str_rename_at_778_193),das_auto_cast<void * const >::cast(__regex_rename_at_778_191.match),1)),int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__node_rename_at_778_192->subexpr->tail),das_auto_cast<void * const >::cast(__regex_rename_at_778_191.match),1))));
		return das_auto_cast<uint8_t *>::cast(__osub_rename_at_782_195);
	};
}

inline bool re_early_out_922d27d5b993b87c ( Context * __context__, TDim<uint32_t,8> &  __cset_rename_at_792_196, regex::ReNode * const  __node_rename_at_792_197 )
{
	if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Char )
	{
		set_or_char_471888d9ed78efab(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),get_character_at(__node_rename_at_792_197->text,0,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))));
		return das_auto_cast<bool>::cast(false);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Set )
	{
		set_or_set_9609a9e932b32815(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->cset);
		return das_auto_cast<bool>::cast(false);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Any )
	{
		{
			bool __need_loop_800 = true;
			// x : uint aka CharSet& -const
			das_iterator<TDim<uint32_t,8>> __x_iterator(__cset_rename_at_792_196);
			uint32_t * __x_rename_at_800_198;
			__need_loop_800 = __x_iterator.first(__context__,(__x_rename_at_800_198)) && __need_loop_800;
			for ( ; __need_loop_800 ; __need_loop_800 = __x_iterator.next(__context__,(__x_rename_at_800_198)) )
			{
				das_copy((*__x_rename_at_800_198),0xffffffffu);
			}
			__x_iterator.close(__context__,(__x_rename_at_800_198));
		};
		return das_auto_cast<bool>::cast(false);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Eos )
	{
		return das_auto_cast<bool>::cast(false);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Group )
	{
		return das_auto_cast<bool>::cast(re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->subexpr));
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Plus )
	{
		return das_auto_cast<bool>::cast(re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->subexpr));
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Star )
	{
		re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->subexpr);
		return das_auto_cast<bool>::cast(true);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Question )
	{
		re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->subexpr);
		return das_auto_cast<bool>::cast(true);
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Concat )
	{
		bool __left_rename_at_816_199 = ((bool)re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->left));
		return das_auto_cast<bool>::cast(__left_rename_at_816_199 ? das_auto_cast<bool>::cast(re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),__node_rename_at_792_197->right)) : das_auto_cast<bool>::cast(false));
	} else if ( __node_rename_at_792_197->op == DAS_COMMENT(enum) regex::ReOp::Union )
	{
		bool __any_rename_at_819_200 = false;
		{
			bool __need_loop_820 = true;
			// sub : regex::ReNode? const&
			das_iterator<TArray<regex::ReNode *> const > __sub_iterator(__node_rename_at_792_197->all);
			regex::ReNode * const  * __sub_rename_at_820_201;
			__need_loop_820 = __sub_iterator.first(__context__,(__sub_rename_at_820_201)) && __need_loop_820;
			for ( ; __need_loop_820 ; __need_loop_820 = __sub_iterator.next(__context__,(__sub_rename_at_820_201)) )
			{
				das_copy(__any_rename_at_819_200,re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__cset_rename_at_792_196),(*__sub_rename_at_820_201)) || __any_rename_at_819_200);
			}
			__sub_iterator.close(__context__,(__sub_rename_at_820_201));
		};
		return das_auto_cast<bool>::cast(__any_rename_at_819_200);
	} else {
		builtin_throw(((char *) "unsupported operation"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		return das_auto_cast<bool>::cast(false);
	};
}

inline bool is_valid_f341200a6f682e5a ( Context * __context__, regex::Regex &  __re_rename_at_831_202 )
{
	return das_auto_cast<bool>::cast(__re_rename_at_831_202.root != nullptr);
}

inline bool regex_compile_18db32cc7aeccc78 ( Context * __context__, regex::Regex &  __re_rename_at_835_203, char * const  __expr_rename_at_835_204 )
{
	das_copy(__re_rename_at_835_203.root,re_parse_dcac85ee353b9cd1(__context__,__expr_rename_at_835_204));
	if ( __re_rename_at_835_203.root != nullptr )
	{
		re_assign_next_3b4ea73434aed381(__context__,das_arg<regex::Regex>::pass(__re_rename_at_835_203));
		re_assign_groups_6a6962661f0751e2(__context__,das_arg<regex::Regex>::pass(__re_rename_at_835_203));
		re_assign_match_functions_8f6d5df970baf66a(__context__,das_arg<regex::Regex>::pass(__re_rename_at_835_203));
		re_early_out_922d27d5b993b87c(__context__,das_arg<TDim<uint32_t,8>>::pass(__re_rename_at_835_203.earlyOut),__re_rename_at_835_203.root);
		das_copy(__re_rename_at_835_203.canEarlyOut,!is_set_empty_fb12252b2129800d(__context__,das_arg<TDim<uint32_t,8>>::pass(__re_rename_at_835_203.earlyOut)));
	};
	return das_auto_cast<bool>::cast(__re_rename_at_835_203.root != nullptr);
}

inline regex::Regex regex_compile_de8b67e813d240c6 ( Context * __context__, char * const  __expr_rename_at_847_205 )
{
	regex::Regex __re_rename_at_848_206; das_zero(__re_rename_at_848_206);
	if ( !regex_compile_18db32cc7aeccc78(__context__,das_arg<regex::Regex>::pass(__re_rename_at_848_206),__expr_rename_at_847_205) )
	{
		builtin_throw(das_string_builder_temp(__context__,SimNode_AotInterop<3>(__tinfo_8, cast<char * const >::from(((char *) "regular expression ")), cast<char * const >::from(__expr_rename_at_847_205), cast<char * const >::from(((char *) " did not compile")))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
	return /* <- */ das_auto_cast_move<regex::Regex>::cast(_FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55(__context__,das_arg<regex::Regex>::pass(__re_rename_at_848_206)));
}

inline regex::Regex regex_compile_6869b0e89f8c00b1 ( Context * __context__, regex::Regex &  __re_rename_at_853_207 )
{
	if ( __re_rename_at_853_207.root != nullptr )
	{
		re_assign_next_3b4ea73434aed381(__context__,das_arg<regex::Regex>::pass(__re_rename_at_853_207));
		re_assign_match_functions_8f6d5df970baf66a(__context__,das_arg<regex::Regex>::pass(__re_rename_at_853_207));
	};
	return /* <- */ das_auto_cast_move<regex::Regex>::cast(_FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55(__context__,das_arg<regex::Regex>::pass(__re_rename_at_853_207)));
}

inline int32_t regex_match_270cb942810fc6f1 ( Context * __context__, regex::Regex &  __regex_rename_at_859_208, char * const  __str_rename_at_859_209, int32_t __offset_rename_at_859_210 )
{
	if ( builtin_empty(__str_rename_at_859_209) )
	{
		return das_auto_cast<int32_t>::cast(-1);
	} else {
		das_copy(__regex_rename_at_859_208.match,das_cast<uint8_t *>::cast(__str_rename_at_859_209));
		uint8_t * __mptr_rename_at_868_211 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__regex_rename_at_859_208.root->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_859_208),__regex_rename_at_859_208.root,__regex_rename_at_859_208.match));
		return das_auto_cast<int32_t>::cast((__mptr_rename_at_868_211 == nullptr) ? das_auto_cast<int32_t>::cast(-1) : das_auto_cast<int32_t>::cast(int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__mptr_rename_at_868_211),das_auto_cast<void * const >::cast(__regex_rename_at_859_208.match),1))));
	};
}

inline char * regex_group_53f438f6c88fd53d ( Context * __context__, regex::Regex const  &  __regex_rename_at_873_212, int32_t __index_rename_at_873_213, char * const  __match_rename_at_873_214 )
{
	range __sub_range_rename_at_875_215 = ((range)das_get_tuple_field<range,0>::get(__regex_rename_at_873_212.groups(__index_rename_at_873_213,__context__)));
	return das_auto_cast<char *>::cast(((char *)(builtin_string_slice1(__match_rename_at_873_214,v_extract_xi(v_cast_vec4i(__sub_range_rename_at_875_215)) /*x*/,v_extract_yi(v_cast_vec4i(__sub_range_rename_at_875_215)) /*y*/,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}

inline void regex_foreach_31d894777e8f6051 ( Context * __context__, regex::Regex &  __regex_rename_at_879_216, char * const  __str_rename_at_879_217, Block DAS_COMMENT((bool,range)) const  &  __blk_rename_at_879_218 )
{
	if ( builtin_empty(__str_rename_at_879_217) )
	{
		return ;
	} else {
		das_copy(__regex_rename_at_879_216.match,das_cast<uint8_t *>::cast(__str_rename_at_879_217));
		regex::ReNode * __root_rename_at_885_219 = __regex_rename_at_879_216.root;
		uint8_t * __pstr_rename_at_886_220 = das_cast<uint8_t *>::cast(__str_rename_at_879_217);
		uint8_t * __cstr_rename_at_887_221 = __pstr_rename_at_886_220;
		if ( __regex_rename_at_879_216.canEarlyOut )
		{
			while ( true )
			{
				int32_t __Ch_rename_at_891_222 = ((int32_t)int32_t((*(__cstr_rename_at_887_221))));
				if ( __Ch_rename_at_891_222 == 0 )
				{
					break;
				} else {
					if ( is_char_in_set(__Ch_rename_at_891_222,das_arg<TDim<uint32_t,8>>::pass(__regex_rename_at_879_216.earlyOut),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
					{
						uint8_t * __om_rename_at_895_223 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__root_rename_at_885_219->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_879_216),__root_rename_at_885_219,__cstr_rename_at_887_221));
						if ( __om_rename_at_895_223 != nullptr )
						{
							if ( !das_invoke<bool>::invoke<range>(__context__,nullptr,__blk_rename_at_879_218,range(int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__cstr_rename_at_887_221),das_auto_cast<void * const >::cast(__pstr_rename_at_886_220),1)),int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__om_rename_at_895_223),das_auto_cast<void * const >::cast(__pstr_rename_at_886_220),1)))) )
							{
								break;
							} else {
								das_copy(__cstr_rename_at_887_221,__om_rename_at_895_223);
							};
						} else {
							das_ptr_inc(__cstr_rename_at_887_221,1);
						};
					} else {
						das_ptr_inc(__cstr_rename_at_887_221,1);
					};
				};
			};
		} else {
			while ( int32_t((*(__cstr_rename_at_887_221))) != 0 )
			{
				uint8_t * __om_rename_at_906_224 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__root_rename_at_885_219->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_879_216),__root_rename_at_885_219,__cstr_rename_at_887_221));
				if ( __om_rename_at_906_224 != nullptr )
				{
					if ( !das_invoke<bool>::invoke<range>(__context__,nullptr,__blk_rename_at_879_218,range(int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__cstr_rename_at_887_221),das_auto_cast<void * const >::cast(__pstr_rename_at_886_220),1)),int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__om_rename_at_906_224),das_auto_cast<void * const >::cast(__pstr_rename_at_886_220),1)))) )
					{
						break;
					} else {
						das_copy(__cstr_rename_at_887_221,__om_rename_at_906_224);
					};
				} else {
					das_ptr_inc(__cstr_rename_at_887_221,1);
				};
			};
		};
	};
}

inline char * regex_replace_406545def8f63efd ( Context * __context__, regex::Regex &  __regex_rename_at_915_225, char * const  __str_rename_at_915_226, Block DAS_COMMENT((char *,char * const )) const  &  __blk_rename_at_915_227 )
{
	return das_auto_cast<char *>::cast(builtin_empty(__str_rename_at_915_226) ? das_auto_cast<char * const >::cast(nullptr) : das_auto_cast<char * const >::cast(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_920_228) DAS_AOT_INLINE_LAMBDA -> void{
		das_copy(__regex_rename_at_915_225.match,das_cast<uint8_t *>::cast(__str_rename_at_915_226));
		regex::ReNode * __root_rename_at_922_229 = __regex_rename_at_915_225.root;
		uint8_t * __pstr_rename_at_923_230 = das_cast<uint8_t *>::cast(__str_rename_at_915_226);
		uint8_t * __cstr_rename_at_924_231 = __pstr_rename_at_923_230;
		if ( __regex_rename_at_915_225.canEarlyOut )
		{
			while ( true )
			{
				int32_t __Ch_rename_at_928_232 = ((int32_t)int32_t((*(__cstr_rename_at_924_231))));
				if ( __Ch_rename_at_928_232 == 0 )
				{
					break;
				} else {
					if ( is_char_in_set(__Ch_rename_at_928_232,das_arg<TDim<uint32_t,8>>::pass(__regex_rename_at_915_225.earlyOut),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))) )
					{
						uint8_t * __om_rename_at_932_233 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__root_rename_at_922_229->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_915_225),__root_rename_at_922_229,__cstr_rename_at_924_231));
						if ( __om_rename_at_932_233 != nullptr )
						{
							char * __repl_rename_at_934_234 = ((char *)(char *)(das_invoke<char *>::invoke<char *>(__context__,nullptr,__blk_rename_at_915_227,((char *)(builtin_string_slice1(__str_rename_at_915_226,int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__cstr_rename_at_924_231),das_auto_cast<void * const >::cast(__pstr_rename_at_923_230),1)),int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__om_rename_at_932_233),das_auto_cast<void * const >::cast(__pstr_rename_at_923_230),1)),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))))));
							das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_9,cast<StringBuilderWriter &>::from(__writer_rename_at_920_228),cast<char * const >::from(__repl_rename_at_934_234)));
							das_copy(__cstr_rename_at_924_231,__om_rename_at_932_233);
						} else {
							write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_920_228),__Ch_rename_at_928_232);
							das_ptr_inc(__cstr_rename_at_924_231,1);
						};
					} else {
						write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_920_228),__Ch_rename_at_928_232);
						das_ptr_inc(__cstr_rename_at_924_231,1);
					};
				};
			};
		} else {
			while ( int32_t((*(__cstr_rename_at_924_231))) != 0 )
			{
				uint8_t * __om_rename_at_945_235 = ((uint8_t *)das_invoke_function<uint8_t *>::invoke<regex::Regex &,regex::ReNode *,uint8_t *>(__context__,nullptr,__root_rename_at_922_229->fun2,das_arg<regex::Regex>::pass(__regex_rename_at_915_225),__root_rename_at_922_229,__cstr_rename_at_924_231));
				if ( __om_rename_at_945_235 != nullptr )
				{
					char * __repl_rename_at_947_236 = ((char *)(char *)(das_invoke<char *>::invoke<char *>(__context__,nullptr,__blk_rename_at_915_227,((char *)(builtin_string_slice1(__str_rename_at_915_226,int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__cstr_rename_at_924_231),das_auto_cast<void * const >::cast(__pstr_rename_at_923_230),1)),int32_t(i_das_ptr_diff(das_auto_cast<void * const >::cast(__om_rename_at_945_235),das_auto_cast<void * const >::cast(__pstr_rename_at_923_230),1)),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))))));
					das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_10,cast<StringBuilderWriter &>::from(__writer_rename_at_920_228),cast<char * const >::from(__repl_rename_at_947_236)));
					das_copy(__cstr_rename_at_924_231,__om_rename_at_945_235);
				} else {
					write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_920_228),int32_t((*(__cstr_rename_at_924_231))));
					das_ptr_inc(__cstr_rename_at_924_231,1);
				};
			};
		};
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
}

inline void regex_debug_1a2f3227d12bb74b ( Context * __context__, regex::Regex const  &  __regex_rename_at_958_237 )
{
	debug_re_8aa07286a87ace73(__context__,__regex_rename_at_958_237.root,1);
	builtin_print(((char *) "\n"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	if ( __regex_rename_at_958_237.canEarlyOut )
	{
		builtin_print(((char *) "early out: "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_set_5bfd1461cc2bf4d3(__context__,__regex_rename_at_958_237.earlyOut);
		builtin_print(((char *) "\n"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
	if ( builtin_array_size(__regex_rename_at_958_237.groups) != 0 )
	{
		builtin_print(((char *) "groups:"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		{
			bool __need_loop_968 = true;
			// g : tuple<range;string> const&
			das_iterator<TArray<TTuple<16,range,char *>> const > __g_iterator(__regex_rename_at_958_237.groups);
			TTuple<16,range,char *> const  * __g_rename_at_968_238;
			__need_loop_968 = __g_iterator.first(__context__,(__g_rename_at_968_238)) && __need_loop_968;
			for ( ; __need_loop_968 ; __need_loop_968 = __g_iterator.next(__context__,(__g_rename_at_968_238)) )
			{
				builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<3>(__tinfo_11, cast<char * const >::from(((char *) "\t")), cast<char * const >::from(das_get_tuple_field<char *,8>::get((*__g_rename_at_968_238))), cast<char * const >::from(((char *) "\n")))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
			}
			__g_iterator.close(__context__,(__g_rename_at_968_238));
		};
	};
}

inline void debug_set_5bfd1461cc2bf4d3 ( Context * __context__, TDim<uint32_t,8> const  &  __cset_rename_at_971_239 )
{
	{
		bool __need_loop_973 = true;
		// x : int const
		das_iterator<range> __x_iterator(range(0,256));
		int32_t __x_rename_at_973_240;
		__need_loop_973 = __x_iterator.first(__context__,(__x_rename_at_973_240)) && __need_loop_973;
		for ( ; __need_loop_973 ; __need_loop_973 = __x_iterator.next(__context__,(__x_rename_at_973_240)) )
		{
			if ( (__cset_rename_at_971_239((__x_rename_at_973_240 >> 5),__context__) & uint32_t(1 << (__x_rename_at_973_240 & 31))) != 0x0u )
			{
				if ( (__x_rename_at_973_240 >= 32) && (__x_rename_at_973_240 <= 127) )
				{
					builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<1>(__tinfo_12, cast<char *>::from(((char *)(to_string_char(__x_rename_at_973_240,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
				} else {
					builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_13, cast<char * const >::from(((char *) "\\")), cast<int32_t>::from(__x_rename_at_973_240))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
				};
			};
		}
		__x_iterator.close(__context__,(__x_rename_at_973_240));
	};
}

inline void debug_re_8aa07286a87ace73 ( Context * __context__, regex::ReNode * const  __node_rename_at_980_241, int32_t __tab_rename_at_980_242 )
{
	builtin_print(((char *) "("),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	if ( __node_rename_at_980_241 != nullptr )
	{
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_14, cast<char * const >::from(((char *) "#")), cast<int32_t>::from(__node_rename_at_980_241->id))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		if ( __node_rename_at_980_241->next != nullptr )
		{
			builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_15, cast<char * const >::from(((char *) "->")), cast<int32_t>::from(__node_rename_at_980_241->next->id))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		} else {
			builtin_print(((char *) "->!"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		};
		builtin_print(((char *) " "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
	if ( __node_rename_at_980_241 == nullptr )
	{
		builtin_print(((char *) "null)"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Char )
	{
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<3>(__tinfo_16, cast<char * const >::from(((char *) "Char `")), cast<char * const >::from(__node_rename_at_980_241->text), cast<char * const >::from(((char *) "`)")))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Set )
	{
		builtin_print(((char *) "Set "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_set_5bfd1461cc2bf4d3(__context__,__node_rename_at_980_241->cset);
		builtin_print(((char *) ")"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Any )
	{
		builtin_print(((char *) "Any)"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Eos )
	{
		builtin_print(((char *) "Eos)"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Group )
	{
		builtin_print(((char *) "Group "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->subexpr,__tab_rename_at_980_242 + 1);
		builtin_print(((char *) ")"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Plus )
	{
		builtin_print(((char *) "Plus "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->subexpr,__tab_rename_at_980_242);
		builtin_print(((char *) ")"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Star )
	{
		builtin_print(((char *) "Star "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->subexpr,__tab_rename_at_980_242);
		builtin_print(((char *) ")"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Question )
	{
		builtin_print(((char *) "Question "),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->subexpr,__tab_rename_at_980_242);
		builtin_print(((char *) ")"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Concat )
	{
		builtin_print(((char *) "Contact"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_17, cast<char * const >::from(((char *) "\n")), cast<char *>::from(((char *)(string_repeat(((char *) "\t"),__tab_rename_at_980_242,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->left,__tab_rename_at_980_242 + 1);
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_18, cast<char * const >::from(((char *) "\n")), cast<char *>::from(((char *)(string_repeat(((char *) "\t"),__tab_rename_at_980_242,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		debug_re_8aa07286a87ace73(__context__,__node_rename_at_980_241->right,__tab_rename_at_980_242 + 1);
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<3>(__tinfo_19, cast<char * const >::from(((char *) "\n")), cast<char *>::from(((char *)(string_repeat(((char *) "\t"),__tab_rename_at_980_242 - 1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) ")")))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else if ( __node_rename_at_980_241->op == DAS_COMMENT(enum) regex::ReOp::Union )
	{
		builtin_print(((char *) "Union\n"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
		{
			bool __need_loop_1026 = true;
			// sub : regex::ReNode? const&
			das_iterator<TArray<regex::ReNode *> const > __sub_iterator(__node_rename_at_980_241->all);
			regex::ReNode * const  * __sub_rename_at_1026_243;
			__need_loop_1026 = __sub_iterator.first(__context__,(__sub_rename_at_1026_243)) && __need_loop_1026;
			for ( ; __need_loop_1026 ; __need_loop_1026 = __sub_iterator.next(__context__,(__sub_rename_at_1026_243)) )
			{
				builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<1>(__tinfo_20, cast<char *>::from(((char *)(string_repeat(((char *) "\t"),__tab_rename_at_980_242,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
				debug_re_8aa07286a87ace73(__context__,(*__sub_rename_at_1026_243),__tab_rename_at_980_242 + 1);
				builtin_print(((char *) "\n"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
			}
			__sub_iterator.close(__context__,(__sub_rename_at_1026_243));
		};
		builtin_print(das_string_builder_temp(__context__,SimNode_AotInterop<2>(__tinfo_21, cast<char *>::from(((char *)(string_repeat(((char *) "\t"),__tab_rename_at_980_242 - 1,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))), cast<char * const >::from(((char *) ")")))),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	} else {
		builtin_throw(((char *) "unsupported op"),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	};
}

inline int32_t rnd_set_character_f49e90c9ced30293 ( Context * __context__, TDim<uint32_t,8> const  &  __cset_rename_at_1036_244, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1036_245 )
{
	uint32_t __total_rename_at_1037_246 = ((uint32_t)char_set_total(__cset_rename_at_1036_244));
	uint32_t __idx_rename_at_1038_247 = 0x0u;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1036_245),__idx_rename_at_1038_247);
	das_copy(__idx_rename_at_1038_247,SimPolicy<uint32_t>::Mod(__idx_rename_at_1038_247,__total_rename_at_1037_246,*__context__,nullptr));
	return das_auto_cast<int32_t>::cast(char_set_element(int32_t(__idx_rename_at_1038_247),__cset_rename_at_1036_244));
}

inline void re_gen2_fail_83869989d4feff33 ( Context * __context__, regex::ReNode * __node_rename_at_1043_248, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1043_249, StringBuilderWriter &  __str_rename_at_1043_250 )
{
	DAS_ASSERTF((false),(((char *) "not running generated regex")));
}

inline void re_gen2_char_f50387c056fd98bf ( Context * __context__, regex::ReNode * __node_rename_at_1048_251, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1048_252, StringBuilderWriter &  __str_rename_at_1048_253 )
{
	das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_22,cast<StringBuilderWriter &>::from(__str_rename_at_1048_253),cast<char *>::from(__node_rename_at_1048_251->text)));
	regex::ReNode * __node2_rename_at_1052_254 = __node_rename_at_1048_251->next;
	if ( __node2_rename_at_1052_254 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1052_254->gen2,__node2_rename_at_1052_254,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1048_252),das_arg<StringBuilderWriter>::pass(__str_rename_at_1048_253));
	};
}

inline void re_gen2_union_9643fdb28fe9f09d ( Context * __context__, regex::ReNode * __node_rename_at_1056_255, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1056_256, StringBuilderWriter &  __str_rename_at_1056_257 )
{
	uint32_t __nidx_rename_at_1059_258 = 0x0u;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1056_256),__nidx_rename_at_1059_258);
	das_copy(__nidx_rename_at_1059_258,SimPolicy<uint32_t>::Mod(__nidx_rename_at_1059_258,uint32_t(builtin_array_size(das_arg<TArray<regex::ReNode *>>::pass(__node_rename_at_1056_255->all))),*__context__,nullptr));
	regex::ReNode * __sub_rename_at_1062_259 = __node_rename_at_1056_255->all(__nidx_rename_at_1059_258,__context__);
	das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__sub_rename_at_1062_259->gen2,__sub_rename_at_1062_259,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1056_256),das_arg<StringBuilderWriter>::pass(__str_rename_at_1056_257));
}

inline void re_gen2_set_687ad6fcb132e4de ( Context * __context__, regex::ReNode * __node_rename_at_1065_260, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1065_261, StringBuilderWriter &  __str_rename_at_1065_262 )
{
	write_string_char(das_arg<StringBuilderWriter>::pass(__str_rename_at_1065_262),rnd_set_character_f49e90c9ced30293(__context__,das_arg<TDim<uint32_t,8>>::pass(__node_rename_at_1065_260->cset),das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1065_261)));
	regex::ReNode * __node2_rename_at_1069_263 = __node_rename_at_1065_260->next;
	if ( __node2_rename_at_1069_263 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1069_263->gen2,__node2_rename_at_1069_263,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1065_261),das_arg<StringBuilderWriter>::pass(__str_rename_at_1065_262));
	};
}

inline void re_gen2_any_998ffcd284a238dd ( Context * __context__, regex::ReNode * __node_rename_at_1073_264, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1073_265, StringBuilderWriter &  __str_rename_at_1073_266 )
{
	uint32_t __ch_rename_at_1076_267 = 0;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1073_265),__ch_rename_at_1076_267);
	write_string_char(das_arg<StringBuilderWriter>::pass(__str_rename_at_1073_266),int32_t((SimPolicy<uint32_t>::Mod(__ch_rename_at_1076_267,0xffu,*__context__,nullptr)) + 0x1u));
	regex::ReNode * __node2_rename_at_1079_268 = __node_rename_at_1073_264->next;
	if ( __node2_rename_at_1079_268 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1079_268->gen2,__node2_rename_at_1079_268,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1073_265),das_arg<StringBuilderWriter>::pass(__str_rename_at_1073_266));
	};
}

inline void re_gen2_concat_2acaded76c0d6fe4 ( Context * __context__, regex::ReNode * __node_rename_at_1083_269, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1083_270, StringBuilderWriter &  __str_rename_at_1083_271 )
{
	regex::ReNode * __left_rename_at_1086_272 = __node_rename_at_1083_269->left;
	das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__left_rename_at_1086_272->gen2,__left_rename_at_1086_272,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1083_270),das_arg<StringBuilderWriter>::pass(__str_rename_at_1083_271));
}

inline void re_gen2_eos_b4ed344d74735b22 ( Context * __context__, regex::ReNode * __node_rename_at_1089_273, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1089_274, StringBuilderWriter &  __str_rename_at_1089_275 )
{
	regex::ReNode * __node2_rename_at_1092_276 = __node_rename_at_1089_273->next;
	if ( __node2_rename_at_1092_276 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1092_276->gen2,__node2_rename_at_1092_276,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1089_274),das_arg<StringBuilderWriter>::pass(__str_rename_at_1089_275));
	};
}

inline void re_gen2_question_23526c1a36f227c7 ( Context * __context__, regex::ReNode * __node_rename_at_1096_277, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1096_278, StringBuilderWriter &  __str_rename_at_1096_279 )
{
	uint32_t __a_rename_at_1099_280 = 0x0u;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1096_278),__a_rename_at_1099_280);
	if ( (__a_rename_at_1099_280 & 0x1u) != 0x0u )
	{
		regex::ReNode * __nsub_rename_at_1102_281 = __node_rename_at_1096_277->subexpr;
		if ( __nsub_rename_at_1102_281 != nullptr )
		{
			das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__nsub_rename_at_1102_281->gen2,__nsub_rename_at_1102_281,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1096_278),das_arg<StringBuilderWriter>::pass(__str_rename_at_1096_279));
		};
	};
	regex::ReNode * __node2_rename_at_1105_282 = __node_rename_at_1096_277->next;
	if ( __node2_rename_at_1105_282 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1105_282->gen2,__node2_rename_at_1105_282,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1096_278),das_arg<StringBuilderWriter>::pass(__str_rename_at_1096_279));
	};
}

inline void re_gen2_plus_76879af5add2064f ( Context * __context__, regex::ReNode * __node_rename_at_1109_283, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1109_284, StringBuilderWriter &  __str_rename_at_1109_285 )
{
	uint32_t __cnt_rename_at_1112_286 = 0x0u;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1109_284),__cnt_rename_at_1112_286);
	das_copy(__cnt_rename_at_1112_286,(SimPolicy<uint32_t>::Mod(__cnt_rename_at_1112_286,das_global<uint32_t,0x8ce995ce57e18608>(__context__) /*re_gen_rep_limit*/,*__context__,nullptr)) + 0x1u);
	regex::ReNode * __nsub_rename_at_1115_287 = __node_rename_at_1109_283->subexpr;
	if ( __nsub_rename_at_1115_287 != nullptr )
	{
		{
			bool __need_loop_1117 = true;
			// i : uint const
			das_iterator<urange> __i_iterator(mk_urange(__cnt_rename_at_1112_286));
			uint32_t __i_rename_at_1117_288;
			__need_loop_1117 = __i_iterator.first(__context__,(__i_rename_at_1117_288)) && __need_loop_1117;
			for ( ; __need_loop_1117 ; __need_loop_1117 = __i_iterator.next(__context__,(__i_rename_at_1117_288)) )
			{
				das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__nsub_rename_at_1115_287->gen2,__nsub_rename_at_1115_287,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1109_284),das_arg<StringBuilderWriter>::pass(__str_rename_at_1109_285));
			}
			__i_iterator.close(__context__,(__i_rename_at_1117_288));
		};
	};
	regex::ReNode * __node2_rename_at_1119_289 = __node_rename_at_1109_283->next;
	if ( __node2_rename_at_1119_289 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1119_289->gen2,__node2_rename_at_1119_289,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1109_284),das_arg<StringBuilderWriter>::pass(__str_rename_at_1109_285));
	};
}

inline void re_gen2_star_2b17ac0e3bbfc0b0 ( Context * __context__, regex::ReNode * __node_rename_at_1123_290, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1123_291, StringBuilderWriter &  __str_rename_at_1123_292 )
{
	uint32_t __cnt_rename_at_1126_293 = 0x0u;
	_FuncbuiltinTicknext_160159e214cdd056(__context__,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1123_291),__cnt_rename_at_1126_293);
	das_copy(__cnt_rename_at_1126_293,SimPolicy<uint32_t>::Mod(__cnt_rename_at_1126_293,das_global<uint32_t,0x8ce995ce57e18608>(__context__) /*re_gen_rep_limit*/,*__context__,nullptr));
	regex::ReNode * __nsub_rename_at_1129_294 = __node_rename_at_1123_290->subexpr;
	if ( __nsub_rename_at_1129_294 != nullptr )
	{
		{
			bool __need_loop_1131 = true;
			// i : uint const
			das_iterator<urange> __i_iterator(mk_urange(__cnt_rename_at_1126_293));
			uint32_t __i_rename_at_1131_295;
			__need_loop_1131 = __i_iterator.first(__context__,(__i_rename_at_1131_295)) && __need_loop_1131;
			for ( ; __need_loop_1131 ; __need_loop_1131 = __i_iterator.next(__context__,(__i_rename_at_1131_295)) )
			{
				das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__nsub_rename_at_1129_294->gen2,__nsub_rename_at_1129_294,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1123_291),das_arg<StringBuilderWriter>::pass(__str_rename_at_1123_292));
			}
			__i_iterator.close(__context__,(__i_rename_at_1131_295));
		};
	};
	regex::ReNode * __node2_rename_at_1133_296 = __node_rename_at_1123_290->next;
	if ( __node2_rename_at_1133_296 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1133_296->gen2,__node2_rename_at_1133_296,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1123_291),das_arg<StringBuilderWriter>::pass(__str_rename_at_1123_292));
	};
}

inline void re_gen2_group_220ee7b205b18ab6 ( Context * __context__, regex::ReNode * __node_rename_at_1137_297, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1137_298, StringBuilderWriter &  __str_rename_at_1137_299 )
{
	regex::ReNode * __nsub_rename_at_1140_300 = __node_rename_at_1137_297->subexpr;
	if ( __nsub_rename_at_1140_300 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__nsub_rename_at_1140_300->gen2,__nsub_rename_at_1140_300,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1137_298),das_arg<StringBuilderWriter>::pass(__str_rename_at_1137_299));
	};
	regex::ReNode * __node2_rename_at_1143_301 = __node_rename_at_1137_297->next;
	if ( __node2_rename_at_1143_301 != nullptr )
	{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__node2_rename_at_1143_301->gen2,__node2_rename_at_1143_301,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1137_298),das_arg<StringBuilderWriter>::pass(__str_rename_at_1137_299));
	};
}

inline char * re_gen_782e537f3d526983 ( Context * __context__, regex::Regex &  __re_rename_at_1147_302, Sequence DAS_COMMENT((uint32_t)) &  __rnd_rename_at_1147_303 )
{
	return das_auto_cast<char *>::cast(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_1148_304) DAS_AOT_INLINE_LAMBDA -> void{
		das_invoke_function<void>::invoke<regex::ReNode *,Sequence DAS_COMMENT((uint32_t)) &,StringBuilderWriter &>(__context__,nullptr,__re_rename_at_1147_302.root->gen2,__re_rename_at_1147_302.root,das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__rnd_rename_at_1147_303),das_arg<StringBuilderWriter>::pass(__writer_rename_at_1148_304));
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncbuiltinTickresize_648390880f9db2f3
	aotLib[0xdeffd8e495b508cb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<regex::ReNode *> & , int32_t  ),&_FuncbuiltinTickresize_648390880f9db2f3>>();
	};
	// _FuncbuiltinTickfinalize_c949f429586500db
	aotLib[0x2c215c5b373afbba] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<regex::ReNode *> &  ),&_FuncbuiltinTickfinalize_c949f429586500db>>();
	};
	// _FuncbuiltinTicklength_7938efcc1bc3eff1
	aotLib[0x1ae4a2b3d2ee865b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<regex::ReNode *,2> const  &  ),&_FuncbuiltinTicklength_7938efcc1bc3eff1>>();
	};
	// finalize_bfa54b0105e1d809
	aotLib[0x97b3eaad5c557d57] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode &  ),&finalize_bfa54b0105e1d809>>();
	};
	// _FuncbuiltinTickpush_1336ab62a70ec972
	aotLib[0x7dddb4cd6a71bfaf] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<TTuple<16,range,char *>> & , TTuple<16,range,char *> const  &  ),&_FuncbuiltinTickpush_1336ab62a70ec972>>();
	};
	// _FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55
	aotLib[0xd73b75ee0f6b2c31] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<regex::Regex & (*) ( Context * __context__, regex::Regex &  ),&_FuncbuiltinTick_return_with_lockcheck_21207450d9cafc55>>();
	};
	// _FuncregexTickfrom_hex_4f3a3d7adb464151
	aotLib[0xeea2ac0ee4591563] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, int32_t , int32_t  ),&_FuncregexTickfrom_hex_4f3a3d7adb464151>>();
	};
	// finalize_2abcbb928def4524
	aotLib[0x37bcd5860ee7304b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> &  ),&finalize_2abcbb928def4524>>();
	};
	// finalize_b8b6319fe678761c
	aotLib[0x186afaecec0fa8d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * &  ),&finalize_b8b6319fe678761c>>();
	};
	// _FuncbuiltinTickpush_362eabc9d9f1c608
	aotLib[0xc1cc66397aab92db] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<regex::ReNode *> & , regex::ReNode * const   ),&_FuncbuiltinTickpush_362eabc9d9f1c608>>();
	};
	// _FuncbuiltinTickto_array_move_610602215d8cf914
	aotLib[0xe109df1487290a69] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<regex::ReNode *> (*) ( Context * __context__, TDim<regex::ReNode *,2> &  ),&_FuncbuiltinTickto_array_move_610602215d8cf914>>();
	};
	// _FuncbuiltinTicknext_160159e214cdd056
	aotLib[0x7f089bc669eb5c6b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, Sequence DAS_COMMENT((uint32_t)) const  & , uint32_t &  ),&_FuncbuiltinTicknext_160159e214cdd056>>();
	};
	// re_gen_get_rep_limit_3aaf29e074018c44
	aotLib[0x79a5e44f8ae7f150] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__ ),&re_gen_get_rep_limit_3aaf29e074018c44>>();
	};
	// trace_89f6695f8909b072
	aotLib[0xc845ba95a737c7fc] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, char * const  , int32_t  ),&trace_89f6695f8909b072>>();
	};
	// note_89f6695f8909b072
	aotLib[0xc845ba95a737c7fc] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, char * const  , int32_t  ),&note_89f6695f8909b072>>();
	};
	// trace_backtrack_c77fe5b3ac1a6a7c
	aotLib[0x888198680207ab01] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__ ),&trace_backtrack_c77fe5b3ac1a6a7c>>();
	};
	// trace_value_4739abdd3b0a7208
	aotLib[0x474ae064a295f895] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * const   ),&trace_value_4739abdd3b0a7208>>();
	};
	// nada_5086bd0a540f8186
	aotLib[0xe0258857a79ae46] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__ ),&nada_5086bd0a540f8186>>();
	};
	// maybe_d7a4f325999cb99b
	aotLib[0x3f10aa504d320b39] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, regex::ReNode * const   ),&maybe_d7a4f325999cb99b>>();
	};
	// eos_dde6e11fd3802ac8
	aotLib[0xdf2982c64054bd3a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, char * const  , int32_t  ),&eos_dde6e11fd3802ac8>>();
	};
	// at_c9bade5ff7edd57d
	aotLib[0xe9714e91ae5c264e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, char * const  , int32_t  ),&at_c9bade5ff7edd57d>>();
	};
	// next_1bd07c8c346bbbc2
	aotLib[0x9570215ffb893f0c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TVariant<16,8,regex::ReNode *,void *> const  &  ),&next_1bd07c8c346bbbc2>>();
	};
	// is_set_empty_fb12252b2129800d
	aotLib[0xd0ac8f3ec6cfba89] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TDim<uint32_t,8> const  &  ),&is_set_empty_fb12252b2129800d>>();
	};
	// set_or_char_471888d9ed78efab
	aotLib[0x892b316805da6b42] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> & , int32_t  ),&set_or_char_471888d9ed78efab>>();
	};
	// set_or_range_6e993851d775263
	aotLib[0x940fb462e7c80505] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> & , range  ),&set_or_range_6e993851d775263>>();
	};
	// set_invert_be791c77bc6b6a11
	aotLib[0xcb36b69c72d9a9d6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> &  ),&set_invert_be791c77bc6b6a11>>();
	};
	// set_or_set_9609a9e932b32815
	aotLib[0xe634f3e9cdac97f4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> & , TDim<uint32_t,8> const  &  ),&set_or_set_9609a9e932b32815>>();
	};
	// set_negative_7a1fcd94df7d5358
	aotLib[0xbbb6a43baf9204fa] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> &  ),&set_negative_7a1fcd94df7d5358>>();
	};
	// set_meta_cc349e8f6f2b739
	aotLib[0x1e685c2b7b5f22c7] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> & , int32_t  ),&set_meta_cc349e8f6f2b739>>();
	};
	// is_meta_character_24d3d25015b1373f
	aotLib[0xf54416db31f754e3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, int32_t  ),&is_meta_character_24d3d25015b1373f>>();
	};
	// is_set_character_11f8fcca4329c870
	aotLib[0x706d3735bb4fb908] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, int32_t  ),&is_set_character_11f8fcca4329c870>>();
	};
	// from_hex_aec816dc2407436
	aotLib[0x4506ad37c83618f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, int32_t  ),&from_hex_aec816dc2407436>>();
	};
	// string_from_hex_d2d056a03cdfae17
	aotLib[0xbbbb925d4d78e65b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, int32_t  ),&string_from_hex_d2d056a03cdfae17>>();
	};
	// string_from_hex_58ccb558a2a0b0ed
	aotLib[0x61ee812bcd64545] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, int32_t , int32_t  ),&string_from_hex_58ccb558a2a0b0ed>>();
	};
	// re_char_dc689de6efe3e576
	aotLib[0xeeef93c03ce74e4d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_char_dc689de6efe3e576>>();
	};
	// re_set_items_9fb85eb4dd2de0ce
	aotLib[0x7ac89a125e432e30] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_set_items_9fb85eb4dd2de0ce>>();
	};
	// re_set_60109875d3448735
	aotLib[0x8ba9645d4555adeb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_set_60109875d3448735>>();
	};
	// re_any_f6446c9dabb991e5
	aotLib[0x1b18670922d44711] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_any_f6446c9dabb991e5>>();
	};
	// re_eos_ce6b3dba83357e14
	aotLib[0x6c9ba9526d7efc15] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_eos_ce6b3dba83357e14>>();
	};
	// re_group_73b2a2ffd8d6e095
	aotLib[0xa5e3bc67f9024832] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_group_73b2a2ffd8d6e095>>();
	};
	// re_elementary_9f9a7e4e2c98fef1
	aotLib[0x3d3a6f98bc141630] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_elementary_9f9a7e4e2c98fef1>>();
	};
	// mk_concat_7baa59a4cd5a0a70
	aotLib[0x8f52f9c4e1780bf4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<regex::ReNode * (*) ( Context * __context__, regex::ReNode * , regex::ReNode *  ),&mk_concat_7baa59a4cd5a0a70>>();
	};
	// mk_union_ef2057df16785333
	aotLib[0x5d5ebd931cd8c10d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<regex::ReNode * (*) ( Context * __context__, regex::ReNode * , regex::ReNode *  ),&mk_union_ef2057df16785333>>();
	};
	// re_re_36eba07f5043127c
	aotLib[0x72d162cbc847a478] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_re_36eba07f5043127c>>();
	};
	// re_basic_16364ce684bfd02f
	aotLib[0xf8eb6e3906786d1a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TVariant<16,8,regex::ReNode *,void *> (*) ( Context * __context__, char * const  , int32_t  ),&re_basic_16364ce684bfd02f>>();
	};
	// re_parse_dcac85ee353b9cd1
	aotLib[0x32002e51db11002e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<regex::ReNode * (*) ( Context * __context__, char * const   ),&re_parse_dcac85ee353b9cd1>>();
	};
	// visit_top_down_ac16ba95cc2d1c98
	aotLib[0x8afe5a8fad79ffb8] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Block DAS_COMMENT((void,regex::ReNode *)) const  &  ),&visit_top_down_ac16ba95cc2d1c98>>();
	};
	// re_assign_next_3b4ea73434aed381
	aotLib[0x581600f63b4b9432] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex &  ),&re_assign_next_3b4ea73434aed381>>();
	};
	// re_assign_groups_6a6962661f0751e2
	aotLib[0xdce9a7968c372a68] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex &  ),&re_assign_groups_6a6962661f0751e2>>();
	};
	// re_assign_match_functions_8f6d5df970baf66a
	aotLib[0x756d9bba8785c82d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex &  ),&re_assign_match_functions_8f6d5df970baf66a>>();
	};
	// re_match2_single_char_ec4bd67a88d6c383
	aotLib[0x286e848e837adc1c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_single_char_ec4bd67a88d6c383>>();
	};
	// re_match2_char_e7712649ef04ae7d
	aotLib[0x3eb5c27313868bce] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_char_e7712649ef04ae7d>>();
	};
	// re_match2_union_29c921f92bb6c013
	aotLib[0xde56084acadc3864] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_union_29c921f92bb6c013>>();
	};
	// re_match2_set_a7d14982d3d94062
	aotLib[0x8f6a318e3032681e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_set_a7d14982d3d94062>>();
	};
	// re_match2_any_145e1cb203d4af15
	aotLib[0xbcd2d4866dcb8e5] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_any_145e1cb203d4af15>>();
	};
	// re_match2_concat_aa5a3133a76ae77
	aotLib[0x50c749f37e707c4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_concat_aa5a3133a76ae77>>();
	};
	// re_match2_eos_e54e018f6fdc2874
	aotLib[0x2a58ba90b045e0d5] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_eos_e54e018f6fdc2874>>();
	};
	// re_match2_question_c6073fc7d021f681
	aotLib[0x49c91441ca732b71] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_question_c6073fc7d021f681>>();
	};
	// re_match2_plus_6caa18e9465405bd
	aotLib[0xb52341fe1300353a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_plus_6caa18e9465405bd>>();
	};
	// re_match2_plus_set_a77e502c2ce10da5
	aotLib[0xac9979747ea42230] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_plus_set_a77e502c2ce10da5>>();
	};
	// re_match2_star_9bdcb86ac2e0b3b3
	aotLib[0x4bbcc83a252e2aca] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_star_9bdcb86ac2e0b3b3>>();
	};
	// re_match2_group_64e1ead31a846f3e
	aotLib[0xdbbf0b6602f2567f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t * (*) ( Context * __context__, regex::Regex & , regex::ReNode * , uint8_t * const   ),&re_match2_group_64e1ead31a846f3e>>();
	};
	// re_early_out_922d27d5b993b87c
	aotLib[0x3fd28a71044c9cca] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TDim<uint32_t,8> & , regex::ReNode * const   ),&re_early_out_922d27d5b993b87c>>();
	};
	// is_valid_f341200a6f682e5a
	aotLib[0xbda775684ba2dc4c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, regex::Regex &  ),&is_valid_f341200a6f682e5a>>();
	};
	// regex_compile_18db32cc7aeccc78
	aotLib[0x2d0b0a593d162383] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, regex::Regex & , char * const   ),&regex_compile_18db32cc7aeccc78>>();
	};
	// regex_compile_de8b67e813d240c6
	aotLib[0x6af3ae43376928e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<regex::Regex (*) ( Context * __context__, char * const   ),&regex_compile_de8b67e813d240c6>>();
	};
	// regex_compile_6869b0e89f8c00b1
	aotLib[0x126ffc17bd9fcb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<regex::Regex (*) ( Context * __context__, regex::Regex &  ),&regex_compile_6869b0e89f8c00b1>>();
	};
	// regex_match_270cb942810fc6f1
	aotLib[0xbaf2bcf3fba917eb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, regex::Regex & , char * const  , int32_t  ),&regex_match_270cb942810fc6f1>>();
	};
	// regex_group_53f438f6c88fd53d
	aotLib[0xf776ef3f30ae89be] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, regex::Regex const  & , int32_t , char * const   ),&regex_group_53f438f6c88fd53d>>();
	};
	// regex_foreach_31d894777e8f6051
	aotLib[0xd072b90d4266b3af] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex & , char * const  , Block DAS_COMMENT((bool,range)) const  &  ),&regex_foreach_31d894777e8f6051>>();
	};
	// regex_replace_406545def8f63efd
	aotLib[0x57e4c4b43dddd303] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, regex::Regex & , char * const  , Block DAS_COMMENT((char *,char * const )) const  &  ),&regex_replace_406545def8f63efd>>();
	};
	// regex_debug_1a2f3227d12bb74b
	aotLib[0x9192e89bcd4132af] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex const  &  ),&regex_debug_1a2f3227d12bb74b>>();
	};
	// debug_set_5bfd1461cc2bf4d3
	aotLib[0xf7f3c9888ddfe1c3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TDim<uint32_t,8> const  &  ),&debug_set_5bfd1461cc2bf4d3>>();
	};
	// debug_re_8aa07286a87ace73
	aotLib[0x1e4d19a9eebc90a3] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * const  , int32_t  ),&debug_re_8aa07286a87ace73>>();
	};
	// rnd_set_character_f49e90c9ced30293
	aotLib[0xc9cae603ba72143f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, TDim<uint32_t,8> const  & , Sequence DAS_COMMENT((uint32_t)) &  ),&rnd_set_character_f49e90c9ced30293>>();
	};
	// re_gen2_fail_83869989d4feff33
	aotLib[0x24fd37a90815eade] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_fail_83869989d4feff33>>();
	};
	// re_gen2_char_f50387c056fd98bf
	aotLib[0x4522a9279a642171] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_char_f50387c056fd98bf>>();
	};
	// re_gen2_union_9643fdb28fe9f09d
	aotLib[0xfe8cd4e53538594a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_union_9643fdb28fe9f09d>>();
	};
	// re_gen2_set_687ad6fcb132e4de
	aotLib[0x2524c3db7c90fdd4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_set_687ad6fcb132e4de>>();
	};
	// re_gen2_any_998ffcd284a238dd
	aotLib[0x3e3efbf4f9859987] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_any_998ffcd284a238dd>>();
	};
	// re_gen2_concat_2acaded76c0d6fe4
	aotLib[0x4b0c746707875913] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_concat_2acaded76c0d6fe4>>();
	};
	// re_gen2_eos_b4ed344d74735b22
	aotLib[0x8e3ef4f4c1da7527] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_eos_b4ed344d74735b22>>();
	};
	// re_gen2_question_23526c1a36f227c7
	aotLib[0x7ed177f8236bb534] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_question_23526c1a36f227c7>>();
	};
	// re_gen2_plus_76879af5add2064f
	aotLib[0xd19a914c62aa3d64] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_plus_76879af5add2064f>>();
	};
	// re_gen2_star_2b17ac0e3bbfc0b0
	aotLib[0xd785eefdfc661e2b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_star_2b17ac0e3bbfc0b0>>();
	};
	// re_gen2_group_220ee7b205b18ab6
	aotLib[0x9e4bf1524323c537] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * , Sequence DAS_COMMENT((uint32_t)) & , StringBuilderWriter &  ),&re_gen2_group_220ee7b205b18ab6>>();
	};
	// re_gen_782e537f3d526983
	aotLib[0xc26f018f471afa53] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, regex::Regex & , Sequence DAS_COMMENT((uint32_t)) &  ),&re_gen_782e537f3d526983>>();
	};
	// [[ init script ]]
	aotLib[0xcdd4468ae6f1930c] = [&](Context & ctx){
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
