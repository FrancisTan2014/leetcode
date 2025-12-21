add_library(0297-serialize-and-deserialize-binary-tree_lib OBJECT solution.cpp)

add_executable(test_0297-serialize-and-deserialize-binary-tree tests/test_0297-serialize-and-deserialize-binary-tree.cpp $<TARGET_OBJECTS:0297-serialize-and-deserialize-binary-tree_lib>)
target_link_libraries(test_0297-serialize-and-deserialize-binary-tree GTest::gtest_main)
gtest_discover_tests(test_0297-serialize-and-deserialize-binary-tree)
