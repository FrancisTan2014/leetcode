add_library(0200-number-of-islands_lib OBJECT solution.cpp)

add_executable(test_0200-number-of-islands tests/test_0200-number-of-islands.cpp $<TARGET_OBJECTS:0200-number-of-islands_lib>)
target_link_libraries(test_0200-number-of-islands GTest::gtest_main)
gtest_discover_tests(test_0200-number-of-islands)
