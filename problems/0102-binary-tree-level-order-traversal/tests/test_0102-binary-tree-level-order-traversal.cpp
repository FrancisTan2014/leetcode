// tests/test_0102-binary-tree-level-order-traversal.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include "../solution.cpp"

using namespace leetcode;

void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Example 1: [3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]
TEST(LevelOrderTraversal, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{3}, {9, 20}, {15, 7}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Example 2: [1] -> [[1]]
TEST(LevelOrderTraversal, SingleNode) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Example 3: [] -> []
TEST(LevelOrderTraversal, EmptyTree) {
  Solution s;
  std::vector<std::vector<int>> result = s.levelOrder(nullptr);
  std::vector<std::vector<int>> expected = {};
  
  EXPECT_EQ(result, expected);
}

// Two nodes, left child
TEST(LevelOrderTraversal, TwoNodesLeft) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Two nodes, right child
TEST(LevelOrderTraversal, TwoNodesRight) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Perfect binary tree
TEST(LevelOrderTraversal, PerfectBinaryTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4, 5, 6, 7}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Left skewed tree
TEST(LevelOrderTraversal, LeftSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2}, {3}, {4}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Right skewed tree
TEST(LevelOrderTraversal, RightSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2}, {3}, {4}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Unbalanced tree
TEST(LevelOrderTraversal, UnbalancedTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(5);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4}, {5}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Zigzag structure
TEST(LevelOrderTraversal, ZigzagStructure) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->right->left = new TreeNode(4);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2}, {3}, {4}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Tree with negative values
TEST(LevelOrderTraversal, NegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(-1);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(-2);
  root->right->right = new TreeNode(2);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{0}, {-1, 1}, {-2, 2}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Complete binary tree (not perfect)
TEST(LevelOrderTraversal, CompleteBinaryTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4, 5, 6}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Complex tree with multiple levels
TEST(LevelOrderTraversal, ComplexTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->left->left = new TreeNode(7);
  root->right->right->right = new TreeNode(8);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4, 5, 6}, {7, 8}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}

// Large values at boundaries
TEST(LevelOrderTraversal, LargeValues) {
  Solution s;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(-1000);
  root->right = new TreeNode(1000);
  
  std::vector<std::vector<int>> result = s.levelOrder(root);
  std::vector<std::vector<int>> expected = {{0}, {-1000, 1000}};
  
  EXPECT_EQ(result, expected);
  deleteTree(root);
}
