add_library(0325-maximum-size-subarray-sum-equals-k_lib OBJECT solution.cpp)

add_executable(test_0325-maximum-size-subarray-sum-equals-k tests/test_0325-maximum-size-subarray-sum-equals-k.cpp $<TARGET_OBJECTS:0325-maximum-size-subarray-sum-equals-k_lib>)
target_link_libraries(test_0325-maximum-size-subarray-sum-equals-k GTest::gtest_main)
gtest_discover_tests(test_0325-maximum-size-subarray-sum-equals-k)
