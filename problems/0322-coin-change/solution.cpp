#include <vector>

using std::vector;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int a = 1; a <= amount; a++) {
      for (int c : coins) {
        if (a-c >= 0) {
          dp[a] = std::min(dp[a], dp[a-c] + 1);
        }
      }
    }

    int count = dp[amount];
    if (count > amount) {
      return -1;
    }

    return count;
  }

 private:
  void bruteForce_backtracking(vector<int>& coins, 
                               int amount, 
                               int index, 
                               vector<int>& current_path, 
                               int& count) {
    if (amount == 0) {
      count = std::min(count, static_cast<int>(current_path.size()));
      return;
    }

    if (index == coins.size() || amount < 0) {
      return;
    }

    current_path.push_back(coins[index]);
    bruteForce_backtracking(coins, amount - coins[index], index, current_path, count);
    current_path.pop_back();

    bruteForce_backtracking(coins, amount, index + 1, current_path, count);
  }
};
