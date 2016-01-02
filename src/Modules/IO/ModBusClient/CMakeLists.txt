set(modbusclient_SRC
  ModBusClient.cpp)

set(modbusclient_HDR
  ModBusClient.h
  )

add_library(libhbmodbusclient SHARED ${modbusclient_SRC})
