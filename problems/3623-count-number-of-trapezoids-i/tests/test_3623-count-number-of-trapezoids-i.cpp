#include <gtest/gtest.h>
#include <vector>
#include "../solution.cpp"

// Example 1: Basic trapezoid formation
TEST(CountTrapezoids, Example1) {
    Solution s;
    std::vector<std::vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    EXPECT_EQ(s.countTrapezoids(points), 3);
}

// Example 2: Single trapezoid
TEST(CountTrapezoids, Example2) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};
    EXPECT_EQ(s.countTrapezoids(points), 1);
}

// Minimum case: exactly 4 points, 2 at each level
TEST(CountTrapezoids, MinimumPoints) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,0},{0,1},{1,1}};
    EXPECT_EQ(s.countTrapezoids(points), 1);
}

// No trapezoids: all points on same horizontal line
TEST(CountTrapezoids, AllSameY) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,0},{2,0},{3,0}};
    EXPECT_EQ(s.countTrapezoids(points), 0);
}

// No trapezoids: all points have unique y-coordinates
TEST(CountTrapezoids, AllUniqueY) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,1},{2,2},{3,3}};
    EXPECT_EQ(s.countTrapezoids(points), 0);
}

// Multiple levels: 3 points at y=0, 2 at y=1
TEST(CountTrapezoids, ThreeAndTwo) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,0},{2,0},{0,1},{1,1}};
    EXPECT_EQ(s.countTrapezoids(points), 3);  // C(3,2) * C(2,2) = 3 * 1 = 3
}

// Multiple levels: 4 points at y=0, 3 at y=1
TEST(CountTrapezoids, FourAndThree) {
    Solution s;
    std::vector<std::vector<int>> points = {{0,0},{1,0},{2,0},{3,0},{0,1},{1,1},{2,1}};
    EXPECT_EQ(s.countTrapezoids(points), 18);  // C(4,2) * C(3,2) = 6 * 3 = 18
}

// Three levels: multiple pairs
TEST(CountTrapezoids, ThreeLevels) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},        // y=0: 2 points
        {0,1},{1,1},{2,1},  // y=1: 3 points
        {0,2},{1,2}         // y=2: 2 points
    };
    // Pairs: (y0,y1): C(2,2)*C(3,2) = 1*3 = 3
    //        (y0,y2): C(2,2)*C(2,2) = 1*1 = 1
    //        (y1,y2): C(3,2)*C(2,2) = 3*1 = 3
    // Total: 3 + 1 + 3 = 7
    EXPECT_EQ(s.countTrapezoids(points), 7);
}

// Large numbers at one level
TEST(CountTrapezoids, ManyPointsOneLevel) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},{2,0},{3,0},{4,0},  // y=0: 5 points
        {0,1},{1,1}                     // y=1: 2 points
    };
    EXPECT_EQ(s.countTrapezoids(points), 10);  // C(5,2) * C(2,2) = 10 * 1 = 10
}

// Negative coordinates
TEST(CountTrapezoids, NegativeCoordinates) {
    Solution s;
    std::vector<std::vector<int>> points = {{-1,-1},{0,-1},{-1,1},{0,1}};
    EXPECT_EQ(s.countTrapezoids(points), 1);
}

// Mixed positive and negative
TEST(CountTrapezoids, MixedCoordinates) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {-2,0},{-1,0},{1,0},{2,0},  // y=0: 4 points
        {-1,5},{1,5}                // y=5: 2 points
    };
    EXPECT_EQ(s.countTrapezoids(points), 6);  // C(4,2) * C(2,2) = 6 * 1 = 6
}

// Equal number of points at two levels
TEST(CountTrapezoids, EqualDistribution) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},{2,0},  // y=0: 3 points
        {0,1},{1,1},{2,1}   // y=1: 3 points
    };
    EXPECT_EQ(s.countTrapezoids(points), 9);  // C(3,2) * C(3,2) = 3 * 3 = 9
}

// Four levels with varying counts
TEST(CountTrapezoids, FourLevels) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},              // y=0: 2 points
        {0,1},{1,1},              // y=1: 2 points
        {0,2},{1,2},{2,2},        // y=2: 3 points
        {0,3},{1,3}               // y=3: 2 points
    };
    // Pairs: (0,1): 1*1=1, (0,2): 1*3=3, (0,3): 1*1=1
    //        (1,2): 1*3=3, (1,3): 1*1=1
    //        (2,3): 3*1=3
    // Total: 1+3+1+3+1+3 = 12
    EXPECT_EQ(s.countTrapezoids(points), 12);
}

// Only two levels with maximum at each
TEST(CountTrapezoids, TwoLevelsMaximum) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},  // y=0: 6 points
        {0,1},{1,1},{2,1},{3,1},{4,1},{5,1}   // y=1: 6 points
    };
    EXPECT_EQ(s.countTrapezoids(points), 225);  // C(6,2) * C(6,2) = 15 * 15 = 225
}

// Sparse vertical distribution
TEST(CountTrapezoids, SparseVertical) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {0,0},{1,0},
        {0,100},{1,100}
    };
    EXPECT_EQ(s.countTrapezoids(points), 1);
}

// Large coordinate values
TEST(CountTrapezoids, LargeCoordinates) {
    Solution s;
    std::vector<std::vector<int>> points = {
        {-100000000,0},{100000000,0},
        {-100000000,100000000},{100000000,100000000}
    };
    EXPECT_EQ(s.countTrapezoids(points), 1);
}

// Performance test
TEST(CountTrapezoids, Performance) {
    Solution s;
    std::vector<std::vector<int>> points;
    
    // Create 1000 points: 500 at y=0, 500 at y=1
    for (int i = 0; i < 500; i++) {
        points.push_back({i, 0});
        points.push_back({i, 1});
    }
    
    // C(500,2) * C(500,2) = 124750 * 124750 = 15,562,562,500
    // Result % (1e9+7) = 562,562,395
    EXPECT_EQ(s.countTrapezoids(points), 562562395);
}
