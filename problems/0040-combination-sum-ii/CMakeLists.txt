add_library(0040-combination-sum-ii_lib OBJECT solution.cpp)

add_executable(test_0040-combination-sum-ii tests/test_0040-combination-sum-ii.cpp $<TARGET_OBJECTS:0040-combination-sum-ii_lib>)
target_link_libraries(test_0040-combination-sum-ii GTest::gtest_main)
gtest_discover_tests(test_0040-combination-sum-ii)
