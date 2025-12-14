add_library(0046-permutations_lib OBJECT solution.cpp)

add_executable(test_0046-permutations tests/test_0046-permutations.cpp $<TARGET_OBJECTS:0046-permutations_lib>)
target_link_libraries(test_0046-permutations GTest::gtest_main)
gtest_discover_tests(test_0046-permutations)
