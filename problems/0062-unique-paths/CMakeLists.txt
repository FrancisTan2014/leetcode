add_library(0062-unique-paths_lib OBJECT solution.cpp)

add_executable(test_0062-unique-paths tests/test_0062-unique-paths.cpp $<TARGET_OBJECTS:0062-unique-paths_lib>)
target_link_libraries(test_0062-unique-paths GTest::gtest_main)
gtest_discover_tests(test_0062-unique-paths)
