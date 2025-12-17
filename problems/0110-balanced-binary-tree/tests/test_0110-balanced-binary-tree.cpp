// tests/test_0110-balanced-binary-tree.cpp
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

// Example 1: [3,9,20,null,null,15,7] -> true
TEST(BalancedBinaryTree, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Example 2: [1,2,2,3,3,null,null,4,4] -> false
TEST(BalancedBinaryTree, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(4);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Example 3: [] -> true
TEST(BalancedBinaryTree, EmptyTree) {
  Solution s;
  EXPECT_TRUE(s.isBalanced(nullptr));
}

// Single node -> true
TEST(BalancedBinaryTree, SingleNode) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Two nodes, left child -> true
TEST(BalancedBinaryTree, TwoNodesLeftChild) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Two nodes, right child -> true
TEST(BalancedBinaryTree, TwoNodesRightChild) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Perfect binary tree of depth 3 -> true
TEST(BalancedBinaryTree, PerfectBinaryTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Complete binary tree -> true
TEST(BalancedBinaryTree, CompleteTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Left skewed tree (3 levels) -> false
TEST(BalancedBinaryTree, LeftSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Right skewed tree (3 levels) -> false
TEST(BalancedBinaryTree, RightSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Left subtree deeper by 2 -> false
TEST(BalancedBinaryTree, LeftSubtreeTooDeep) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Right subtree deeper by 2 -> false
TEST(BalancedBinaryTree, RightSubtreeTooDeep) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Balanced at root but unbalanced in subtree -> false
TEST(BalancedBinaryTree, UnbalancedSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(5);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Height difference exactly 1 -> true
TEST(BalancedBinaryTree, HeightDifferenceOne) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  
  EXPECT_TRUE(s.isBalanced(root));
  deleteTree(root);
}

// Complex unbalanced tree (node 3 has height diff of 2)
TEST(BalancedBinaryTree, ComplexUnbalanced) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->left->left = new TreeNode(7);
  root->right->right->right = new TreeNode(8);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}

// Zigzag unbalanced tree
TEST(BalancedBinaryTree, ZigzagUnbalanced) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->right->left = new TreeNode(4);
  
  EXPECT_FALSE(s.isBalanced(root));
  deleteTree(root);
}
