#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    int h = calculateHeight(root, diameter);
    return diameter;
  }

 private:
  int calculateHeight(TreeNode* root, int& maxDiameter) {
    if (root == nullptr) return 0;

    int left_h = calculateHeight(root->left, maxDiameter);
    int right_h = calculateHeight(root->right, maxDiameter);
    maxDiameter = std::max(maxDiameter, left_h + right_h);
    return 1 + std::max(left_h, right_h);
  }
};
