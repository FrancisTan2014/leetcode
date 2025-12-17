#include <climits>

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
  bool isValidBST(TreeNode* root) {
    long min = INT_MIN - 1L;
    long max = INT_MAX + 1L;
    return validate(root, min, max);
  }

 private:
  bool validate(TreeNode* root, long min, long max) {
    if (root == nullptr) return true;

    if (root->val <= min || root->val >= max) return false;

    return validate(root->left, min, root->val) &&
        validate(root->right, root->val, max);
  }
};
