// tests/test_ReverseInteger.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"
#include <climits>

using namespace leetcode;

// ========== Base Cases ==========

TEST(ReverseInteger, Zero) {
    Solution s;
    EXPECT_EQ(s.reverse(0), 0);
}

TEST(ReverseInteger, SingleDigitPositive) {
    Solution s;
    EXPECT_EQ(s.reverse(5), 5);
}

TEST(ReverseInteger, SingleDigitNegative) {
    Solution s;
    EXPECT_EQ(s.reverse(-7), -7);
}

// ========== Typical Cases ==========

TEST(ReverseInteger, PositiveThreeDigits) {
    Solution s;
    EXPECT_EQ(s.reverse(123), 321);
}

TEST(ReverseInteger, NegativeThreeDigits) {
    Solution s;
    EXPECT_EQ(s.reverse(-123), -321);
}

TEST(ReverseInteger, TrailingZeros) {
    Solution s;
    EXPECT_EQ(s.reverse(120), 21);
    EXPECT_EQ(s.reverse(1200), 21);
    EXPECT_EQ(s.reverse(1000), 1);
}

TEST(ReverseInteger, NegativeTrailingZeros) {
    Solution s;
    EXPECT_EQ(s.reverse(-120), -21);
}

// ========== Boundary Cases ==========

TEST(ReverseInteger, MaxInt) {
    Solution s;
    // INT_MAX = 2147483647, reversed would be 7463847412 which overflows
    EXPECT_EQ(s.reverse(INT_MAX), 0);
}

TEST(ReverseInteger, MinInt) {
    Solution s;
    // INT_MIN = -2147483648, reversed would overflow
    EXPECT_EQ(s.reverse(INT_MIN), 0);
}

TEST(ReverseInteger, JustBelowOverflowPositive) {
    Solution s;
    // 1463847412 reversed = 2147483641 (still within INT_MAX)
    EXPECT_EQ(s.reverse(1463847412), 2147483641);
}

TEST(ReverseInteger, JustAboveOverflowPositive) {
    Solution s;
    // 1563847412 reversed = 2147483651 which exceeds INT_MAX (2147483647)
    EXPECT_EQ(s.reverse(1563847412), 0);
}

TEST(ReverseInteger, JustBelowOverflowNegative) {
    Solution s;
    // -1463847412 reversed = -2147483641 (still within INT_MIN)
    EXPECT_EQ(s.reverse(-1463847412), -2147483641);
}

TEST(ReverseInteger, JustAboveOverflowNegative) {
    Solution s;
    // -1563847412 reversed = -2147483651 which exceeds INT_MIN (-2147483648)
    EXPECT_EQ(s.reverse(-1563847412), 0);
}

// ========== Edge Behavior Cases ==========

TEST(ReverseInteger, AllSameDigits) {
    Solution s;
    EXPECT_EQ(s.reverse(1111), 1111);
    EXPECT_EQ(s.reverse(-9999), -9999);
}

TEST(ReverseInteger, LeadingZerosAfterReverse) {
    Solution s;
    EXPECT_EQ(s.reverse(100), 1);
    EXPECT_EQ(s.reverse(10000), 1);
}

// ========== Trick Cases ==========

TEST(ReverseInteger, OverflowTrickCase1) {
    Solution s;
    // 1534236469 reversed = 9646324351 which overflows
    EXPECT_EQ(s.reverse(1534236469), 0);
}

TEST(ReverseInteger, OverflowTrickCase2) {
    Solution s;
    // 2147483647 (INT_MAX) reversed = 7463847412 which overflows
    EXPECT_EQ(s.reverse(2147483647), 0);
}

TEST(ReverseInteger, OverflowTrickCase3) {
    Solution s;
    // -2147483648 (INT_MIN) reversed would overflow
    EXPECT_EQ(s.reverse(-2147483648), 0);
}

TEST(ReverseInteger, OverflowTrickCase4) {
    Solution s;
    // -2147483412 reversed = -2143847412 which does not overflow
    EXPECT_EQ(s.reverse(-2147483412), -2143847412);
}

TEST(ReverseInteger, NineDigitNumber) {
    Solution s;
    EXPECT_EQ(s.reverse(123456789), 987654321);
    EXPECT_EQ(s.reverse(-123456789), -987654321);
}

// ========== Performance Cases ==========

TEST(ReverseInteger, PerformanceStressTest) {
    Solution s;
    PerformanceMonitor monitor(1.0, 1024); // 1ms, 1MB
    
    auto metrics = monitor.measure([&]() {
        // Run reverse operation many times
        for (int i = 0; i < 100000; i++) {
            volatile int result = s.reverse(123456789);
            (void)result; // Prevent optimization
        }
    });
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "StressTest100K");
    EXPECT_TIME_LIMIT(metrics, 100.0); // Should complete in under 100ms
}
