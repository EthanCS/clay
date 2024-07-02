#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require strings_boost
 // require math
#include "daScript/simulate/aot_builtin_math.h"
 // require strings
#include "daScript/simulate/aot_builtin_string.h"

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
namespace _anon_6357486512992380575 {

extern TypeInfo __type_info__37d36026a6078a42;
extern TypeInfo __type_info__dbbca5962c1c455f;
extern TypeInfo __type_info__5673b06bfec20c2c;
extern TypeInfo __type_info__af63eb4c86020609;
extern TypeInfo __type_info__af63e44c8601fa24;
extern TypeInfo __type_info__5eddda99b960ff80;
extern TypeInfo __type_info__af63ee4c86020b22;
extern TypeInfo __type_info__af90fe4c864e9d52;
extern VarInfo __var_info__335dc116793f6a22;
extern FuncInfo __func_info__d23ecd373e379628;

VarInfo __func_info__d23ecd373e379628_field_0 =  { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af63ee4c86020b22, nullptr, nullptr, nullptr, 0, 0, nullptr, 57442, 24, UINT64_C(0x335dc116793f6a22), "arr", 0, 0 };
VarInfo * __func_info__d23ecd373e379628_fields[1] =  { &__func_info__d23ecd373e379628_field_0 };
FuncInfo __func_info__d23ecd373e379628 = {"invoke block<(arr:array<string> const#):void> const", "", __func_info__d23ecd373e379628_fields, 1, 32, &__type_info__af63eb4c86020609, nullptr,0,UINT64_C(0xd23ecd373e379628), 0x0 };
TypeInfo __type_info__37d36026a6078a42 = { Type::tHandle, nullptr, nullptr, DAS_MAKE_ANNOTATION("~strings::StringBuilderWriter"), nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 2, 288, UINT64_C(0x37d36026a6078a42) };
TypeInfo __type_info__dbbca5962c1c455f = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af63e44c8601fa24, nullptr, nullptr, nullptr, 0, 0, nullptr, 40962, 24, UINT64_C(0xdbbca5962c1c455f) };
TypeInfo __type_info__5673b06bfec20c2c = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__dbbca5962c1c455f, nullptr, nullptr, nullptr, 0, 0, nullptr, 40962, 24, UINT64_C(0x5673b06bfec20c2c) };
TypeInfo __type_info__af63eb4c86020609 = { Type::tVoid, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 0, UINT64_C(0xaf63eb4c86020609) };
TypeInfo __type_info__af63e44c8601fa24 = { Type::tInt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 28, 4, UINT64_C(0xaf63e44c8601fa24) };
TypeInfo __type_info__5eddda99b960ff80 = { Type::tArray, nullptr, nullptr, nullptr, &__type_info__af63ee4c86020b22, nullptr, nullptr, nullptr, 0, 0, nullptr, 57346, 24, UINT64_C(0x5eddda99b960ff80) };
TypeInfo __type_info__af63ee4c86020b22 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16388, 8, UINT64_C(0xaf63ee4c86020b22) };
TypeInfo __type_info__af90fe4c864e9d52 = { Type::tString, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0, nullptr, 16420, 8, UINT64_C(0xaf90fe4c864e9d52) };

static void resolveTypeInfoAnnotations()
{
	__type_info__37d36026a6078a42.resolveAnnotation();
}

TypeInfo * __tinfo_0[1] = { &__type_info__5eddda99b960ff80 };
TypeInfo * __tinfo_1[1] = { &__type_info__5673b06bfec20c2c };
TypeInfo * __tinfo_2[2] = { &__type_info__37d36026a6078a42, &__type_info__af90fe4c864e9d52 };
// unused enumeration ConversionResult

inline void _FuncbuiltinTickresize_74ec5e1daf7410dd ( Context * __context__, TArray<char *> & __Arr_rename_at_50_0, int32_t __newSize_rename_at_50_1 );
inline void _FuncbuiltinTickclone_8be9ccdd83f97cc9 ( Context * __context__, TArray<char *> & __a_rename_at_485_2, TArray<char *> const  & __b_rename_at_485_3 );
inline TArray<char *> & _FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af ( Context * __context__, TArray<char *> & __a_rename_at_38_8 );
inline void _FuncbuiltinTickfinalize_db8c446ca40888ac ( Context * __context__, TArray<TArray<int32_t>> & __a_rename_at_544_9 );
inline void _FuncbuiltinTickfinalize_a9c1b5b42849f16c ( Context * __context__, TArray<int32_t> & __a_rename_at_544_11 );
inline void _FuncbuiltinTickresize_5f1ca32fbed30c65 ( Context * __context__, TArray<TArray<int32_t>> & __Arr_rename_at_50_12, int32_t __newSize_rename_at_50_13 );
inline void _FuncbuiltinTickresize_8cfe3f0a9e270599 ( Context * __context__, TArray<int32_t> & __Arr_rename_at_50_14, int32_t __newSize_rename_at_50_15 );
inline void _FuncbuiltinTickswap_9c26497759a39ade ( Context * __context__, TArray<int32_t> & __a_rename_at_931_16, TArray<int32_t> & __b_rename_at_931_17 );
inline bool _FuncbuiltinTickempty_e1ad558da3dd6f5c ( Context * __context__, TArray<TTuple<16,char *,char *>> const  & __a_rename_at_270_19 );
inline char * wide_af0b6808e99dcd61 ( Context * __context__, char * const  __text_rename_at_11_20, int32_t __width_rename_at_11_21 );
inline TArray<char *> split_9ae7413d8a97c7f9 ( Context * __context__, char * const  __text_rename_at_60_23, char * const  __delim_rename_at_60_24 );
inline TArray<char *> split_by_chars_9aeed0dc41cd9810 ( Context * __context__, char * const  __text_rename_at_69_27, char * const  __delim_rename_at_69_28 );
inline int32_t levenshtein_distance_173a3b0d569715c6 ( Context * __context__, char * const  __s_rename_at_89_31, char * const  __t_rename_at_89_32 );
inline int32_t levenshtein_distance_fast_cf372b361e0d44ca ( Context * __context__, char * const  __s_rename_at_112_41, char * const  __t_rename_at_112_42 );
inline char * replace_multiple_dee4c0cb18d973d2 ( Context * __context__, char * const  __source_rename_at_138_53, TArray<TTuple<16,char *,char *>> const  & __replaces_rename_at_138_54 );
inline bool is_hex_3cd19dea5cc5dda ( Context * __context__, int32_t __ch_rename_at_157_60 );
inline bool is_tab_or_space_4e7e1b336c6452cc ( Context * __context__, int32_t __ch_rename_at_160_61 );

void __init_script ( Context * __context__, bool __init_shared )
{
}

inline void _FuncbuiltinTickresize_74ec5e1daf7410dd ( Context * __context__, TArray<char *> &  __Arr_rename_at_50_0, int32_t __newSize_rename_at_50_1 )
{
	builtin_array_resize(das_arg<TArray<char *>>::pass(__Arr_rename_at_50_0),__newSize_rename_at_50_1,8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickclone_8be9ccdd83f97cc9 ( Context * __context__, TArray<char *> &  __a_rename_at_485_2, TArray<char *> const  &  __b_rename_at_485_3 )
{
	_FuncbuiltinTickresize_74ec5e1daf7410dd(__context__,das_arg<TArray<char *>>::pass(__a_rename_at_485_2),builtin_array_size(__b_rename_at_485_3));
	{
		bool __need_loop_487 = true;
		// aV : string aka TT&
		das_iterator<TArray<char *>> __aV_iterator(__a_rename_at_485_2);
		char * * __aV_rename_at_487_6;
		__need_loop_487 = __aV_iterator.first(__context__,(__aV_rename_at_487_6)) && __need_loop_487;
		// bV : string const&#
		das_iterator<TArray<char *> const > __bV_iterator(__b_rename_at_485_3);
		char * const  * __bV_rename_at_487_7;
		__need_loop_487 = __bV_iterator.first(__context__,(__bV_rename_at_487_7)) && __need_loop_487;
		for ( ; __need_loop_487 ; __need_loop_487 = __aV_iterator.next(__context__,(__aV_rename_at_487_6)) && __bV_iterator.next(__context__,(__bV_rename_at_487_7)) )
		{
			das_copy((*__aV_rename_at_487_6),((char *)(builtin_string_clone((*__bV_rename_at_487_7),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))))));
		}
		__aV_iterator.close(__context__,(__aV_rename_at_487_6));
		__bV_iterator.close(__context__,(__bV_rename_at_487_7));
	};
}

inline TArray<char *> & _FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af ( Context * __context__, TArray<char *> &  __a_rename_at_38_8 )
{
	das_call_interop<void>::call(&builtin_verify_locks,__context__,SimNode_AotInterop<1>(__tinfo_0,cast<TArray<char *> &>::from(__a_rename_at_38_8)));
	return das_auto_cast_ref<TArray<char *> &>::cast(__a_rename_at_38_8);
}

inline void _FuncbuiltinTickfinalize_db8c446ca40888ac ( Context * __context__, TArray<TArray<int32_t>> &  __a_rename_at_544_9 )
{
	{
		bool __need_loop_546 = true;
		// aV : array<int> aka TT&
		das_iterator<TArray<TArray<int32_t>>> __aV_iterator(__a_rename_at_544_9);
		TArray<int32_t> * __aV_rename_at_546_10;
		__need_loop_546 = __aV_iterator.first(__context__,(__aV_rename_at_546_10)) && __need_loop_546;
		for ( ; __need_loop_546 ; __need_loop_546 = __aV_iterator.next(__context__,(__aV_rename_at_546_10)) )
		{
			_FuncbuiltinTickfinalize_a9c1b5b42849f16c(__context__,das_arg<TArray<int32_t>>::pass((*__aV_rename_at_546_10)));
		}
		__aV_iterator.close(__context__,(__aV_rename_at_546_10));
	};
	builtin_array_free(das_arg<TArray<TArray<int32_t>>>::pass(__a_rename_at_544_9),24,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickfinalize_a9c1b5b42849f16c ( Context * __context__, TArray<int32_t> &  __a_rename_at_544_11 )
{
	builtin_array_free(das_arg<TArray<int32_t>>::pass(__a_rename_at_544_11),4,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickresize_5f1ca32fbed30c65 ( Context * __context__, TArray<TArray<int32_t>> &  __Arr_rename_at_50_12, int32_t __newSize_rename_at_50_13 )
{
	das_call_interop<void>::call(&builtin_verify_locks,__context__,SimNode_AotInterop<1>(__tinfo_1,cast<TArray<TArray<int32_t>> &>::from(__Arr_rename_at_50_12)));
	builtin_array_resize(das_arg<TArray<TArray<int32_t>>>::pass(__Arr_rename_at_50_12),__newSize_rename_at_50_13,24,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickresize_8cfe3f0a9e270599 ( Context * __context__, TArray<int32_t> &  __Arr_rename_at_50_14, int32_t __newSize_rename_at_50_15 )
{
	builtin_array_resize(das_arg<TArray<int32_t>>::pass(__Arr_rename_at_50_14),__newSize_rename_at_50_15,4,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
}

inline void _FuncbuiltinTickswap_9c26497759a39ade ( Context * __context__, TArray<int32_t> &  __a_rename_at_931_16, TArray<int32_t> &  __b_rename_at_931_17 )
{
	TArray<int32_t> __t_rename_at_933_18; das_zero(__t_rename_at_933_18); das_move(__t_rename_at_933_18, __a_rename_at_931_16);
	das_move(__a_rename_at_931_16,__b_rename_at_931_17);
	das_move(__b_rename_at_931_17,__t_rename_at_933_18);
}

inline bool _FuncbuiltinTickempty_e1ad558da3dd6f5c ( Context * __context__, TArray<TTuple<16,char *,char *>> const  &  __a_rename_at_270_19 )
{
	return das_auto_cast<bool>::cast(builtin_array_size(__a_rename_at_270_19) == 0);
}

inline char * wide_af0b6808e99dcd61 ( Context * __context__, char * const  __text_rename_at_11_20, int32_t __width_rename_at_11_21 )
{
	int32_t __extra_rename_at_12_22 = ((int32_t)(__width_rename_at_11_21 - builtin_string_length(__text_rename_at_11_20,__context__)));
	return das_auto_cast<char *>::cast((__extra_rename_at_12_22 > 0) ? das_auto_cast<char *>::cast((cast<char *>::to(SimPolicy<char *>::Add(cast<char *>::from(__text_rename_at_11_20),cast<char *>::from(((char *)(string_repeat(((char *) " "),__extra_rename_at_12_22,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))),*__context__,nullptr)))) : das_auto_cast<char *>::cast(__text_rename_at_11_20));
}

inline TArray<char *> split_9ae7413d8a97c7f9 ( Context * __context__, char * const  __text_rename_at_60_23, char * const  __delim_rename_at_60_24 ) { das_stack_prologue __prologue(__context__,128,"split " DAS_FILE_LINE);
{
	TArray<char *> __res_rename_at_61_25; das_zero(__res_rename_at_61_25);
	builtin_string_split(__text_rename_at_60_23,__delim_rename_at_60_24,das_make_block<void,TArray<char *> const  &>(__context__,112,0,&__func_info__d23ecd373e379628,[&](TArray<char *> const  & __arr_rename_at_62_26) -> void{
		_FuncbuiltinTickclone_8be9ccdd83f97cc9(__context__,das_arg<TArray<char *>>::pass(__res_rename_at_61_25),__arr_rename_at_62_26);
	}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<TArray<char *>>::cast(_FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af(__context__,das_arg<TArray<char *>>::pass(__res_rename_at_61_25)));
}}

inline TArray<char *> split_by_chars_9aeed0dc41cd9810 ( Context * __context__, char * const  __text_rename_at_69_27, char * const  __delim_rename_at_69_28 ) { das_stack_prologue __prologue(__context__,128,"split_by_chars " DAS_FILE_LINE);
{
	TArray<char *> __res_rename_at_70_29; das_zero(__res_rename_at_70_29);
	builtin_string_split_by_char(__text_rename_at_69_27,__delim_rename_at_69_28,das_make_block<void,TArray<char *> const  &>(__context__,112,0,&__func_info__d23ecd373e379628,[&](TArray<char *> const  & __arr_rename_at_71_30) -> void{
		_FuncbuiltinTickclone_8be9ccdd83f97cc9(__context__,das_arg<TArray<char *>>::pass(__res_rename_at_70_29),__arr_rename_at_71_30);
	}),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)));
	return /* <- */ das_auto_cast_move<TArray<char *>>::cast(_FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af(__context__,das_arg<TArray<char *>>::pass(__res_rename_at_70_29)));
}}

inline int32_t levenshtein_distance_173a3b0d569715c6 ( Context * __context__, char * const  __s_rename_at_89_31, char * const  __t_rename_at_89_32 )
{
	int32_t __sLen_rename_at_90_33; memset(&__sLen_rename_at_90_33,0,sizeof(__sLen_rename_at_90_33));
	int32_t __tLen_rename_at_91_34; memset(&__tLen_rename_at_91_34,0,sizeof(__tLen_rename_at_91_34));
	TArray<TArray<int32_t>> __d_rename_at_92_35; memset(&__d_rename_at_92_35,0,sizeof(__d_rename_at_92_35));
	int32_t __substitutionCost_rename_at_102_40; memset(&__substitutionCost_rename_at_102_40,0,sizeof(__substitutionCost_rename_at_102_40));
/* finally */ auto __finally_90= das_finally([&](){
	_FuncbuiltinTickfinalize_db8c446ca40888ac(__context__,das_arg<TArray<TArray<int32_t>>>::pass(__d_rename_at_92_35));
/* end finally */ });
	__sLen_rename_at_90_33 = ((int32_t)builtin_string_length(__s_rename_at_89_31,__context__));
	__tLen_rename_at_91_34 = ((int32_t)builtin_string_length(__t_rename_at_89_32,__context__));
	__d_rename_at_92_35; das_zero(__d_rename_at_92_35);
	_FuncbuiltinTickresize_5f1ca32fbed30c65(__context__,das_arg<TArray<TArray<int32_t>>>::pass(__d_rename_at_92_35),__sLen_rename_at_90_33 + 1);
	{
		bool __need_loop_94 = true;
		// i : int const
		das_iterator<range> __i_iterator(mk_range(__sLen_rename_at_90_33 + 1));
		int32_t __i_rename_at_94_36;
		__need_loop_94 = __i_iterator.first(__context__,(__i_rename_at_94_36)) && __need_loop_94;
		for ( ; __need_loop_94 ; __need_loop_94 = __i_iterator.next(__context__,(__i_rename_at_94_36)) )
		{
			_FuncbuiltinTickresize_8cfe3f0a9e270599(__context__,das_arg<TArray<int32_t>>::pass(__d_rename_at_92_35(__i_rename_at_94_36,__context__)),__tLen_rename_at_91_34 + 1);
			das_copy(__d_rename_at_92_35(__i_rename_at_94_36,__context__)(0,__context__),__i_rename_at_94_36);
		}
		__i_iterator.close(__context__,(__i_rename_at_94_36));
	};
	{
		bool __need_loop_97 = true;
		// j : int const
		das_iterator<range> __j_iterator(mk_range(__tLen_rename_at_91_34 + 1));
		int32_t __j_rename_at_97_37;
		__need_loop_97 = __j_iterator.first(__context__,(__j_rename_at_97_37)) && __need_loop_97;
		for ( ; __need_loop_97 ; __need_loop_97 = __j_iterator.next(__context__,(__j_rename_at_97_37)) )
		{
			das_copy(__d_rename_at_92_35(0,__context__)(__j_rename_at_97_37,__context__),__j_rename_at_97_37);
		}
		__j_iterator.close(__context__,(__j_rename_at_97_37));
	};
	{
		bool __need_loop_100 = true;
		// i : int const
		das_iterator<range> __i_iterator(range(1,__sLen_rename_at_90_33 + 1));
		int32_t __i_rename_at_100_38;
		__need_loop_100 = __i_iterator.first(__context__,(__i_rename_at_100_38)) && __need_loop_100;
		for ( ; __need_loop_100 ; __need_loop_100 = __i_iterator.next(__context__,(__i_rename_at_100_38)) )
		{
			{
				bool __need_loop_101 = true;
				// j : int const
				das_iterator<range> __j_iterator(range(1,__tLen_rename_at_91_34 + 1));
				int32_t __j_rename_at_101_39;
				__need_loop_101 = __j_iterator.first(__context__,(__j_rename_at_101_39)) && __need_loop_101;
				for ( ; __need_loop_101 ; __need_loop_101 = __j_iterator.next(__context__,(__j_rename_at_101_39)) )
				{
					__substitutionCost_rename_at_102_40 = ((int32_t)((get_character_uat(__s_rename_at_89_31,__i_rename_at_100_38 - 1) == get_character_uat(__t_rename_at_89_32,__j_rename_at_101_39 - 1)) ? das_auto_cast<int32_t>::cast(0) : das_auto_cast<int32_t>::cast(1)));
					das_copy(__d_rename_at_92_35(__i_rename_at_100_38,__context__)(__j_rename_at_101_39,__context__),SimPolicy<int32_t>::Min(__d_rename_at_92_35((__i_rename_at_100_38 - 1),__context__)(__j_rename_at_101_39,__context__) + 1,__d_rename_at_92_35(__i_rename_at_100_38,__context__)((__j_rename_at_101_39 - 1),__context__) + 1,*__context__,nullptr));
					das_copy(__d_rename_at_92_35(__i_rename_at_100_38,__context__)(__j_rename_at_101_39,__context__),SimPolicy<int32_t>::Min(__d_rename_at_92_35(__i_rename_at_100_38,__context__)(__j_rename_at_101_39,__context__),__d_rename_at_92_35((__i_rename_at_100_38 - 1),__context__)((__j_rename_at_101_39 - 1),__context__) + __substitutionCost_rename_at_102_40,*__context__,nullptr));
				}
				__j_iterator.close(__context__,(__j_rename_at_101_39));
			};
		}
		__i_iterator.close(__context__,(__i_rename_at_100_38));
	};
	return das_auto_cast<int32_t>::cast(__d_rename_at_92_35(__sLen_rename_at_90_33,__context__)(__tLen_rename_at_91_34,__context__));
}

inline int32_t levenshtein_distance_fast_cf372b361e0d44ca ( Context * __context__, char * const  __s_rename_at_112_41, char * const  __t_rename_at_112_42 )
{
	int32_t __sLen_rename_at_113_43; memset(&__sLen_rename_at_113_43,0,sizeof(__sLen_rename_at_113_43));
	int32_t __tLen_rename_at_114_44; memset(&__tLen_rename_at_114_44,0,sizeof(__tLen_rename_at_114_44));
	TArray<int32_t> __v0_rename_at_115_45; memset(&__v0_rename_at_115_45,0,sizeof(__v0_rename_at_115_45));
	TArray<int32_t> __v1_rename_at_117_46; memset(&__v1_rename_at_117_46,0,sizeof(__v1_rename_at_117_46));
	int32_t __deletionCost_rename_at_125_50; memset(&__deletionCost_rename_at_125_50,0,sizeof(__deletionCost_rename_at_125_50));
	int32_t __insertionCost_rename_at_126_51; memset(&__insertionCost_rename_at_126_51,0,sizeof(__insertionCost_rename_at_126_51));
	int32_t __substitutionCost_rename_at_127_52; memset(&__substitutionCost_rename_at_127_52,0,sizeof(__substitutionCost_rename_at_127_52));
/* finally */ auto __finally_113= das_finally([&](){
	_FuncbuiltinTickfinalize_a9c1b5b42849f16c(__context__,das_arg<TArray<int32_t>>::pass(__v0_rename_at_115_45));
	_FuncbuiltinTickfinalize_a9c1b5b42849f16c(__context__,das_arg<TArray<int32_t>>::pass(__v1_rename_at_117_46));
/* end finally */ });
	__sLen_rename_at_113_43 = ((int32_t)builtin_string_length(__s_rename_at_112_41,__context__));
	__tLen_rename_at_114_44 = ((int32_t)builtin_string_length(__t_rename_at_112_42,__context__));
	__v0_rename_at_115_45; das_zero(__v0_rename_at_115_45);
	_FuncbuiltinTickresize_8cfe3f0a9e270599(__context__,das_arg<TArray<int32_t>>::pass(__v0_rename_at_115_45),__tLen_rename_at_114_44 + 1);
	__v1_rename_at_117_46; das_zero(__v1_rename_at_117_46);
	_FuncbuiltinTickresize_8cfe3f0a9e270599(__context__,das_arg<TArray<int32_t>>::pass(__v1_rename_at_117_46),__tLen_rename_at_114_44 + 1);
	{
		bool __need_loop_119 = true;
		// i : int const
		das_iterator<range> __i_iterator(mk_range(__tLen_rename_at_114_44 + 1));
		int32_t __i_rename_at_119_47;
		__need_loop_119 = __i_iterator.first(__context__,(__i_rename_at_119_47)) && __need_loop_119;
		for ( ; __need_loop_119 ; __need_loop_119 = __i_iterator.next(__context__,(__i_rename_at_119_47)) )
		{
			das_copy(__v0_rename_at_115_45(__i_rename_at_119_47,__context__),__i_rename_at_119_47);
		}
		__i_iterator.close(__context__,(__i_rename_at_119_47));
	};
	{
		bool __need_loop_122 = true;
		// i : int const
		das_iterator<range> __i_iterator(range(0,__sLen_rename_at_113_43));
		int32_t __i_rename_at_122_48;
		__need_loop_122 = __i_iterator.first(__context__,(__i_rename_at_122_48)) && __need_loop_122;
		for ( ; __need_loop_122 ; __need_loop_122 = __i_iterator.next(__context__,(__i_rename_at_122_48)) )
		{
			das_copy(__v1_rename_at_117_46(0,__context__),__i_rename_at_122_48 + 1);
			{
				bool __need_loop_124 = true;
				// j : int const
				das_iterator<range> __j_iterator(range(0,__tLen_rename_at_114_44));
				int32_t __j_rename_at_124_49;
				__need_loop_124 = __j_iterator.first(__context__,(__j_rename_at_124_49)) && __need_loop_124;
				for ( ; __need_loop_124 ; __need_loop_124 = __j_iterator.next(__context__,(__j_rename_at_124_49)) )
				{
					__deletionCost_rename_at_125_50 = ((int32_t)(__v0_rename_at_115_45((__j_rename_at_124_49 + 1),__context__) + 1));
					__insertionCost_rename_at_126_51 = ((int32_t)(__v1_rename_at_117_46(__j_rename_at_124_49,__context__) + 1));
					__substitutionCost_rename_at_127_52 = ((int32_t)(__v0_rename_at_115_45(__j_rename_at_124_49,__context__) + ((get_character_uat(__s_rename_at_112_41,__i_rename_at_122_48) == get_character_uat(__t_rename_at_112_42,__j_rename_at_124_49)) ? das_auto_cast<int32_t>::cast(0) : das_auto_cast<int32_t>::cast(1))));
					das_copy(__v1_rename_at_117_46((__j_rename_at_124_49 + 1),__context__),SimPolicy<int32_t>::Min(__deletionCost_rename_at_125_50,__insertionCost_rename_at_126_51,*__context__,nullptr));
					das_copy(__v1_rename_at_117_46((__j_rename_at_124_49 + 1),__context__),SimPolicy<int32_t>::Min(__v1_rename_at_117_46((__j_rename_at_124_49 + 1),__context__),__substitutionCost_rename_at_127_52,*__context__,nullptr));
				}
				__j_iterator.close(__context__,(__j_rename_at_124_49));
			};
			_FuncbuiltinTickswap_9c26497759a39ade(__context__,das_arg<TArray<int32_t>>::pass(__v0_rename_at_115_45),das_arg<TArray<int32_t>>::pass(__v1_rename_at_117_46));
		}
		__i_iterator.close(__context__,(__i_rename_at_122_48));
	};
	return das_auto_cast<int32_t>::cast(__v0_rename_at_115_45(__tLen_rename_at_114_44,__context__));
}

inline char * replace_multiple_dee4c0cb18d973d2 ( Context * __context__, char * const  __source_rename_at_138_53, TArray<TTuple<16,char *,char *>> const  &  __replaces_rename_at_138_54 )
{
	return das_auto_cast<char *>::cast((builtin_empty(__source_rename_at_138_53) || _FuncbuiltinTickempty_e1ad558da3dd6f5c(__context__,__replaces_rename_at_138_54)) ? das_auto_cast<char * const >::cast(__source_rename_at_138_53) : das_auto_cast<char * const >::cast(((char *)(builtin_build_string_T([&](StringBuilderWriter & __writer_rename_at_142_55) DAS_AOT_INLINE_LAMBDA -> void{
		int32_t __index_rename_at_143_56 = 0;
		int32_t __len_rename_at_144_57 = ((int32_t)builtin_string_length(__source_rename_at_138_53,__context__));
		while ( __index_rename_at_143_56 < __len_rename_at_144_57 )
		{
			bool __found_rename_at_146_58 = false;
			{
				bool __need_loop_147 = true;
				// replace : tuple<text:string;replacement:string> const&
				das_iterator<TArray<TTuple<16,char *,char *>> const > __replace_iterator(__replaces_rename_at_138_54);
				TTuple<16,char *,char *> const  * __replace_rename_at_147_59;
				__need_loop_147 = __replace_iterator.first(__context__,(__replace_rename_at_147_59)) && __need_loop_147;
				for ( ; __need_loop_147 ; __need_loop_147 = __replace_iterator.next(__context__,(__replace_rename_at_147_59)) )
				{
					if ( builtin_string_startswith3(__source_rename_at_138_53,__index_rename_at_143_56,das_get_tuple_field<char *,0>::get((*__replace_rename_at_147_59)),__context__) )
					{
						das_call_interop<StringBuilderWriter &>::call(&builtin_write_string,__context__,SimNode_AotInterop<2>(__tinfo_2,cast<StringBuilderWriter &>::from(__writer_rename_at_142_55),cast<char * const >::from(das_get_tuple_field<char *,8>::get((*__replace_rename_at_147_59)))));
						__index_rename_at_143_56 += builtin_string_length(das_get_tuple_field<char *,0>::get((*__replace_rename_at_147_59)),__context__);
						das_copy(__found_rename_at_146_58,true);
						break;
					};
				}
				__replace_iterator.close(__context__,(__replace_rename_at_147_59));
			};
			if ( !__found_rename_at_146_58 )
			{
				write_string_char(das_arg<StringBuilderWriter>::pass(__writer_rename_at_142_55),get_character_uat(__source_rename_at_138_53,__index_rename_at_143_56));
				++__index_rename_at_143_56;
			};
		};
	},__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL)))))));
}

inline bool is_hex_3cd19dea5cc5dda ( Context * __context__, int32_t __ch_rename_at_157_60 )
{
	return das_auto_cast<bool>::cast((((__ch_rename_at_157_60 >= 48) && (__ch_rename_at_157_60 <= 57)) || ((__ch_rename_at_157_60 >= 97) && (__ch_rename_at_157_60 <= 102))) || ((__ch_rename_at_157_60 >= 65) && (__ch_rename_at_157_60 <= 70)));
}

inline bool is_tab_or_space_4e7e1b336c6452cc ( Context * __context__, int32_t __ch_rename_at_160_61 )
{
	return das_auto_cast<bool>::cast((__ch_rename_at_160_61 == 32) || (__ch_rename_at_160_61 == 9));
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// _FuncbuiltinTickresize_74ec5e1daf7410dd
	aotLib[0xa8f7d3522b19cb40] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<char *> & , int32_t  ),&_FuncbuiltinTickresize_74ec5e1daf7410dd>>();
	};
	// _FuncbuiltinTickclone_8be9ccdd83f97cc9
	aotLib[0x7e4e68e34d09088e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<char *> & , TArray<char *> const  &  ),&_FuncbuiltinTickclone_8be9ccdd83f97cc9>>();
	};
	// _FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af
	aotLib[0xdeae3e4362af414f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<TArray<char *> & (*) ( Context * __context__, TArray<char *> &  ),&_FuncbuiltinTick_return_with_lockcheck_64fb77f0b59f33af>>();
	};
	// _FuncbuiltinTickfinalize_db8c446ca40888ac
	aotLib[0x81adea71bde89087] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<TArray<int32_t>> &  ),&_FuncbuiltinTickfinalize_db8c446ca40888ac>>();
	};
	// _FuncbuiltinTickfinalize_a9c1b5b42849f16c
	aotLib[0x645e1259a18985] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<int32_t> &  ),&_FuncbuiltinTickfinalize_a9c1b5b42849f16c>>();
	};
	// _FuncbuiltinTickresize_5f1ca32fbed30c65
	aotLib[0x51d99372db1d1843] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<TArray<int32_t>> & , int32_t  ),&_FuncbuiltinTickresize_5f1ca32fbed30c65>>();
	};
	// _FuncbuiltinTickresize_8cfe3f0a9e270599
	aotLib[0x5cc5d1612ee650f6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<int32_t> & , int32_t  ),&_FuncbuiltinTickresize_8cfe3f0a9e270599>>();
	};
	// _FuncbuiltinTickswap_9c26497759a39ade
	aotLib[0xed522c474f9013a0] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<void (*) ( Context * __context__, TArray<int32_t> & , TArray<int32_t> &  ),&_FuncbuiltinTickswap_9c26497759a39ade>>();
	};
	// _FuncbuiltinTickempty_e1ad558da3dd6f5c
	aotLib[0x853b8e93f64e3746] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, TArray<TTuple<16,char *,char *>> const  &  ),&_FuncbuiltinTickempty_e1ad558da3dd6f5c>>();
	};
	// wide_af0b6808e99dcd61
	aotLib[0xb81e26932edf2d35] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, char * const  , int32_t  ),&wide_af0b6808e99dcd61>>();
	};
	// split_9ae7413d8a97c7f9
	aotLib[0xf5d86ebd39e8fdd6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<char *> (*) ( Context * __context__, char * const  , char * const   ),&split_9ae7413d8a97c7f9>>();
	};
	// split_by_chars_9aeed0dc41cd9810
	aotLib[0x4a4cad6992450bdf] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<TArray<char *> (*) ( Context * __context__, char * const  , char * const   ),&split_by_chars_9aeed0dc41cd9810>>();
	};
	// levenshtein_distance_173a3b0d569715c6
	aotLib[0x6868ff831e50c40f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, char * const  , char * const   ),&levenshtein_distance_173a3b0d569715c6>>();
	};
	// levenshtein_distance_fast_cf372b361e0d44ca
	aotLib[0x8c0c62f13e3c8bd6] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<int32_t (*) ( Context * __context__, char * const  , char * const   ),&levenshtein_distance_fast_cf372b361e0d44ca>>();
	};
	// replace_multiple_dee4c0cb18d973d2
	aotLib[0xc2e6381181a78c8e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<char * (*) ( Context * __context__, char * const  , TArray<TTuple<16,char *,char *>> const  &  ),&replace_multiple_dee4c0cb18d973d2>>();
	};
	// is_hex_3cd19dea5cc5dda
	aotLib[0x910c07bdad7a75f7] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, int32_t  ),&is_hex_3cd19dea5cc5dda>>();
	};
	// is_tab_or_space_4e7e1b336c6452cc
	aotLib[0xb6d64be636d41d6f] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, int32_t  ),&is_tab_or_space_4e7e1b336c6452cc>>();
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
