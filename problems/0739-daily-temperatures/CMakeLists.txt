add_library(0739-daily-temperatures_lib OBJECT solution.cpp)

add_executable(test_0739-daily-temperatures tests/test_0739-daily-temperatures.cpp $<TARGET_OBJECTS:0739-daily-temperatures_lib>)
target_link_libraries(test_0739-daily-temperatures GTest::gtest_main)
gtest_discover_tests(test_0739-daily-temperatures)
