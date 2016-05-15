set(vscore_SRC
  AbstractImageSource.cpp
  )

set(vscore_HDR
  AbstractImageSource.h
  AbstractImageSink.h
  )

add_library(libhbvscore SHARED ${vscore_SRC} ${vscore_HDR})
target_link_libraries(libhbvscore ${OpenCV_LIBS})

file(COPY ${vscore_HDR} DESTINATION ${CMAKE_BINARY_DIR}/include/hb/VisionSystem/VSCore/)
