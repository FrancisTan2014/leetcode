// tests/test_0955-delete-columns-to-make-sorted-ii.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include <string>
#include "../solution.cpp"

using namespace leetcode;

// Example 1: ["ca","bb","ac"] -> 1
TEST(DeleteColumnsToMakeSortedII, Example1) {
    Solution s;
    std::vector<std::string> strs = {"ca", "bb", "ac"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Example 2: ["xc","yb","za"] -> 0
TEST(DeleteColumnsToMakeSortedII, Example2) {
    Solution s;
    std::vector<std::string> strs = {"xc", "yb", "za"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Example 3: ["zyx","wvu","tsr"] -> 3
TEST(DeleteColumnsToMakeSortedII, Example3) {
    Solution s;
    std::vector<std::string> strs = {"zyx", "wvu", "tsr"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// Single string (minimum n=1)
TEST(DeleteColumnsToMakeSortedII, SingleString) {
    Solution s;
    std::vector<std::string> strs = {"abc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Two strings already sorted
TEST(DeleteColumnsToMakeSortedII, TwoStringsSorted) {
    Solution s;
    std::vector<std::string> strs = {"abc", "def"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Two strings need all deletions
TEST(DeleteColumnsToMakeSortedII, TwoStringsReverse) {
    Solution s;
    std::vector<std::string> strs = {"bbb", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// All strings identical
TEST(DeleteColumnsToMakeSortedII, AllIdentical) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "aaa", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// First column determines order
TEST(DeleteColumnsToMakeSortedII, FirstColumnDetermines) {
    Solution s;
    std::vector<std::string> strs = {"abc", "bcd", "cde"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Need to delete middle column
TEST(DeleteColumnsToMakeSortedII, DeleteMiddle) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "aba", "aca"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Complex case with partial sorting
TEST(DeleteColumnsToMakeSortedII, ComplexPartialSort) {
    Solution s;
    std::vector<std::string> strs = {"xga", "xfb", "yfa"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Single character strings
TEST(DeleteColumnsToMakeSortedII, SingleChar) {
    Solution s;
    std::vector<std::string> strs = {"a", "b", "c"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Single character strings reversed
TEST(DeleteColumnsToMakeSortedII, SingleCharReversed) {
    Solution s;
    std::vector<std::string> strs = {"c", "b", "a"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Strings with equal prefixes
TEST(DeleteColumnsToMakeSortedII, EqualPrefixes) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "aab", "aac"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Multiple pairs with same chars in first column
TEST(DeleteColumnsToMakeSortedII, MultiplePairsSameFirstChar) {
    Solution s;
    std::vector<std::string> strs = {"ao", "ap", "bn", "ca", "cb"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Same chars in first column, need to check second
TEST(DeleteColumnsToMakeSortedII, SameCharsFirstColumn) {
    Solution s;
    std::vector<std::string> strs = {"aac", "aab", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Same chars in multiple columns before determining order
TEST(DeleteColumnsToMakeSortedII, MultipleColumnsWithSameChars) {
    Solution s;
    std::vector<std::string> strs = {"aabc", "aabd", "aabe"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Same chars require checking later column, then need deletion
TEST(DeleteColumnsToMakeSortedII, SameCharsThenDelete) {
    Solution s;
    std::vector<std::string> strs = {"aaba", "aabb", "aaac"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// All same in first two columns, third determines order
TEST(DeleteColumnsToMakeSortedII, DetermineOrderAtThirdColumn) {
    Solution s;
    std::vector<std::string> strs = {"aaab", "aaac", "aaad"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Partial same chars pattern
TEST(DeleteColumnsToMakeSortedII, PartialSameCharsPattern) {
    Solution s;
    std::vector<std::string> strs = {"abc", "abd", "bcd"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Same chars in col 1, unsorted in col 2, sorted in col 3
TEST(DeleteColumnsToMakeSortedII, SameThenUnsortedThenSorted) {
    Solution s;
    std::vector<std::string> strs = {"aba", "aca", "ada"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Complex: some pairs already sorted by first col, others need second col
TEST(DeleteColumnsToMakeSortedII, MixedPairDetermination) {
    Solution s;
    std::vector<std::string> strs = {"abc", "adc", "bef"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Need to track which pairs are sorted independently
TEST(DeleteColumnsToMakeSortedII, IndependentPairTracking) {
    Solution s;
    std::vector<std::string> strs = {"abc", "acd", "ace"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// First column same, second determines some pairs, third determines rest
TEST(DeleteColumnsToMakeSortedII, GradualPairDetermination) {
    Solution s;
    std::vector<std::string> strs = {"aaab", "aaac", "aabc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// LeetCode regression test case 1
TEST(DeleteColumnsToMakeSortedII, LeetCodeRegressionCase1) {
    Solution s;
    std::vector<std::string> strs = {"jsebodtwc", "cnneoytml", "eeneuyzlu", "ewpnmtivg"};
    EXPECT_EQ(s.minDeletionSize(strs), 2);
}

// LeetCode regression test case 2
TEST(DeleteColumnsToMakeSortedII, LeetCodeRegressionCase2) {
    Solution s;
    std::vector<std::string> strs = {"vdy", "vei", "zvc", "zld"};
    EXPECT_EQ(s.minDeletionSize(strs), 2);
}

TEST(DeleteColumnsToMakeSortedII, Performance) {
    Solution s;
    
    // Build test data: 100 strings of length 100
    std::vector<std::string> strs(100, std::string(100, 'a'));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            strs[i][j] = 'a' + (i + j) % 26;
        }
    }
    
    // Measure performance
    PerformanceMonitor monitor(1000.0, 10 * 1024); // 1s, 10MB limits
    auto metrics = monitor.measure([&]() {
        s.minDeletionSize(strs);
    });
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "DeleteColumnsToMakeSortedII");
    EXPECT_PERFORMANCE(metrics, 1000.0, 10 * 1024);
}
