//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_TRANSLATOR_TRANSLATORMETALDIRECT_INTRODUCEVERTEXINDEX_H_
#define COMPILER_TRANSLATOR_TRANSLATORMETALDIRECT_INTRODUCEVERTEXINDEX_H_

#include "common/angleutils.h"
#include "compiler/translator/Compiler.h"
#include "compiler/translator/TranslatorMetalDirect/Pipeline.h"
namespace sh
{

[[nodiscard]] bool IntroduceVertexAndInstanceIndex(TCompiler &compiler, TIntermBlock &root);

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_TRANSLATORMETALDIRECT_INTRODUCEVERTEXINDEX_H_
