#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> empty;
    vector<vector<int>> result;
    backtracking(candidates, target, 0, empty, result);

    return result;
  }

 private:
  void backtracking(vector<int>& candidates, 
                    int target, 
                    int index, 
                    vector<int>& current_path, 
                    vector<vector<int>>& result) {
    if (target == 0) {
      result.push_back(current_path);
      return;
    }

    if (index == candidates.size() || target < 0) {
      return;
    }

    current_path.push_back(candidates[index]);
    backtracking(candidates, target - candidates[index], index, current_path, result);
    current_path.pop_back();

    backtracking(candidates, target, index + 1, current_path, result);
  }
};