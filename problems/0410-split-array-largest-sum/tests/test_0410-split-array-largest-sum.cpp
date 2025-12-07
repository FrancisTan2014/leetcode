// tests/test_0410-split-array-largest-sum.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

TEST(SplitArray, SingleElement) {
    Solution s;
    vector<int> nums = {10};
    EXPECT_EQ(s.splitArray(nums, 1), 10);
}

TEST(SplitArray, TwoElementsOneSplit) {
    Solution s;
    vector<int> nums = {1, 2};
    EXPECT_EQ(s.splitArray(nums, 1), 3);
}

TEST(SplitArray, TwoElementsTwoSplits) {
    Solution s;
    vector<int> nums = {1, 2};
    EXPECT_EQ(s.splitArray(nums, 2), 2);
}

TEST(SplitArray, Example1) {
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    EXPECT_EQ(s.splitArray(nums, 2), 18);
}

TEST(SplitArray, Example2) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.splitArray(nums, 2), 9);
}

TEST(SplitArray, ThreeElementsTwoSplits) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(s.splitArray(nums, 2), 3);
}

TEST(SplitArray, ThreeElementsThreeSplits) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(s.splitArray(nums, 3), 3);
}

TEST(SplitArray, AllOnes) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    EXPECT_EQ(s.splitArray(nums, 3), 2);
}

TEST(SplitArray, MaxSplits) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.splitArray(nums, 5), 5);
}

TEST(SplitArray, LargeNumbers) {
    Solution s;
    vector<int> nums = {100, 200, 300, 400, 500};
    EXPECT_EQ(s.splitArray(nums, 2), 900);
}

TEST(SplitArray, UnevenDistribution) {
    Solution s;
    vector<int> nums = {1, 1, 1, 10};
    EXPECT_EQ(s.splitArray(nums, 2), 10);
}

TEST(SplitArray, IncreasingSequence) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.splitArray(nums, 3), 21);
}

TEST(SplitArray, DecreasingSequence) {
    Solution s;
    vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    EXPECT_EQ(s.splitArray(nums, 3), 21);
}

TEST(SplitArray, WithZeros) {
    Solution s;
    vector<int> nums = {0, 0, 0, 0, 5};
    EXPECT_EQ(s.splitArray(nums, 2), 5);
}

TEST(SplitArray, AllZeros) {
    Solution s;
    vector<int> nums = {0, 0, 0, 0, 0};
    EXPECT_EQ(s.splitArray(nums, 3), 0);
}

TEST(SplitArray, TwoLargeGroups) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 10, 10, 10, 10};
    EXPECT_EQ(s.splitArray(nums, 2), 24);
}

TEST(SplitArray, FourSplits) {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    EXPECT_EQ(s.splitArray(nums, 3), 6);
}

TEST(SplitArray, MixedValues) {
    Solution s;
    vector<int> nums = {5, 2, 3, 1, 6, 4};
    EXPECT_EQ(s.splitArray(nums, 3), 10);
}

TEST(SplitArray, LargeSingleValue) {
    Solution s;
    vector<int> nums = {1000000, 1, 1, 1, 1};
    EXPECT_EQ(s.splitArray(nums, 2), 1000000);
}

TEST(SplitArray, EqualSums) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(s.splitArray(nums, 3), 9);
}

TEST(SplitArray, TenElements) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.splitArray(nums, 5), 15);
}

TEST(SplitArray, ManySplits) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(s.splitArray(nums, 4), 11);
}

TEST(SplitArray, SmallAndLarge) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1000000};
    EXPECT_EQ(s.splitArray(nums, 2), 1000000);
}

TEST(SplitArray, ConsecutivePairs) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.splitArray(nums, 2), 28);
}

TEST(SplitArray, Performance1000Elements) {
    Solution s;
    
    vector<int> nums(1000);
    for (int i = 0; i < 1000; i++) {
        nums[i] = i + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.splitArray(nums, 10);
    }, result);
    
    EXPECT_EQ(result, 50325);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance1000Elements");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SplitArray, PerformanceLargeValues) {
    Solution s;
    
    vector<int> nums(1000, 1000000);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.splitArray(nums, 50);
    }, result);
    
    EXPECT_EQ(result, 20000000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "PerformanceLargeValues");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SplitArray, PerformanceMaxSplits) {
    Solution s;
    
    vector<int> nums(1000);
    for (int i = 0; i < 1000; i++) {
        nums[i] = (i + 1) * 100;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.splitArray(nums, 50);
    }, result);
    
    EXPECT_EQ(result, 1036100);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "PerformanceMaxSplits");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
