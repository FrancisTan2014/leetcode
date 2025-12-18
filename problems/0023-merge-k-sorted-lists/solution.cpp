#include <vector>
#include <queue>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Compare { 
  bool operator()(ListNode* a, ListNode* b) {
    if (a == nullptr || b == nullptr) return false;
    return a->val >= b->val;
  } 
};

using std::vector;
using std::priority_queue;
using MinHeap = priority_queue<ListNode*, vector<ListNode*>, Compare>;

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    MinHeap heap;
    for (const auto& l : lists) {
        if (l != nullptr) {  // Only push non-null lists
            heap.push(l);
        }
    }

    ListNode dummy;
    ListNode* tail = &dummy;
    while (!heap.empty()) {
        ListNode* min = heap.top();
        heap.pop();

        tail->next = min;
        tail = min;

        if (min->next != nullptr) {
            heap.push(min->next);
        }
    }

    return dummy.next;
  }
};
