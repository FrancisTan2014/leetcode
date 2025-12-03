#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(const vector<int>& nums) {
        unordered_map<int, int> prefix;
        int sum_values[2] = { -1, 1 };

        int sum = 0;
        int len = 0;

        prefix[0] = -1;

        for (int right = 0; right < nums.size(); right++) {
            sum += sum_values[nums[right]];
            if (prefix.find(sum) == prefix.end()) {
                prefix[sum] = right;
            } else {
                int last_appear = prefix[sum];
                len = max(len, right - last_appear);
            }
        }

        return len;
    }
};