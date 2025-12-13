add_library(0994-rotting-oranges_lib OBJECT solution.cpp)

add_executable(test_0994-rotting-oranges tests/test_0994-rotting-oranges.cpp $<TARGET_OBJECTS:0994-rotting-oranges_lib>)
target_link_libraries(test_0994-rotting-oranges GTest::gtest_main)
gtest_discover_tests(test_0994-rotting-oranges)
