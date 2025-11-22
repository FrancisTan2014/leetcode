// tests/test_SimplifyPath.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;
using namespace std;

TEST(SimplifyPath, SampleTest) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/home/"), "/home");
}

TEST(SimplifyPath, SingleSlash) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/"), "/");
}

TEST(SimplifyPath, ParentAtBeginning) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/../"), "/");
}

TEST(SimplifyPath, TrimEndSlash) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/home/foo/"), "/home/foo");
}

TEST(SimplifyPath, ComplexNavigation) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/a/./b/../../c/"), "/c");
}

TEST(SimplifyPath, TripleDotsDirectory) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/a/.../b/.."), "/a/...");
}

TEST(SimplifyPath, MultipleSlashes) {
    Solution s;
    EXPECT_EQ(s.simplifyPath("/a//b////c"), "/a/b/c");
}

TEST(SimplifyPath, Performance) {
    Solution s;
    
    // Setup worst-case scenario: maximum length path (3000 chars) with complex navigation
    // This tests the algorithm's ability to handle:
    // - Maximum constraint (3000 chars)
    // - Heavy use of .. (parent directory navigation requiring stack operations)
    // - Multiple consecutive slashes
    // - Mix of ., .., and valid directories
    string longPath = "/";
    
    // Build a deeply nested path then navigate up/down repeatedly
    // Pattern: /dir0/dir1/.../dirN/../../dir/../../... (worst case for stack-based solutions)
    int segmentCount = 0;
    while (longPath.length() < 2800) {  // Leave room for final segments
        longPath += "d" + to_string(segmentCount++) + "/";
        // Add navigation complexity every few segments
        if (segmentCount % 3 == 0) longPath += "../";
        if (segmentCount % 5 == 0) longPath += "././";
        if (segmentCount % 7 == 0) longPath += "//";
    }
    
    // Fill remaining space with edge cases
    while (longPath.length() < 3000) {
        longPath += ".../"; // Valid directory name (3+ periods)
    }
    
    // Ensure exactly at constraint boundary
    longPath = longPath.substr(0, 3000);
    
    // Measure performance on single execution (constraint: 3000 char path)
    PerformanceMonitor monitor(5.0, 512); // 5ms, 512KB reasonable for string operations
    string result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.simplifyPath(longPath);
    }, result);
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthPath3000");
    EXPECT_PERFORMANCE(metrics, 5.0, 512);
    
    // Verify result is valid simplified path
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result[0], '/');
    // Should not end with '/' unless it's root
    if (result.length() > 1) {
        EXPECT_NE(result[result.length() - 1], '/');
    }
}
