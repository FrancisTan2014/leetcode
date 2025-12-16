#include <gtest/gtest.h>
#include <performance.h>
#include <algorithm>
#include <vector>
#include "../solution.cpp"

using namespace std;
using namespace leetcode;

// Helper to sort combinations for comparison
void sortCombinations(vector<vector<int>>& combinations) {
    for (auto& combo : combinations) {
        sort(combo.begin(), combo.end());
    }
    sort(combinations.begin(), combinations.end());
}

class LC39_CombinationSum : public ::testing::Test {
protected:
    Solution s;
};

// Official Examples
TEST_F(LC39_CombinationSum, Example1) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{2, 2, 3}, {7}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC39_CombinationSum, Example2) {
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC39_CombinationSum, Example3_NoSolution) {
    vector<int> candidates = {2};
    int target = 1;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    EXPECT_TRUE(result.empty());
}

// Edge Cases
TEST_F(LC39_CombinationSum, SingleCandidateExactMatch) {
    vector<int> candidates = {5};
    int target = 5;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{5}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC39_CombinationSum, SingleCandidateMultipleTimes) {
    vector<int> candidates = {3};
    int target = 9;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{3, 3, 3}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC39_CombinationSum, SingleCandidateNotDivisible) {
    vector<int> candidates = {3};
    int target = 10;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    EXPECT_TRUE(result.empty());
}

TEST_F(LC39_CombinationSum, AllCandidatesLargerThanTarget) {
    vector<int> candidates = {10, 20, 30};
    int target = 5;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    EXPECT_TRUE(result.empty());
}

TEST_F(LC39_CombinationSum, TargetIsOne) {
    vector<int> candidates = {2, 3, 5};
    int target = 1;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    EXPECT_TRUE(result.empty());
}

// Multiple Solutions with Varying Lengths
TEST_F(LC39_CombinationSum, MultipleSolutionsVaryingLengths) {
    vector<int> candidates = {2, 3, 4};
    int target = 6;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{2, 2, 2}, {2, 4}, {3, 3}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Only One Way with Multiple Uses
TEST_F(LC39_CombinationSum, OnlyRepeatedUse) {
    vector<int> candidates = {4};
    int target = 12;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{4, 4, 4}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Large Candidate Values
TEST_F(LC39_CombinationSum, LargeCandidateValues) {
    vector<int> candidates = {30, 40};
    int target = 70;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{30, 40}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Multiple Candidates, Target Equals One Candidate
TEST_F(LC39_CombinationSum, TargetEqualsOneCandidate) {
    vector<int> candidates = {2, 3, 5, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{2, 2, 3}, {2, 5}, {7}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Complex Case with Many Combinations
TEST_F(LC39_CombinationSum, ManyCombinations) {
    vector<int> candidates = {2, 3, 5};
    int target = 10;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {
        {2, 2, 2, 2, 2},
        {2, 2, 3, 3},
        {2, 3, 5},
        {5, 5}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Prime Number Target with Mixed Candidates
TEST_F(LC39_CombinationSum, PrimeTarget) {
    vector<int> candidates = {2, 3, 5, 7};
    int target = 11;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {
        {2, 2, 2, 2, 3},
        {2, 2, 2, 5},
        {2, 2, 7},
        {2, 3, 3, 3},
        {3, 3, 5}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Larger Target with Small Candidates
TEST_F(LC39_CombinationSum, LargerTargetSmallCandidates) {
    vector<int> candidates = {2, 3};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    vector<vector<int>> expected = {{2, 2, 3}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Maximum Constraint Test (smaller version for practicality)
TEST_F(LC39_CombinationSum, LargerCandidateSet) {
    vector<int> candidates = {2, 3, 5, 7, 11};
    int target = 13;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    // Expected combinations sum to 13
    vector<vector<int>> expected = {
        {2, 2, 2, 2, 2, 3},
        {2, 2, 2, 2, 5},
        {2, 2, 2, 7},
        {2, 2, 3, 3, 3},
        {2, 3, 3, 5},
        {2, 11},
        {3, 3, 7},
        {3, 5, 5}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Regression: LeetCode reported time/memory limitation case 1
TEST_F(LC39_CombinationSum, Regression_LeetCode_TimeLimit_Case1) {
    vector<int> candidates = {10,17,15,18,16,31,22,25,20,23,30,12,19,38,36,26,40,32,34,13,35,29,39,14,11,27};
    int target = 31;
    
    // Measure performance with LeetCode-realistic limits: 1000ms, 50MB
    PerformanceMonitor monitor(1000.0, 50 * 1024);
    vector<vector<int>> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.combinationSum(candidates, target);
    }, result);
    
    // Record performance metrics
    RECORD_PERFORMANCE_PROPERTY(metrics, "Regression_LeetCode_TimeLimit_Case1");
    EXPECT_PERFORMANCE(metrics, 1000.0, 50 * 1024);
    
    // Should find exactly 7 combinations
    EXPECT_EQ(result.size(), 7);
    
    // Verify a few known combinations exist
    vector<vector<int>> expected = {
        {10, 10, 11},
        {11, 20},
        {12, 19},
        {13, 18},
        {14, 17},
        {15, 16},
        {31}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Regression: LeetCode reported time/memory limitation case 2
TEST_F(LC39_CombinationSum, Regression_LeetCode_TimeLimit_Case2) {
    vector<int> candidates = {2,22,4,17,28,13,39,27,24,37,12,30,5,23,29,8,16,34,15,36,14,10,31};
    int target = 30;
    
    // Measure performance with LeetCode-realistic limits: 1000ms, 50MB
    PerformanceMonitor monitor(1000.0, 50 * 1024);
    vector<vector<int>> result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.combinationSum(candidates, target);
    }, result);
    
    // Record performance metrics
    RECORD_PERFORMANCE_PROPERTY(metrics, "Regression_LeetCode_TimeLimit_Case2");
    EXPECT_PERFORMANCE(metrics, 1000.0, 50 * 1024);
    
    // Should find exactly 140 combinations (many due to small candidate 2)
    EXPECT_EQ(result.size(), 140);
    
    // Verify it contains some known combinations
    sortCombinations(result);
    
    // Check for single element solution
    bool found_single = false;
    for (const auto& combo : result) {
        if (combo.size() == 1 && combo[0] == 30) {
            found_single = true;
            break;
        }
    }
    EXPECT_TRUE(found_single);
    
    // Verify all combinations sum to target
    for (const auto& combo : result) {
        int sum = 0;
        for (int num : combo) {
            sum += num;
        }
        EXPECT_EQ(sum, target);
    }
}
