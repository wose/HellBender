set(core_SRC
  SharedLibrary.cpp
  )

set(core_HDR
  Core.h
  SharedLibrary.h
  )


add_definitions(-DHB_BUILD_SHARED)

add_library(hb SHARED ${core_SRC})
