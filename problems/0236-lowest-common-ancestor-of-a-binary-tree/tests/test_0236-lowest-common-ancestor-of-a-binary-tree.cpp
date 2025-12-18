// tests/test_0236-lowest-common-ancestor-of-a-binary-tree.cpp
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

// Example 1: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1 -> 3
TEST(LowestCommonAncestor, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  
  TreeNode* p = root->left; // 5
  TreeNode* q = root->right; // 1
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 3);
  deleteTree(root);
}

// Example 2: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4 -> 5
TEST(LowestCommonAncestor, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  
  TreeNode* p = root->left; // 5
  TreeNode* q = root->left->right->right; // 4
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Example 3: root = [1,2], p = 1, q = 2 -> 1
TEST(LowestCommonAncestor, Example3) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  TreeNode* p = root; // 1
  TreeNode* q = root->left; // 2
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 1);
  deleteTree(root);
}

// Both nodes in left subtree
TEST(LowestCommonAncestor, BothInLeftSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  
  TreeNode* p = root->left->left; // 6
  TreeNode* q = root->left->right; // 2
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Both nodes in right subtree
TEST(LowestCommonAncestor, BothInRightSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  
  TreeNode* p = root->right->left; // 0
  TreeNode* q = root->right->right; // 8
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 1);
  deleteTree(root);
}

// Deep nodes in left subtree
TEST(LowestCommonAncestor, DeepNodesLeft) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  
  TreeNode* p = root->left->right->left; // 7
  TreeNode* q = root->left->right->right; // 4
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Root is LCA (one node in each subtree)
TEST(LowestCommonAncestor, RootIsLCA) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  
  TreeNode* p = root->left->left; // 4
  TreeNode* q = root->right->right; // 5
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 1);
  deleteTree(root);
}

// Node is ancestor of itself (p is ancestor of q)
TEST(LowestCommonAncestor, NodeIsAncestorOfItself) {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  
  TreeNode* p = root->left; // 5
  TreeNode* q = root->left->left; // 6
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Left skewed tree
TEST(LowestCommonAncestor, LeftSkewedTree) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(2);
  root->left->left->left->left = new TreeNode(1);
  
  TreeNode* p = root->left->left; // 3
  TreeNode* q = root->left->left->left->left; // 1
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 3);
  deleteTree(root);
}

// Right skewed tree
TEST(LowestCommonAncestor, RightSkewedTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  root->right->right->right->right = new TreeNode(5);
  
  TreeNode* p = root->right->right; // 3
  TreeNode* q = root->right->right->right->right; // 5
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 3);
  deleteTree(root);
}

// Two adjacent nodes (parent-child)
TEST(LowestCommonAncestor, AdjacentNodes) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  TreeNode* p = root; // 1
  TreeNode* q = root->left; // 2
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 1);
  deleteTree(root);
}

// Nodes with negative values
TEST(LowestCommonAncestor, NegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(-5);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(-10);
  root->left->right = new TreeNode(-2);
  
  TreeNode* p = root->left->left; // -10
  TreeNode* q = root->left->right; // -2
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, -5);
  deleteTree(root);
}

// Complex tree structure
TEST(LowestCommonAncestor, ComplexTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);
  
  TreeNode* p = root->left->left->left; // 8
  TreeNode* q = root->left->right->right; // 9
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Root with only two children
TEST(LowestCommonAncestor, ThreeNodeTree) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  TreeNode* p = root->left; // 2
  TreeNode* q = root->right; // 3
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 1);
  deleteTree(root);
}
