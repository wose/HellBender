set(ocvcamera_SRC
  OCVCamera.cpp
  )

set(ocvcamera_HDR
  OCVCamera.h
  )

add_library(libhbocvcamera SHARED ${ocvcamera_SRC})
target_link_libraries(libhbocvcamera libhbvscore)
