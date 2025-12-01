add_library(0904-fruit-into-baskets_lib OBJECT solution.cpp)

add_executable(test_0904-fruit-into-baskets tests/test_0904-fruit-into-baskets.cpp $<TARGET_OBJECTS:0904-fruit-into-baskets_lib>)
target_link_libraries(test_0904-fruit-into-baskets GTest::gtest_main)
gtest_discover_tests(test_0904-fruit-into-baskets)
