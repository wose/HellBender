set(coretest_SRC
  main.cpp
  SharedLibraryTest.cpp
  )

add_executable(core_test ${coretest_SRC})
target_link_libraries(core_test
  libgtest
  libgmock
  hb
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
