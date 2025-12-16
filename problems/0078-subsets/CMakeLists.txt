add_library(0078-subsets_lib OBJECT solution.cpp)

add_executable(test_0078-subsets tests/test_0078-subsets.cpp $<TARGET_OBJECTS:0078-subsets_lib>)
target_link_libraries(test_0078-subsets GTest::gtest_main)
gtest_discover_tests(test_0078-subsets)
