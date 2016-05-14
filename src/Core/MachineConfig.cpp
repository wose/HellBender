// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "MachineConfig.h"

#include <stdexcept>

namespace hellbender {

MachineConfig::MachineConfig()
{
}

MachineConfig::MachineConfig(const char* path)
{
    load(path);
}

void MachineConfig::load(const char* path)
{
    auto result = doc_.load_file(path);
    if(!result)
        throw std::runtime_error(result.description());
}

}
