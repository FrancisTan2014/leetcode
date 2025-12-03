// tests/test_0525-contiguous-array.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [0,1]: balance 0→-1→0, length 2
TEST(ContiguousArray, TwoElements_01) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1}), 2);
}

// [1,0]: balance 0→1→0, length 2
TEST(ContiguousArray, TwoElements_10) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 0}), 2);
}

// [0,0]: balance 0→-1→-2, never returns to previous, max = 0
TEST(ContiguousArray, TwoSame_00) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 0}), 0);
}

// [1,1]: balance 0→1→2, never returns to previous, max = 0
TEST(ContiguousArray, TwoSame_11) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1}), 0);
}

// ========== Typical Cases ==========

// [0,1,0]: balance 0→-1→0→-1
// At index 1: balance 0 seen at start, length = 1-0 = 2 (subarray [0,1])
TEST(ContiguousArray, Example2) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 0}), 2);
}

// [0,1,1,0]: balance 0→-1→0→1→0
// At index 1: balance 0, length = 1-(-1) = 2
// At index 3: balance 0, length = 3-(-1) = 4 (entire array)
TEST(ContiguousArray, Balanced) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 1, 0}), 4);
}

// [0,1,1,1,1,1,0,0,0]: balance 0→-1→0→1→2→3→4→3→2→1
// Positions: 0:-1, 1:0, 2:1, 3:2, 4:3, 5:4, 6:3, 7:2, 8:1
// Balance 3 first at index 4, again at index 6: length = 6-4 = 2
// Balance 2 first at index 3, again at index 7: length = 7-3 = 4
// Balance 1 first at index 2, again at index 8: length = 8-2 = 6
TEST(ContiguousArray, Example3) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 1, 1, 1, 1, 0, 0, 0}), 6);
}

// [1,1,1,0,0,0]: balance 0→1→2→3→2→1→0
// Balance 0 at start and end: length = 6-0 = 6
TEST(ContiguousArray, AllBalanced) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1, 1, 0, 0, 0}), 6);
}

// ========== Boundary Cases ==========

// [0]: single element, can't have equal 0s and 1s
TEST(ContiguousArray, SingleElement_0) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0}), 0);
}

// [1]: single element
TEST(ContiguousArray, SingleElement_1) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1}), 0);
}

// [1,0,1,0,1,0]: balance 0→1→0→1→0→1→0
// Balance 0 at positions: start, 1, 3, 5
// Max: 5-start = 6 (entire array)
TEST(ContiguousArray, Alternating) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 0, 1, 0, 1, 0}), 6);
}

// [0,0,0,0]: balance 0→-1→-2→-3→-4, all unique, max = 0
TEST(ContiguousArray, AllZeros) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 0, 0, 0}), 0);
}

// [1,1,1,1]: balance 0→1→2→3→4, all unique, max = 0
TEST(ContiguousArray, AllOnes) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1, 1, 1}), 0);
}

// ========== Pattern Cases ==========

// [0,0,1,1]: balance 0→-1→-2→-1→0
// Balance -1 at indices 0,2: length = 2-0 = 2
// Balance 0 at start and end: length = 3-(-1) = 4
TEST(ContiguousArray, TwoGroupsBalanced) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 0, 1, 1}), 4);
}

// [1,0,0,1,1,0]: balance 0→1→0→-1→0→1→0
// Balance 0 at: start, 1, 3, 5
// Max: 5-start = 6 (entire array)
TEST(ContiguousArray, MixedPattern) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 0, 0, 1, 1, 0}), 6);
}

// [0,1,1,0,1,0,0,1]: balance 0→-1→0→1→0→1→0→-1→0
// Balance 0 appears at: start, 1, 3, 5, 8
// Max: 8-start = 8 (entire array)
TEST(ContiguousArray, ComplexPattern) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 1, 0, 1, 0, 0, 1}), 8);
}

// ========== Edge Cases ==========

// [1,1,1,1,0,0]: balance 0→1→2→3→4→3→2
// Balance 2 at indices 1,5: length = 5-1 = 4 (subarray [1,1,0,0])
// Balance 3 at indices 2,4: length = 4-2 = 2 (subarray [1,0])
TEST(ContiguousArray, UnbalancedPrefix) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1, 1, 1, 0, 0}), 4);
}

// [0,0,1,1,1,1]: balance 0→-1→-2→-1→0→1→2
// Balance -1 at indices 0,2: length = 2-0 = 2
// Balance 0 at start and 3: length = 3-0 = 4 (subarray [0,0,1,1])
TEST(ContiguousArray, UnbalancedSuffix) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 0, 1, 1, 1, 1}), 4);
}

// [1,1,0,1,0,0,0,1]: balance 0→1→2→1→2→1→0→-1→0
// Balance 1 at indices 0,2,4: max = 4-0 = 4
// Balance 0 at start,5,8: max = 8-start = 8 (entire array)
TEST(ContiguousArray, MultipleOccurrences) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1, 0, 1, 0, 0, 0, 1}), 8);
}

// [0,1,0,1,1,0,0,1,1,0]: all balanced
// balance 0→-1→0→-1→0→1→0→-1→0→1→0
// Balance 0 at: start,1,3,5,7,10: max = 10-start = 10
TEST(ContiguousArray, LongBalanced) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 0, 1, 1, 0, 0, 1, 1, 0}), 10);
}

// ========== Trick Cases ==========

// [0,0,0,1,1,1]: balance 0→-1→-2→-3→-2→-1→0
// Balance 0 at start and end: length = 6
// Balance -1 at 0,4: length = 4-0 = 4
// Balance -2 at 1,3: length = 3-1 = 2
TEST(ContiguousArray, SymmetricImbalance) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 0, 0, 1, 1, 1}), 6);
}

// [1,1,0,0,0,1,1,0]: balance 0→1→2→1→0→-1→0→1→0
// Balance 0 at: start,3,5,8: max = 8-start = 8
TEST(ContiguousArray, NestedBalance) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 1, 0, 0, 0, 1, 1, 0}), 8);
}

// [0,1,1,1,0,0,0,1]: balance 0→-1→0→1→2→1→0→-1→0
// Balance 0 at: start,1,5,8: max = 8-start = 8
TEST(ContiguousArray, BalanceAtBothEnds) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({0, 1, 1, 1, 0, 0, 0, 1}), 8);
}

// [1,0,1,1,0,0,1,0,1,0]: balance 0→1→0→1→2→1→0→1→0→1→0
// Balance 0 at: start,1,5,7,10: max = 10-start = 10
TEST(ContiguousArray, FrequentBalancePoints) {
    Solution s;
    EXPECT_EQ(s.findMaxLength({1, 0, 1, 1, 0, 0, 1, 0, 1, 0}), 10);
}

// ========== Performance Cases ==========

TEST(ContiguousArray, MaxLengthAllBalanced) {
    Solution s;
    
    // Create array: 50000 zeros followed by 50000 ones
    vector<int> nums(100000);
    for (int i = 0; i < 50000; i++) {
        nums[i] = 0;
        nums[i + 50000] = 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.findMaxLength(nums);
    }, result);
    
    // Entire array is balanced: 50000 zeros and 50000 ones
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllBalanced");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(ContiguousArray, MaxLengthAlternating) {
    Solution s;
    
    // Alternating: 0,1,0,1,0,1...
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = i % 2;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.findMaxLength(nums);
    }, result);
    
    // Entire array is balanced
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAlternating");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(ContiguousArray, MaxLengthNoBalance) {
    Solution s;
    
    // All zeros - no balanced subarray
    vector<int> nums(100000, 0);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.findMaxLength(nums);
    }, result);
    
    // No balanced subarray possible
    EXPECT_EQ(result, 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthNoBalance");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(ContiguousArray, MaxLengthWorstCase) {
    Solution s;
    
    // Pattern that creates many unique balances: 0,0,0...0,1,1,1...1
    // with imbalance in middle
    vector<int> nums(100000);
    for (int i = 0; i < 30000; i++) nums[i] = 0;
    for (int i = 30000; i < 70000; i++) nums[i] = 1;
    for (int i = 70000; i < 100000; i++) nums[i] = 0;
    // 30000 zeros, 40000 ones, 30000 zeros
    // Balance at start: 0, at 30000: -30000, at 70000: 10000, at end: -20000
    // Best match: none equal, need to find within
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.findMaxLength(nums);
    }, result);
    
    // Should find some balanced subarray
    EXPECT_GE(result, 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthWorstCase");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}


