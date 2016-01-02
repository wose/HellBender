#ifndef HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H
#define HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H

namespace hellbender {
namespace io {

class ModBusClient
{
 public:
    ModBusClient();

    bool isConnected() { return connected_; }
 private:
    bool connected_ = false;

};

}
}

#endif // HB_MODULES_IO_MODBUSCLIENT_MODBUSCLIENT_H
