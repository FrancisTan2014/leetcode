add_library(merge_intervals_lib OBJECT solution.cpp)

add_executable(test_0056-merge-intervals tests/test_0056-merge-intervals.cpp $<TARGET_OBJECTS:merge_intervals_lib>)
target_link_libraries(test_0056-merge-intervals GTest::gtest_main)
gtest_discover_tests(test_0056-merge-intervals)
