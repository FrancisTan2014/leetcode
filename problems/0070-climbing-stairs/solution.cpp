class Solution {
 public:
  int climbStairs(int n) {
    int a = 0;
    int b = 1;
    for (int i = 1; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b;
  }
};
