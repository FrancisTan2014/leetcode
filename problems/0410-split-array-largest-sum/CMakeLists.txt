add_library(0410-split-array-largest-sum_lib OBJECT solution.cpp)

add_executable(test_0410-split-array-largest-sum tests/test_0410-split-array-largest-sum.cpp $<TARGET_OBJECTS:0410-split-array-largest-sum_lib>)
target_link_libraries(test_0410-split-array-largest-sum GTest::gtest_main)
gtest_discover_tests(test_0410-split-array-largest-sum)
