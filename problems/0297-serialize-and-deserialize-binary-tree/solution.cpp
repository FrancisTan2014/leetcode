#include <string>
#include <sstream>
#include <queue>

using std::string;
using std::stringstream;
using std::queue;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
  inline static const string NIL = "#";
  inline static const string DELIMITER = " ";

 public:
    string serialize(TreeNode* root) {
      if (root == nullptr) return NIL;
      return std::to_string(root->val) + DELIMITER +
        serialize(root->left) + DELIMITER +
        serialize(root->right);
    }

    TreeNode* deserialize(string data) {
      stringstream ss(data);
      return build_tree(ss);
    }

 private:
  TreeNode* build_tree(stringstream& ss) {
    string val;
    ss >> val;

    if (val == NIL) {
      return nullptr;
    }

    TreeNode* root = new TreeNode(std::stoi(val));
    root->left = build_tree(ss);
    root->right = build_tree(ss);

    return root;
  }
};
