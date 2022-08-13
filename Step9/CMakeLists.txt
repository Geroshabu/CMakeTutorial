cmake_minimum_required(VERSION 3.10)

project(Tutorial)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(MyLibrary)

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MyMethods)

install(TARGETS Tutorial DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_SOURCE_GENERATOR "ZIP")
include(CPack)
