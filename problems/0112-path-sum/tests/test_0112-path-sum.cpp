// tests/test_0112-path-sum.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace leetcode;

void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Example 1: [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22 -> true
TEST(PathSum, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->right->right = new TreeNode(1);
  
  EXPECT_TRUE(s.hasPathSum(root, 22));
  deleteTree(root);
}

// Example 2: [1,2,3], targetSum = 5 -> false
TEST(PathSum, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  EXPECT_FALSE(s.hasPathSum(root, 5));
  deleteTree(root);
}

// Example 3: [], targetSum = 0 -> false
TEST(PathSum, EmptyTree) {
  Solution s;
  EXPECT_FALSE(s.hasPathSum(nullptr, 0));
}

// Single node matching target
TEST(PathSum, SingleNodeMatch) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  EXPECT_TRUE(s.hasPathSum(root, 1));
  deleteTree(root);
}

// Single node not matching target
TEST(PathSum, SingleNodeNoMatch) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  EXPECT_FALSE(s.hasPathSum(root, 2));
  deleteTree(root);
}

// Path sum on left side only
TEST(PathSum, LeftPathSum) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  
  EXPECT_TRUE(s.hasPathSum(root, 7)); // 1+2+4
  deleteTree(root);
}

// Path sum on right side only
TEST(PathSum, RightPathSum) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(4);
  
  EXPECT_TRUE(s.hasPathSum(root, 8)); // 1+3+4
  deleteTree(root);
}

// No path matches target
TEST(PathSum, NoPathMatches) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  EXPECT_FALSE(s.hasPathSum(root, 10));
  deleteTree(root);
}

// Negative values in path
TEST(PathSum, NegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(-1);
  
  EXPECT_TRUE(s.hasPathSum(root, -2)); // 1+(-2)+(-1)
  deleteTree(root);
}

// Target is zero with negative and positive values
TEST(PathSum, TargetZero) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(-1);
  
  EXPECT_TRUE(s.hasPathSum(root, 0));
  deleteTree(root);
}

// Deep left skewed tree
TEST(PathSum, DeepLeftSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->left->left->left->left = new TreeNode(5);
  
  EXPECT_TRUE(s.hasPathSum(root, 15)); // 1+2+3+4+5
  deleteTree(root);
}

// Deep right skewed tree
TEST(PathSum, DeepRightSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  
  EXPECT_TRUE(s.hasPathSum(root, 10)); // 1+2+3+4
  deleteTree(root);
}

// Multiple paths, one matches
TEST(PathSum, MultiplePathsOneMatches) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  
  EXPECT_TRUE(s.hasPathSum(root, 22)); // 5+4+11+2
  EXPECT_FALSE(s.hasPathSum(root, 100));
  deleteTree(root);
}

// Path through internal nodes but not to leaf doesn't count
TEST(PathSum, InternalNodeNotLeaf) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  
  EXPECT_FALSE(s.hasPathSum(root, 3)); // 1+2=3 but node 2 is not a leaf
  EXPECT_TRUE(s.hasPathSum(root, 6)); // 1+2+3=6 and node 3 is a leaf
  deleteTree(root);
}

// All negative values
TEST(PathSum, AllNegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(-1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(-3);
  
  EXPECT_TRUE(s.hasPathSum(root, -3)); // -1+(-2)
  EXPECT_TRUE(s.hasPathSum(root, -4)); // -1+(-3)
  deleteTree(root);
}

// Large values
TEST(PathSum, LargeValues) {
  Solution s;
  TreeNode* root = new TreeNode(1000);
  root->left = new TreeNode(-500);
  root->right = new TreeNode(500);
  root->left->left = new TreeNode(-200);
  
  EXPECT_TRUE(s.hasPathSum(root, 300)); // 1000+(-500)+(-200)
  deleteTree(root);
}
