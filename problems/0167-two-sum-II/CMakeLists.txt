add_library(0167-two-sum-II_lib OBJECT solution.cpp)

add_executable(test_0167-two-sum-II tests/test_0167-two-sum-II.cpp $<TARGET_OBJECTS:0167-two-sum-II_lib>)
target_link_libraries(test_0167-two-sum-II GTest::gtest_main)
gtest_discover_tests(test_0167-two-sum-II)
