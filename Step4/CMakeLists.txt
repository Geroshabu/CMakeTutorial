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

enable_testing()

add_test(NAME Runs COMMAND Tutorial 2 10)

add_test(NAME Output COMMAND Tutorial 2 10)
set_tests_properties(Output
  PROPERTIES PASS_REGULAR_EXPRESSION "Hel.*rld!"
  )

# define a function to simplify adding tests
function(do_test target arg1 arg2 result)
  add_test(NAME Comp${arg1}_${arg2} COMMAND ${target} ${arg1} ${arg2})
  set_tests_properties(Comp${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(Tutorial 1 2 "1")
do_test(Tutorial 2 2 "4")
do_test(Tutorial 2 5 "32")
do_test(Tutorial 2 10 "1024")
do_test(Tutorial 3 3 "27")
do_test(Tutorial 10 5 "100000")
