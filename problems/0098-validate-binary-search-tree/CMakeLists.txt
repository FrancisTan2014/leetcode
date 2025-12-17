add_library(0098-validate-binary-search-tree_lib OBJECT solution.cpp)

add_executable(test_0098-validate-binary-search-tree tests/test_0098-validate-binary-search-tree.cpp $<TARGET_OBJECTS:0098-validate-binary-search-tree_lib>)
target_link_libraries(test_0098-validate-binary-search-tree GTest::gtest_main)
gtest_discover_tests(test_0098-validate-binary-search-tree)
