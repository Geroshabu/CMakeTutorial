cmake_minimum_required(VERSION 3.10)

project(Tutorial)

add_subdirectory(MyLibrary)

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MyLibrary)

target_include_directories(Tutorial PUBLIC
                          "${PROJECT_SOURCE_DIR}/MyLibrary"
                          )
