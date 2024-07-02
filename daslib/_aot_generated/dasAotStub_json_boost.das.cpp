#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require json_boost
 // require rtti
#include "daScript/simulate/aot_builtin_rtti.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_handle.h"
 // require strings
#include "daScript/simulate/aot_builtin_string.h"
 // require ast
#include "daScript/ast/ast.h"
#include "daScript/simulate/aot_builtin_ast.h"
 // require math
#include "daScript/simulate/aot_builtin_math.h"
 // require strings_boost
 // require json
 // require ast_boost
 // require contracts
 // require templates
 // require array_boost
 // require algorithm
 // require templates_boost
 // require macro_boost
 // require defer
 // require apply

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
namespace _anon_2895423093344936280 {

extern TypeInfo __type_info__8d8d8008262e16ec;
extern TypeInfo __type_info__b68d800849332aec;

TypeInfo __type_info__8d8d8008262e16ec = { Type::tInt64, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 8, UINT64_C(0x8d8d8008262e16ec) };
TypeInfo __type_info__b68d800849332aec = { Type::tUInt64, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 8, UINT64_C(0xb68d800849332aec) };

static void resolveTypeInfoAnnotations()
{
}

TypeInfo * __tinfo_0[1] = { &__type_info__8d8d8008262e16ec };
TypeInfo * __tinfo_1[1] = { &__type_info__b68d800849332aec };
namespace json_boost { struct BetterJsonMacro; };
namespace json_boost { struct JsonReader; };
namespace ast { struct AstFunctionAnnotation; };
namespace ast { struct AstBlockAnnotation; };
namespace ast { struct AstStructureAnnotation; };
namespace ast { struct AstPassMacro; };
namespace ast { struct AstVariantMacro; };
namespace ast { struct AstForLoopMacro; };
namespace ast { struct AstCaptureMacro; };
namespace ast { struct AstSimulateMacro; };
namespace ast { struct AstReaderMacro; };
namespace ast { struct AstCommentReader; };
namespace ast { struct AstCallMacro; };
namespace ast { struct AstTypeInfoMacro; };
namespace ast { struct AstEnumerationAnnotation; };
namespace ast { struct AstVisitor; };
namespace json { struct JsonValue; };
namespace json { struct TokenAt; };
namespace json { struct _lambda_json_83_8_1; };
namespace ast_boost { struct MacroMacro; };
namespace ast_boost { struct TagFunctionAnnotation; };
namespace ast_boost { struct TagStructureAnnotation; };
namespace ast_boost { struct SetupAnyAnnotation; };
namespace ast_boost { struct SetupFunctionAnnotation; };
namespace ast_boost { struct SetupBlockAnnotation; };
namespace ast_boost { struct SetupStructureAnnotation; };
namespace ast_boost { struct SetupEnumerationAnnotation; };
namespace ast_boost { struct SetupContractAnnotation; };
namespace ast_boost { struct SetupReaderMacro; };
namespace ast_boost { struct SetupCommentReader; };
namespace ast_boost { struct SetupVariantMacro; };
namespace ast_boost { struct SetupForLoopMacro; };
namespace ast_boost { struct SetupCaptureMacro; };
namespace ast_boost { struct SetupSimulateMacro; };
namespace ast_boost { struct SetupCallMacro; };
namespace ast_boost { struct SetupTypeInfoMacro; };
namespace ast_boost { struct SetupInferMacro; };
namespace ast_boost { struct SetupDirtyInferMacro; };
namespace ast_boost { struct SetupLintMacro; };
namespace ast_boost { struct SetupGlobalLintMacro; };
namespace ast_boost { struct SetupOptimizationMacro; };
namespace ast_boost { struct TagFunctionMacro; };
namespace ast_boost { struct BetterRttiVisitor; };
namespace contracts { struct IsAnyType; };
namespace contracts { struct IsAnyArrayMacro; };
namespace contracts { struct IsAnyEnumMacro; };
namespace contracts { struct IsAnyBitfieldMacro; };
namespace contracts { struct IsAnyVectorType; };
namespace contracts { struct IsAnyStructMacro; };
namespace contracts { struct IsAnyNumericMacro; };
namespace contracts { struct IsAnyWorkhorse; };
namespace contracts { struct IsAnyWorkhorseNonPtrMacro; };
namespace contracts { struct IsAnyTupleNonPtrMacro; };
namespace contracts { struct IsAnyVariantNonPtrMacro; };
namespace contracts { struct IsAnyFunctionNonPtrMacro; };
namespace contracts { struct IsAnyLambdaMacro; };
namespace contracts { struct IsRefMacro; };
namespace contracts { struct IsPointer; };
namespace contracts { struct IsClass; };
namespace contracts { struct IsValueHandle; };
namespace templates { struct DecltypeMacro; };
namespace templates { struct DecltypeNoRefMacro; };
namespace templates { struct TemplateMacro; };
namespace templates_boost { struct Template; };
namespace templates_boost { struct TemplateVisitor; };
namespace templates_boost { struct RemoveDerefVisitor; };
namespace templates_boost { struct QRulesVisitor; };
namespace templates_boost { struct AstQCallMacro; };
namespace templates_boost { struct QMacro; };
namespace templates_boost { struct QBlockMacro; };
namespace templates_boost { struct QBlockToArrayMacro; };
namespace templates_boost { struct QBlockExprMacro; };
namespace templates_boost { struct QTypeMacro; };
namespace templates_boost { struct AstQNamedMacro; };
namespace templates_boost { struct AstQFunctionMacro; };
namespace templates_boost { struct AstQVariableMacro; };
namespace templates_boost { struct AstQNamedClassMacro; };
namespace templates_boost { struct AstQMethodMacro; };
namespace macro_boost { struct MacroVerifyMacro; };
namespace macro_boost { struct CaptureBlock; };
namespace macro_boost { struct CapturedVariable; };
namespace macro_boost { struct ColletFinally; };
namespace macro_boost { struct ColletLabels; };
namespace macro_boost { struct ReturnSkipLockcheck; };
namespace defer { struct DeferMacro; };
namespace defer { struct DeferDeleteMacro; };
namespace apply { struct ApplyMacro; };
// unused enumeration CompilationError
// unused enumeration Type
// unused enumeration RefMatters
// unused enumeration ConstMatters
// unused enumeration TemporaryMatters
// unused enumeration ConversionResult
// unused enumeration SideEffects
// unused enumeration CaptureMode
// unused structure AstFunctionAnnotation
// unused structure AstBlockAnnotation
// unused structure AstStructureAnnotation
// unused structure AstPassMacro
namespace ast {

struct AstVariantMacro {
	void * __rtti;
	Func DAS_COMMENT((void,ast::AstVariantMacro)) __finalize;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprIsVariant> const )) visitExprIsVariant;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprAsVariant> const )) visitExprAsVariant;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprSafeAsVariant> const )) visitExprSafeAsVariant;
};
static_assert(sizeof(AstVariantMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(AstVariantMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprIsVariant)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprAsVariant)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprSafeAsVariant)==32,"structure field offset mismatch with DAS");
}
// unused structure AstForLoopMacro
// unused structure AstCaptureMacro
// unused structure AstSimulateMacro
namespace ast {

struct AstReaderMacro {
	void * __rtti;
	Func DAS_COMMENT((void,ast::AstReaderMacro)) __finalize;
	Func DAS_COMMENT((bool,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,int32_t,LineInfo const )) accept;
	Func DAS_COMMENT((char *,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,LineInfo const ,int32_t &,FileInfo * &)) suffix;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprReader> const )) visit;
};
static_assert(sizeof(AstReaderMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(AstReaderMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,accept)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,suffix)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,visit)==32,"structure field offset mismatch with DAS");
}
// unused structure AstCommentReader
// unused structure AstCallMacro
// unused structure AstTypeInfoMacro
// unused structure AstEnumerationAnnotation
// unused structure AstVisitor
namespace json {

struct JsonValue {
	TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> value;
};
static_assert(sizeof(JsonValue)==56,"structure size mismatch with DAS");
static_assert(offsetof(JsonValue,value)==0,"structure field offset mismatch with DAS");
}
// unused structure TokenAt
// unused structure _lambda_json_83_8_1
// unused structure MacroMacro
// unused structure TagFunctionAnnotation
// unused structure TagStructureAnnotation
// unused structure SetupAnyAnnotation
// unused structure SetupFunctionAnnotation
// unused structure SetupBlockAnnotation
// unused structure SetupStructureAnnotation
// unused structure SetupEnumerationAnnotation
// unused structure SetupContractAnnotation
// unused structure SetupReaderMacro
// unused structure SetupCommentReader
// unused structure SetupVariantMacro
// unused structure SetupForLoopMacro
// unused structure SetupCaptureMacro
// unused structure SetupSimulateMacro
// unused structure SetupCallMacro
// unused structure SetupTypeInfoMacro
// unused structure SetupInferMacro
// unused structure SetupDirtyInferMacro
// unused structure SetupLintMacro
// unused structure SetupGlobalLintMacro
// unused structure SetupOptimizationMacro
// unused structure TagFunctionMacro
// unused structure BetterRttiVisitor
// unused structure IsAnyType
// unused structure IsAnyArrayMacro
// unused structure IsAnyEnumMacro
// unused structure IsAnyBitfieldMacro
// unused structure IsAnyVectorType
// unused structure IsAnyStructMacro
// unused structure IsAnyNumericMacro
// unused structure IsAnyWorkhorse
// unused structure IsAnyWorkhorseNonPtrMacro
// unused structure IsAnyTupleNonPtrMacro
// unused structure IsAnyVariantNonPtrMacro
// unused structure IsAnyFunctionNonPtrMacro
// unused structure IsAnyLambdaMacro
// unused structure IsRefMacro
// unused structure IsPointer
// unused structure IsClass
// unused structure IsValueHandle
// unused structure DecltypeMacro
// unused structure DecltypeNoRefMacro
// unused structure TemplateMacro
// unused structure Template
// unused structure TemplateVisitor
// unused structure RemoveDerefVisitor
// unused structure QRulesVisitor
// unused structure AstQCallMacro
// unused structure QMacro
// unused structure QBlockMacro
// unused structure QBlockToArrayMacro
// unused structure QBlockExprMacro
// unused structure QTypeMacro
// unused structure AstQNamedMacro
// unused structure AstQFunctionMacro
// unused structure AstQVariableMacro
// unused structure AstQNamedClassMacro
// unused structure AstQMethodMacro
// unused structure MacroVerifyMacro
// unused structure CaptureBlock
// unused structure CapturedVariable
// unused structure ColletFinally
// unused structure ColletLabels
// unused structure ReturnSkipLockcheck
// unused structure DeferMacro
// unused structure DeferDeleteMacro
// unused structure ApplyMacro
namespace json_boost {

struct BetterJsonMacro {
	void * __rtti;
	Func DAS_COMMENT((void,ast::AstVariantMacro)) __finalize;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprIsVariant> const )) visitExprIsVariant;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprAsVariant> const )) visitExprAsVariant;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprSafeAsVariant> const )) visitExprSafeAsVariant;
};
static_assert(sizeof(BetterJsonMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprIsVariant)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprAsVariant)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprSafeAsVariant)==32,"structure field offset mismatch with DAS");
}
namespace json_boost {

struct JsonReader {
	void * __rtti;
	Func DAS_COMMENT((void,ast::AstReaderMacro)) __finalize;
	Func DAS_COMMENT((bool,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,int32_t,LineInfo const )) accept;
	Func DAS_COMMENT((char *,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,LineInfo const ,int32_t &,FileInfo * &)) suffix;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprReader> const )) visit;
};
static_assert(sizeof(JsonReader)==40,"structure size mismatch with DAS");
static_assert(offsetof(JsonReader,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,accept)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,suffix)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,visit)==32,"structure field offset mismatch with DAS");
}

inline void _FuncbuiltinTickpush_8b4d194b628cfcf4 ( Context * __context__, TArray<ast::AstVariantMacro *> & __Arr_rename_at_79_0, ast::AstVariantMacro * const  __value_rename_at_79_1 );
inline StructInfo const  * _FuncrttiTickclass_info_57f0aa6ae8272f27 ( Context * __context__, json_boost::BetterJsonMacro const  & __cl_rename_at_86_2 );
inline void _FuncbuiltinTickpush_e2306b8546429eb2 ( Context * __context__, TArray<ast::AstReaderMacro *> & __Arr_rename_at_79_3, ast::AstReaderMacro * const  __value_rename_at_79_4 );
inline StructInfo const  * _FuncrttiTickclass_info_4d4384a649e466f4 ( Context * __context__, json_boost::JsonReader const  & __cl_rename_at_86_5 );
inline json::JsonValue * _FuncQmarkSqblSqbr_2059b2acd8f6f271 ( Context * __context__, json::JsonValue * const  __a_rename_at_20_10, char * const  __key_rename_at_20_11 );
inline json::JsonValue * _FuncQmarkSqblSqbr_b8bcd29b3b34cb33 ( Context * __context__, json::JsonValue * __a_rename_at_24_12, char * const  __key_rename_at_24_13 );
inline json::JsonValue * _FuncQmarkDot_2059b2acd8f6f271 ( Context * __context__, json::JsonValue * const  __a_rename_at_28_14, char * const  __key_rename_at_28_15 );
inline json::JsonValue * _FuncQmarkDot_b8bcd29b3b34cb33 ( Context * __context__, json::JsonValue * __a_rename_at_32_16, char * const  __key_rename_at_32_17 );
inline json::JsonValue * _FuncQmarkSqblSqbr_8e788c53589f99f9 ( Context * __context__, json::JsonValue * const  __a_rename_at_36_18, int32_t __idx_rename_at_36_19 );
inline json::JsonValue * _FuncQmarkSqblSqbr_9046f5372eb49abb ( Context * __context__, json::JsonValue * __a_rename_at_40_20, int32_t __idx_rename_at_40_21 );
inline double _FuncQmarkQmark_489e7233c8f69ebb ( Context * __context__, json::JsonValue * const  __a_rename_at_44_22, double __val_rename_at_44_23 );
inline float _FuncQmarkQmark_337713364fb3eeaa ( Context * __context__, json::JsonValue * const  __a_rename_at_48_24, float __val_rename_at_48_25 );
inline int8_t _FuncQmarkQmark_50acfa3ba18126b9 ( Context * __context__, json::JsonValue * const  __a_rename_at_52_26, int8_t __val_rename_at_52_27 );
inline int16_t _FuncQmarkQmark_abee4b0132a46026 ( Context * __context__, json::JsonValue * const  __a_rename_at_56_28, int16_t __val_rename_at_56_29 );
inline int32_t _FuncQmarkQmark_98af60dc67a282e7 ( Context * __context__, json::JsonValue * const  __a_rename_at_60_30, int32_t __val_rename_at_60_31 );
inline int64_t _FuncQmarkQmark_3878b214616eec09 ( Context * __context__, json::JsonValue * const  __a_rename_at_64_32, int64_t __val_rename_at_64_33 );
inline uint8_t _FuncQmarkQmark_4321e6f4895ba8e4 ( Context * __context__, json::JsonValue * const  __a_rename_at_68_34, uint8_t __val_rename_at_68_35 );
inline uint16_t _FuncQmarkQmark_9188e9c8fa66462d ( Context * __context__, json::JsonValue * const  __a_rename_at_72_36, uint16_t __val_rename_at_72_37 );
inline uint32_t _FuncQmarkQmark_7ed3403e12019276 ( Context * __context__, json::JsonValue * const  __a_rename_at_76_38, uint32_t __val_rename_at_76_39 );
inline uint64_t _FuncQmarkQmark_a1a244f1a2a778 ( Context * __context__, json::JsonValue * const  __a_rename_at_80_40, uint64_t __val_rename_at_80_41 );
inline bool _FuncQmarkQmark_2b395cc65763d229 ( Context * __context__, json::JsonValue * const  __a_rename_at_84_42, bool __val_rename_at_84_43 );
inline char * _FuncQmarkQmark_5ae5441b01295b59 ( Context * __context__, json::JsonValue * const  __a_rename_at_88_44, char * const  __val_rename_at_88_45 );
inline json::JsonValue * JV_29c2b5b33818b86c ( Context * __context__, float __v_rename_at_371_46 );
inline json::JsonValue * JV_6622951aed6ee0ee ( Context * __context__, int32_t __v_rename_at_374_47 );
inline json::JsonValue * JV_49f2b952a360e00c ( Context * __context__, Bitfield __v_rename_at_377_48 );
inline json::JsonValue * JV_34967019502a64e7 ( Context * __context__, int8_t __val_rename_at_380_49 );
inline json::JsonValue * JV_39223a40f88cc681 ( Context * __context__, uint8_t __val_rename_at_383_50 );
inline json::JsonValue * JV_3942d24d3c8451ca ( Context * __context__, int16_t __val_rename_at_386_51 );
inline json::JsonValue * JV_164b1e3e11380406 ( Context * __context__, uint16_t __val_rename_at_389_52 );
inline json::JsonValue * JV_ff440a0f393eb30c ( Context * __context__, uint32_t __val_rename_at_392_53 );
inline json::JsonValue * JV_b9c05218ac74084f ( Context * __context__, int64_t __val_rename_at_395_54 );
inline json::JsonValue * JV_b7e4c8ca4f0d7bfa ( Context * __context__, uint64_t __val_rename_at_401_55 );

void __init_script ( Context * __context__, bool __init_shared )
{
}

inline void _FuncbuiltinTickpush_8b4d194b628cfcf4 ( Context * __context__, TArray<ast::AstVariantMacro *> &  __Arr_rename_at_79_0, ast::AstVariantMacro * const  __value_rename_at_79_1 )
{
	das_copy(__Arr_rename_at_79_0(builtin_array_push_back(das_arg<TArray<ast::AstVariantMacro *>>::pass(__Arr_rename_at_79_0),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_1);
}

inline StructInfo const  * _FuncrttiTickclass_info_57f0aa6ae8272f27 ( Context * __context__, json_boost::BetterJsonMacro const  &  __cl_rename_at_86_2 )
{
	return das_auto_cast<StructInfo const  *>::cast(das_cast<StructInfo const  *>::cast(((das_deref(__context__,das_cast<TypeInfo const  *>::cast(__cl_rename_at_86_2.__rtti))).getStructType())));
}

inline void _FuncbuiltinTickpush_e2306b8546429eb2 ( Context * __context__, TArray<ast::AstReaderMacro *> &  __Arr_rename_at_79_3, ast::AstReaderMacro * const  __value_rename_at_79_4 )
{
	das_copy(__Arr_rename_at_79_3(builtin_array_push_back(das_arg<TArray<ast::AstReaderMacro *>>::pass(__Arr_rename_at_79_3),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_4);
}

inline StructInfo const  * _FuncrttiTickclass_info_4d4384a649e466f4 ( Context * __context__, json_boost::JsonReader const  &  __cl_rename_at_86_5 )
{
	return das_auto_cast<StructInfo const  *>::cast(das_cast<StructInfo const  *>::cast(((das_deref(__context__,das_cast<TypeInfo const  *>::cast(__cl_rename_at_86_5.__rtti))).getStructType())));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_2059b2acd8f6f271 ( Context * __context__, json::JsonValue * const  __a_rename_at_20_10, char * const  __key_rename_at_20_11 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_20_10 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_20_10->value)) ? das_auto_cast<json::JsonValue * const >::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_20_10->value,__context__)),__key_rename_at_20_11,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue * const >::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_b8bcd29b3b34cb33 ( Context * __context__, json::JsonValue * __a_rename_at_24_12, char * const  __key_rename_at_24_13 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_24_12 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_24_12->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_24_12->value,__context__)),__key_rename_at_24_13,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline json::JsonValue * _FuncQmarkDot_2059b2acd8f6f271 ( Context * __context__, json::JsonValue * const  __a_rename_at_28_14, char * const  __key_rename_at_28_15 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_28_14 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_28_14->value)) ? das_auto_cast<json::JsonValue * const >::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_28_14->value,__context__)),__key_rename_at_28_15,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue * const >::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline json::JsonValue * _FuncQmarkDot_b8bcd29b3b34cb33 ( Context * __context__, json::JsonValue * __a_rename_at_32_16, char * const  __key_rename_at_32_17 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_32_16 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_32_16->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_32_16->value,__context__)),__key_rename_at_32_17,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_8e788c53589f99f9 ( Context * __context__, json::JsonValue * const  __a_rename_at_36_18, int32_t __idx_rename_at_36_19 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_36_18 != nullptr) && das_get_variant_field<TArray<json::JsonValue *>,8,1>::is(__a_rename_at_36_18->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TArray<json::JsonValue *>::safe_index(&(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__a_rename_at_36_18->value,__context__)),__idx_rename_at_36_19,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_9046f5372eb49abb ( Context * __context__, json::JsonValue * __a_rename_at_40_20, int32_t __idx_rename_at_40_21 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_40_20 != nullptr) && das_get_variant_field<TArray<json::JsonValue *>,8,1>::is(__a_rename_at_40_20->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TArray<json::JsonValue *>::safe_index(&(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__a_rename_at_40_20->value,__context__)),__idx_rename_at_40_21,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 17375517337867118711u)))));
}

inline double _FuncQmarkQmark_489e7233c8f69ebb ( Context * __context__, json::JsonValue * const  __a_rename_at_44_22, double __val_rename_at_44_23 )
{
	return das_auto_cast<double>::cast(((__a_rename_at_44_22 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_44_22->value)) ? das_auto_cast<double>::cast(das_get_variant_field<double,8,3>::as(__a_rename_at_44_22->value,__context__)) : das_auto_cast<double>::cast(__val_rename_at_44_23));
}

inline float _FuncQmarkQmark_337713364fb3eeaa ( Context * __context__, json::JsonValue * const  __a_rename_at_48_24, float __val_rename_at_48_25 )
{
	return das_auto_cast<float>::cast(((__a_rename_at_48_24 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_48_24->value)) ? das_auto_cast<float>::cast(float(das_get_variant_field<double,8,3>::as(__a_rename_at_48_24->value,__context__))) : das_auto_cast<float>::cast(__val_rename_at_48_25));
}

inline int8_t _FuncQmarkQmark_50acfa3ba18126b9 ( Context * __context__, json::JsonValue * const  __a_rename_at_52_26, int8_t __val_rename_at_52_27 )
{
	return das_auto_cast<int8_t>::cast(((__a_rename_at_52_26 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_52_26->value)) ? das_auto_cast<int8_t>::cast(int8_t(das_get_variant_field<double,8,3>::as(__a_rename_at_52_26->value,__context__))) : das_auto_cast<int8_t>::cast(__val_rename_at_52_27));
}

inline int16_t _FuncQmarkQmark_abee4b0132a46026 ( Context * __context__, json::JsonValue * const  __a_rename_at_56_28, int16_t __val_rename_at_56_29 )
{
	return das_auto_cast<int16_t>::cast(((__a_rename_at_56_28 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_56_28->value)) ? das_auto_cast<int16_t>::cast(int16_t(das_get_variant_field<double,8,3>::as(__a_rename_at_56_28->value,__context__))) : das_auto_cast<int16_t>::cast(__val_rename_at_56_29));
}

inline int32_t _FuncQmarkQmark_98af60dc67a282e7 ( Context * __context__, json::JsonValue * const  __a_rename_at_60_30, int32_t __val_rename_at_60_31 )
{
	return das_auto_cast<int32_t>::cast(((__a_rename_at_60_30 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_60_30->value)) ? das_auto_cast<int32_t>::cast(int32_t(das_get_variant_field<double,8,3>::as(__a_rename_at_60_30->value,__context__))) : das_auto_cast<int32_t>::cast(__val_rename_at_60_31));
}

inline int64_t _FuncQmarkQmark_3878b214616eec09 ( Context * __context__, json::JsonValue * const  __a_rename_at_64_32, int64_t __val_rename_at_64_33 )
{
	return das_auto_cast<int64_t>::cast(((__a_rename_at_64_32 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_64_32->value)) ? das_auto_cast<int64_t>::cast(int64_t(das_get_variant_field<double,8,3>::as(__a_rename_at_64_32->value,__context__))) : das_auto_cast<int64_t>::cast(__val_rename_at_64_33));
}

inline uint8_t _FuncQmarkQmark_4321e6f4895ba8e4 ( Context * __context__, json::JsonValue * const  __a_rename_at_68_34, uint8_t __val_rename_at_68_35 )
{
	return das_auto_cast<uint8_t>::cast(((__a_rename_at_68_34 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_68_34->value)) ? das_auto_cast<uint8_t>::cast(uint8_t(das_get_variant_field<double,8,3>::as(__a_rename_at_68_34->value,__context__))) : das_auto_cast<uint8_t>::cast(__val_rename_at_68_35));
}

inline uint16_t _FuncQmarkQmark_9188e9c8fa66462d ( Context * __context__, json::JsonValue * const  __a_rename_at_72_36, uint16_t __val_rename_at_72_37 )
{
	return das_auto_cast<uint16_t>::cast(((__a_rename_at_72_36 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_72_36->value)) ? das_auto_cast<uint16_t>::cast(uint16_t(das_get_variant_field<double,8,3>::as(__a_rename_at_72_36->value,__context__))) : das_auto_cast<uint16_t>::cast(__val_rename_at_72_37));
}

inline uint32_t _FuncQmarkQmark_7ed3403e12019276 ( Context * __context__, json::JsonValue * const  __a_rename_at_76_38, uint32_t __val_rename_at_76_39 )
{
	return das_auto_cast<uint32_t>::cast(((__a_rename_at_76_38 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_76_38->value)) ? das_auto_cast<uint32_t>::cast(uint32_t(das_get_variant_field<double,8,3>::as(__a_rename_at_76_38->value,__context__))) : das_auto_cast<uint32_t>::cast(__val_rename_at_76_39));
}

inline uint64_t _FuncQmarkQmark_a1a244f1a2a778 ( Context * __context__, json::JsonValue * const  __a_rename_at_80_40, uint64_t __val_rename_at_80_41 )
{
	return das_auto_cast<uint64_t>::cast(((__a_rename_at_80_40 != nullptr) && das_get_variant_field<double,8,3>::is(__a_rename_at_80_40->value)) ? das_auto_cast<uint64_t>::cast(uint64_t(das_get_variant_field<double,8,3>::as(__a_rename_at_80_40->value,__context__))) : das_auto_cast<uint64_t>::cast(__val_rename_at_80_41));
}

inline bool _FuncQmarkQmark_2b395cc65763d229 ( Context * __context__, json::JsonValue * const  __a_rename_at_84_42, bool __val_rename_at_84_43 )
{
	return das_auto_cast<bool>::cast(((__a_rename_at_84_42 != nullptr) && das_get_variant_field<bool,8,4>::is(__a_rename_at_84_42->value)) ? das_auto_cast<bool>::cast(das_get_variant_field<bool,8,4>::as(__a_rename_at_84_42->value,__context__)) : das_auto_cast<bool>::cast(__val_rename_at_84_43));
}

inline char * _FuncQmarkQmark_5ae5441b01295b59 ( Context * __context__, json::JsonValue * const  __a_rename_at_88_44, char * const  __val_rename_at_88_45 )
{
	return das_auto_cast<char *>::cast(((__a_rename_at_88_44 != nullptr) && das_get_variant_field<char *,8,2>::is(__a_rename_at_88_44->value)) ? das_auto_cast<char * const >::cast(das_get_variant_field<char *,8,2>::as(__a_rename_at_88_44->value,__context__)) : das_auto_cast<char * const >::cast(__val_rename_at_88_45));
}

inline json::JsonValue * JV_29c2b5b33818b86c ( Context * __context__, float __v_rename_at_371_46 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_372;
		das_zero(__mks_372);
		das_move((__mks_372.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_372;
			das_get_variant_field<double,8,3>::set(__mkv_372) = double(__v_rename_at_371_46);
			return __mkv_372;
		})())));
		return __mks_372;
	})())));
}

inline json::JsonValue * JV_6622951aed6ee0ee ( Context * __context__, int32_t __v_rename_at_374_47 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_375;
		das_zero(__mks_375);
		das_move((__mks_375.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_375;
			das_get_variant_field<double,8,3>::set(__mkv_375) = double(__v_rename_at_374_47);
			return __mkv_375;
		})())));
		return __mks_375;
	})())));
}

inline json::JsonValue * JV_49f2b952a360e00c ( Context * __context__, Bitfield __v_rename_at_377_48 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_378;
		das_zero(__mks_378);
		das_move((__mks_378.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_378;
			das_get_variant_field<double,8,3>::set(__mkv_378) = double(__v_rename_at_377_48);
			return __mkv_378;
		})())));
		return __mks_378;
	})())));
}

inline json::JsonValue * JV_34967019502a64e7 ( Context * __context__, int8_t __val_rename_at_380_49 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_381;
		das_zero(__mks_381);
		das_move((__mks_381.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_381;
			das_get_variant_field<double,8,3>::set(__mkv_381) = double(__val_rename_at_380_49);
			return __mkv_381;
		})())));
		return __mks_381;
	})())));
}

inline json::JsonValue * JV_39223a40f88cc681 ( Context * __context__, uint8_t __val_rename_at_383_50 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_384;
		das_zero(__mks_384);
		das_move((__mks_384.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_384;
			das_get_variant_field<double,8,3>::set(__mkv_384) = double(__val_rename_at_383_50);
			return __mkv_384;
		})())));
		return __mks_384;
	})())));
}

inline json::JsonValue * JV_3942d24d3c8451ca ( Context * __context__, int16_t __val_rename_at_386_51 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_387;
		das_zero(__mks_387);
		das_move((__mks_387.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_387;
			das_get_variant_field<double,8,3>::set(__mkv_387) = double(__val_rename_at_386_51);
			return __mkv_387;
		})())));
		return __mks_387;
	})())));
}

inline json::JsonValue * JV_164b1e3e11380406 ( Context * __context__, uint16_t __val_rename_at_389_52 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_390;
		das_zero(__mks_390);
		das_move((__mks_390.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_390;
			das_get_variant_field<double,8,3>::set(__mkv_390) = double(__val_rename_at_389_52);
			return __mkv_390;
		})())));
		return __mks_390;
	})())));
}

inline json::JsonValue * JV_ff440a0f393eb30c ( Context * __context__, uint32_t __val_rename_at_392_53 )
{
	return das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_393;
		das_zero(__mks_393);
		das_move((__mks_393.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_393;
			das_get_variant_field<double,8,3>::set(__mkv_393) = double(__val_rename_at_392_53);
			return __mkv_393;
		})())));
		return __mks_393;
	})())));
}

inline json::JsonValue * JV_b9c05218ac74084f ( Context * __context__, int64_t __val_rename_at_395_54 )
{
	return das_auto_cast<json::JsonValue *>::cast(((__val_rename_at_395_54 < INT64_C(-2147483648)) || (__val_rename_at_395_54 > INT64_C(2147483647))) ? das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_397;
		das_zero(__mks_397);
		das_move((__mks_397.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_397;
			das_get_variant_field<char *,8,2>::set(__mkv_397) = das_string_builder(__context__,SimNode_AotInterop<1>(__tinfo_0, cast<int64_t>::from(__val_rename_at_395_54)));
			return __mkv_397;
		})())));
		return __mks_397;
	})()))) : das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_399;
		das_zero(__mks_399);
		das_move((__mks_399.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_399;
			das_get_variant_field<double,8,3>::set(__mkv_399) = double(__val_rename_at_395_54);
			return __mkv_399;
		})())));
		return __mks_399;
	})()))));
}

inline json::JsonValue * JV_b7e4c8ca4f0d7bfa ( Context * __context__, uint64_t __val_rename_at_401_55 )
{
	return das_auto_cast<json::JsonValue *>::cast((__val_rename_at_401_55 > UINT64_C(0xffffffff)) ? das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_403;
		das_zero(__mks_403);
		das_move((__mks_403.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_403;
			das_get_variant_field<char *,8,2>::set(__mkv_403) = das_string_builder(__context__,SimNode_AotInterop<1>(__tinfo_1, cast<uint64_t>::from(__val_rename_at_401_55)));
			return __mkv_403;
		})())));
		return __mks_403;
	})()))) : das_auto_cast<json::JsonValue *>::cast(das_ascend<json::JsonValue,json::JsonValue>::make(__context__,nullptr,(([&]() -> json::JsonValue {
		json::JsonValue __mks_405;
		das_zero(__mks_405);
		das_move((__mks_405.value),((([&]() -> TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> {
			TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,bool,void *> __mkv_405;
			das_get_variant_field<double,8,3>::set(__mkv_405) = double(__val_rename_at_401_55);
			return __mkv_405;
		})())));
		return __mks_405;
	})()))));
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncbuiltinTickpush_8b4d194b628cfcf4
	aotLib[0x49a33d1368af70b5] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<ast::AstVariantMacro *> & , ast::AstVariantMacro * const   ),&_FuncbuiltinTickpush_8b4d194b628cfcf4>>();
	};
	// _FuncrttiTickclass_info_57f0aa6ae8272f27
	aotLib[0x6057fcf5a8396143] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<StructInfo const  * (*) ( Context * __context__, json_boost::BetterJsonMacro const  &  ),&_FuncrttiTickclass_info_57f0aa6ae8272f27>>();
	};
	// _FuncbuiltinTickpush_e2306b8546429eb2
	aotLib[0xcffef67e590ffc2b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<ast::AstReaderMacro *> & , ast::AstReaderMacro * const   ),&_FuncbuiltinTickpush_e2306b8546429eb2>>();
	};
	// _FuncrttiTickclass_info_4d4384a649e466f4
	aotLib[0x3085cd13430a2ab1] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<StructInfo const  * (*) ( Context * __context__, json_boost::JsonReader const  &  ),&_FuncrttiTickclass_info_4d4384a649e466f4>>();
	};
	// _FuncQmarkSqblSqbr_2059b2acd8f6f271
	aotLib[0x2ffad4bbeda7a584] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * const  , char * const   ),&_FuncQmarkSqblSqbr_2059b2acd8f6f271>>();
	};
	// _FuncQmarkSqblSqbr_b8bcd29b3b34cb33
	aotLib[0xe1396fc21d41236b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * , char * const   ),&_FuncQmarkSqblSqbr_b8bcd29b3b34cb33>>();
	};
	// _FuncQmarkDot_2059b2acd8f6f271
	aotLib[0x2ffad4bbeda7a584] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * const  , char * const   ),&_FuncQmarkDot_2059b2acd8f6f271>>();
	};
	// _FuncQmarkDot_b8bcd29b3b34cb33
	aotLib[0xe1396fc21d41236b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * , char * const   ),&_FuncQmarkDot_b8bcd29b3b34cb33>>();
	};
	// _FuncQmarkSqblSqbr_8e788c53589f99f9
	aotLib[0xdafd2bd3e0a3d550] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * const  , int32_t  ),&_FuncQmarkSqblSqbr_8e788c53589f99f9>>();
	};
	// _FuncQmarkSqblSqbr_9046f5372eb49abb
	aotLib[0xa0b34fea346a3cb7] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, json::JsonValue * , int32_t  ),&_FuncQmarkSqblSqbr_9046f5372eb49abb>>();
	};
	// _FuncQmarkQmark_489e7233c8f69ebb
	aotLib[0xc6f784ccd9695c7] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<double (*) ( Context * __context__, json::JsonValue * const  , double  ),&_FuncQmarkQmark_489e7233c8f69ebb>>();
	};
	// _FuncQmarkQmark_337713364fb3eeaa
	aotLib[0x44927f6fddc0ad8b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float (*) ( Context * __context__, json::JsonValue * const  , float  ),&_FuncQmarkQmark_337713364fb3eeaa>>();
	};
	// _FuncQmarkQmark_50acfa3ba18126b9
	aotLib[0x6776f66862a6788] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int8_t (*) ( Context * __context__, json::JsonValue * const  , int8_t  ),&_FuncQmarkQmark_50acfa3ba18126b9>>();
	};
	// _FuncQmarkQmark_abee4b0132a46026
	aotLib[0x337cc9f17abd0e16] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int16_t (*) ( Context * __context__, json::JsonValue * const  , int16_t  ),&_FuncQmarkQmark_abee4b0132a46026>>();
	};
	// _FuncQmarkQmark_98af60dc67a282e7
	aotLib[0x8de1c0b1bf158c66] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, json::JsonValue * const  , int32_t  ),&_FuncQmarkQmark_98af60dc67a282e7>>();
	};
	// _FuncQmarkQmark_3878b214616eec09
	aotLib[0x9438a8ad132a4a90] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int64_t (*) ( Context * __context__, json::JsonValue * const  , int64_t  ),&_FuncQmarkQmark_3878b214616eec09>>();
	};
	// _FuncQmarkQmark_4321e6f4895ba8e4
	aotLib[0xe2081a8071b1e3ae] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint8_t (*) ( Context * __context__, json::JsonValue * const  , uint8_t  ),&_FuncQmarkQmark_4321e6f4895ba8e4>>();
	};
	// _FuncQmarkQmark_9188e9c8fa66462d
	aotLib[0xf147f836abb1882c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint16_t (*) ( Context * __context__, json::JsonValue * const  , uint16_t  ),&_FuncQmarkQmark_9188e9c8fa66462d>>();
	};
	// _FuncQmarkQmark_7ed3403e12019276
	aotLib[0xfff558042accd5ab] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__, json::JsonValue * const  , uint32_t  ),&_FuncQmarkQmark_7ed3403e12019276>>();
	};
	// _FuncQmarkQmark_a1a244f1a2a778
	aotLib[0xf93efa41e19b8aa8] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint64_t (*) ( Context * __context__, json::JsonValue * const  , uint64_t  ),&_FuncQmarkQmark_a1a244f1a2a778>>();
	};
	// _FuncQmarkQmark_2b395cc65763d229
	aotLib[0x86e1ec1e9aeaf6ea] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, json::JsonValue * const  , bool  ),&_FuncQmarkQmark_2b395cc65763d229>>();
	};
	// _FuncQmarkQmark_5ae5441b01295b59
	aotLib[0x6bffe097c740b7c] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, json::JsonValue * const  , char * const   ),&_FuncQmarkQmark_5ae5441b01295b59>>();
	};
	// JV_29c2b5b33818b86c
	aotLib[0x5c3d47f33fa17d57] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, float  ),&JV_29c2b5b33818b86c>>();
	};
	// JV_6622951aed6ee0ee
	aotLib[0xffdcf069fdbac270] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, int32_t  ),&JV_6622951aed6ee0ee>>();
	};
	// JV_49f2b952a360e00c
	aotLib[0x5655e562ca717e77] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, Bitfield  ),&JV_49f2b952a360e00c>>();
	};
	// JV_34967019502a64e7
	aotLib[0xaab85fcb1013e497] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, int8_t  ),&JV_34967019502a64e7>>();
	};
	// JV_39223a40f88cc681
	aotLib[0x7f1b12c54fedeef0] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, uint8_t  ),&JV_39223a40f88cc681>>();
	};
	// JV_3942d24d3c8451ca
	aotLib[0x663c3ced494d153d] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, int16_t  ),&JV_3942d24d3c8451ca>>();
	};
	// JV_164b1e3e11380406
	aotLib[0x906eb3204ff07cf5] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, uint16_t  ),&JV_164b1e3e11380406>>();
	};
	// JV_ff440a0f393eb30c
	aotLib[0xd14d27adf11dc164] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, uint32_t  ),&JV_ff440a0f393eb30c>>();
	};
	// JV_b9c05218ac74084f
	aotLib[0x5965c9af9ab1ddca] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, int64_t  ),&JV_b9c05218ac74084f>>();
	};
	// JV_b7e4c8ca4f0d7bfa
	aotLib[0xc277e392e1c25d2] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<json::JsonValue * (*) ( Context * __context__, uint64_t  ),&JV_b7e4c8ca4f0d7bfa>>();
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
