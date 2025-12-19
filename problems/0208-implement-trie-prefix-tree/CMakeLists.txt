add_library(implement_trie_prefix_tree_lib OBJECT solution.cpp)

add_executable(test_0208-implement-trie-prefix-tree tests/test_0208-implement-trie-prefix-tree.cpp $<TARGET_OBJECTS:implement_trie_prefix_tree_lib>)
target_link_libraries(test_0208-implement-trie-prefix-tree GTest::gtest_main)
gtest_discover_tests(test_0208-implement-trie-prefix-tree)
