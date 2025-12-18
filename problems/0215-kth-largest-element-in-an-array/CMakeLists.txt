add_library(0215-kth-largest-element-in-an-array_lib OBJECT solution.cpp)

add_executable(test_0215-kth-largest-element-in-an-array tests/test_0215-kth-largest-element-in-an-array.cpp $<TARGET_OBJECTS:0215-kth-largest-element-in-an-array_lib>)
target_link_libraries(test_0215-kth-largest-element-in-an-array GTest::gtest_main)
gtest_discover_tests(test_0215-kth-largest-element-in-an-array)
