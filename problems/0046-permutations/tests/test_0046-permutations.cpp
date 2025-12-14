// tests/test_0046-permutations.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"
#include <algorithm>
#include <set>

using namespace std;
using namespace leetcode;

// Helper to sort permutations for comparison
vector<vector<int>> sortPermutations(vector<vector<int>> perms) {
    for (auto& perm : perms) {
        sort(perm.begin(), perm.end());
    }
    sort(perms.begin(), perms.end());
    return perms;
}

class LC46_Permutations : public ::testing::Test {
protected:
    Solution s;
};

// Official Examples
TEST_F(LC46_Permutations, Example1) {
    vector<int> nums = {1, 2, 3};
    auto result = s.permute(nums);
    auto expected = vector<vector<int>>{
        {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
    };
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

TEST_F(LC46_Permutations, Example2) {
    vector<int> nums = {0, 1};
    auto result = s.permute(nums);
    auto expected = vector<vector<int>>{{0,1}, {1,0}};
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

TEST_F(LC46_Permutations, Example3) {
    vector<int> nums = {1};
    auto result = s.permute(nums);
    auto expected = vector<vector<int>>{{1}};
    EXPECT_EQ(result, expected);
}

// Edge Cases
TEST_F(LC46_Permutations, SingleElement) {
    vector<int> nums = {5};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], vector<int>{5});
}

TEST_F(LC46_Permutations, TwoElements) {
    vector<int> nums = {3, 7};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 2);
    auto expected = vector<vector<int>>{{3,7}, {7,3}};
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

// Negative Numbers
TEST_F(LC46_Permutations, WithNegativeNumbers) {
    vector<int> nums = {-1, 0, 1};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
    auto expected = vector<vector<int>>{
        {-1,0,1}, {-1,1,0}, {0,-1,1}, {0,1,-1}, {1,-1,0}, {1,0,-1}
    };
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

TEST_F(LC46_Permutations, AllNegative) {
    vector<int> nums = {-3, -2, -1};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
    auto expected = vector<vector<int>>{
        {-3,-2,-1}, {-3,-1,-2}, {-2,-3,-1}, {-2,-1,-3}, {-1,-3,-2}, {-1,-2,-3}
    };
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

// Size Variations
TEST_F(LC46_Permutations, FourElements) {
    vector<int> nums = {1, 2, 3, 4};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 24); // 4! = 24
    
    // Verify all permutations are unique
    set<vector<int>> uniquePerms(result.begin(), result.end());
    EXPECT_EQ(uniquePerms.size(), 24);
    
    // Verify each permutation contains the same elements
    for (const auto& perm : result) {
        auto sorted = perm;
        sort(sorted.begin(), sorted.end());
        EXPECT_EQ(sorted, vector<int>({1, 2, 3, 4}));
    }
}

TEST_F(LC46_Permutations, FiveElements) {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 120); // 5! = 120
    
    // Verify all permutations are unique
    set<vector<int>> uniquePerms(result.begin(), result.end());
    EXPECT_EQ(uniquePerms.size(), 120);
}

TEST_F(LC46_Permutations, MaxSize_SixElements) {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 720); // 6! = 720
    
    // Verify all permutations are unique
    set<vector<int>> uniquePerms(result.begin(), result.end());
    EXPECT_EQ(uniquePerms.size(), 720);
    
    // Verify each permutation contains the same elements
    for (const auto& perm : result) {
        EXPECT_EQ(perm.size(), 6);
        auto sorted = perm;
        sort(sorted.begin(), sorted.end());
        EXPECT_EQ(sorted, vector<int>({1, 2, 3, 4, 5, 6}));
    }
}

// Special Value Patterns
TEST_F(LC46_Permutations, WithZero) {
    vector<int> nums = {0, 1, 2};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
    
    // Verify all permutations contain 0, 1, 2
    for (const auto& perm : result) {
        auto sorted = perm;
        sort(sorted.begin(), sorted.end());
        EXPECT_EQ(sorted, vector<int>({0, 1, 2}));
    }
}

TEST_F(LC46_Permutations, BoundaryValues) {
    vector<int> nums = {-10, 0, 10};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
    
    auto expected = vector<vector<int>>{
        {-10,0,10}, {-10,10,0}, {0,-10,10}, {0,10,-10}, {10,-10,0}, {10,0,-10}
    };
    EXPECT_EQ(sortPermutations(result), sortPermutations(expected));
}

// Non-sequential Numbers
TEST_F(LC46_Permutations, NonSequential) {
    vector<int> nums = {5, 15, 25};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
    
    // Verify each permutation has the correct elements
    for (const auto& perm : result) {
        auto sorted = perm;
        sort(sorted.begin(), sorted.end());
        EXPECT_EQ(sorted, vector<int>({5, 15, 25}));
    }
}

TEST_F(LC46_Permutations, LargeGaps) {
    vector<int> nums = {-100, 0, 100};
    auto result = s.permute(nums);
    EXPECT_EQ(result.size(), 6);
}

// Verify Complete Coverage (spot check some specific permutations)
TEST_F(LC46_Permutations, VerifySpecificPermutations) {
    vector<int> nums = {1, 2, 3};
    auto result = s.permute(nums);
    
    // Convert to set for easy lookup
    set<vector<int>> permSet(result.begin(), result.end());
    
    // Check that specific permutations exist
    EXPECT_TRUE(permSet.count({1, 2, 3}));
    EXPECT_TRUE(permSet.count({1, 3, 2}));
    EXPECT_TRUE(permSet.count({2, 1, 3}));
    EXPECT_TRUE(permSet.count({2, 3, 1}));
    EXPECT_TRUE(permSet.count({3, 1, 2}));
    EXPECT_TRUE(permSet.count({3, 2, 1}));
}

TEST(LC46_Permutations_Performance, Performance) {
    Solution s;
    
    // Max size test case (6 elements)
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    
    // Measure performance
    PerformanceMonitor monitor(1000.0, 10 * 1024); // 1s, 10MB limits
    auto metrics = monitor.measure([&]() {
        s.permute(nums);
    });
    
    // Record performance for CTest reporting
    RECORD_PERFORMANCE_PROPERTY(metrics, "0046-permutations");
    EXPECT_PERFORMANCE(metrics, 1000.0, 10 * 1024);
}
