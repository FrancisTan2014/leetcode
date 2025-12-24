#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * DO NOT 
 *  physically remove chars, cause O(n x n) per column
 * 
 * Treat the input as a table and compare chars column by column.
 * End the loop if the current column is already sorted.
 * 
 */
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int rows = strs.size();
    int columns = strs[0].length();

    int delete_count = 0;
    vector<bool> determined(rows - 1, false);

    for (int col = 0; col < columns; col++) {
      bool need_delete = false;

      for (int row = 0; row < rows - 1; row++) {
        if (!determined[row]) {
          if (strs[row][col] > strs[row+1][col]) {
            need_delete = true;
            break;
          }
        }
      }

      if (need_delete) {
        delete_count++;
      } else {
        // Core of this solution:
        // only update determined array if we're keeping this column
        for (int row = 0; row < rows - 1; row++) {
          if (!determined[row] && strs[row][col] < strs[row+1][col]) {
            determined[row] = true;
          }
        }
      }
    }

    return delete_count;
  }

 private:

  /**
   * Original solution, partially correct
   * stop correcting it since that makes the code hard to maintain
   * hence a violation of simplication
   */
  int minDeletionSize_suffering(vector<string>& strs) {
    int n = strs.size();
    int total_cols = strs[0].length();

    int deletion_count = 0;
    int col = 0;
    int last_sorted_column = -1;

    while (col < total_cols) {
      char prev = '\0';
      bool same_chars_exist = false;
      int saved_deletion_count = deletion_count;

      for (int i = 0; i < n; i++) {
        char curr = strs[i][col];
        if (prev > curr && 
            (last_sorted_column < 0 || strs[i-1][last_sorted_column] >= strs[i][last_sorted_column])) {
          deletion_count++;
          break;
        } else {
          if (prev == curr) {
            // indicates a comparison of an additional column
            same_chars_exist = true;
          }
          prev = curr;
        }
      }

      if (saved_deletion_count == deletion_count) {
        last_sorted_column = col;
        // early break while current column has already been sorted
        if (!same_chars_exist) break;
      }

      col++;
    }

    return deletion_count;
  }
};
