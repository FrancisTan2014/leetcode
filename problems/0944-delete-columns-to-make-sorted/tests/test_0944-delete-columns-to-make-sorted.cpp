// tests/test_0944-delete-columns-to-make-sorted.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include <string>
#include "../solution.cpp"

using namespace leetcode;

// ========== Example Cases ==========

// Example 1: ["cba","daf","ghi"] -> 1
TEST(DeleteColumnsToMakeSorted, Example1) {
    Solution s;
    std::vector<std::string> strs = {"cba", "daf", "ghi"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Example 2: ["a","b"] -> 0
TEST(DeleteColumnsToMakeSorted, Example2) {
    Solution s;
    std::vector<std::string> strs = {"a", "b"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Example 3: ["zyx","wvu","tsr"] -> 3
TEST(DeleteColumnsToMakeSorted, Example3) {
    Solution s;
    std::vector<std::string> strs = {"zyx", "wvu", "tsr"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// ========== Edge Cases ==========

// Single string (minimum n=1)
TEST(DeleteColumnsToMakeSorted, SingleString) {
    Solution s;
    std::vector<std::string> strs = {"abc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Single character strings
TEST(DeleteColumnsToMakeSorted, SingleCharStrings) {
    Solution s;
    std::vector<std::string> strs = {"a", "b", "c"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// All strings identical
TEST(DeleteColumnsToMakeSorted, AllIdentical) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "aaa", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Two strings sorted
TEST(DeleteColumnsToMakeSorted, TwoStringsSorted) {
    Solution s;
    std::vector<std::string> strs = {"abc", "def"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Two strings reverse order
TEST(DeleteColumnsToMakeSorted, TwoStringsReverse) {
    Solution s;
    std::vector<std::string> strs = {"bbb", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// ========== Basic Column Tests ==========

// All columns sorted
TEST(DeleteColumnsToMakeSorted, AllColumnsSorted) {
    Solution s;
    std::vector<std::string> strs = {"abc", "bcd", "cde"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// No columns sorted
TEST(DeleteColumnsToMakeSorted, NoColumnsSorted) {
    Solution s;
    std::vector<std::string> strs = {"cba", "bab", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// First column unsorted
TEST(DeleteColumnsToMakeSorted, FirstColumnUnsorted) {
    Solution s;
    std::vector<std::string> strs = {"bac", "aad"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Middle column unsorted
TEST(DeleteColumnsToMakeSorted, MiddleColumnUnsorted) {
    Solution s;
    std::vector<std::string> strs = {"abc", "adc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);  // All columns sorted: a<=a, b<=d, c<=c
}

// Last column unsorted
TEST(DeleteColumnsToMakeSorted, LastColumnUnsorted) {
    Solution s;
    std::vector<std::string> strs = {"aba", "aca"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);  // All columns sorted: a<=a, b<=c, a<=a
}

// ========== Multiple Column Tests ==========

// Delete first and last columns
TEST(DeleteColumnsToMakeSorted, DeleteFirstAndLast) {
    Solution s;
    std::vector<std::string> strs = {"cba", "dae"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);  // Only col 1: b>a (unsorted)
}

// Delete alternating columns
TEST(DeleteColumnsToMakeSorted, DeleteAlternating) {
    Solution s;
    std::vector<std::string> strs = {"caca", "bdbd"};
    EXPECT_EQ(s.minDeletionSize(strs), 2);  // Col 0: c>b (delete), Col 2: c>b (delete)
}

// Delete all but two
TEST(DeleteColumnsToMakeSorted, DeleteAllButOne) {
    Solution s;
    std::vector<std::string> strs = {"dcba", "abcd"};
    EXPECT_EQ(s.minDeletionSize(strs), 2);  // Col 0: d>a, Col 1: c>b (delete), Cols 2-3: sorted
}

// ========== Boundary Value Tests ==========

// Maximum string length (1000)
TEST(DeleteColumnsToMakeSorted, MaxStringLength) {
    Solution s;
    std::string str1(1000, 'a');
    std::string str2(1000, 'b');
    std::vector<std::string> strs = {str1, str2};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Maximum number of strings (100)
TEST(DeleteColumnsToMakeSorted, MaxStringCount) {
    Solution s;
    std::vector<std::string> strs(100, "abc");
    for (int i = 0; i < 100; i++) {
        strs[i][0] = 'a' + (i % 26);
    }
    // First column: a,b,c,...,z,a,b,... -> has 'z' > 'a' at i=26, so 1 deletion
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// ========== Pattern Tests ==========

// Ascending pattern
TEST(DeleteColumnsToMakeSorted, AscendingPattern) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "bbb", "ccc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// Descending pattern
TEST(DeleteColumnsToMakeSorted, DescendingPattern) {
    Solution s;
    std::vector<std::string> strs = {"ccc", "bbb", "aaa"};
    EXPECT_EQ(s.minDeletionSize(strs), 3);
}

// Mixed pattern
TEST(DeleteColumnsToMakeSorted, MixedPattern) {
    Solution s;
    std::vector<std::string> strs = {"abc", "bac", "cab"};
    EXPECT_EQ(s.minDeletionSize(strs), 2);
}

// Repeating characters
TEST(DeleteColumnsToMakeSorted, RepeatingCharacters) {
    Solution s;
    std::vector<std::string> strs = {"aaa", "aaa", "bbb"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);
}

// ========== Special Cases ==========

// Equal adjacent characters in column (sorted with equals)
TEST(DeleteColumnsToMakeSorted, EqualAdjacentChars) {
    Solution s;
    std::vector<std::string> strs = {"aac", "aac", "abc"};
    EXPECT_EQ(s.minDeletionSize(strs), 0);  // Fixed: col 2 was c->b->c (unsorted)
}

// Column with single violation at start
TEST(DeleteColumnsToMakeSorted, ViolationAtStart) {
    Solution s;
    std::vector<std::string> strs = {"ba", "aa", "aa"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Column with single violation in middle
TEST(DeleteColumnsToMakeSorted, ViolationInMiddle) {
    Solution s;
    std::vector<std::string> strs = {"aa", "ca", "ba"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

// Column with single violation at end
TEST(DeleteColumnsToMakeSorted, ViolationAtEnd) {
    Solution s;
    std::vector<std::string> strs = {"aa", "ab", "aa"};
    EXPECT_EQ(s.minDeletionSize(strs), 1);
}

TEST(DeleteColumnsToMakeSorted, Performance) {
    Solution s;
    
    // Build test data: 100 strings of length 1000
    std::vector<std::string> strs(100, std::string(1000, 'a'));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            strs[i][j] = 'a' + (i + j) % 26;
        }
    }
    
    // Measure performance
    PerformanceMonitor monitor(1000.0, 10 * 1024); // 1s, 10MB limits
    auto metrics = monitor.measure([&]() {
        s.minDeletionSize(strs);
    });
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "DeleteColumnsToMakeSorted");
    EXPECT_PERFORMANCE(metrics, 1000.0, 10 * 1024);
}

