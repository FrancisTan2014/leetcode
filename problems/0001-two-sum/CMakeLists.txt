# problem: 0001-two-sum
add_library(two_sum_lib OBJECT solution.cpp)

add_executable(test_two_sum tests/test_two_sum.cpp $<TARGET_OBJECTS:two_sum_lib>)
target_link_libraries(test_two_sum GTest::gtest_main)
gtest_discover_tests(test_two_sum)
