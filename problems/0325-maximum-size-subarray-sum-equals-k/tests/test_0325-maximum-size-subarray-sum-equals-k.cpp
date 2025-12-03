// tests/test_0325-maximum-size-subarray-sum-equals-k.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [1], k=1: entire array, prefix: 0→1, check 1-1=0 (found at -1), length = 0-(-1) = 1
TEST(MaximumSizeSubarraySumEqualsK, SingleElementMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1}, 1), 1);
}

// [1], k=2: no match, prefix: 0→1, check 1-2=-1 (not found)
TEST(MaximumSizeSubarraySumEqualsK, SingleElementNoMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1}, 2), 0);
}

// [1, 2], k=3: entire array, prefix: 0→1→3, check 3-3=0 (found at -1), length = 1-(-1) = 2
TEST(MaximumSizeSubarraySumEqualsK, TwoElementsMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 2}, 3), 2);
}

// [1, 2], k=1: [1], prefix: 0→1→3, at index 0: check 1-1=0 (found), length = 0-(-1) = 1
TEST(MaximumSizeSubarraySumEqualsK, TwoElementsPartialMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 2}, 1), 1);
}

// ========== Typical Cases ==========

// [1, -1, 5, -2, 3], k=3
// prefix: 0→1→0→5→3→6
// At index 3: prefix=3, check 3-3=0 (found at -1), length = 3-(-1) = 4 → [1,-1,5,-2]
// At index 4: prefix=6, check 6-3=3 (found at 3), length = 4-3 = 1 → [3]
TEST(MaximumSizeSubarraySumEqualsK, Example1) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, -1, 5, -2, 3}, 3), 4);
}

// [-2, -1, 2, 1], k=1
// prefix: 0→-2→-3→-1→0
// At index 2: prefix=-1, check -1-1=-2 (found at 0), length = 2-0 = 2 → [-1,2]
// At index 3: prefix=0, check 0-1=-1 (found at 2), length = 3-2 = 1 → [1]
TEST(MaximumSizeSubarraySumEqualsK, Example2) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({-2, -1, 2, 1}, 1), 2);
}

// [1, 2, 3, 4], k=10: entire array, prefix: 0→1→3→6→10
// At index 3: prefix=10, check 10-10=0 (found at -1), length = 3-(-1) = 4
TEST(MaximumSizeSubarraySumEqualsK, EntireArray) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 2, 3, 4}, 10), 4);
}

// [2, 3, 4], k=10: no match
// prefix: 0→2→5→9, never reaches 10
TEST(MaximumSizeSubarraySumEqualsK, NoMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({2, 3, 4}, 10), 0);
}

// ========== Boundary Cases ==========

// [0], k=0: prefix: 0→0, at index 0: check 0-0=0 (found at -1), length = 0-(-1) = 1
TEST(MaximumSizeSubarraySumEqualsK, SingleZero) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({0}, 0), 1);
}

// [0, 0, 0], k=0: entire array
// prefix: 0→0→0→0, at index 0: check 0-0=0 (found at -1), length = 0-(-1) = 1
// But prefix 0 doesn't get stored again (keep first occurrence at -1)
// At index 1,2: still check 0-0=0 (found at -1), lengths = 1-(-1)=2, 2-(-1)=3
TEST(MaximumSizeSubarraySumEqualsK, MultipleZeros) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({0, 0, 0}, 0), 3);
}

// [1, 1, 1, 1], k=2
// prefix: 0→1→2→3→4
// At index 1: prefix=2, check 2-2=0 (found at -1), length = 1-(-1) = 2 → [1,1]
TEST(MaximumSizeSubarraySumEqualsK, AllSamePositive) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 1, 1, 1}, 2), 2);
}

// [-1, -1, -1], k=-2
// prefix: 0→-1→-2→-3
// At index 1: prefix=-2, check -2-(-2)=0 (found at -1), length = 1-(-1) = 2
TEST(MaximumSizeSubarraySumEqualsK, AllSameNegative) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({-1, -1, -1}, -2), 2);
}

// ========== Pattern Cases ==========

// [1, 0, -1, 1, 0, -1], k=0
// prefix: 0→1→1→0→1→1→0
// At index 2: prefix=0, check 0-0=0 (found at -1), length = 2-(-1) = 3 → [1,0,-1]
// At index 5: prefix=0, check 0-0=0 (found at -1), length = 5-(-1) = 6 → entire array
TEST(MaximumSizeSubarraySumEqualsK, RepeatingPattern) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 0, -1, 1, 0, -1}, 0), 6);
}

// [1, -1, 1, -1, 1], k=1
// prefix: 0→1→0→1→0→1
// At index 0: prefix=1, check 1-1=0 (found at -1), length = 0-(-1) = 1
// At index 2: prefix=1, check 1-1=0 (found at -1), length = 2-(-1) = 3
// At index 4: prefix=1, check 1-1=0 (found at -1), length = 4-(-1) = 5
TEST(MaximumSizeSubarraySumEqualsK, AlternatingPattern) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, -1, 1, -1, 1}, 1), 5);
}

// [5, -2, 3, -1, 1], k=5
// prefix: 0→5→3→6→5→6
// At index 0: prefix=5, check 5-5=0 (found at -1), length = 0-(-1) = 1 → [5]
// At index 3: prefix=5, check 5-5=0 (found at -1), length = 3-(-1) = 4 → [5,-2,3,-1]
TEST(MaximumSizeSubarraySumEqualsK, SamePrefixSum) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({5, -2, 3, -1, 1}, 5), 4);
}

// ========== Edge Cases ==========

// [10, -5, -5, 10], k=0
// prefix: 0→10→5→0→10
// At index 2: prefix=0, check 0-0=0 (found at -1), length = 2-(-1) = 3 → [10,-5,-5]
TEST(MaximumSizeSubarraySumEqualsK, BalancedMiddle) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({10, -5, -5, 10}, 0), 3);
}

// [1, 2, -1, -2, 3], k=3
// prefix: 0→1→3→2→0→3
// At index 1: prefix=3, check 3-3=0 (found at -1), length = 1-(-1) = 2 → [1,2]
// At index 4: prefix=3, check 3-3=0 (found at -1), length = 4-(-1) = 5 → entire array
TEST(MaximumSizeSubarraySumEqualsK, MultipleValidSubarrays) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 2, -1, -2, 3}, 3), 5);
}

// [-1, 1, -1, 1, -1, 1], k=0
// prefix: 0→-1→0→-1→0→-1→0
// At index 1: prefix=0, check 0-0=0 (found at -1), length = 1-(-1) = 2
// At index 3: prefix=0, check 0-0=0 (found at -1), length = 3-(-1) = 4
// At index 5: prefix=0, check 0-0=0 (found at -1), length = 5-(-1) = 6
TEST(MaximumSizeSubarraySumEqualsK, AlternatingZeroSum) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({-1, 1, -1, 1, -1, 1}, 0), 6);
}

// [100, -100, 50, -50], k=0
// prefix: 0→100→0→50→0
// At index 1: prefix=0, check 0-0=0 (found at -1), length = 1-(-1) = 2 → [100,-100]
// At index 3: prefix=0, check 0-0=0 (found at -1), length = 3-(-1) = 4 → entire array
TEST(MaximumSizeSubarraySumEqualsK, LargeValues) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({100, -100, 50, -50}, 0), 4);
}

// ========== Trick Cases ==========

// [1, 1, 1, 1, 1], k=3
// prefix: 0→1→2→3→4→5
// At index 2: prefix=3, check 3-3=0 (found at -1), length = 2-(-1) = 3
TEST(MaximumSizeSubarraySumEqualsK, ConsecutiveSum) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 1, 1, 1, 1}, 3), 3);
}

// [3, 1, -1, 1, -1, 1], k=3
// prefix: 0→3→4→3→4→3→4
// At index 0: prefix=3, check 3-3=0 (found at -1), length = 0-(-1) = 1
// At index 2: prefix=3, check 3-3=0 (found at -1), length = 2-(-1) = 3
// At index 4: prefix=3, check 3-3=0 (found at -1), length = 4-(-1) = 5
TEST(MaximumSizeSubarraySumEqualsK, RepeatingPrefixSum) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({3, 1, -1, 1, -1, 1}, 3), 5);
}

// [1, 2, 3, -3, -2, -1, 4], k=4
// prefix: 0→1→3→6→3→1→0→4
// At index 6: prefix=4, check 4-4=0 (found at -1), length = 6-(-1) = 7
TEST(MaximumSizeSubarraySumEqualsK, ComplexPattern) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({1, 2, 3, -3, -2, -1, 4}, 4), 7);
}

// [5, -3, 2, -1, 4, -2, 1], k=6
// prefix: 0→5→2→4→3→7→5→6
// At index 5: prefix=5, check 5-6=-1 (not found)
// At index 6: prefix=6, check 6-6=0 (found at -1), length = 6-(-1) = 7
TEST(MaximumSizeSubarraySumEqualsK, NoEarlyMatch) {
    Solution s;
    EXPECT_EQ(s.maxSubArrayLen({5, -3, 2, -1, 4, -2, 1}, 6), 7);
}

// ========== Performance Cases ==========

TEST(MaximumSizeSubarraySumEqualsK, MaxLengthAllSameSum) {
    Solution s;
    
    // All elements sum to k: [1,1,1,...,1], k = 100000
    vector<int> nums(100000, 1);
    
    PerformanceMonitor monitor(100.0, 10240); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSubArrayLen(nums, 100000);
    }, result);
    
    // Entire array sums to 100000
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllSameSum");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(MaximumSizeSubarraySumEqualsK, MaxLengthAlternating) {
    Solution s;
    
    // Alternating [1, -1, 1, -1, ...], k = 0
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = (i % 2 == 0) ? 1 : -1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSubArrayLen(nums, 0);
    }, result);
    
    // Entire array sums to 0
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAlternating");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(MaximumSizeSubarraySumEqualsK, MaxLengthNoMatch) {
    Solution s;
    
    // All positive, k = -1 (impossible)
    vector<int> nums(100000, 1);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSubArrayLen(nums, -1);
    }, result);
    
    // No subarray can sum to -1
    EXPECT_EQ(result, 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthNoMatch");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(MaximumSizeSubarraySumEqualsK, MaxLengthManyUniqueSums) {
    Solution s;
    
    // Pattern with many unique prefix sums: [1, -1, 2, -2, 3, -3, ...]
    // Creates many unique prefix sums but keeps values reasonable
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = (i % 2 == 0) ? (i / 2 + 1) : -(i / 2 + 1);
    }
    // prefix sums: 0→1→0→2→0→3→0... (alternates back to 0)
    // Looking for k=0 should give length 100000 (entire array sums to 0)
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSubArrayLen(nums, 0);
    }, result);
    
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthManyUniqueSums");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
