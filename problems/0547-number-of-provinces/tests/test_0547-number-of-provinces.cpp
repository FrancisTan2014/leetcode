// tests/test_0547-number-of-provinces.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Example 1: 2 provinces
TEST(NumberOfProvinces, Example1) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
  EXPECT_EQ(s.findCircleNum(isConnected), 2);
}

// Example 2: 3 provinces (all isolated)
TEST(NumberOfProvinces, Example2) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
  EXPECT_EQ(s.findCircleNum(isConnected), 3);
}

// Single city
TEST(NumberOfProvinces, SingleCity) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {{1}};
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Two cities connected
TEST(NumberOfProvinces, TwoCitiesConnected) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {{1,1},{1,1}};
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Two cities not connected
TEST(NumberOfProvinces, TwoCitiesNotConnected) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {{1,0},{0,1}};
  EXPECT_EQ(s.findCircleNum(isConnected), 2);
}

// All cities connected (fully connected graph)
TEST(NumberOfProvinces, AllConnected) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Chain connection: 0-1-2-3
TEST(NumberOfProvinces, ChainConnection) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0},
    {1,1,1,0},
    {0,1,1,1},
    {0,0,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Two separate groups
TEST(NumberOfProvinces, TwoSeparateGroups) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,1,1},
    {0,0,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 2);
}

// Three separate groups
TEST(NumberOfProvinces, ThreeSeparateGroups) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0,0,0},
    {1,1,0,0,0,0},
    {0,0,1,1,0,0},
    {0,0,1,1,0,0},
    {0,0,0,0,1,1},
    {0,0,0,0,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 3);
}

// Star topology: one city connected to all others
TEST(NumberOfProvinces, StarTopology) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,1,1},
    {1,1,0,0},
    {1,0,1,0},
    {1,0,0,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Complex case with multiple components
TEST(NumberOfProvinces, ComplexMultipleComponents) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,0,0,1,0},
    {0,1,1,0,0},
    {0,1,1,0,0},
    {1,0,0,1,0},
    {0,0,0,0,1}
  };
  // Groups: {0,3}, {1,2}, {4} = 3 provinces
  EXPECT_EQ(s.findCircleNum(isConnected), 3);
}

// Larger isolated cities
TEST(NumberOfProvinces, LargerIsolated) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {0,0,0,0,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 5);
}

// Ring topology: 0-1-2-3-0
TEST(NumberOfProvinces, RingTopology) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,1},
    {1,1,1,0},
    {0,1,1,1},
    {1,0,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// One large group and one isolated
TEST(NumberOfProvinces, OneLargeOneIsolated) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,1,0},
    {1,1,1,0},
    {1,1,1,0},
    {0,0,0,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 2);
}

// Asymmetric connections pattern
TEST(NumberOfProvinces, AsymmetricPattern) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0,0},
    {1,1,0,0,0},
    {0,0,1,0,1},
    {0,0,0,1,0},
    {0,0,1,0,1}
  };
  // Groups: {0,1}, {2,4}, {3} = 3 provinces
  EXPECT_EQ(s.findCircleNum(isConnected), 3);
}

// Large single province
TEST(NumberOfProvinces, LargeSingleProvince) {
  Solution s;
  int n = 10;
  std::vector<std::vector<int>> isConnected(n, std::vector<int>(n, 0));
  // Make a chain: 0-1-2-...-9
  for (int i = 0; i < n; i++) {
    isConnected[i][i] = 1;
    if (i > 0) {
      isConnected[i][i-1] = 1;
      isConnected[i-1][i] = 1;
    }
  }
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}

// Many small provinces
TEST(NumberOfProvinces, ManySmallProvinces) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0,0,0},
    {1,1,0,0,0,0},
    {0,0,1,1,0,0},
    {0,0,1,1,0,0},
    {0,0,0,0,1,1},
    {0,0,0,0,1,1}
  };
  EXPECT_EQ(s.findCircleNum(isConnected), 3);
}

// Indirect connections
TEST(NumberOfProvinces, IndirectConnections) {
  Solution s;
  std::vector<std::vector<int>> isConnected = {
    {1,1,0,0,0},
    {1,1,1,0,0},
    {0,1,1,1,0},
    {0,0,1,1,1},
    {0,0,0,1,1}
  };
  // All connected through chain
  EXPECT_EQ(s.findCircleNum(isConnected), 1);
}
