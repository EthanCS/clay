#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require random
 // require math
#include "daScript/simulate/aot_builtin_math.h"

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
namespace _anon_8574275246747535210 {

extern StructInfo __struct_info__1fb60dfa6730c2c4;
extern TypeInfo __type_info__af969b4c86582719;
extern TypeInfo __type_info__af63eb4c86020609;
extern TypeInfo __type_info__3da0182fc87a33b6;
extern TypeInfo __type_info__af81fe4c86352052;
extern TypeInfo __type_info__2a2886d56ce30259;
extern VarInfo __var_info__39ce2976c4975d79;
extern VarInfo __var_info__afd24bfcb80d06ee;
extern VarInfo __var_info__2e2afaf79f40082;
extern VarInfo __var_info__3f4c2bb398f9b3db;
extern VarInfo __var_info__b3ab9c85ca68ac95;

TypeInfo * __type_info__b3ab9c85ca68ac95_arg_types_var_2285029230061339332[2] = { &__type_info__2a2886d56ce30259, &__type_info__af969b4c86582719 };
const char * __type_info__b3ab9c85ca68ac95_arg_names_var_2285029230061339332[2] = { "__this", "_yield_96" };
VarInfo __struct_info__1fb60dfa6730c2c4_field_0 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__af81fe4c86352052, nullptr, (TypeInfo **)__type_info__b3ab9c85ca68ac95_arg_types_var_2285029230061339332, __type_info__b3ab9c85ca68ac95_arg_names_var_2285029230061339332, 2, 0, nullptr, 12, 8, UINT64_C(0xb3ab9c85ca68ac95), "__lambda", 0, 0 };
TypeInfo * __type_info__afd24bfcb80d06ee_arg_types_var_2285029230061339332[1] = { &__type_info__3da0182fc87a33b6 };
const char * __type_info__afd24bfcb80d06ee_arg_names_var_2285029230061339332[1] = { "__this" };
VarInfo __struct_info__1fb60dfa6730c2c4_field_1 =  { Type::tFunction, nullptr, nullptr, nullptr, &__type_info__af63eb4c86020609, nullptr, (TypeInfo **)__type_info__afd24bfcb80d06ee_arg_types_var_2285029230061339332, __type_info__afd24bfcb80d06ee_arg_names_var_2285029230061339332, 1, 0, nullptr, 12, 8, UINT64_C(0xafd24bfcb80d06ee), "__finalize", 8, 0 };
VarInfo __struct_info__1fb60dfa6730c2c4_field_2 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x2e2afaf79f40082), "__yield", 16, 0 };
VarInfo __struct_info__1fb60dfa6730c2c4_field_3 =  { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0x39ce2976c4975d79), "rnd_seed", 20, 0 };
VarInfo __struct_info__1fb60dfa6730c2c4_field_4 =  { Type::tInt4, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 16, UINT64_C(0x3f4c2bb398f9b3db), "seed", 24, 0 };
VarInfo * __struct_info__1fb60dfa6730c2c4_fields[5] =  { &__struct_info__1fb60dfa6730c2c4_field_0, &__struct_info__1fb60dfa6730c2c4_field_1, &__struct_info__1fb60dfa6730c2c4_field_2, &__struct_info__1fb60dfa6730c2c4_field_3, &__struct_info__1fb60dfa6730c2c4_field_4 };
StructInfo __struct_info__1fb60dfa6730c2c4 = {"_lambda_random_96_8_1", "random", 14, __struct_info__1fb60dfa6730c2c4_fields, 5, 40, UINT64_C(0x0), nullptr, UINT64_C(0x1fb60dfa6730c2c4), 5 };
TypeInfo __type_info__af969b4c86582719 = { Type::tUInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 285, 4, UINT64_C(0xaf969b4c86582719) };
TypeInfo __type_info__af63eb4c86020609 = { Type::tVoid, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 0, UINT64_C(0xaf63eb4c86020609) };
TypeInfo __type_info__3da0182fc87a33b6 = { Type::tPointer, nullptr, nullptr, nullptr, &__type_info__2a2886d56ce30259, nullptr, nullptr, nullptr, 0, 0, nullptr, 24588, 8, UINT64_C(0x3da0182fc87a33b6) };
TypeInfo __type_info__af81fe4c86352052 = { Type::tBool, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 60, 1, UINT64_C(0xaf81fe4c86352052) };
TypeInfo __type_info__2a2886d56ce30259 = { Type::tStructure, &__struct_info__1fb60dfa6730c2c4, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 24590, 40, UINT64_C(0x2a2886d56ce30259) };

static void resolveTypeInfoAnnotations()
{
}

namespace random { struct _lambda_random_96_8_1; };
namespace random {

struct _lambda_random_96_8_1 {
	Func DAS_COMMENT((bool,random::_lambda_random_96_8_1,uint32_t &)) __lambda;
	Func DAS_COMMENT((void,random::_lambda_random_96_8_1 *)) __finalize;
	int32_t __yield;
	int32_t rnd_seed;
	int4 seed;
};
static_assert(sizeof(_lambda_random_96_8_1)==40,"structure size mismatch with DAS");
static_assert(offsetof(_lambda_random_96_8_1,__lambda)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_random_96_8_1,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_random_96_8_1,__yield)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_random_96_8_1,rnd_seed)==20,"structure field offset mismatch with DAS");
static_assert(offsetof(_lambda_random_96_8_1,seed)==24,"structure field offset mismatch with DAS");
}

inline uint32_t _FuncrandomTickrandom_uint_a20ddd90c3d8cc59 ( Context * __context__, int4 & __seed_rename_at_40_0 );
inline void finalize_5697222b5e2a5b2d ( Context * __context__, random::_lambda_random_96_8_1 & ____this_rename_at_96_2 );
inline Sequence DAS_COMMENT((uint32_t)) _FuncbuiltinTickeach_3fade8cbda983f79 ( Context * __context__, Lambda DAS_COMMENT((bool,uint32_t &)) const  __lam_rename_at_626_3 );
inline int4 _FuncrandomTickrandom_seed_40d32f1495a9708e ( Context * __context__, int32_t __seed_rename_at_15_5 );
inline bool _Func_lambda_random_96_8_1Tickfunction_24c009f0d663bc2a ( Context * __context__, random::_lambda_random_96_8_1 & ____this_rename_at_96_6, uint32_t & ___yield_96_rename_at_96_7 );
inline void _Func_lambda_random_96_8_1Tickfinalizer_471cd463dc639cbb ( Context * __context__, random::_lambda_random_96_8_1 * ____this_rename_at_96_8 );
inline Sequence DAS_COMMENT((uint32_t)) each_random_uint_41b7bdd619ff25d2 ( Context * __context__, int32_t __rnd_seed_rename_at_94_9 );

void __init_script ( Context * __context__, bool __init_shared )
{
	das_global<int32_t,0xa100e9a22960fc22>(__context__) = 32767;/*LCG_RAND_MAX*/
	das_global<int32_t,0x6d7ed615eaf34962>(__context__) = 1073741823;/*LCG_RAND_MAX_BIG*/
	das_global<float,0xe18471da7dd7b153>(__context__) = 3.05185094e-05f;/*LCG_IRAND_MAX_FLT*/
}

inline uint32_t _FuncrandomTickrandom_uint_a20ddd90c3d8cc59 ( Context * __context__, int4 & __seed_rename_at_40_0 )
{
	das_copy(__seed_rename_at_40_0,SimPolicy<int4>::Add((SimPolicy<int4>::Mul(int4(214013,214013,214013,214013),__seed_rename_at_40_0,*__context__,nullptr)),int4(2531011,2531011,2531011,2531011),*__context__,nullptr));
	int3 __i123_rename_at_43_1 = ((int3)(SimPolicy<int3>::BinAnd((SimPolicy<int3>::BinShr(das_swizzle_seq<int3,int4,0>::swizzle(__seed_rename_at_40_0) /*xyz*/,cast<int32_t>::from(16),*__context__,nullptr)),int3(32767,32767,32767),*__context__,nullptr)));
	return das_auto_cast<uint32_t>::cast((uint32_t(v_extract_xi(v_cast_vec4i(__i123_rename_at_43_1)) /*x*/) ^ (uint32_t(v_extract_yi(v_cast_vec4i(__i123_rename_at_43_1)) /*y*/) << 0xfu)) ^ (uint32_t(v_extract_zi(v_cast_vec4i(__i123_rename_at_43_1)) /*z*/) << 0x1eu));
}

inline void finalize_5697222b5e2a5b2d ( Context * __context__, random::_lambda_random_96_8_1 &  ____this_rename_at_96_2 )
{
	memset(&(____this_rename_at_96_2), 0, 40);
}

inline Sequence DAS_COMMENT((uint32_t)) _FuncbuiltinTickeach_3fade8cbda983f79 ( Context * __context__, Lambda DAS_COMMENT((bool,uint32_t &)) const  __lam_rename_at_626_3 )
{
	Sequence DAS_COMMENT((uint32_t)) __it_rename_at_628_4; das_zero(__it_rename_at_628_4);
	builtin_make_lambda_iterator(das_arg<Sequence DAS_COMMENT((uint32_t))>::pass(__it_rename_at_628_4),__lam_rename_at_626_3,4,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((uint32_t))>::cast(__it_rename_at_628_4);
}

inline int4 _FuncrandomTickrandom_seed_40d32f1495a9708e ( Context * __context__, int32_t __seed_rename_at_15_5 )
{
	return das_auto_cast<int4>::cast(int4(__seed_rename_at_15_5,__seed_rename_at_15_5 + 1,__seed_rename_at_15_5 + 2,__seed_rename_at_15_5 + 3));
}

inline bool _Func_lambda_random_96_8_1Tickfunction_24c009f0d663bc2a ( Context * __context__, random::_lambda_random_96_8_1 &  ____this_rename_at_96_6, uint32_t & ___yield_96_rename_at_96_7 )
{
	switch (____this_rename_at_96_6.__yield) {
	case 0: goto label_0;
	case 1: goto label_1;
	case 3: goto label_3;
	case 2: goto label_2;
	default: __context__->throw_error("invalid label");
	};
	label_0:;;
	das_copy(____this_rename_at_96_6.seed,_FuncrandomTickrandom_seed_40d32f1495a9708e(__context__,____this_rename_at_96_6.rnd_seed));
	label_1:;;
	das_copy(___yield_96_rename_at_96_7,_FuncrandomTickrandom_uint_a20ddd90c3d8cc59(__context__,____this_rename_at_96_6.seed));
	das_copy(____this_rename_at_96_6.__yield,3);
	return das_auto_cast<bool>::cast(true);
	label_3:;;
	goto label_1;
	label_2:;;
	return das_auto_cast<bool>::cast(false);
}

inline void _Func_lambda_random_96_8_1Tickfinalizer_471cd463dc639cbb ( Context * __context__, random::_lambda_random_96_8_1 * ____this_rename_at_96_8 )
{
	finalize_5697222b5e2a5b2d(__context__,das_arg<random::_lambda_random_96_8_1>::pass(das_deref(__context__,____this_rename_at_96_8)));
	das_delete_lambda_struct<random::_lambda_random_96_8_1 *>::clear(__context__,____this_rename_at_96_8);
}

inline Sequence DAS_COMMENT((uint32_t)) each_random_uint_41b7bdd619ff25d2 ( Context * __context__, int32_t __rnd_seed_rename_at_94_9 )
{
	return /* <- */ das_auto_cast_move<Sequence DAS_COMMENT((uint32_t))>::cast(_FuncbuiltinTickeach_3fade8cbda983f79(__context__,das_ascend<bool,random::_lambda_random_96_8_1>::make(__context__,&__type_info__2a2886d56ce30259,(([&]() -> random::_lambda_random_96_8_1 {
		random::_lambda_random_96_8_1 __mks_95;
		das_zero(__mks_95);
		das_copy((__mks_95.__lambda),(Func(__context__->fnByMangledName(/*@random::_lambda_random_96_8_1`function XS<random::_lambda_random_96_8_1> &u*/ 13557031043394381076u))));
		das_copy((__mks_95.__finalize),(Func(__context__->fnByMangledName(/*@random::_lambda_random_96_8_1`finalizer X1<S<random::_lambda_random_96_8_1>>?*/ 9983163889760742665u))));
		das_copy((__mks_95.rnd_seed),(__rnd_seed_rename_at_94_9));
		return __mks_95;
	})()))));
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncrandomTickrandom_uint_a20ddd90c3d8cc59
	aotLib[0x753f756c2ade260] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__, int4 &  ),&_FuncrandomTickrandom_uint_a20ddd90c3d8cc59>>();
	};
	// finalize_5697222b5e2a5b2d
	aotLib[0x65462c90e36db104] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, random::_lambda_random_96_8_1 &  ),&finalize_5697222b5e2a5b2d>>();
	};
	// _FuncbuiltinTickeach_3fade8cbda983f79
	aotLib[0x8789841499982349] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((uint32_t)) (*) ( Context * __context__, Lambda DAS_COMMENT((bool,uint32_t &)) const   ),&_FuncbuiltinTickeach_3fade8cbda983f79>>();
	};
	// _FuncrandomTickrandom_seed_40d32f1495a9708e
	aotLib[0x865950996dfc90b2] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int4 (*) ( Context * __context__, int32_t  ),&_FuncrandomTickrandom_seed_40d32f1495a9708e>>();
	};
	// _Func_lambda_random_96_8_1Tickfunction_24c009f0d663bc2a
	aotLib[0xdd9c0e18e1d92ef2] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, random::_lambda_random_96_8_1 & , uint32_t &  ),&_Func_lambda_random_96_8_1Tickfunction_24c009f0d663bc2a>>();
	};
	// _Func_lambda_random_96_8_1Tickfinalizer_471cd463dc639cbb
	aotLib[0xbb52222bfa1bdb75] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, random::_lambda_random_96_8_1 *  ),&_Func_lambda_random_96_8_1Tickfinalizer_471cd463dc639cbb>>();
	};
	// each_random_uint_41b7bdd619ff25d2
	aotLib[0x1244c7e513f42762] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<Sequence DAS_COMMENT((uint32_t)) (*) ( Context * __context__, int32_t  ),&each_random_uint_41b7bdd619ff25d2>>();
	};
	// [[ init script ]]
	aotLib[0xccb3379a77146546] = [&](Context & ctx){
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
