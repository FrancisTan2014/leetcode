// tests/test_0062-unique-paths.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Example 1: m = 3, n = 7
TEST(UniquePaths, Example1) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(3, 7), 28);
}

// Example 2: m = 3, n = 2
TEST(UniquePaths, Example2) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(3, 2), 3);
}

// Single row
TEST(UniquePaths, SingleRow) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(1, 10), 1);
}

// Single column
TEST(UniquePaths, SingleColumn) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(10, 1), 1);
}

// Single cell (1x1 grid)
TEST(UniquePaths, SingleCell) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(1, 1), 1);
}

// 2x2 grid
TEST(UniquePaths, TwoByTwo) {
  Solution s;
  // Paths: RD, DR
  EXPECT_EQ(s.uniquePaths(2, 2), 2);
}

// 2x3 grid
TEST(UniquePaths, TwoByThree) {
  Solution s;
  // Paths: RRD, RDR, DRR
  EXPECT_EQ(s.uniquePaths(2, 3), 3);
}

// 3x3 grid
TEST(UniquePaths, ThreeByThree) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(3, 3), 6);
}

// 4x4 grid
TEST(UniquePaths, FourByFour) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(4, 4), 20);
}

// 5x5 grid
TEST(UniquePaths, FiveByFive) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(5, 5), 70);
}

// Asymmetric: m = 7, n = 3 (transpose of Example1)
TEST(UniquePaths, TransposeExample1) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(7, 3), 28);
}

// Larger grid: m = 10, n = 10
TEST(UniquePaths, TenByTen) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(10, 10), 48620);
}

// Wide grid: m = 2, n = 10
TEST(UniquePaths, WideGrid) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(2, 10), 10);
}

// Tall grid: m = 10, n = 2
TEST(UniquePaths, TallGrid) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(10, 2), 10);
}

// Large values: m = 23, n = 12
TEST(UniquePaths, LargeGrid1) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(23, 12), 193536720);
}

// Near max constraint: m = 51, n = 9
TEST(UniquePaths, LargeGrid2) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(51, 9), 1916797311);
}

// Symmetric large grid: m = 15, n = 15
TEST(UniquePaths, FifteenByFifteen) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(15, 15), 40116600);
}

// Edge case: m = 1, n = 100
TEST(UniquePaths, OneByHundred) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(1, 100), 1);
}

// Edge case: m = 100, n = 1
TEST(UniquePaths, HundredByOne) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(100, 1), 1);
}

// m = 5, n = 10
TEST(UniquePaths, FiveByTen) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(5, 10), 715);
}

// m = 10, n = 5 (transpose of above)
TEST(UniquePaths, TenByFive) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(10, 5), 715);
}
