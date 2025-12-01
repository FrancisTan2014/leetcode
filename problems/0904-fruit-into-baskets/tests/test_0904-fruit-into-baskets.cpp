// tests/test_0904-fruit-into-baskets.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(FruitIntoBaskets, SingleFruit) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1}), 1);
}

TEST(FruitIntoBaskets, TwoFruitsSameType) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1}), 2);
}

TEST(FruitIntoBaskets, TwoFruitsDifferentTypes) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2}), 2);
    EXPECT_EQ(s.totalFruit({0, 1}), 2);
}

// ========== Typical Cases ==========

TEST(FruitIntoBaskets, Example1) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 1}), 3);
}

TEST(FruitIntoBaskets, Example2) {
    Solution s;
    EXPECT_EQ(s.totalFruit({0, 1, 2, 2}), 3); // Pick [1,2,2]
}

TEST(FruitIntoBaskets, Example3) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 3, 2, 2}), 4); // Pick [2,3,2,2]
}

TEST(FruitIntoBaskets, AllSameType) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1, 1, 1, 1}), 5);
    EXPECT_EQ(s.totalFruit({0, 0, 0}), 3);
}

TEST(FruitIntoBaskets, TwoTypesAlternating) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 1, 2, 1, 2}), 6);
    EXPECT_EQ(s.totalFruit({0, 1, 0, 1}), 4);
}

// ========== Boundary Cases ==========

TEST(FruitIntoBaskets, ThreeTypesSimple) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 3}), 2); // Can only pick [1,2] or [2,3]
}

TEST(FruitIntoBaskets, MinLength) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1}), 1);
}

TEST(FruitIntoBaskets, ExactlyTwoTypes) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1, 2, 2}), 4);
    EXPECT_EQ(s.totalFruit({5, 5, 5, 6, 6}), 5);
}

TEST(FruitIntoBaskets, MaxFruitValue) {
    Solution s;
    // fruits[i] can be up to fruits.length - 1
    EXPECT_EQ(s.totalFruit({0, 1, 2, 1}), 3); // [1,2,1]
}

// ========== Window Shrinking Cases ==========

TEST(FruitIntoBaskets, WindowAtStart) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 3, 4, 5}), 2); // Any adjacent pair
}

TEST(FruitIntoBaskets, WindowAtEnd) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 1, 3, 3, 3}), 4); // [3,3,3] wrong, should be [1,3,3,3]
}

TEST(FruitIntoBaskets, WindowInMiddle) {
    Solution s;
    EXPECT_EQ(s.totalFruit({3, 3, 1, 2, 1, 1, 2, 3, 3}), 5); // [1,2,1,1,2]
}

TEST(FruitIntoBaskets, LongPrefixBeforeOptimal) {
    Solution s;
    EXPECT_EQ(s.totalFruit({0, 0, 0, 1, 2, 2, 2}), 4); // [0,0,0,1] or [1,2,2,2] both = 4
}

// ========== Frequency Cases ==========

TEST(FruitIntoBaskets, UnevenFrequencies) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1, 1, 1, 2}), 5);
    EXPECT_EQ(s.totalFruit({1, 2, 2, 2, 2}), 5);
}

TEST(FruitIntoBaskets, MultipleOccurrences) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1, 2, 2, 3, 3}), 4); // [1,1,2,2] or [2,2,3,3]
}

TEST(FruitIntoBaskets, RepeatedPattern) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 1, 2, 3}), 4); // [1,2,1,2]
}

// ========== Edge Patterns ==========

TEST(FruitIntoBaskets, ManyDistinctTypes) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 3, 4, 5, 6, 7, 8}), 2); // Any adjacent pair
}

TEST(FruitIntoBaskets, ZeroValues) {
    Solution s;
    EXPECT_EQ(s.totalFruit({0, 0, 0}), 3);
    EXPECT_EQ(s.totalFruit({0, 1, 0}), 3);
}

TEST(FruitIntoBaskets, IncreasingSequence) {
    Solution s;
    EXPECT_EQ(s.totalFruit({0, 1, 2, 3, 4}), 2);
}

TEST(FruitIntoBaskets, DecreasingSequence) {
    Solution s;
    EXPECT_EQ(s.totalFruit({4, 3, 2, 1, 0}), 2);
}

// ========== Trick Cases ==========

TEST(FruitIntoBaskets, LongSequenceThenNew) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 1, 1, 1, 1, 2, 2, 2, 3}), 8); // [1,1,1,1,1,2,2,2]
}

TEST(FruitIntoBaskets, NewTypeBreaksWindow) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 1, 2, 1, 3}), 5); // [1,2,1,2]
}

TEST(FruitIntoBaskets, OptimalNotAtBoundary) {
    Solution s;
    EXPECT_EQ(s.totalFruit({3, 1, 2, 2, 2, 2, 1, 3}), 6);
}

TEST(FruitIntoBaskets, ThreeTypesInterleaved) {
    Solution s;
    EXPECT_EQ(s.totalFruit({1, 2, 3, 2, 1, 4}), 3); // [3,2,1] or [2,3,2]
}

// ========== Performance Cases ==========

TEST(FruitIntoBaskets, MaxLengthAllSame) {
    Solution s;
    
    vector<int> fruits(100000, 1);
    
    PerformanceMonitor monitor(100.0, 10240); // 100ms, 10MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.totalFruit(fruits);
    }, result);
    
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllSame");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(FruitIntoBaskets, MaxLengthTwoTypes) {
    Solution s;
    
    // Alternating pattern of two types
    vector<int> fruits(100000);
    for (int i = 0; i < 100000; i++) {
        fruits[i] = i % 2;
    }
    
    PerformanceMonitor monitor(100.0, 10240);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.totalFruit(fruits);
    }, result);
    
    EXPECT_EQ(result, 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthTwoTypes");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(FruitIntoBaskets, MaxLengthManyTypes) {
    Solution s;
    
    // Each position has unique type - worst case
    vector<int> fruits(100000);
    for (int i = 0; i < 100000; i++) {
        fruits[i] = i;
    }
    
    PerformanceMonitor monitor(100.0, 10240);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.totalFruit(fruits);
    }, result);
    
    EXPECT_EQ(result, 2); // Can only pick 2 adjacent
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthManyTypes");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}

TEST(FruitIntoBaskets, MaxLengthWorstCase) {
    Solution s;
    
    // Worst case: optimal window at end after scanning many types
    vector<int> fruits;
    fruits.reserve(100000);
    
    // First 50000: each unique type
    for (int i = 0; i < 50000; i++) {
        fruits.push_back(i);
    }
    
    // Last 50000: two types alternating
    for (int i = 0; i < 50000; i++) {
        fruits.push_back(i % 2);
    }
    
    PerformanceMonitor monitor(100.0, 10240);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.totalFruit(fruits);
    }, result);
    
    EXPECT_EQ(result, 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthWorstCase");
    EXPECT_PERFORMANCE(metrics, 100.0, 10240);
}
