#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(const vector<int>& nums, int k) {
        if (nums.size() <= k) return nums.size();

        int left = 0;
        int right = 0;
        int seen[2] = {0};

        int max_len = 0;

        while (right < nums.size()) {
            seen[nums[right]]++;

            while ((right - left + 1) - seen[1] > k) {
                --seen[nums[left++]];
            }
            
            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};
