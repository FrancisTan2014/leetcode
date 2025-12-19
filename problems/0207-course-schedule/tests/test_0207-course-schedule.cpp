#include <gtest/gtest.h>
#include "../solution.cpp"

class CourseScheduleTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Example 1: Simple valid schedule
TEST_F(CourseScheduleTest, Example1) {
  vector<vector<int>> prerequisites = {{1, 0}};
  EXPECT_TRUE(solution.canFinish(2, prerequisites));
}

// Example 2: Simple cycle
TEST_F(CourseScheduleTest, Example2) {
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  EXPECT_FALSE(solution.canFinish(2, prerequisites));
}

// No prerequisites - all courses can be taken independently
TEST_F(CourseScheduleTest, NoPrerequisites) {
  vector<vector<int>> prerequisites = {};
  EXPECT_TRUE(solution.canFinish(5, prerequisites));
}

// Single course
TEST_F(CourseScheduleTest, SingleCourse) {
  vector<vector<int>> prerequisites = {};
  EXPECT_TRUE(solution.canFinish(1, prerequisites));
}

// Linear chain - valid DAG
TEST_F(CourseScheduleTest, LinearChain) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {4, 3}};
  EXPECT_TRUE(solution.canFinish(5, prerequisites));
}

// Three-node cycle
TEST_F(CourseScheduleTest, ThreeNodeCycle) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {0, 2}};
  EXPECT_FALSE(solution.canFinish(3, prerequisites));
}

// Complex valid DAG
TEST_F(CourseScheduleTest, ComplexValidDAG) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  EXPECT_TRUE(solution.canFinish(4, prerequisites));
}

// Multiple disconnected components, all valid
TEST_F(CourseScheduleTest, DisconnectedComponents) {
  vector<vector<int>> prerequisites = {{1, 0}, {3, 2}, {5, 4}};
  EXPECT_TRUE(solution.canFinish(6, prerequisites));
}

// Multiple disconnected components with one cycle
TEST_F(CourseScheduleTest, DisconnectedWithCycle) {
  vector<vector<int>> prerequisites = {{1, 0}, {3, 2}, {2, 3}, {5, 4}};
  EXPECT_FALSE(solution.canFinish(6, prerequisites));
}

// Star topology - all courses depend on one
TEST_F(CourseScheduleTest, StarTopology) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
  EXPECT_TRUE(solution.canFinish(5, prerequisites));
}

// Multiple prerequisites for one course
TEST_F(CourseScheduleTest, MultiplePrerequisites) {
  vector<vector<int>> prerequisites = {{2, 0}, {2, 1}, {3, 2}, {4, 3}};
  EXPECT_TRUE(solution.canFinish(5, prerequisites));
}

// Complex cycle in larger graph
TEST_F(CourseScheduleTest, ComplexCycle) {
  vector<vector<int>> prerequisites = {
      {1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}, {3, 5}
  };
  EXPECT_FALSE(solution.canFinish(6, prerequisites));
}

// Large valid DAG
TEST_F(CourseScheduleTest, LargeValidDAG) {
  vector<vector<int>> prerequisites = {
      {1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 1}, {4, 2},
      {5, 3}, {5, 4}, {6, 3}, {6, 4}, {7, 5}, {7, 6}
  };
  EXPECT_TRUE(solution.canFinish(8, prerequisites));
}

// Self-loop (course depends on itself)
TEST_F(CourseScheduleTest, SelfLoop) {
  vector<vector<int>> prerequisites = {{0, 0}};
  EXPECT_FALSE(solution.canFinish(1, prerequisites));
}

// Multiple paths to same node, but no cycle
TEST_F(CourseScheduleTest, MultiplePathsNoCycle) {
  vector<vector<int>> prerequisites = {
      {2, 0}, {2, 1}, {3, 0}, {3, 1}, {3, 2}
  };
  EXPECT_TRUE(solution.canFinish(4, prerequisites));
}

// Hidden cycle
TEST_F(CourseScheduleTest, HiddenCycle) {
  vector<vector<int>> prerequisites = {
      {1, 0}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {5, 4}, {2, 5}
  };
  EXPECT_FALSE(solution.canFinish(6, prerequisites));
}

// All courses form one long chain
TEST_F(CourseScheduleTest, LongChain) {
  vector<vector<int>> prerequisites;
  for (int i = 1; i < 10; i++) {
    prerequisites.push_back({i, i - 1});
  }
  EXPECT_TRUE(solution.canFinish(10, prerequisites));
}

// Diamond pattern - valid DAG
TEST_F(CourseScheduleTest, DiamondPattern) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  EXPECT_TRUE(solution.canFinish(4, prerequisites));
}

// Cycle at the end of a chain
TEST_F(CourseScheduleTest, CycleAtEndOfChain) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {4, 3}, {3, 4}};
  EXPECT_FALSE(solution.canFinish(5, prerequisites));
}

// All courses eventually depend on course 0
TEST_F(CourseScheduleTest, AllDependOnZero) {
  vector<vector<int>> prerequisites = {
      {1, 0}, {2, 1}, {3, 1}, {4, 2}, {5, 3}, {6, 4}, {6, 5}
  };
  EXPECT_TRUE(solution.canFinish(7, prerequisites));
}
