#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
 // require math_boost
 // require math
#include "daScript/simulate/aot_builtin_math.h"
 // require math_bits

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
namespace _anon_5474359827199664040 {



static void resolveTypeInfoAnnotations()
{
}

namespace math_boost { struct AABR; };
namespace math_boost { struct AABB; };
namespace math_boost { struct Ray; };
namespace math_boost {

struct AABR {
	float2 min;
	float2 max;
};
static_assert(sizeof(AABR)==16,"structure size mismatch with DAS");
static_assert(offsetof(AABR,min)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AABR,max)==8,"structure field offset mismatch with DAS");
}
namespace math_boost {

struct AABB {
	float3 min;
	float3 max;
};
static_assert(sizeof(AABB)==24,"structure size mismatch with DAS");
static_assert(offsetof(AABB,min)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AABB,max)==12,"structure field offset mismatch with DAS");
}
namespace math_boost {

struct Ray {
	float3 dir;
	float3 origin;
};
static_assert(sizeof(Ray)==24,"structure size mismatch with DAS");
static_assert(offsetof(Ray,dir)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(Ray,origin)==12,"structure field offset mismatch with DAS");
}

inline float degrees_a661e6cfff0d8952 ( Context * __context__, float __f_rename_at_27_0 );
inline float radians_aa78c69bde52354a ( Context * __context__, float __f_rename_at_31_1 );
inline uint32_t RGBA_TO_UCOLOR_f52d3d498ec28ea4 ( Context * __context__, float __x_rename_at_35_2, float __y_rename_at_35_3, float __z_rename_at_35_4, float __w_rename_at_35_5 );
inline uint32_t RGBA_TO_UCOLOR_fb5992436af224c9 ( Context * __context__, float4 __xyzw_rename_at_39_6 );
inline float4 UCOLOR_TO_RGBA_df3b1693521d201f ( Context * __context__, uint32_t __x_rename_at_42_7 );
inline float3 UCOLOR_TO_RGB_1557f9cd645f174a ( Context * __context__, uint32_t __x_rename_at_50_8 );
inline float linear_to_SRGB_eedb6de51617a75 ( Context * __context__, float __x_rename_at_57_9 );
inline float3 linear_to_SRGB_5492768924fd03c3 ( Context * __context__, float3 __c_rename_at_64_10 );
inline float4 linear_to_SRGB_30ee3e123c55a357 ( Context * __context__, float4 __c_rename_at_67_11 );
inline bool is_intersecting_519f106fdec1d140 ( Context * __context__, math_boost::AABR const  & __a_rename_at_70_12, math_boost::AABR const  & __b_rename_at_70_13 );
inline bool is_intersecting_76dc5cb27b1cce20 ( Context * __context__, math_boost::AABB const  & __a_rename_at_75_14, math_boost::AABB const  & __b_rename_at_75_15 );
inline bool is_intersecting_83c244c5cad1eaf9 ( Context * __context__, math_boost::Ray const  & __ray_rename_at_79_16, math_boost::AABB const  & __aabb_rename_at_79_17, float __Tmin_rename_at_79_18, float __Tmax_rename_at_79_19 );
inline float4x4 look_at_lh_12ae4d22ab712b1 ( Context * __context__, float3 __Eye_rename_at_89_27, float3 __At_rename_at_89_28, float3 __Up_rename_at_89_29 );
inline float4x4 look_at_rh_57fabbbe8b8576f7 ( Context * __context__, float3 __Eye_rename_at_103_34, float3 __At_rename_at_103_35, float3 __Up_rename_at_103_36 );
inline float4x4 perspective_lh_2fac1cd2df0ab7fe ( Context * __context__, float __fovy_rename_at_117_41, float __aspect_rename_at_117_42, float __zn_rename_at_117_43, float __zf_rename_at_117_44 );
inline float4x4 perspective_rh_5d20db61257b5b19 ( Context * __context__, float __fovy_rename_at_130_48, float __aspect_rename_at_130_49, float __zn_rename_at_130_50, float __zf_rename_at_130_51 );
inline float4x4 perspective_rh_opengl_fcf6139ab08387ca ( Context * __context__, float __fovy_rename_at_143_55, float __aspect_rename_at_143_56, float __zn_rename_at_143_57, float __zf_rename_at_143_58 );
inline float4x4 ortho_rh_f6bc4f195f22d8d5 ( Context * __context__, float __left_rename_at_156_62, float __right_rename_at_156_63, float __bottom_rename_at_156_64, float __top_rename_at_156_65, float __zNear_rename_at_156_66, float __zFar_rename_at_156_67 );
inline float plane_dot_cf6fadebd33ebe09 ( Context * __context__, float4 __Plane_rename_at_168_69, float4 __Vec_rename_at_168_70 );
inline float4 plane_normalize_bcd7d36c68415690 ( Context * __context__, float4 __Plane_rename_at_172_71 );
inline float4 plane_from_point_normal_110b03e9793d1239 ( Context * __context__, float3 __p_rename_at_177_73, float3 __n_rename_at_177_74 );
inline float4x4 planar_shadow_304637f7a6dac3fe ( Context * __context__, float4 __Light_rename_at_181_75, float4 __Plane_rename_at_181_76 );

void __init_script ( Context * __context__, bool __init_shared )
{
}

inline float degrees_a661e6cfff0d8952 ( Context * __context__, float __f_rename_at_27_0 )
{
	return das_auto_cast<float>::cast(SimPolicy<float>::Div((__f_rename_at_27_0 * 180.f),3.14159274f,*__context__,nullptr));
}

inline float radians_aa78c69bde52354a ( Context * __context__, float __f_rename_at_31_1 )
{
	return das_auto_cast<float>::cast(SimPolicy<float>::Div((__f_rename_at_31_1 * 3.14159274f),180.f,*__context__,nullptr));
}

inline uint32_t RGBA_TO_UCOLOR_f52d3d498ec28ea4 ( Context * __context__, float __x_rename_at_35_2, float __y_rename_at_35_3, float __z_rename_at_35_4, float __w_rename_at_35_5 )
{
	return das_auto_cast<uint32_t>::cast(pack_float_to_byte(SimPolicy<float4>::MulVecScal(float4(__x_rename_at_35_2,__y_rename_at_35_3,__z_rename_at_35_4,__w_rename_at_35_5),cast<float>::from(255.f),*__context__,nullptr)));
}

inline uint32_t RGBA_TO_UCOLOR_fb5992436af224c9 ( Context * __context__, float4 __xyzw_rename_at_39_6 )
{
	return das_auto_cast<uint32_t>::cast(pack_float_to_byte(SimPolicy<float4>::MulVecScal(__xyzw_rename_at_39_6,cast<float>::from(255.f),*__context__,nullptr)));
}

inline float4 UCOLOR_TO_RGBA_df3b1693521d201f ( Context * __context__, uint32_t __x_rename_at_42_7 )
{
	return das_auto_cast<float4>::cast(float4(SimPolicy<float>::Div(float((__x_rename_at_42_7 >> 0x10u) & 0xffu),255.f,*__context__,nullptr),SimPolicy<float>::Div(float((__x_rename_at_42_7 >> 0x8u) & 0xffu),255.f,*__context__,nullptr),SimPolicy<float>::Div(float((__x_rename_at_42_7 >> 0x0u) & 0xffu),255.f,*__context__,nullptr),SimPolicy<float>::Div(float((__x_rename_at_42_7 >> 0x18u) & 0xffu),255.f,*__context__,nullptr)));
}

inline float3 UCOLOR_TO_RGB_1557f9cd645f174a ( Context * __context__, uint32_t __x_rename_at_50_8 )
{
	return das_auto_cast<float3>::cast(float3(SimPolicy<float>::Div(float((__x_rename_at_50_8 >> 0x10u) & 0xffu),255.f,*__context__,nullptr),SimPolicy<float>::Div(float((__x_rename_at_50_8 >> 0x8u) & 0xffu),255.f,*__context__,nullptr),SimPolicy<float>::Div(float((__x_rename_at_50_8 >> 0x0u) & 0xffu),255.f,*__context__,nullptr)));
}

inline float linear_to_SRGB_eedb6de51617a75 ( Context * __context__, float __x_rename_at_57_9 )
{
	return das_auto_cast<float>::cast((__x_rename_at_57_9 <= 0.000313080003f) ? das_auto_cast<float>::cast((__x_rename_at_57_9 * 12.9200001f)) : das_auto_cast<float>::cast(((SimPolicy<float>::Pow(__x_rename_at_57_9,0.416666657f,*__context__,nullptr) * 1.05499995f) - 0.0549999997f)));
}

inline float3 linear_to_SRGB_5492768924fd03c3 ( Context * __context__, float3 __c_rename_at_64_10 )
{
	return das_auto_cast<float3>::cast(float3(linear_to_SRGB_eedb6de51617a75(__context__,v_extract_x(__c_rename_at_64_10) /*x*/),linear_to_SRGB_eedb6de51617a75(__context__,v_extract_y(__c_rename_at_64_10) /*y*/),linear_to_SRGB_eedb6de51617a75(__context__,v_extract_z(__c_rename_at_64_10) /*z*/)));
}

inline float4 linear_to_SRGB_30ee3e123c55a357 ( Context * __context__, float4 __c_rename_at_67_11 )
{
	return das_auto_cast<float4>::cast(float4(linear_to_SRGB_eedb6de51617a75(__context__,v_extract_x(__c_rename_at_67_11) /*x*/),linear_to_SRGB_eedb6de51617a75(__context__,v_extract_y(__c_rename_at_67_11) /*y*/),linear_to_SRGB_eedb6de51617a75(__context__,v_extract_z(__c_rename_at_67_11) /*z*/),v_extract_w(__c_rename_at_67_11) /*w*/));
}

inline bool is_intersecting_519f106fdec1d140 ( Context * __context__, math_boost::AABR const  &  __a_rename_at_70_12, math_boost::AABR const  &  __b_rename_at_70_13 )
{
	return das_auto_cast<bool>::cast((((v_extract_x(__a_rename_at_70_12.min) /*x*/ <= v_extract_x(__b_rename_at_70_13.max) /*x*/) && (v_extract_y(__a_rename_at_70_12.min) /*y*/ <= v_extract_y(__b_rename_at_70_13.max) /*y*/)) && (v_extract_x(__a_rename_at_70_12.max) /*x*/ >= v_extract_x(__b_rename_at_70_13.min) /*x*/)) && (v_extract_y(__a_rename_at_70_12.max) /*y*/ >= v_extract_y(__b_rename_at_70_13.min) /*y*/));
}

inline bool is_intersecting_76dc5cb27b1cce20 ( Context * __context__, math_boost::AABB const  &  __a_rename_at_75_14, math_boost::AABB const  &  __b_rename_at_75_15 )
{
	return das_auto_cast<bool>::cast((((((v_extract_x(__a_rename_at_75_14.min) /*x*/ <= v_extract_x(__b_rename_at_75_15.max) /*x*/) && (v_extract_y(__a_rename_at_75_14.min) /*y*/ <= v_extract_y(__b_rename_at_75_15.max) /*y*/)) && (v_extract_z(__a_rename_at_75_14.min) /*z*/ <= v_extract_z(__b_rename_at_75_15.max) /*z*/)) && (v_extract_x(__a_rename_at_75_14.max) /*x*/ >= v_extract_x(__b_rename_at_75_15.min) /*x*/)) && (v_extract_y(__a_rename_at_75_14.max) /*y*/ >= v_extract_y(__b_rename_at_75_15.min) /*y*/)) && (v_extract_z(__a_rename_at_75_14.max) /*z*/ >= v_extract_z(__b_rename_at_75_15.min) /*z*/));
}

inline bool is_intersecting_83c244c5cad1eaf9 ( Context * __context__, math_boost::Ray const  &  __ray_rename_at_79_16, math_boost::AABB const  &  __aabb_rename_at_79_17, float __Tmin_rename_at_79_18, float __Tmax_rename_at_79_19 )
{
	float3 __invD_rename_at_80_20 = ((float3)SimPolicy<float3>::Rcp(__ray_rename_at_79_16.dir,*__context__,nullptr));
	float3 __t0s_rename_at_81_21 = ((float3)(SimPolicy<float3>::Mul((SimPolicy<float3>::Sub(__aabb_rename_at_79_17.min,__ray_rename_at_79_16.origin,*__context__,nullptr)),__invD_rename_at_80_20,*__context__,nullptr)));
	float3 __t1s_rename_at_82_22 = ((float3)(SimPolicy<float3>::Mul((SimPolicy<float3>::Sub(__aabb_rename_at_79_17.max,__ray_rename_at_79_16.origin,*__context__,nullptr)),__invD_rename_at_80_20,*__context__,nullptr)));
	float3 __tsmaller_rename_at_83_23 = ((float3)SimPolicy<float3>::Min(__t0s_rename_at_81_21,__t1s_rename_at_82_22,*__context__,nullptr));
	float3 __tbigger_rename_at_84_24 = ((float3)SimPolicy<float3>::Max(__t0s_rename_at_81_21,__t1s_rename_at_82_22,*__context__,nullptr));
	float __tmin_rename_at_85_25 = ((float)SimPolicy<float>::Max(__Tmin_rename_at_79_18,SimPolicy<float>::Max(das_index<float3 const >::at(__tsmaller_rename_at_83_23,0,__context__),SimPolicy<float>::Max(das_index<float3 const >::at(__tsmaller_rename_at_83_23,1,__context__),das_index<float3 const >::at(__tsmaller_rename_at_83_23,2,__context__),*__context__,nullptr),*__context__,nullptr),*__context__,nullptr));
	float __tmax_rename_at_86_26 = ((float)SimPolicy<float>::Min(__Tmax_rename_at_79_19,SimPolicy<float>::Min(das_index<float3 const >::at(__tbigger_rename_at_84_24,0,__context__),SimPolicy<float>::Min(das_index<float3 const >::at(__tbigger_rename_at_84_24,1,__context__),das_index<float3 const >::at(__tbigger_rename_at_84_24,2,__context__),*__context__,nullptr),*__context__,nullptr),*__context__,nullptr));
	return das_auto_cast<bool>::cast(__tmin_rename_at_85_25 < __tmax_rename_at_86_26);
}

inline float4x4 look_at_lh_12ae4d22ab712b1 ( Context * __context__, float3 __Eye_rename_at_89_27, float3 __At_rename_at_89_28, float3 __Up_rename_at_89_29 )
{
	float3 __zaxis_rename_at_91_30 = ((float3)safe_normalize3(SimPolicy<float3>::Sub(__At_rename_at_89_28,__Eye_rename_at_89_27,*__context__,nullptr)));
	float3 __xaxis_rename_at_92_31 = ((float3)safe_normalize3(cross3(__Up_rename_at_89_29,__zaxis_rename_at_91_30)));
	float3 __yaxis_rename_at_93_32 = ((float3)cross3(__zaxis_rename_at_91_30,__xaxis_rename_at_92_31));
	float4x4 __tm_rename_at_94_33; das_zero(__tm_rename_at_94_33);
	das_copy(das_index<float4x4>::at(__tm_rename_at_94_33,0,__context__),float4(v_extract_x(__xaxis_rename_at_92_31) /*x*/,v_extract_x(__yaxis_rename_at_93_32) /*x*/,v_extract_x(__zaxis_rename_at_91_30) /*x*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_94_33,1,__context__),float4(v_extract_y(__xaxis_rename_at_92_31) /*y*/,v_extract_y(__yaxis_rename_at_93_32) /*y*/,v_extract_y(__zaxis_rename_at_91_30) /*y*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_94_33,2,__context__),float4(v_extract_z(__xaxis_rename_at_92_31) /*z*/,v_extract_z(__yaxis_rename_at_93_32) /*z*/,v_extract_z(__zaxis_rename_at_91_30) /*z*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_94_33,3,__context__),float4(-dot3(__xaxis_rename_at_92_31,__Eye_rename_at_89_27),-dot3(__yaxis_rename_at_93_32,__Eye_rename_at_89_27),-dot3(__zaxis_rename_at_91_30,__Eye_rename_at_89_27),1.f));
	return das_auto_cast_ref<float4x4>::cast(__tm_rename_at_94_33);
}

inline float4x4 look_at_rh_57fabbbe8b8576f7 ( Context * __context__, float3 __Eye_rename_at_103_34, float3 __At_rename_at_103_35, float3 __Up_rename_at_103_36 )
{
	float3 __zaxis_rename_at_105_37 = ((float3)safe_normalize3(SimPolicy<float3>::Sub(__Eye_rename_at_103_34,__At_rename_at_103_35,*__context__,nullptr)));
	float3 __xaxis_rename_at_106_38 = ((float3)safe_normalize3(cross3(__Up_rename_at_103_36,__zaxis_rename_at_105_37)));
	float3 __yaxis_rename_at_107_39 = ((float3)cross3(__zaxis_rename_at_105_37,__xaxis_rename_at_106_38));
	float4x4 __tm_rename_at_108_40; das_zero(__tm_rename_at_108_40);
	das_copy(das_index<float4x4>::at(__tm_rename_at_108_40,0,__context__),float4(v_extract_x(__xaxis_rename_at_106_38) /*x*/,v_extract_x(__yaxis_rename_at_107_39) /*x*/,v_extract_x(__zaxis_rename_at_105_37) /*x*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_108_40,1,__context__),float4(v_extract_y(__xaxis_rename_at_106_38) /*y*/,v_extract_y(__yaxis_rename_at_107_39) /*y*/,v_extract_y(__zaxis_rename_at_105_37) /*y*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_108_40,2,__context__),float4(v_extract_z(__xaxis_rename_at_106_38) /*z*/,v_extract_z(__yaxis_rename_at_107_39) /*z*/,v_extract_z(__zaxis_rename_at_105_37) /*z*/,0.f));
	das_copy(das_index<float4x4>::at(__tm_rename_at_108_40,3,__context__),float4(-dot3(__xaxis_rename_at_106_38,__Eye_rename_at_103_34),-dot3(__yaxis_rename_at_107_39,__Eye_rename_at_103_34),-dot3(__zaxis_rename_at_105_37,__Eye_rename_at_103_34),1.f));
	return das_auto_cast_ref<float4x4>::cast(__tm_rename_at_108_40);
}

inline float4x4 perspective_lh_2fac1cd2df0ab7fe ( Context * __context__, float __fovy_rename_at_117_41, float __aspect_rename_at_117_42, float __zn_rename_at_117_43, float __zf_rename_at_117_44 )
{
	float __yScale_rename_at_119_45 = ((float)(SimPolicy<float>::Div(1.f,SimPolicy<float>::Tan(SimPolicy<float>::Div(__fovy_rename_at_117_41,2.f,*__context__,nullptr),*__context__,nullptr),*__context__,nullptr)));
	float __xScale_rename_at_120_46 = ((float)(SimPolicy<float>::Div(__yScale_rename_at_119_45,__aspect_rename_at_117_42,*__context__,nullptr)));
	float4x4 __Result_rename_at_121_47; das_zero(__Result_rename_at_121_47);
	float4x4_identity(das_arg<float4x4>::pass(__Result_rename_at_121_47));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_121_47,0,__context__),0,__context__),__xScale_rename_at_120_46);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_121_47,1,__context__),1,__context__),__yScale_rename_at_119_45);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_121_47,2,__context__),2,__context__),SimPolicy<float>::Div(__zf_rename_at_117_44,(__zf_rename_at_117_44 - __zn_rename_at_117_43),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_121_47,2,__context__),3,__context__),-1.f);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_121_47,3,__context__),2,__context__),SimPolicy<float>::Div((-__zn_rename_at_117_43 * __zf_rename_at_117_44),(__zn_rename_at_117_43 - __zf_rename_at_117_44),*__context__,nullptr));
	return das_auto_cast_ref<float4x4>::cast(__Result_rename_at_121_47);
}

inline float4x4 perspective_rh_5d20db61257b5b19 ( Context * __context__, float __fovy_rename_at_130_48, float __aspect_rename_at_130_49, float __zn_rename_at_130_50, float __zf_rename_at_130_51 )
{
	float __yScale_rename_at_132_52 = ((float)(SimPolicy<float>::Div(1.f,SimPolicy<float>::Tan(SimPolicy<float>::Div(__fovy_rename_at_130_48,2.f,*__context__,nullptr),*__context__,nullptr),*__context__,nullptr)));
	float __xScale_rename_at_133_53 = ((float)(SimPolicy<float>::Div(__yScale_rename_at_132_52,__aspect_rename_at_130_49,*__context__,nullptr)));
	float4x4 __Result_rename_at_134_54; das_zero(__Result_rename_at_134_54);
	float4x4_identity(das_arg<float4x4>::pass(__Result_rename_at_134_54));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_134_54,0,__context__),0,__context__),__xScale_rename_at_133_53);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_134_54,1,__context__),1,__context__),__yScale_rename_at_132_52);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_134_54,2,__context__),2,__context__),SimPolicy<float>::Div(__zf_rename_at_130_51,(__zn_rename_at_130_50 - __zf_rename_at_130_51),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_134_54,2,__context__),3,__context__),-1.f);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_134_54,3,__context__),2,__context__),SimPolicy<float>::Div((__zn_rename_at_130_50 * __zf_rename_at_130_51),(__zn_rename_at_130_50 - __zf_rename_at_130_51),*__context__,nullptr));
	return das_auto_cast_ref<float4x4>::cast(__Result_rename_at_134_54);
}

inline float4x4 perspective_rh_opengl_fcf6139ab08387ca ( Context * __context__, float __fovy_rename_at_143_55, float __aspect_rename_at_143_56, float __zn_rename_at_143_57, float __zf_rename_at_143_58 )
{
	float __yScale_rename_at_145_59 = ((float)(SimPolicy<float>::Div(1.f,SimPolicy<float>::Tan(SimPolicy<float>::Div(__fovy_rename_at_143_55,2.f,*__context__,nullptr),*__context__,nullptr),*__context__,nullptr)));
	float __xScale_rename_at_146_60 = ((float)(SimPolicy<float>::Div(__yScale_rename_at_145_59,__aspect_rename_at_143_56,*__context__,nullptr)));
	float4x4 __Result_rename_at_147_61; das_zero(__Result_rename_at_147_61);
	float4x4_identity(das_arg<float4x4>::pass(__Result_rename_at_147_61));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_147_61,0,__context__),0,__context__),__xScale_rename_at_146_60);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_147_61,1,__context__),1,__context__),__yScale_rename_at_145_59);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_147_61,2,__context__),2,__context__),SimPolicy<float>::Div((__zf_rename_at_143_58 + __zn_rename_at_143_57),(__zn_rename_at_143_57 - __zf_rename_at_143_58),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_147_61,2,__context__),3,__context__),-1.f);
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_147_61,3,__context__),2,__context__),SimPolicy<float>::Div(((__zn_rename_at_143_57 * 2.f) * __zf_rename_at_143_58),(__zn_rename_at_143_57 - __zf_rename_at_143_58),*__context__,nullptr));
	return das_auto_cast_ref<float4x4>::cast(__Result_rename_at_147_61);
}

inline float4x4 ortho_rh_f6bc4f195f22d8d5 ( Context * __context__, float __left_rename_at_156_62, float __right_rename_at_156_63, float __bottom_rename_at_156_64, float __top_rename_at_156_65, float __zNear_rename_at_156_66, float __zFar_rename_at_156_67 )
{
	float4x4 __Result_rename_at_158_68; das_zero(__Result_rename_at_158_68);
	float4x4_identity(das_arg<float4x4>::pass(__Result_rename_at_158_68));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,0,__context__),0,__context__),SimPolicy<float>::Div(2.f,(__right_rename_at_156_63 - __left_rename_at_156_62),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,1,__context__),1,__context__),SimPolicy<float>::Div(2.f,(__top_rename_at_156_65 - __bottom_rename_at_156_64),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,2,__context__),2,__context__),SimPolicy<float>::Div(-2.f,(__zFar_rename_at_156_67 - __zNear_rename_at_156_66),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,3,__context__),0,__context__),SimPolicy<float>::Div(-((__right_rename_at_156_63 + __left_rename_at_156_62)),(__right_rename_at_156_63 - __left_rename_at_156_62),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,3,__context__),1,__context__),SimPolicy<float>::Div(-((__top_rename_at_156_65 + __bottom_rename_at_156_64)),(__top_rename_at_156_65 - __bottom_rename_at_156_64),*__context__,nullptr));
	das_copy(das_index<float4>::at(das_index<float4x4>::at(__Result_rename_at_158_68,3,__context__),2,__context__),SimPolicy<float>::Div(-((__zFar_rename_at_156_67 + __zNear_rename_at_156_66)),(__zFar_rename_at_156_67 - __zNear_rename_at_156_66),*__context__,nullptr));
	return das_auto_cast_ref<float4x4>::cast(__Result_rename_at_158_68);
}

inline float plane_dot_cf6fadebd33ebe09 ( Context * __context__, float4 __Plane_rename_at_168_69, float4 __Vec_rename_at_168_70 )
{
	return das_auto_cast<float>::cast(dot4(__Plane_rename_at_168_69,__Vec_rename_at_168_70));
}

inline float4 plane_normalize_bcd7d36c68415690 ( Context * __context__, float4 __Plane_rename_at_172_71 )
{
	float __len_rename_at_174_72 = ((float)length3(das_swizzle_seq<float3,float4 const ,0>::swizzle(__Plane_rename_at_172_71) /*xyz*/));
	return das_auto_cast<float4>::cast((__len_rename_at_174_72 != 0.f) ? (vec4f)das_auto_cast<float4>::cast((SimPolicy<float4>::DivVecScal(__Plane_rename_at_172_71,cast<float>::from(__len_rename_at_174_72),*__context__,nullptr))) : (vec4f)das_auto_cast<float4>::cast(v_zero()));
}

inline float4 plane_from_point_normal_110b03e9793d1239 ( Context * __context__, float3 __p_rename_at_177_73, float3 __n_rename_at_177_74 )
{
	return das_auto_cast<float4>::cast(float4(v_extract_x(__n_rename_at_177_74) /*x*/,v_extract_y(__n_rename_at_177_74) /*y*/,v_extract_z(__n_rename_at_177_74) /*z*/,-dot3(__p_rename_at_177_73,__n_rename_at_177_74)));
}

inline float4x4 planar_shadow_304637f7a6dac3fe ( Context * __context__, float4 __Light_rename_at_181_75, float4 __Plane_rename_at_181_76 )
{
	float4 __P_rename_at_183_77 = ((float4)plane_normalize_bcd7d36c68415690(__context__,__Plane_rename_at_181_76));
	float4 __L_rename_at_184_78 = ((float4)__Light_rename_at_181_75);
	float __d_rename_at_185_79 = ((float)-(dot4(__P_rename_at_183_77,__L_rename_at_184_78)));
	float4x4 __Result_rename_at_186_80; das_zero(__Result_rename_at_186_80);
	das_copy(das_index<float4x4>::at(__Result_rename_at_186_80,0,__context__),float4((v_extract_x(__P_rename_at_183_77) /*x*/ * v_extract_x(__L_rename_at_184_78) /*x*/) + __d_rename_at_185_79,v_extract_x(__P_rename_at_183_77) /*x*/ * v_extract_y(__L_rename_at_184_78) /*y*/,v_extract_x(__P_rename_at_183_77) /*x*/ * v_extract_z(__L_rename_at_184_78) /*z*/,v_extract_x(__P_rename_at_183_77) /*x*/ * v_extract_w(__L_rename_at_184_78) /*w*/));
	das_copy(das_index<float4x4>::at(__Result_rename_at_186_80,1,__context__),float4(v_extract_y(__P_rename_at_183_77) /*y*/ * v_extract_x(__L_rename_at_184_78) /*x*/,(v_extract_y(__P_rename_at_183_77) /*y*/ * v_extract_y(__L_rename_at_184_78) /*y*/) + __d_rename_at_185_79,v_extract_y(__P_rename_at_183_77) /*y*/ * v_extract_z(__L_rename_at_184_78) /*z*/,v_extract_y(__P_rename_at_183_77) /*y*/ * v_extract_w(__L_rename_at_184_78) /*w*/));
	das_copy(das_index<float4x4>::at(__Result_rename_at_186_80,2,__context__),float4(v_extract_z(__P_rename_at_183_77) /*z*/ * v_extract_x(__L_rename_at_184_78) /*x*/,v_extract_z(__P_rename_at_183_77) /*z*/ * v_extract_y(__L_rename_at_184_78) /*y*/,(v_extract_z(__P_rename_at_183_77) /*z*/ * v_extract_z(__L_rename_at_184_78) /*z*/) + __d_rename_at_185_79,v_extract_z(__P_rename_at_183_77) /*z*/ * v_extract_w(__L_rename_at_184_78) /*w*/));
	das_copy(das_index<float4x4>::at(__Result_rename_at_186_80,3,__context__),float4(v_extract_w(__P_rename_at_183_77) /*w*/ * v_extract_x(__L_rename_at_184_78) /*x*/,v_extract_w(__P_rename_at_183_77) /*w*/ * v_extract_y(__L_rename_at_184_78) /*y*/,v_extract_w(__P_rename_at_183_77) /*w*/ * v_extract_z(__L_rename_at_184_78) /*z*/,(v_extract_w(__P_rename_at_183_77) /*w*/ * v_extract_w(__L_rename_at_184_78) /*w*/) + __d_rename_at_185_79));
	return das_auto_cast_ref<float4x4>::cast(__Result_rename_at_186_80);
}

static void registerAotFunctions ( AotLibrary & aotLib ) {
	// degrees_a661e6cfff0d8952
	aotLib[0x2ee5617839c80503] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float (*) ( Context * __context__, float  ),&degrees_a661e6cfff0d8952>>();
	};
	// radians_aa78c69bde52354a
	aotLib[0x8097b19889f6f743] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float (*) ( Context * __context__, float  ),&radians_aa78c69bde52354a>>();
	};
	// RGBA_TO_UCOLOR_f52d3d498ec28ea4
	aotLib[0xbe5a92268add91bc] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__, float , float , float , float  ),&RGBA_TO_UCOLOR_f52d3d498ec28ea4>>();
	};
	// RGBA_TO_UCOLOR_fb5992436af224c9
	aotLib[0x6616ece0cec99afb] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<uint32_t (*) ( Context * __context__, float4  ),&RGBA_TO_UCOLOR_fb5992436af224c9>>();
	};
	// UCOLOR_TO_RGBA_df3b1693521d201f
	aotLib[0xf7127e2849275d81] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float4 (*) ( Context * __context__, uint32_t  ),&UCOLOR_TO_RGBA_df3b1693521d201f>>();
	};
	// UCOLOR_TO_RGB_1557f9cd645f174a
	aotLib[0x9106d878cc3f859b] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float3 (*) ( Context * __context__, uint32_t  ),&UCOLOR_TO_RGB_1557f9cd645f174a>>();
	};
	// linear_to_SRGB_eedb6de51617a75
	aotLib[0x4b41e11493a96c91] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float (*) ( Context * __context__, float  ),&linear_to_SRGB_eedb6de51617a75>>();
	};
	// linear_to_SRGB_5492768924fd03c3
	aotLib[0xc69f026144784982] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float3 (*) ( Context * __context__, float3  ),&linear_to_SRGB_5492768924fd03c3>>();
	};
	// linear_to_SRGB_30ee3e123c55a357
	aotLib[0xa6a0cb8005a3268e] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float4 (*) ( Context * __context__, float4  ),&linear_to_SRGB_30ee3e123c55a357>>();
	};
	// is_intersecting_519f106fdec1d140
	aotLib[0x4c9ea1930bbe2b49] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, math_boost::AABR const  & , math_boost::AABR const  &  ),&is_intersecting_519f106fdec1d140>>();
	};
	// is_intersecting_76dc5cb27b1cce20
	aotLib[0x77b5d8071cf07797] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, math_boost::AABB const  & , math_boost::AABB const  &  ),&is_intersecting_76dc5cb27b1cce20>>();
	};
	// is_intersecting_83c244c5cad1eaf9
	aotLib[0x9b1315bba3a71b01] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<bool (*) ( Context * __context__, math_boost::Ray const  & , math_boost::AABB const  & , float , float  ),&is_intersecting_83c244c5cad1eaf9>>();
	};
	// look_at_lh_12ae4d22ab712b1
	aotLib[0xa40516ac8935dca8] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float3 , float3 , float3  ),&look_at_lh_12ae4d22ab712b1>>();
	};
	// look_at_rh_57fabbbe8b8576f7
	aotLib[0x5f7cd33634f15b97] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float3 , float3 , float3  ),&look_at_rh_57fabbbe8b8576f7>>();
	};
	// perspective_lh_2fac1cd2df0ab7fe
	aotLib[0xb263618c6859de55] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float , float , float , float  ),&perspective_lh_2fac1cd2df0ab7fe>>();
	};
	// perspective_rh_5d20db61257b5b19
	aotLib[0xa27bb976e9c07ce4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float , float , float , float  ),&perspective_rh_5d20db61257b5b19>>();
	};
	// perspective_rh_opengl_fcf6139ab08387ca
	aotLib[0xd7bfcfd6d2fe2618] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float , float , float , float  ),&perspective_rh_opengl_fcf6139ab08387ca>>();
	};
	// ortho_rh_f6bc4f195f22d8d5
	aotLib[0x4c2e2f12a1115a2a] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float , float , float , float , float , float  ),&ortho_rh_f6bc4f195f22d8d5>>();
	};
	// plane_dot_cf6fadebd33ebe09
	aotLib[0x84f8930f974df0b4] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float (*) ( Context * __context__, float4 , float4  ),&plane_dot_cf6fadebd33ebe09>>();
	};
	// plane_normalize_bcd7d36c68415690
	aotLib[0x987c4305692375f0] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float4 (*) ( Context * __context__, float4  ),&plane_normalize_bcd7d36c68415690>>();
	};
	// plane_from_point_normal_110b03e9793d1239
	aotLib[0xf15fffcd49a4baa9] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_Aot<float4 (*) ( Context * __context__, float3 , float3  ),&plane_from_point_normal_110b03e9793d1239>>();
	};
	// planar_shadow_304637f7a6dac3fe
	aotLib[0x195553ad422a5ed2] = [&](Context & ctx){
		return ctx.code->makeNode<SimNode_AotCMRES<float4x4 (*) ( Context * __context__, float4 , float4  ),&planar_shadow_304637f7a6dac3fe>>();
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
