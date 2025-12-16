add_library(0039-combination-sum_lib OBJECT solution.cpp)

add_executable(test_0039-combination-sum tests/test_0039-combination-sum.cpp $<TARGET_OBJECTS:0039-combination-sum_lib>)
target_link_libraries(test_0039-combination-sum GTest::gtest_main)
gtest_discover_tests(test_0039-combination-sum)
