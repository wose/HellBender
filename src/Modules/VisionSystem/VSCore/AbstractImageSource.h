// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESOURCE_H
#define HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESOURCE_H

#include <mutex>
#include <opencv2/opencv.hpp>
#include <unordered_map>

namespace hellbender {
namespace vs { inline namespace v1 {

class AbstractImageSink;

class AbstractImageSource
{
 public:
    virtual ~AbstractImageSource() {}

    void addSink(AbstractImageSink* sink);
    void removeSink(AbstractImageSink* sink);
    virtual cv::Mat getLastImage() const;

 protected:
    virtual void sinkConnected(AbstractImageSink* sink) {}
    virtual void sinkDisconnected(AbstractImageSink* sink) {}

    cv::Mat lastImage_;
    std::mutex imageLock_;
    std::unordered_map<int, AbstractImageSink*> sinks_;
    std::mutex sinkListLock_;
};

}
}
}

#endif // HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESOURCE_H
