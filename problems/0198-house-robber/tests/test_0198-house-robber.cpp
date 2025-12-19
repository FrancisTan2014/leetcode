// tests/test_0198-house-robber.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Example 1: [1,2,3,1]
TEST(HouseRobber, Example1) {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 1};
  EXPECT_EQ(s.rob(nums), 4);
}

// Example 2: [2,7,9,3,1]
TEST(HouseRobber, Example2) {
  Solution s;
  std::vector<int> nums = {2, 7, 9, 3, 1};
  EXPECT_EQ(s.rob(nums), 12);
}

// Single house
TEST(HouseRobber, SingleHouse) {
  Solution s;
  std::vector<int> nums = {5};
  EXPECT_EQ(s.rob(nums), 5);
}

// Two houses - rob the larger one
TEST(HouseRobber, TwoHouses) {
  Solution s;
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(s.rob(nums), 2);
}

// Two houses - first is larger
TEST(HouseRobber, TwoHousesFirstLarger) {
  Solution s;
  std::vector<int> nums = {5, 1};
  EXPECT_EQ(s.rob(nums), 5);
}

// Three houses - rob first and third
TEST(HouseRobber, ThreeHouses) {
  Solution s;
  std::vector<int> nums = {2, 1, 1};
  EXPECT_EQ(s.rob(nums), 3);
}

// Three houses - rob middle one
TEST(HouseRobber, ThreeHousesMiddle) {
  Solution s;
  std::vector<int> nums = {1, 3, 1};
  EXPECT_EQ(s.rob(nums), 3);
}

// All houses have same value
TEST(HouseRobber, AllSameValue) {
  Solution s;
  std::vector<int> nums = {5, 5, 5, 5, 5};
  // Rob houses at index 0, 2, 4 = 15
  EXPECT_EQ(s.rob(nums), 15);
}

// Houses with zeros
TEST(HouseRobber, WithZeros) {
  Solution s;
  std::vector<int> nums = {0, 0, 0, 0};
  EXPECT_EQ(s.rob(nums), 0);
}

// Mixed with zeros
TEST(HouseRobber, MixedWithZeros) {
  Solution s;
  std::vector<int> nums = {5, 0, 0, 5};
  EXPECT_EQ(s.rob(nums), 10);
}

// Alternating high and low
TEST(HouseRobber, AlternatingHighLow) {
  Solution s;
  std::vector<int> nums = {10, 1, 10, 1, 10};
  EXPECT_EQ(s.rob(nums), 30);
}

// Increasing values
TEST(HouseRobber, IncreasingValues) {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // Rob houses at index 0, 2, 4 or 1, 3 = 1+3+5=9 vs 2+4=6
  EXPECT_EQ(s.rob(nums), 9);
}

// Decreasing values
TEST(HouseRobber, DecreasingValues) {
  Solution s;
  std::vector<int> nums = {5, 4, 3, 2, 1};
  // Rob houses at index 0, 2, 4 = 5+3+1=9
  EXPECT_EQ(s.rob(nums), 9);
}

// Large first house
TEST(HouseRobber, LargeFirstHouse) {
  Solution s;
  std::vector<int> nums = {100, 1, 1, 100};
  EXPECT_EQ(s.rob(nums), 200);
}

// Large middle house
TEST(HouseRobber, LargeMiddleHouse) {
  Solution s;
  std::vector<int> nums = {1, 100, 1};
  EXPECT_EQ(s.rob(nums), 100);
}

// Should skip to maximize
TEST(HouseRobber, SkipToMaximize) {
  Solution s;
  std::vector<int> nums = {2, 1, 1, 2};
  // Rob houses 0 and 3 = 4
  EXPECT_EQ(s.rob(nums), 4);
}

// Complex case 1
TEST(HouseRobber, ComplexCase1) {
  Solution s;
  std::vector<int> nums = {5, 3, 4, 11, 2};
  // Rob houses 0, 3 = 5+11=16 or 1, 3 = 3+11=14 or 0, 2, 4 = 5+4+2=11
  EXPECT_EQ(s.rob(nums), 16);
}

// Complex case 2
TEST(HouseRobber, ComplexCase2) {
  Solution s;
  std::vector<int> nums = {6, 7, 1, 3, 8, 2, 4};
  // Optimal: rob houses 0, 2, 4, 6 = 6+1+8+4=19 or 1, 3, 5 = 7+3+2=12 or 1, 4, 6 = 7+8+4=19
  EXPECT_EQ(s.rob(nums), 19);
}

// Max values
TEST(HouseRobber, MaxValues) {
  Solution s;
  std::vector<int> nums = {400, 400, 400, 400};
  // Rob houses 0, 2 = 800
  EXPECT_EQ(s.rob(nums), 800);
}

// Long sequence
TEST(HouseRobber, LongSequence) {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 1, 1, 2, 3, 1, 1, 2};
  EXPECT_EQ(s.rob(nums), 10);
}

// Longer increasing then decreasing
TEST(HouseRobber, IncreasingThenDecreasing) {
  Solution s;
  std::vector<int> nums = {1, 3, 5, 7, 9, 7, 5, 3, 1};
  // Optimal: rob indices 0, 2, 4, 6, 8 = 1+5+9+5+1=21
  EXPECT_EQ(s.rob(nums), 21);
}

// Two large values far apart
TEST(HouseRobber, TwoLargeValuesFarApart) {
  Solution s;
  std::vector<int> nums = {100, 1, 1, 1, 1, 1, 100};
  // Rob indices 0, 2, 4, 6 = 100+1+1+100=202
  EXPECT_EQ(s.rob(nums), 202);
}

// Two large values close together
TEST(HouseRobber, TwoLargeValuesCloseTogether) {
  Solution s;
  std::vector<int> nums = {1, 100, 100, 1};
  // Rob indices 0 and 2 = 1+100=101
  EXPECT_EQ(s.rob(nums), 101);
}
