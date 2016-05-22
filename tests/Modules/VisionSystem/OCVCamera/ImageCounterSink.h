// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_TEST_MODULES_VISIONSYSTEM_OCVCAMERA_IMAGECOUNTERSINK_H
#define HB_TEST_MODULES_VISIONSYSTEM_OCVCAMERA_IMAGECOUNTERSINK_H


#include "VisionSystem/VSCore/ImageSinkBase.h"

#include <opencv2/opencv.hpp>

using namespace hellbender::vs;

class ImageCounterSink : public ImageSinkBase
{
 public:
    ImageCounterSink()
    {
    };

    virtual void onNewImage(cv::Mat& image) override
    {
        ++counter_;
    }

    long counter_ = 0;
};

#endif // HB_TEST_MODULES_VISIONSYSTEM_OCVCAMERA_IMAGECOUNTERSINK_H
