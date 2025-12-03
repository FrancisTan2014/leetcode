#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(const vector<int>& nums, int k) {
        unordered_map<int, int> prefix;

        int len = 0;
        int sum = 0;
        prefix[0] = -1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            if (prefix.find(sum) == prefix.end()) {
                prefix[sum] = right;
            }

            int relative = sum - k;
            auto it = prefix.find(relative);
            if (it != prefix.end()) {
                int left = it->second;
                len = max(len, right - left);
            }
        }

        return len;
    }
};