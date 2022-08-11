add_library(MyMethods MyMethod.cpp print2.cpp)

target_include_directories(MyMethods
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS MyMethods DESTINATION lib)
install(FILES MyMethod.hpp DESTINATION include)
