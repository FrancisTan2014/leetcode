add_library(0076-minimum-window-substring_lib OBJECT solution.cpp)

add_executable(test_0076-minimum-window-substring tests/test_0076-minimum-window-substring.cpp $<TARGET_OBJECTS:0076-minimum-window-substring_lib>)
target_link_libraries(test_0076-minimum-window-substring GTest::gtest_main)
gtest_discover_tests(test_0076-minimum-window-substring)
