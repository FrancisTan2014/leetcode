// tests/test_0322-coin-change.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Example 1: coins = [1,2,5], amount = 11
TEST(CoinChange, Example1) {
  Solution s;
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(s.coinChange(coins, 11), 3);
}

// Example 2: coins = [2], amount = 3
TEST(CoinChange, Example2) {
  Solution s;
  std::vector<int> coins = {2};
  EXPECT_EQ(s.coinChange(coins, 3), -1);
}

// Example 3: coins = [1], amount = 0
TEST(CoinChange, Example3) {
  Solution s;
  std::vector<int> coins = {1};
  EXPECT_EQ(s.coinChange(coins, 0), 0);
}

// Single coin, exact match
TEST(CoinChange, SingleCoinExactMatch) {
  Solution s;
  std::vector<int> coins = {5};
  EXPECT_EQ(s.coinChange(coins, 5), 1);
}

// Single coin, multiple needed
TEST(CoinChange, SingleCoinMultiple) {
  Solution s;
  std::vector<int> coins = {1};
  EXPECT_EQ(s.coinChange(coins, 10), 10);
}

// Single coin, impossible
TEST(CoinChange, SingleCoinImpossible) {
  Solution s;
  std::vector<int> coins = {2};
  EXPECT_EQ(s.coinChange(coins, 3), -1);
}

// Coin larger than amount
TEST(CoinChange, CoinLargerThanAmount) {
  Solution s;
  std::vector<int> coins = {10};
  EXPECT_EQ(s.coinChange(coins, 5), -1);
}

// Multiple coins, all larger than amount
TEST(CoinChange, AllCoinsLarger) {
  Solution s;
  std::vector<int> coins = {5, 10, 25};
  EXPECT_EQ(s.coinChange(coins, 3), -1);
}

// Greedy fails case: coins=[1,3,4], amount=6
TEST(CoinChange, GreedyFails) {
  Solution s;
  std::vector<int> coins = {1, 3, 4};
  // Greedy would use 4+1+1=3, but optimal is 3+3=2
  EXPECT_EQ(s.coinChange(coins, 6), 2);
}

// Standard US coins
TEST(CoinChange, USCoins) {
  Solution s;
  std::vector<int> coins = {1, 5, 10, 25};
  EXPECT_EQ(s.coinChange(coins, 41), 4); // 25+10+5+1
}

// Two coins, various amounts
TEST(CoinChange, TwoCoins) {
  Solution s;
  std::vector<int> coins = {1, 3};
  EXPECT_EQ(s.coinChange(coins, 5), 3); // 3+1+1
}

// Large amount with small coins
TEST(CoinChange, LargeAmount) {
  Solution s;
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(s.coinChange(coins, 100), 20); // 20 coins of 5
}

// Amount = 1
TEST(CoinChange, AmountOne) {
  Solution s;
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(s.coinChange(coins, 1), 1);
}

// Many coins, small amount
TEST(CoinChange, ManyCoinsSmallAmount) {
  Solution s;
  std::vector<int> coins = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(s.coinChange(coins, 15), 2); // 10+5
}

// Prime number amount
TEST(CoinChange, PrimeAmount) {
  Solution s;
  std::vector<int> coins = {2, 5};
  EXPECT_EQ(s.coinChange(coins, 11), 4); // 5+5+1? No 1, so 5+2+2+2
}

// Actually for prime 11 with [2,5]: 5+2+2+2=4 coins
TEST(CoinChange, PrimeAmount11) {
  Solution s;
  std::vector<int> coins = {2, 5};
  EXPECT_EQ(s.coinChange(coins, 11), 4); // 5+2+2+2
}

// Large coins
TEST(CoinChange, LargeCoins) {
  Solution s;
  std::vector<int> coins = {100, 200, 500};
  EXPECT_EQ(s.coinChange(coins, 1000), 2); // 500+500
}

// Consecutive coins
TEST(CoinChange, ConsecutiveCoins) {
  Solution s;
  std::vector<int> coins = {1, 2, 3};
  EXPECT_EQ(s.coinChange(coins, 7), 3); // 3+3+1 or 3+2+2
}

// Powers of 2
TEST(CoinChange, PowersOfTwo) {
  Solution s;
  std::vector<int> coins = {1, 2, 4, 8, 16};
  EXPECT_EQ(s.coinChange(coins, 31), 5); // 16+8+4+2+1
}

// Amount that requires specific combination
TEST(CoinChange, SpecificCombination) {
  Solution s;
  std::vector<int> coins = {3, 5};
  EXPECT_EQ(s.coinChange(coins, 9), 3); // 3+3+3
}

// Amount impossible with given coins
TEST(CoinChange, ImpossibleCombination) {
  Solution s;
  std::vector<int> coins = {3, 5};
  EXPECT_EQ(s.coinChange(coins, 1), -1);
}

// Maximum amount constraint
TEST(CoinChange, MaxAmount) {
  Solution s;
  std::vector<int> coins = {1, 5, 10, 25, 100};
  EXPECT_EQ(s.coinChange(coins, 10000), 100); // 100 coins of 100
}

// Coins in descending order
TEST(CoinChange, DescendingOrder) {
  Solution s;
  std::vector<int> coins = {25, 10, 5, 1};
  EXPECT_EQ(s.coinChange(coins, 41), 4); // 25+10+5+1
}

// Duplicate coin values shouldn't matter
TEST(CoinChange, WithOne) {
  Solution s;
  std::vector<int> coins = {1, 2, 3, 4, 5};
  EXPECT_EQ(s.coinChange(coins, 11), 3); // 5+5+1
}
