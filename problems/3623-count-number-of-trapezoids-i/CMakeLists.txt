cmake_minimum_required(VERSION 3.10)

# Add executable for tests
add_executable(test_3623-count-number-of-trapezoids-i
    tests/test_3623-count-number-of-trapezoids-i.cpp
)

# Link against GoogleTest
target_link_libraries(test_3623-count-number-of-trapezoids-i
    gtest
    gtest_main
)

# Discover tests
gtest_discover_tests(test_3623-count-number-of-trapezoids-i)
