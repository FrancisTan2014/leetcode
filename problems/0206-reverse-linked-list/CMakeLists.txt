add_library(0206-reverse-linked-list_lib OBJECT solution.cpp)

add_executable(test_0206-reverse-linked-list tests/test_0206-reverse-linked-list.cpp $<TARGET_OBJECTS:0206-reverse-linked-list_lib>)
target_link_libraries(test_0206-reverse-linked-list GTest::gtest_main)
gtest_discover_tests(test_0206-reverse-linked-list)
