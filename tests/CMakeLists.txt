find_package(Threads REQUIRED)

include(ExternalProject)

ExternalProject_Add(
  gmock
  URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
  # Disable install step
  INSTALL_COMMAND ""
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
add_dependencies(libgmock gmock)

ExternalProject_Get_Property(gmock source_dir binary_dir)

set_target_properties(libgmock PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/libgmock.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  )

set_target_properties(libgtest PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/gtest/libgtest.a"
  )

include_directories("${source_dir}/include")
include_directories("${source_dir}/gtest/include")

include_directories("../src/Modules")

add_subdirectory(Modules)
