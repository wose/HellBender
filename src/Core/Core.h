// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_CORE_CORE_H
#define HB_CORE_CORE_H

#ifndef HB_API
#   ifdef _WIN32
#       if defined(HB_BUILD_SHARED)
#           define HB_API __declspec(dllexport)
#       elif !defined(HB_BUILD_STATIC)
#           define HB_API __declspec(dllimport)
#       else
#           define HB_API
#       endif
#   else
#       if __GNUC__ >= 4
#           define HB_API __attribute__((visibility("default")))
#       else
#           define HB_API
#       endif
#   endif
#endif

#ifdef __GNUC__
#   define HB_UNUSED __attribute__((unused))
#else
#   define HB_UNUSED
#endif

#endif
