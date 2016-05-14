// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_CORE_MACHINECONFIG_H
#define HB_CORE_MACHINECONFIG_H

#include "Core.h"
#include "pugixml.hpp"

#include <string>

namespace hellbender {

class HB_API MachineConfig {
public:
    MachineConfig();
    MachineConfig(const char* path);

    void load(const char* path);


private:
    pugi::xml_document doc_;
};

}

#endif // HB_CORE_MACHINECONFIG_H
