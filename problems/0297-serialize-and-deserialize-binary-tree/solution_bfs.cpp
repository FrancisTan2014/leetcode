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
  inline static const string NIL = "null";
  inline static const char SEPARATER = ',';
  inline static const char LEFT_BRACKET = '[';
  inline static const char RIGHT_BRACKET = ']';

  inline static constexpr bool is_leaf(TreeNode* node) {
    return node != nullptr && 
      node->left == nullptr && 
      node->right == nullptr;
  }

 public:
    string serialize(TreeNode* root) {
      if (root == nullptr) return "[]";

      queue<TreeNode*> sequence;
      sequence.push(root);

      stringstream ss;
      ss << LEFT_BRACKET;

      int height = max_height(root);
      int level = 1;
      while (!sequence.empty()) {
        int size = sequence.size();
        for (int i = 0; i < size; i++) {
          TreeNode* curr = sequence.front();
          sequence.pop();

          if (curr == nullptr) {
            ss << NIL;
          } else {
            ss << std::to_string(curr->val);
            if (level != height) {
              sequence.push(curr->left);
              sequence.push(curr->right);
            }
          }
          
          if (!sequence.empty()) {
            ss << SEPARATER;
          }
        }

        level++;
      }

      ss << RIGHT_BRACKET;
      return ss.str();
    }

    TreeNode* deserialize(string data) {
      int index = 0;
      TreeNode* root = read(data, index);
      if (root == nullptr) return nullptr;
      
      queue<TreeNode*> pending;
      pending.push(root);

      while (index < data.size()) {
        TreeNode* curr = pending.front();
        pending.pop();

        curr->left = read(data, index);
        curr->right = read(data, index);

        if (curr->left != nullptr) pending.push(curr->left);
        if (curr->right != nullptr) pending.push(curr->right);
      }

      return root;
    }

 private:
  TreeNode* read(const string& data, int& index) {
    char c = '\0';
    stringstream ss;
    while (index < data.size()) {
      c = data[index++];
      if (c == LEFT_BRACKET) continue;
      if (c == SEPARATER || c == RIGHT_BRACKET) {
        break;
      }
      ss << c;
    }

    string value = ss.str();
    if (value == NIL || value == "") {
      return nullptr;
    } else {
      int val = std::stoi(value);
      return new TreeNode(val);
    }
  }

  int max_height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(max_height(root->left), max_height(root->right));
  }
};
