#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require regex_boost
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
 // require ast_boost
 // require regex

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
namespace _anon_9918864458530016907 {



static void resolveTypeInfoAnnotations()
{
}

namespace regex_boost { struct RegexReader; };
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
namespace regex { struct ReNode; };
namespace regex { struct Regex; };
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
// unused structure AstVariantMacro
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
template <> struct cast< das::_anon_9918864458530016907::regex::ReOp > : cast_enum < das::_anon_9918864458530016907::regex::ReOp > {};
namespace _anon_9918864458530016907 {
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
namespace regex_boost {

struct RegexReader {
	void * __rtti;
	Func DAS_COMMENT((void,ast::AstReaderMacro)) __finalize;
	Func DAS_COMMENT((bool,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,int32_t,LineInfo const )) accept;
	Func DAS_COMMENT((char *,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,LineInfo const ,int32_t &,FileInfo * &)) suffix;
	Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprReader> const )) visit;
};
static_assert(sizeof(RegexReader)==40,"structure size mismatch with DAS");
static_assert(offsetof(RegexReader,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(RegexReader,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(RegexReader,accept)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(RegexReader,suffix)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(RegexReader,visit)==32,"structure field offset mismatch with DAS");
}

inline void finalize_1db505b7ad774ab5 ( Context * __context__, TTuple<16,range,char *> & ____this_rename_at_548_0 );
inline void _FuncbuiltinTickfinalize_29ef72815d419f2f ( Context * __context__, TArray<regex::ReNode *> & __a_rename_at_544_1 );
inline void _FuncbuiltinTickpush_e2306b8546429eb2 ( Context * __context__, TArray<ast::AstReaderMacro *> & __Arr_rename_at_79_3, ast::AstReaderMacro * const  __value_rename_at_79_4 );
inline StructInfo const  * _FuncrttiTickclass_info_11f8c4c5622ed2c2 ( Context * __context__, regex_boost::RegexReader const  & __cl_rename_at_86_5 );
inline void finalize_94070b9feef91215 ( Context * __context__, regex::ReNode & ____this_rename_at_27_6 );
inline void _FuncbuiltinTickfinalize_a64784dbfb3c7aac ( Context * __context__, TArray<TTuple<16,range,char *>> & __a_rename_at_544_7 );
inline void finalize_ed3070803543f020 ( Context * __context__, regex::ReNode * & ____this_rename_at_47_9 );
inline void finalize_5f502c9cbec3c371 ( Context * __context__, regex::Regex & ____this_rename_at_45_10 );

void __init_script ( Context * __context__, bool __init_shared )
{
}

inline void finalize_1db505b7ad774ab5 ( Context * __context__, TTuple<16,range,char *> &  ____this_rename_at_548_0 )
{
	memset(&(____this_rename_at_548_0), 0, 16);
}

inline void _FuncbuiltinTickfinalize_29ef72815d419f2f ( Context * __context__, TArray<regex::ReNode *> &  __a_rename_at_544_1 )
{
	{
		bool __need_loop_546 = true;
		// aV : regex::ReNode? aka TT&
		das_iterator<TArray<regex::ReNode *>> __aV_iterator(__a_rename_at_544_1);
		regex::ReNode * * __aV_rename_at_546_2;
		__need_loop_546 = __aV_iterator.first(__context__,(__aV_rename_at_546_2)) && __need_loop_546;
		for ( ; __need_loop_546 ; __need_loop_546 = __aV_iterator.next(__context__,(__aV_rename_at_546_2)) )
		{
			finalize_ed3070803543f020(__context__,(*__aV_rename_at_546_2));
		}
		__aV_iterator.close(__context__,(__aV_rename_at_546_2));
	};
	builtin_array_free(das_arg<TArray<regex::ReNode *>>::pass(__a_rename_at_544_1),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickpush_e2306b8546429eb2 ( Context * __context__, TArray<ast::AstReaderMacro *> &  __Arr_rename_at_79_3, ast::AstReaderMacro * const  __value_rename_at_79_4 )
{
	das_copy(__Arr_rename_at_79_3(builtin_array_push_back(das_arg<TArray<ast::AstReaderMacro *>>::pass(__Arr_rename_at_79_3),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_79_4);
}

inline StructInfo const  * _FuncrttiTickclass_info_11f8c4c5622ed2c2 ( Context * __context__, regex_boost::RegexReader const  &  __cl_rename_at_86_5 )
{
	return das_auto_cast<StructInfo const  *>::cast(das_cast<StructInfo const  *>::cast(((das_deref(__context__,das_cast<TypeInfo const  *>::cast(__cl_rename_at_86_5.__rtti))).getStructType())));
}

inline void finalize_94070b9feef91215 ( Context * __context__, regex::ReNode &  ____this_rename_at_27_6 )
{
	_FuncbuiltinTickfinalize_29ef72815d419f2f(__context__,das_arg<TArray<regex::ReNode *>>::pass(____this_rename_at_27_6.all));
	finalize_ed3070803543f020(__context__,____this_rename_at_27_6.left);
	finalize_ed3070803543f020(__context__,____this_rename_at_27_6.right);
	finalize_ed3070803543f020(__context__,____this_rename_at_27_6.subexpr);
	memset(&(____this_rename_at_27_6), 0, 152);
}

inline void _FuncbuiltinTickfinalize_a64784dbfb3c7aac ( Context * __context__, TArray<TTuple<16,range,char *>> &  __a_rename_at_544_7 )
{
	{
		bool __need_loop_546 = true;
		// aV : tuple<range;string> aka TT&
		das_iterator<TArray<TTuple<16,range,char *>>> __aV_iterator(__a_rename_at_544_7);
		TTuple<16,range,char *> * __aV_rename_at_546_8;
		__need_loop_546 = __aV_iterator.first(__context__,(__aV_rename_at_546_8)) && __need_loop_546;
		for ( ; __need_loop_546 ; __need_loop_546 = __aV_iterator.next(__context__,(__aV_rename_at_546_8)) )
		{
			finalize_1db505b7ad774ab5(__context__,das_arg<TTuple<16,range,char *>>::pass((*__aV_rename_at_546_8)));
		}
		__aV_iterator.close(__context__,(__aV_rename_at_546_8));
	};
	builtin_array_free(das_arg<TArray<TTuple<16,range,char *>>>::pass(__a_rename_at_544_7),16,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void finalize_ed3070803543f020 ( Context * __context__, regex::ReNode * & ____this_rename_at_47_9 )
{
	if ( ____this_rename_at_47_9 != nullptr )
	{
		finalize_94070b9feef91215(__context__,das_arg<regex::ReNode>::pass(das_deref(__context__,____this_rename_at_47_9)));
		das_delete<regex::ReNode *>::clear(__context__,____this_rename_at_47_9);
		das_copy(____this_rename_at_47_9,nullptr);
	};
}

inline void finalize_5f502c9cbec3c371 ( Context * __context__, regex::Regex &  ____this_rename_at_45_10 )
{
	finalize_ed3070803543f020(__context__,____this_rename_at_45_10.root);
	_FuncbuiltinTickfinalize_a64784dbfb3c7aac(__context__,das_arg<TArray<TTuple<16,range,char *>>>::pass(____this_rename_at_45_10.groups));
	memset(&(____this_rename_at_45_10), 0, 80);
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// finalize_1db505b7ad774ab5
	aotLib[0xe2538c8019992d24] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TTuple<16,range,char *> &  ),&finalize_1db505b7ad774ab5>>();
	};
	// _FuncbuiltinTickfinalize_29ef72815d419f2f
	aotLib[0xdeb5b415e862c44a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<regex::ReNode *> &  ),&_FuncbuiltinTickfinalize_29ef72815d419f2f>>();
	};
	// _FuncbuiltinTickpush_e2306b8546429eb2
	aotLib[0xcffef67e590ffc2b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<ast::AstReaderMacro *> & , ast::AstReaderMacro * const   ),&_FuncbuiltinTickpush_e2306b8546429eb2>>();
	};
	// _FuncrttiTickclass_info_11f8c4c5622ed2c2
	aotLib[0x2cea4e805bdcb452] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<StructInfo const  * (*) ( Context * __context__, regex_boost::RegexReader const  &  ),&_FuncrttiTickclass_info_11f8c4c5622ed2c2>>();
	};
	// finalize_94070b9feef91215
	aotLib[0xfd0cd4a305a7fd64] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode &  ),&finalize_94070b9feef91215>>();
	};
	// _FuncbuiltinTickfinalize_a64784dbfb3c7aac
	aotLib[0xd97aaad5e7ee4210] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<TTuple<16,range,char *>> &  ),&_FuncbuiltinTickfinalize_a64784dbfb3c7aac>>();
	};
	// finalize_ed3070803543f020
	aotLib[0xd4223c6a10c2e34] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::ReNode * &  ),&finalize_ed3070803543f020>>();
	};
	// finalize_5f502c9cbec3c371
	aotLib[0x21e25c9ddde5fb00] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, regex::Regex &  ),&finalize_5f502c9cbec3c371>>();
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
