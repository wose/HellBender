// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ImageSourceBase.h"
#include "ImageSinkBase.h"

namespace hellbender {
namespace vs { inline namespace v1 {

void ImageSourceBase::addSink(ImageSinkBase* sink)
{
    if(sink) {
        std::lock_guard<std::mutex> lock(sinkListLock_);
        sinks_[sink->getSinkID()]= sink;
    }
    sinkConnected(sink);
}


void ImageSourceBase::removeSink(ImageSinkBase* sink)
{
    if(sink) {
        std::lock_guard<std::mutex> lock(sinkListLock_);
        sinks_.erase(sink->getSinkID());
    }
    sinkDisconnected(sink);
}

cv::Mat ImageSourceBase::getLastImage() const
{
    return lastImage_;
}

}
}
}
