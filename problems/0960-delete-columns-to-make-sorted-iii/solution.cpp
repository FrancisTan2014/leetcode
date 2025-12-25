#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    return bruteForce(strs);
  }

 private:
  int bruteForce(const vector<string>& strs) {
    int rows = strs.size();
    int cols = strs[0].length();

    vector<vector<bool>> table;
    for (int i = 0; i < rows; i++) {
      table.push_back(analyze(strs[i]));
    }

    int delete_count = 0;
    for (int c = 0; c < cols; c++) {
      for (int r = 0; r < rows; r++) {
        if (table[r][c]) {
          delete_count++;
          break;
        }
      }
    }

    return delete_count;
  }

  vector<bool> analyze(const string& s) {
    vector<bool> v(s.size(), false);
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] > s[i + 1]) {
        v[i] = true;
      }
    }

    return v;
  }
};
