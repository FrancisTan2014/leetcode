// tests/test_0567-permutation-in-string.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

TEST(PermutationInString, SampleTest) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "eidbaooo"));
}

TEST(PermutationInString, NoPermutaionsFound) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("ab", "eidboaoo"));
}

TEST(PermutationInString, OneLetterSource_Found) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("a", "bacd"));
}

TEST(PermutationInString, OneLetterSource_NotFound) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("a", "bcde"));
}

TEST(PermutationInString, BothOneLetter_Found) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("a", "a"));
}

TEST(PermutationInString, BothOneLetter_NotFound) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("a", "b"));
}

TEST(PermutationInString, TwoSameLetters_Found) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("aa", "cbaadc"));
}

TEST(PermutationInString, TwoSameLetters_NotFound) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("aa", "cbadac"));
}

TEST(PermutationInString, ComplextPermutation_Distinct) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("abcdefg", "arbitraygefcdabrandom"));
}

TEST(PermutationInString, ComplextPermutation_Duplicate) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("abccdefg", "arbitraycgfedbcarandom"));
}

TEST(PermutationInString, TargetIsShorterThanSource) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("abc", "ab"));
}

// ========== The following cases are designed by AI ==========

// ========== Boundary Cases ==========

TEST(PermutationInString, EqualLength_SameContent) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("abc", "abc"));
    EXPECT_TRUE(s.checkInclusion("abc", "bca"));
}

TEST(PermutationInString, EqualLength_DifferentContent) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("abc", "def"));
    EXPECT_FALSE(s.checkInclusion("abc", "abd"));
}

TEST(PermutationInString, PermutationAtStart) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "baxyz"));
    EXPECT_TRUE(s.checkInclusion("abc", "cbaxyz"));
}

TEST(PermutationInString, PermutationAtEnd) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "xyzba"));
    EXPECT_TRUE(s.checkInclusion("abc", "xyzbca"));
}

// ========== Frequency/Count Edge Cases ==========

TEST(PermutationInString, ExcessCharsInS2) {
    Solution s;
    // s2 has excess chars but windows can still contain valid permutations
    EXPECT_TRUE(s.checkInclusion("ab", "aaaabc"));  // "bc" at end is permutation of "ab"
    EXPECT_FALSE(s.checkInclusion("abc", "aabbcc")); // All windows: aab,abb,bbc,bcc - none match 1a,1b,1c
    EXPECT_TRUE(s.checkInclusion("abc", "aabcde")); // "abc" exists
}

TEST(PermutationInString, PartialMatchThatSucceeds) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("aab", "aaab"));  // Contains "aab"
    EXPECT_TRUE(s.checkInclusion("aab", "aabb"));  // Contains "aab" or "aba"
    EXPECT_TRUE(s.checkInclusion("aab", "baaaa")); // Contains "aab"
}

TEST(PermutationInString, OffByOneCharCount) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("aab", "aac"));  // Wrong char, not enough 'b'
    EXPECT_FALSE(s.checkInclusion("aab", "abb"));  // Not enough 'a'
    EXPECT_TRUE(s.checkInclusion("aab", "aaaab")); // Contains "aab"
}

TEST(PermutationInString, AlmostPermutation_MissingOneChar) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("abc", "abx")); // 'x' instead of 'c'
    EXPECT_FALSE(s.checkInclusion("abc", "ab"));  // Missing 'c'
}

// ========== Pattern Cases ==========

TEST(PermutationInString, AllSameCharacter) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("aaa", "aaaaa"));  // Has enough 'a's
    EXPECT_FALSE(s.checkInclusion("aaa", "aa"));    // Not enough 'a's
    EXPECT_TRUE(s.checkInclusion("aaa", "baaaac")); // Contains "aaa"
}

TEST(PermutationInString, PermutationAppearsMultipleTimes) {
    Solution s;
    // "ba" appears at positions 0-1, 2-3, 4-5
    EXPECT_TRUE(s.checkInclusion("ab", "baabba"));
    // "abc" permutations appear multiple times
    EXPECT_TRUE(s.checkInclusion("abc", "cabcbaacb"));
}

TEST(PermutationInString, LongRepeatingPattern) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("aaab", "aaaaaab"));  // Contains "aaab"
    EXPECT_FALSE(s.checkInclusion("aaab", "aaaaaa")); // Missing 'b'
}

// ========== Window Sliding Edge Cases ==========

TEST(PermutationInString, OverlappingCandidates) {
    Solution s;
    // Multiple potential permutations overlap
    EXPECT_TRUE(s.checkInclusion("abc", "cbaebabacd"));
    EXPECT_TRUE(s.checkInclusion("ab", "ababab"));
}

TEST(PermutationInString, RequiresFullWindowSlide) {
    Solution s;
    // Need to slide window all the way to the end
    EXPECT_TRUE(s.checkInclusion("abc", "zzzzzzzcba"));
    EXPECT_FALSE(s.checkInclusion("abc", "zzzzzzzcb")); // Incomplete at end
}

TEST(PermutationInString, CharactersBetweenMatches) {
    Solution s;
    // Characters split across non-contiguous positions
    EXPECT_FALSE(s.checkInclusion("abc", "azbzcz")); // Windows: azb,zbz,bzc,zcz - no match
    EXPECT_TRUE(s.checkInclusion("abc", "xyzabcxyz")); // "abc" exists in middle
}

// ========== Performance Cases ==========

TEST(PermutationInString, MaxLengthBothStrings) {
    Solution s;
    
    // Max length: s1 and s2 both 10^4 chars
    string s1(10000, 'a');
    string s2(10000, 'a');
    
    PerformanceMonitor monitor(50.0, 1024); // 50ms, 1MB
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.checkInclusion(s1, s2);
    }, result);
    
    EXPECT_TRUE(result); // s2 is exactly s1
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthExactMatch");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(PermutationInString, MaxLengthWorstCase) {
    Solution s;
    
    // Worst case: s1 at the very end of s2
    string s1(100, 'a');
    string s2;
    s2.reserve(10000);
    // Fill with 'b' except last 100 chars
    for (int i = 0; i < 9900; i++) {
        s2 += 'b';
    }
    for (int i = 0; i < 100; i++) {
        s2 += 'a';
    }
    
    PerformanceMonitor monitor(50.0, 1024);
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.checkInclusion(s1, s2);
    }, result);
    
    EXPECT_TRUE(result); // Found at the end
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "WorstCaseEndMatch");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(PermutationInString, MaxLengthNoMatch) {
    Solution s;
    
    // s1 has 'z', s2 has no 'z' - should quickly determine no match possible
    string s1(100, 'a');
    s1[50] = 'z'; // Add one 'z'
    string s2(10000, 'a'); // All 'a', no 'z'
    
    PerformanceMonitor monitor(50.0, 1024);
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.checkInclusion(s1, s2);
    }, result);
    
    EXPECT_FALSE(result); // No 'z' in s2
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthNoMatch");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}

TEST(PermutationInString, MaxLengthAlternatingPattern) {
    Solution s;
    
    // Alternating pattern that requires many window slides
    string s1 = "abcdefghij"; // 10 distinct chars
    string s2;
    s2.reserve(10000);
    // Pattern that never quite matches until the end
    for (int i = 0; i < 999; i++) {
        s2 += "abcdefghi"; // Missing 'j'
    }
    s2 += "jihgfedcba"; // Finally a permutation
    
    PerformanceMonitor monitor(50.0, 1024);
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.checkInclusion(s1, s2);
    }, result);
    
    EXPECT_TRUE(result); // Found at the end
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "AlternatingPattern");
    EXPECT_PERFORMANCE(metrics, 50.0, 1024);
}
