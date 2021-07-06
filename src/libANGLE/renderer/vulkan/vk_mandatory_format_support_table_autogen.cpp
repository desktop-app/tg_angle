// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_mandatory_format_support_table.py using data from
// vk_mandatory_format_support_data.json and the vk.xml file situated at
// /third_party/vulkan-validation-layers/src/scripts/vk.xml
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// vk_mandatory_format_support_table_autogen.cpp:
//   Queries for full Vulkan mandatory format support information based on VK format.

#include "libANGLE/renderer/vulkan/vk_format_utils.h"

using namespace angle;

namespace rx
{
namespace vk
{
namespace
{
constexpr VkFormatFeatureFlagBits BLIT_DST         = VK_FORMAT_FEATURE_BLIT_DST_BIT;
constexpr VkFormatFeatureFlagBits BLIT_SRC         = VK_FORMAT_FEATURE_BLIT_SRC_BIT;
constexpr VkFormatFeatureFlagBits COLOR_ATTACHMENT = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT;
constexpr VkFormatFeatureFlagBits COLOR_ATTACHMENT_BLEND =
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT;
constexpr VkFormatFeatureFlagBits DEPTH_STENCIL_ATTACHMENT =
    VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT;
constexpr VkFormatFeatureFlagBits SAMPLED_IMAGE = VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
constexpr VkFormatFeatureFlagBits SAMPLED_IMAGE_FILTER_LINEAR =
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT;
constexpr VkFormatFeatureFlagBits STORAGE_IMAGE        = VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT;
constexpr VkFormatFeatureFlagBits STORAGE_IMAGE_ATOMIC = VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT;
constexpr VkFormatFeatureFlagBits STORAGE_TEXEL_BUFFER = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT;
constexpr VkFormatFeatureFlagBits STORAGE_TEXEL_BUFFER_ATOMIC =
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT;
constexpr VkFormatFeatureFlagBits UNIFORM_TEXEL_BUFFER = VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT;
constexpr VkFormatFeatureFlagBits VERTEX_BUFFER        = VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;

using namespace angle;

constexpr FormatMap<VkFormatProperties> kFormatProperties = {
    {FormatID::R8G8_USCALED, {0, 0, 0}},
    {FormatID::D32_FLOAT_S8X24_UINT, {0, 0, 0}},
    {FormatID::ETC2_R8G8B8_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R32G32B32A32_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_10x8_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16_USCALED, {0, 0, 0}},
    {FormatID::BC4_RED_SNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16_SNORM, {0, 0, 0}},
    {FormatID::S8_UINT, {0, 0, 0}},
    {FormatID::R8G8B8_USCALED, {0, 0, 0}},
    {FormatID::ASTC_5x4_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::BC5_RG_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_8x5_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8G8_SNORM,
     {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16B16_UINT, {0, 0, 0}},
    {FormatID::ETC2_R8G8B8A8_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16_USCALED, {0, 0, 0}},
    {FormatID::BC3_RGBA_UNORM_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R11G11B10_FLOAT,
     {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR, UNIFORM_TEXEL_BUFFER}},
    {FormatID::D24_UNORM_S8_UINT, {0, 0, 0}},
    {FormatID::B4G4R4A4_UNORM, {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR, 0}},
    {FormatID::ASTC_12x10_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R8G8B8_SSCALED, {0, 0, 0}},
    {FormatID::R32G32B32_UINT, {0, 0, VERTEX_BUFFER}},
    {FormatID::R16_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::D16_UNORM, {0, BLIT_SRC | DEPTH_STENCIL_ATTACHMENT | SAMPLED_IMAGE, 0}},
    {FormatID::ASTC_4x4_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_8x8_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8_USCALED, {0, 0, 0}},
    {FormatID::R8G8B8_UNORM_SRGB, {0, 0, 0}},
    {FormatID::BPTC_RGB_UNSIGNED_FLOAT_BLOCK, {0, 0, 0}},
    {FormatID::B5G5R5A1_UNORM, {0, 0, 0}},
    {FormatID::R16G16_SSCALED, {0, 0, 0}},
    {FormatID::B8G8R8A8_UNORM_SRGB,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      0}},
    {FormatID::BC3_RGBA_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::G8_B8R8_2PLANE_420_UNORM, {0, 0, 0}},
    {FormatID::R16_FLOAT,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R8G8B8A8_SNORM,
     {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R8G8B8A8_SSCALED, {0, 0, 0}},
    {FormatID::R8_UNORM_SRGB, {0, 0, 0}},
    {FormatID::BC1_RGBA_UNORM_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_10x10_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R10G10B10A2_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_12x10_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_5x4_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_8x5_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16A16_USCALED, {0, 0, 0}},
    {FormatID::R8G8B8A8_UNORM_SRGB,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      0}},
    {FormatID::NONE, {0, 0, 0}},
    {FormatID::R32G32_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16_SNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::R16_UNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::R10G10B10A2_SINT, {0, 0, 0}},
    {FormatID::R16G16B16A16_FLOAT,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_5x5_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::EAC_R11_SNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_8x6_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8G8B8A8_USCALED, {0, 0, 0}},
    {FormatID::ASTC_6x5_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R8G8B8A8_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R5G6B5_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      0}},
    {FormatID::R8G8B8A8_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::B8G8R8A8_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R32G32B32A32_FLOAT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16B16_UNORM, {0, 0, 0}},
    {FormatID::BC2_RGBA_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_12x12_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ETC2_R8G8B8A8_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R10G10B10A2_SNORM, {0, 0, 0}},
    {FormatID::R8G8B8A8_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_6x6_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_10x10_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ETC2_R8G8B8A1_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16_SSCALED, {0, 0, 0}},
    {FormatID::R16G16_UNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::D32_FLOAT, {0, 0, 0}},
    {FormatID::R16G16B16A16_UNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::EAC_R11_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16A16_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16B16A16_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::BPTC_RGBA_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::A1R5G5B5_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      0}},
    {FormatID::ASTC_8x6_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::EAC_R11G11_SNORM_BLOCK, {0, 0, 0}},
    {FormatID::R10G10B10A2_SSCALED, {0, 0, 0}},
    {FormatID::BC1_RGBA_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R32G32_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R32G32B32_FLOAT, {0, 0, VERTEX_BUFFER}},
    {FormatID::R8_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_10x6_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::BC1_RGB_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R4G4B4A4_UNORM, {0, 0, 0}},
    {FormatID::BC1_RGB_UNORM_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::BPTC_RGB_SIGNED_FLOAT_BLOCK, {0, 0, 0}},
    {FormatID::R10G10B10A2_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE, UNIFORM_TEXEL_BUFFER}},
    {FormatID::ASTC_6x5_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R16G16_FLOAT,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::B5G6R5_UNORM, {0, 0, 0}},
    {FormatID::R32_FLOAT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_12x12_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_5x5_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R8G8B8_SINT, {0, 0, 0}},
    {FormatID::ASTC_8x8_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R32_SINT,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE | STORAGE_IMAGE_ATOMIC,
      STORAGE_TEXEL_BUFFER | STORAGE_TEXEL_BUFFER_ATOMIC | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ETC2_R8G8B8A1_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16_SSCALED, {0, 0, 0}},
    {FormatID::ASTC_6x6_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R8G8B8_SNORM, {0, 0, 0}},
    {FormatID::R16_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R8_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R32G32_FLOAT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::BC5_RG_SNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16B16A16_SNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::R8G8_UNORM,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | COLOR_ATTACHMENT_BLEND | SAMPLED_IMAGE |
          SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::ASTC_10x6_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_10x5_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::B10G10R10A2_UNORM, {0, 0, 0}},
    {FormatID::BC2_RGBA_UNORM_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R32G32B32_SINT, {0, 0, VERTEX_BUFFER}},
    {FormatID::R10G10B10A2_USCALED, {0, 0, 0}},
    {FormatID::R8G8_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16B16A16_SSCALED, {0, 0, 0}},
    {FormatID::ASTC_10x5_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8_SSCALED, {0, 0, 0}},
    {FormatID::R16G16B16_FLOAT, {0, 0, 0}},
    {FormatID::R8_SNORM,
     {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16_SNORM, {0, 0, VERTEX_BUFFER}},
    {FormatID::D24_UNORM_X8_UINT, {0, 0, 0}},
    {FormatID::R16G16_SINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R16G16B16_SINT, {0, 0, 0}},
    {FormatID::R8G8_SSCALED, {0, 0, 0}},
    {FormatID::EAC_R11G11_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_10x8_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::ASTC_4x4_SRGB_BLOCK, {0, 0, 0}},
    {FormatID::R8G8_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE,
      UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R5G5B5A1_UNORM, {0, 0, 0}},
    {FormatID::R8G8B8_UINT, {0, 0, 0}},
    {FormatID::G8_B8_R8_3PLANE_420_UNORM, {0, 0, 0}},
    {FormatID::ETC2_R8G8B8_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R32_UINT,
     {0,
      BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE | STORAGE_IMAGE_ATOMIC,
      STORAGE_TEXEL_BUFFER | STORAGE_TEXEL_BUFFER_ATOMIC | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::R9G9B9E5_SHAREDEXP, {0, BLIT_SRC | SAMPLED_IMAGE | SAMPLED_IMAGE_FILTER_LINEAR, 0}},
    {FormatID::BC4_RED_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R32G32B32A32_UINT,
     {0, BLIT_DST | BLIT_SRC | COLOR_ATTACHMENT | SAMPLED_IMAGE | STORAGE_IMAGE,
      STORAGE_TEXEL_BUFFER | UNIFORM_TEXEL_BUFFER | VERTEX_BUFFER}},
    {FormatID::BPTC_SRGB_ALPHA_UNORM_BLOCK, {0, 0, 0}},
    {FormatID::R16G16_USCALED, {0, 0, 0}}};
}  // anonymous namespace

const VkFormatProperties &GetMandatoryFormatSupport(FormatID formatID)
{
    return kFormatProperties[formatID];
}
}  // namespace vk
}  // namespace rx
