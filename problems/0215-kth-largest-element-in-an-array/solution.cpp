#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

using MinHeap = priority_queue<int, vector<int>, std::greater<int>>;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    MinHeap heap = buildHeap(nums, k);

    for (int i = k; i < nums.size(); i++) {
        if (nums[i] <= heap.top()) {
            continue;
        }

        heap.pop();
        heap.push(nums[i]);
    }

    return heap.top();
  }

 private:
  MinHeap buildHeap(const vector<int>& nums, int k) {
    MinHeap heap;
    for (int i = 0; i < k; i++) {
        heap.push(nums[i]);
    }

    return heap;
  }
};
