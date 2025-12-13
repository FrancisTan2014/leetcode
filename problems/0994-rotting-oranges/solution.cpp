#include <vector>
#include <queue>

using Grid = std::vector<std::vector<int>>;
using RottenQueue = std::queue<std::pair<int, int>>;

class Solution {
    static constexpr int FRESH = 1;
    static constexpr int ROTTEN = 2;

    static constexpr bool withinGrid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

 public:
    int orangesRotting(Grid& grid) {
        int freshCount = 0;
        RottenQueue rottenQueue;

        // minute 0: initialize fresh and rotten
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                switch (grid[r][c])
                {
                    case FRESH: freshCount++; break;
                    case ROTTEN: rottenQueue.push({r, c}); break;
                    default: break;
                }
            }
        }

        return bfsRotting(grid, rottenQueue, freshCount);
    }

 private:
    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int bfsRotting(Grid& grid, RottenQueue& currentPath, int freshCount) {
        if (freshCount == 0) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;

        while (!currentPath.empty()) {
            minutes++;
            
            int currentCount = currentPath.size();
            for (int i = 0; i < currentCount; i++) {
                auto [r, c] = currentPath.front();
                currentPath.pop();
                
                for (const auto [x, y] : directions) {
                    int newR = r + x;
                    int newC = c + y;

                    bool valid = withinGrid(newR, newC, rows, cols);
                    if (valid && grid[newR][newC] == FRESH) {
                        grid[newR][newC] = ROTTEN;
                        if (--freshCount == 0) {
                            return minutes;
                        }

                        currentPath.push({newR, newC});
                    }
                }
            }
        }

        return -1;
    }
};
