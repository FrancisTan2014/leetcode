// tests/test_1004-max-consecutive-ones-iii.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(MaxConsecutiveOnesIII, SingleOne) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1}, 0), 1);
    EXPECT_EQ(s.longestOnes({1}, 1), 1);
}

TEST(MaxConsecutiveOnesIII, SingleZero) {
    Solution s;
    EXPECT_EQ(s.longestOnes({0}, 0), 0);
    EXPECT_EQ(s.longestOnes({0}, 1), 1); // Can flip the zero
}

TEST(MaxConsecutiveOnesIII, TwoElements) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1, 1}, 0), 2);
    EXPECT_EQ(s.longestOnes({1, 0}, 1), 2); // Flip the zero
    EXPECT_EQ(s.longestOnes({0, 0}, 1), 1); // Can only flip one
}

// ========== Typical Cases ==========

TEST(MaxConsecutiveOnesIII, Example1) {
    Solution s;
    // [1,1,1,0,0,0,1,1,1,1,0], k=2
    // Flip 2 zeros: [1,1,1,0,0,1,1,1,1,1,1] -> window of 6
    EXPECT_EQ(s.longestOnes({1,1,1,0,0,0,1,1,1,1,0}, 2), 6);
}

TEST(MaxConsecutiveOnesIII, Example2) {
    Solution s;
    // [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k=3
    // Best window: indices 2-11 with 3 zeros flipped = 10
    EXPECT_EQ(s.longestOnes({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3), 10);
}

TEST(MaxConsecutiveOnesIII, AllOnes) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1,1,1,1,1}, 0), 5);
    EXPECT_EQ(s.longestOnes({1,1,1,1,1}, 2), 5);
}

TEST(MaxConsecutiveOnesIII, AllZeros) {
    Solution s;
    EXPECT_EQ(s.longestOnes({0,0,0,0,0}, 0), 0);
    EXPECT_EQ(s.longestOnes({0,0,0,0,0}, 2), 2);
    EXPECT_EQ(s.longestOnes({0,0,0,0,0}, 5), 5); // Flip all
}

// ========== Boundary Cases ==========

TEST(MaxConsecutiveOnesIII, KZero) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1,0,1,1,0,1}, 0), 2); // Max consecutive 1s without flips
    EXPECT_EQ(s.longestOnes({0,1,0,1,0}, 0), 1);
}

TEST(MaxConsecutiveOnesIII, KEqualsLength) {
    Solution s;
    // Can flip all zeros
    EXPECT_EQ(s.longestOnes({0,0,1,0,1}, 5), 5);
    EXPECT_EQ(s.longestOnes({1,0,0,0,1}, 5), 5);
}

TEST(MaxConsecutiveOnesIII, KGreaterThanZeros) {
    Solution s;
    // [1,0,1,0,1] has 2 zeros, k=5 means we can flip both
    EXPECT_EQ(s.longestOnes({1,0,1,0,1}, 5), 5);
}

TEST(MaxConsecutiveOnesIII, MinLength) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1}, 0), 1);
    EXPECT_EQ(s.longestOnes({0}, 0), 0);
}

// ========== Window Cases ==========

TEST(MaxConsecutiveOnesIII, WindowAtStart) {
    Solution s;
    // [1,1,1,0,0,1] k=1: best is [1,1,1,0] = 4
    EXPECT_EQ(s.longestOnes({1,1,1,0,0,1}, 1), 4);
}

TEST(MaxConsecutiveOnesIII, WindowAtEnd) {
    Solution s;
    // [0,0,1,1,1,1] k=1: best is [0,1,1,1,1] or [1,1,1,1] = 5
    EXPECT_EQ(s.longestOnes({0,0,1,1,1,1}, 1), 5);
}

TEST(MaxConsecutiveOnesIII, WindowInMiddle) {
    Solution s;
    // [0,1,1,0,1,1,0] k=1: best is [1,1,0,1,1] = 5
    EXPECT_EQ(s.longestOnes({0,1,1,0,1,1,0}, 1), 5);
}

TEST(MaxConsecutiveOnesIII, EntireArray) {
    Solution s;
    // [1,0,1,0,1] k=2: can flip both zeros -> entire array
    EXPECT_EQ(s.longestOnes({1,0,1,0,1}, 2), 5);
}

// ========== Pattern Cases ==========

TEST(MaxConsecutiveOnesIII, AlternatingPattern) {
    Solution s;
    // [1,0,1,0,1,0,1] k=2: flip 2 zeros -> [1,1,1,1,1,0,1] = 5
    EXPECT_EQ(s.longestOnes({1,0,1,0,1,0,1}, 2), 5);
}

TEST(MaxConsecutiveOnesIII, ConsecutiveZeros) {
    Solution s;
    // [1,1,0,0,0,1,1] k=2: [1,1,0,0,1,1] = 6 or [1,0,0,1,1] = 5? 
    // Actually [1,1,0,0,0] with k=2 flips 2 zeros = 5, then add [1,1] but that adds a 3rd zero
    // Best: [1,1,0,0] = 4 with 2 flips, or [0,0,1,1] = 4
    EXPECT_EQ(s.longestOnes({1,1,0,0,0,1,1}, 2), 4);
}

TEST(MaxConsecutiveOnesIII, ScatteredZeros) {
    Solution s;
    // [1,1,0,1,0,1,1,0,1] k=2: [1,1,0,1,0,1,1] = 7 with 2 zeros flipped
    EXPECT_EQ(s.longestOnes({1,1,0,1,0,1,1,0,1}, 2), 7);
}

// ========== Edge Patterns ==========

TEST(MaxConsecutiveOnesIII, LeadingZeros) {
    Solution s;
    // [0,0,0,1,1,1] k=2: [0,0,1,1,1] = 5
    EXPECT_EQ(s.longestOnes({0,0,0,1,1,1}, 2), 5);
}

TEST(MaxConsecutiveOnesIII, TrailingZeros) {
    Solution s;
    // [1,1,1,0,0,0] k=2: [1,1,1,0,0] = 5
    EXPECT_EQ(s.longestOnes({1,1,1,0,0,0}, 2), 5);
}

TEST(MaxConsecutiveOnesIII, SingleZeroInMiddle) {
    Solution s;
    // [1,1,1,0,1,1,1] k=1: flip the 0 -> entire array = 7
    EXPECT_EQ(s.longestOnes({1,1,1,0,1,1,1}, 1), 7);
}

TEST(MaxConsecutiveOnesIII, MultipleValidWindows) {
    Solution s;
    // [1,1,0,0,1,1,0,0,1,1] k=2: multiple windows of length 6
    EXPECT_EQ(s.longestOnes({1,1,0,0,1,1,0,0,1,1}, 2), 6);
}

// ========== Trick Cases ==========

TEST(MaxConsecutiveOnesIII, NoFlipsNeeded) {
    Solution s;
    EXPECT_EQ(s.longestOnes({1,1,1,1}, 5), 4);
}

TEST(MaxConsecutiveOnesIII, FlipOnlyOneZero) {
    Solution s;
    // [1,1,1,1,0] k=1: flip the zero -> 5
    EXPECT_EQ(s.longestOnes({1,1,1,1,0}, 1), 5);
}

TEST(MaxConsecutiveOnesIII, ManyZerosSmallK) {
    Solution s;
    // [0,0,0,0,0,1,1,0,0,0] k=1: best is [0,1,1] or [1,1,0] = 3
    EXPECT_EQ(s.longestOnes({0,0,0,0,0,1,1,0,0,0}, 1), 3);
}

TEST(MaxConsecutiveOnesIII, LongRunOfOnes) {
    Solution s;
    // [1,1,1,1,1,1,1,0,1] k=1: flip the zero -> 9
    EXPECT_EQ(s.longestOnes({1,1,1,1,1,1,1,0,1}, 1), 9);
}

// ========== Performance Cases ==========

TEST(MaxConsecutiveOnesIII, MaxLengthAllOnes) {
    Solution s;
    
    vector<int> nums(100000, 1);
    
    PerformanceMonitor monitor(50.0, 1024); // 50ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.longestOnes(nums, 0);
    }, result);
    
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllOnes");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(MaxConsecutiveOnesIII, MaxLengthAlternating) {
    Solution s;
    
    // Alternating 1,0,1,0,... - worst case for window shrinking
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = i % 2;
    }
    
    PerformanceMonitor monitor(50.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.longestOnes(nums, 1000);
    }, result);
    
    // Can flip 1000 zeros, get window of ~2000
    EXPECT_GE(result, 2000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAlternating");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(MaxConsecutiveOnesIII, MaxLengthManyZeros) {
    Solution s;
    
    // First 50000 zeros, last 50000 ones
    vector<int> nums(100000);
    for (int i = 0; i < 50000; i++) {
        nums[i] = 0;
    }
    for (int i = 50000; i < 100000; i++) {
        nums[i] = 1;
    }
    
    PerformanceMonitor monitor(50.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.longestOnes(nums, 100);
    }, result);
    
    // Can flip 100 zeros + 50000 ones = 50100
    EXPECT_EQ(result, 50100);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthManyZeros");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(MaxConsecutiveOnesIII, MaxLengthScattered) {
    Solution s;
    
    // Pattern: 9 ones, 1 zero repeated
    vector<int> nums;
    nums.reserve(100000);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 9; j++) {
            nums.push_back(1);
        }
        nums.push_back(0);
    }
    
    PerformanceMonitor monitor(50.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.longestOnes(nums, 500);
    }, result);
    
    // 500 zeros flipped spans ~5000 chars
    EXPECT_GE(result, 5000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthScattered");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}
