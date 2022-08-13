add_library(MyMethods MyMethod.cpp)

target_include_directories(MyMethods
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(PrintLibrary STATIC
            print2.cpp
            )

target_link_libraries(MyMethods PRIVATE PrintLibrary)

target_compile_definitions(MyMethods PRIVATE "EXPORTING_PRINT")

set(installable_libs MyMethods)
if(TARGET PrintLibrary)
  list(APPEND installable_libs PrintLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MyMethod.hpp DESTINATION include)
