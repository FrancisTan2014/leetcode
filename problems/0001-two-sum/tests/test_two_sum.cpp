// tests/test_two_sum.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"
#include <vector>
using namespace std;

TEST(TwoSum, Basic) {
    Solution s;
    vector<int> nums = {2,7,11,15};
    auto out = s.twoSum(nums, 9);
    ASSERT_EQ(out.size(), 2);
    EXPECT_EQ(out[0], 0);
    EXPECT_EQ(out[1], 1);
}

TEST(TwoSum, NoSolution) {
    Solution s;
    vector<int> nums = {1,2,3};
    auto out = s.twoSum(nums, 7);
    EXPECT_TRUE(out.empty());
}
