// tests/test_0069-sqrtx.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

TEST(MySqrt, Zero) {
    Solution s;
    EXPECT_EQ(s.mySqrt(0), 0);
}

TEST(MySqrt, One) {
    Solution s;
    EXPECT_EQ(s.mySqrt(1), 1);
}

TEST(MySqrt, Two) {
    Solution s;
    EXPECT_EQ(s.mySqrt(2), 1);
}

TEST(MySqrt, Three) {
    Solution s;
    EXPECT_EQ(s.mySqrt(3), 1);
}

TEST(MySqrt, PerfectSquare4) {
    Solution s;
    EXPECT_EQ(s.mySqrt(4), 2);
}

TEST(MySqrt, Example2) {
    Solution s;
    EXPECT_EQ(s.mySqrt(8), 2);
}

TEST(MySqrt, PerfectSquare9) {
    Solution s;
    EXPECT_EQ(s.mySqrt(9), 3);
}

TEST(MySqrt, NonPerfectSquare10) {
    Solution s;
    EXPECT_EQ(s.mySqrt(10), 3);
}

TEST(MySqrt, PerfectSquare16) {
    Solution s;
    EXPECT_EQ(s.mySqrt(16), 4);
}

TEST(MySqrt, NonPerfectSquare15) {
    Solution s;
    EXPECT_EQ(s.mySqrt(15), 3);
}

TEST(MySqrt, NonPerfectSquare17) {
    Solution s;
    EXPECT_EQ(s.mySqrt(17), 4);
}

TEST(MySqrt, PerfectSquare25) {
    Solution s;
    EXPECT_EQ(s.mySqrt(25), 5);
}

TEST(MySqrt, NonPerfectSquare24) {
    Solution s;
    EXPECT_EQ(s.mySqrt(24), 4);
}

TEST(MySqrt, NonPerfectSquare26) {
    Solution s;
    EXPECT_EQ(s.mySqrt(26), 5);
}

TEST(MySqrt, PerfectSquare100) {
    Solution s;
    EXPECT_EQ(s.mySqrt(100), 10);
}

TEST(MySqrt, NonPerfectSquare99) {
    Solution s;
    EXPECT_EQ(s.mySqrt(99), 9);
}

TEST(MySqrt, NonPerfectSquare101) {
    Solution s;
    EXPECT_EQ(s.mySqrt(101), 10);
}

TEST(MySqrt, PerfectSquare144) {
    Solution s;
    EXPECT_EQ(s.mySqrt(144), 12);
}

TEST(MySqrt, LargePerfectSquare) {
    Solution s;
    EXPECT_EQ(s.mySqrt(10000), 100);
}

TEST(MySqrt, LargeNonPerfectSquare) {
    Solution s;
    EXPECT_EQ(s.mySqrt(9999), 99);
}

TEST(MySqrt, LargeValue) {
    Solution s;
    EXPECT_EQ(s.mySqrt(123456), 351);
}

TEST(MySqrt, VeryLargePerfectSquare) {
    Solution s;
    EXPECT_EQ(s.mySqrt(1000000), 1000);
}

TEST(MySqrt, VeryLargeNonPerfectSquare) {
    Solution s;
    EXPECT_EQ(s.mySqrt(999999), 999);
}

TEST(MySqrt, NearMaxInt) {
    Solution s;
    EXPECT_EQ(s.mySqrt(2147395599), 46339);
}

TEST(MySqrt, MaxInt) {
    Solution s;
    EXPECT_EQ(s.mySqrt(2147483647), 46340);
}

TEST(MySqrt, MaxIntMinus1) {
    Solution s;
    EXPECT_EQ(s.mySqrt(2147483646), 46340);
}

TEST(MySqrt, PerfectSquareNearMax) {
    Solution s;
    EXPECT_EQ(s.mySqrt(2147395600), 46340);
}

TEST(MySqrt, LargePrime) {
    Solution s;
    EXPECT_EQ(s.mySqrt(1000000007), 31622);
}

TEST(MySqrt, Performance) {
    Solution s;
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.mySqrt(2147483647);
    }, result);
    
    EXPECT_EQ(result, 46340);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
