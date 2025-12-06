add_library(0069-sqrtx_lib OBJECT solution.cpp)

add_executable(test_0069-sqrtx tests/test_0069-sqrtx.cpp $<TARGET_OBJECTS:0069-sqrtx_lib>)
target_link_libraries(test_0069-sqrtx GTest::gtest_main)
gtest_discover_tests(test_0069-sqrtx)
