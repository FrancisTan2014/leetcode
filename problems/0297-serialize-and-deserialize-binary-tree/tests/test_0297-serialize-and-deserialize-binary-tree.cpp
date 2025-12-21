// tests/test_0297-serialize-and-deserialize-binary-tree.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include <string>
#include <functional>
#include "../solution.cpp"

using namespace leetcode;

void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

bool areTreesEqual(TreeNode* t1, TreeNode* t2) {
  if (!t1 && !t2) return true;
  if (!t1 || !t2) return false;
  if (t1->val != t2->val) return false;
  return areTreesEqual(t1->left, t2->left) && areTreesEqual(t1->right, t2->right);
}

// Example 1: [1,2,3,null,null,4,5]
TEST(SerializeDeserializeBinaryTree, Example1) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Example 2: Empty tree []
TEST(SerializeDeserializeBinaryTree, EmptyTree) {
  Codec codec;
  TreeNode* root = nullptr;
  
  std::string serialized = codec.serialize(root);
  EXPECT_EQ(serialized, "[]");
  
  TreeNode* deserialized = codec.deserialize(serialized);
  EXPECT_EQ(deserialized, nullptr);
}

// Single node tree [1]
TEST(SerializeDeserializeBinaryTree, SingleNode) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Left-skewed tree [1,2,null,3]
TEST(SerializeDeserializeBinaryTree, LeftSkewedTree) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Right-skewed tree [1,null,2,null,3]
TEST(SerializeDeserializeBinaryTree, RightSkewedTree) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Perfect binary tree [1,2,3,4,5,6,7]
TEST(SerializeDeserializeBinaryTree, PerfectBinaryTree) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Tree with negative values [-1,-2,-3]
TEST(SerializeDeserializeBinaryTree, NegativeValues) {
  Codec codec;
  TreeNode* root = new TreeNode(-1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(-3);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Tree with mix of positive, negative, and zero [0,1,-1]
TEST(SerializeDeserializeBinaryTree, MixedValues) {
  Codec codec;
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(-1);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Complex tree with nulls in the middle [1,2,3,null,4,null,5]
TEST(SerializeDeserializeBinaryTree, ComplexTree) {
  Codec codec;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(5);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

// Tree with maximum constraint values [1000,-1000]
TEST(SerializeDeserializeBinaryTree, BoundaryValues) {
  Codec codec;
  TreeNode* root = new TreeNode(1000);
  root->left = new TreeNode(-1000);
  
  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);
  
  EXPECT_TRUE(areTreesEqual(root, deserialized));
  
  deleteTree(root);
  deleteTree(deserialized);
}

TEST(SerializeDeserializeBinaryTree, Performance) {
  Codec codec;
  
  // Build a large balanced tree
  std::function<TreeNode*(int)> buildTree = [&buildTree](int depth) -> TreeNode* {
    if (depth == 0) return nullptr;
    TreeNode* node = new TreeNode(depth);
    node->left = buildTree(depth - 1);
    node->right = buildTree(depth - 1);
    return node;
  };
  
  TreeNode* root = buildTree(10); // Tree with ~1023 nodes
  
  // Measure performance
  PerformanceMonitor monitor(1000.0, 10 * 1024); // 1s, 10MB limits
  auto metrics = monitor.measure([&]() {
    std::string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    deleteTree(deserialized);
  });
  
  deleteTree(root);
  
  // Record performance for CTest reporting
  RECORD_PERFORMANCE_PROPERTY(metrics, "SerializeDeserializeBinaryTree");
  EXPECT_PERFORMANCE(metrics, 1000.0, 10 * 1024);
}
