add_library(0007-reverse-integer_lib OBJECT solution.cpp)

add_executable(test_0007-reverse-integer tests/test_0007-reverse-integer.cpp $<TARGET_OBJECTS:0007-reverse-integer_lib>)
target_link_libraries(test_0007-reverse-integer GTest::gtest_main)
gtest_discover_tests(test_0007-reverse-integer)
