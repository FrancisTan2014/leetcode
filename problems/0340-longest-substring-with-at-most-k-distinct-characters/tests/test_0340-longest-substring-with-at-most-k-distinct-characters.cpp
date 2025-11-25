// tests/test_0340-longest-substring-with-at-most-k-distinct-characters.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(LongestSubstringKDistinct, SingleChar) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("a", 0), 0);  // k=0, no chars allowed
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("a", 1), 1);  // k=1, entire string
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("a", 2), 1);  // k>distinct, entire string
}

TEST(LongestSubstringKDistinct, TwoChars) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("ab", 1), 1);  // Only 1 distinct allowed
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("ab", 2), 2);  // Both allowed
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aa", 1), 2);  // Same char repeated
}

// ========== Typical Cases ==========

TEST(LongestSubstringKDistinct, Example1) {
    Solution s;
    // "eceba", k=2: "ece" has 2 distinct (e,c), length 3
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("eceba", 2), 3);
}

TEST(LongestSubstringKDistinct, Example2) {
    Solution s;
    // "aa", k=1: entire string "aa" has 1 distinct, length 2
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aa", 1), 2);
}

TEST(LongestSubstringKDistinct, MultipleOccurrences) {
    Solution s;
    // "aaabbcc", k=2: "aabbc" or "abbcc" both have length 5
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aaabbcc", 2), 5);
}

TEST(LongestSubstringKDistinct, AllDifferent) {
    Solution s;
    // "abcdef", k=3: "abc" or "bcd" or "cde" or "def", all length 3
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abcdef", 3), 3);
}

// ========== Boundary Cases ==========

TEST(LongestSubstringKDistinct, KIsZero) {
    Solution s;
    // k=0 means no distinct characters allowed
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abc", 0), 0);
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aaa", 0), 0);
}

TEST(LongestSubstringKDistinct, KEqualsDistinct) {
    Solution s;
    // When k equals number of distinct chars, entire string is valid
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abcde", 5), 5);
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aabbcc", 3), 6);
}

TEST(LongestSubstringKDistinct, KGreaterThanDistinct) {
    Solution s;
    // When k > distinct chars, entire string is valid
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abc", 10), 3);
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aabbcc", 10), 6);
}

TEST(LongestSubstringKDistinct, MaxK) {
    Solution s;
    // k=50 (max constraint)
    string str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";  // 26 distinct
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct(str, 50), 52);
}

// ========== Edge Behavior Cases ==========

TEST(LongestSubstringKDistinct, AllSameChar) {
    Solution s;
    // All same character: entire string valid if k>=1
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aaaaaaa", 1), 7);
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("zzzzz", 1), 5);
}

TEST(LongestSubstringKDistinct, AlternatingPattern) {
    Solution s;
    // "ababab", k=2: entire string valid, length 6
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("ababab", 2), 6);
    // "ababab", k=1: "a" or "b", length 1
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("ababab", 1), 1);
}

TEST(LongestSubstringKDistinct, StartMiddleEnd) {
    Solution s;
    // "aabbbccd", k=2: "aabbb" (a,b) or "bbbcc" (b,c), length 5
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aabbbccd", 2), 5);
}

// ========== Trick Cases ==========

TEST(LongestSubstringKDistinct, LongRepetitionThenNew) {
    Solution s;
    // "aaaaaab", k=1: "aaaaaa", length 6 (not 7!)
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aaaaaab", 1), 6);
}

TEST(LongestSubstringKDistinct, NewCharAtStart) {
    Solution s;
    // "abbbbb", k=1: "bbbbb", length 5
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abbbbb", 1), 5);
}

TEST(LongestSubstringKDistinct, ComplexPattern) {
    Solution s;
    // "abaccc", k=2: "accc" (a,c), length 4
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("abaccc", 2), 4);
}

TEST(LongestSubstringKDistinct, MultipleValidSubstrings) {
    Solution s;
    // "aabbccdd", k=2: "aabb" or "bbcc" or "ccdd", all length 4
    EXPECT_EQ(s.lengthOfLongestSubstringKDistinct("aabbccdd", 2), 4);
}

// ========== Performance Cases ==========

TEST(LongestSubstringKDistinct, MaxLengthAllSame) {
    Solution s;
    
    // Max length (50000) with all same char, k=1
    string str(50000, 'a');
    
    PerformanceMonitor monitor(20.0, 1024); // 20ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.lengthOfLongestSubstringKDistinct(str, 1);
    }, result);
    
    EXPECT_EQ(result, 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllSame");
    EXPECT_PERFORMANCE(metrics, 20.0, 1024);
}

TEST(LongestSubstringKDistinct, MaxLengthAlternating) {
    Solution s;
    
    // Max length with alternating pattern "ababab...", k=2
    string str;
    str.reserve(50000);
    for (int i = 0; i < 50000; i++) {
        str += (i % 2 == 0) ? 'a' : 'b';
    }
    
    PerformanceMonitor monitor(20.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.lengthOfLongestSubstringKDistinct(str, 2);
    }, result);
    
    EXPECT_EQ(result, 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAlternating");
    EXPECT_PERFORMANCE(metrics, 20.0, 1024);
}

TEST(LongestSubstringKDistinct, MaxLengthWorstCase) {
    Solution s;
    
    // Worst case: k=1, string with many different chars forcing window to shrink often
    // Pattern: "abcdef...zabcdef...z" repeated
    string str;
    str.reserve(50000);
    for (int i = 0; i < 50000; i++) {
        str += char('a' + (i % 26));
    }
    
    PerformanceMonitor monitor(20.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.lengthOfLongestSubstringKDistinct(str, 1);
    }, result);
    
    EXPECT_EQ(result, 1);  // Only single char substrings valid
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthWorstCase");
    EXPECT_PERFORMANCE(metrics, 20.0, 1024);
}

TEST(LongestSubstringKDistinct, MaxKMaxLength) {
    Solution s;
    
    // Max k (50) with max length: use all 26 lowercase letters
    string str;
    str.reserve(50000);
    for (int i = 0; i < 50000; i++) {
        str += char('a' + (i % 26));
    }
    
    PerformanceMonitor monitor(20.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.lengthOfLongestSubstringKDistinct(str, 50);
    }, result);
    
    EXPECT_EQ(result, 50000);  // All chars valid since k=50 > 26 distinct
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxKMaxLength");
    EXPECT_PERFORMANCE(metrics, 20.0, 1024);
}
