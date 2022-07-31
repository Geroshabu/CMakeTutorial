cmake_minimum_required(VERSION 3.10)

project(Tutorial)

configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)
option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  add_subdirectory(MyLibrary)
  list(APPEND EXTRA_LIBS MyLibrary)
endif()

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )
