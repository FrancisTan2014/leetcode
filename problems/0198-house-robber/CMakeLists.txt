add_library(0198-house-robber_lib OBJECT solution.cpp)

add_executable(test_0198-house-robber tests/test_0198-house-robber.cpp $<TARGET_OBJECTS:0198-house-robber_lib>)
target_link_libraries(test_0198-house-robber GTest::gtest_main)
gtest_discover_tests(test_0198-house-robber)
