cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.23)

add_subdirectory(MyLibrary)

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MyMath)

install(TARGETS Tutorial DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "ZIP")
include(CPack)
