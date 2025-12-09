add_library(0142-linked-list-cycle-ii_lib OBJECT solution.cpp)

add_executable(test_0142-linked-list-cycle-ii tests/test_0142-linked-list-cycle-ii.cpp $<TARGET_OBJECTS:0142-linked-list-cycle-ii_lib>)
target_link_libraries(test_0142-linked-list-cycle-ii GTest::gtest_main)
gtest_discover_tests(test_0142-linked-list-cycle-ii)
