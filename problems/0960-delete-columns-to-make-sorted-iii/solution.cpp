#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

/**
 * DP pattern
 */
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int cols = strs[0].length();
    vector<int> dp(cols);
    for (int i = 0; i < cols; i++) {
      dp[i] = 1; // At minimum, keep just column i by itself

      for (int j = 0; j < i; j++) {
        if (canFollow(strs, j, i)) {
          // Can we extend the subsequence ending at j by adding column i?
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
    }

    int maxDp = *std::max_element(dp.begin(), dp.end());
    return cols - maxDp;
  }

 private:
  bool canFollow(const vector<string>& strs, int col1, int col2) {
    for (const string& s : strs) {
      if (s[col1] > s[col2]) return false;
    }
    return true;
  }
};
