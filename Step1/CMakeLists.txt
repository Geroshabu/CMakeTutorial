cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.1)

add_executable(Tutorial tutorial.cxx)

configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
