set(coretest_SRC
  main.cpp
  MachineConfigTest.cpp
  MetaObjectTest.cpp
  SharedLibraryTest.cpp
  )

add_executable(core_test ${coretest_SRC})
target_link_libraries(core_test
  libgtest
  libgmock
  hb
  pugixml
  )

add_library( TestLib SHARED
  TestLib.cpp
  TestPlugin.cpp
  TestPlugin.h )
target_link_libraries(TestLib
  hb
  )

add_test(NAME CoreTest
  COMMAND core_test)

configure_file(ValidConfig.xml ValidConfig.xml COPYONLY)
configure_file(InvalidConfig.xml InvalidConfig.xml COPYONLY)
