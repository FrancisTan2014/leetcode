#include <gtest/gtest.h>
#include "../solution.cpp"

class MergeIntervalsTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Example 1: Basic overlapping intervals
TEST_F(MergeIntervalsTest, Example1) {
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> expected = {{1,6},{8,10},{15,18}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Example 2: Touching intervals
TEST_F(MergeIntervalsTest, Example2) {
  vector<vector<int>> intervals = {{1,4},{4,5}};
  vector<vector<int>> expected = {{1,5}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Single interval
TEST_F(MergeIntervalsTest, SingleInterval) {
  vector<vector<int>> intervals = {{1,5}};
  vector<vector<int>> expected = {{1,5}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// No overlaps
TEST_F(MergeIntervalsTest, NoOverlaps) {
  vector<vector<int>> intervals = {{1,2},{3,4},{5,6}};
  vector<vector<int>> expected = {{1,2},{3,4},{5,6}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// All intervals merge into one
TEST_F(MergeIntervalsTest, AllMerge) {
  vector<vector<int>> intervals = {{1,4},{2,5},{3,6}};
  vector<vector<int>> expected = {{1,6}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Intervals already sorted, no merge needed
TEST_F(MergeIntervalsTest, AlreadySortedNoMerge) {
  vector<vector<int>> intervals = {{1,2},{4,5},{7,8}};
  vector<vector<int>> expected = {{1,2},{4,5},{7,8}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Unsorted intervals with overlaps
TEST_F(MergeIntervalsTest, UnsortedWithOverlaps) {
  vector<vector<int>> intervals = {{8,10},{1,3},{2,6},{15,18}};
  vector<vector<int>> expected = {{1,6},{8,10},{15,18}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// One interval contains another
TEST_F(MergeIntervalsTest, OneContainsAnother) {
  vector<vector<int>> intervals = {{1,5},{2,3}};
  vector<vector<int>> expected = {{1,5}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Multiple intervals inside one large interval
TEST_F(MergeIntervalsTest, MultipleInsideOne) {
  vector<vector<int>> intervals = {{1,10},{2,3},{4,5},{6,7}};
  vector<vector<int>> expected = {{1,10}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Identical intervals
TEST_F(MergeIntervalsTest, IdenticalIntervals) {
  vector<vector<int>> intervals = {{1,3},{1,3},{1,3}};
  vector<vector<int>> expected = {{1,3}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Adjacent non-overlapping intervals
TEST_F(MergeIntervalsTest, AdjacentNonOverlapping) {
  vector<vector<int>> intervals = {{1,2},{3,4},{5,6}};
  vector<vector<int>> expected = {{1,2},{3,4},{5,6}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Two groups of overlapping intervals
TEST_F(MergeIntervalsTest, TwoGroups) {
  vector<vector<int>> intervals = {{1,3},{2,4},{6,8},{7,9}};
  vector<vector<int>> expected = {{1,4},{6,9}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Zero start point
TEST_F(MergeIntervalsTest, ZeroStart) {
  vector<vector<int>> intervals = {{0,1},{1,2},{2,3}};
  vector<vector<int>> expected = {{0,3}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Large values
TEST_F(MergeIntervalsTest, LargeValues) {
  vector<vector<int>> intervals = {{9999,10000},{9998,9999}};
  vector<vector<int>> expected = {{9998,10000}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Same start different end
TEST_F(MergeIntervalsTest, SameStartDifferentEnd) {
  vector<vector<int>> intervals = {{1,4},{1,5},{1,3}};
  vector<vector<int>> expected = {{1,5}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Complex overlapping pattern
TEST_F(MergeIntervalsTest, ComplexPattern) {
  vector<vector<int>> intervals = {{1,4},{0,4}};
  vector<vector<int>> expected = {{0,4}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Multiple merges needed
TEST_F(MergeIntervalsTest, MultipleMerges) {
  vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
  vector<vector<int>> expected = {{0,5}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Long chain of overlaps
TEST_F(MergeIntervalsTest, LongChain) {
  vector<vector<int>> intervals = {{1,3},{2,4},{3,5},{4,6},{5,7}};
  vector<vector<int>> expected = {{1,7}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Intervals with gaps
TEST_F(MergeIntervalsTest, IntervalsWithGaps) {
  vector<vector<int>> intervals = {{1,2},{4,5},{7,8},{10,11}};
  vector<vector<int>> expected = {{1,2},{4,5},{7,8},{10,11}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Single point intervals
TEST_F(MergeIntervalsTest, SinglePointIntervals) {
  vector<vector<int>> intervals = {{1,1},{2,2},{3,3}};
  vector<vector<int>> expected = {{1,1},{2,2},{3,3}};
  EXPECT_EQ(solution.merge(intervals), expected);
}

// Overlapping single point intervals
TEST_F(MergeIntervalsTest, OverlappingSinglePoint) {
  vector<vector<int>> intervals = {{1,3},{2,2}};
  vector<vector<int>> expected = {{1,3}};
  EXPECT_EQ(solution.merge(intervals), expected);

}
