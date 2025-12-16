#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../solution.cpp"

using namespace std;

// Helper function to sort and compare subset collections
bool areSubsetsEqual(vector<vector<int>>& result, vector<vector<int>>& expected) {
  if (result.size() != expected.size()) return false;
  
  // Sort each subset
  for (auto& subset : result) {
    sort(subset.begin(), subset.end());
  }
  for (auto& subset : expected) {
    sort(subset.begin(), subset.end());
  }
  
  // Sort the collections
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  
  return result == expected;
}

class LC78_Subsets : public ::testing::Test {
 protected:
  Solution s;
};

// Official Examples
TEST_F(LC78_Subsets, Example1) {
  vector<int> nums = {1, 2, 3};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 8);  // 2^3 = 8
}

TEST_F(LC78_Subsets, Example2) {
  vector<int> nums = {0};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {0}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 2);  // 2^1 = 2
}

// Edge Cases
TEST_F(LC78_Subsets, SingleElement) {
  vector<int> nums = {5};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {5}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 2);
}

TEST_F(LC78_Subsets, TwoElements) {
  vector<int> nums = {1, 2};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {1}, {2}, {1, 2}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 4);  // 2^2 = 4
}

TEST_F(LC78_Subsets, FourElements) {
  vector<int> nums = {1, 2, 3, 4};
  auto result = s.subsets(nums);
  EXPECT_EQ(result.size(), 16);  // 2^4 = 16
  
  // Verify some specific subsets exist
  vector<vector<int>> expected = {
    {},
    {1}, {2}, {3}, {4},
    {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
    {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4},
    {1, 2, 3, 4}
  };
  EXPECT_TRUE(areSubsetsEqual(result, expected));
}

// Negative Numbers
TEST_F(LC78_Subsets, WithNegativeNumbers) {
  vector<int> nums = {-1, 0, 1};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {-1}, {0}, {1}, {-1, 0}, {-1, 1}, {0, 1}, {-1, 0, 1}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 8);
}

TEST_F(LC78_Subsets, AllNegative) {
  vector<int> nums = {-3, -2, -1};
  auto result = s.subsets(nums);
  EXPECT_EQ(result.size(), 8);  // 2^3 = 8
  
  // Verify empty set and full set exist
  bool hasEmpty = false;
  bool hasFull = false;
  for (auto& subset : result) {
    vector<int> sorted = subset;
    sort(sorted.begin(), sorted.end());
    if (sorted.empty()) hasEmpty = true;
    if (sorted == vector<int>{-3, -2, -1}) hasFull = true;
  }
  EXPECT_TRUE(hasEmpty);
  EXPECT_TRUE(hasFull);
}

// Boundary Cases
TEST_F(LC78_Subsets, MaxLength_10Elements) {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = s.subsets(nums);
  EXPECT_EQ(result.size(), 1024);  // 2^10 = 1024
  
  // Verify empty set exists
  bool hasEmpty = false;
  for (auto& subset : result) {
    if (subset.empty()) {
      hasEmpty = true;
      break;
    }
  }
  EXPECT_TRUE(hasEmpty);
  
  // Verify full set exists
  bool hasFull = false;
  for (auto& subset : result) {
    if (subset.size() == 10) {
      vector<int> sorted = subset;
      sort(sorted.begin(), sorted.end());
      if (sorted == nums) {
        hasFull = true;
        break;
      }
    }
  }
  EXPECT_TRUE(hasFull);
}

TEST_F(LC78_Subsets, WithBoundaryValues) {
  vector<int> nums = {-10, 10};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {-10}, {10}, {-10, 10}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 4);
}

// Verification of Power Set Properties
TEST_F(LC78_Subsets, VerifyEmptySetAlwaysIncluded) {
  vector<int> nums = {7, 8, 9};
  auto result = s.subsets(nums);
  
  bool hasEmpty = false;
  for (auto& subset : result) {
    if (subset.empty()) {
      hasEmpty = true;
      break;
    }
  }
  EXPECT_TRUE(hasEmpty);
}

TEST_F(LC78_Subsets, VerifyFullSetAlwaysIncluded) {
  vector<int> nums = {2, 4, 6};
  auto result = s.subsets(nums);
  
  bool hasFull = false;
  for (auto& subset : result) {
    if (subset.size() == 3) {
      vector<int> sorted = subset;
      sort(sorted.begin(), sorted.end());
      vector<int> expected = {2, 4, 6};
      sort(expected.begin(), expected.end());
      if (sorted == expected) {
        hasFull = true;
        break;
      }
    }
  }
  EXPECT_TRUE(hasFull);
}

TEST_F(LC78_Subsets, VerifyAllSingletonsIncluded) {
  vector<int> nums = {5, 6, 7};
  auto result = s.subsets(nums);
  
  // Count singletons
  int singletonCount = 0;
  for (auto& subset : result) {
    if (subset.size() == 1) {
      singletonCount++;
    }
  }
  EXPECT_EQ(singletonCount, 3);  // Should have exactly 3 singleton subsets
}

// Special Patterns
TEST_F(LC78_Subsets, ConsecutiveNumbers) {
  vector<int> nums = {1, 2, 3, 4, 5};
  auto result = s.subsets(nums);
  EXPECT_EQ(result.size(), 32);  // 2^5 = 32
}

TEST_F(LC78_Subsets, NonConsecutiveNumbers) {
  vector<int> nums = {1, 5, 9};
  auto result = s.subsets(nums);
  vector<vector<int>> expected = {{}, {1}, {5}, {9}, {1, 5}, {1, 9}, {5, 9}, {1, 5, 9}};
  EXPECT_TRUE(areSubsetsEqual(result, expected));
  EXPECT_EQ(result.size(), 8);
}

TEST_F(LC78_Subsets, ZeroAndNegatives) {
  vector<int> nums = {-5, 0, 5};
  auto result = s.subsets(nums);
  EXPECT_EQ(result.size(), 8);  // 2^3 = 8
  
  // Check that {0} exists
  bool hasZeroSubset = false;
  for (auto& subset : result) {
    if (subset.size() == 1 && subset[0] == 0) {
      hasZeroSubset = true;
      break;
    }
  }
  EXPECT_TRUE(hasZeroSubset);
}
