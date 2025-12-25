add_library(0960-delete-columns-to-make-sorted-iii_lib OBJECT solution.cpp)

add_executable(test_0960-delete-columns-to-make-sorted-iii tests/test_0960-delete-columns-to-make-sorted-iii.cpp $<TARGET_OBJECTS:0960-delete-columns-to-make-sorted-iii_lib>)
target_link_libraries(test_0960-delete-columns-to-make-sorted-iii GTest::gtest_main)
gtest_discover_tests(test_0960-delete-columns-to-make-sorted-iii)
