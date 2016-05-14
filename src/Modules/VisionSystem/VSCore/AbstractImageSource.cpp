// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "AbstractImageSource.h"
#include "AbstractImageSink.h"

namespace hellbender {
namespace vs { inline namespace v1 {

void AbstractImageSource::addSink(AbstractImageSink* sink)
{
    if(sink) {
        std::lock_guard<std::mutex> lock(sinkListLock_);
        sinks_[sink->getSinkID()]= sink;
    }
    sinkConnected(sink);
}


void AbstractImageSource::removeSink(AbstractImageSink* sink)
{
    if(sink) {
        std::lock_guard<std::mutex> lock(sinkListLock_);
        sinks_.erase(sink->getSinkID());
    }
    sinkDisconnected(sink);
}

cv::Mat AbstractImageSource::getLastImage() const
{
    return lastImage_;
}

}
}
}
