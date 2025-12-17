add_library(0235-lowest-common-ancestor-of-a-binary-search-tree_lib OBJECT solution.cpp)

add_executable(test_0235-lowest-common-ancestor-of-a-binary-search-tree tests/test_0235-lowest-common-ancestor-of-a-binary-search-tree.cpp $<TARGET_OBJECTS:0235-lowest-common-ancestor-of-a-binary-search-tree_lib>)
target_link_libraries(test_0235-lowest-common-ancestor-of-a-binary-search-tree GTest::gtest_main)
gtest_discover_tests(test_0235-lowest-common-ancestor-of-a-binary-search-tree)
