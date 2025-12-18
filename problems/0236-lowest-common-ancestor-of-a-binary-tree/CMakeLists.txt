add_library(0236-lowest-common-ancestor-of-a-binary-tree_lib OBJECT solution.cpp)

add_executable(test_0236-lowest-common-ancestor-of-a-binary-tree tests/test_0236-lowest-common-ancestor-of-a-binary-tree.cpp $<TARGET_OBJECTS:0236-lowest-common-ancestor-of-a-binary-tree_lib>)
target_link_libraries(test_0236-lowest-common-ancestor-of-a-binary-tree GTest::gtest_main)
gtest_discover_tests(test_0236-lowest-common-ancestor-of-a-binary-tree)
