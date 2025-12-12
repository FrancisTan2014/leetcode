add_library(0021-merge-two-sorted-lists_lib OBJECT solution.cpp)

add_executable(test_0021-merge-two-sorted-lists tests/test_0021-merge-two-sorted-lists.cpp $<TARGET_OBJECTS:0021-merge-two-sorted-lists_lib>)
target_link_libraries(test_0021-merge-two-sorted-lists GTest::gtest_main)
gtest_discover_tests(test_0021-merge-two-sorted-lists)
