#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int shipWithinDays(const vector<int>& weights, int days) {
        int max_w = *max_element(weights.begin(), weights.end());
        int total_weight = accumulate(weights.begin(), weights.end(), 0);

        if (days == 1) return total_weight;

        int left = max_w;
        int right = total_weight;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool check(const vector<int>& weights, int days, int capacity) {
        int days_needed = 1;
        int current_load = 0;

        for (int w: weights) {
            if (current_load + w > capacity) {
                days_needed++;
                current_load = w;

                if (days_needed > days) return false;
            } else {
                current_load += w;
            }
        }

        return true;
    }
};

