// tests/test_0142-linked-list-cycle-ii.cpp
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

ListNode* getNodeAt(ListNode* head, int pos) {
    ListNode* node = head;
    for (int i = 0; i < pos && node; i++) {
        node = node->next;
    }
    return node;
}

void createCycle(ListNode* head, int pos) {
    if (!head || pos < 0) return;
    
    ListNode* tail = head;
    ListNode* cycleStart = getNodeAt(head, pos);
    
    while (tail->next) {
        tail = tail->next;
    }
    
    if (cycleStart) {
        tail->next = cycleStart;
    }
}

void breakCycle(ListNode* head) {
    if (!head) return;
    
    unordered_set<ListNode*> visited;
    ListNode* current = head;
    
    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        current = current->next;
    }
    
    if (!current) return;
    
    int totalNodes = visited.size();
    ListNode* tail = head;
    for (int i = 0; i < totalNodes - 1; i++) {
        tail = tail->next;
    }
    
    tail->next = nullptr;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST(DetectCycle, EmptyList) {
    Solution s;
    EXPECT_EQ(s.detectCycle(nullptr), nullptr);
}

TEST(DetectCycle, SingleNodeNoCycle) {
    Solution s;
    ListNode* head = createList({1});
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, SingleNodeWithCycle) {
    Solution s;
    ListNode* head = createList({1});
    createCycle(head, 0);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, head);
    head->next = nullptr;
    delete head;
}

TEST(DetectCycle, TwoNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2});
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, TwoNodesCycleAtFirst) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* expected = head;
    createCycle(head, 0);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, Example1) {
    Solution s;
    ListNode* head = createList({3, 2, 0, -4});
    ListNode* expected = getNodeAt(head, 1);
    createCycle(head, 1);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, Example2) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* expected = head;
    createCycle(head, 0);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, Example3) {
    Solution s;
    ListNode* head = createList({1});
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, ThreeNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, ThreeNodesCycleAtMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* expected = getNodeAt(head, 1);
    createCycle(head, 1);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, ThreeNodesCycleAtEnd) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* expected = getNodeAt(head, 2);
    createCycle(head, 2);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, FiveNodesNoCycle) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, FiveNodesCycleAtStart) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* expected = head;
    createCycle(head, 0);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, FiveNodesCycleAtMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* expected = getNodeAt(head, 2);
    createCycle(head, 2);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, FiveNodesCycleAtEnd) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* expected = getNodeAt(head, 4);
    createCycle(head, 4);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, TenNodesNoCycle) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i;
    ListNode* head = createList(vals);
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, TenNodesCycleAtIndex5) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* expected = getNodeAt(head, 5);
    createCycle(head, 5);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, LongListCycleAtStart) {
    Solution s;
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* expected = head;
    createCycle(head, 0);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, LongListCycleAtMiddle) {
    Solution s;
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* expected = getNodeAt(head, 50);
    createCycle(head, 50);
    ListNode* result = s.detectCycle(head);
    EXPECT_EQ(result, expected);
    breakCycle(head);
    deleteList(head);
}

TEST(DetectCycle, LongListNoCycle) {
    Solution s;
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) vals[i] = i;
    ListNode* head = createList(vals);
    EXPECT_EQ(s.detectCycle(head), nullptr);
    deleteList(head);
}

TEST(DetectCycle, Performance1000Nodes) {
    Solution s;
    
    vector<int> vals(1000);
    for (int i = 0; i < 1000; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* expected = getNodeAt(head, 500);
    createCycle(head, 500);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.detectCycle(head);
    }, result);
    
    EXPECT_EQ(result, expected);
    
    breakCycle(head);
    deleteList(head);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance1000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(DetectCycle, Performance10000NodesNoCycle) {
    Solution s;
    
    vector<int> vals(10000);
    for (int i = 0; i < 10000; i++) vals[i] = i;
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.detectCycle(head);
    }, result);
    
    EXPECT_EQ(result, nullptr);
    
    deleteList(head);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance10000NodesNoCycle");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
