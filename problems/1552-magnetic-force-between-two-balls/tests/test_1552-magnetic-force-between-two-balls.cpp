// tests/test_1552-magnetic-force-between-two-balls.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

TEST(MaxDistance, TwoPositionsTwoBalls) {
    Solution s;
    vector<int> position = {1, 2};
    EXPECT_EQ(s.maxDistance(position, 2), 1);
}

TEST(MaxDistance, TwoPositionsLargeGap) {
    Solution s;
    vector<int> position = {1, 1000000000};
    EXPECT_EQ(s.maxDistance(position, 2), 999999999);
}

TEST(MaxDistance, ThreePositionsTwoBalls) {
    Solution s;
    vector<int> position = {1, 2, 8};
    EXPECT_EQ(s.maxDistance(position, 2), 7);
}

TEST(MaxDistance, Example1) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 7};
    EXPECT_EQ(s.maxDistance(position, 3), 3);
}

TEST(MaxDistance, Example2) {
    Solution s;
    vector<int> position = {5, 4, 3, 2, 1, 1000000000};
    EXPECT_EQ(s.maxDistance(position, 2), 999999999);
}

TEST(MaxDistance, FourPositionsThreeBalls) {
    Solution s;
    vector<int> position = {1, 2, 4, 8};
    EXPECT_EQ(s.maxDistance(position, 3), 3);
}

TEST(MaxDistance, FivePositionsTwoBalls) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.maxDistance(position, 2), 4);
}

TEST(MaxDistance, FivePositionsFourBalls) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.maxDistance(position, 4), 1);
}

TEST(MaxDistance, FivePositionsFiveBalls) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.maxDistance(position, 5), 1);
}

TEST(MaxDistance, UnevenSpacing) {
    Solution s;
    vector<int> position = {1, 2, 4, 8, 16};
    EXPECT_EQ(s.maxDistance(position, 3), 7);
}

TEST(MaxDistance, ExponentialGrowth) {
    Solution s;
    vector<int> position = {1, 2, 4, 8, 16, 32};
    EXPECT_EQ(s.maxDistance(position, 3), 15);
}

TEST(MaxDistance, UnsortedInput) {
    Solution s;
    vector<int> position = {79, 74, 57, 22};
    EXPECT_EQ(s.maxDistance(position, 2), 57);
}

TEST(MaxDistance, SmallGaps) {
    Solution s;
    vector<int> position = {1, 3, 5, 7, 9, 11};
    EXPECT_EQ(s.maxDistance(position, 3), 4);
}

TEST(MaxDistance, LargeGaps) {
    Solution s;
    vector<int> position = {1, 100, 200, 300, 400};
    EXPECT_EQ(s.maxDistance(position, 3), 199);
}

TEST(MaxDistance, ConsecutivePositions) {
    Solution s;
    vector<int> position = {10, 11, 12, 13, 14, 15};
    EXPECT_EQ(s.maxDistance(position, 3), 2);
}

TEST(MaxDistance, TenPositionsFiveBalls) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.maxDistance(position, 5), 2);
}

TEST(MaxDistance, SparsePositions) {
    Solution s;
    vector<int> position = {1, 10, 20, 100, 200};
    EXPECT_EQ(s.maxDistance(position, 3), 99);
}

TEST(MaxDistance, MixedSpacing) {
    Solution s;
    vector<int> position = {1, 5, 6, 10, 50};
    EXPECT_EQ(s.maxDistance(position, 3), 9);
}

TEST(MaxDistance, ClusteredPositions) {
    Solution s;
    vector<int> position = {1, 2, 3, 100, 101, 102};
    EXPECT_EQ(s.maxDistance(position, 3), 2);
}

TEST(MaxDistance, MaxBalls) {
    Solution s;
    vector<int> position = {1, 5, 10, 15, 20, 25};
    EXPECT_EQ(s.maxDistance(position, 6), 4);
}

TEST(MaxDistance, LargeRange) {
    Solution s;
    vector<int> position = {1, 1000, 2000, 3000, 1000000000};
    EXPECT_EQ(s.maxDistance(position, 3), 2999);
}

TEST(MaxDistance, PowerOfTwo) {
    Solution s;
    vector<int> position = {1, 2, 4, 8, 16, 32, 64, 128};
    EXPECT_EQ(s.maxDistance(position, 4), 31);
}

TEST(MaxDistance, AlmostEqual) {
    Solution s;
    vector<int> position = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.maxDistance(position, 10), 1);
}

TEST(MaxDistance, TwoGroups) {
    Solution s;
    vector<int> position = {1, 2, 3, 100, 101, 102};
    EXPECT_EQ(s.maxDistance(position, 2), 101);
}

TEST(MaxDistance, Performance100K) {
    Solution s;
    
    vector<int> position(100000);
    for (int i = 0; i < 100000; i++) {
        position[i] = i + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxDistance(position, 50000);
    }, result);
    
    EXPECT_EQ(result, 2);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance100K");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(MaxDistance, PerformanceSparse) {
    Solution s;
    
    vector<int> position(100000);
    for (int i = 0; i < 100000; i++) {
        position[i] = (long long)i * 10000 + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxDistance(position, 2);
    }, result);
    
    EXPECT_EQ(result, 999990000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "PerformanceSparse");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(MaxDistance, PerformanceRandom) {
    Solution s;
    
    vector<int> position(100000);
    for (int i = 0; i < 100000; i++) {
        position[i] = (i * 17 + 13) % 1000000000;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.maxDistance(position, 10000);
    }, result);
    
    EXPECT_GT(result, 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "PerformanceRandom");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
