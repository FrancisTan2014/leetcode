#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    vector<int> curr = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      const vector<int>& next = intervals[i];
      if (curr[1] >= next[0]) {
        curr[1] = std::max(curr[1], next[1]);
      } else {
        result.push_back(curr);
        curr = next;
      }
    }

    result.push_back(curr);

    return result;
  }
};
