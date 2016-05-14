// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_VISIONSYSTEM_OCVCAMERA_OCVCAMERA_H
#define HB_MODULES_VISIONSYSTEM_OCVCAMERA_OCVCAMERA_H

#include <atomic>
#include <opencv2/opencv.hpp>
#include <string>
#include <thread>

#include "VisionSystem/VSCore/AbstractImageSource.h"

namespace hellbender {
namespace vs { inline namespace v1 {

class OCVCamera : public AbstractImageSource
{
public:
    OCVCamera();
    OCVCamera(int device);
    OCVCamera(const std::string& file);
    ~OCVCamera();

    void open(int device);
    void open(const std::string& file);
    void start();
    void stop();
    bool isGrabbing() const {return isGrabbing_;}

protected:
    virtual void sinkConnected(AbstractImageSink* sink) override;
    virtual void sinkDisconnected(AbstractImageSink* sink) override;

private:
    void grabbingThread();


    std::atomic_flag grabFlag_ = ATOMIC_FLAG_INIT;
    bool isGrabbing_ = false;
    cv::VideoCapture videoCapture_;
    std::thread grabbingThread_;
};

}
}
}

#endif // HB_MODULES_VISIONSYSTEM_OCVCAMERA_OCVCAMERA_H
