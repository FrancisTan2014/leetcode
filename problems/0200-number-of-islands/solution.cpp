#include <vector>
#include <queue>

using Row = std::vector<char>;
using Grid = std::vector<Row>;

class Solution {
    static constexpr char WATER = '0';
    static constexpr char LAND = '1';

    const std::vector<std::pair<int, int>> directions = {
        { -1, 0 }, // Up
        { 1, 0 },  // Down
        { 0, -1 }, // Left
        { 0, 1 }   // Right
    };

 public:
    int numIslands(Grid& grid) {
        std::queue<std::pair<int, int>> toVisit;
        int islandCount = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == LAND) {
                    islandCount++;
                    grid[r][c] = WATER;
                    toVisit.push({r, c});
                    sinkIslands(grid, toVisit);
                }
            }
        }

        return islandCount;
    }
    
 private:
    void sinkIslands(Grid& grid, std::queue<std::pair<int, int>>& toVisit) {
        while (!toVisit.empty()) {
            auto [r, c] = toVisit.front();
            toVisit.pop();

            for (const auto& [dr, dc] : directions) {
                int newR = r + dr;
                int newC = c + dc;

                if (newR >= 0 && newR < grid.size() &&
                    newC >= 0 && newC < grid[newR].size() &&
                    grid[newR][newC] == LAND) {
                    grid[newR][newC] = WATER;
                    toVisit.push({newR, newC});
                }
            }
        }
    }
};
