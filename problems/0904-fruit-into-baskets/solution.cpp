#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(const vector<int>& fruits) {
        constexpr int BUSKET_COUNT = 2;
        if (fruits.size() <= BUSKET_COUNT) {
            return fruits.size();
        }

        int left = 0;
        int right = 0;
        int matched_types = 0;

        unordered_map<int, int> seen;

        int max_len = 0;

        while (right < fruits.size()) {
            int type = fruits[right];
            if (seen[type]++ == 0) {
                matched_types++;
            }

            // shrink
            while (matched_types > BUSKET_COUNT) {
                int t = fruits[left];
                if (--seen[t] == 0) {
                    matched_types--;
                }

                left++;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};