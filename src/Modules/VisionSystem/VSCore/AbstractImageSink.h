// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESINK_H
#define HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESINK_H

#include "AbstractImageSource.h"

#include <atomic>
#include <memory>
#include <mutex>
#include <opencv2/opencv.hpp>

namespace hellbender {
namespace vs { inline namespace v1 {

class AbstractImageSink{
 public:
    AbstractImageSink() :
        sinkID_(++lastSinkID_) {}
    virtual ~AbstractImageSink()
    {
        disconnect();
    }

    void connectTo(AbstractImageSource* source)
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

    void disconnect()
    {
        if(source_) {
            source_->removeSink(this);
            source_ = nullptr;
        }
    }

    virtual void onNewImage(cv::Mat& image) = 0;
    int getSinkID() { return sinkID_;}
 protected:
    AbstractImageSource* source_ = nullptr;
    static std::atomic<int> lastSinkID_;
    int sinkID_;
};

std::atomic<int> AbstractImageSink::lastSinkID_{1};

}
}
}

#endif // HB_MODULES_VISIONSYSTEM_VSCORE_ABSTRACTIMAGESINK_H
