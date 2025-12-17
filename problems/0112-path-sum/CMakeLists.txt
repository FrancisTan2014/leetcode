add_library(0112-path-sum_lib OBJECT solution.cpp)

add_executable(test_0112-path-sum tests/test_0112-path-sum.cpp $<TARGET_OBJECTS:0112-path-sum_lib>)
target_link_libraries(test_0112-path-sum GTest::gtest_main)
gtest_discover_tests(test_0112-path-sum)
