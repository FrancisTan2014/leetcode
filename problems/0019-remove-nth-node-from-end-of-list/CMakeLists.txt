add_library(0019-remove-nth-node-from-end-of-list_lib OBJECT solution.cpp)

add_executable(test_0019-remove-nth-node-from-end-of-list tests/test_0019-remove-nth-node-from-end-of-list.cpp $<TARGET_OBJECTS:0019-remove-nth-node-from-end-of-list_lib>)
target_link_libraries(test_0019-remove-nth-node-from-end-of-list GTest::gtest_main)
gtest_discover_tests(test_0019-remove-nth-node-from-end-of-list)
