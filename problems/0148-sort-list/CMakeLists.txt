add_library(0148-sort-list_lib OBJECT solution.cpp)

add_executable(test_0148-sort-list tests/test_0148-sort-list.cpp $<TARGET_OBJECTS:0148-sort-list_lib>)
target_link_libraries(test_0148-sort-list GTest::gtest_main)
gtest_discover_tests(test_0148-sort-list)
