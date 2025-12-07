#include <vector>
#include <algorithm>

using namespace std;

#define NOT_FOUND -1

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int left = 1;
        int right = (position.back() - position.front()) / (m - 1);

        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (can_place_balls(position, m, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }

private:
    bool can_place_balls(const vector<int>& position, int m, int gap) {
        // greedy strategy: place the first ball at 0
        int count = 1;
        int last = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= gap) {
                count++;
                last = position[i];

                if (count == m) return true;
            }
        }

        return false;
    }
};
