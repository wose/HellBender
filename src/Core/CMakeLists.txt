set(core_SRC
  AbstractMetaObjectBase.cpp
  SharedLibrary.cpp
  )

set(core_HDR
  AbstractMetaObjectBase.h
  Core.h
  SharedLibrary.h
  )


add_definitions(-DHB_BUILD_SHARED)

add_library(hb SHARED ${core_SRC} ${core_HDR})

target_link_libraries(hb
  dl
  )
