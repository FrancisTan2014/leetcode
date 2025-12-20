#include <gtest/gtest.h>
#include "../solution.cpp"

class InsertIntervalTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Example 1: Insert in the middle with merge
TEST_F(InsertIntervalTest, Example1) {
  vector<vector<int>> intervals = {{1,3},{6,9}};
  vector<int> newInterval = {2,5};
  vector<vector<int>> expected = {{1,5},{6,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Example 2: Multiple overlaps
TEST_F(InsertIntervalTest, Example2) {
  vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> newInterval = {4,8};
  vector<vector<int>> expected = {{1,2},{3,10},{12,16}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Empty intervals
TEST_F(InsertIntervalTest, EmptyIntervals) {
  vector<vector<int>> intervals = {};
  vector<int> newInterval = {5,7};
  vector<vector<int>> expected = {{5,7}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Insert at beginning with no overlap
TEST_F(InsertIntervalTest, InsertAtBeginningNoOverlap) {
  vector<vector<int>> intervals = {{3,5},{6,9}};
  vector<int> newInterval = {1,2};
  vector<vector<int>> expected = {{1,2},{3,5},{6,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Insert at end with no overlap
TEST_F(InsertIntervalTest, InsertAtEndNoOverlap) {
  vector<vector<int>> intervals = {{1,2},{3,5}};
  vector<int> newInterval = {6,8};
  vector<vector<int>> expected = {{1,2},{3,5},{6,8}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Insert at beginning with overlap
TEST_F(InsertIntervalTest, InsertAtBeginningWithOverlap) {
  vector<vector<int>> intervals = {{2,5},{6,8}};
  vector<int> newInterval = {1,3};
  vector<vector<int>> expected = {{1,5},{6,8}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Insert at end with overlap
TEST_F(InsertIntervalTest, InsertAtEndWithOverlap) {
  vector<vector<int>> intervals = {{1,3},{6,8}};
  vector<int> newInterval = {7,10};
  vector<vector<int>> expected = {{1,3},{6,10}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Insert in middle with no overlap
TEST_F(InsertIntervalTest, InsertInMiddleNoOverlap) {
  vector<vector<int>> intervals = {{1,2},{5,6}};
  vector<int> newInterval = {3,4};
  vector<vector<int>> expected = {{1,2},{3,4},{5,6}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// New interval covers all existing intervals
TEST_F(InsertIntervalTest, NewIntervalCoversAll) {
  vector<vector<int>> intervals = {{2,3},{4,5},{6,7}};
  vector<int> newInterval = {1,8};
  vector<vector<int>> expected = {{1,8}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// New interval inside existing interval
TEST_F(InsertIntervalTest, NewIntervalInside) {
  vector<vector<int>> intervals = {{1,5}};
  vector<int> newInterval = {2,3};
  vector<vector<int>> expected = {{1,5}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Touching intervals - left
TEST_F(InsertIntervalTest, TouchingLeft) {
  vector<vector<int>> intervals = {{3,5},{6,9}};
  vector<int> newInterval = {1,3};
  vector<vector<int>> expected = {{1,5},{6,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Touching intervals - right
TEST_F(InsertIntervalTest, TouchingRight) {
  vector<vector<int>> intervals = {{1,2},{5,9}};
  vector<int> newInterval = {2,5};
  vector<vector<int>> expected = {{1,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Single existing interval, merge
TEST_F(InsertIntervalTest, SingleIntervalMerge) {
  vector<vector<int>> intervals = {{1,5}};
  vector<int> newInterval = {3,7};
  vector<vector<int>> expected = {{1,7}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Single existing interval, before
TEST_F(InsertIntervalTest, SingleIntervalBefore) {
  vector<vector<int>> intervals = {{5,7}};
  vector<int> newInterval = {1,2};
  vector<vector<int>> expected = {{1,2},{5,7}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Single existing interval, after
TEST_F(InsertIntervalTest, SingleIntervalAfter) {
  vector<vector<int>> intervals = {{1,2}};
  vector<int> newInterval = {5,7};
  vector<vector<int>> expected = {{1,2},{5,7}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Merge with first and second
TEST_F(InsertIntervalTest, MergeFirstTwo) {
  vector<vector<int>> intervals = {{1,2},{3,4},{6,8}};
  vector<int> newInterval = {0,5};
  vector<vector<int>> expected = {{0,5},{6,8}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Merge with last two
TEST_F(InsertIntervalTest, MergeLastTwo) {
  vector<vector<int>> intervals = {{1,2},{5,6},{7,8}};
  vector<int> newInterval = {4,9};
  vector<vector<int>> expected = {{1,2},{4,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Multiple gaps, insert in first gap
TEST_F(InsertIntervalTest, InsertInFirstGap) {
  vector<vector<int>> intervals = {{1,2},{5,6},{9,10}};
  vector<int> newInterval = {3,4};
  vector<vector<int>> expected = {{1,2},{3,4},{5,6},{9,10}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Multiple gaps, insert in last gap
TEST_F(InsertIntervalTest, InsertInLastGap) {
  vector<vector<int>> intervals = {{1,2},{5,6},{9,10}};
  vector<int> newInterval = {7,8};
  vector<vector<int>> expected = {{1,2},{5,6},{7,8},{9,10}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// New interval same as existing
TEST_F(InsertIntervalTest, SameAsExisting) {
  vector<vector<int>> intervals = {{1,3},{5,7}};
  vector<int> newInterval = {5,7};
  vector<vector<int>> expected = {{1,3},{5,7}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Zero values
TEST_F(InsertIntervalTest, ZeroValues) {
  vector<vector<int>> intervals = {{1,3},{6,9}};
  vector<int> newInterval = {0,5};
  vector<vector<int>> expected = {{0,5},{6,9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Large values
TEST_F(InsertIntervalTest, LargeValues) {
  vector<vector<int>> intervals = {{100000,100001}};
  vector<int> newInterval = {99999,100000};
  vector<vector<int>> expected = {{99999,100001}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// Single point intervals
TEST_F(InsertIntervalTest, SinglePointIntervals) {
  vector<vector<int>> intervals = {{1,1},{3,3},{5,5}};
  vector<int> newInterval = {2,4};
  vector<vector<int>> expected = {{1,1},{2,4},{5,5}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}

// New interval is single point
TEST_F(InsertIntervalTest, NewIntervalSinglePoint) {
  vector<vector<int>> intervals = {{1,2},{4,5}};
  vector<int> newInterval = {3,3};
  vector<vector<int>> expected = {{1,2},{3,3},{4,5}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}
