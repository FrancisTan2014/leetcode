// tests/test_1011-capacity-to-ship-packages-within-d-days.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

// [5], days=1: must ship in 1 day, capacity = 5
TEST(ShipWithinDays, SinglePackageSingleDay) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({5}, 1), 5);
}

// [1, 2], days=1: must ship all in 1 day, capacity = 1+2 = 3
TEST(ShipWithinDays, TwoPackagesSingleDay) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1, 2}, 1), 3);
}

// [1, 2], days=2: can ship 1 per day, capacity = max(1,2) = 2
TEST(ShipWithinDays, TwoPackagesTwoDays) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1, 2}, 2), 2);
}

// [5, 5], days=2: ship 1 per day, capacity = 5
TEST(ShipWithinDays, EqualWeights) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({5, 5}, 2), 5);
}

// ========== Typical Cases ==========

// [1,2,3,4,5,6,7,8,9,10], days=5
// Capacity 15: [1,2,3,4,5]=15, [6,7]=13, [8]=8, [9]=9, [10]=10 → 5 days ✓
// Capacity 14: [1,2,3,4,5]=15 can't fit → doesn't work ✗
TEST(ShipWithinDays, Example1) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,2,3,4,5,6,7,8,9,10}, 5), 15);
}

// [3,2,2,4,1,4], days=3
// Capacity 6: [3,2]=5, [2,4]=6, [1,4]=5 → 3 days ✓
// Capacity 5: [3,2]=5, [2], [4], [1,4]=5 → 4 days ✗
TEST(ShipWithinDays, Example2) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({3,2,2,4,1,4}, 3), 6);
}

// [1,2,3,1,1], days=4
// Capacity 3: [1,2]=3, [3]=3, [1,1]=2 → 3 days (less than 4) ✓
// Capacity 2: [1]=1, [2]=2, [3] can't fit ✗
TEST(ShipWithinDays, Example3) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,2,3,1,1}, 4), 3);
}

// [1,1,1,1,1], days=3
// Capacity 2: [1,1]=2, [1,1]=2, [1]=1 → 3 days ✓
// Capacity 1: [1],[1],[1],[1],[1] → 5 days ✗
TEST(ShipWithinDays, AllOnes) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,1,1,1,1}, 3), 2);
}

// ========== Boundary Cases ==========

// [10], days=1: single package, single day
TEST(ShipWithinDays, MinimumCase) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({10}, 1), 10);
}

// [1,1,1,1,1], days=5: 5 packages, 5 days, 1 per day
TEST(ShipWithinDays, OneDayPerPackage) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,1,1,1,1}, 5), 1);
}

// [500], days=1: maximum weight single package
TEST(ShipWithinDays, MaxWeight) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({500}, 1), 500);
}

// [500,500,500], days=1: must ship all at once
TEST(ShipWithinDays, MaxWeightAllAtOnce) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({500,500,500}, 1), 1500);
}

// [500,500,500], days=3: one per day
TEST(ShipWithinDays, MaxWeightOneDayEach) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({500,500,500}, 3), 500);
}

// ========== Pattern Cases ==========

// [1,2,3,4,5], days=3
// Capacity 6: [1,2,3]=6, [4]=4, [5]=5 → 3 days ✓
// Capacity 5: [1,2], [3], [4], [5] → 4 days ✗
TEST(ShipWithinDays, IncreasingWeights) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,2,3,4,5}, 3), 6);
}

// [5,4,3,2,1], days=3
// Capacity 6: [5]=5, [4]=4, [3,2,1]=6 → 3 days ✓
// Capacity 5: [5]=5, [4]=4, [3,2]=5, [1]=1 → 4 days ✗
TEST(ShipWithinDays, DecreasingWeights) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({5,4,3,2,1}, 3), 6);
}

// [10,1,1,1,1], days=2
// Capacity 11: [10,1]=11, [1,1,1]=3 → 2 days ✓
// Capacity 10: [10]=10, [1,1,1,1]=4 → 2 days ✓
// Capacity 9: Can't ship 10 ✗
TEST(ShipWithinDays, HeavyFirst) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({10,1,1,1,1}, 2), 10);
}

// [1,1,1,1,10], days=2
// Capacity 11: [1,1,1,1]=4, [10]=10 → 2 days ✓
// Capacity 10: [1,1,1,1], [10] → 2 days ✓ but need capacity 10 minimum
TEST(ShipWithinDays, HeavyLast) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,1,1,1,10}, 2), 10);
}

// ========== Edge Cases ==========

// [3,3,3,3,3], days=2
// Capacity 9: [3,3,3]=9, [3,3]=6 → 2 days ✓
// Capacity 8: [3,3]=6, [3,3]=6, [3]=3 → 3 days ✗
TEST(ShipWithinDays, AllSameWeight) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({3,3,3,3,3}, 2), 9);
}

// [10,9,8,7,6,5,4,3,2,1], days=4
// Sum = 55
// Capacity 18: [10]=10, [9,8]=17, [7,6,5]=18, [4,3,2,1]=10 → 4 days ✓
// Capacity 17: [10]=10, [9,8]=17, [7,6]=13, [5,4,3,2]=14, [1]=1 → 5 days ✗
TEST(ShipWithinDays, LongDecreasing) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({10,9,8,7,6,5,4,3,2,1}, 4), 17);
}

// [1,2,1,2,1,2], days=3
// Capacity 3: [1,2]=3, [1,2]=3, [1,2]=3 → 3 days ✓
// Capacity 2: [1],[2],[1],[2],[1],[2] → 6 days ✗
TEST(ShipWithinDays, AlternatingPattern) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,2,1,2,1,2}, 3), 3);
}

// [100,200,100,200], days=2
// Capacity 300: [100,200]=300, [100,200]=300 → 2 days ✓
// Capacity 299: [100,200]=300 exceeds ✗
TEST(ShipWithinDays, LargeAlternating) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({100,200,100,200}, 2), 300);
}

// ========== Trick Cases ==========

// [1,1,1,1,1,1,1,1,1,10], days=5
// Capacity 10: [1,1,1,1,1,1,1,1,1]=9, [10]=10 → 2 days ✓ (but too few)
// Actually with capacity 10: can we split into 5 days?
// [1,1,1,1,1,1,1,1]=8, [1]=1, [10]=10 → 3 days minimum
// Need capacity 3: [1,1,1]=3, [1,1,1]=3, [1,1,1]=3, [1]=1, [10] → need cap 10
TEST(ShipWithinDays, ManySmallOneHeavy) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({1,1,1,1,1,1,1,1,1,10}, 5), 10);
}

// [5,5,5,5,5], days=1: must ship all at once
TEST(ShipWithinDays, AllSameOneDa) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({5,5,5,5,5}, 1), 25);
}

// [1,2,3,4,5,4,3,2,1], days=5
// Sum = 25, symmetric pattern
TEST(ShipWithinDays, SymmetricPattern) {
    Solution s;
    // Cap 6: [1,2,3]=6, [4]=4, [5]=5, [4]=4, [3,2,1]=6 → 5 days ✓
    // Cap 5: [1,2]=3, [3]=3, [4]=4, [5]=5, [4]=4, [3,2]=5, [1]=1 → 7 days ✗
    EXPECT_EQ(s.shipWithinDays({1,2,3,4,5,4,3,2,1}, 5), 6);
}

// [100,100,100], days=2
// Capacity 200: [100,100]=200, [100]=100 → 2 days ✓
// Capacity 199: [100]=100, [100]=100, [100]=100 → 3 days ✗
TEST(ShipWithinDays, ExactDouble) {
    Solution s;
    EXPECT_EQ(s.shipWithinDays({100,100,100}, 2), 200);
}

// ========== Performance Cases ==========

TEST(ShipWithinDays, MaxPackagesMinDays) {
    Solution s;
    
    // 50000 packages, all weight 1
    vector<int> weights(50000, 1);
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.shipWithinDays(weights, 1);
    }, result);
    
    // Must ship all in 1 day
    EXPECT_EQ(result, 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPackagesMinDays");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(ShipWithinDays, MaxPackagesMaxDays) {
    Solution s;
    
    // 50000 packages, all weight 1, 50000 days
    vector<int> weights(50000, 1);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.shipWithinDays(weights, 50000);
    }, result);
    
    // Can ship 1 per day
    EXPECT_EQ(result, 1);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPackagesMaxDays");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(ShipWithinDays, MaxPackagesVariedWeights) {
    Solution s;
    
    // 50000 packages with varying weights
    vector<int> weights(50000);
    for (int i = 0; i < 50000; i++) {
        weights[i] = (i % 500) + 1;  // 1 to 500
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.shipWithinDays(weights, 10000);
    }, result);
    
    EXPECT_GT(result, 0);
    EXPECT_LE(result, 12512500);  // sum of all weights
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPackagesVariedWeights");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(ShipWithinDays, MaxPackagesMaxWeight) {
    Solution s;
    
    // 50000 packages, all max weight
    vector<int> weights(50000, 500);
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.shipWithinDays(weights, 25000);
    }, result);
    
    // With 50000 packages and 25000 days, need capacity for 2 per day
    EXPECT_EQ(result, 1000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxPackagesMaxWeight");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
