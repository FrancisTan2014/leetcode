// tests/test_0239-sliding-window-maximum.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [1], k=1: window size 1, max is 1 → [1]
TEST(SlidingWindowMaximum, SingleElement) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1}, 1), vector<int>({1}));
}

// [1, 2], k=1: two windows of size 1 → [1, 2]
TEST(SlidingWindowMaximum, TwoElementsWindowOne) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1, 2}, 1), vector<int>({1, 2}));
}

// [1, 2], k=2: one window [1,2], max is 2 → [2]
TEST(SlidingWindowMaximum, TwoElementsWindowTwo) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1, 2}, 2), vector<int>({2}));
}

// [2, 1], k=2: one window [2,1], max is 2 → [2]
TEST(SlidingWindowMaximum, TwoElementsDecreasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({2, 1}, 2), vector<int>({2}));
}

// ========== Typical Cases ==========

// [1,3,-1,-3,5,3,6,7], k=3
// Window [1,3,-1] → max=3
// Window [3,-1,-3] → max=3
// Window [-1,-3,5] → max=5
// Window [-3,5,3] → max=5
// Window [5,3,6] → max=6
// Window [3,6,7] → max=7
TEST(SlidingWindowMaximum, Example1) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3), 
              vector<int>({3,3,5,5,6,7}));
}

// [1,2,3,4,5], k=3
// [1,2,3]→3, [2,3,4]→4, [3,4,5]→5
TEST(SlidingWindowMaximum, Increasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,2,3,4,5}, 3), 
              vector<int>({3,4,5}));
}

// [5,4,3,2,1], k=3
// [5,4,3]→5, [4,3,2]→4, [3,2,1]→3
TEST(SlidingWindowMaximum, Decreasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({5,4,3,2,1}, 3), 
              vector<int>({5,4,3}));
}

// [1,3,1,2,0,5], k=3
// [1,3,1]→3, [3,1,2]→3, [1,2,0]→2, [2,0,5]→5
TEST(SlidingWindowMaximum, MixedPattern) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,3,1,2,0,5}, 3), 
              vector<int>({3,3,2,5}));
}

// ========== Boundary Cases ==========

// [1,1,1,1], k=2: all equal
// [1,1]→1, [1,1]→1, [1,1]→1
TEST(SlidingWindowMaximum, AllEqual) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,1,1,1}, 2), 
              vector<int>({1,1,1}));
}

// [1,2,3,4,5], k=5: window size equals array size
TEST(SlidingWindowMaximum, WindowSizeEqualsLength) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,2,3,4,5}, 5), 
              vector<int>({5}));
}

// [5,4,3,2,1], k=1: window size 1
TEST(SlidingWindowMaximum, WindowSizeOne) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({5,4,3,2,1}, 1), 
              vector<int>({5,4,3,2,1}));
}

// [-1,-2,-3,-4], k=2: all negative
// [-1,-2]→-1, [-2,-3]→-2, [-3,-4]→-3
TEST(SlidingWindowMaximum, AllNegative) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({-1,-2,-3,-4}, 2), 
              vector<int>({-1,-2,-3}));
}

// ========== Pattern Cases ==========

// [1,5,3,5,1], k=3
// [1,5,3]→5, [5,3,5]→5, [3,5,1]→5
TEST(SlidingWindowMaximum, PeakInMiddle) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,5,3,5,1}, 3), 
              vector<int>({5,5,5}));
}

// [3,1,5,1,3], k=3
// [3,1,5]→5, [1,5,1]→5, [5,1,3]→5
TEST(SlidingWindowMaximum, ValleyPattern) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({3,1,5,1,3}, 3), 
              vector<int>({5,5,5}));
}

// [1,3,2,4,3,5], k=3
// [1,3,2]→3, [3,2,4]→4, [2,4,3]→4, [4,3,5]→5
TEST(SlidingWindowMaximum, AlternatingPeaks) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,3,2,4,3,5}, 3), 
              vector<int>({3,4,4,5}));
}

// [5,3,4,2,3,1], k=3
// [5,3,4]→5, [3,4,2]→4, [4,2,3]→4, [2,3,1]→3
TEST(SlidingWindowMaximum, DescendingPeaks) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({5,3,4,2,3,1}, 3), 
              vector<int>({5,4,4,3}));
}

// ========== Edge Cases ==========

// [10000, -10000, 10000], k=2
// [10000,-10000]→10000, [-10000,10000]→10000
TEST(SlidingWindowMaximum, ExtremeValues) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({10000, -10000, 10000}, 2), 
              vector<int>({10000, 10000}));
}

// [0,0,0,0], k=3
// [0,0,0]→0, [0,0,0]→0
TEST(SlidingWindowMaximum, AllZeros) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({0,0,0,0}, 3), 
              vector<int>({0,0}));
}

// [1,-1,1,-1,1], k=2
// [1,-1]→1, [-1,1]→1, [1,-1]→1, [-1,1]→1
TEST(SlidingWindowMaximum, Alternating) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,-1,1,-1,1}, 2), 
              vector<int>({1,1,1,1}));
}

// [9,8,7,6,5,4,3,2,1], k=4
// [9,8,7,6]→9, [8,7,6,5]→8, [7,6,5,4]→7, [6,5,4,3]→6, [5,4,3,2]→5, [4,3,2,1]→4
TEST(SlidingWindowMaximum, LongDecreasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({9,8,7,6,5,4,3,2,1}, 4), 
              vector<int>({9,8,7,6,5,4}));
}

// ========== Trick Cases ==========

// [1,3,2,3,4], k=2
// [1,3]→3, [3,2]→3, [2,3]→3, [3,4]→4
TEST(SlidingWindowMaximum, RepeatedMax) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,3,2,3,4}, 2), 
              vector<int>({3,3,3,4}));
}

// [7,2,4,6,1,3,5], k=3
// [7,2,4]→7, [2,4,6]→6, [4,6,1]→6, [6,1,3]→6, [1,3,5]→5
TEST(SlidingWindowMaximum, MaxAtStart) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({7,2,4,6,1,3,5}, 3), 
              vector<int>({7,6,6,6,5}));
}

// [1,2,3,4,5,6,7], k=3
// [1,2,3]→3, [2,3,4]→4, [3,4,5]→5, [4,5,6]→6, [5,6,7]→7
TEST(SlidingWindowMaximum, StrictlyIncreasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({1,2,3,4,5,6,7}, 3), 
              vector<int>({3,4,5,6,7}));
}

// [10,9,8,7,6,5,4], k=3
// [10,9,8]→10, [9,8,7]→9, [8,7,6]→8, [7,6,5]→7, [6,5,4]→6
TEST(SlidingWindowMaximum, StrictlyDecreasing) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({10,9,8,7,6,5,4}, 3), 
              vector<int>({10,9,8,7,6}));
}

// [5,5,5,5,5], k=3
// [5,5,5]→5, [5,5,5]→5, [5,5,5]→5
TEST(SlidingWindowMaximum, AllSameValue) {
    Solution s;
    EXPECT_EQ(s.maxSlidingWindow({5,5,5,5,5}, 3), 
              vector<int>({5,5,5}));
}

// ========== Performance Cases ==========

TEST(SlidingWindowMaximum, MaxLengthIncreasing) {
    Solution s;
    
    // [1, 2, 3, ..., 100000], k=1000
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = i + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSlidingWindow(nums, 1000);
    }, result);
    
    // Each window max is the last element
    EXPECT_EQ(result.size(), 99001);
    EXPECT_EQ(result[0], 1000);
    EXPECT_EQ(result[98999], 99999);
    EXPECT_EQ(result[99000], 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthIncreasing");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SlidingWindowMaximum, MaxLengthDecreasing) {
    Solution s;
    
    // [100000, 99999, ..., 1], k=1000
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = 100000 - i;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSlidingWindow(nums, 1000);
    }, result);
    
    // Each window max is the first element
    EXPECT_EQ(result.size(), 99001);
    EXPECT_EQ(result[0], 100000);
    EXPECT_EQ(result[50000], 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthDecreasing");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SlidingWindowMaximum, MaxLengthAllSame) {
    Solution s;
    
    // All 5000s
    vector<int> nums(100000, 5000);
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSlidingWindow(nums, 1000);
    }, result);
    
    // All windows have max 5000
    EXPECT_EQ(result.size(), 99001);
    EXPECT_EQ(result[0], 5000);
    EXPECT_EQ(result[50000], 5000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllSame");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SlidingWindowMaximum, MaxLengthAlternating) {
    Solution s;
    
    // Alternating [1, 10000, 1, 10000, ...]
    vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) {
        nums[i] = (i % 2 == 0) ? 1 : 10000;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxSlidingWindow(nums, 1000);
    }, result);
    
    // Each window should have at least one 10000
    EXPECT_EQ(result.size(), 99001);
    EXPECT_EQ(result[0], 10000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAlternating");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
