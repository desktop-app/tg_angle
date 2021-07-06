// GENERATED FILE - DO NOT EDIT.
// Generated by gen_builtin_symbols.py using data from builtin_variables.json and
// builtin_function_declarations.txt.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ParseContext_ESSL_autogen.h:
//   Helpers for built-in related checks.

#ifndef COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_
#define COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_

namespace sh
{

namespace BuiltInGroup
{

bool isTextureOffsetNoBias(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3795 && id <= 3864;
}
bool isTextureOffsetBias(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3865 && id <= 3884;
}
bool isTextureGatherOffsetNoComp(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3922 && id <= 3929;
}
bool isTextureGatherOffsetComp(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3930 && id <= 3935;
}
bool isTextureGatherOffset(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3922 && id <= 3935;
}
bool isTextureGatherOffsetsNoComp(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3936 && id <= 3952;
}
bool isTextureGatherOffsetsComp(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3953 && id <= 3964;
}
bool isTextureGatherOffsets(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3936 && id <= 3964;
}
bool isTextureGather(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3898 && id <= 3964;
}
bool isInterpolationFS(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 3977 && id <= 4000;
}
bool isAtomicMemory(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 4005 && id <= 4022;
}
bool isImageStore(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 4059 && id <= 4076;
}
bool isImageLoad(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 4077 && id <= 4094;
}
bool isImageAtomic(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 4095 && id <= 4670;
}
bool isImage(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 4023 && id <= 4670;
}

}  // namespace BuiltInGroup

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_
