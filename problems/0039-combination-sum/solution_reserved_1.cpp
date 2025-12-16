// Solution: Backtracking with Memoization
//
// Approach:
// - Use backtracking to explore all valid combinations
// - For each candidate at index i, make two choices:
//   1. Exclude: skip to next candidate (index + 1)
//   2. Include: use candidate repeatedly (1x, 2x, 3x...) until sum >= target
// - Cache intermediate results: cache[index][remaining_target] stores all valid
//   combinations that can be formed from candidates[index..] with given target
// - When cache hit, merge cached results with current path to avoid recomputation
//
// Time Complexity: O(N * T) with memoization vs O(T^N) without
//   where N = number of candidates, T = target value
// Space Complexity: O(N * T) for cache + O(T) for recursion stack
//
// Trade-offs:
// + Performance: Passes LeetCode time limits (~15ms vs several seconds)
// + Demonstrates DP optimization technique
// - Complexity: ~110 lines vs ~30 for standard backtracking
// - Maintenance: Cache logic harder to understand/debug
// - Memory: Uses extra space for memoization
//
// Note: Standard backtracking with early pruning (sorting + break when sum > target)
// is simpler and often sufficient. This solution prioritizes performance over simplicity.

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

using CacheTable =
    unordered_map<int, unordered_map<int, vector<vector<int>>>>;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int>> result;
    CacheTable cache;
    Backtracking(candidates, 0, path, target, cache, result);
    return result;
  }

 private:
  void Backtracking(const vector<int>& candidates, int index,
                    vector<int>& current_path, int target, CacheTable& cache,
                    vector<vector<int>>& result) {
    if (index == candidates.size()) return;

    // Exclude candidates[index]
    if (!MergeCachedResultsIfExist(result, cache, index + 1, target,
                                    current_path)) {
      Backtracking(candidates, index + 1, current_path, target, cache, result);
    }

    // Include candidates[index]
    int n = candidates[index];
    if (n == target) {
      current_path.push_back(n);
      result.push_back(current_path);
      current_path.pop_back();
      return;
    }

    int acc = 0;
    do {
      acc += n;
      current_path.push_back(n);

      int left_target = target - acc;
      bool cache_shot = MergeCachedResultsIfExist(result, cache, index + 1,
                                                   left_target, current_path);
      if (!cache_shot) {
        vector<vector<int>> following_paths;
        vector<int> cp;
        Backtracking(candidates, index + 1, cp, left_target, cache,
                     following_paths);

        CacheIntermediateResult(cache, index + 1, left_target,
                                following_paths);
        if (following_paths.size() > 0) {
          Merge(result, current_path, following_paths);
        }
      }
    } while (acc < target);

    if (acc == target) {
      result.push_back(current_path);
    }

    // Recover current_path before return
    current_path.resize(current_path.size() - acc / n);
  }

  vector<int> Combine(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    result.reserve(v1.size() + v2.size());
    result.insert(result.end(), v1.begin(), v1.end());
    result.insert(result.end(), v2.begin(), v2.end());
    return result;
  }

  void Merge(vector<vector<int>>& result, const vector<int>& current_path,
             const vector<vector<int>>& following_paths) {
    for (const auto& v : following_paths) {
      vector<int> t = Combine(current_path, v);
      result.push_back(t);
    }
  }

  bool MergeCachedResultsIfExist(vector<vector<int>>& result, CacheTable& cache,
                                  int index, int target,
                                  const vector<int>& current_path) {
    bool cache_shot = false;
    auto index_cache = cache.find(index);
    if (index_cache != cache.end()) {
      auto result_cache = index_cache->second.find(target);
      if (result_cache != index_cache->second.end()) {
        if (result_cache->second.size() > 0) {
          Merge(result, current_path, result_cache->second);
        }
        cache_shot = true;
      }
    }
    return cache_shot;
  }

  void CacheIntermediateResult(CacheTable& cache, int index, int target,
                                const vector<vector<int>>& results) {
    cache[index][target] = results;
  }
};
