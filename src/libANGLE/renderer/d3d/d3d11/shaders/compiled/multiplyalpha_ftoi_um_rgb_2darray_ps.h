#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// Sampler                           sampler      NA          NA             s0      1 
// TextureF_2DArray                  texture  float4     2darray             t0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// SV_RENDERTARGETARRAYINDEX     0   x           1  RTINDEX    uint   x   
// TEXCOORD                 0   xyz         2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TARGET                0   xyzw        0   TARGET     int   xyzw
//
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2darray (float,float,float,float) t0
dcl_input_ps_siv constant v1.x, rendertarget_array_index
dcl_input_ps linear v2.xy
dcl_output o0.xyzw
dcl_temps 2
utof r0.z, v1.x
mov r0.xy, v2.xyxx
sample r0.xyzw, r0.xyzx, t0.xyzw, s0
lt r1.x, l(0.000000), r0.w
div r1.yzw, r0.xxyz, r0.wwww
movc r0.xyz, r1.xxxx, r1.yzwy, r0.xyzx
mul r0.xyz, r0.xyzx, l(127.000000, 127.000000, 127.000000, 0.000000)
round_ne r0.xyz, r0.xyzx
mul r0.xyz, r0.xyzx, l(1.000000, 1.000000, 1.000000, 0.000000)
ftoi o0.xyz, r0.xyzx
mov o0.w, l(1)
ret 
// Approximately 12 instruction slots used
#endif

const BYTE g_PS_FtoI_UM_RGB_2DArray[] = {
    68,  88,  66,  67,  229, 156, 153, 172, 30,  111, 168, 172, 47,  75,  227, 206, 198, 78,  62,
    42,  1,   0,   0,   0,   168, 3,   0,   0,   5,   0,   0,   0,   52,  0,   0,   0,   220, 0,
    0,   0,   100, 1,   0,   0,   152, 1,   0,   0,   44,  3,   0,   0,   82,  68,  69,  70,  160,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   28,  0,   0,   0,
    0,   4,   255, 255, 0,   1,   0,   0,   117, 0,   0,   0,   92,  0,   0,   0,   3,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,
    0,   0,   1,   0,   0,   0,   100, 0,   0,   0,   2,   0,   0,   0,   5,   0,   0,   0,   5,
    0,   0,   0,   255, 255, 255, 255, 0,   0,   0,   0,   1,   0,   0,   0,   13,  0,   0,   0,
    83,  97,  109, 112, 108, 101, 114, 0,   84,  101, 120, 116, 117, 114, 101, 70,  95,  50,  68,
    65,  114, 114, 97,  121, 0,   77,  105, 99,  114, 111, 115, 111, 102, 116, 32,  40,  82,  41,
    32,  72,  76,  83,  76,  32,  83,  104, 97,  100, 101, 114, 32,  67,  111, 109, 112, 105, 108,
    101, 114, 32,  49,  48,  46,  49,  0,   171, 171, 171, 73,  83,  71,  78,  128, 0,   0,   0,
    3,   0,   0,   0,   8,   0,   0,   0,   80,  0,   0,   0,   0,   0,   0,   0,   1,   0,   0,
    0,   3,   0,   0,   0,   0,   0,   0,   0,   15,  0,   0,   0,   92,  0,   0,   0,   0,   0,
    0,   0,   4,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   1,   0,   0,   118,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   0,   0,   0,   2,   0,   0,   0,
    7,   3,   0,   0,   83,  86,  95,  80,  79,  83,  73,  84,  73,  79,  78,  0,   83,  86,  95,
    82,  69,  78,  68,  69,  82,  84,  65,  82,  71,  69,  84,  65,  82,  82,  65,  89,  73,  78,
    68,  69,  88,  0,   84,  69,  88,  67,  79,  79,  82,  68,  0,   171, 79,  83,  71,  78,  44,
    0,   0,   0,   1,   0,   0,   0,   8,   0,   0,   0,   32,  0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   15,  0,   0,   0,   83,  86,  95,
    84,  65,  82,  71,  69,  84,  0,   171, 171, 83,  72,  68,  82,  140, 1,   0,   0,   64,  0,
    0,   0,   99,  0,   0,   0,   90,  0,   0,   3,   0,   96,  16,  0,   0,   0,   0,   0,   88,
    64,  0,   4,   0,   112, 16,  0,   0,   0,   0,   0,   85,  85,  0,   0,   100, 8,   0,   4,
    18,  16,  16,  0,   1,   0,   0,   0,   4,   0,   0,   0,   98,  16,  0,   3,   50,  16,  16,
    0,   2,   0,   0,   0,   101, 0,   0,   3,   242, 32,  16,  0,   0,   0,   0,   0,   104, 0,
    0,   2,   2,   0,   0,   0,   86,  0,   0,   5,   66,  0,   16,  0,   0,   0,   0,   0,   10,
    16,  16,  0,   1,   0,   0,   0,   54,  0,   0,   5,   50,  0,   16,  0,   0,   0,   0,   0,
    70,  16,  16,  0,   2,   0,   0,   0,   69,  0,   0,   9,   242, 0,   16,  0,   0,   0,   0,
    0,   70,  2,   16,  0,   0,   0,   0,   0,   70,  126, 16,  0,   0,   0,   0,   0,   0,   96,
    16,  0,   0,   0,   0,   0,   49,  0,   0,   7,   18,  0,   16,  0,   1,   0,   0,   0,   1,
    64,  0,   0,   0,   0,   0,   0,   58,  0,   16,  0,   0,   0,   0,   0,   14,  0,   0,   7,
    226, 0,   16,  0,   1,   0,   0,   0,   6,   9,   16,  0,   0,   0,   0,   0,   246, 15,  16,
    0,   0,   0,   0,   0,   55,  0,   0,   9,   114, 0,   16,  0,   0,   0,   0,   0,   6,   0,
    16,  0,   1,   0,   0,   0,   150, 7,   16,  0,   1,   0,   0,   0,   70,  2,   16,  0,   0,
    0,   0,   0,   56,  0,   0,   10,  114, 0,   16,  0,   0,   0,   0,   0,   70,  2,   16,  0,
    0,   0,   0,   0,   2,   64,  0,   0,   0,   0,   254, 66,  0,   0,   254, 66,  0,   0,   254,
    66,  0,   0,   0,   0,   64,  0,   0,   5,   114, 0,   16,  0,   0,   0,   0,   0,   70,  2,
    16,  0,   0,   0,   0,   0,   56,  0,   0,   10,  114, 0,   16,  0,   0,   0,   0,   0,   70,
    2,   16,  0,   0,   0,   0,   0,   2,   64,  0,   0,   0,   0,   128, 63,  0,   0,   128, 63,
    0,   0,   128, 63,  0,   0,   0,   0,   27,  0,   0,   5,   114, 32,  16,  0,   0,   0,   0,
    0,   70,  2,   16,  0,   0,   0,   0,   0,   54,  0,   0,   5,   130, 32,  16,  0,   0,   0,
    0,   0,   1,   64,  0,   0,   1,   0,   0,   0,   62,  0,   0,   1,   83,  84,  65,  84,  116,
    0,   0,   0,   12,  0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   3,   0,   0,   0,
    5,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   2,   0,   0,   0,   1,   0,   0,   0,   3,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0};
