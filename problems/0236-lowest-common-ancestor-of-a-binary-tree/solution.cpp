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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return find_internal(root, p, q);
  }

  /**
   * 
   * Key insight: the return value contains all the context we need
   */

 private:
  TreeNode* find_internal(TreeNode* side, TreeNode* p, TreeNode* q) {
    if (side == nullptr) return nullptr;

    // when p/q is under q/p, return p/q immediately
    // which is the expected result
    if (side == p || side == q) return side;

    TreeNode* left = find_internal(side->left, p, q);
    TreeNode* right = find_internal(side->right, p, q);
    
    if (left == nullptr) {
        return right;
    } else if (right == nullptr) {
        return left;
    } else {
        return side;
    }
  }
};
