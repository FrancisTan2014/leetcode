// tests/test_0875-koko-eating-bananas.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [10], h=1: must eat all 10 in 1 hour, speed=10
TEST(KokoEatingBananas, SinglePileSingleHour) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({10}, 1), 10);
}

// [10], h=10: can eat 1 per hour, speed=1
TEST(KokoEatingBananas, SinglePileManyHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({10}, 10), 1);
}

// [10], h=5: need ceil(10/k)<=5, k=2 works (5 hours), k=1 needs 10 hours
TEST(KokoEatingBananas, SinglePilePartialHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({10}, 5), 2);
}

// [5, 5], h=2: each pile needs 1 hour at k=5, total 2 hours
TEST(KokoEatingBananas, TwoPilesExactHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({5, 5}, 2), 5);
}

// ========== Typical Cases ==========

// [3,6,7,11], h=8
// k=4: ceil(3/4)+ceil(6/4)+ceil(7/4)+ceil(11/4) = 1+2+2+3 = 8 hours ✓
// k=3: ceil(3/3)+ceil(6/3)+ceil(7/3)+ceil(11/3) = 1+2+3+4 = 10 hours ✗
TEST(KokoEatingBananas, Example1) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({3,6,7,11}, 8), 4);
}

// [30,11,23,4,20], h=5: 5 piles, 5 hours, must finish each in 1 hour
// Need k >= max(piles) = 30
TEST(KokoEatingBananas, Example2) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({30,11,23,4,20}, 5), 30);
}

// [30,11,23,4,20], h=6
// k=23: ceil(30/23)+ceil(11/23)+ceil(23/23)+ceil(4/23)+ceil(20/23) = 2+1+1+1+1 = 6 ✓
// k=22: ceil(30/22)+ceil(11/22)+ceil(23/22)+ceil(4/22)+ceil(20/22) = 2+1+2+1+1 = 7 ✗
TEST(KokoEatingBananas, Example3) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({30,11,23,4,20}, 6), 23);
}

// [1,2,3,4,5], h=15: total 15 bananas, 15 hours, k=1
TEST(KokoEatingBananas, MinSpeedOne) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1,2,3,4,5}, 15), 1);
}

// ========== Boundary Cases ==========

// [1], h=1: minimum pile size, minimum hours
TEST(KokoEatingBananas, MinimumValues) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1}, 1), 1);
}

// [1], h=1000000: very small pile, many hours, k=1
TEST(KokoEatingBananas, VeryManyHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1}, 1000000), 1);
}

// [1000000000], h=1: maximum pile size, must eat all in 1 hour
TEST(KokoEatingBananas, MaximumPileSize) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1000000000}, 1), 1000000000);
}

// [1000000000], h=2: can eat at half speed
// ceil(1000000000/500000000) = 2 hours ✓
TEST(KokoEatingBananas, MaximumPileTwoHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1000000000}, 2), 500000000);
}

// [1,1,1,1,1], h=5: 5 piles of 1, 5 hours, k=1
TEST(KokoEatingBananas, AllOnesExactHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1,1,1,1,1}, 5), 1);
}

// ========== Pattern Cases ==========

// [10,10,10,10], h=8: 4 piles, 8 hours
// k=5: 4*ceil(10/5) = 4*2 = 8 ✓
// k=4: 4*ceil(10/4) = 4*3 = 12 ✗
TEST(KokoEatingBananas, AllSamePiles) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({10,10,10,10}, 8), 5);
}

// [1,2,4,8,16], h=10
// k=5: 1+1+1+2+4 = 9 ✓
// k=4: 1+1+1+2+4 = 9 ✓  
// k=3: 1+1+2+3+6 = 13 ✗
TEST(KokoEatingBananas, PowersOfTwo) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1,2,4,8,16}, 10), 4);
}

// [100,200,300], h=6
// k=150: ceil(100/150)+ceil(200/150)+ceil(300/150) = 1+2+2 = 5 ✓
// k=140: ceil(100/140)+ceil(200/140)+ceil(300/140) = 1+2+3 = 6 ✓
// k=120: ceil(100/120)+ceil(200/120)+ceil(300/120) = 1+2+3 = 6 ✓
// k=100: ceil(100/100)+ceil(200/100)+ceil(300/100) = 1+2+3 = 6 ✓
// k=99: ceil(100/99)+ceil(200/99)+ceil(300/99) = 2+3+4 = 9 ✗
TEST(KokoEatingBananas, IncreasingPiles) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({100,200,300}, 6), 100);
}

// [500,400,300,200,100], h=10
// k=150: 4+3+2+2+1 = 12 ✗
// k=180: 3+3+2+2+1 = 11 ✗
// k=200: 3+2+2+1+1 = 9 ✓
// k=199: 3+3+2+2+1 = 11 ✗
TEST(KokoEatingBananas, DecreasingPiles) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({500,400,300,200,100}, 10), 200);
}

// ========== Edge Cases ==========

// [5,6,7,8], h=20: plenty of time
// k=2: 3+3+4+4 = 14 ✓
// k=1: 5+6+7+8 = 26 ✗
TEST(KokoEatingBananas, PlentyOfTime) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({5,6,7,8}, 20), 2);
}

// [1000,1000,1000,1000], h=4: exactly n hours for n piles
TEST(KokoEatingBananas, ExactlyNHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({1000,1000,1000,1000}, 4), 1000);
}

// [312884470], h=312884469: pile > hours by 1
// Need speed = 2 (takes 156442235 hours)
TEST(KokoEatingBananas, PileLargerThanHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({312884470}, 312884469), 2);
}

// [805306368,805306368,805306368], h=1000000000
// k=3: each pile takes 268435456 hours, total = 805306368 hours ✓
// k=2: each pile takes 402653184 hours, total = 1207959552 hours ✗
TEST(KokoEatingBananas, LargePilesLargeHours) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({805306368,805306368,805306368}, 1000000000), 3);
}

// ========== Trick Cases ==========

// [9,9,9,9,9], h=14
// k=3: 5*ceil(9/3) = 5*3 = 15 ✗
// k=4: 5*ceil(9/4) = 5*3 = 15 ✗
// k=5: 5*ceil(9/5) = 5*2 = 10 ✓
TEST(KokoEatingBananas, CeilBoundary) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({9,9,9,9,9}, 14), 5);
}

// [2,2,2,2,2,2], h=7
// k=2: 6*1 = 6 ✓
// k=1: 6*2 = 12 ✗
TEST(KokoEatingBananas, ExactDivision) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({2,2,2,2,2,2}, 7), 2);
}

// [30,30,30], h=4
// k=30: 3*1 = 3 ✓
// k=29: 3*2 = 6 ✗
TEST(KokoEatingBananas, JustUnderMax) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({30,30,30}, 4), 30);
}

// [11,13,17,19], h=10
// k=8: 2+2+3+3 = 10 ✓
// k=7: 2+2+3+3 = 10 ✓
// k=6: 2+3+3+4 = 12 ✗
TEST(KokoEatingBananas, PrimePiles) {
    Solution s;
    EXPECT_EQ(s.minEatingSpeed({11,13,17,19}, 10), 7);
}

// ========== Performance Cases ==========

TEST(KokoEatingBananas, MaxPilesMaxValue) {
    Solution s;
    
    // 10000 piles, all with max value
    vector<int> piles(10000, 1000000000);
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minEatingSpeed(piles, 10000);
    }, result);
    
    // With 10000 piles and 10000 hours, need max speed
    EXPECT_EQ(result, 1000000000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPilesMaxValue");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(KokoEatingBananas, MaxPilesManyHours) {
    Solution s;
    
    // 10000 piles with varying sizes
    vector<int> piles(10000);
    for (int i = 0; i < 10000; i++) {
        piles[i] = i + 1;  // 1 to 10000
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minEatingSpeed(piles, 1000000000);
    }, result);
    
    // With plenty of hours, speed should be 1
    EXPECT_EQ(result, 1);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPilesManyHours");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(KokoEatingBananas, MaxPilesTightHours) {
    Solution s;
    
    // 10000 piles, all with value 1000
    vector<int> piles(10000, 1000);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minEatingSpeed(piles, 20000);
    }, result);
    
    // 10000 piles * ceil(1000/k) <= 20000
    // ceil(1000/k) <= 2, so k >= 500
    EXPECT_EQ(result, 500);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPilesTightHours");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(KokoEatingBananas, MaxPilesVariedSizes) {
    Solution s;
    
    // 10000 piles with powers of 2 pattern
    vector<int> piles(10000);
    for (int i = 0; i < 10000; i++) {
        piles[i] = 1 << (i % 20);  // Powers of 2 from 2^0 to 2^19
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minEatingSpeed(piles, 50000);
    }, result);
    
    EXPECT_GT(result, 0);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPilesVariedSizes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
