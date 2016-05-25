// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ImageSinkBase.h"
#include "ImageSourceBase.h"

namespace hellbender {
namespace vs { inline namespace v1 {

std::atomic<int> ImageSinkBase::lastSinkID_{1};

ImageSinkBase::ImageSinkBase() :
    sinkID_{++lastSinkID_}
{
}

ImageSinkBase::~ImageSinkBase()
{
    disconnect();
}

void ImageSinkBase::connectTo(std::weak_ptr<ImageSourceBase> source)
{
    if(source_.lock()) {
        disconnect();
    }

    if(auto sp = source.lock()) {
        source_ = source;
        sp->addSink(this);
    }
}

void ImageSinkBase::disconnect()
{
    if(auto sp = source_.lock()) {
        sp->removeSink(this);
    }
}

bool ImageSinkBase::isConnected()
{
     return source_.lock() != nullptr;
}

}
}
}
