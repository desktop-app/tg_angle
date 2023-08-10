// GENERATED FILE - DO NOT EDIT.
// Generated by gen_extensions.py using data from registry_xml.py and gl.xml
//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// gles_extensions_autogen.h: GLES extension information.

#ifndef LIBANGLE_GLES_EXTENSIONS_AUTOGEN_H_
#define LIBANGLE_GLES_EXTENSIONS_AUTOGEN_H_

namespace gl
{
class TextureCapsMap;

struct Extensions
{
    Extensions();
    Extensions(const Extensions &other);

    Extensions &operator=(const Extensions &other);

    // Generate a vector of supported extension strings
    std::vector<std::string> getStrings() const;

    // Set all texture related extension support based on the supported textures.
    // Determines support for:
    // GL_OES_packed_depth_stencil
    // GL_OES_rgb8_rgba8
    // GL_EXT_texture_format_BGRA8888
    // GL_EXT_color_buffer_half_float,
    // GL_OES_texture_half_float, GL_OES_texture_half_float_linear
    // GL_OES_texture_float, GL_OES_texture_float_linear
    // GL_EXT_texture_rg
    // GL_EXT_texture_type_2_10_10_10_REV
    // GL_EXT_texture_compression_dxt1, GL_ANGLE_texture_compression_dxt3,
    // GL_ANGLE_texture_compression_dxt5
    // GL_KHR_texture_compression_astc_ldr, GL_OES_texture_compression_astc.
    //     NOTE: GL_KHR_texture_compression_astc_hdr must be enabled separately. Support for the
    //           HDR profile cannot be determined from the format enums alone.
    // GL_OES_compressed_ETC1_RGB8_texture
    // GL_EXT_sRGB
    // GL_ANGLE_depth_texture, GL_OES_depth32
    // GL_EXT_color_buffer_float
    // GL_EXT_texture_norm16
    // GL_EXT_texture_compression_bptc
    // GL_EXT_texture_compression_rgtc
    void setTextureExtensionSupport(const TextureCapsMap &textureCaps);

    // Helper functions
    bool clipCullDistanceAny() const { return (clipCullDistanceANGLE || clipCullDistanceEXT); }
    bool copyImageAny() const { return (copyImageEXT || copyImageOES); }
    bool depthTextureAny() const { return (depthTextureANGLE || depthTextureOES); }
    bool drawBuffersIndexedAny() const { return (drawBuffersIndexedEXT || drawBuffersIndexedOES); }
    bool drawElementsBaseVertexAny() const
    {
        return (drawElementsBaseVertexEXT || drawElementsBaseVertexOES);
    }
    bool framebufferBlitAny() const { return (framebufferBlitANGLE || framebufferBlitNV); }
    bool geometryShaderAny() const { return (geometryShaderEXT || geometryShaderOES); }
    bool instancedArraysAny() const { return (instancedArraysANGLE || instancedArraysEXT); }
    bool polygonModeAny() const { return (polygonModeANGLE || polygonModeNV); }
    bool primitiveBoundingBoxAny() const
    {
        return (primitiveBoundingBoxEXT || primitiveBoundingBoxOES);
    }
    bool shaderFramebufferFetchAny() const
    {
        return (shaderFramebufferFetchARM || shaderFramebufferFetchEXT);
    }
    bool shaderIoBlocksAny() const { return (shaderIoBlocksEXT || shaderIoBlocksOES); }
    bool textureBorderClampAny() const { return (textureBorderClampEXT || textureBorderClampOES); }
    bool textureBufferAny() const { return (textureBufferEXT || textureBufferOES); }
    bool textureCubeMapArrayAny() const
    {
        return (textureCubeMapArrayEXT || textureCubeMapArrayOES);
    }

    // GLES 2.0+ extensions
    // --------------------

    // GL_EXT_base_instance
    bool baseInstanceEXT = false;

    // GL_KHR_blend_equation_advanced
    bool blendEquationAdvancedKHR = false;

    // GL_EXT_blend_func_extended
    bool blendFuncExtendedEXT = false;

    // GL_EXT_blend_minmax
    bool blendMinmaxEXT = false;

    // GL_EXT_buffer_storage
    bool bufferStorageEXT = false;

    // GL_EXT_clip_control
    bool clipControlEXT = false;

    // GL_EXT_clip_cull_distance
    bool clipCullDistanceEXT = false;

    // GL_APPLE_clip_distance
    bool clipDistanceAPPLE = false;

    // GL_EXT_color_buffer_float
    bool colorBufferFloatEXT = false;

    // GL_EXT_color_buffer_half_float
    bool colorBufferHalfFloatEXT = false;

    // GL_OES_compressed_EAC_R11_signed_texture
    bool compressedEACR11SignedTextureOES = false;

    // GL_OES_compressed_EAC_R11_unsigned_texture
    bool compressedEACR11UnsignedTextureOES = false;

    // GL_OES_compressed_EAC_RG11_signed_texture
    bool compressedEACRG11SignedTextureOES = false;

    // GL_OES_compressed_EAC_RG11_unsigned_texture
    bool compressedEACRG11UnsignedTextureOES = false;

    // GL_EXT_compressed_ETC1_RGB8_sub_texture
    bool compressedETC1RGB8SubTextureEXT = false;

    // GL_OES_compressed_ETC1_RGB8_texture
    bool compressedETC1RGB8TextureOES = false;

    // GL_OES_compressed_ETC2_punchthroughA_RGBA8_texture
    bool compressedETC2PunchthroughARGBA8TextureOES = false;

    // GL_OES_compressed_ETC2_punchthroughA_sRGB8_alpha_texture
    bool compressedETC2PunchthroughASRGB8AlphaTextureOES = false;

    // GL_OES_compressed_ETC2_RGB8_texture
    bool compressedETC2RGB8TextureOES = false;

    // GL_OES_compressed_ETC2_RGBA8_texture
    bool compressedETC2RGBA8TextureOES = false;

    // GL_OES_compressed_ETC2_sRGB8_alpha8_texture
    bool compressedETC2SRGB8Alpha8TextureOES = false;

    // GL_OES_compressed_ETC2_sRGB8_texture
    bool compressedETC2SRGB8TextureOES = false;

    // GL_OES_compressed_paletted_texture
    bool compressedPalettedTextureOES = false;

    // GL_EXT_conservative_depth
    bool conservativeDepthEXT = false;

    // GL_EXT_copy_image
    bool copyImageEXT = false;

    // GL_OES_copy_image
    bool copyImageOES = false;

    // GL_KHR_debug
    bool debugKHR = false;

    // GL_EXT_debug_label
    bool debugLabelEXT = false;

    // GL_EXT_debug_marker
    bool debugMarkerEXT = false;

    // GL_OES_depth24
    bool depth24OES = false;

    // GL_OES_depth32
    bool depth32OES = false;

    // GL_NV_depth_buffer_float2
    bool depthBufferFloat2NV = false;

    // GL_EXT_depth_clamp
    bool depthClampEXT = false;

    // GL_ANGLE_depth_texture
    bool depthTextureANGLE = false;

    // GL_OES_depth_texture
    bool depthTextureOES = false;

    // GL_OES_depth_texture_cube_map
    bool depthTextureCubeMapOES = false;

    // GL_EXT_discard_framebuffer
    bool discardFramebufferEXT = false;

    // GL_EXT_disjoint_timer_query
    bool disjointTimerQueryEXT = false;

    // GL_EXT_draw_buffers
    bool drawBuffersEXT = false;

    // GL_EXT_draw_buffers_indexed
    bool drawBuffersIndexedEXT = false;

    // GL_OES_draw_buffers_indexed
    bool drawBuffersIndexedOES = false;

    // GL_EXT_draw_elements_base_vertex
    bool drawElementsBaseVertexEXT = false;

    // GL_OES_draw_elements_base_vertex
    bool drawElementsBaseVertexOES = false;

    // GL_OES_EGL_image
    bool EGLImageOES = false;

    // GL_EXT_EGL_image_array
    bool EGLImageArrayEXT = false;

    // GL_OES_EGL_image_external
    bool EGLImageExternalOES = false;

    // GL_OES_EGL_image_external_essl3
    bool EGLImageExternalEssl3OES = false;

    // GL_EXT_EGL_image_external_wrap_modes
    bool EGLImageExternalWrapModesEXT = false;

    // GL_EXT_EGL_image_storage
    bool EGLImageStorageEXT = false;

    // GL_NV_EGL_stream_consumer_external
    bool EGLStreamConsumerExternalNV = false;

    // GL_OES_EGL_sync
    bool EGLSyncOES = false;

    // GL_OES_element_index_uint
    bool elementIndexUintOES = false;

    // GL_ANDROID_extension_pack_es31a
    bool extensionPackEs31aANDROID = false;

    // GL_EXT_external_buffer
    bool externalBufferEXT = false;

    // GL_OES_fbo_render_mipmap
    bool fboRenderMipmapOES = false;

    // GL_NV_fence
    bool fenceNV = false;

    // GL_EXT_float_blend
    bool floatBlendEXT = false;

    // GL_EXT_frag_depth
    bool fragDepthEXT = false;

    // GL_ANGLE_framebuffer_blit
    bool framebufferBlitANGLE = false;

    // GL_NV_framebuffer_blit
    bool framebufferBlitNV = false;

    // GL_MESA_framebuffer_flip_y
    bool framebufferFlipYMESA = false;

    // GL_EXT_geometry_shader
    bool geometryShaderEXT = false;

    // GL_OES_geometry_shader
    bool geometryShaderOES = false;

    // GL_OES_get_program_binary
    bool getProgramBinaryOES = false;

    // GL_EXT_gpu_shader5
    bool gpuShader5EXT = false;

    // GL_ANGLE_instanced_arrays
    bool instancedArraysANGLE = false;

    // GL_EXT_instanced_arrays
    bool instancedArraysEXT = false;

    // GL_OES_mapbuffer
    bool mapbufferOES = false;

    // GL_EXT_map_buffer_range
    bool mapBufferRangeEXT = false;

    // GL_EXT_memory_object
    bool memoryObjectEXT = false;

    // GL_EXT_memory_object_fd
    bool memoryObjectFdEXT = false;

    // GL_EXT_multi_draw_indirect
    bool multiDrawIndirectEXT = false;

    // GL_EXT_multisample_compatibility
    bool multisampleCompatibilityEXT = false;

    // GL_EXT_multisampled_render_to_texture
    bool multisampledRenderToTextureEXT = false;

    // GL_EXT_multisampled_render_to_texture2
    bool multisampledRenderToTexture2EXT = false;

    // GL_OVR_multiview
    bool multiviewOVR = false;

    // GL_OVR_multiview2
    bool multiview2OVR = false;

    // GL_KHR_no_error
    bool noErrorKHR = false;

    // GL_EXT_occlusion_query_boolean
    bool occlusionQueryBooleanEXT = false;

    // GL_OES_packed_depth_stencil
    bool packedDepthStencilOES = false;

    // GL_ANGLE_pack_reverse_row_order
    bool packReverseRowOrderANGLE = false;

    // GL_NV_pack_subimage
    bool packSubimageNV = false;

    // GL_KHR_parallel_shader_compile
    bool parallelShaderCompileKHR = false;

    // GL_AMD_performance_monitor
    bool performanceMonitorAMD = false;

    // GL_NV_pixel_buffer_object
    bool pixelBufferObjectNV = false;

    // GL_NV_polygon_mode
    bool polygonModeNV = false;

    // GL_EXT_polygon_offset_clamp
    bool polygonOffsetClampEXT = false;

    // GL_EXT_primitive_bounding_box
    bool primitiveBoundingBoxEXT = false;

    // GL_OES_primitive_bounding_box
    bool primitiveBoundingBoxOES = false;

    // GL_EXT_protected_textures
    bool protectedTexturesEXT = false;

    // GL_EXT_pvrtc_sRGB
    bool pvrtcSRGBEXT = false;

    // GL_NV_read_depth
    bool readDepthNV = false;

    // GL_NV_read_depth_stencil
    bool readDepthStencilNV = false;

    // GL_EXT_read_format_bgra
    bool readFormatBgraEXT = false;

    // GL_NV_read_stencil
    bool readStencilNV = false;

    // GL_QCOM_render_shared_exponent
    bool renderSharedExponentQCOM = false;

    // GL_EXT_render_snorm
    bool renderSnormEXT = false;

    // GL_OES_rgb8_rgba8
    bool rgb8Rgba8OES = false;

    // GL_KHR_robust_buffer_access_behavior
    bool robustBufferAccessBehaviorKHR = false;

    // GL_EXT_robustness
    bool robustnessEXT = false;

    // GL_NV_robustness_video_memory_purge
    bool robustnessVideoMemoryPurgeNV = false;

    // GL_OES_sample_shading
    bool sampleShadingOES = false;

    // GL_OES_sample_variables
    bool sampleVariablesOES = false;

    // GL_EXT_semaphore
    bool semaphoreEXT = false;

    // GL_EXT_semaphore_fd
    bool semaphoreFdEXT = false;

    // GL_EXT_separate_shader_objects
    bool separateShaderObjectsEXT = false;

    // GL_ARM_shader_framebuffer_fetch
    bool shaderFramebufferFetchARM = false;

    // GL_EXT_shader_framebuffer_fetch
    bool shaderFramebufferFetchEXT = false;

    // GL_EXT_shader_framebuffer_fetch_non_coherent
    bool shaderFramebufferFetchNonCoherentEXT = false;

    // GL_OES_shader_image_atomic
    bool shaderImageAtomicOES = false;

    // GL_EXT_shader_io_blocks
    bool shaderIoBlocksEXT = false;

    // GL_OES_shader_io_blocks
    bool shaderIoBlocksOES = false;

    // GL_OES_shader_multisample_interpolation
    bool shaderMultisampleInterpolationOES = false;

    // GL_EXT_shader_non_constant_global_initializers
    bool shaderNonConstantGlobalInitializersEXT = false;

    // GL_NV_shader_noperspective_interpolation
    bool shaderNoperspectiveInterpolationNV = false;

    // GL_EXT_shader_texture_lod
    bool shaderTextureLodEXT = false;

    // GL_QCOM_shading_rate
    bool shadingRateQCOM = false;

    // GL_EXT_shadow_samplers
    bool shadowSamplersEXT = false;

    // GL_EXT_sRGB
    bool sRGBEXT = false;

    // GL_EXT_sRGB_write_control
    bool sRGBWriteControlEXT = false;

    // GL_OES_standard_derivatives
    bool standardDerivativesOES = false;

    // GL_OES_surfaceless_context
    bool surfacelessContextOES = false;

    // GL_ARB_sync
    bool syncARB = false;

    // GL_EXT_tessellation_shader
    bool tessellationShaderEXT = false;

    // GL_OES_texture_3D
    bool texture3DOES = false;

    // GL_EXT_texture_border_clamp
    bool textureBorderClampEXT = false;

    // GL_OES_texture_border_clamp
    bool textureBorderClampOES = false;

    // GL_EXT_texture_buffer
    bool textureBufferEXT = false;

    // GL_OES_texture_buffer
    bool textureBufferOES = false;

    // GL_OES_texture_compression_astc
    bool textureCompressionAstcOES = false;

    // GL_KHR_texture_compression_astc_hdr
    bool textureCompressionAstcHdrKHR = false;

    // GL_KHR_texture_compression_astc_ldr
    bool textureCompressionAstcLdrKHR = false;

    // GL_KHR_texture_compression_astc_sliced_3d
    bool textureCompressionAstcSliced3dKHR = false;

    // GL_EXT_texture_compression_bptc
    bool textureCompressionBptcEXT = false;

    // GL_EXT_texture_compression_dxt1
    bool textureCompressionDxt1EXT = false;

    // GL_IMG_texture_compression_pvrtc
    bool textureCompressionPvrtcIMG = false;

    // GL_IMG_texture_compression_pvrtc2
    bool textureCompressionPvrtc2IMG = false;

    // GL_EXT_texture_compression_rgtc
    bool textureCompressionRgtcEXT = false;

    // GL_EXT_texture_compression_s3tc
    bool textureCompressionS3tcEXT = false;

    // GL_EXT_texture_compression_s3tc_srgb
    bool textureCompressionS3tcSrgbEXT = false;

    // GL_EXT_texture_cube_map_array
    bool textureCubeMapArrayEXT = false;

    // GL_OES_texture_cube_map_array
    bool textureCubeMapArrayOES = false;

    // GL_EXT_texture_filter_anisotropic
    bool textureFilterAnisotropicEXT = false;

    // GL_EXT_texture_filter_minmax
    bool textureFilterMinmaxEXT = false;

    // GL_OES_texture_float
    bool textureFloatOES = false;

    // GL_OES_texture_float_linear
    bool textureFloatLinearOES = false;

    // GL_EXT_texture_format_BGRA8888
    bool textureFormatBGRA8888EXT = false;

    // GL_EXT_texture_format_sRGB_override
    bool textureFormatSRGBOverrideEXT = false;

    // GL_OES_texture_half_float
    bool textureHalfFloatOES = false;

    // GL_OES_texture_half_float_linear
    bool textureHalfFloatLinearOES = false;

    // GL_EXT_texture_mirror_clamp_to_edge
    bool textureMirrorClampToEdgeEXT = false;

    // GL_EXT_texture_norm16
    bool textureNorm16EXT = false;

    // GL_OES_texture_npot
    bool textureNpotOES = false;

    // GL_EXT_texture_rg
    bool textureRgEXT = false;

    // GL_EXT_texture_sRGB_decode
    bool textureSRGBDecodeEXT = false;

    // GL_EXT_texture_sRGB_R8
    bool textureSRGBR8EXT = false;

    // GL_EXT_texture_sRGB_RG8
    bool textureSRGBRG8EXT = false;

    // GL_OES_texture_stencil8
    bool textureStencil8OES = false;

    // GL_EXT_texture_storage
    bool textureStorageEXT = false;

    // GL_OES_texture_storage_multisample_2d_array
    bool textureStorageMultisample2dArrayOES = false;

    // GL_EXT_texture_type_2_10_10_10_REV
    bool textureType2101010REVEXT = false;

    // GL_ANGLE_texture_usage
    bool textureUsageANGLE = false;

    // GL_ANGLE_translated_shader_source
    bool translatedShaderSourceANGLE = false;

    // GL_EXT_unpack_subimage
    bool unpackSubimageEXT = false;

    // GL_OES_vertex_array_object
    bool vertexArrayObjectOES = false;

    // GL_OES_vertex_half_float
    bool vertexHalfFloatOES = false;

    // GL_OES_vertex_type_10_10_10_2
    bool vertexType1010102OES = false;

    // GL_WEBGL_video_texture
    bool videoTextureWEBGL = false;

    // GL_EXT_YUV_target
    bool YUVTargetEXT = false;

    // ANGLE unofficial extensions
    // ---------------------------

    // GL_ANGLE_base_vertex_base_instance
    bool baseVertexBaseInstanceANGLE = false;

    // GL_ANGLE_base_vertex_base_instance_shader_builtin
    bool baseVertexBaseInstanceShaderBuiltinANGLE = false;

    // GL_CHROMIUM_bind_generates_resource
    bool bindGeneratesResourceCHROMIUM = false;

    // GL_CHROMIUM_bind_uniform_location
    bool bindUniformLocationCHROMIUM = false;

    // GL_ANGLE_client_arrays
    bool clientArraysANGLE = false;

    // GL_ANGLE_clip_cull_distance
    bool clipCullDistanceANGLE = false;

    // GL_CHROMIUM_color_buffer_float_rgb
    bool colorBufferFloatRgbCHROMIUM = false;

    // GL_CHROMIUM_color_buffer_float_rgba
    bool colorBufferFloatRgbaCHROMIUM = false;

    // GL_ANGLE_compressed_texture_etc
    bool compressedTextureEtcANGLE = false;

    // GL_CHROMIUM_copy_compressed_texture
    bool copyCompressedTextureCHROMIUM = false;

    // GL_CHROMIUM_copy_texture
    bool copyTextureCHROMIUM = false;

    // GL_ANGLE_copy_texture_3d
    bool copyTexture3dANGLE = false;

    // GL_CHROMIUM_framebuffer_mixed_samples
    bool framebufferMixedSamplesCHROMIUM = false;

    // GL_ANGLE_framebuffer_multisample
    bool framebufferMultisampleANGLE = false;

    // GL_ANGLE_get_image
    bool getImageANGLE = false;

    // GL_ANGLE_get_serialized_context_string
    bool getSerializedContextStringANGLE = false;

    // GL_ANGLE_get_tex_level_parameter
    bool getTexLevelParameterANGLE = false;

    // GL_ANGLE_logic_op
    bool logicOpANGLE = false;

    // GL_CHROMIUM_lose_context
    bool loseContextCHROMIUM = false;

    // GL_ANGLE_lossy_etc_decode
    bool lossyEtcDecodeANGLE = false;

    // GL_ANGLE_memory_object_flags
    bool memoryObjectFlagsANGLE = false;

    // GL_ANGLE_memory_object_fuchsia
    bool memoryObjectFuchsiaANGLE = false;

    // GL_ANGLE_memory_size
    bool memorySizeANGLE = false;

    // GL_ANGLE_multi_draw
    bool multiDrawANGLE = false;

    // GL_ANGLE_multiview_multisample
    bool multiviewMultisampleANGLE = false;

    // GL_ANGLE_polygon_mode
    bool polygonModeANGLE = false;

    // GL_ANGLE_program_binary
    bool programBinaryANGLE = false;

    // GL_ANGLE_program_cache_control
    bool programCacheControlANGLE = false;

    // GL_ANGLE_provoking_vertex
    bool provokingVertexANGLE = false;

    // GL_ANGLE_read_only_depth_stencil_feedback_loops
    bool readOnlyDepthStencilFeedbackLoopsANGLE = false;

    // GL_ANGLE_relaxed_vertex_attribute_type
    bool relaxedVertexAttributeTypeANGLE = false;

    // GL_ANGLE_renderability_validation
    bool renderabilityValidationANGLE = false;

    // GL_ANGLE_request_extension
    bool requestExtensionANGLE = false;

    // GL_ANGLE_rgbx_internal_format
    bool rgbxInternalFormatANGLE = false;

    // GL_ANGLE_robust_client_memory
    bool robustClientMemoryANGLE = false;

    // GL_ANGLE_robust_fragment_shader_output
    bool robustFragmentShaderOutputANGLE = false;

    // GL_ANGLE_robust_resource_initialization
    bool robustResourceInitializationANGLE = false;

    // GL_ANGLE_semaphore_fuchsia
    bool semaphoreFuchsiaANGLE = false;

    // GL_ANGLE_shader_binary
    bool shaderBinaryANGLE = false;

    // GL_ANGLE_shader_pixel_local_storage
    bool shaderPixelLocalStorageANGLE = false;

    // GL_ANGLE_shader_pixel_local_storage_coherent
    bool shaderPixelLocalStorageCoherentANGLE = false;

    // GL_ANGLE_stencil_texturing
    bool stencilTexturingANGLE = false;

    // GL_CHROMIUM_sync_query
    bool syncQueryCHROMIUM = false;

    // GL_ANGLE_texture_compression_dxt3
    bool textureCompressionDxt3ANGLE = false;

    // GL_ANGLE_texture_compression_dxt5
    bool textureCompressionDxt5ANGLE = false;

    // GL_ANGLE_texture_external_update
    bool textureExternalUpdateANGLE = false;

    // GL_CHROMIUM_texture_filtering_hint
    bool textureFilteringHintCHROMIUM = false;

    // GL_ANGLE_texture_multisample
    bool textureMultisampleANGLE = false;

    // GL_ANGLE_texture_rectangle
    bool textureRectangleANGLE = false;

    // GL_ANGLE_vulkan_image
    bool vulkanImageANGLE = false;

    // GL_ANGLE_webgl_compatibility
    bool webglCompatibilityANGLE = false;

    // GL_ANGLE_yuv_internal_format
    bool yuvInternalFormatANGLE = false;

    // GLES 1.0 and 1.1 extensions
    // ---------------------------

    // GL_OES_draw_texture
    bool drawTextureOES = false;

    // GL_OES_framebuffer_object
    bool framebufferObjectOES = false;

    // GL_OES_matrix_palette
    bool matrixPaletteOES = false;

    // GL_OES_point_size_array
    bool pointSizeArrayOES = false;

    // GL_OES_point_sprite
    bool pointSpriteOES = false;

    // GL_OES_query_matrix
    bool queryMatrixOES = false;

    // GL_OES_texture_cube_map
    bool textureCubeMapOES = false;
};
}  // namespace gl

#endif  // LIBANGLE_GLES_EXTENSIONS_AUTOGEN_H_
