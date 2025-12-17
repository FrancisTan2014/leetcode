add_library(0102-binary-tree-level-order-traversal_lib OBJECT solution.cpp)

add_executable(test_0102-binary-tree-level-order-traversal tests/test_0102-binary-tree-level-order-traversal.cpp $<TARGET_OBJECTS:0102-binary-tree-level-order-traversal_lib>)
target_link_libraries(test_0102-binary-tree-level-order-traversal GTest::gtest_main)
gtest_discover_tests(test_0102-binary-tree-level-order-traversal)
