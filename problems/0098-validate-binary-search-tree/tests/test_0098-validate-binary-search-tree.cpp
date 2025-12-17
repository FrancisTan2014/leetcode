// tests/test_0098-validate-binary-search-tree.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <climits>
#include "../solution.cpp"

using namespace leetcode;

void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Example 1: [2,1,3] -> true
TEST(ValidateBST, Example1) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Example 2: [5,1,4,null,null,3,6] -> false
TEST(ValidateBST, Example2) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(6);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Example 3: [] -> true
TEST(ValidateBST, EmptyTree) {
  Solution s;
  EXPECT_TRUE(s.isValidBST(nullptr));
}

// Single node -> true
TEST(ValidateBST, SingleNode) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Valid BST with left child only
TEST(ValidateBST, ValidLeftChildOnly) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Valid BST with right child only
TEST(ValidateBST, ValidRightChildOnly) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Invalid: left child greater than parent
TEST(ValidateBST, InvalidLeftGreaterThanParent) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Invalid: right child less than parent
TEST(ValidateBST, InvalidRightLessThanParent) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->right = new TreeNode(1);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Valid perfect BST
TEST(ValidateBST, ValidPerfectBST) {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Invalid: left subtree contains value greater than root
TEST(ValidateBST, InvalidLeftSubtreeGreaterThanRoot) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->left->right = new TreeNode(6); // 6 > 5, invalid
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Invalid: right subtree contains value less than root
TEST(ValidateBST, InvalidRightSubtreeLessThanRoot) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->right->left = new TreeNode(4); // 4 < 5, invalid
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Edge case: duplicate values (BST requires strictly less/greater)
TEST(ValidateBST, DuplicateValueLeftChild) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Edge case: duplicate values in right child
TEST(ValidateBST, DuplicateValueRightChild) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}

// Valid BST with negative values
TEST(ValidateBST, ValidNegativeValues) {
  Solution s;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(-1);
  root->right = new TreeNode(1);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Valid left-skewed BST
TEST(ValidateBST, ValidLeftSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->left->left = new TreeNode(1);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Valid right-skewed BST
TEST(ValidateBST, ValidRightSkewed) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Edge case: INT_MIN as node value
TEST(ValidateBST, IntMinValue) {
  Solution s;
  TreeNode* root = new TreeNode(INT_MIN);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Edge case: INT_MAX as node value
TEST(ValidateBST, IntMaxValue) {
  Solution s;
  TreeNode* root = new TreeNode(INT_MAX);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Edge case: INT_MIN with right child
TEST(ValidateBST, IntMinWithRightChild) {
  Solution s;
  TreeNode* root = new TreeNode(INT_MIN);
  root->right = new TreeNode(INT_MAX);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Complex valid BST
TEST(ValidateBST, ComplexValidBST) {
  Solution s;
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(12);
  root->right->right = new TreeNode(18);
  
  EXPECT_TRUE(s.isValidBST(root));
  deleteTree(root);
}

// Complex invalid BST (subtle violation)
TEST(ValidateBST, ComplexInvalidBST) {
  Solution s;
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(6); // 6 < 10 but in right subtree, invalid
  root->right->right = new TreeNode(18);
  
  EXPECT_FALSE(s.isValidBST(root));
  deleteTree(root);
}
