#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Gap = n + 1
        // means when fast reaches the end, 
        // slow is the node before the target one
        for (int i = 0; i <= n; i++) {
            // the constraints of the problem ensures that fast will never be nullptr at this stage
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        delete nodeToDelete;

        return dummy.next;
    }

private:
    /**
     * AI review result:
     *  In C# or Java, the Garbage Collector cleans up the node you removed (slow).
     *  In C++, you are responsible for the memory.
     */
    ListNode* removeNthFromEnd_ByMyself(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        do {
            fast = fast->next;
            n--;
        } while (fast != nullptr && n > 0);

        ListNode* last = nullptr;
        while (fast != nullptr) {
            last = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (slow == head) {
            return head->next;
        }

        // memory leak: forgot to delete slow
        // imagine the scenario that the function runs one million times
        last->next = slow->next;

        return head;
    }
};
