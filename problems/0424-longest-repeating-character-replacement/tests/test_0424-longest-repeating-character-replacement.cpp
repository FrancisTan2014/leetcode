// tests/test_0424-longest-repeating-character-replacement.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(LongestRepeatingCharacterReplacement, SingleChar) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("A", 0), 1);
    EXPECT_EQ(s.characterReplacement("A", 1), 1);
}

TEST(LongestRepeatingCharacterReplacement, TwoCharsSame) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("AA", 0), 2);
    EXPECT_EQ(s.characterReplacement("AA", 1), 2);
}

TEST(LongestRepeatingCharacterReplacement, TwoCharsDifferent) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("AB", 0), 1); // Can't replace, max is "A" or "B"
    EXPECT_EQ(s.characterReplacement("AB", 1), 2); // Replace A->B or B->A, get "AA" or "BB"
}

// ========== Typical Cases ==========

TEST(LongestRepeatingCharacterReplacement, Example1) {
    Solution s;
    // "ABAB", k=2: Replace 2 A's -> "BBBB" or 2 B's -> "AAAA"
    EXPECT_EQ(s.characterReplacement("ABAB", 2), 4);
}

TEST(LongestRepeatingCharacterReplacement, Example2) {
    Solution s;
    // "AABABBA", k=1: Window "AABBB" at indices 1-5, replace 1 A -> "BBBBB" = 5? No.
    // Let's trace: Best is "AABA" (replace B->A) = 4 or "ABBB" (replace A->B) = 4
    // Actually: "AABBB" has 3 B's and 2 A's, need to replace 2 A's but k=1
    // Window "ABBB" = 3 B's and 1 A, replace 1 A -> 4
    // Window "BBBA" = 3 B's and 1 A, replace 1 A -> 4
    EXPECT_EQ(s.characterReplacement("AABABBA", 1), 4);
}

TEST(LongestRepeatingCharacterReplacement, AllSameChar) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("AAAA", 0), 4);
    EXPECT_EQ(s.characterReplacement("AAAA", 2), 4);
}

TEST(LongestRepeatingCharacterReplacement, AlternatingPattern) {
    Solution s;
    // "ABABAB", k=2: "BABAB" or "ABABA" has 3 of one char, replace 2 -> length 5
    EXPECT_EQ(s.characterReplacement("ABABAB", 2), 5);
}

// ========== Boundary Cases ==========

TEST(LongestRepeatingCharacterReplacement, KZero) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("ABCDE", 0), 1); // No replacements, max is 1
    EXPECT_EQ(s.characterReplacement("AABBC", 0), 2); // Longest is "AA" or "BB"
}

TEST(LongestRepeatingCharacterReplacement, KEqualsLength) {
    Solution s;
    // k = length means we can replace all chars
    EXPECT_EQ(s.characterReplacement("ABCD", 4), 4);
    EXPECT_EQ(s.characterReplacement("ABCDEFGH", 8), 8);
}

TEST(LongestRepeatingCharacterReplacement, KGreaterThanNeeded) {
    Solution s;
    // "AAABBB", k=5: Only need 3 replacements to make all same
    EXPECT_EQ(s.characterReplacement("AAABBB", 5), 6);
}

TEST(LongestRepeatingCharacterReplacement, MinLength) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("A", 0), 1);
    EXPECT_EQ(s.characterReplacement("A", 100), 1);
}

// ========== Window Cases ==========

TEST(LongestRepeatingCharacterReplacement, WindowAtStart) {
    Solution s;
    // "AAABCCC", k=2: Window "AAABC" = 3 A's, replace 2 -> length 5
    EXPECT_EQ(s.characterReplacement("AAABCCC", 2), 5);
}

TEST(LongestRepeatingCharacterReplacement, WindowAtEnd) {
    Solution s;
    // "ABCCCC", k=1: Window "BCCCC" = 4 C's, replace 1 B -> length 5
    EXPECT_EQ(s.characterReplacement("ABCCCC", 1), 5);
}

TEST(LongestRepeatingCharacterReplacement, WindowInMiddle) {
    Solution s;
    // "XXAAAAYY", k=2: Window "AAAAXX" or "YYAAAA" = 4 A's + 2 replacements = 6
    EXPECT_EQ(s.characterReplacement("XXAAAAYY", 2), 6);
}

// ========== Frequency Cases ==========

TEST(LongestRepeatingCharacterReplacement, DominantCharacter) {
    Solution s;
    // "AAAAABC", k=2: 5 A's + replace B,C -> 7
    EXPECT_EQ(s.characterReplacement("AAAAABC", 2), 7);
}

TEST(LongestRepeatingCharacterReplacement, MultipleCharTypes) {
    Solution s;
    // "ABCABC", k=2: Window "ABCA" = 2 A's + 2 others, replace 2 -> length 4
    EXPECT_EQ(s.characterReplacement("ABCABC", 2), 4);
}

TEST(LongestRepeatingCharacterReplacement, ConsecutiveGroups) {
    Solution s;
    // "AABBCC", k=2: Window "AABB" or "BBCC" = 2+2, replace 2 -> length 4
    EXPECT_EQ(s.characterReplacement("AABBCC", 2), 4);
}

// ========== Edge Patterns ==========

TEST(LongestRepeatingCharacterReplacement, AllDifferent) {
    Solution s;
    // "ABCDEF", k=2: Best is 1 + 2 replacements = 3
    EXPECT_EQ(s.characterReplacement("ABCDEF", 2), 3);
}

TEST(LongestRepeatingCharacterReplacement, LongRun) {
    Solution s;
    // "AAAAAAAAB", k=1: 8 A's + 1 B, replace B -> 9
    EXPECT_EQ(s.characterReplacement("AAAAAAAAB", 1), 9);
}

TEST(LongestRepeatingCharacterReplacement, Scattered) {
    Solution s;
    // "ABACABAD", k=3: Find window with most frequent char
    // "ABACABA" = 4 A's + 3 others, replace 3 -> length 7
    EXPECT_EQ(s.characterReplacement("ABACABAD", 3), 7);
}

// ========== Trick Cases ==========

TEST(LongestRepeatingCharacterReplacement, PartialReplacement) {
    Solution s;
    // "AAABAA", k=1: "AAABAA" has 5 A's + 1 B, replace B -> 6
    EXPECT_EQ(s.characterReplacement("AAABAA", 1), 6);
}

TEST(LongestRepeatingCharacterReplacement, NoReplacementNeeded) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("ZZZZZ", 5), 5);
    EXPECT_EQ(s.characterReplacement("QQQQQQQ", 0), 7);
}

TEST(LongestRepeatingCharacterReplacement, MultipleValidWindows) {
    Solution s;
    // "AABBCCDD", k=2: Multiple windows of length 6 possible
    // "AABBCC" = 2+2+2, can make 4 same (2 originals + 2 replacements)
    // "BBCCDD" = same
    EXPECT_EQ(s.characterReplacement("AABBCCDD", 2), 4);
}

TEST(LongestRepeatingCharacterReplacement, HighFrequencyAtEnd) {
    Solution s;
    // "ABCDEEEE", k=2: "CDEEEE" = 4 E's + 2 others, replace 2 -> 6
    EXPECT_EQ(s.characterReplacement("ABCDEEEE", 2), 6);
}

TEST(LongestRepeatingCharacterReplacement, ShrinkBoundary) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("AAAAABBBBCBB", 4), 10);
}

// ========== Performance Cases ==========

TEST(LongestRepeatingCharacterReplacement, MaxLengthDominantChar) {
    Solution s;
    
    // 99900 A's with 100 scattered B's - tests window expansion/shrinking
    string str(99900, 'A');
    for (int i = 1000; i < 100000; i += 1000) {
        if (i < str.size()) str[i] = 'B';
    }
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.characterReplacement(str, 50);
    }, result);
    
    // Can include 50 B's in window with dominant A's
    EXPECT_GE(result, 50000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthDominantChar");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(LongestRepeatingCharacterReplacement, MaxLengthRepeatingPattern) {
    Solution s;
    
    // AABBAABB... pattern - tests window sliding with balanced frequencies
    string str;
    str.reserve(100000);
    for (int i = 0; i < 50000; i++) {
        str += "AABB";
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.characterReplacement(str, 1000);
    }, result);
    
    // With k=1000, can get long window with dominant char + replacements
    EXPECT_GE(result, 2000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthRepeatingPattern");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(LongestRepeatingCharacterReplacement, MaxLengthManyDistinctChars) {
    Solution s;
    
    // Cycling through all 26 letters - worst case for window management
    string str;
    str.reserve(100000);
    for (int i = 0; i < 100000; i++) {
        str += 'A' + (i % 26);
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.characterReplacement(str, 10);
    }, result);
    
    // In ABCDEFG...Z pattern, can get ~26 consecutive + 10 replacements
    EXPECT_GE(result, 11);
    EXPECT_LE(result, 36);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthManyDistinctChars");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(LongestRepeatingCharacterReplacement, MaxLengthInterruptedRuns) {
    Solution s;
    
    // Long runs of A's interrupted by single different chars
    // Tests window expansion with strategic replacements
    string str;
    str.reserve(100000);
    for (int i = 0; i < 10000; i++) {
        str += "AAAAAAAAAB"; // 9 A's, 1 B
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.characterReplacement(str, 500);
    }, result);
    
    // Can span ~500 B's with dominant A's = ~500*10 = 5000+ chars
    EXPECT_GE(result, 5000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthInterruptedRuns");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
