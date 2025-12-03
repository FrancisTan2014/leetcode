add_library(0992-subarrays-with-k-different-integers_lib OBJECT solution.cpp)

add_executable(test_0992-subarrays-with-k-different-integers tests/test_0992-subarrays-with-k-different-integers.cpp $<TARGET_OBJECTS:0992-subarrays-with-k-different-integers_lib>)
target_link_libraries(test_0992-subarrays-with-k-different-integers GTest::gtest_main)
gtest_discover_tests(test_0992-subarrays-with-k-different-integers)
