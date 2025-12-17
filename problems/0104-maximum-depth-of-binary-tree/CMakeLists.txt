add_library(0104-maximum-depth-of-binary-tree_lib OBJECT solution.cpp)

add_executable(test_0104-maximum-depth-of-binary-tree tests/test_0104-maximum-depth-of-binary-tree.cpp $<TARGET_OBJECTS:0104-maximum-depth-of-binary-tree_lib>)
target_link_libraries(test_0104-maximum-depth-of-binary-tree GTest::gtest_main)
gtest_discover_tests(test_0104-maximum-depth-of-binary-tree)
