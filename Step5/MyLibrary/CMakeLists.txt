add_library(MyLibrary pow.cpp)

target_include_directories(MyLibrary
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
