// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H
#define HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H

namespace hellbender {
namespace io {

class ModBusClient
{
 public:
    ModBusClient();

    bool isConnected() const { return connected_; }
 private:
    bool connected_ = false;

};

}
}

#endif // HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H
