add_library(0322-coin-change_lib OBJECT solution.cpp)

add_executable(test_0322-coin-change tests/test_0322-coin-change.cpp $<TARGET_OBJECTS:0322-coin-change_lib>)
target_link_libraries(test_0322-coin-change GTest::gtest_main)
gtest_discover_tests(test_0322-coin-change)
