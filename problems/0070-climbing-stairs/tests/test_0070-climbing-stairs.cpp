// tests/test_0070-climbing-stairs.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Example 1: n = 2
TEST(ClimbingStairs, Example1) {
  Solution s;
  EXPECT_EQ(s.climbStairs(2), 2);
}

// Example 2: n = 3
TEST(ClimbingStairs, Example2) {
  Solution s;
  EXPECT_EQ(s.climbStairs(3), 3);
}

// Base case: n = 1
TEST(ClimbingStairs, BaseCase) {
  Solution s;
  EXPECT_EQ(s.climbStairs(1), 1);
}

// Small value: n = 4
TEST(ClimbingStairs, SmallValue) {
  Solution s;
  // ways: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2
  EXPECT_EQ(s.climbStairs(4), 5);
}

// n = 5
TEST(ClimbingStairs, FiveSteps) {
  Solution s;
  // Follows Fibonacci: 1, 2, 3, 5, 8
  EXPECT_EQ(s.climbStairs(5), 8);
}

// n = 6
TEST(ClimbingStairs, SixSteps) {
  Solution s;
  // Follows Fibonacci: 1, 2, 3, 5, 8, 13
  EXPECT_EQ(s.climbStairs(6), 13);
}

// n = 7
TEST(ClimbingStairs, SevenSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(7), 21);
}

// n = 8
TEST(ClimbingStairs, EightSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(8), 34);
}

// n = 10
TEST(ClimbingStairs, TenSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(10), 89);
}

// n = 15
TEST(ClimbingStairs, FifteenSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(15), 987);
}

// n = 20
TEST(ClimbingStairs, TwentySteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(20), 10946);
}

// n = 25
TEST(ClimbingStairs, TwentyFiveSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(25), 121393);
}

// n = 30
TEST(ClimbingStairs, ThirtySteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(30), 1346269);
}

// n = 35
TEST(ClimbingStairs, ThirtyFiveSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(35), 14930352);
}

// n = 40
TEST(ClimbingStairs, FortySteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(40), 165580141);
}

// n = 44 (close to max)
TEST(ClimbingStairs, FortyFourSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(44), 1134903170);
}

// n = 45 (max constraint)
TEST(ClimbingStairs, MaxSteps) {
  Solution s;
  EXPECT_EQ(s.climbStairs(45), 1836311903);
}

// Sequential values to verify pattern
TEST(ClimbingStairs, SequentialPattern) {
  Solution s;
  EXPECT_EQ(s.climbStairs(1), 1);
  EXPECT_EQ(s.climbStairs(2), 2);
  EXPECT_EQ(s.climbStairs(3), 3);
  EXPECT_EQ(s.climbStairs(4), 5);
  EXPECT_EQ(s.climbStairs(5), 8);
  EXPECT_EQ(s.climbStairs(6), 13);
  EXPECT_EQ(s.climbStairs(7), 21);
  EXPECT_EQ(s.climbStairs(8), 34);
  EXPECT_EQ(s.climbStairs(9), 55);
  EXPECT_EQ(s.climbStairs(10), 89);
}

// Verify Fibonacci property: f(n) = f(n-1) + f(n-2)
TEST(ClimbingStairs, FibonacciProperty) {
  Solution s;
  int n1 = s.climbStairs(10);
  int n2 = s.climbStairs(11);
  int n3 = s.climbStairs(12);
  EXPECT_EQ(n3, n1 + n2);
}
