add_library(0110-balanced-binary-tree_lib OBJECT solution.cpp)

add_executable(test_0110-balanced-binary-tree tests/test_0110-balanced-binary-tree.cpp $<TARGET_OBJECTS:0110-balanced-binary-tree_lib>)
target_link_libraries(test_0110-balanced-binary-tree GTest::gtest_main)
gtest_discover_tests(test_0110-balanced-binary-tree)
