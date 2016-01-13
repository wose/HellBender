// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_CORE_SHAREDLIBRARY_H
#define HB_CORE_SHAREDLIBRARY_H

#include "Core.h"

#ifdef _WIN32
#include "SharedLibrary_Win32.h"
#else
#include "SharedLibrary_UNIX.h"
#endif

#include <string>

namespace hellbender {

class HB_API SharedLibrary: private SharedLibraryImpl
{
public:
    SharedLibrary();
    SharedLibrary(const std::string& path);
    virtual ~SharedLibrary();

    void load(const std::string& path);
    void unload();
    bool isLoaded() const;
    bool hasSymbol(const std::string& name);
    void* getSymbol(const std::string& name);
    const std::string& getPath() const;

    static std::string prefix();
    static std::string suffix();
    static std::string getOSName(const std::string& name);

private:
    SharedLibrary(const SharedLibrary&);
    SharedLibrary& operator = (const SharedLibrary&);
};

}

#endif // HB_CORE_SHAREDLIBRARY_H
