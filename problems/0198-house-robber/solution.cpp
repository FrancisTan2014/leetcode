#include <vector>

using std::vector;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int prev1 = nums[0];
    int prev2 = 0;
    int robbed = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
      robbed = std::max(nums[i] + prev2, prev1);
      prev2 = prev1;
      prev1 = robbed;
    }

    return robbed;
  }
};
