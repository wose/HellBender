// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ImageSourceBase.h"
#include "ImageSinkBase.h"

namespace hellbender {
namespace vs { inline namespace v1 {

void ImageSourceBase::addSink(ImageSinkBase* const sink)
{
    if(!sink) return;

    {
        std::lock_guard<std::mutex> lock(sinkListLock_);
        sinks_.insert({sink->getSinkID(), sink});
    }

    sinkConnected(sink);
}


void ImageSourceBase::removeSink(ImageSinkBase* const sink)
{
    if(!sink) return;

    {
        std::lock_guard<std::mutex> lock(sinkListLock_);

        if(!sinks_.empty()) {
            sinks_.erase(sink->getSinkID());
        }
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
