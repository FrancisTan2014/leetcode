// tests/test_0739-daily-temperatures.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [30]: no warmer day → [0]
TEST(DailyTemperatures, SingleElement) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30}), vector<int>({0}));
}

// [30, 40]: 40 > 30 at index 1, distance = 1-0 = 1 → [1, 0]
TEST(DailyTemperatures, TwoElementsIncreasing) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30, 40}), vector<int>({1, 0}));
}

// [40, 30]: no warmer for 40, no warmer for 30 → [0, 0]
TEST(DailyTemperatures, TwoElementsDecreasing) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({40, 30}), vector<int>({0, 0}));
}

// [30, 30]: equal temps, no warmer → [0, 0]
TEST(DailyTemperatures, TwoElementsEqual) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30, 30}), vector<int>({0, 0}));
}

// ========== Typical Cases ==========

// [73,74,75,71,69,72,76,73]
// 73: next warmer is 74 at index 1 → 1-0 = 1
// 74: next warmer is 75 at index 2 → 2-1 = 1
// 75: next warmer is 76 at index 6 → 6-2 = 4
// 71: next warmer is 72 at index 5 → 5-3 = 2
// 69: next warmer is 72 at index 5 → 5-4 = 1
// 72: next warmer is 76 at index 6 → 6-5 = 1
// 76: no warmer → 0
// 73: no warmer → 0
TEST(DailyTemperatures, Example1) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({73,74,75,71,69,72,76,73}), 
              vector<int>({1,1,4,2,1,1,0,0}));
}

// [30,40,50,60]: each has next warmer at +1 → [1,1,1,0]
TEST(DailyTemperatures, Example2) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,40,50,60}), 
              vector<int>({1,1,1,0}));
}

// [30,60,90]: 30→60 at +1, 60→90 at +1, 90 no warmer → [1,1,0]
TEST(DailyTemperatures, Example3) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,60,90}), 
              vector<int>({1,1,0}));
}

// [60,50,40,30]: strictly decreasing, no warmer days → [0,0,0,0]
TEST(DailyTemperatures, StrictlyDecreasing) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({60,50,40,30}), 
              vector<int>({0,0,0,0}));
}

// ========== Boundary Cases ==========

// [30,30,30,30]: all equal, no warmer → [0,0,0,0]
TEST(DailyTemperatures, AllEqual) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,30,30,30}), 
              vector<int>({0,0,0,0}));
}

// [100]: max temp, no warmer → [0]
TEST(DailyTemperatures, MaxTemperature) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({100}), 
              vector<int>({0}));
}

// [30]: min temp → [0]
TEST(DailyTemperatures, MinTemperature) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30}), 
              vector<int>({0}));
}

// [30,31,32,33,34]: strictly increasing by 1 → [1,1,1,1,0]
TEST(DailyTemperatures, StrictlyIncreasing) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,31,32,33,34}), 
              vector<int>({1,1,1,1,0}));
}

// ========== Pattern Cases ==========

// [50,40,60]: 50→60 at +2, 40→60 at +1, 60 no warmer → [2,1,0]
TEST(DailyTemperatures, ValleyPattern) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({50,40,60}), 
              vector<int>({2,1,0}));
}

// [40,50,40]: 40→50 at +1, 50 no warmer, 40 no warmer → [1,0,0]
TEST(DailyTemperatures, PeakPattern) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({40,50,40}), 
              vector<int>({1,0,0}));
}

// [30,40,35,45]: 30→40 at +1, 40→45 at +2, 35→45 at +1, 45 → [1,2,1,0]
TEST(DailyTemperatures, ZigzagPattern) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,40,35,45}), 
              vector<int>({1,2,1,0}));
}

// [50,50,51]: 50→51 at +2, 50→51 at +1, 51 → [2,1,0]
TEST(DailyTemperatures, DuplicateThenWarmer) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({50,50,51}), 
              vector<int>({2,1,0}));
}

// ========== Edge Cases ==========

// [70,60,50,40,50,60,70,80]
// 70→80 at +7, 60→70 at +5, 50→60 at +3, 40→50 at +1,
// 50→60 at +1, 60→70 at +1, 70→80 at +1, 80
TEST(DailyTemperatures, LongValley) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({70,60,50,40,50,60,70,80}), 
              vector<int>({7,5,3,1,1,1,1,0}));
}

// [80,70,60,50,60,70,80,90]
// 80→90 at +7, 70→80 at +5, 60→70 at +3, 50→60 at +1,
// 60→70 at +1, 70→80 at +1, 80→90 at +1, 90
TEST(DailyTemperatures, DeclineThenRise) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({80,70,60,50,60,70,80,90}), 
              vector<int>({7,5,3,1,1,1,1,0}));
}

// [50,60,70,80,70,60,50,40]
// 50→60 at +1, 60→70 at +1, 70→80 at +1, 80 no warmer,
// 70 no warmer, 60 no warmer, 50 no warmer, 40 no warmer
TEST(DailyTemperatures, RiseThenDecline) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({50,60,70,80,70,60,50,40}), 
              vector<int>({1,1,1,0,0,0,0,0}));
}

// [30,100,30,100]: 30→100 at +1, 100 no warmer, 30→100 at +1, 100 → [1,0,1,0]
TEST(DailyTemperatures, ExtremeJumps) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({30,100,30,100}), 
              vector<int>({1,0,1,0}));
}

// ========== Trick Cases ==========

// [75,74,73,72,71,70,69,68,67,66,80]
// All wait for 80: [10,9,8,7,6,5,4,3,2,1,0]
TEST(DailyTemperatures, LongDeclineThenPeak) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({75,74,73,72,71,70,69,68,67,66,80}), 
              vector<int>({10,9,8,7,6,5,4,3,2,1,0}));
}

// [50,51,49,52,48,53]: 
// 50→51 at +1, 51→52 at +2, 49→52 at +1, 52→53 at +2, 48→53 at +1, 53
TEST(DailyTemperatures, SmallIncrements) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({50,51,49,52,48,53}), 
              vector<int>({1,2,1,2,1,0}));
}

// [60,55,56,57,58,59,61]
// 60→61 at +6, 55→56 at +1, 56→57 at +1, 57→58 at +1, 58→59 at +1, 59→61 at +1, 61
TEST(DailyTemperatures, SlowClimb) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({60,55,56,57,58,59,61}), 
              vector<int>({6,1,1,1,1,1,0}));
}

// [73,72,71,73]: 73 no warmer (next 73 is equal), 72→73 at +2, 71→73 at +1, 73 → [0,2,1,0]
// Wait, 73 at index 0 should look for > 73, finds 73 at index 3 but that's equal
// Actually no warmer found
TEST(DailyTemperatures, EqualAtEnd) {
    Solution s;
    EXPECT_EQ(s.dailyTemperatures({73,72,71,73}), 
              vector<int>({0,2,1,0}));
}

// ========== Performance Cases ==========

TEST(DailyTemperatures, MaxLengthIncreasing) {
    Solution s;
    
    // [30, 31, 32, ..., 100, 100, ..., 100] up to 100000 elements
    vector<int> temps(100000);
    for (int i = 0; i < 71; i++) {
        temps[i] = 30 + i;  // 30 to 100
    }
    for (int i = 71; i < 100000; i++) {
        temps[i] = 100;  // Rest are 100
    }
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.dailyTemperatures(temps);
    }, result);
    
    // First 70 elements each have next at +1
    // Element at index 70 (value 100) and rest have no warmer (0)
    EXPECT_EQ(result.size(), 100000);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[70], 0);
    EXPECT_EQ(result[99999], 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthIncreasing");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(DailyTemperatures, MaxLengthDecreasing) {
    Solution s;
    
    // [100, 99, 98, ..., 31, 30] strictly decreasing
    vector<int> temps(100000);
    for (int i = 0; i < 100000; i++) {
        temps[i] = 100 - (i % 71);  // Cycles through 100 down to 30
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.dailyTemperatures(temps);
    }, result);
    
    // Most elements should have some warmer day
    EXPECT_EQ(result.size(), 100000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthDecreasing");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(DailyTemperatures, MaxLengthAllSame) {
    Solution s;
    
    // All 50s - no warmer days
    vector<int> temps(100000, 50);
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.dailyTemperatures(temps);
    }, result);
    
    // All should be 0
    EXPECT_EQ(result.size(), 100000);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[50000], 0);
    EXPECT_EQ(result[99999], 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllSame");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(DailyTemperatures, MaxLengthWorstCase) {
    Solution s;
    
    // Decreasing then one peak: [100, 99, ..., 31, 30, 100]
    vector<int> temps(100000);
    for (int i = 0; i < 99999; i++) {
        temps[i] = 100 - (i % 71);
    }
    temps[99999] = 100;  // Peak at end
    
    PerformanceMonitor monitor(100.0, 1024);
    vector<int> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.dailyTemperatures(temps);
    }, result);
    
    EXPECT_EQ(result.size(), 100000);
    EXPECT_EQ(result[99999], 0);  // Last element has no warmer
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthWorstCase");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
