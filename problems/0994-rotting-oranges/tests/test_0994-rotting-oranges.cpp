#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../solution.cpp"

namespace {

using Grid = std::vector<std::vector<int>>;

Grid ParseGrid(const std::vector<std::string>& rows) {
  Grid grid;
  grid.reserve(rows.size());
  for (const auto& row : rows) {
    std::vector<int> r;
    r.reserve(row.size());
    for (char ch : row) {
      r.push_back(ch - '0');
    }
    grid.push_back(std::move(r));
  }
  return grid;
}

}  // namespace

TEST(LC994_RottingOranges, Example1) {
  Solution s;
  auto grid = ParseGrid({"211", "110", "011"});
  EXPECT_EQ(s.orangesRotting(grid), 4);
}

TEST(LC994_RottingOranges, Example2_Impossible) {
  Solution s;
  auto grid = ParseGrid({"211", "011", "101"});
  EXPECT_EQ(s.orangesRotting(grid), -1);
}

TEST(LC994_RottingOranges, Example3_NoFreshOranges) {
  Solution s;
  auto grid = ParseGrid({"02"});
  EXPECT_EQ(s.orangesRotting(grid), 0);
}

TEST(LC994_RottingOranges, AllEmpty) {
  Solution s;
  auto grid = ParseGrid({"000", "000"});
  EXPECT_EQ(s.orangesRotting(grid), 0);
}

TEST(LC994_RottingOranges, AllFreshNoRotten_Impossible) {
  Solution s;
  auto grid = ParseGrid({"111", "111"});
  EXPECT_EQ(s.orangesRotting(grid), -1);
}

TEST(LC994_RottingOranges, AllRottenNoFresh) {
  Solution s;
  auto grid = ParseGrid({"222", "222"});
  EXPECT_EQ(s.orangesRotting(grid), 0);
}

TEST(LC994_RottingOranges, SingleFreshSingleRotten) {
  Solution s;
  auto grid = ParseGrid({"21"});
  EXPECT_EQ(s.orangesRotting(grid), 1);
}

TEST(LC994_RottingOranges, SingleCellFresh_Impossible) {
  Solution s;
  auto grid = ParseGrid({"1"});
  EXPECT_EQ(s.orangesRotting(grid), -1);
}

TEST(LC994_RottingOranges, SingleCellRotten) {
  Solution s;
  auto grid = ParseGrid({"2"});
  EXPECT_EQ(s.orangesRotting(grid), 0);
}

TEST(LC994_RottingOranges, DiagonalNotConnected_Impossible) {
  Solution s;
  auto grid = ParseGrid({"20", "01"});
  EXPECT_EQ(s.orangesRotting(grid), -1);
}

TEST(LC994_RottingOranges, MultipleRottenSources) {
  Solution s;
  auto grid = ParseGrid({"21112", "10001", "10001", "21112"});
  EXPECT_EQ(s.orangesRotting(grid), 2);
}

TEST(LC994_RottingOranges, LongPath) {
  Solution s;
  auto grid = ParseGrid({"2111111111"});
  EXPECT_EQ(s.orangesRotting(grid), 9);
}

TEST(LC994_RottingOranges, MixedWithEmpty) {
  Solution s;
  auto grid = ParseGrid({"210", "101", "012"});
  EXPECT_EQ(s.orangesRotting(grid), 1);
}

TEST(LC994_RottingOranges, SurroundedByEmpty_Impossible) {
  Solution s;
  auto grid = ParseGrid({"202", "010", "202"});
  EXPECT_EQ(s.orangesRotting(grid), -1);
}

TEST(LC994_RottingOranges, ComplexGrid) {
  Solution s;
  auto grid = ParseGrid({
      "2100",
      "1110",
      "0111",
      "0012",
  });
  EXPECT_EQ(s.orangesRotting(grid), 3);
}
