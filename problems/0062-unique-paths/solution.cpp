#include <vector>

using std::vector;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> row(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        row[j] = row[j] + row[j-1];
      }
    }

    return row[n-1];
  }

 private:
  int uniquePaths_2dArray(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    }

    return dp[m-1][n-1];
  }

  int uniquePaths_bruteForce(int m, int n) {
    if (m == 1 || n == 1) return 1;
    if (m == 2) return n;
    if (n == 2) return m;

    return uniquePaths_bruteForce(m - 1, n) + 
        uniquePaths_bruteForce(m, n - 1);
  }
};
