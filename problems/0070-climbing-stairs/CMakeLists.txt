add_library(0070-climbing-stairs_lib OBJECT solution.cpp)

add_executable(test_0070-climbing-stairs tests/test_0070-climbing-stairs.cpp $<TARGET_OBJECTS:0070-climbing-stairs_lib>)
target_link_libraries(test_0070-climbing-stairs GTest::gtest_main)
gtest_discover_tests(test_0070-climbing-stairs)
