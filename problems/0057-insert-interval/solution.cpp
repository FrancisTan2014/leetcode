#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // STAGE 1: Strictly Left
    // Current interval ends BEFORE newInterval starts.
    while (i < n && intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i++]);
    }

    // STAGE 2: Overlapping (Merge)
    // Current interval starts BEFORE newInterval ends.
    // (If it started after, it would be Stage 3).
    while (i < n && intervals[i][1] <= newInterval[1]) {
      // Absorb the current interval into newInterval
      newInterval[0] = std::min(intervals[i][0], newInterval[0]);
      newInterval[1] = std::max(intervals[i][1], newInterval[1]);
      i++;
    }

    // Push the fully merged interval
    result.push_back(newInterval);

    while (i < n) {
      result.push_back(intervals[i]);
    }

    // STAGE 3: Strictly Right
    // Add the rest
    return result;
  }
};
