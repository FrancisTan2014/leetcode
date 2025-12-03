add_library(0525-contiguous-array_lib OBJECT solution.cpp)

add_executable(test_0525-contiguous-array tests/test_0525-contiguous-array.cpp $<TARGET_OBJECTS:0525-contiguous-array_lib>)
target_link_libraries(test_0525-contiguous-array GTest::gtest_main)
gtest_discover_tests(test_0525-contiguous-array)
