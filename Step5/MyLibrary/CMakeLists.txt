add_library(MyLibrary pow.cpp)

target_include_directories(MyLibrary
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# does this system provide the pow functions?
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::pow(2, 10);
    return 0;
  }
" HAVE_POW)

if(HAVE_POW)
  target_compile_definitions(MyLibrary
                             PRIVATE "HAVE_POW")
endif()
