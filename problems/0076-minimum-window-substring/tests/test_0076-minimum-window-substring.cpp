// tests/test_0076-minimum-window-substring.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(MinWindowSubstring, SingleCharBoth) {
    Solution s;
    EXPECT_EQ(s.minWindow("a", "a"), "a");
}

TEST(MinWindowSubstring, SingleCharNotFound) {
    Solution s;
    EXPECT_EQ(s.minWindow("a", "b"), "");
}

TEST(MinWindowSubstring, TwoCharExactMatch) {
    Solution s;
    EXPECT_EQ(s.minWindow("ab", "ab"), "ab");
    EXPECT_EQ(s.minWindow("ab", "ba"), "ab"); // Order doesn't matter
}

// ========== Typical Cases ==========

TEST(MinWindowSubstring, Example1) {
    Solution s;
    EXPECT_EQ(s.minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST(MinWindowSubstring, Example2) {
    Solution s;
    EXPECT_EQ(s.minWindow("a", "a"), "a");
}

TEST(MinWindowSubstring, Example3) {
    Solution s;
    EXPECT_EQ(s.minWindow("a", "aa"), "");
}

TEST(MinWindowSubstring, MultipleOccurrences) {
    Solution s;
    // Minimum window from index 2 to 7 contains a,b,c
    EXPECT_EQ(s.minWindow("aaabbbccc", "abc"), "abbbc");
}

TEST(MinWindowSubstring, WindowInMiddle) {
    Solution s;
    EXPECT_EQ(s.minWindow("xxabcyy", "abc"), "abc");
}

// ========== Boundary Cases ==========

TEST(MinWindowSubstring, SLengthLessThanT) {
    Solution s;
    EXPECT_EQ(s.minWindow("ab", "abc"), ""); // s too short
    EXPECT_EQ(s.minWindow("a", "aa"), "");   // Not enough chars
}

TEST(MinWindowSubstring, SEqualsT) {
    Solution s;
    EXPECT_EQ(s.minWindow("abc", "abc"), "abc");
    EXPECT_EQ(s.minWindow("abc", "bca"), "abc"); // Permutation
}

TEST(MinWindowSubstring, EntireStringIsWindow) {
    Solution s;
    EXPECT_EQ(s.minWindow("abc", "abc"), "abc");
    EXPECT_EQ(s.minWindow("aabbcc", "abc"), "abbc"); // Minimum window at indices 1-4
}

TEST(MinWindowSubstring, WindowAtStart) {
    Solution s;
    EXPECT_EQ(s.minWindow("abcxyz", "abc"), "abc");
}

TEST(MinWindowSubstring, WindowAtEnd) {
    Solution s;
    EXPECT_EQ(s.minWindow("xyzabc", "abc"), "abc");
}

// ========== Frequency Cases ==========

TEST(MinWindowSubstring, DuplicatesInT) {
    Solution s;
    EXPECT_EQ(s.minWindow("aa", "aa"), "aa");
    EXPECT_EQ(s.minWindow("aaab", "aa"), "aa");
    EXPECT_EQ(s.minWindow("baa", "aa"), "aa");
}

TEST(MinWindowSubstring, ExcessCharsInWindow) {
    Solution s;
    // Window contains extra chars but still valid
    EXPECT_EQ(s.minWindow("aaabbbccc", "abc"), "abbbc");
    EXPECT_EQ(s.minWindow("aabbccabc", "abc"), "cab"); // Last "abc" is smallest
}

TEST(MinWindowSubstring, MultipleValidWindows) {
    Solution s;
    // Multiple windows, should return smallest
    EXPECT_EQ(s.minWindow("cabefgecdabc", "cae"), "cabe");
}

// ========== Case Sensitivity ==========

TEST(MinWindowSubstring, UppercaseLowercase) {
    Solution s;
    EXPECT_EQ(s.minWindow("Aa", "Aa"), "Aa");
    EXPECT_EQ(s.minWindow("aA", "Aa"), "aA");
    EXPECT_EQ(s.minWindow("abc", "ABC"), ""); // Case matters
}

TEST(MinWindowSubstring, MixedCase) {
    Solution s;
    EXPECT_EQ(s.minWindow("AaBbCc", "ABC"), "AaBbC"); // Need uppercase A,B,C
}

// ========== Edge Patterns ==========

TEST(MinWindowSubstring, AllSameChar) {
    Solution s;
    EXPECT_EQ(s.minWindow("aaaa", "aa"), "aa");
    EXPECT_EQ(s.minWindow("aaaa", "aaa"), "aaa");
}

TEST(MinWindowSubstring, NoValidWindow) {
    Solution s;
    EXPECT_EQ(s.minWindow("abc", "xyz"), ""); // No x,y,z in s
    EXPECT_EQ(s.minWindow("aaa", "b"), "");   // No b in s
}

TEST(MinWindowSubstring, SingleCharRepeated) {
    Solution s;
    EXPECT_EQ(s.minWindow("bbbbbab", "ab"), "ba");
    EXPECT_EQ(s.minWindow("abbbbbba", "ab"), "ab"); // First occurrence
}

// ========== Shrinking Window Cases ==========

TEST(MinWindowSubstring, RequiresShrinking) {
    Solution s;
    // Window must shrink to find minimum
    EXPECT_EQ(s.minWindow("aaaaabc", "abc"), "abc");
    EXPECT_EQ(s.minWindow("abccccc", "abc"), "abc");
}

TEST(MinWindowSubstring, InterleavedChars) {
    Solution s;
    EXPECT_EQ(s.minWindow("acbbaca", "aba"), "baca"); // Need 2 'a's and 1 'b', minimum is indices 3-7
}

// ========== Trick Cases ==========

TEST(MinWindowSubstring, OverlappingWindows) {
    Solution s;
    // Multiple valid windows, return smallest
    EXPECT_EQ(s.minWindow("abcabdabc", "abd"), "abd"); // Indices 3-5 give "abd"
}

TEST(MinWindowSubstring, LongPrefix) {
    Solution s;
    // Long prefix before valid window
    EXPECT_EQ(s.minWindow("zzzzzzzzabc", "abc"), "abc");
}

TEST(MinWindowSubstring, LongSuffix) {
    Solution s;
    // Valid window early with long suffix
    EXPECT_EQ(s.minWindow("abczzzzzz", "abc"), "abc");
}

// ========== Performance Cases ==========

TEST(MinWindowSubstring, MaxLengthBothStrings) {
    Solution s;
    
    // Max length: s=100000, t=100000 (both at limit)
    string str_s(100000, 'a');
    string str_t(100000, 'a');
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    string result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minWindow(str_s, str_t);
    }, result);
    
    EXPECT_EQ(result, str_s); // Entire string is the window
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthExactMatch");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(MinWindowSubstring, MaxLengthWorstCase) {
    Solution s;
    
    // Worst case: small window at the very end of large string
    string str_s;
    str_s.reserve(100000);
    // Fill with 'a's except last 10 chars
    for (int i = 0; i < 99990; i++) {
        str_s += 'a';
    }
    str_s += "bcdefghijk"; // Last 10 chars contain all needed
    
    string str_t = "bcdefghijk";
    
    PerformanceMonitor monitor(10, 1);
    string result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minWindow(str_s, str_t);
    }, result);
    
    EXPECT_EQ(result, "bcdefghijk"); // Found at end
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "WorstCaseEndMatch");
    EXPECT_PERFORMANCE(metrics, 10, 1);
}

TEST(MinWindowSubstring, MaxLengthNoMatch) {
    Solution s;
    
    // s is all 'a', t requires 'z' - should quickly determine no match
    string str_s(100000, 'a');
    string str_t = "az";
    
    PerformanceMonitor monitor(10, 1);
    string result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minWindow(str_s, str_t);
    }, result);
    
    EXPECT_EQ(result, ""); // No 'z' in s
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthNoMatch");
    EXPECT_PERFORMANCE(metrics, 10, 1);
}

TEST(MinWindowSubstring, MaxLengthManyDistinct) {
    Solution s;
    
    // Large string with many distinct chars, small t
    string str_s;
    str_s.reserve(100000);
    for (int i = 0; i < 100000; i++) {
        str_s += char('a' + (i % 26));
    }
    
    string str_t = "abcdefghij"; // 10 distinct chars
    
    PerformanceMonitor monitor(10, 1);
    string result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.minWindow(str_s, str_t);
    }, result);
    
    // Should find a valid window
    EXPECT_FALSE(result.empty());
    EXPECT_GE(result.length(), 10); // At least 10 chars
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "ManyDistinctChars");
    EXPECT_PERFORMANCE(metrics, 10, 1);
}
