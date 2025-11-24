// tests/test_0167-two-sum-II.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(TwoSumII, MinimumLength) {
    Solution s;
    vector<int> numbers = {1, 2};
    vector<int> result = s.twoSum(numbers, 3);
    EXPECT_EQ(result, vector<int>({1, 2}));
}

TEST(TwoSumII, ThreeElements) {
    Solution s;
    vector<int> numbers = {2, 3, 4};
    vector<int> result = s.twoSum(numbers, 6);
    EXPECT_EQ(result, vector<int>({1, 3}));
}

// ========== Typical Cases ==========

TEST(TwoSumII, Example1) {
    Solution s;
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> result = s.twoSum(numbers, 9);
    EXPECT_EQ(result, vector<int>({1, 2}));
}

TEST(TwoSumII, MiddleElements) {
    Solution s;
    vector<int> numbers = {1, 3, 5, 7, 9, 13};
    vector<int> result = s.twoSum(numbers, 12);
    EXPECT_EQ(result, vector<int>({2, 5})); // 3 + 9 = 12 (unique solution)
}

TEST(TwoSumII, FirstAndLast) {
    Solution s;
    vector<int> numbers = {1, 2, 3, 4, 5, 10};
    vector<int> result = s.twoSum(numbers, 11);
    EXPECT_EQ(result, vector<int>({1, 6})); // 1 + 10 = 11
}

// ========== Boundary Cases ==========

TEST(TwoSumII, MaxLength) {
    Solution s;
    // Create array of length 30000 (max constraint)
    vector<int> numbers;
    numbers.reserve(30000);
    for (int i = 0; i < 30000; i++) {
        numbers.push_back(i);
    }
    // Target: 0 + 29999 = 29999
    vector<int> result = s.twoSum(numbers, 29999);
    EXPECT_EQ(result, vector<int>({1, 30000}));
}

TEST(TwoSumII, MinValues) {
    Solution s;
    vector<int> numbers = {-1000, -999, -500, 0, 500};
    vector<int> result = s.twoSum(numbers, -1999);
    EXPECT_EQ(result, vector<int>({1, 2})); // -1000 + (-999) = -1999
}

TEST(TwoSumII, MaxValues) {
    Solution s;
    vector<int> numbers = {998, 999, 1000};
    vector<int> result = s.twoSum(numbers, 1999);
    EXPECT_EQ(result, vector<int>({2, 3})); // 999 + 1000 = 1999
}

// ========== Edge Behavior Cases ==========

TEST(TwoSumII, NegativeNumbers) {
    Solution s;
    vector<int> numbers = {-1, 0};
    vector<int> result = s.twoSum(numbers, -1);
    EXPECT_EQ(result, vector<int>({1, 2}));
}

TEST(TwoSumII, AllNegative) {
    Solution s;
    vector<int> numbers = {-10, -8, -5, -3, -1};
    vector<int> result = s.twoSum(numbers, -6);
    EXPECT_EQ(result, vector<int>({3, 5})); // -5 + (-1) = -6
}

TEST(TwoSumII, MixedPositiveNegative) {
    Solution s;
    vector<int> numbers = {-5, -3, 0, 3, 6, 8};
    vector<int> result = s.twoSum(numbers, 0);
    EXPECT_EQ(result, vector<int>({2, 4})); // -3 + 3 = 0
}

TEST(TwoSumII, Duplicates) {
    Solution s;
    vector<int> numbers = {1, 2, 2, 4, 5};
    vector<int> result = s.twoSum(numbers, 4);
    EXPECT_EQ(result, vector<int>({2, 3})); // 2 + 2 = 4
}

TEST(TwoSumII, AllSameExceptTwo) {
    Solution s;
    vector<int> numbers = {1, 5, 5, 5, 5, 5, 10};
    vector<int> result = s.twoSum(numbers, 11);
    EXPECT_EQ(result, vector<int>({1, 7})); // 1 + 10 = 11
}

// ========== Trick Cases ==========

TEST(TwoSumII, ConsecutiveIndices) {
    Solution s;
    vector<int> numbers = {1, 3, 4, 5, 7, 11};
    vector<int> result = s.twoSum(numbers, 7);
    EXPECT_EQ(result, vector<int>({2, 3})); // 3 + 4 = 7
}

TEST(TwoSumII, LargeGap) {
    Solution s;
    vector<int> numbers = {-1000, -500, 0, 500, 1000};
    vector<int> result = s.twoSum(numbers, 0);
    EXPECT_EQ(result, vector<int>({1, 5})); // -1000 + 1000 = 0
}

TEST(TwoSumII, TargetZero) {
    Solution s;
    vector<int> numbers = {-5, -2, 0, 2, 6};
    vector<int> result = s.twoSum(numbers, 0);
    EXPECT_EQ(result, vector<int>({2, 4})); // -2 + 2 = 0
}

TEST(TwoSumII, SmallTarget) {
    Solution s;
    vector<int> numbers = {-1000, -999, -998};
    vector<int> result = s.twoSum(numbers, -1999);
    EXPECT_EQ(result, vector<int>({1, 2})); // -1000 + (-999) = -1999
}

// ========== Performance Cases ==========

TEST(TwoSumII, PerformanceMaxLength) {
    Solution s;
    
    // Create max-length sorted array (30000 elements)
    vector<int> numbers;
    numbers.reserve(30000);
    for (int i = 0; i < 30000; i++) {
        numbers.push_back(i - 15000); // Range: -15000 to 14999
    }
    
    // Worst case: target at the ends (requires full scan for naive O(n²) solution)
    int target = -30000 + 1; // First + second element
    
    PerformanceMonitor monitor(10.0, 512); // 10ms, 512KB (O(1) space required)
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.twoSum(numbers, target);
    }, result);
    
    EXPECT_EQ(result, vector<int>({1, 2}));
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLength30K");
    EXPECT_PERFORMANCE(metrics, 10.0, 512);
}

TEST(TwoSumII, PerformanceWorstCase) {
    Solution s;
    
    // Worst case for two-pointer: answer in the middle
    vector<int> numbers;
    numbers.reserve(20000);
    for (int i = 0; i < 20000; i++) {
        numbers.push_back(i);
    }
    
    // Target elements roughly in the middle
    int target = 19999; // 9999 + 10000
    
    PerformanceMonitor monitor(10.0, 512);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.twoSum(numbers, target);
    }, result);
    
    // Verify the solution is correct (convert from 1-indexed to 0-indexed)
    EXPECT_EQ(numbers[result[0] - 1] + numbers[result[1] - 1], target);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "WorstCase20K");
    EXPECT_PERFORMANCE(metrics, 10.0, 512);
}
