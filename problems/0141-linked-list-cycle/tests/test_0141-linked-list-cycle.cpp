// tests/test_0141-linked-list-cycle.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <unordered_set>
#include "../solution.cpp"

using namespace std;
using namespace leetcode;

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void createCycle(ListNode* head, int pos) {
    if (!head || pos < 0) return;
    
    ListNode* tail = head;
    ListNode* cycleStart = nullptr;
    int index = 0;
    
    while (tail->next) {
        if (index == pos) {
            cycleStart = tail;
        }
        tail = tail->next;
        index++;
    }
    
    if (index == pos) {
        cycleStart = tail;
    }
    
    if (cycleStart) {
        tail->next = cycleStart;
    }
}

void deleteListNoCycle(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void breakCycle(ListNode* head, int pos) {
    if (!head || pos < 0) return;
    
    unordered_set<ListNode*> visited;
    ListNode* current = head;
    
    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        current = current->next;
    }
    
    int totalNodes = visited.size();
    
    ListNode* tail = head;
    for (int i = 0; i < totalNodes - 1; i++) {
        tail = tail->next;
    }
    
    tail->next = nullptr;
}

TEST(HasCycle, EmptyList) {
    Solution s;
    EXPECT_FALSE(s.hasCycle(nullptr));
}

TEST(HasCycle, SingleNodeNoCycle) {
    Solution s;
    ListNode* head = createList({1});
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, SingleNodeWithCycle) {
    Solution s;
    ListNode* head = createList({1});
    createCycle(head, 0);
    EXPECT_TRUE(s.hasCycle(head));
    head->next = nullptr;
    delete head;
}

TEST(HasCycle, TwoNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2});
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, TwoNodesWithCycle) {
    Solution s;
    ListNode* head = createList({1, 2});
    createCycle(head, 0);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 0);
    deleteListNoCycle(head);
}

TEST(HasCycle, Example1) {
    Solution s;
    ListNode* head = createList({3, 2, 0, -4});
    createCycle(head, 1);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 1);
    deleteListNoCycle(head);
}

TEST(HasCycle, Example2) {
    Solution s;
    ListNode* head = createList({1, 2});
    createCycle(head, 0);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 0);
    deleteListNoCycle(head);
}

TEST(HasCycle, Example3) {
    Solution s;
    ListNode* head = createList({1});
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, ThreeNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, ThreeNodesCycleAtMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    createCycle(head, 1);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 1);
    deleteListNoCycle(head);
}

TEST(HasCycle, ThreeNodesCycleAtEnd) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    createCycle(head, 2);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 2);
    deleteListNoCycle(head);
}

TEST(HasCycle, FiveNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, FiveNodesCycleAtStart) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    createCycle(head, 0);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 0);
    deleteListNoCycle(head);
}

TEST(HasCycle, FiveNodesCycleAtMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    createCycle(head, 2);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 2);
    deleteListNoCycle(head);
}

TEST(HasCycle, TenNodesNoCycle) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i;
    ListNode* head = createList(vals);
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, TenNodesWithCycle) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i;
    ListNode* head = createList(vals);
    createCycle(head, 5);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 5);
    deleteListNoCycle(head);
}

TEST(HasCycle, LargeCycle) {
    Solution s;
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) vals[i] = i;
    ListNode* head = createList(vals);
    createCycle(head, 50);
    EXPECT_TRUE(s.hasCycle(head));
    breakCycle(head, 50);
    deleteListNoCycle(head);
}

TEST(HasCycle, LargeNoCycle) {
    Solution s;
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) vals[i] = i;
    ListNode* head = createList(vals);
    EXPECT_FALSE(s.hasCycle(head));
    deleteListNoCycle(head);
}

TEST(HasCycle, Performance1000Nodes) {
    Solution s;
    
    vector<int> vals(1000);
    for (int i = 0; i < 1000; i++) vals[i] = i;
    ListNode* head = createList(vals);
    createCycle(head, 500);
    
    PerformanceMonitor monitor(100.0, 1024);
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.hasCycle(head);
    }, result);
    
    EXPECT_TRUE(result);
    
    breakCycle(head, 500);
    deleteListNoCycle(head);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance1000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(HasCycle, Performance10000Nodes) {
    Solution s;
    
    vector<int> vals(10000);
    for (int i = 0; i < 10000; i++) vals[i] = i;
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    bool result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.hasCycle(head);
    }, result);
    
    EXPECT_FALSE(result);
    
    deleteListNoCycle(head);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance10000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
