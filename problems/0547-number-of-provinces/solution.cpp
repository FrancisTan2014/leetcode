#include <vector>

using std::vector;

class UnionFind {
 private:
  vector<int> parent;

 public:
  UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      parent[rootX] = rootY; // Merge
      return true;
    }

    return false;
  }
};

class Solution {
  static constexpr int CONNECTED = 1;

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int count = n;
    UnionFind unionFind(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (i == j) continue;
        if (isConnected[i][j] == CONNECTED) {
          if (unionFind.unite(i, j)) count--;
        }
      }
    }

    return count;
  }
};
