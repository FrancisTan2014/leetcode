// tests/test_0226-invert-binary-tree.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <queue>
#include <vector>
#include "../solution.cpp"

using namespace leetcode;

void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Helper to collect tree values in level order
std::vector<int> levelOrder(TreeNode* root) {
  std::vector<int> result;
  if (!root) return result;
  
  std::queue<TreeNode*> q;
  q.push(root);
  
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    
    result.push_back(node->val);
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  
  return result;
}

// Example 1: [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
TEST(InvertBinaryTree, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {4, 7, 2, 9, 6, 3, 1};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Example 2: [2,1,3] -> [2,3,1]
TEST(InvertBinaryTree, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {2, 3, 1};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Example 3: [] -> []
TEST(InvertBinaryTree, EmptyTree) {
  Solution s;
  TreeNode* inverted = s.invertTree(nullptr);
  EXPECT_EQ(inverted, nullptr);
}

// Single node
TEST(InvertBinaryTree, SingleNode) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  TreeNode* inverted = s.invertTree(root);
  EXPECT_EQ(inverted->val, 1);
  EXPECT_EQ(inverted->left, nullptr);
  EXPECT_EQ(inverted->right, nullptr);
  deleteTree(inverted);
}

// Two nodes, left child
TEST(InvertBinaryTree, TwoNodesLeft) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  TreeNode* inverted = s.invertTree(root);
  EXPECT_EQ(inverted->val, 1);
  EXPECT_EQ(inverted->left, nullptr);
  EXPECT_NE(inverted->right, nullptr);
  EXPECT_EQ(inverted->right->val, 2);
  deleteTree(inverted);
}

// Two nodes, right child
TEST(InvertBinaryTree, TwoNodesRight) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  TreeNode* inverted = s.invertTree(root);
  EXPECT_EQ(inverted->val, 1);
  EXPECT_NE(inverted->left, nullptr);
  EXPECT_EQ(inverted->left->val, 2);
  EXPECT_EQ(inverted->right, nullptr);
  deleteTree(inverted);
}

// Left skewed tree
TEST(InvertBinaryTree, LeftSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {1, 2, 3, 4};
  
  EXPECT_EQ(result, expected);
  // Verify it's now right skewed
  EXPECT_EQ(inverted->left, nullptr);
  EXPECT_NE(inverted->right, nullptr);
  deleteTree(inverted);
}

// Right skewed tree
TEST(InvertBinaryTree, RightSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {1, 2, 3, 4};
  
  EXPECT_EQ(result, expected);
  // Verify it's now left skewed
  EXPECT_NE(inverted->left, nullptr);
  EXPECT_EQ(inverted->right, nullptr);
  deleteTree(inverted);
}

// Perfect binary tree
TEST(InvertBinaryTree, PerfectBinaryTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {1, 3, 2, 7, 6, 5, 4};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Unbalanced tree
TEST(InvertBinaryTree, UnbalancedTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(5);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {1, 3, 2, 4, 5};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Zigzag structure
TEST(InvertBinaryTree, ZigzagStructure) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->right->left = new TreeNode(4);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {1, 2, 3, 4};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Tree with negative values
TEST(InvertBinaryTree, NegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(-1);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(-2);
  root->right->right = new TreeNode(2);
  
  TreeNode* inverted = s.invertTree(root);
  std::vector<int> result = levelOrder(inverted);
  std::vector<int> expected = {0, 1, -1, 2, -2};
  
  EXPECT_EQ(result, expected);
  deleteTree(inverted);
}

// Inverted twice should return to original
TEST(InvertBinaryTree, InvertTwice) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  
  std::vector<int> original = levelOrder(root);
  
  TreeNode* inverted = s.invertTree(root);
  TreeNode* doubleInverted = s.invertTree(inverted);
  
  std::vector<int> result = levelOrder(doubleInverted);
  EXPECT_EQ(result, original);
  deleteTree(doubleInverted);
}
