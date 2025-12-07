#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        if (k == 1) return right;

        int ans = left;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (is_balanced(nums, k, mid)) {
                ans = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

private:
    bool is_balanced(const vector<int>& nums, int k, int limit) {
        int current_sum = 0;
        int pieces = 1;

        for (int n: nums) {
            if (n > limit) return false;

            if (current_sum + n > limit) {
                pieces++;
                current_sum = n;
            } else {
                current_sum += n;
            }
        }

        return pieces <= k;
    }
};
