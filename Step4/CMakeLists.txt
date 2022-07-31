cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

add_subdirectory(MyLibrary)

add_executable(Tutorial tutorial.cxx)

configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)

target_link_libraries(Tutorial PUBLIC MyLibrary)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.hpp"
  DESTINATION include
  )
