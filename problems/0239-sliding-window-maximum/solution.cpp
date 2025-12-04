#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        if (k == 1) {
            return vector<int>(nums.begin(), nums.end());
        }

        vector<int> result;

        int left = 0;
        deque<int> indices;

        for (int right = 0; right < nums.size(); right++) {
            while (!indices.empty() && nums[right] > nums[indices.back()]) {
                indices.pop_back();
            }
            indices.push_back(right);

            while (!indices.empty() && indices.front() < left) {
                indices.pop_front();
            }

            if (right - left + 1 == k) {
                result.push_back(nums[indices.front()]);
                left++;
            }
        }

        return result;
    }
};