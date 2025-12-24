add_library(0944-delete-columns-to-make-sorted_lib OBJECT solution.cpp)

add_executable(test_0944-delete-columns-to-make-sorted tests/test_0944-delete-columns-to-make-sorted.cpp $<TARGET_OBJECTS:0944-delete-columns-to-make-sorted_lib>)
target_link_libraries(test_0944-delete-columns-to-make-sorted GTest::gtest_main)
gtest_discover_tests(test_0944-delete-columns-to-make-sorted)
