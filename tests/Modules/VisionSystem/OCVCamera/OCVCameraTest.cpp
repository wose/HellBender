// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "VisionSystem/OCVCamera/OCVCamera.h"
#include "ImageCounterSink.h"

#include <chrono>

using namespace ::testing;
using namespace hellbender::vs;

class AOCVCamera : public Test {
public:
    OCVCamera ocvcam_;
    ImageCounterSink imageCounterSink_1, imageCounterSink_2;

    const char* validVideoFile = "Road1101.mp4";
    const char* invalidVideoFile = "Foo.mp4";
};

TEST_F(AOCVCamera, ThrowsWhenFileNotFound) {
    ASSERT_THROW(ocvcam_.open(invalidVideoFile), std::runtime_error);
}

TEST_F(AOCVCamera, CanOpenAVideoFile) {
    ocvcam_.open(validVideoFile);
}

TEST_F(AOCVCamera, StartsGrabbingWhenOpenedAndSinkConnects) {
    ocvcam_.open(validVideoFile);
    imageCounterSink_1.connectTo(&ocvcam_);
    ASSERT_THAT(ocvcam_.isGrabbing(), Eq(true));
}

TEST_F(AOCVCamera, StartsGrabbingWhenSinksAreConnectedAndOpened) {
    imageCounterSink_1.connectTo(&ocvcam_);
    ocvcam_.open(validVideoFile);
    ASSERT_THAT(ocvcam_.isGrabbing(), Eq(true));
}

TEST_F(AOCVCamera, StopsGrabbingWhenLastSinkDisconnects) {
    imageCounterSink_1.connectTo(&ocvcam_);
    imageCounterSink_2.connectTo(&ocvcam_);
    ocvcam_.open(validVideoFile);
    imageCounterSink_2.disconnect();
    ASSERT_THAT(ocvcam_.isGrabbing(), Eq(true));
    imageCounterSink_1.disconnect();
    ASSERT_THAT(ocvcam_.isGrabbing(), Eq(false));
}
