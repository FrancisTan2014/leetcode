#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

class Solution {
  static constexpr int MOD = 1e9 + 7;
  static constexpr long Combination(int n) {
    return (long)n * (n - 1) / 2;
  }

 public:
  int countTrapezoids(vector<vector<int>>& points) {
    // Step 1: group points by y, note that we don't need the point, we just need the count
    std::unordered_map<int, int> groups;
    for (const auto& p : points) {
      ++groups[p[1]];
    }

    // Step 2: Use mathematical formula to avoid O(k^2) nested loop
    // sum_{i<j} C(n_i,2) * C(n_j,2) = [(sum C(n_i,2))^2 - sum C(n_i,2)^2] / 2
    long long sum_of_combinations = 0;
    long long sum_of_squares = 0;
    
    for (const auto& [y, count] : groups) {
      if (count < 2) continue;
      long long c = Combination(count);
      sum_of_combinations = (sum_of_combinations + c) % MOD;
      sum_of_squares = (sum_of_squares + (c * c) % MOD) % MOD;
    }
    
    long long total = ((sum_of_combinations * sum_of_combinations) % MOD - sum_of_squares + MOD) % MOD;
    
    // Divide by 2 (multiply by modular inverse of 2)
    const long long INV2 = (MOD + 1) / 2;
    total = (total * INV2) % MOD;
    
    return total;
  }
};
