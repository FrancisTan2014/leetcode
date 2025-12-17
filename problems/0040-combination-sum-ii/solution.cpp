#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

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

    if (index == candidates.size()) {
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i-1]) {
            // Duplicate Check (The "Clever" Part)
            // If this is NOT the first time we see this number in the current loop...
            // AND it is same as the previous number...
            // SKIP IT.
            continue;
        }

        if (candidates[i] > target) {
            break;
        }

        current_path.push_back(candidates[i]);
        backtracking(candidates, target - candidates[i], i + 1, current_path, result);
        current_path.pop_back();
    }
  }
};