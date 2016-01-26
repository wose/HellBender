/* Original work
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// Modified work
// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_CORE_ABSTRACTMETAOBJECTBASE_H
#define HB_CORE_ABSTRACTMETAOBJECTBASE_H

#include <vector>
#include <string>
#include <typeinfo>

namespace hellbender {

class ClassLoader;
using ClassLoaderVector = std::vector<ClassLoader*>;

class AbstractMetaObjectBase
{
public:
    AbstractMetaObjectBase(const std::string& className, const std::string& baseName);
    virtual ~AbstractMetaObjectBase();

    std::string className() const;
    std::string baseClassName() const;
    std::string typeidBaseClassName() const;
    std::string libraryPath() const;

    void setLibraryPath(const std::string& libraryPath);
    void addClassLoader(ClassLoader* loader);
    void removeClassLoader(const ClassLoader* loader);
    bool isOwnedBy(const ClassLoader* loader) const;
    bool isOwnedByAnybody() const;

    ClassLoaderVector getClassLoaders() const;

protected:
    virtual void dummy(){}

protected:
    ClassLoaderVector classLoaders_;
    std::string libraryPath_;
    std::string baseClassName_;
    std::string className_;
    std::string typeidBaseClassName_;
};

}

#endif
