add_library(0141-linked-list-cycle_lib OBJECT solution.cpp)

add_executable(test_0141-linked-list-cycle tests/test_0141-linked-list-cycle.cpp $<TARGET_OBJECTS:0141-linked-list-cycle_lib>)
target_link_libraries(test_0141-linked-list-cycle GTest::gtest_main)
gtest_discover_tests(test_0141-linked-list-cycle)
