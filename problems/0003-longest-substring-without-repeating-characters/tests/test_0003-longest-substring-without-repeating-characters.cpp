// tests/test_0003-longest-substring-without-repeating-characters.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

TEST(LongestSubstring, Basic) {
    Solution s;
    string input = "abcabcbb";
    int output = s.lengthOfLongestSubstring(input);
    EXPECT_EQ(output, 3); // "abc"
}

TEST(LongestSubstring, LargeString) {
    Solution s;
    
    // Create a large test case with a string of length 5 * 104
    const int length = 5 * 104;
    string input;
    input.reserve(length);
    
    // Generate a string with repeating pattern of printable ASCII characters
    for (int i = 0; i < length; ++i) {
        input += char('a' + (i % 26));
    }
    
    // Measure performance
    PerformanceMonitor monitor(1.0, 1);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.lengthOfLongestSubstring(input);
    }, result);
    
    // Verify correctness - should find all 26 unique characters
    EXPECT_EQ(result, 26);
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "LargeString");
    EXPECT_PERFORMANCE(metrics, 1.0, 1);
}
