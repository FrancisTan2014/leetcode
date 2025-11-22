add_library(0071-simplify-path_lib OBJECT solution.cpp)

add_executable(test_0071-simplify-path tests/test_0071-simplify-path.cpp $<TARGET_OBJECTS:0071-simplify-path_lib>)
target_link_libraries(test_0071-simplify-path GTest::gtest_main)
gtest_discover_tests(test_0071-simplify-path)
