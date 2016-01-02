set(modbusclienttest_SRC
  main.cpp
  ModBusClientTest.cpp
  )

add_executable(modbusclient_test ${modbusclienttest_SRC})

target_link_libraries(modbusclient_test
  libgtest
  libgmock
  libhbmodbusclient
)

add_test(NAME ModBusClientTest
  COMMAND modbusclient_test)
