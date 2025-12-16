#include <vector>

using namespace std;

class Solution {
 public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> path;
      vector<vector<int>> result;
      backtrack(nums, 0, path, result);

      return result;
    }

 private:
    void backtrack(vector<int>& nums, 
                   int index, 
                   vector<int>& current_path, 
                   vector<vector<int>>& result) {
      if (index == nums.size()) {
        result.push_back(current_path);
        return;
      }

      // Exclude nums[index]
      backtrack(nums, index + 1, current_path, result);

      // Include nums[index]
      current_path.push_back(nums[index]);
      backtrack(nums, index + 1, current_path, result);
      current_path.pop_back();
    }
};
