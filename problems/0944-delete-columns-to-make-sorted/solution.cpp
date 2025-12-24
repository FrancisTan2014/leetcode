#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int rows = strs.size();
    int cols = strs[0].length();
    int count = 0;

    for (int c = 0; c < cols; c++) {
      for (int r = 0; r < rows - 1; r++) {
        if (strs[r][c] > strs[r+1][c]) {
          count++;
          break;
        }
      }
    }

    return count;
  }
};

