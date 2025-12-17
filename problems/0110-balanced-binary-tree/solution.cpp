#include <algorithm>
#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
  static constexpr int PROPAGATE_INDICATOR = -1;

 public:
  bool isBalanced(TreeNode* root) {
    if (checkHeight(root) == PROPAGATE_INDICATOR) {
      return false;
    }

    return true;
  }

 private:
  int checkHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int left_h = checkHeight(root->left);
    if (left_h == PROPAGATE_INDICATOR) return PROPAGATE_INDICATOR;

    int right_h = checkHeight(root->right);
    if (right_h == PROPAGATE_INDICATOR) return PROPAGATE_INDICATOR;

    if (abs(left_h - right_h) > 1) return PROPAGATE_INDICATOR;

    return 1 + std::max(left_h, right_h);
  }
};
