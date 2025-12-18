// tests/test_0215-kth-largest-element-in-an-array.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include "../solution.cpp"

using namespace leetcode;

// Example 1: nums = [3,2,1,5,6,4], k = 2 -> 5
TEST(KthLargestElement, Example1) {
  Solution s;
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  EXPECT_EQ(s.findKthLargest(nums, 2), 5);
}

// Example 2: nums = [3,2,3,1,2,4,5,5,6], k = 4 -> 4
TEST(KthLargestElement, Example2) {
  Solution s;
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  EXPECT_EQ(s.findKthLargest(nums, 4), 4);
}

// Single element, k = 1
TEST(KthLargestElement, SingleElement) {
  Solution s;
  std::vector<int> nums = {1};
  EXPECT_EQ(s.findKthLargest(nums, 1), 1);
}

// Two elements, k = 1 (largest)
TEST(KthLargestElement, TwoElementsLargest) {
  Solution s;
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(s.findKthLargest(nums, 1), 2);
}

// Two elements, k = 2 (smallest)
TEST(KthLargestElement, TwoElementsSmallest) {
  Solution s;
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(s.findKthLargest(nums, 2), 1);
}

// All elements are the same
TEST(KthLargestElement, AllSameElements) {
  Solution s;
  std::vector<int> nums = {5, 5, 5, 5, 5};
  EXPECT_EQ(s.findKthLargest(nums, 3), 5);
}

// k = 1 (maximum element)
TEST(KthLargestElement, FirstLargest) {
  Solution s;
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  EXPECT_EQ(s.findKthLargest(nums, 1), 6);
}

// k = n (minimum element)
TEST(KthLargestElement, LastLargest) {
  Solution s;
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  EXPECT_EQ(s.findKthLargest(nums, 6), 1);
}

// Already sorted ascending
TEST(KthLargestElement, SortedAscending) {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(s.findKthLargest(nums, 2), 4);
}

// Already sorted descending
TEST(KthLargestElement, SortedDescending) {
  Solution s;
  std::vector<int> nums = {5, 4, 3, 2, 1};
  EXPECT_EQ(s.findKthLargest(nums, 3), 3);
}

// Negative numbers
TEST(KthLargestElement, NegativeNumbers) {
  Solution s;
  std::vector<int> nums = {-1, -2, -3, -4, -5};
  EXPECT_EQ(s.findKthLargest(nums, 2), -2);
}

// Mix of positive and negative
TEST(KthLargestElement, MixedPositiveNegative) {
  Solution s;
  std::vector<int> nums = {-1, 2, 0, -3, 4};
  EXPECT_EQ(s.findKthLargest(nums, 3), 0);
}

// Duplicates with different k
TEST(KthLargestElement, DuplicatesK3) {
  Solution s;
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  EXPECT_EQ(s.findKthLargest(nums, 3), 5);
}

// Large array
TEST(KthLargestElement, LargeArray) {
  Solution s;
  std::vector<int> nums;
  for (int i = 1; i <= 100; i++) {
    nums.push_back(i);
  }
  EXPECT_EQ(s.findKthLargest(nums, 10), 91);
}

// k in the middle
TEST(KthLargestElement, MiddleK) {
  Solution s;
  std::vector<int> nums = {7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(s.findKthLargest(nums, 4), 4);
}

// Random order with duplicates
TEST(KthLargestElement, RandomOrderDuplicates) {
  Solution s;
  std::vector<int> nums = {4, 5, 8, 2, 8, 3, 1, 5, 9};
  // Sorted descending: [9, 8, 8, 5, 5, 4, 3, 2, 1]
  // k=5 should be 5 (the 5th element)
  EXPECT_EQ(s.findKthLargest(nums, 5), 5);
}

// Boundary values
TEST(KthLargestElement, BoundaryValues) {
  Solution s;
  std::vector<int> nums = {-10000, 0, 10000};
  EXPECT_EQ(s.findKthLargest(nums, 1), 10000);
  EXPECT_EQ(s.findKthLargest(nums, 2), 0);
  EXPECT_EQ(s.findKthLargest(nums, 3), -10000);
}

// k = n/2 (median-like)
TEST(KthLargestElement, MedianPosition) {
  Solution s;
  std::vector<int> nums = {9, 3, 7, 1, 5};
  EXPECT_EQ(s.findKthLargest(nums, 3), 5);
}

// Large k close to n
TEST(KthLargestElement, LargeKCloseToN) {
  Solution s;
  std::vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(s.findKthLargest(nums, 9), 2);
}

// Array with zeros
TEST(KthLargestElement, WithZeros) {
  Solution s;
  std::vector<int> nums = {0, 0, 0, 1, 2};
  EXPECT_EQ(s.findKthLargest(nums, 3), 0);
}
