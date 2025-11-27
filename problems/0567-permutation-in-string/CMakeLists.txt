add_library(0567-permutation-in-string_lib OBJECT solution.cpp)

add_executable(test_0567-permutation-in-string tests/test_0567-permutation-in-string.cpp $<TARGET_OBJECTS:0567-permutation-in-string_lib>)
target_link_libraries(test_0567-permutation-in-string GTest::gtest_main)
gtest_discover_tests(test_0567-permutation-in-string)
