#include <vector>

class Solution {
 public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<bool> used(nums.size(), false);
        std::vector<int> path;
        backtrack(nums, used, path, result);

        return result;
    }

 private:
    void backtrack(std::vector<int>& nums,
             std::vector<bool>& used,
             std::vector<int>& path,
             std::vector<std::vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, used, path, result);

            path.pop_back();     // backtrack
            used[i] = false;
        }
    }
};
