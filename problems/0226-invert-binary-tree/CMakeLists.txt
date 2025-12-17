add_library(0226-invert-binary-tree_lib OBJECT solution.cpp)

add_executable(test_0226-invert-binary-tree tests/test_0226-invert-binary-tree.cpp $<TARGET_OBJECTS:0226-invert-binary-tree_lib>)
target_link_libraries(test_0226-invert-binary-tree GTest::gtest_main)
gtest_discover_tests(test_0226-invert-binary-tree)
