// tests/test_0543-diameter-of-binary-tree.cpp
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

// Example 1: [1,2,3,4,5] -> 3
TEST(DiameterOfBinaryTree, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 3);
  deleteTree(root);
}

// Example 2: [1,2] -> 1
TEST(DiameterOfBinaryTree, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 1);
  deleteTree(root);
}

// Single node
TEST(DiameterOfBinaryTree, SingleNode) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 0);
  deleteTree(root);
}

// Diameter through root: left depth 2, right depth 2
TEST(DiameterOfBinaryTree, DiameterThroughRoot) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(7);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 6);
  deleteTree(root);
}

// Diameter not through root (entirely in left subtree)
TEST(DiameterOfBinaryTree, DiameterInLeftSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 4);
  deleteTree(root);
}

// Diameter not through root (entirely in right subtree)
TEST(DiameterOfBinaryTree, DiameterInRightSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->left->left = new TreeNode(5);
  root->right->right->right = new TreeNode(6);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 4);
  deleteTree(root);
}

// Only left children (skewed left)
TEST(DiameterOfBinaryTree, OnlyLeftChildren) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 3);
  deleteTree(root);
}

// Only right children (skewed right)
TEST(DiameterOfBinaryTree, OnlyRightChildren) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  root->right->right->right->right = new TreeNode(5);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 4);
  deleteTree(root);
}

// Perfect binary tree of depth 3
TEST(DiameterOfBinaryTree, PerfectBinaryTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 4);
  deleteTree(root);
}

// Zigzag path (diameter goes through multiple levels)
TEST(DiameterOfBinaryTree, ZigzagPath) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->right->left = new TreeNode(4);
  root->left->right->left->right = new TreeNode(5);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 4);
  deleteTree(root);
}

// Two nodes, root and right child
TEST(DiameterOfBinaryTree, TwoNodesRightChild) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 1);
  deleteTree(root);
}

// Unbalanced tree with longer right path
TEST(DiameterOfBinaryTree, UnbalancedRight) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  root->right->right->right->right = new TreeNode(6);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 5);
  deleteTree(root);
}

// Complex tree: diameter path is [8,4,2,1,3,6,9]
TEST(DiameterOfBinaryTree, ComplexTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(8);
  root->right->left->right = new TreeNode(9);
  
  EXPECT_EQ(s.diameterOfBinaryTree(root), 6);
  deleteTree(root);
}
