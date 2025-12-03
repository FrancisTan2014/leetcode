// tests/test_0992-subarrays-with-k-different-integers.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

// ========== Base Cases ==========

TEST(SubarraysWithKDifferentIntegers, SingleElement) {
    Solution s;
    EXPECT_EQ(s.subarraysWithKDistinct({1}, 1), 1); // [1]
}

TEST(SubarraysWithKDifferentIntegers, TwoSameElements) {
    Solution s;
    EXPECT_EQ(s.subarraysWithKDistinct({1, 1}, 1), 3); // [1], [1], [1,1]
}

TEST(SubarraysWithKDifferentIntegers, TwoDifferentElements) {
    Solution s;
    // [1,2]: subarrays with exactly 1 distinct: [1], [2] = 2
    EXPECT_EQ(s.subarraysWithKDistinct({1, 2}, 1), 2);
    // [1,2]: subarrays with exactly 2 distinct: [1,2] = 1
    EXPECT_EQ(s.subarraysWithKDistinct({1, 2}, 2), 1);
}

// ========== Typical Cases ==========

TEST(SubarraysWithKDifferentIntegers, Example1) {
    Solution s;
    // [1,2,1,2,3], k=2
    // Subarrays: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,1,2,3}, 2), 7);
}

TEST(SubarraysWithKDifferentIntegers, Example2) {
    Solution s;
    // [1,2,1,3,4], k=3
    // Subarrays: [1,2,1,3], [2,1,3], [1,3,4]
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,1,3,4}, 3), 3);
}

TEST(SubarraysWithKDifferentIntegers, AllSameElements) {
    Solution s;
    // [1,1,1,1], k=1: all subarrays have exactly 1 distinct
    // Count: 1+2+3+4 = 10
    EXPECT_EQ(s.subarraysWithKDistinct({1,1,1,1}, 1), 10);
}

TEST(SubarraysWithKDifferentIntegers, AllDifferentElements) {
    Solution s;
    // [1,2,3,4], k=1: [1], [2], [3], [4] = 4
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3,4}, 1), 4);
    // [1,2,3,4], k=2: [1,2], [2,3], [3,4] = 3
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3,4}, 2), 3);
    // [1,2,3,4], k=4: [1,2,3,4] = 1
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3,4}, 4), 1);
}

// ========== Boundary Cases ==========

TEST(SubarraysWithKDifferentIntegers, KEqualsOne) {
    Solution s;
    // [1,2,2,3,3,3], k=1
    // [1]=1, [2]=1, [2,2]=2, [3]=1, [3,3]=2, [3,3,3]=3
    // Total: 1 + 1 + 2 + 1 + 2 + 3 = 10
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,2,3,3,3}, 1), 10);
}

TEST(SubarraysWithKDifferentIntegers, KEqualsLength) {
    Solution s;
    // [1,2,3], k=3: only [1,2,3] = 1
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3}, 3), 1);
}

TEST(SubarraysWithKDifferentIntegers, KGreaterThanDistinct) {
    Solution s;
    // [1,1,2,2], has 2 distinct but k=3: no valid subarrays
    EXPECT_EQ(s.subarraysWithKDistinct({1,1,2,2}, 3), 0);
}

TEST(SubarraysWithKDifferentIntegers, MinLength) {
    Solution s;
    EXPECT_EQ(s.subarraysWithKDistinct({1}, 1), 1);
    EXPECT_EQ(s.subarraysWithKDistinct({1}, 2), 0);
}

// ========== Pattern Cases ==========

TEST(SubarraysWithKDifferentIntegers, RepeatingPattern) {
    Solution s;
    // [1,2,1,2], k=2
    // Subarrays: [1,2], [1,2,1], [1,2,1,2], [2,1], [2,1,2], [1,2] = 6
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,1,2}, 2), 6);
}

TEST(SubarraysWithKDifferentIntegers, ConsecutiveDuplicates) {
    Solution s;
    // [1,1,2,2,3], k=2
    // With 2 distinct: [1,1,2], [1,1,2,2], [1,2], [1,2,2], [2,2,3], [2,3]
    EXPECT_EQ(s.subarraysWithKDistinct({1,1,2,2,3}, 2), 6);
}

TEST(SubarraysWithKDifferentIntegers, ThreeDistinctElements) {
    Solution s;
    // [1,2,3,2,1], k=3: all 5 elements are needed
    // Subarrays: [1,2,3], [1,2,3,2], [1,2,3,2,1], [2,3,2,1], [3,2,1]
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3,2,1}, 3), 5);
}

// ========== Edge Cases ==========

TEST(SubarraysWithKDifferentIntegers, LongRunSameValue) {
    Solution s;
    // [1,1,1,1,1], k=1: 1+2+3+4+5 = 15
    EXPECT_EQ(s.subarraysWithKDistinct({1,1,1,1,1}, 1), 15);
}

TEST(SubarraysWithKDifferentIntegers, AlternatingTwo) {
    Solution s;
    // [1,2,1,2,1], k=2
    // All subarrays with 2 distinct
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,1,2,1}, 2), 10);
}

TEST(SubarraysWithKDifferentIntegers, LargeValues) {
    Solution s;
    // [100,200,100], k=2
    // [100,200], [100,200,100], [200,100] = 3
    EXPECT_EQ(s.subarraysWithKDistinct({100,200,100}, 2), 3);
}

TEST(SubarraysWithKDifferentIntegers, MaxValue) {
    Solution s;
    // [20000, 20000], k=1
    EXPECT_EQ(s.subarraysWithKDistinct({20000, 20000}, 1), 3);
}

// ========== Trick Cases ==========

TEST(SubarraysWithKDifferentIntegers, SingleDistinctRepeated) {
    Solution s;
    // [5,5,5,5], k=1: 1+2+3+4 = 10
    EXPECT_EQ(s.subarraysWithKDistinct({5,5,5,5}, 1), 10);
}

TEST(SubarraysWithKDifferentIntegers, TwoGroups) {
    Solution s;
    // [1,1,1,2,2,2], k=2
    // Need both 1 and 2: [1,1,2], [1,1,2,2], [1,1,2,2,2], [1,2], [1,2,2], [1,2,2,2], 
    //                    [2,2], [2,2,2] (only 2s, doesn't count)
    // Actually need to recalculate...
    EXPECT_EQ(s.subarraysWithKDistinct({1,1,1,2,2,2}, 2), 9);
}

TEST(SubarraysWithKDifferentIntegers, ComplexPattern) {
    Solution s;
    // [1,2,3,1,2,3], k=3
    // Subarrays: [1,2,3], [1,2,3,1], [1,2,3,1,2], [1,2,3,1,2,3],
    //            [2,3,1], [2,3,1,2], [2,3,1,2,3], [3,1,2], [3,1,2,3], [1,2,3]
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,3,1,2,3}, 3), 10);
}

TEST(SubarraysWithKDifferentIntegers, MixedFrequencies) {
    Solution s;
    // [1,2,2,3,3,3,4], k=2
    EXPECT_EQ(s.subarraysWithKDistinct({1,2,2,3,3,3,4}, 2), 11);
}

// ========== Performance Cases ==========

TEST(SubarraysWithKDifferentIntegers, MaxLengthSingleDistinct) {
    Solution s;
    
    vector<int> nums(20000, 1);
    
    PerformanceMonitor monitor(100.0, 1024); // 100ms, 1MB
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.subarraysWithKDistinct(nums, 1);
    }, result);
    
    // n*(n+1)/2 = 20000*20001/2 = 200,010,000
    EXPECT_EQ(result, 200010000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthSingleDistinct");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SubarraysWithKDifferentIntegers, MaxLengthAllDistinct) {
    Solution s;
    
    vector<int> nums(20000);
    for (int i = 0; i < 20000; i++) {
        nums[i] = i + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.subarraysWithKDistinct(nums, 1000);
    }, result);
    
    // With k=1000, many subarrays with exactly 1000 distinct
    EXPECT_GE(result, 1000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthAllDistinct");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SubarraysWithKDifferentIntegers, MaxLengthRepeatingPattern) {
    Solution s;
    
    // Pattern: 1,2,1,2,1,2,... - only 2 distinct integers
    vector<int> nums(20000);
    for (int i = 0; i < 20000; i++) {
        nums[i] = (i % 2) + 1;
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.subarraysWithKDistinct(nums, 2);
    }, result);
    
    // Most subarrays will have exactly 2 distinct
    EXPECT_GE(result, 19000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthRepeatingPattern");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SubarraysWithKDifferentIntegers, MaxLengthWorstCase) {
    Solution s;
    
    // Many distinct integers with complex overlaps
    vector<int> nums(20000);
    for (int i = 0; i < 20000; i++) {
        nums[i] = (i % 100) + 1; // 100 distinct values repeated
    }
    
    PerformanceMonitor monitor(100.0, 1024);
    int result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.subarraysWithKDistinct(nums, 10);
    }, result);
    
    EXPECT_GE(result, 1000);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "MaxLengthWorstCase");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
