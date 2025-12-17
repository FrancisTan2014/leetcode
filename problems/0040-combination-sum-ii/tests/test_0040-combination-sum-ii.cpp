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

class LC40_CombinationSumII : public ::testing::Test {
protected:
    Solution s;
};

// Official Examples
TEST_F(LC40_CombinationSumII, Example1) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC40_CombinationSumII, Example2) {
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{1, 2, 2}, {5}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Edge Cases
TEST_F(LC40_CombinationSumII, SingleElementExactMatch) {
    vector<int> candidates = {5};
    int target = 5;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{5}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC40_CombinationSumII, SingleElementNoMatch) {
    vector<int> candidates = {3};
    int target = 5;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    EXPECT_TRUE(result.empty());
}

TEST_F(LC40_CombinationSumII, AllElementsSame_ExactDivide) {
    vector<int> candidates = {2, 2, 2, 2};
    int target = 6;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{2, 2, 2}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC40_CombinationSumII, AllElementsSame_NoSolution) {
    vector<int> candidates = {2, 2, 2, 2};
    int target = 5;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    EXPECT_TRUE(result.empty());
}

TEST_F(LC40_CombinationSumII, AllTooLarge) {
    vector<int> candidates = {10, 20, 30};
    int target = 5;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    EXPECT_TRUE(result.empty());
}

// Duplicate Handling
TEST_F(LC40_CombinationSumII, MultipleDuplicates) {
    vector<int> candidates = {1, 1, 1, 1, 1};
    int target = 3;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{1, 1, 1}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC40_CombinationSumII, DuplicatesAtDifferentPositions) {
    vector<int> candidates = {1, 2, 1, 2, 1};
    int target = 4;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{1, 1, 2}, {2, 2}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

TEST_F(LC40_CombinationSumII, ManyDuplicatesMultipleSolutions) {
    vector<int> candidates = {4, 4, 2, 1, 4, 2, 2, 1, 3};
    int target = 6;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {
        {1, 1, 2, 2},
        {1, 1, 4},
        {1, 2, 3},
        {2, 2, 2},
        {2, 4}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Multiple Solutions
TEST_F(LC40_CombinationSumII, MultipleSolutionsVaryingLengths) {
    vector<int> candidates = {1, 2, 3, 4, 5};
    int target = 7;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {
        {1, 2, 4},
        {2, 5},
        {3, 4}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Target Equals One Element
TEST_F(LC40_CombinationSumII, TargetEqualsMultipleElements) {
    vector<int> candidates = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {
        {1, 2, 4},
        {1, 6},
        {2, 5},
        {3, 4},
        {7}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Large Input
TEST_F(LC40_CombinationSumII, LargerArray) {
    vector<int> candidates = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 10;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    // Multiple valid combinations exist
    EXPECT_GT(result.size(), 0);
    
    // Verify all combinations sum to target
    for (const auto& combo : result) {
        int sum = 0;
        for (int num : combo) {
            sum += num;
        }
        EXPECT_EQ(sum, target);
    }
}

// Minimum Target
TEST_F(LC40_CombinationSumII, TargetIsOne) {
    vector<int> candidates = {1, 2, 3};
    int target = 1;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {{1}};
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Complex Duplicates Pattern
TEST_F(LC40_CombinationSumII, ComplexDuplicatePattern) {
    vector<int> candidates = {3, 1, 3, 5, 1, 1};
    int target = 8;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    vector<vector<int>> expected = {
        {1, 1, 1, 5},
        {1, 1, 3, 3},
        {3, 5}
    };
    
    sortCombinations(result);
    sortCombinations(expected);
    EXPECT_EQ(result, expected);
}

// Maximum Constraints Test
TEST_F(LC40_CombinationSumII, LargeInputWithDuplicates) {
    vector<int> candidates = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    int target = 10;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    
    EXPECT_GT(result.size(), 0);
    
    // Verify no duplicate combinations
    set<vector<int>> uniqueCombos;
    for (auto combo : result) {
        sort(combo.begin(), combo.end());
        EXPECT_EQ(uniqueCombos.count(combo), 0) << "Found duplicate combination";
        uniqueCombos.insert(combo);
    }
    
    // Verify all combinations sum to target
    for (const auto& combo : result) {
        int sum = 0;
        for (int num : combo) {
            sum += num;
        }
        EXPECT_EQ(sum, target);
    }
}
