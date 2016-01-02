// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "IO/ModBusClient/ModBusClient.h"

using namespace ::testing;
using namespace hellbender::io;

class AModBusClient : public Test {
public:
    ModBusClient mbclient_;
};

TEST_F(AModBusClient, IsNotConnectedWhenCreated) {
    ASSERT_THAT(mbclient_.isConnected(), Eq(false));
}
