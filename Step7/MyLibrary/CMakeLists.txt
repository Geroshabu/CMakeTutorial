add_library(MyMath pow.cpp)

target_include_directories(MyMath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
