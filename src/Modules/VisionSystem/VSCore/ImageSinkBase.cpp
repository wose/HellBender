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

void ImageSinkBase::connectTo(ImageSourceBase* source)
{
    if(source_) {
        disconnect();
    }

    if(source)
    {
        source->addSink(this);
        source_ = source;
    }
}

void ImageSinkBase::disconnect()
{
    if(source_) {
        source_->removeSink(this);
        source_ = nullptr;
    }
}

bool ImageSinkBase::isConnected()
{
    return source_ != nullptr;
}

}
}
}
