add_library(0239-sliding-window-maximum_lib OBJECT solution.cpp)

add_executable(test_0239-sliding-window-maximum tests/test_0239-sliding-window-maximum.cpp $<TARGET_OBJECTS:0239-sliding-window-maximum_lib>)
target_link_libraries(test_0239-sliding-window-maximum GTest::gtest_main)
gtest_discover_tests(test_0239-sliding-window-maximum)
