// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "MachineConfig.h"
#include "pugixml.hpp"

#include <string>

using namespace ::testing;
using namespace hellbender;

class AMachineConfig : public Test {
public:
    MachineConfig machineconfig_;

    const char* pathToValidConfig = "ValidConfig.xml";
    const char* pathToInvalidConfig = "InvalidConfig.xml";
    const char* pathToNonExistingConfig = "NonExistingConfig.xml";
};

TEST_F(AMachineConfig, CanBeConstructedWithPath) {
    MachineConfig tMachineConfig(pathToValidConfig);
    ASSERT_THAT(true, Eq(true));
}

TEST_F(AMachineConfig, ThrowsWhenConstructedWithInvalidPath) {
    ASSERT_THROW(MachineConfig tMachineConfig(pathToNonExistingConfig),
                 std::runtime_error);
}

TEST_F(AMachineConfig, ThrowsWhenConstructedWithInvalidConfig) {
    ASSERT_THROW(MachineConfig tMachineConfig(pathToInvalidConfig),
                 std::runtime_error);
}

TEST_F(AMachineConfig, CanLoadAConfigFile) {
    machineconfig_.load(pathToValidConfig);
}

TEST_F(AMachineConfig, CanReturnAListOfDevices) {

}
