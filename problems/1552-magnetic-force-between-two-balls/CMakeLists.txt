add_library(1552-magnetic-force-between-two-balls_lib OBJECT solution.cpp)

add_executable(test_1552-magnetic-force-between-two-balls tests/test_1552-magnetic-force-between-two-balls.cpp $<TARGET_OBJECTS:1552-magnetic-force-between-two-balls_lib>)
target_link_libraries(test_1552-magnetic-force-between-two-balls GTest::gtest_main)
gtest_discover_tests(test_1552-magnetic-force-between-two-balls)
