set(vscore_SRC
  ImageSinkBase.cpp
  ImageSourceBase.cpp
  )

set(vscore_HDR
  ImageSinkBase.h
  ImageSourceBase.h
  )

add_library(libhbvscore SHARED ${vscore_SRC} ${vscore_HDR})
target_link_libraries(libhbvscore ${OpenCV_LIBS})

file(COPY ${vscore_HDR} DESTINATION ${CMAKE_BINARY_DIR}/include/hb/VisionSystem/VSCore/)
