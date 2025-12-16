/**
 * 
 * It solves the problem, but it is not divide-and-conqure way.
 * The do-while loop can be erased.
 * Remember the principle: each further step goes nearer to the answer.
 * 
 */

#include <unordered_map>
#include <vector>
#include <algorithm>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> empty;
    backtracking(candidates, target, 0, empty, result);

    return result;
  }

 private:
  void backtracking(vector<int>& candidates, 
                    int target,
                    int index,
                    vector<int>& current_path, 
                    vector<vector<int>>& result) {
    if (index == candidates.size()) return;
    
    int n = candidates[index];
    if (n > target) return;

    if (n == target) {
        current_path.push_back(n);
        result.push_back(current_path);
        current_path.pop_back();
        return;
    }
    
    // Excludes n
    backtracking(candidates, target, index + 1, current_path, result);

    // Includes n
    int acc = 0;
    do {
        acc += n;
        current_path.push_back(n);
        backtracking(candidates, target - acc, index + 1, current_path, result);
    } while (acc < target);

    if (acc == target) {
        result.push_back(current_path);
    }

    // recover current_path before return
    current_path.resize(current_path.size() - acc / n);
  }
};
