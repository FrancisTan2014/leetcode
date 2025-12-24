add_library(0955-delete-columns-to-make-sorted-ii_lib OBJECT solution.cpp)

add_executable(test_0955-delete-columns-to-make-sorted-ii tests/test_0955-delete-columns-to-make-sorted-ii.cpp $<TARGET_OBJECTS:0955-delete-columns-to-make-sorted-ii_lib>)
target_link_libraries(test_0955-delete-columns-to-make-sorted-ii GTest::gtest_main)
gtest_discover_tests(test_0955-delete-columns-to-make-sorted-ii)
