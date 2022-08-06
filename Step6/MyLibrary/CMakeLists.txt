add_executable(CreateFile CreateFile.cpp)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/File.hpp
  COMMAND CreateFile ${CMAKE_CURRENT_BINARY_DIR}/File.hpp
  DEPENDS CreateFile
  )

add_library(MyLibrary
            pow.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/File.hpp)

target_include_directories(MyLibrary
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )
