// tests/test_two_sum.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"
#include <vector>
using namespace std;
using namespace leetcode;

TEST(TwoSum, Basic) {
    Solution s;
    vector<int> nums = {2,7,11,15};
    auto out = s.twoSum(nums, 9);
    ASSERT_EQ(out.size(), 2);
    EXPECT_EQ(out[0], 0);
    EXPECT_EQ(out[1], 1);
}

TEST(TwoSum, NoSolution) {
    Solution s;
    vector<int> nums = {1,2,3};
    auto out = s.twoSum(nums, 7);
    EXPECT_TRUE(out.empty());
}

// Performance test example
TEST(TwoSum, Performance_SmallArray) {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    // Measure performance without limits
    PerformanceMonitor monitor;
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.twoSum(nums, target);
    }, result);
    
    // Verify correctness
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "SmallArray");
    
    // Assert performance limits (adjust as needed)
    EXPECT_TIME_LIMIT(metrics, 10.0);  // 10ms limit
}

// Performance test with strict limits
TEST(TwoSum, Performance_LargeArray) {
    Solution s;
    
    // Create a large test case
    vector<int> nums;
    for (int i = 0; i < 10000; i++) {
        nums.push_back(i);
    }
    int target = 19997; // nums[9998] + nums[9999]
    
    // Monitor with limits: 100ms time, 10MB memory
    PerformanceMonitor monitor(100.0, 10 * 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.twoSum(nums, target);
    }, result);
    
    // Verify correctness
    ASSERT_EQ(result.size(), 2);
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "LargeArray");
    EXPECT_PERFORMANCE(metrics, 100.0, 10 * 1024);
    
    // Individual checks with better messages
    if (metrics.time_exceeded) {
        FAIL() << "Time limit exceeded: " << metrics.time_ms << "ms > 100ms";
    }
    if (metrics.memory_exceeded) {
        FAIL() << "Memory limit exceeded: " << metrics.memory_kb << "KB > 10MB";
    }
}
