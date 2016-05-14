set(ocvcameratest_SRC
  main.cpp
  OCVCameraTest.cpp
  )

add_executable(ocvcamera_test ${ocvcameratest_SRC})

target_link_libraries(ocvcamera_test
  libgtest
  libgmock
  libhbocvcamera
  ${OpenCV_Libs}
  )

add_test(NAME OCVCameraTest
  COMMAND ocvcamera_test)

configure_file(Road1101.mp4 Road1101.mp4 COPYONLY)
