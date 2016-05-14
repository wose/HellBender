// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "VisionSystem/VSCore/AbstractImageSink.h"
#include "OCVCamera.h"

#include "spdlog/spdlog.h"


#include <chrono>
#include <condition_variable>
#include <thread>
#include <stdexcept>

namespace hellbender {
namespace vs { inline namespace v1 {

OCVCamera::OCVCamera()
{
}

OCVCamera::OCVCamera(int device) :
    videoCapture_(device)
{
    if(!videoCapture_.isOpened()) {
        throw std::runtime_error("Couldn't open OpenCV capture device.");
    }
}

OCVCamera::OCVCamera(const std::string& file) :
    videoCapture_(file)
{
    if(!videoCapture_.isOpened()) {
        throw std::runtime_error("Couldn't open file");
    }
}

OCVCamera::~OCVCamera()
{
    stop();
}

void OCVCamera::open(int device)
{
    videoCapture_.open(device);
    if(!videoCapture_.isOpened()) {
        throw std::runtime_error("Couldn't open OpenCV capture device");
    }

    if(!sinks_.empty()) {
        start();
    }
}

void OCVCamera::open(const std::string& file)
{
    videoCapture_.open(file);
    if(!videoCapture_.isOpened()) {
        throw std::runtime_error("Couldn't open file");
    }

    if(!sinks_.empty()) {
        start();
    }
}

void OCVCamera::start()
{
    if(!isGrabbing_)
    {
        if(!videoCapture_.isOpened()) {
            throw std::runtime_error("No capture device or file opened");
        }

        grabFlag_.test_and_set(std::memory_order_acquire);

        isGrabbing_ = true;
        grabbingThread_ = std::thread(&OCVCamera::grabbingThread, this);
    }
}

void OCVCamera::stop()
{
    if(isGrabbing_) {
        grabFlag_.clear(std::memory_order_release);
        grabbingThread_.join();
        isGrabbing_= false;
    }
}

void OCVCamera::sinkConnected(AbstractImageSink* sink)
{
    if(!isGrabbing_ && videoCapture_.isOpened()) {
        start();
    }
}

void OCVCamera::sinkDisconnected(AbstractImageSink* sink)
{
    if(isGrabbing_ && sinks_.empty())
    {
        stop();
    }
}

void OCVCamera::grabbingThread()
{
    while(grabFlag_.test_and_set(std::memory_order_acquire)) {
        {
            std::lock_guard<std::mutex> imageLock(imageLock_);
            videoCapture_ >> lastImage_;
        }

        std::lock_guard<std::mutex> sinkListLock(sinkListLock_);
        for(auto& sink : sinks_) {
            sink.second->onNewImage(lastImage_);
        }
    }
    grabFlag_.clear(std::memory_order_release);
}

}
}
}
