cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0091 NEW)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(TG_ANGLE_SPECIAL_TARGET "" CACHE STRING "Use special platform target, like 'macstore' for Mac App Store.")

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11 CACHE STRING "Minimum OS X deployment version" FORCE)

if (NOT TG_ANGLE_SPECIAL_TARGET STREQUAL "")
    set(TG_ANGLE_PACKAGED_BUILD 0)
else()
    set(TG_ANGLE_PACKAGED_BUILD 1)
endif()

set(not_packaged_build 0)
if (NOT TG_ANGLE_PACKAGED_BUILD)
    set(not_packaged_build 1)
endif()

option(BUILD_SHARED_LIBS "Builds shared libraries instead of static." ${TG_ANGLE_PACKAGED_BUILD})

if (BUILD_SHARED_LIBS)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

project(tg_angle
    LANGUAGES C CXX ASM
    DESCRIPTION "ANGLE build for Telegram"
    HOMEPAGE_URL "https://github.com/desktop-app/tg_angle.git"
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tg_angle)

get_filename_component(angle_loc "src" REALPATH)
get_filename_component(angle_include_loc "include" REALPATH)
get_filename_component(third_party_loc "third_party" REALPATH)

if (CMAKE_OSX_ARCHITECTURES STREQUAL "arm64")
    set(is_aarch64 1)
    set(arm_use_neon 1)
else()
    if(CMAKE_OSX_ARCHITECTURES STREQUAL "x86_64")
        set(is_x64 1)
    else()
        include(cmake/arch.cmake)
    endif()
endif()

include(cmake/nice_target_sources.cmake)
include(cmake/init_target.cmake)
include(cmake/external.cmake)
include(cmake/generate_target.cmake)
include(cmake/generate_commit_id.cmake)
include(cmake/generate_version.cmake)

add_library(tg_angle)
init_target(tg_angle)

link_zlib(tg_angle)

set_target_properties(tg_angle PROPERTIES SOVERSION 0 VERSION 0.0.0)

include(cmake/libanglebuild.cmake)
target_link_libraries(tg_angle PUBLIC tg_angle::libanglebuild)

nice_target_sources(tg_angle ${third_party_loc}
PRIVATE
    zlib/google/compression_utils_portable.cc
    zlib/google/compression_utils_portable.h
)

nice_target_sources(tg_angle ${angle_include_loc}
PRIVATE
    angle_gl.h
    export.h
    EGL/egl.h
    EGL/eglext.h
    EGL/eglext_angle.h
    EGL/eglplatform.h
    GLES/gl.h
    GLES/glplatform.h
    GLES/glext.h
    GLES2/gl2.h
    GLES2/gl2ext.h
    GLES2/gl2ext_angle.h
    GLES2/gl2platform.h
    GLES3/gl3.h
    GLES3/gl3platform.h
    GLES3/gl31.h
    GLES3/gl32.h
    KHR/khrplatform.h
    WGL/wgl.h
    platform/Feature.h
    platform/FeaturesD3D_autogen.h
    platform/FeaturesGL_autogen.h
    platform/FeaturesMtl_autogen.h
    platform/FeaturesVk_autogen.h
    platform/FrontendFeatures_autogen.h
    platform/PlatformMethods.h
    vulkan/vulkan_fuchsia_ext.h
)

nice_target_sources(tg_angle ${angle_loc}
PRIVATE
    common/aligned_memory.cpp
    common/aligned_memory.h
    # common/aligned_memory_unittest.cpp
    common/android_util.cpp
    common/android_util.h
    common/angleutils.cpp
    common/angleutils.h
    # common/angleutils_unittest.cpp
    common/angle_version.h
    common/angle_version_info.cpp
    common/angle_version_info.h
    # common/apple_platform_utils.h
    # common/apple_platform_utils.mm
    common/backtrace_utils.h
    # common/backtrace_utils_android.cpp
    common/backtrace_utils_noop.cpp
    common/BinaryStream.h
    # common/BinaryStream_unittest.cpp
    common/bitset_utils.h
    # common/bitset_utils_unittest.cpp
    common/CircularBuffer.h
    # common/CircularBuffer_unittest.cpp
    common/Color.h
    common/Color.inc
    common/CompiledShaderState.cpp
    common/CompiledShaderState.h
    common/debug.cpp
    common/debug.h
    common/entry_points_enum_autogen.cpp
    common/entry_points_enum_autogen.h
    common/event_tracer.cpp
    common/event_tracer.h
    common/FastVector.h
    # common/FastVector_unittest.cpp
    common/FixedQueue.h
    # common/FixedQueue_unittest.cpp
    common/FixedVector.h
    # common/FixedVector_unittest.cpp
    common/Float16ToFloat32.cpp
    # common/Float16ToFloat32.py
    # common/frame_capture_utils.cpp
    # common/frame_capture_utils.h
    common/frame_capture_utils_autogen.cpp
    common/frame_capture_utils_autogen.h
    # common/gen_packed_gl_enums.py
    # common/gen_uniform_type_table.py
    common/gl_enum_utils.cpp
    common/gl_enum_utils.h
    common/gl_enum_utils_autogen.cpp
    common/gl_enum_utils_autogen.h
    common/hash_utils.h
    # common/hash_utils_unittest.cpp
    common/mathutil.cpp
    common/mathutil.h
    # common/mathutil_unittest.cpp
    common/matrix_utils.cpp
    common/matrix_utils.h
    # common/matrix_utils_unittest.cpp
    common/MemoryBuffer.cpp
    common/MemoryBuffer.h
    common/Optional.h
    # common/Optional_unittest.cpp
    common/PackedCLEnums_autogen.cpp
    common/PackedCLEnums_autogen.h
    common/PackedEGLEnums_autogen.cpp
    common/PackedEGLEnums_autogen.h
    common/PackedEnums.cpp
    common/PackedEnums.h
    common/PackedGLEnums_autogen.cpp
    common/PackedGLEnums_autogen.h
    common/packed_cl_enums.json
    common/packed_egl_enums.json
    common/packed_gl_enums.json
    common/platform.h
    common/PoolAlloc.cpp
    common/PoolAlloc.h
    # common/PoolAlloc_unittest.cpp
    common/RingBufferAllocator.cpp
    common/RingBufferAllocator.h
    common/Spinlock.h
    common/string_utils.cpp
    common/string_utils.h
    # common/string_utils_unittest.cpp
    common/SynchronizedValue.h
    common/system_utils.cpp
    common/system_utils.h
    # common/system_utils_apple.cpp
    # common/system_utils_ios.cpp
    # common/system_utils_ios.mm
    # common/system_utils_linux.cpp
    # common/system_utils_mac.cpp
    # common/system_utils_posix.cpp
    # common/system_utils_unittest.cpp
    common/system_utils_win.cpp
    common/system_utils_win32.cpp
    # common/system_utils_winuwp.cpp
    common/tls.cpp
    common/tls.h
    common/uniform_type_info_autogen.cpp
    common/utilities.cpp
    common/utilities.h
    # common/utilities_unittest.cpp
    common/vector_utils.h
    # common/vector_utils_unittest.cpp
    common/WorkerThread.cpp
    common/WorkerThread.h
    # common/WorkerThread_unittest.cpp

    common/base/anglebase/base_export.h
    common/base/anglebase/containers/mru_cache.h
    common/base/anglebase/logging.h
    common/base/anglebase/macros.h
    common/base/anglebase/no_destructor.h
    common/base/anglebase/numerics/safe_conversions.h
    common/base/anglebase/numerics/safe_conversions_impl.h
    common/base/anglebase/numerics/safe_math.h
    common/base/anglebase/numerics/safe_math_arm_impl.h
    common/base/anglebase/numerics/safe_math_clang_gcc_impl.h
    common/base/anglebase/numerics/safe_math_shared_impl.h
    common/base/anglebase/sha1.cc
    common/base/anglebase/sha1.h
    common/base/anglebase/sys_byteorder.h

    compiler/translator/ASTMetadataHLSL.cpp
    compiler/translator/ASTMetadataHLSL.h
    compiler/translator/AtomicCounterFunctionHLSL.cpp
    compiler/translator/AtomicCounterFunctionHLSL.h
    compiler/translator/BaseTypes.cpp
    compiler/translator/BaseTypes.h
    compiler/translator/blocklayout.cpp
    compiler/translator/blocklayout.h
    compiler/translator/blocklayoutHLSL.cpp
    compiler/translator/blocklayoutHLSL.h
    # compiler/translator/BuildSPIRV.cpp
    # compiler/translator/BuildSPIRV.h
    compiler/translator/BuiltInFunctionEmulator.cpp
    compiler/translator/BuiltInFunctionEmulator.h
    compiler/translator/BuiltInFunctionEmulatorGLSL.cpp
    compiler/translator/BuiltInFunctionEmulatorGLSL.h
    compiler/translator/BuiltInFunctionEmulatorHLSL.cpp
    compiler/translator/BuiltInFunctionEmulatorHLSL.h
    compiler/translator/BuiltinsWorkaroundGLSL.cpp
    compiler/translator/BuiltinsWorkaroundGLSL.h
    compiler/translator/builtin_function_declarations.txt
    # compiler/translator/builtin_variables.json
    compiler/translator/CallDAG.cpp
    compiler/translator/CallDAG.h
    compiler/translator/CodeGen.cpp
    compiler/translator/CollectVariables.cpp
    compiler/translator/CollectVariables.h
    compiler/translator/Common.h
    compiler/translator/Compiler.cpp
    compiler/translator/Compiler.h
    compiler/translator/ConstantUnion.cpp
    compiler/translator/ConstantUnion.h
    compiler/translator/Declarator.cpp
    compiler/translator/Declarator.h
    compiler/translator/Diagnostics.cpp
    compiler/translator/Diagnostics.h
    compiler/translator/DirectiveHandler.cpp
    compiler/translator/DirectiveHandler.h
    compiler/translator/DriverUniformMetal.cpp
    compiler/translator/DriverUniformMetal.h
    compiler/translator/emulated_builtin_functions_hlsl_autogen.cpp
    # compiler/translator/emulated_builtin_function_data_hlsl.json
    compiler/translator/ExtensionBehavior.cpp
    compiler/translator/ExtensionBehavior.h
    compiler/translator/ExtensionGLSL.cpp
    compiler/translator/ExtensionGLSL.h
    compiler/translator/FlagStd140Structs.cpp
    compiler/translator/FlagStd140Structs.h
    compiler/translator/FunctionLookup.cpp
    compiler/translator/FunctionLookup.h
    # compiler/translator/generate_parser.py
    # compiler/translator/gen_builtin_symbols.py
    # compiler/translator/gen_emulated_builtin_function_tables.py
    compiler/translator/glslang.h
    compiler/translator/glslang.l
    compiler/translator/glslang.y
    compiler/translator/glslang_lex_autogen.cpp
    compiler/translator/glslang_tab_autogen.cpp
    compiler/translator/glslang_tab_autogen.h
    compiler/translator/HashNames.cpp
    compiler/translator/HashNames.h
    compiler/translator/ImageFunctionHLSL.cpp
    compiler/translator/ImageFunctionHLSL.h
    compiler/translator/ImmutableString.h
    compiler/translator/ImmutableStringBuilder.cpp
    compiler/translator/ImmutableStringBuilder.h
    compiler/translator/ImmutableString_autogen.cpp
    # compiler/translator/ImmutableString_ESSL_autogen.cpp
    compiler/translator/InfoSink.cpp
    compiler/translator/InfoSink.h
    compiler/translator/Initialize.cpp
    compiler/translator/Initialize.h
    compiler/translator/InitializeDll.cpp
    compiler/translator/InitializeDll.h
    compiler/translator/InitializeGlobals.h
    compiler/translator/IntermNode.cpp
    compiler/translator/IntermNode.h
    compiler/translator/IsASTDepthBelowLimit.cpp
    compiler/translator/IsASTDepthBelowLimit.h
    compiler/translator/length_limits.h
    compiler/translator/Operator.cpp
    compiler/translator/Operator_autogen.h
    # compiler/translator/OutputESSL.cpp
    # compiler/translator/OutputESSL.h
    compiler/translator/OutputGLSL.cpp
    compiler/translator/OutputGLSL.h
    compiler/translator/OutputGLSLBase.cpp
    compiler/translator/OutputGLSLBase.h
    compiler/translator/OutputHLSL.cpp
    compiler/translator/OutputHLSL.h
    # compiler/translator/OutputSPIRV.cpp
    # compiler/translator/OutputSPIRV.h
    compiler/translator/OutputTree.cpp
    compiler/translator/OutputTree.h
    compiler/translator/ParseContext.cpp
    compiler/translator/ParseContext.h
    compiler/translator/PoolAlloc.cpp
    compiler/translator/PoolAlloc.h
    compiler/translator/Pragma.h
    compiler/translator/QualifierTypes.cpp
    compiler/translator/QualifierTypes.h
    compiler/translator/ResourcesHLSL.cpp
    compiler/translator/ResourcesHLSL.h
    compiler/translator/Severity.h
    compiler/translator/ShaderLang.cpp
    compiler/translator/ShaderStorageBlockFunctionHLSL.cpp
    compiler/translator/ShaderStorageBlockFunctionHLSL.h
    compiler/translator/ShaderStorageBlockOutputHLSL.cpp
    compiler/translator/ShaderStorageBlockOutputHLSL.h
    compiler/translator/ShaderVars.cpp
    # compiler/translator/span_unittest.cpp
    compiler/translator/StaticType.h
    compiler/translator/StructureHLSL.cpp
    compiler/translator/StructureHLSL.h
    compiler/translator/Symbol.cpp
    compiler/translator/Symbol.h
    compiler/translator/SymbolTable.cpp
    compiler/translator/SymbolTable.h
    compiler/translator/SymbolTable_autogen.cpp
    compiler/translator/SymbolTable_autogen.h
    # compiler/translator/SymbolTable_ESSL_autogen.cpp
    compiler/translator/SymbolUniqueId.cpp
    compiler/translator/SymbolUniqueId.h
    compiler/translator/TextureFunctionHLSL.cpp
    compiler/translator/TextureFunctionHLSL.h
    # compiler/translator/TranslatorESSL.cpp
    # compiler/translator/TranslatorESSL.h
    compiler/translator/TranslatorGLSL.cpp
    compiler/translator/TranslatorGLSL.h
    compiler/translator/TranslatorHLSL.cpp
    compiler/translator/TranslatorHLSL.h
    compiler/translator/TranslatorMetalDirect.cpp
    compiler/translator/TranslatorMetalDirect.h
    compiler/translator/TranslatorVulkan.cpp
    compiler/translator/TranslatorVulkan.h
    compiler/translator/Types.cpp
    compiler/translator/Types.h
    compiler/translator/util.cpp
    compiler/translator/util.h
    compiler/translator/UtilsHLSL.cpp
    compiler/translator/UtilsHLSL.h
    compiler/translator/ValidateAST.cpp
    compiler/translator/ValidateAST.h
    compiler/translator/ValidateBarrierFunctionCall.cpp
    compiler/translator/ValidateBarrierFunctionCall.h
    compiler/translator/ValidateClipCullDistance.cpp
    compiler/translator/ValidateClipCullDistance.h
    compiler/translator/ValidateGlobalInitializer.cpp
    compiler/translator/ValidateGlobalInitializer.h
    compiler/translator/ValidateLimitations.cpp
    compiler/translator/ValidateLimitations.h
    compiler/translator/ValidateMaxParameters.cpp
    compiler/translator/ValidateMaxParameters.h
    compiler/translator/ValidateOutputs.cpp
    compiler/translator/ValidateOutputs.h
    compiler/translator/ValidateSwitch.cpp
    compiler/translator/ValidateSwitch.h
    compiler/translator/ValidateTypeSizeLimitations.cpp
    compiler/translator/ValidateTypeSizeLimitations.h
    compiler/translator/ValidateVaryingLocations.cpp
    compiler/translator/ValidateVaryingLocations.h
    compiler/translator/VariablePacker.cpp
    compiler/translator/VariablePacker.h
    compiler/translator/VersionGLSL.cpp
    compiler/translator/VersionGLSL.h

    compiler/translator/tree_ops/ClampIndirectIndices.cpp
    compiler/translator/tree_ops/ClampIndirectIndices.h
    compiler/translator/tree_ops/ClampPointSize.cpp
    compiler/translator/tree_ops/ClampPointSize.h
    compiler/translator/tree_ops/ConvertUnsupportedConstructorsToFunctionCalls.cpp
    compiler/translator/tree_ops/ConvertUnsupportedConstructorsToFunctionCalls.h
    compiler/translator/tree_ops/DeclareAndInitBuiltinsForInstancedMultiview.cpp
    compiler/translator/tree_ops/DeclareAndInitBuiltinsForInstancedMultiview.h
    compiler/translator/tree_ops/DeclarePerVertexBlocks.cpp
    compiler/translator/tree_ops/DeclarePerVertexBlocks.h
    compiler/translator/tree_ops/DeferGlobalInitializers.cpp
    compiler/translator/tree_ops/DeferGlobalInitializers.h
    compiler/translator/tree_ops/EmulateGLFragColorBroadcast.cpp
    compiler/translator/tree_ops/EmulateGLFragColorBroadcast.h
    compiler/translator/tree_ops/EmulateMultiDrawShaderBuiltins.cpp
    compiler/translator/tree_ops/EmulateMultiDrawShaderBuiltins.h
    compiler/translator/tree_ops/FoldExpressions.cpp
    compiler/translator/tree_ops/FoldExpressions.h
    compiler/translator/tree_ops/ForcePrecisionQualifier.cpp
    compiler/translator/tree_ops/ForcePrecisionQualifier.h
    compiler/translator/tree_ops/InitializeVariables.cpp
    compiler/translator/tree_ops/InitializeVariables.h
    compiler/translator/tree_ops/MonomorphizeUnsupportedFunctions.cpp
    compiler/translator/tree_ops/MonomorphizeUnsupportedFunctions.h
    compiler/translator/tree_ops/PruneEmptyCases.cpp
    compiler/translator/tree_ops/PruneEmptyCases.h
    compiler/translator/tree_ops/PruneNoOps.cpp
    compiler/translator/tree_ops/PruneNoOps.h
    compiler/translator/tree_ops/RecordConstantPrecision.cpp
    compiler/translator/tree_ops/RecordConstantPrecision.h
    compiler/translator/tree_ops/RemoveArrayLengthMethod.cpp
    compiler/translator/tree_ops/RemoveArrayLengthMethod.h
    compiler/translator/tree_ops/RemoveAtomicCounterBuiltins.cpp
    compiler/translator/tree_ops/RemoveAtomicCounterBuiltins.h
    compiler/translator/tree_ops/RemoveDynamicIndexing.cpp
    compiler/translator/tree_ops/RemoveDynamicIndexing.h
    compiler/translator/tree_ops/RemoveInactiveInterfaceVariables.cpp
    compiler/translator/tree_ops/RemoveInactiveInterfaceVariables.h
    compiler/translator/tree_ops/RemoveInvariantDeclaration.cpp
    compiler/translator/tree_ops/RemoveInvariantDeclaration.h
    compiler/translator/tree_ops/RemoveUnreferencedVariables.cpp
    compiler/translator/tree_ops/RemoveUnreferencedVariables.h
    compiler/translator/tree_ops/RewriteArrayOfArrayOfOpaqueUniforms.cpp
    compiler/translator/tree_ops/RewriteArrayOfArrayOfOpaqueUniforms.h
    compiler/translator/tree_ops/RewriteAtomicCounters.cpp
    compiler/translator/tree_ops/RewriteAtomicCounters.h
    compiler/translator/tree_ops/RewriteCubeMapSamplersAs2DArray.cpp
    compiler/translator/tree_ops/RewriteCubeMapSamplersAs2DArray.h
    compiler/translator/tree_ops/RewriteDfdy.cpp
    compiler/translator/tree_ops/RewriteDfdy.h
    compiler/translator/tree_ops/RewritePixelLocalStorage.cpp
    compiler/translator/tree_ops/RewritePixelLocalStorage.h
    compiler/translator/tree_ops/RewriteStructSamplers.cpp
    compiler/translator/tree_ops/RewriteStructSamplers.h
    compiler/translator/tree_ops/RewriteTexelFetchOffset.cpp
    compiler/translator/tree_ops/RewriteTexelFetchOffset.h
    compiler/translator/tree_ops/SeparateDeclarations.cpp
    compiler/translator/tree_ops/SeparateDeclarations.h
    compiler/translator/tree_ops/SeparateStructFromUniformDeclarations.cpp
    compiler/translator/tree_ops/SeparateStructFromUniformDeclarations.h
    compiler/translator/tree_ops/SimplifyLoopConditions.cpp
    compiler/translator/tree_ops/SimplifyLoopConditions.h
    compiler/translator/tree_ops/SplitSequenceOperator.cpp
    compiler/translator/tree_ops/SplitSequenceOperator.h

    # compiler/translator/tree_ops/apple/AddAndTrueToLoopCondition.cpp
    # compiler/translator/tree_ops/apple/AddAndTrueToLoopCondition.h
    # compiler/translator/tree_ops/apple/RewriteDoWhile.cpp
    # compiler/translator/tree_ops/apple/RewriteDoWhile.h
    # compiler/translator/tree_ops/apple/RewriteRowMajorMatrices.cpp
    # compiler/translator/tree_ops/apple/RewriteRowMajorMatrices.h
    # compiler/translator/tree_ops/apple/RewriteUnaryMinusOperatorFloat.cpp
    # compiler/translator/tree_ops/apple/RewriteUnaryMinusOperatorFloat.h
    # compiler/translator/tree_ops/apple/UnfoldShortCircuitAST.cpp
    # compiler/translator/tree_ops/apple/UnfoldShortCircuitAST.h
    
    compiler/translator/tree_ops/d3d/AddDefaultReturnStatements.cpp
    compiler/translator/tree_ops/d3d/AddDefaultReturnStatements.h
    compiler/translator/tree_ops/d3d/AggregateAssignArraysInSSBOs.cpp
    compiler/translator/tree_ops/d3d/AggregateAssignArraysInSSBOs.h
    compiler/translator/tree_ops/d3d/AggregateAssignStructsInSSBOs.cpp
    compiler/translator/tree_ops/d3d/AggregateAssignStructsInSSBOs.h
    compiler/translator/tree_ops/d3d/ArrayReturnValueToOutParameter.cpp
    compiler/translator/tree_ops/d3d/ArrayReturnValueToOutParameter.h
    compiler/translator/tree_ops/d3d/BreakVariableAliasingInInnerLoops.cpp
    compiler/translator/tree_ops/d3d/BreakVariableAliasingInInnerLoops.h
    compiler/translator/tree_ops/d3d/ExpandIntegerPowExpressions.cpp
    compiler/translator/tree_ops/d3d/ExpandIntegerPowExpressions.h
    compiler/translator/tree_ops/d3d/RecordUniformBlocksWithLargeArrayMember.cpp
    compiler/translator/tree_ops/d3d/RecordUniformBlocksWithLargeArrayMember.h
    compiler/translator/tree_ops/d3d/RemoveSwitchFallThrough.cpp
    compiler/translator/tree_ops/d3d/RemoveSwitchFallThrough.h
    compiler/translator/tree_ops/d3d/RewriteAtomicFunctionExpressions.cpp
    compiler/translator/tree_ops/d3d/RewriteAtomicFunctionExpressions.h
    compiler/translator/tree_ops/d3d/RewriteElseBlocks.cpp
    compiler/translator/tree_ops/d3d/RewriteElseBlocks.h
    compiler/translator/tree_ops/d3d/RewriteExpressionsWithShaderStorageBlock.cpp
    compiler/translator/tree_ops/d3d/RewriteExpressionsWithShaderStorageBlock.h
    compiler/translator/tree_ops/d3d/RewriteUnaryMinusOperatorInt.cpp
    compiler/translator/tree_ops/d3d/RewriteUnaryMinusOperatorInt.h
    compiler/translator/tree_ops/d3d/SeparateArrayConstructorStatements.cpp
    compiler/translator/tree_ops/d3d/SeparateArrayConstructorStatements.h
    compiler/translator/tree_ops/d3d/SeparateArrayInitialization.cpp
    compiler/translator/tree_ops/d3d/SeparateArrayInitialization.h
    compiler/translator/tree_ops/d3d/SeparateExpressionsReturningArrays.cpp
    compiler/translator/tree_ops/d3d/SeparateExpressionsReturningArrays.h
    compiler/translator/tree_ops/d3d/UnfoldShortCircuitToIf.cpp
    compiler/translator/tree_ops/d3d/UnfoldShortCircuitToIf.h
    compiler/translator/tree_ops/d3d/WrapSwitchStatementsInBlocks.cpp
    compiler/translator/tree_ops/d3d/WrapSwitchStatementsInBlocks.h
    
#[===[
    compiler/translator/tree_ops/gl/ClampFragDepth.cpp
    compiler/translator/tree_ops/gl/ClampFragDepth.h
    compiler/translator/tree_ops/gl/RegenerateStructNames.cpp
    compiler/translator/tree_ops/gl/RegenerateStructNames.h
    compiler/translator/tree_ops/gl/RewriteRepeatedAssignToSwizzled.cpp
    compiler/translator/tree_ops/gl/RewriteRepeatedAssignToSwizzled.h
    compiler/translator/tree_ops/gl/ScalarizeVecAndMatConstructorArgs.cpp
    compiler/translator/tree_ops/gl/ScalarizeVecAndMatConstructorArgs.h
    compiler/translator/tree_ops/gl/UseInterfaceBlockFields.cpp
    compiler/translator/tree_ops/gl/UseInterfaceBlockFields.h
]===]
    
    compiler/translator/tree_ops/vulkan/EmulateAdvancedBlendEquations.cpp
    compiler/translator/tree_ops/vulkan/EmulateAdvancedBlendEquations.h
    compiler/translator/tree_ops/vulkan/EmulateDithering.cpp
    compiler/translator/tree_ops/vulkan/EmulateDithering.h
    compiler/translator/tree_ops/vulkan/EmulateFragColorData.cpp
    compiler/translator/tree_ops/vulkan/EmulateFragColorData.h
    compiler/translator/tree_ops/vulkan/EmulateYUVBuiltIns.cpp
    compiler/translator/tree_ops/vulkan/EmulateYUVBuiltIns.h
    compiler/translator/tree_ops/vulkan/FlagSamplersWithTexelFetch.cpp
    compiler/translator/tree_ops/vulkan/FlagSamplersWithTexelFetch.h
    compiler/translator/tree_ops/vulkan/ReplaceForShaderFramebufferFetch.cpp
    compiler/translator/tree_ops/vulkan/ReplaceForShaderFramebufferFetch.h
    compiler/translator/tree_ops/vulkan/RewriteInterpolateAtOffset.cpp
    compiler/translator/tree_ops/vulkan/RewriteInterpolateAtOffset.h
    compiler/translator/tree_ops/vulkan/RewriteR32fImages.cpp
    compiler/translator/tree_ops/vulkan/RewriteR32fImages.h
    
    compiler/translator/tree_util/AsNode.h
    compiler/translator/tree_util/BuiltIn.h
    compiler/translator/tree_util/BuiltIn_complete_autogen.h
    # compiler/translator/tree_util/BuiltIn_ESSL_autogen.h
    compiler/translator/tree_util/DriverUniform.cpp
    compiler/translator/tree_util/DriverUniform.h
    compiler/translator/tree_util/FindFunction.cpp
    compiler/translator/tree_util/FindFunction.h
    compiler/translator/tree_util/FindMain.cpp
    compiler/translator/tree_util/FindMain.h
    compiler/translator/tree_util/FindPreciseNodes.cpp
    compiler/translator/tree_util/FindPreciseNodes.h
    compiler/translator/tree_util/FindSymbolNode.cpp
    compiler/translator/tree_util/FindSymbolNode.h
    compiler/translator/tree_util/IntermNodePatternMatcher.cpp
    compiler/translator/tree_util/IntermNodePatternMatcher.h
    compiler/translator/tree_util/IntermNode_util.cpp
    compiler/translator/tree_util/IntermNode_util.h
    compiler/translator/tree_util/IntermRebuild.cpp
    compiler/translator/tree_util/IntermRebuild.h
    compiler/translator/tree_util/IntermTraverse.cpp
    compiler/translator/tree_util/IntermTraverse.h
    compiler/translator/tree_util/NodeSearch.h
    compiler/translator/tree_util/NodeType.h
    compiler/translator/tree_util/ReplaceArrayOfMatrixVarying.cpp
    compiler/translator/tree_util/ReplaceArrayOfMatrixVarying.h
    compiler/translator/tree_util/ReplaceClipCullDistanceVariable.cpp
    compiler/translator/tree_util/ReplaceClipCullDistanceVariable.h
    compiler/translator/tree_util/ReplaceShadowingVariables.cpp
    compiler/translator/tree_util/ReplaceShadowingVariables.h
    compiler/translator/tree_util/ReplaceVariable.cpp
    compiler/translator/tree_util/ReplaceVariable.h
    compiler/translator/tree_util/RewriteSampleMaskVariable.cpp
    compiler/translator/tree_util/RewriteSampleMaskVariable.h
    compiler/translator/tree_util/RunAtTheBeginningOfShader.cpp
    compiler/translator/tree_util/RunAtTheBeginningOfShader.h
    compiler/translator/tree_util/RunAtTheEndOfShader.cpp
    compiler/translator/tree_util/RunAtTheEndOfShader.h
    compiler/translator/tree_util/SpecializationConstant.cpp
    compiler/translator/tree_util/SpecializationConstant.h
    compiler/translator/tree_util/Visit.h

    compiler/preprocessor/DiagnosticsBase.cpp
    compiler/preprocessor/DiagnosticsBase.h
    compiler/preprocessor/DirectiveHandlerBase.cpp
    compiler/preprocessor/DirectiveHandlerBase.h
    compiler/preprocessor/DirectiveParser.cpp
    compiler/preprocessor/DirectiveParser.h
    compiler/preprocessor/ExpressionParser.h
    # compiler/preprocessor/generate_parser.py
    compiler/preprocessor/Input.cpp
    compiler/preprocessor/Input.h
    compiler/preprocessor/Lexer.cpp
    compiler/preprocessor/Lexer.h
    compiler/preprocessor/Macro.cpp
    compiler/preprocessor/Macro.h
    compiler/preprocessor/MacroExpander.cpp
    compiler/preprocessor/MacroExpander.h
    compiler/preprocessor/numeric_lex.h
    compiler/preprocessor/Preprocessor.cpp
    compiler/preprocessor/Preprocessor.h
    compiler/preprocessor/preprocessor.l
    compiler/preprocessor/preprocessor.y
    compiler/preprocessor/preprocessor_lex_autogen.cpp
    compiler/preprocessor/preprocessor_tab_autogen.cpp
    compiler/preprocessor/SourceLocation.h
    compiler/preprocessor/Token.cpp
    compiler/preprocessor/Token.h
    compiler/preprocessor/Tokenizer.h

    # image_util/AstcDecompressor.cpp
    image_util/AstcDecompressor.h
    image_util/AstcDecompressorNoOp.cpp
    # image_util/AstcDecompressorTestUtils.h
    # image_util/AstcDecompressor_unittest.cpp
    image_util/copyimage.cpp
    image_util/copyimage.h
    image_util/copyimage.inc
    image_util/generatemip.h
    image_util/generatemip.inc
    image_util/imageformats.cpp
    image_util/imageformats.h
    image_util/loadimage.cpp
    image_util/loadimage.h
    image_util/loadimage.inc
    image_util/loadimage_astc.cpp
    image_util/loadimage_etc.cpp
    image_util/loadimage_paletted.cpp
    image_util/storeimage.h
    image_util/storeimage_paletted.cpp

    gpu_info_util/SystemInfo.cpp
    gpu_info_util/SystemInfo.h
    # gpu_info_util/SystemInfo_android.cpp
    # gpu_info_util/SystemInfo_apple.mm
    # gpu_info_util/SystemInfo_fuchsia.cpp
    gpu_info_util/SystemInfo_internal.h
    # gpu_info_util/SystemInfo_ios.cpp
    # gpu_info_util/SystemInfo_libpci.cpp
    # gpu_info_util/SystemInfo_linux.cpp
    # gpu_info_util/SystemInfo_macos.mm
    # gpu_info_util/SystemInfo_unittest.cpp
    # gpu_info_util/SystemInfo_vulkan.cpp
    # gpu_info_util/SystemInfo_vulkan.h
    gpu_info_util/SystemInfo_win.cpp
    # gpu_info_util/SystemInfo_x11.cpp

    third_party/systeminfo/SystemInfo.cpp
    third_party/systeminfo/SystemInfo.h

    libANGLE/angletypes.cpp
    libANGLE/angletypes.h
    libANGLE/angletypes.inc
    libANGLE/AttributeMap.cpp
    libANGLE/AttributeMap.h
    # libANGLE/BlendStateExt_unittest.cpp
    libANGLE/BlobCache.cpp
    libANGLE/BlobCache.h
    # libANGLE/BlobCache_unittest.cpp
    libANGLE/Buffer.cpp
    libANGLE/Buffer.h
    libANGLE/Caps.cpp
    libANGLE/Caps.h
    libANGLE/CLBitField.h
    libANGLE/CLBuffer.cpp
    libANGLE/CLBuffer.h
    libANGLE/CLCommandQueue.cpp
    libANGLE/CLCommandQueue.h
    libANGLE/CLContext.cpp
    libANGLE/CLContext.h
    libANGLE/CLDevice.cpp
    libANGLE/CLDevice.h
    libANGLE/CLEvent.cpp
    libANGLE/CLEvent.h
    libANGLE/CLImage.cpp
    libANGLE/CLImage.h
    libANGLE/CLKernel.cpp
    libANGLE/CLKernel.h
    libANGLE/CLMemory.cpp
    libANGLE/CLMemory.h
    libANGLE/CLObject.cpp
    libANGLE/CLObject.h
    libANGLE/CLPlatform.cpp
    libANGLE/CLPlatform.h
    libANGLE/CLProgram.cpp
    libANGLE/CLProgram.h
    libANGLE/CLRefPointer.h
    libANGLE/CLSampler.cpp
    libANGLE/CLSampler.h
    libANGLE/CLtypes.h
    libANGLE/cl_utils.cpp
    libANGLE/cl_utils.h
    libANGLE/Compiler.cpp
    libANGLE/Compiler.h
    libANGLE/Config.cpp
    libANGLE/Config.h
    # libANGLE/Config_unittest.cpp
    libANGLE/Constants.h
    libANGLE/Context.cpp
    libANGLE/Context.h
    libANGLE/Context.inl.h
    libANGLE/Context_gl.cpp
    libANGLE/Context_gles_1_0.cpp
    libANGLE/Context_gles_1_0_autogen.h
    libANGLE/Context_gles_2_0_autogen.h
    libANGLE/Context_gles_3_0_autogen.h
    libANGLE/Context_gles_3_1_autogen.h
    libANGLE/Context_gles_3_2_autogen.h
    libANGLE/Context_gles_ext_autogen.h
    libANGLE/Context_gl_1_autogen.h
    libANGLE/Context_gl_2_autogen.h
    libANGLE/Context_gl_3_autogen.h
    libANGLE/Context_gl_4_autogen.h
    libANGLE/Debug.cpp
    libANGLE/Debug.h
    libANGLE/Device.cpp
    libANGLE/Device.h
    libANGLE/Display.cpp
    libANGLE/Display.h
    libANGLE/EGLSync.cpp
    libANGLE/EGLSync.h
    libANGLE/entry_points_utils.cpp
    libANGLE/entry_points_utils.h
    libANGLE/Error.cpp
    libANGLE/Error.h
    libANGLE/Error.inc
    libANGLE/ErrorStrings.h
    # libANGLE/es3_copy_conversion_formats.json
    libANGLE/es3_copy_conversion_table_autogen.cpp
    # libANGLE/es3_format_type_combinations.json
    libANGLE/features.h
    libANGLE/Fence.cpp
    libANGLE/Fence.h
    # libANGLE/Fence_unittest.cpp
    libANGLE/formatutils.cpp
    libANGLE/formatutils.h
    libANGLE/format_map_autogen.cpp
    # libANGLE/format_map_data.json
    libANGLE/format_map_desktop.cpp
    libANGLE/Framebuffer.cpp
    libANGLE/Framebuffer.h
    libANGLE/FramebufferAttachment.cpp
    libANGLE/FramebufferAttachment.h
    # libANGLE/gen_copy_conversion_table.py
    # libANGLE/gen_extensions.py
    # libANGLE/gen_format_map.py
    # libANGLE/gen_overlay_fonts.py
    # libANGLE/gen_overlay_widgets.py
    libANGLE/GLES1Renderer.cpp
    libANGLE/GLES1Renderer.h
    libANGLE/GLES1Shaders.inc
    libANGLE/GLES1State.cpp
    libANGLE/GLES1State.h
    libANGLE/gles_extensions_autogen.cpp
    libANGLE/gles_extensions_autogen.h
    libANGLE/GlobalMutex.cpp
    libANGLE/GlobalMutex.h
    # libANGLE/GlobalMutex_unittest.cpp
    libANGLE/HandleAllocator.cpp
    libANGLE/HandleAllocator.h
    # libANGLE/HandleAllocator_unittest.cpp
    libANGLE/histogram_macros.h
    libANGLE/Image.cpp
    libANGLE/Image.h
    libANGLE/ImageIndex.cpp
    libANGLE/ImageIndex.h
    # libANGLE/ImageIndexIterator_unittest.cpp
    # libANGLE/Image_unittest.cpp
    libANGLE/IndexRangeCache.cpp
    libANGLE/IndexRangeCache.h
    libANGLE/InfoLog.h
    libANGLE/LoggingAnnotator.cpp
    libANGLE/LoggingAnnotator.h
    libANGLE/MemoryObject.cpp
    libANGLE/MemoryObject.h
    libANGLE/MemoryProgramCache.cpp
    libANGLE/MemoryProgramCache.h
    libANGLE/MemoryShaderCache.cpp
    libANGLE/MemoryShaderCache.h
    libANGLE/Observer.cpp
    libANGLE/Observer.h
    # libANGLE/Observer_unittest.cpp
    libANGLE/Overlay.cpp
    libANGLE/Overlay.h
    libANGLE/OverlayWidgets.cpp
    libANGLE/OverlayWidgets.h
    libANGLE/Overlay_autogen.cpp
    libANGLE/Overlay_autogen.h
    libANGLE/Overlay_font_autogen.cpp
    libANGLE/Overlay_font_autogen.h
    # libANGLE/overlay_widgets.json
    libANGLE/PixelLocalStorage.cpp
    libANGLE/PixelLocalStorage.h
    libANGLE/Platform.cpp
    libANGLE/Program.cpp
    libANGLE/Program.h
    libANGLE/ProgramExecutable.cpp
    libANGLE/ProgramExecutable.h
    libANGLE/ProgramLinkedResources.cpp
    libANGLE/ProgramLinkedResources.h
    libANGLE/ProgramPipeline.cpp
    libANGLE/ProgramPipeline.h
    # libANGLE/Program_unittest.cpp
    libANGLE/Query.cpp
    libANGLE/Query.h
    libANGLE/queryconversions.cpp
    libANGLE/queryconversions.h
    libANGLE/queryutils.cpp
    libANGLE/queryutils.h
    libANGLE/RefCountObject.h
    libANGLE/Renderbuffer.cpp
    libANGLE/Renderbuffer.h
    libANGLE/ResourceManager.cpp
    libANGLE/ResourceManager.h
    # libANGLE/ResourceManager_unittest.cpp
    libANGLE/ResourceMap.h
    # libANGLE/ResourceMap_unittest.cpp
    libANGLE/Sampler.cpp
    libANGLE/Sampler.h
    libANGLE/Semaphore.cpp
    libANGLE/Semaphore.h
    libANGLE/Shader.cpp
    libANGLE/Shader.h
    libANGLE/SizedMRUCache.h
    # libANGLE/SizedMRUCache_unittest.cpp
    libANGLE/State.cpp
    libANGLE/State.h
    libANGLE/Stream.cpp
    libANGLE/Stream.h
    libANGLE/Surface.cpp
    libANGLE/Surface.h
    # libANGLE/Surface_unittest.cpp
    libANGLE/Texture.cpp
    libANGLE/Texture.h
    libANGLE/Thread.cpp
    libANGLE/Thread.h
    libANGLE/trace.h
    libANGLE/TransformFeedback.cpp
    libANGLE/TransformFeedback.h
    # libANGLE/TransformFeedback_unittest.cpp
    libANGLE/Uniform.cpp
    libANGLE/Uniform.h
    # libANGLE/UnlockedTailCall_unittest.cpp
    libANGLE/validationCL.cpp
    libANGLE/validationCL.h
    libANGLE/validationCL_autogen.h
    libANGLE/validationEGL.cpp
    libANGLE/validationEGL.h
    libANGLE/validationEGL_autogen.h
    libANGLE/validationES.cpp
    libANGLE/validationES.h
    libANGLE/validationES1.cpp
    libANGLE/validationES1.h
    libANGLE/validationES1_autogen.h
    libANGLE/validationES2.cpp
    libANGLE/validationES2.h
    libANGLE/validationES2_autogen.h
    libANGLE/validationES3.cpp
    libANGLE/validationES3.h
    libANGLE/validationES31.cpp
    libANGLE/validationES31.h
    libANGLE/validationES31_autogen.h
    libANGLE/validationES32.cpp
    libANGLE/validationES32.h
    libANGLE/validationES32_autogen.h
    libANGLE/validationES3_autogen.h
    libANGLE/validationESEXT.cpp
    libANGLE/validationESEXT.h
    libANGLE/validationESEXT_autogen.h
    libANGLE/validationGL1.cpp
    libANGLE/validationGL11_autogen.h
    libANGLE/validationGL12_autogen.h
    libANGLE/validationGL13_autogen.h
    libANGLE/validationGL14_autogen.h
    libANGLE/validationGL15_autogen.h
    libANGLE/validationGL1_autogen.h
    libANGLE/validationGL2.cpp
    libANGLE/validationGL21_autogen.h
    libANGLE/validationGL2_autogen.h
    libANGLE/validationGL3.cpp
    libANGLE/validationGL31_autogen.h
    libANGLE/validationGL32_autogen.h
    libANGLE/validationGL33_autogen.h
    libANGLE/validationGL3_autogen.h
    libANGLE/validationGL4.cpp
    libANGLE/validationGL41_autogen.h
    libANGLE/validationGL42_autogen.h
    libANGLE/validationGL43_autogen.h
    libANGLE/validationGL44_autogen.h
    libANGLE/validationGL45_autogen.h
    libANGLE/validationGL46_autogen.h
    libANGLE/validationGL4_autogen.h
    libANGLE/VaryingPacking.cpp
    libANGLE/VaryingPacking.h
    # libANGLE/VaryingPacking_unittest.cpp
    libANGLE/Version.h
    libANGLE/Version.inc
    libANGLE/VertexArray.cpp
    libANGLE/VertexArray.h
    # libANGLE/VertexArray_unittest.cpp
    libANGLE/VertexAttribute.cpp
    libANGLE/VertexAttribute.h
    libANGLE/VertexAttribute.inc

    # libANGLE/capture/capture_egl_autogen.cpp
    # libANGLE/capture/capture_egl_autogen.h
    # libANGLE/capture/capture_gles_1_0_autogen.cpp
    # libANGLE/capture/capture_gles_1_0_autogen.h
    # libANGLE/capture/capture_gles_1_0_params.cpp
    # libANGLE/capture/capture_gles_2_0_autogen.cpp
    # libANGLE/capture/capture_gles_2_0_autogen.h
    # libANGLE/capture/capture_gles_2_0_params.cpp
    # libANGLE/capture/capture_gles_3_0_autogen.cpp
    # libANGLE/capture/capture_gles_3_0_autogen.h
    # libANGLE/capture/capture_gles_3_0_params.cpp
    # libANGLE/capture/capture_gles_3_1_autogen.cpp
    # libANGLE/capture/capture_gles_3_1_autogen.h
    # libANGLE/capture/capture_gles_3_1_params.cpp
    # libANGLE/capture/capture_gles_3_2_autogen.cpp
    # libANGLE/capture/capture_gles_3_2_autogen.h
    # libANGLE/capture/capture_gles_3_2_params.cpp
    # libANGLE/capture/capture_gles_ext_autogen.cpp
    # libANGLE/capture/capture_gles_ext_autogen.h
    # libANGLE/capture/capture_gles_ext_params.cpp
    # libANGLE/capture/capture_gl_1_autogen.cpp
    # libANGLE/capture/capture_gl_1_autogen.h
    # libANGLE/capture/capture_gl_1_params.cpp
    # libANGLE/capture/capture_gl_2_autogen.cpp
    # libANGLE/capture/capture_gl_2_autogen.h
    # libANGLE/capture/capture_gl_2_params.cpp
    # libANGLE/capture/capture_gl_3_autogen.cpp
    # libANGLE/capture/capture_gl_3_autogen.h
    # libANGLE/capture/capture_gl_3_params.cpp
    # libANGLE/capture/capture_gl_4_autogen.cpp
    # libANGLE/capture/capture_gl_4_autogen.h
    # libANGLE/capture/capture_gl_4_params.cpp
    # libANGLE/capture/FrameCapture.cpp
    libANGLE/capture/FrameCapture.h
    libANGLE/capture/FrameCapture_mock.cpp
    # libANGLE/capture/serialize.cpp
    # libANGLE/capture/serialize.h
    libANGLE/capture/serialize_mock.cpp

    libANGLE/renderer/BufferImpl.cpp
    libANGLE/renderer/BufferImpl.h
    # libANGLE/renderer/BufferImpl_mock.h
    libANGLE/renderer/CLCommandQueueImpl.cpp
    libANGLE/renderer/CLCommandQueueImpl.h
    libANGLE/renderer/CLContextImpl.cpp
    libANGLE/renderer/CLContextImpl.h
    libANGLE/renderer/CLDeviceImpl.cpp
    libANGLE/renderer/CLDeviceImpl.h
    libANGLE/renderer/CLEventImpl.cpp
    libANGLE/renderer/CLEventImpl.h
    libANGLE/renderer/CLExtensions.cpp
    libANGLE/renderer/CLExtensions.h
    libANGLE/renderer/CLKernelImpl.cpp
    libANGLE/renderer/CLKernelImpl.h
    libANGLE/renderer/CLMemoryImpl.cpp
    libANGLE/renderer/CLMemoryImpl.h
    libANGLE/renderer/CLPlatformImpl.cpp
    libANGLE/renderer/CLPlatformImpl.h
    libANGLE/renderer/CLProgramImpl.cpp
    libANGLE/renderer/CLProgramImpl.h
    libANGLE/renderer/CLSamplerImpl.cpp
    libANGLE/renderer/CLSamplerImpl.h
    libANGLE/renderer/CLtypes.h
    libANGLE/renderer/CompilerImpl.h
    libANGLE/renderer/ContextImpl.cpp
    libANGLE/renderer/ContextImpl.h
    libANGLE/renderer/copyvertex.h
    libANGLE/renderer/copyvertex.inc.h
    libANGLE/renderer/d3d_format.cpp
    libANGLE/renderer/d3d_format.h
    libANGLE/renderer/DeviceImpl.cpp
    libANGLE/renderer/DeviceImpl.h
    libANGLE/renderer/DisplayImpl.cpp
    libANGLE/renderer/DisplayImpl.h
    libANGLE/renderer/driver_utils.cpp
    libANGLE/renderer/driver_utils.h
    # libANGLE/renderer/driver_utils_ios.mm
    # libANGLE/renderer/driver_utils_mac.mm
    # libANGLE/renderer/dxgi_format_data.json
    libANGLE/renderer/dxgi_format_map.h
    libANGLE/renderer/dxgi_format_map_autogen.cpp
    # libANGLE/renderer/dxgi_support_data.json
    libANGLE/renderer/dxgi_support_table.h
    libANGLE/renderer/dxgi_support_table_autogen.cpp
    libANGLE/renderer/EGLImplFactory.h
    libANGLE/renderer/EGLReusableSync.cpp
    libANGLE/renderer/EGLReusableSync.h
    libANGLE/renderer/EGLSyncImpl.cpp
    libANGLE/renderer/EGLSyncImpl.h
    libANGLE/renderer/FenceNVImpl.h
    libANGLE/renderer/Format.h
    libANGLE/renderer/FormatID_autogen.h
    libANGLE/renderer/Format_table_autogen.cpp
    libANGLE/renderer/FramebufferAttachmentObjectImpl.h
    libANGLE/renderer/FramebufferImpl.cpp
    libANGLE/renderer/FramebufferImpl.h
    # libANGLE/renderer/FramebufferImpl_mock.h
    # libANGLE/renderer/gen_angle_format_table.py
    # libANGLE/renderer/gen_dxgi_format_table.py
    # libANGLE/renderer/gen_dxgi_support_tables.py
    # libANGLE/renderer/gen_load_functions_table.py
    libANGLE/renderer/GLImplFactory.h
    libANGLE/renderer/ImageImpl.cpp
    libANGLE/renderer/ImageImpl.h
    # libANGLE/renderer/ImageImpl_mock.h
    # libANGLE/renderer/load_functions_data.json
    libANGLE/renderer/load_functions_table.h
    libANGLE/renderer/load_functions_table_autogen.cpp
    libANGLE/renderer/MemoryObjectImpl.h
    libANGLE/renderer/OverlayImpl.h
    libANGLE/renderer/ProgramImpl.cpp
    libANGLE/renderer/ProgramImpl.h
    # libANGLE/renderer/ProgramImpl_mock.h
    libANGLE/renderer/ProgramPipelineImpl.cpp
    libANGLE/renderer/ProgramPipelineImpl.h
    libANGLE/renderer/QueryImpl.cpp
    libANGLE/renderer/QueryImpl.h
    libANGLE/renderer/README.md
    libANGLE/renderer/RenderbufferImpl.cpp
    libANGLE/renderer/RenderbufferImpl.h
    # libANGLE/renderer/RenderbufferImpl_mock.h
    libANGLE/renderer/renderer_utils.cpp
    libANGLE/renderer/renderer_utils.h
    libANGLE/renderer/RenderTargetCache.h
    libANGLE/renderer/SamplerImpl.h
    libANGLE/renderer/SemaphoreImpl.h
    libANGLE/renderer/serial_utils.h
    # libANGLE/renderer/serial_utils_unittest.cpp
    libANGLE/renderer/ShaderImpl.cpp
    libANGLE/renderer/ShaderImpl.h
    libANGLE/renderer/StreamProducerImpl.h
    libANGLE/renderer/SurfaceImpl.cpp
    libANGLE/renderer/SurfaceImpl.h
    libANGLE/renderer/SyncImpl.h
    libANGLE/renderer/TextureImpl.cpp
    libANGLE/renderer/TextureImpl.h
    # libANGLE/renderer/TextureImpl_mock.h
    libANGLE/renderer/TransformFeedbackImpl.cpp
    libANGLE/renderer/TransformFeedbackImpl.h
    # libANGLE/renderer/TransformFeedbackImpl_mock.h
    libANGLE/renderer/VertexArrayImpl.cpp
    libANGLE/renderer/VertexArrayImpl.h

    libANGLE/renderer/d3d/BufferD3D.cpp
    libANGLE/renderer/d3d/BufferD3D.h
    libANGLE/renderer/d3d/BUILD.gn
    libANGLE/renderer/d3d/CompilerD3D.cpp
    libANGLE/renderer/d3d/CompilerD3D.h
    libANGLE/renderer/d3d/ContextD3D.h
    libANGLE/renderer/d3d/DeviceD3D.cpp
    libANGLE/renderer/d3d/DeviceD3D.h
    libANGLE/renderer/d3d/DisplayD3D.cpp
    libANGLE/renderer/d3d/DisplayD3D.h
    libANGLE/renderer/d3d/driver_utils_d3d.cpp
    libANGLE/renderer/d3d/driver_utils_d3d.h
    libANGLE/renderer/d3d/DynamicHLSL.cpp
    libANGLE/renderer/d3d/DynamicHLSL.h
    libANGLE/renderer/d3d/DynamicImage2DHLSL.cpp
    libANGLE/renderer/d3d/DynamicImage2DHLSL.h
    libANGLE/renderer/d3d/EGLImageD3D.cpp
    libANGLE/renderer/d3d/EGLImageD3D.h
    libANGLE/renderer/d3d/formatutilsD3D.h
    libANGLE/renderer/d3d/FramebufferD3D.cpp
    libANGLE/renderer/d3d/FramebufferD3D.h
    libANGLE/renderer/d3d/HLSLCompiler.cpp
    libANGLE/renderer/d3d/HLSLCompiler.h
    libANGLE/renderer/d3d/ImageD3D.cpp
    libANGLE/renderer/d3d/ImageD3D.h
    libANGLE/renderer/d3d/IndexBuffer.cpp
    libANGLE/renderer/d3d/IndexBuffer.h
    libANGLE/renderer/d3d/IndexDataManager.cpp
    libANGLE/renderer/d3d/IndexDataManager.h
    libANGLE/renderer/d3d/NativeWindowD3D.cpp
    libANGLE/renderer/d3d/NativeWindowD3D.h
    libANGLE/renderer/d3d/OWNERS
    libANGLE/renderer/d3d/ProgramD3D.cpp
    libANGLE/renderer/d3d/ProgramD3D.h
    libANGLE/renderer/d3d/RenderbufferD3D.cpp
    libANGLE/renderer/d3d/RenderbufferD3D.h
    libANGLE/renderer/d3d/RendererD3D.cpp
    libANGLE/renderer/d3d/RendererD3D.h
    libANGLE/renderer/d3d/RenderTargetD3D.cpp
    libANGLE/renderer/d3d/RenderTargetD3D.h
    libANGLE/renderer/d3d/SamplerD3D.h
    libANGLE/renderer/d3d/ShaderD3D.cpp
    libANGLE/renderer/d3d/ShaderD3D.h
    libANGLE/renderer/d3d/ShaderExecutableD3D.cpp
    libANGLE/renderer/d3d/ShaderExecutableD3D.h
    libANGLE/renderer/d3d/SurfaceD3D.cpp
    libANGLE/renderer/d3d/SurfaceD3D.h
    libANGLE/renderer/d3d/SwapChainD3D.cpp
    libANGLE/renderer/d3d/SwapChainD3D.h
    libANGLE/renderer/d3d/TextureD3D.cpp
    libANGLE/renderer/d3d/TextureD3D.h
    libANGLE/renderer/d3d/TextureStorage.h
    libANGLE/renderer/d3d/VertexBuffer.cpp
    libANGLE/renderer/d3d/VertexBuffer.h
    libANGLE/renderer/d3d/VertexDataManager.cpp
    libANGLE/renderer/d3d/VertexDataManager.h    

    libANGLE/renderer/d3d/d3d11/Blit11.cpp
    libANGLE/renderer/d3d/d3d11/Blit11.h
    libANGLE/renderer/d3d/d3d11/Blit11Helper_autogen.inc
    libANGLE/renderer/d3d/d3d11/Buffer11.cpp
    libANGLE/renderer/d3d/d3d11/Buffer11.h
    libANGLE/renderer/d3d/d3d11/Clear11.cpp
    libANGLE/renderer/d3d/d3d11/Clear11.h
    libANGLE/renderer/d3d/d3d11/Context11.cpp
    libANGLE/renderer/d3d/d3d11/Context11.h
    libANGLE/renderer/d3d/d3d11/d3d11_blit_shaders_autogen.gni
    libANGLE/renderer/d3d/d3d11/DebugAnnotator11.cpp
    libANGLE/renderer/d3d/d3d11/DebugAnnotator11.h
    libANGLE/renderer/d3d/d3d11/ExternalImageSiblingImpl11.cpp
    libANGLE/renderer/d3d/d3d11/ExternalImageSiblingImpl11.h
    libANGLE/renderer/d3d/d3d11/Fence11.cpp
    libANGLE/renderer/d3d/d3d11/Fence11.h
    libANGLE/renderer/d3d/d3d11/FormatTables.md
    libANGLE/renderer/d3d/d3d11/formatutils11.cpp
    libANGLE/renderer/d3d/d3d11/formatutils11.h
    libANGLE/renderer/d3d/d3d11/Framebuffer11.cpp
    libANGLE/renderer/d3d/d3d11/Framebuffer11.h
    # libANGLE/renderer/d3d/d3d11/gen_blit11helper.py
    # libANGLE/renderer/d3d/d3d11/gen_texture_format_table.py
    libANGLE/renderer/d3d/d3d11/Image11.cpp
    libANGLE/renderer/d3d/d3d11/Image11.h
    libANGLE/renderer/d3d/d3d11/IndexBuffer11.cpp
    libANGLE/renderer/d3d/d3d11/IndexBuffer11.h
    libANGLE/renderer/d3d/d3d11/InputLayoutCache.cpp
    libANGLE/renderer/d3d/d3d11/InputLayoutCache.h
    libANGLE/renderer/d3d/d3d11/MappedSubresourceVerifier11.cpp
    libANGLE/renderer/d3d/d3d11/MappedSubresourceVerifier11.h
    libANGLE/renderer/d3d/d3d11/NativeWindow11.h
    libANGLE/renderer/d3d/d3d11/PixelTransfer11.cpp
    libANGLE/renderer/d3d/d3d11/PixelTransfer11.h
    libANGLE/renderer/d3d/d3d11/Program11.cpp
    libANGLE/renderer/d3d/d3d11/Program11.h
    libANGLE/renderer/d3d/d3d11/ProgramPipeline11.cpp
    libANGLE/renderer/d3d/d3d11/ProgramPipeline11.h
    libANGLE/renderer/d3d/d3d11/Query11.cpp
    libANGLE/renderer/d3d/d3d11/Query11.h
    libANGLE/renderer/d3d/d3d11/Renderer11.cpp
    libANGLE/renderer/d3d/d3d11/Renderer11.h
    libANGLE/renderer/d3d/d3d11/renderer11_utils.cpp
    libANGLE/renderer/d3d/d3d11/renderer11_utils.h
    libANGLE/renderer/d3d/d3d11/RenderStateCache.cpp
    libANGLE/renderer/d3d/d3d11/RenderStateCache.h
    libANGLE/renderer/d3d/d3d11/RenderTarget11.cpp
    libANGLE/renderer/d3d/d3d11/RenderTarget11.h
    libANGLE/renderer/d3d/d3d11/ResourceManager11.cpp
    libANGLE/renderer/d3d/d3d11/ResourceManager11.h
    libANGLE/renderer/d3d/d3d11/ShaderExecutable11.cpp
    libANGLE/renderer/d3d/d3d11/ShaderExecutable11.h
    libANGLE/renderer/d3d/d3d11/StateManager11.cpp
    libANGLE/renderer/d3d/d3d11/StateManager11.h
    libANGLE/renderer/d3d/d3d11/StreamProducerD3DTexture.cpp
    libANGLE/renderer/d3d/d3d11/StreamProducerD3DTexture.h
    libANGLE/renderer/d3d/d3d11/SwapChain11.cpp
    libANGLE/renderer/d3d/d3d11/SwapChain11.h
    libANGLE/renderer/d3d/d3d11/TextureStorage11.cpp
    libANGLE/renderer/d3d/d3d11/TextureStorage11.h
    # libANGLE/renderer/d3d/d3d11/texture_format_data.json
    # libANGLE/renderer/d3d/d3d11/texture_format_map.json
    libANGLE/renderer/d3d/d3d11/texture_format_table.cpp
    libANGLE/renderer/d3d/d3d11/texture_format_table.h
    libANGLE/renderer/d3d/d3d11/texture_format_table_autogen.cpp
    libANGLE/renderer/d3d/d3d11/texture_format_table_utils.h
    libANGLE/renderer/d3d/d3d11/TransformFeedback11.cpp
    libANGLE/renderer/d3d/d3d11/TransformFeedback11.h
    libANGLE/renderer/d3d/d3d11/Trim11.cpp
    libANGLE/renderer/d3d/d3d11/Trim11.h
    libANGLE/renderer/d3d/d3d11/UniformBlockToStructuredBufferTranslation.md
    libANGLE/renderer/d3d/d3d11/VertexArray11.cpp
    libANGLE/renderer/d3d/d3d11/VertexArray11.h
    libANGLE/renderer/d3d/d3d11/VertexBuffer11.cpp
    libANGLE/renderer/d3d/d3d11/VertexBuffer11.h

    libANGLE/renderer/d3d/d3d11/converged/CompositorNativeWindow11.cpp
    libANGLE/renderer/d3d/d3d11/converged/CompositorNativeWindow11.h

    libANGLE/renderer/d3d/d3d11/win32/NativeWindow11Win32.cpp
    libANGLE/renderer/d3d/d3d11/win32/NativeWindow11Win32.h

    # libANGLE/renderer/d3d/d3d11/winrt/CoreWindowNativeWindow.cpp
    # libANGLE/renderer/d3d/d3d11/winrt/CoreWindowNativeWindow.h
    # libANGLE/renderer/d3d/d3d11/winrt/CoreWindowNativeWindow_unittest.cpp
    # libANGLE/renderer/d3d/d3d11/winrt/InspectableNativeWindow.cpp
    # libANGLE/renderer/d3d/d3d11/winrt/InspectableNativeWindow.h
    # libANGLE/renderer/d3d/d3d11/winrt/NativeWindow11WinRT.cpp
    # libANGLE/renderer/d3d/d3d11/winrt/NativeWindow11WinRT.h
    # libANGLE/renderer/d3d/d3d11/winrt/SwapChainPanelNativeWindow.cpp
    # libANGLE/renderer/d3d/d3d11/winrt/SwapChainPanelNativeWindow.h
    # libANGLE/renderer/d3d/d3d11/winrt/SwapChainPanelNativeWindow_unittest.cpp

    libANGLE/renderer/d3d/d3d9/Blit9.cpp
    libANGLE/renderer/d3d/d3d9/Blit9.h
    libANGLE/renderer/d3d/d3d9/Buffer9.cpp
    libANGLE/renderer/d3d/d3d9/Buffer9.h
    libANGLE/renderer/d3d/d3d9/Context9.cpp
    libANGLE/renderer/d3d/d3d9/Context9.h
    libANGLE/renderer/d3d/d3d9/DebugAnnotator9.cpp
    libANGLE/renderer/d3d/d3d9/DebugAnnotator9.h
    libANGLE/renderer/d3d/d3d9/Fence9.cpp
    libANGLE/renderer/d3d/d3d9/Fence9.h
    libANGLE/renderer/d3d/d3d9/formatutils9.cpp
    libANGLE/renderer/d3d/d3d9/formatutils9.h
    libANGLE/renderer/d3d/d3d9/Framebuffer9.cpp
    libANGLE/renderer/d3d/d3d9/Framebuffer9.h
    libANGLE/renderer/d3d/d3d9/Image9.cpp
    libANGLE/renderer/d3d/d3d9/Image9.h
    libANGLE/renderer/d3d/d3d9/IndexBuffer9.cpp
    libANGLE/renderer/d3d/d3d9/IndexBuffer9.h
    libANGLE/renderer/d3d/d3d9/NativeWindow9.cpp
    libANGLE/renderer/d3d/d3d9/NativeWindow9.h
    libANGLE/renderer/d3d/d3d9/Query9.cpp
    libANGLE/renderer/d3d/d3d9/Query9.h
    libANGLE/renderer/d3d/d3d9/Renderer9.cpp
    libANGLE/renderer/d3d/d3d9/Renderer9.h
    libANGLE/renderer/d3d/d3d9/renderer9_utils.cpp
    libANGLE/renderer/d3d/d3d9/renderer9_utils.h
    libANGLE/renderer/d3d/d3d9/RenderTarget9.cpp
    libANGLE/renderer/d3d/d3d9/RenderTarget9.h
    libANGLE/renderer/d3d/d3d9/ShaderCache.h
    libANGLE/renderer/d3d/d3d9/ShaderExecutable9.cpp
    libANGLE/renderer/d3d/d3d9/ShaderExecutable9.h
    libANGLE/renderer/d3d/d3d9/StateManager9.cpp
    libANGLE/renderer/d3d/d3d9/StateManager9.h
    libANGLE/renderer/d3d/d3d9/SwapChain9.cpp
    libANGLE/renderer/d3d/d3d9/SwapChain9.h
    libANGLE/renderer/d3d/d3d9/TextureStorage9.cpp
    libANGLE/renderer/d3d/d3d9/TextureStorage9.h
    libANGLE/renderer/d3d/d3d9/VertexArray9.h
    libANGLE/renderer/d3d/d3d9/VertexBuffer9.cpp
    libANGLE/renderer/d3d/d3d9/VertexBuffer9.h
    libANGLE/renderer/d3d/d3d9/vertexconversion.h
    libANGLE/renderer/d3d/d3d9/VertexDeclarationCache.cpp
    libANGLE/renderer/d3d/d3d9/VertexDeclarationCache.h

    libANGLE/renderer/gl/BlitGL.cpp
    libANGLE/renderer/gl/BlitGL.h
    libANGLE/renderer/gl/BufferGL.cpp
    libANGLE/renderer/gl/BufferGL.h
    libANGLE/renderer/gl/BUILD.gn
    libANGLE/renderer/gl/ClearMultiviewGL.cpp
    libANGLE/renderer/gl/ClearMultiviewGL.h
    libANGLE/renderer/gl/CompilerGL.cpp
    libANGLE/renderer/gl/CompilerGL.h
    libANGLE/renderer/gl/ContextGL.cpp
    libANGLE/renderer/gl/ContextGL.h
    libANGLE/renderer/gl/DispatchTableGL_autogen.cpp
    libANGLE/renderer/gl/DispatchTableGL_autogen.h
    libANGLE/renderer/gl/DisplayGL.cpp
    libANGLE/renderer/gl/DisplayGL.h
    # libANGLE/renderer/gl/DisplayGL_unittest.cpp
    libANGLE/renderer/gl/FeatureSupportGL.md
    libANGLE/renderer/gl/FenceNVGL.cpp
    libANGLE/renderer/gl/FenceNVGL.h
    libANGLE/renderer/gl/formatutilsgl.cpp
    libANGLE/renderer/gl/formatutilsgl.h
    libANGLE/renderer/gl/FramebufferGL.cpp
    libANGLE/renderer/gl/FramebufferGL.h
    libANGLE/renderer/gl/FunctionsGL.cpp
    libANGLE/renderer/gl/FunctionsGL.h
    libANGLE/renderer/gl/functionsgl_enums.h
    libANGLE/renderer/gl/functionsgl_typedefs.h
    # libANGLE/renderer/gl/generate_gl_dispatch_table.py
    libANGLE/renderer/gl/gl_backend.gni
    # libANGLE/renderer/gl/gl_bindings_data.json
    libANGLE/renderer/gl/ImageGL.cpp
    libANGLE/renderer/gl/ImageGL.h
    libANGLE/renderer/gl/MemoryObjectGL.cpp
    libANGLE/renderer/gl/MemoryObjectGL.h
    libANGLE/renderer/gl/null_functions.cpp
    libANGLE/renderer/gl/null_functions.h
    libANGLE/renderer/gl/OWNERS
    libANGLE/renderer/gl/PLSProgramCache.cpp
    libANGLE/renderer/gl/PLSProgramCache.h
    libANGLE/renderer/gl/ProgramGL.cpp
    libANGLE/renderer/gl/ProgramGL.h
    libANGLE/renderer/gl/ProgramPipelineGL.cpp
    libANGLE/renderer/gl/ProgramPipelineGL.h
    libANGLE/renderer/gl/QueryGL.cpp
    libANGLE/renderer/gl/QueryGL.h
    libANGLE/renderer/gl/RenderbufferGL.cpp
    libANGLE/renderer/gl/RenderbufferGL.h
    libANGLE/renderer/gl/RendererGL.cpp
    libANGLE/renderer/gl/RendererGL.h
    libANGLE/renderer/gl/renderergl_utils.cpp
    libANGLE/renderer/gl/renderergl_utils.h
    libANGLE/renderer/gl/SamplerGL.cpp
    libANGLE/renderer/gl/SamplerGL.h
    libANGLE/renderer/gl/SemaphoreGL.cpp
    libANGLE/renderer/gl/SemaphoreGL.h
    libANGLE/renderer/gl/ShaderGL.cpp
    libANGLE/renderer/gl/ShaderGL.h
    libANGLE/renderer/gl/StateManagerGL.cpp
    libANGLE/renderer/gl/StateManagerGL.h
    libANGLE/renderer/gl/SurfaceGL.cpp
    libANGLE/renderer/gl/SurfaceGL.h
    libANGLE/renderer/gl/SyncGL.cpp
    libANGLE/renderer/gl/SyncGL.h
    libANGLE/renderer/gl/TextureGL.cpp
    libANGLE/renderer/gl/TextureGL.h
    libANGLE/renderer/gl/TransformFeedbackGL.cpp
    libANGLE/renderer/gl/TransformFeedbackGL.h
    libANGLE/renderer/gl/VertexArrayGL.cpp
    libANGLE/renderer/gl/VertexArrayGL.h

    libANGLE/renderer/gl/wgl/ContextWGL.cpp
    libANGLE/renderer/gl/wgl/ContextWGL.h
    libANGLE/renderer/gl/wgl/D3DTextureSurfaceWGL.cpp
    libANGLE/renderer/gl/wgl/D3DTextureSurfaceWGL.h
    libANGLE/renderer/gl/wgl/DisplayWGL.cpp
    libANGLE/renderer/gl/wgl/DisplayWGL.h
    libANGLE/renderer/gl/wgl/DXGISwapChainWindowSurfaceWGL.cpp
    libANGLE/renderer/gl/wgl/DXGISwapChainWindowSurfaceWGL.h
    libANGLE/renderer/gl/wgl/FunctionsWGL.cpp
    libANGLE/renderer/gl/wgl/FunctionsWGL.h
    libANGLE/renderer/gl/wgl/functionswgl_typedefs.h
    libANGLE/renderer/gl/wgl/PbufferSurfaceWGL.cpp
    libANGLE/renderer/gl/wgl/PbufferSurfaceWGL.h
    libANGLE/renderer/gl/wgl/RendererWGL.cpp
    libANGLE/renderer/gl/wgl/RendererWGL.h
    libANGLE/renderer/gl/wgl/SurfaceWGL.h
    libANGLE/renderer/gl/wgl/wgl_utils.cpp
    libANGLE/renderer/gl/wgl/wgl_utils.h
    libANGLE/renderer/gl/wgl/WindowSurfaceWGL.cpp
    libANGLE/renderer/gl/wgl/WindowSurfaceWGL.h

    libGLESv2/cl_dispatch_table.cpp
    libGLESv2/cl_dispatch_table.h
    libGLESv2/cl_stubs.cpp
    libGLESv2/cl_stubs_autogen.h
    libGLESv2/egl_ext_stubs.cpp
    libGLESv2/egl_ext_stubs_autogen.h
    libGLESv2/egl_get_labeled_object_data.json
    libGLESv2/egl_stubs.cpp
    libGLESv2/egl_stubs_autogen.h
    # libGLESv2/entry_points_cl_autogen.cpp
    # libGLESv2/entry_points_cl_autogen.h
    # libGLESv2/entry_points_cl_utils.cpp
    # libGLESv2/entry_points_cl_utils.h
    libGLESv2/entry_points_egl_autogen.cpp
    libGLESv2/entry_points_egl_autogen.h
    libGLESv2/entry_points_egl_ext_autogen.cpp
    libGLESv2/entry_points_egl_ext_autogen.h
    libGLESv2/entry_points_gles_1_0_autogen.cpp
    libGLESv2/entry_points_gles_1_0_autogen.h
    libGLESv2/entry_points_gles_2_0_autogen.cpp
    libGLESv2/entry_points_gles_2_0_autogen.h
    libGLESv2/entry_points_gles_3_0_autogen.cpp
    libGLESv2/entry_points_gles_3_0_autogen.h
    libGLESv2/entry_points_gles_3_1_autogen.cpp
    libGLESv2/entry_points_gles_3_1_autogen.h
    libGLESv2/entry_points_gles_3_2_autogen.cpp
    libGLESv2/entry_points_gles_3_2_autogen.h
    libGLESv2/entry_points_gles_ext_autogen.cpp
    libGLESv2/entry_points_gles_ext_autogen.h
    # libGLESv2/entry_points_glx.cpp
    # libGLESv2/entry_points_glx.h
    libGLESv2/entry_points_gl_1_autogen.cpp
    libGLESv2/entry_points_gl_1_autogen.h
    libGLESv2/entry_points_gl_2_autogen.cpp
    libGLESv2/entry_points_gl_2_autogen.h
    libGLESv2/entry_points_gl_3_autogen.cpp
    libGLESv2/entry_points_gl_3_autogen.h
    libGLESv2/entry_points_gl_4_autogen.cpp
    libGLESv2/entry_points_gl_4_autogen.h
    # libGLESv2/entry_points_wgl.cpp
    # libGLESv2/entry_points_wgl.h
    libGLESv2/global_state.cpp
    libGLESv2/global_state.h
    # libGLESv2/libGLESv2.rc
    libGLESv2/libGLESv2_autogen.cpp
    # libGLESv2/libGLESv2_autogen.def
    # libGLESv2/libGLESv2_no_capture_autogen.def
    # libGLESv2/libGLESv2_vulkan_secondaries_autogen.def
    # libGLESv2/libGLESv2_with_capture_autogen.def
    # libGLESv2/opengl32_autogen.def
    # libGLESv2/opengl32_with_wgl_autogen.def
    # libGLESv2/proc_table_cl.h
    # libGLESv2/proc_table_cl_autogen.cpp
    libGLESv2/proc_table_egl.h
    libGLESv2/proc_table_egl_autogen.cpp
    # libGLESv2/proc_table_glx.h
    # libGLESv2/proc_table_glx_autogen.cpp
    # libGLESv2/proc_table_wgl.h
    # libGLESv2/proc_table_wgl_autogen.cpp
    libGLESv2/resource.h

    libEGL/egl_loader_autogen.cpp
    libEGL/egl_loader_autogen.h
    # libEGL/libEGL.rc
    libEGL/libEGL_autogen.cpp
    # libEGL/libEGL_autogen.def
    # libEGL/libEGL_vulkan_secondaries_autogen.def
    libEGL/resource.h
)

generate_version(tg_angle)
generate_commit_id(tg_angle)
