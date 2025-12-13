#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../solution.cpp"

namespace {

using Grid = std::vector<std::vector<char>>;

Grid ParseGrid(const std::vector<std::string>& rows) {
    Grid grid;
    grid.reserve(rows.size());
    for (const auto& row : rows) {
        grid.emplace_back(row.begin(), row.end());
    }
    return grid;
}

}  // namespace

TEST(LC200_NumberOfIslands, SingleCellWater) {
    Solution s;
    auto grid = ParseGrid({"0"});
    EXPECT_EQ(s.numIslands(grid), 0);
}

TEST(LC200_NumberOfIslands, SingleCellLand) {
    Solution s;
    auto grid = ParseGrid({"1"});
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, AllWater) {
    Solution s;
    auto grid = ParseGrid({"000", "000"});
    EXPECT_EQ(s.numIslands(grid), 0);
}

TEST(LC200_NumberOfIslands, AllLandOneIsland) {
    Solution s;
    auto grid = ParseGrid({"111", "111"});
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, Example1) {
    Solution s;
    auto grid = ParseGrid({
            "11110",
            "11010",
            "11000",
            "00000",
    });
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, Example2) {
    Solution s;
    auto grid = ParseGrid({
            "11000",
            "11000",
            "00100",
            "00011",
    });
    EXPECT_EQ(s.numIslands(grid), 3);
}

TEST(LC200_NumberOfIslands, DiagonalsDoNotConnect) {
    Solution s;
    auto grid = ParseGrid({
            "10",
            "01",
    });
    EXPECT_EQ(s.numIslands(grid), 2);
}

TEST(LC200_NumberOfIslands, Checkerboard3x3) {
    // Each '1' is isolated by 4-direction adjacency.
    Solution s;
    auto grid = ParseGrid({
            "101",
            "010",
            "101",
    });
    EXPECT_EQ(s.numIslands(grid), 5);
}

TEST(LC200_NumberOfIslands, ThinRow) {
    Solution s;
    auto grid = ParseGrid({"101101"});
    EXPECT_EQ(s.numIslands(grid), 3);
}

TEST(LC200_NumberOfIslands, ThinColumn) {
    Solution s;
    auto grid = ParseGrid({"1", "0", "1", "1", "0", "1"});
    EXPECT_EQ(s.numIslands(grid), 3);
}

TEST(LC200_NumberOfIslands, RingWithHolesStillOneIsland) {
    Solution s;
    auto grid = ParseGrid({
            "11111",
            "10001",
            "10001",
            "10001",
            "11111",
    });
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, MultipleBlobs) {
    Solution s;
    auto grid = ParseGrid({
            "110011",
            "110001",
            "001100",
            "001100",
    });
    EXPECT_EQ(s.numIslands(grid), 3);
}

TEST(LC200_NumberOfIslands, ThreeIslandsInOffsetBlocksPattern) {
    // This pattern forms 3 disconnected components under 4-direction adjacency.
    Solution s;
    auto grid = ParseGrid({
            "110011",
            "110011",
            "001100",
            "001100",
    });
    EXPECT_EQ(s.numIslands(grid), 3);
}

TEST(LC200_NumberOfIslands, BorderOnlyLandIsOneIsland) {
    // Land on the border forms a single loop (still 1 island).
    Solution s;
    auto grid = ParseGrid({
            "11111",
            "10001",
            "10001",
            "10001",
            "11111",
    });
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, LongSnakeIsOneIsland) {
    // A single connected winding path.
    Solution s;
    auto grid = ParseGrid({
            "11110",
            "00010",
            "01110",
            "01000",
            "01111",
    });
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LC200_NumberOfIslands, Checkerboard5x5Has13Islands) {
    // In an odd-sized checkerboard starting with '1', count of '1's is 13.
    Solution s;
    auto grid = ParseGrid({
            "10101",
            "01010",
            "10101",
            "01010",
            "10101",
    });
    EXPECT_EQ(s.numIslands(grid), 13);
}

TEST(LC200_NumberOfIslands, Regression_LeetCodeReportedTLECase_IsOneIsland) {
    // Reported failing case on LeetCode for some BFS/DFS implementations.
    // Expected islands: 1.
    Solution s;
    auto grid = ParseGrid({
            "11111011111111101011",
            "01111111111110111110",
            "10111001101111111111",
            "11110111111111111111",
            "10011111111111111111",
            "10111111011101110111",
            "01111111111101101111",
            "11111111111101111011",
            "11111111110111111111",
            "11111111111111111111",
            "01111111011111111111",
            "11111111111111111111",
            "11111111111111111111",
            "11111011111110111111",
            "10111110111011110111",
            "11111111111101111110",
            "11111111111110111100",
            "11111111111111111111",
            "11111111111111111111",
            "11111111111111111111",
    });
    EXPECT_EQ(s.numIslands(grid), 1);
}
