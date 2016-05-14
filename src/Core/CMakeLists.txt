set(core_SRC
  AbstractMetaObjectBase.cpp
  MachineConfig.cpp
  SharedLibrary.cpp
  )

set(core_HDR
  AbstractMetaObject.h
  AbstractMetaObjectBase.h
  Core.h
  MachineConfig.h
  MetaObject.h
  SharedLibrary.h
  )


add_definitions(-DHB_BUILD_SHARED)

add_library(hb SHARED ${core_SRC} ${core_HDR})

target_link_libraries(hb
  dl
  )

target_link_libraries(hb pugixml)
