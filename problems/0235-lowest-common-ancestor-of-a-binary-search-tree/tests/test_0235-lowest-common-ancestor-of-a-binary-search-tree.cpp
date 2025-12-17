// tests/test_0235-lowest-common-ancestor-of-a-binary-search-tree.cpp
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

// Example 1: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8 -> 6
TEST(LowestCommonAncestorBST, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  
  TreeNode* p = root->left; // 2
  TreeNode* q = root->right; // 8
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 6);
  deleteTree(root);
}

// Example 2: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4 -> 2
TEST(LowestCommonAncestorBST, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  
  TreeNode* p = root->left; // 2
  TreeNode* q = root->left->right; // 4
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Example 3: root = [2,1], p = 2, q = 1 -> 2
TEST(LowestCommonAncestorBST, Example3) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  
  TreeNode* p = root; // 2
  TreeNode* q = root->left; // 1
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Both nodes in left subtree
TEST(LowestCommonAncestorBST, BothInLeftSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  
  TreeNode* p = root->left->left; // 0
  TreeNode* q = root->left->right; // 4
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Both nodes in right subtree
TEST(LowestCommonAncestorBST, BothInRightSubtree) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  
  TreeNode* p = root->right->left; // 7
  TreeNode* q = root->right->right; // 9
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 8);
  deleteTree(root);
}

// Deep nodes in left subtree
TEST(LowestCommonAncestorBST, DeepNodesLeft) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  
  TreeNode* p = root->left->right->left; // 3
  TreeNode* q = root->left->right->right; // 5
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 4);
  deleteTree(root);
}

// Root is LCA (one node in each subtree)
TEST(LowestCommonAncestorBST, RootIsLCA) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->right->right = new TreeNode(9);
  
  TreeNode* p = root->left->left; // 1
  TreeNode* q = root->right->right; // 9
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Node is ancestor of itself (p is ancestor of q)
TEST(LowestCommonAncestorBST, NodeIsAncestorOfItself) {
  Solution s;
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  
  TreeNode* p = root->left; // 2
  TreeNode* q = root->left->left; // 0
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

// Left skewed BST
TEST(LowestCommonAncestorBST, LeftSkewedBST) {
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

// Right skewed BST
TEST(LowestCommonAncestorBST, RightSkewedBST) {
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

// Two adjacent nodes
TEST(LowestCommonAncestorBST, AdjacentNodes) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  
  TreeNode* p = root->left; // 3
  TreeNode* q = root; // 5
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Nodes with negative values
TEST(LowestCommonAncestorBST, NegativeValues) {
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

// Large BST structure
TEST(LowestCommonAncestorBST, LargeBST) {
  Solution s;
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(12);
  root->right->right = new TreeNode(20);
  root->left->left->left = new TreeNode(1);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(8);
  
  TreeNode* p = root->left->left->left; // 1
  TreeNode* q = root->left->right->right; // 8
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

// Root with only two children
TEST(LowestCommonAncestorBST, ThreeNodeTree) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  
  TreeNode* p = root->left; // 1
  TreeNode* q = root->right; // 3
  TreeNode* lca = s.lowestCommonAncestor(root, p, q);
  
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}
