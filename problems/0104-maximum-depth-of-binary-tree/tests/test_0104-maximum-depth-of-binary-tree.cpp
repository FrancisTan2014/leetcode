#include <gtest/gtest.h>
#include "../solution.cpp"

class LC104_MaximumDepthOfBinaryTree : public ::testing::Test {
protected:
    Solution s;
    
    // Helper to delete tree
    void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

// Official Examples
TEST_F(LC104_MaximumDepthOfBinaryTree, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    EXPECT_EQ(s.maxDepth(root), 3);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, Example2) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    
    EXPECT_EQ(s.maxDepth(root), 2);
    deleteTree(root);
}

// Edge Cases
TEST_F(LC104_MaximumDepthOfBinaryTree, EmptyTree) {
    TreeNode* root = nullptr;
    EXPECT_EQ(s.maxDepth(root), 0);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(s.maxDepth(root), 1);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, OnlyLeftChildren) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    
    EXPECT_EQ(s.maxDepth(root), 4);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, OnlyRightChildren) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    
    EXPECT_EQ(s.maxDepth(root), 5);
    deleteTree(root);
}

// Balanced Trees
TEST_F(LC104_MaximumDepthOfBinaryTree, PerfectBinaryTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    EXPECT_EQ(s.maxDepth(root), 3);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, CompleteTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    EXPECT_EQ(s.maxDepth(root), 3);
    deleteTree(root);
}

// Unbalanced Trees
TEST_F(LC104_MaximumDepthOfBinaryTree, UnbalancedLeft) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    
    EXPECT_EQ(s.maxDepth(root), 4);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, UnbalancedRight) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);
    
    EXPECT_EQ(s.maxDepth(root), 5);
    deleteTree(root);
}

// Zigzag Path
TEST_F(LC104_MaximumDepthOfBinaryTree, ZigzagPath) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(4);
    root->left->right->left->right = new TreeNode(5);
    
    EXPECT_EQ(s.maxDepth(root), 5);
    deleteTree(root);
}

// Multiple Paths Same Depth
TEST_F(LC104_MaximumDepthOfBinaryTree, MultiplePathsSameDepth) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    
    EXPECT_EQ(s.maxDepth(root), 4);
    deleteTree(root);
}

// Large Depth
TEST_F(LC104_MaximumDepthOfBinaryTree, DeepTree) {
    TreeNode* root = new TreeNode(1);
    TreeNode* current = root;
    for (int i = 2; i <= 100; ++i) {
        current->left = new TreeNode(i);
        current = current->left;
    }
    
    EXPECT_EQ(s.maxDepth(root), 100);
    deleteTree(root);
}

// Two Nodes
TEST_F(LC104_MaximumDepthOfBinaryTree, TwoNodesLeftChild) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    EXPECT_EQ(s.maxDepth(root), 2);
    deleteTree(root);
}

TEST_F(LC104_MaximumDepthOfBinaryTree, TwoNodesRightChild) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    
    EXPECT_EQ(s.maxDepth(root), 2);
    deleteTree(root);
}
