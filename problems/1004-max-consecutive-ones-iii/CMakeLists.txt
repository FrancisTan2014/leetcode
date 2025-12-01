add_library(1004-max-consecutive-ones-iii_lib OBJECT solution.cpp)

add_executable(test_1004-max-consecutive-ones-iii tests/test_1004-max-consecutive-ones-iii.cpp $<TARGET_OBJECTS:1004-max-consecutive-ones-iii_lib>)
target_link_libraries(test_1004-max-consecutive-ones-iii GTest::gtest_main)
gtest_discover_tests(test_1004-max-consecutive-ones-iii)
