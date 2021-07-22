add_library(libanglebuild INTERFACE)
add_library(tg_angle::libanglebuild ALIAS libanglebuild)

target_compile_definitions(libanglebuild
INTERFACE
    $<$<CONFIG:Debug>:ANGLE_GENERATE_SHADER_DEBUG_INFO>
    $<$<CONFIG:Debug>:ANGLE_ENABLE_DEBUG_ANNOTATIONS>
    LIBANGLE_IMPLEMENTATION
    ANGLE_FORCE_CONTEXT_CHECK_EVERY_CALL=1
    ANGLE_ENABLE_OPENGL
    ANGLE_ENABLE_OPENGL_DESKTOP
    ANGLE_ENABLE_GLSL
    ANGLE_CAPTURE_ENABLED=0
    ANGLE_EXPORT=
    ANGLE_STATIC=1
    ANGLE_UTIL_EXPORT=
    EGLAPI=
    GL_APICALL=
    GL_API=
    XXH_INLINE_ALL
)

if (CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_compile_definitions(libanglebuild
    INTERFACE
        ANGLE_IS_32_BIT_CPU
    )
else()
    target_compile_definitions(libanglebuild
    INTERFACE
        ANGLE_IS_64_BIT_CPU
    )
endif()

if (WIN32)
    target_compile_definitions(libanglebuild
    INTERFACE
        ANGLE_IS_WIN
        ANGLE_DEFAULT_D3D11=1
        ANGLE_ENABLE_D3D11
        ANGLE_ENABLE_D3D11_COMPOSITOR_NATIVE_WINDOW
        ANGLE_ENABLE_D3D9
        "ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES={ \"d3dcompiler_47.dll\", \"d3dcompiler_46.dll\", \"d3dcompiler_43.dll\" }"
        ANGLE_ENABLE_HLSL
        _ATL_NO_OPENGL
    )
elseif (APPLE)
    target_compile_definitions(libanglebuild
    INTERFACE
    )
else()
    target_compile_definitions(libanglebuild
    INTERFACE
    )
endif()

target_include_directories(libanglebuild
INTERFACE
    ${angle_loc}
    ${angle_include_loc}
    ${angle_loc}/common/third_party/base
    ${angle_loc}/third_party/khronos
    ${third_party_loc}/zlib/google
)
