#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());

        if (piles.size() == h) return right;

        int left = 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid)) {
                // if we can finish, we eat slower
                right = mid;
            } else {
                // if we cannot finish, we eat faster
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool check(const vector<int>& piles, int h, int k) {
        long total_hours = 0;
        for (int pile: piles) {
            total_hours += (pile + k - 1) / k;

            if (total_hours > h) return false;
        }
        return true;
    }

};
