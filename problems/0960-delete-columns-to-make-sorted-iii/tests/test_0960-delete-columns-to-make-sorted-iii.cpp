// tests/test_0960-delete-columns-to-make-sorted-iii.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include <string>
#include "../solution.cpp"

using namespace leetcode;

// ========== Example Cases ==========

// Example 1: ["babca","bbazb"] -> 3
TEST(DeleteColumnsToMakeSortedIII, Example1) {
    Solution s;
    std::vector<std::string> strs = {"babca", "bbazb"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// Example 2: ["edcba"] -> 4
TEST(DeleteColumnsToMakeSortedIII, Example2) {
    Solution s;
    std::vector<std::string> strs = {"edcba"};
    EXPECT_EQ(s.minDeletionSize(strs), 4);
}

// Example 3: ["ghi","def","abc"] -> 0
TEST(DeleteColumnsToMakeSortedIII, Example3) {
    Solution s;
    std::vector<std::string> strs = {"ghi", "def", "abc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// ========== Edge Cases ==========

// Single string, single char
TEST(DeleteColumnsToMakeSortedIII, SingleCharString) {
    Solution s;
    std::vector<std::string> strs = {"a"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Single string, already sorted
TEST(DeleteColumnsToMakeSortedIII, SingleStringSorted) {
    Solution s;
    std::vector<std::string> strs = {"abc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Single string, reverse order
TEST(DeleteColumnsToMakeSortedIII, SingleStringReverse) {
    Solution s;
    std::vector<std::string> strs = {"cba"};
    EXPECT_EQ(s.minDeletionSize(strs), 2); // Keep only one character
}

// Multiple strings, all sorted
TEST(DeleteColumnsToMakeSortedIII, AllStringsSorted) {
    Solution s;
    std::vector<std::string> strs = {"abc", "def", "xyz"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Multiple strings, all reversed
TEST(DeleteColumnsToMakeSortedIII, AllStringsReversed) {
    Solution s;
    std::vector<std::string> strs = {"cba", "fed", "zyx"};
    EXPECT_EQ(s.minDeletionSize(strs), 2); // Keep only one character per string
}

// ========== Basic Cases ==========

// Two strings with different patterns
TEST(DeleteColumnsToMakeSortedIII, TwoStringsDifferentPatterns) {
    Solution s;
    std::vector<std::string> strs = {"abc", "cba"};
    EXPECT_EQ(s.minDeletionSize(strs), 2); // Can keep at most one column
}

// Strings with alternating up/down
TEST(DeleteColumnsToMakeSortedIII, AlternatingPattern) {
    Solution s;
    std::vector<std::string> strs = {"aba", "cdc"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // Can keep columns 0,2 (both a<=a and c<=c)
}

// Keep first and last columns
TEST(DeleteColumnsToMakeSortedIII, KeepFirstAndLast) {
    Solution s;
    std::vector<std::string> strs = {"aca", "bdb"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // Keep columns 0,2 (a<=a, b<=b)
}

// All same characters
TEST(DeleteColumnsToMakeSortedIII, AllSameChars) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "bbb", "ccc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// ========== LIS Pattern Cases ==========

// Classic LIS within strings
TEST(DeleteColumnsToMakeSortedIII, ClassicLIS) {
    Solution s;
    std::vector<std::string> strs = {"acdb", "acdb"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // LIS is "acd" (length 3), delete 1
}

// Multiple valid LIS
TEST(DeleteColumnsToMakeSortedIII, MultipleValidLIS) {
    Solution s;
    std::vector<std::string> strs = {"abdc", "abdc"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // Can keep "abd" or "abc", delete 1
}

// LIS at the end
TEST(DeleteColumnsToMakeSortedIII, LISAtEnd) {
    Solution s;
    std::vector<std::string> strs = {"dcba", "dcba"};
    EXPECT_EQ(s.minDeletionSize(strs), 3); // Can only keep 1 column
}

// ========== Constraint Cases ==========

// Different LIS lengths in different strings
TEST(DeleteColumnsToMakeSortedIII, DifferentLISLengths) {
    Solution s;
    std::vector<std::string> strs = {"abc", "bac"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // "abc"->keep all, "bac"->keep "ac", intersection: 2 columns
}

// One string limits the solution
TEST(DeleteColumnsToMakeSortedIII, OneLimitingString) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "cba"};
    EXPECT_EQ(s.minDeletionSize(strs), 2); // Second string limits to 1 column
}

// ========== Special Patterns ==========

// Strictly increasing
TEST(DeleteColumnsToMakeSortedIII, StrictlyIncreasing) {
    Solution s;
    std::vector<std::string> strs = {"abcd", "efgh"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// With repeated characters (non-strict)
TEST(DeleteColumnsToMakeSortedIII, WithRepeatedChars) {
    Solution s;
    std::vector<std::string> strs = {"aabc", "aabc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Zigzag pattern
TEST(DeleteColumnsToMakeSortedIII, ZigzagPattern) {
    Solution s;
    std::vector<std::string> strs = {"abab", "cdcd"};
    EXPECT_EQ(s.minDeletionSize(strs), 1); // Can keep columns {0,1,3} → "abb", "cdd"
}

TEST(DeleteColumnsToMakeSortedIII, Performance) {
    Solution s;
    
    // Build test data: 100 strings of length 100
    std::vector<std::string> strs(100, std::string(100, 'a'));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            strs[i][j] = 'a' + (j % 26);
        }
    }
    
    // Measure performance
    PerformanceMonitor monitor(1000.0, 10 * 1024); // 1s, 10MB limits
    auto metrics = monitor.measure([&]() {
        s.minDeletionSize(strs);
    });
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "DeleteColumnsToMakeSortedIII");
    EXPECT_PERFORMANCE(metrics, 1000.0, 10 * 1024);
}

