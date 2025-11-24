// solution.cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pl = 0;
        int pr = numbers.size() - 1;
        while (pl < pr) {
            int sum = numbers[pl] + numbers[pr];
            if (sum == target) {
                return {pl + 1, pr + 1};
            } else if (sum < target) {
                ++pl;
            } else {
                --pr;
            }
        }
        return {};
    }
};
