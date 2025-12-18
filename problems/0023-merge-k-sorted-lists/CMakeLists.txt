add_library(0023-merge-k-sorted-lists_lib OBJECT solution.cpp)

add_executable(test_0023-merge-k-sorted-lists tests/test_0023-merge-k-sorted-lists.cpp $<TARGET_OBJECTS:0023-merge-k-sorted-lists_lib>)
target_link_libraries(test_0023-merge-k-sorted-lists GTest::gtest_main)
gtest_discover_tests(test_0023-merge-k-sorted-lists)
