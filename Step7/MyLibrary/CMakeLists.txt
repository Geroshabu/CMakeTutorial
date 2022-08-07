add_library(MyMath pow.cpp)

target_include_directories(MyMath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS MyMath DESTINATION lib)
install(FILES math.hpp DESTINATION include)
