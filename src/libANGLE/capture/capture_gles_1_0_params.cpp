//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// capture_gles1_params.cpp:
//   Pointer parameter capture functions for the OpenGL ES 1.0 entry points.

#include "libANGLE/capture/capture_gles_1_0_autogen.h"

using namespace angle;

namespace gl
{

void CaptureClipPlanef_eqn(const State &glState,
                           bool isCallValid,
                           GLenum p,
                           const GLfloat *eqn,
                           ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureClipPlanex_equation(const State &glState,
                                bool isCallValid,
                                GLenum plane,
                                const GLfixed *equation,
                                ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureColorPointer_pointer(const State &glState,
                                 bool isCallValid,
                                 GLint size,
                                 VertexAttribType typePacked,
                                 GLsizei stride,
                                 const void *pointer,
                                 ParamCapture *paramCapture)
{
    CaptureVertexPointerGLES1(glState, ClientVertexArrayType::Color, pointer, paramCapture);
}

void CaptureFogfv_params(const State &glState,
                         bool isCallValid,
                         GLenum pname,
                         const GLfloat *params,
                         ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureFogxv_param(const State &glState,
                        bool isCallValid,
                        GLenum pname,
                        const GLfixed *param,
                        ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetClipPlanef_equation(const State &glState,
                                   bool isCallValid,
                                   GLenum plane,
                                   GLfloat *equation,
                                   ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetClipPlanex_equation(const State &glState,
                                   bool isCallValid,
                                   GLenum plane,
                                   GLfixed *equation,
                                   ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetFixedv_params(const State &glState,
                             bool isCallValid,
                             GLenum pname,
                             GLfixed *params,
                             ParamCapture *paramCapture)
{
    CaptureGetParameter(glState, pname, sizeof(GLfixed), paramCapture);
}

void CaptureGetLightfv_params(const State &glState,
                              bool isCallValid,
                              GLenum light,
                              LightParameter pnamePacked,
                              GLfloat *params,
                              ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetLightxv_params(const State &glState,
                              bool isCallValid,
                              GLenum light,
                              LightParameter pnamePacked,
                              GLfixed *params,
                              ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetMaterialfv_params(const State &glState,
                                 bool isCallValid,
                                 GLenum face,
                                 MaterialParameter pnamePacked,
                                 GLfloat *params,
                                 ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetMaterialxv_params(const State &glState,
                                 bool isCallValid,
                                 GLenum face,
                                 MaterialParameter pnamePacked,
                                 GLfixed *params,
                                 ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetTexEnvfv_params(const State &glState,
                               bool isCallValid,
                               TextureEnvTarget targetPacked,
                               TextureEnvParameter pnamePacked,
                               GLfloat *params,
                               ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetTexEnviv_params(const State &glState,
                               bool isCallValid,
                               TextureEnvTarget targetPacked,
                               TextureEnvParameter pnamePacked,
                               GLint *params,
                               ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetTexEnvxv_params(const State &glState,
                               bool isCallValid,
                               TextureEnvTarget targetPacked,
                               TextureEnvParameter pnamePacked,
                               GLfixed *params,
                               ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureGetTexParameterxv_params(const State &glState,
                                     bool isCallValid,
                                     TextureType targetPacked,
                                     GLenum pname,
                                     GLfixed *params,
                                     ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureLightModelfv_params(const State &glState,
                                bool isCallValid,
                                GLenum pname,
                                const GLfloat *params,
                                ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureLightModelxv_param(const State &glState,
                               bool isCallValid,
                               GLenum pname,
                               const GLfixed *param,
                               ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureLightfv_params(const State &glState,
                           bool isCallValid,
                           GLenum light,
                           LightParameter pnamePacked,
                           const GLfloat *params,
                           ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureLightxv_params(const State &glState,
                           bool isCallValid,
                           GLenum light,
                           LightParameter pnamePacked,
                           const GLfixed *params,
                           ParamCapture *paramCapture)
{
    CaptureMemory(params, sizeof(GLfixed), paramCapture);
}

void CaptureLoadMatrixf_m(const State &glState,
                          bool isCallValid,
                          const GLfloat *m,
                          ParamCapture *paramCapture)
{
    CaptureMemory(m, sizeof(GLfloat) * 16, paramCapture);
}

void CaptureLoadMatrixx_m(const State &glState,
                          bool isCallValid,
                          const GLfixed *m,
                          ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureMaterialfv_params(const State &glState,
                              bool isCallValid,
                              GLenum face,
                              MaterialParameter pnamePacked,
                              const GLfloat *params,
                              ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureMaterialxv_param(const State &glState,
                             bool isCallValid,
                             GLenum face,
                             MaterialParameter pnamePacked,
                             const GLfixed *param,
                             ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureMultMatrixf_m(const State &glState,
                          bool isCallValid,
                          const GLfloat *m,
                          ParamCapture *paramCapture)
{
    CaptureMemory(m, sizeof(GLfloat) * 16, paramCapture);
}

void CaptureMultMatrixx_m(const State &glState,
                          bool isCallValid,
                          const GLfixed *m,
                          ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureNormalPointer_pointer(const State &glState,
                                  bool isCallValid,
                                  VertexAttribType typePacked,
                                  GLsizei stride,
                                  const void *pointer,
                                  ParamCapture *paramCapture)
{
    CaptureVertexPointerGLES1(glState, ClientVertexArrayType::Normal, pointer, paramCapture);
}

void CapturePointParameterfv_params(const State &glState,
                                    bool isCallValid,
                                    PointParameter pnamePacked,
                                    const GLfloat *params,
                                    ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CapturePointParameterxv_params(const State &glState,
                                    bool isCallValid,
                                    PointParameter pnamePacked,
                                    const GLfixed *params,
                                    ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureTexCoordPointer_pointer(const State &glState,
                                    bool isCallValid,
                                    GLint size,
                                    VertexAttribType typePacked,
                                    GLsizei stride,
                                    const void *pointer,
                                    ParamCapture *paramCapture)
{
    CaptureVertexPointerGLES1(glState, ClientVertexArrayType::TextureCoord, pointer, paramCapture);
}

void CaptureTexEnvfv_params(const State &glState,
                            bool isCallValid,
                            TextureEnvTarget targetPacked,
                            TextureEnvParameter pnamePacked,
                            const GLfloat *params,
                            ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureTexEnviv_params(const State &glState,
                            bool isCallValid,
                            TextureEnvTarget targetPacked,
                            TextureEnvParameter pnamePacked,
                            const GLint *params,
                            ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureTexEnvxv_params(const State &glState,
                            bool isCallValid,
                            TextureEnvTarget targetPacked,
                            TextureEnvParameter pnamePacked,
                            const GLfixed *params,
                            ParamCapture *paramCapture)
{
    CaptureMemory(params, sizeof(GLfixed), paramCapture);
}

void CaptureTexParameterxv_params(const State &glState,
                                  bool isCallValid,
                                  TextureType targetPacked,
                                  GLenum pname,
                                  const GLfixed *params,
                                  ParamCapture *paramCapture)
{
    UNIMPLEMENTED();
}

void CaptureVertexPointer_pointer(const State &glState,
                                  bool isCallValid,
                                  GLint size,
                                  VertexAttribType typePacked,
                                  GLsizei stride,
                                  const void *pointer,
                                  ParamCapture *paramCapture)
{
    CaptureVertexPointerGLES1(glState, ClientVertexArrayType::Vertex, pointer, paramCapture);
}

}  // namespace gl
