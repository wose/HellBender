// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_VISIONSYSTEM_VSCORE_IMAGESOURCEBASE_H
#define HB_MODULES_VISIONSYSTEM_VSCORE_IMAGESOURCEBASE_H

#include <mutex>
#include <opencv2/opencv.hpp>
#include <unordered_map>

namespace hellbender {
namespace vs { inline namespace v1 {

class ImageSinkBase;

class ImageSourceBase
{
 public:
    virtual ~ImageSourceBase() {}

    void addSink(ImageSinkBase* sink);
    void removeSink(ImageSinkBase* sink);
    virtual cv::Mat getLastImage() const;

 protected:
    virtual void sinkConnected(ImageSinkBase* sink) {}
    virtual void sinkDisconnected(ImageSinkBase* sink) {}

    cv::Mat lastImage_;
    std::mutex imageLock_;
    std::unordered_map<int, ImageSinkBase*> sinks_;
    std::mutex sinkListLock_;
};

}
}
}

#endif // HB_MODULES_VISIONSYSTEM_VSCORE_IMAGESOURCEBASE_H
