// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "pugixml.hpp"

#include <string>

using namespace ::testing;
//using namespace hellbender;

class MachineConfig {
public:
    MachineConfig() {
    }

    MachineConfig(const std::string& path) {
        auto result = doc_.load_file(path.c_str());
        if(!result)
            throw std::runtime_error(result.description());
    }

private:
    pugi::xml_document doc_;
};

class AMachineConfig : public Test {
public:
    MachineConfig machineconfig_;

    const std::string pathToValidConfig = "ValidConfig.xml";
    const std::string pathToInvalidConfig = "InvalidConfig.xml";
    const std::string pathToNonExistingConfig = "NonExistingConfig.xml";
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
