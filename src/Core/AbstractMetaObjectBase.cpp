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

#include "AbstractMetaObjectBase.h"

#include <algorithm>

namespace hellbender {

AbstractMetaObjectBase::AbstractMetaObjectBase(const std::string& className,
  const std::string& baseClassName):
    libraryPath_("Unknown"),
    baseClassName_(baseClassName),
    className_(className),
    typeidBaseClassName_("UNSET")
{
}

AbstractMetaObjectBase::~AbstractMetaObjectBase()
{
}

std::string AbstractMetaObjectBase::className() const
{
    return className_;
}

std::string AbstractMetaObjectBase::baseClassName() const
{
    return baseClassName_;
}

std::string AbstractMetaObjectBase::typeidBaseClassName() const
{
    return typeidBaseClassName_;
}

std::string AbstractMetaObjectBase::libraryPath() const
{
    return libraryPath_;
}

void AbstractMetaObjectBase::setLibraryPath(const std::string& libraryPath)
{
    libraryPath_= libraryPath;
}

void AbstractMetaObjectBase::addClassLoader(ClassLoader* loader)
{
    if(std::find(classLoaders_.cbegin(), classLoaders_.cend(), loader)
       == classLoaders_.cend())
    {
        classLoaders_.push_back(loader);
    }
}

void AbstractMetaObjectBase::removeClassLoader(const ClassLoader* loader)
{
    auto it = std::find(classLoaders_.begin(), classLoaders_.end(), loader);
    if(it != classLoaders_.end())
    {
        classLoaders_.erase(it);
    }
}

bool AbstractMetaObjectBase::isOwnedBy(const ClassLoader* loader) const
{
    auto it = std::find(classLoaders_.cbegin(), classLoaders_.cend(), loader);
    return it != classLoaders_.cend();
}

bool AbstractMetaObjectBase::isOwnedByAnybody() const
{
    return classLoaders_.size() > 0;
}

ClassLoaderVector AbstractMetaObjectBase::getClassLoaders() const
{
    return classLoaders_;
}

}
