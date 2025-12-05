add_library(0875-koko-eating-bananas_lib OBJECT solution.cpp)

add_executable(test_0875-koko-eating-bananas tests/test_0875-koko-eating-bananas.cpp $<TARGET_OBJECTS:0875-koko-eating-bananas_lib>)
target_link_libraries(test_0875-koko-eating-bananas GTest::gtest_main)
gtest_discover_tests(test_0875-koko-eating-bananas)
