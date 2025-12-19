#include <string>

using std::string;

struct TrieNode {
  TrieNode* children[26] { nullptr };
  bool isEndOfWord;

  TrieNode() : isEndOfWord(false) {}
  TrieNode(bool isEnd) : isEndOfWord(isEnd) {}
};

class Trie {
  TrieNode* root_;

 public:
  Trie() {
    root_ = new TrieNode();
  }
  
  void insert(string word) {
    TrieNode* curr = root_;
    for (const char& c : word) {
      int index = c - 'a';
      TrieNode* child = curr->children[index];
      if (child == nullptr) {
        child = new TrieNode();
        curr->children[index] = child;
      }

      curr = child;
    }

    curr->isEndOfWord = true;
  }
  
  bool search(string word) {
    TrieNode* result = search_internal(word);
    return result != nullptr && result->isEndOfWord;
  }
  
  bool startsWith(string prefix) {
    TrieNode* result = search_internal(prefix);
    return result != nullptr;
  }

  ~Trie() {
    free(root_);
  }

 private:
  TrieNode* search_internal(const string& word) {
    TrieNode* curr = root_;

    for (const char& c : word) {
      if (curr == nullptr) return nullptr;

      int index = c - 'a';
      curr = curr->children[index];
    }

    return curr;
  }

  void free(TrieNode* node) {
    if (node == nullptr) return;

    for (int i = 0; i < 26; i++) {
      free(node->children[i]);
    }

    delete node;
  }
};
