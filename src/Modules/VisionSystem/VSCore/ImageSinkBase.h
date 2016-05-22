// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_VISIONSYSTEM_VSCORE_IMAGESINKBASE_H
#define HB_MODULES_VISIONSYSTEM_VSCORE_IMAGESINKBASE_H

#include <atomic>
#include <memory>
#include <mutex>
#include <opencv2/opencv.hpp>

namespace hellbender {
namespace vs { inline namespace v1 {

class ImageSourceBase;

class ImageSinkBase{
 public:
    ImageSinkBase();
    virtual ~ImageSinkBase();

    void connectTo(ImageSourceBase* source);
    void disconnect();
    bool isConnected();
    int getSinkID() { return sinkID_;}

    virtual void onNewImage(cv::Mat& image) = 0;

 protected:
    ImageSourceBase* source_ = nullptr;
    static std::atomic<int> lastSinkID_;
    int sinkID_;
};

}
}
}

#endif // HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESINK_H
