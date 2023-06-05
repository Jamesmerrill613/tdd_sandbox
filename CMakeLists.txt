cmake_minimum_required(VERSION 3.15)
project(tdd_sandbox LANGUAGES CXX)
enable_testing()

include(cmakemodules/gtest_utils.cmake)

# build google test so we can run tests
build_gtest(deps/googletest deps/googletest)

# build the state machine library so we can link against it and use it in tests
add_subdirectory(deps/state_machine/state_machine deps/state_machine)
add_subdirectory(custom_states)

# function(add_gtest TEST_NAME SOURCES INCLUDES LIBRARIES OUT_DIR)

# An example test to be sure we can link and run a gtest and get test results
add_gtest(GtestExample tests/GTestExample.cpp "" "" "")

# An example that links in the state machine library
add_gtest(StateMachineLinkedTest tests/StateMachineLinkedTest.cpp "" state_machine "")

