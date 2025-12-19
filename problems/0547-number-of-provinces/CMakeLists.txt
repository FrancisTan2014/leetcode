add_library(0547-number-of-provinces_lib OBJECT solution.cpp)

add_executable(test_0547-number-of-provinces tests/test_0547-number-of-provinces.cpp $<TARGET_OBJECTS:0547-number-of-provinces_lib>)
target_link_libraries(test_0547-number-of-provinces GTest::gtest_main)
gtest_discover_tests(test_0547-number-of-provinces)
