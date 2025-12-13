#include <vector>

using Row = std::vector<char>;
using Grid = std::vector<Row>;

class Solution {
    static constexpr char WATER = '0';
    static constexpr char LAND = '1';

 public:
    int numIslands(Grid& grid) {
        Grid gridCopy = grid;
        
        int islandCount = 0;
        for (int r = 0; r < gridCopy.size(); r++) {
            for (int c = 0; c < gridCopy[r].size(); c++) {
                if (gridCopy[r][c] == LAND) {
                    islandCount++;
                    sinkIslands(gridCopy, r, c);
                }
            }
        }

        return islandCount;
    }
    
 private:
    void sinkIslands(Grid& grid, int r, int c) {
        if (r < 0 || r >= grid.size()) {
            return;
        }

        Row& row = grid[r];
        if (c < 0 || c >= row.size()) {
            return;
        }

        if (row[c] == WATER) {
            return;
        }

        row[c] = WATER;
        sinkIslands(grid, r - 1, c);
        sinkIslands(grid, r + 1, c);
        sinkIslands(grid, r, c - 1);
        sinkIslands(grid, r, c + 1);
    }
};
