// tests/test_0019-remove-nth-node-from-end-of-list.cpp
#include <gtest/gtest.h>
#include <performance.h>
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

vector<int> toVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST(RemoveNthFromEnd, Example1) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 5}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, Example2) {
    Solution s;
    ListNode* head = createList({1});
    ListNode* result = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(toVector(result), vector<int>({}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, Example3) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* result = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(toVector(result), vector<int>({1}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, TwoNodesRemoveFirst) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({2}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, ThreeNodesRemoveLast) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(toVector(result), vector<int>({1, 2}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, ThreeNodesRemoveMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({1, 3}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, ThreeNodesRemoveFirst) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = s.removeNthFromEnd(head, 3);
    EXPECT_EQ(toVector(result), vector<int>({2, 3}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FourNodesRemoveLast) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FourNodesRemoveSecondLast) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 4}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FourNodesRemoveThirdLast) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = s.removeNthFromEnd(head, 3);
    EXPECT_EQ(toVector(result), vector<int>({1, 3, 4}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FourNodesRemoveFirst) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = s.removeNthFromEnd(head, 4);
    EXPECT_EQ(toVector(result), vector<int>({2, 3, 4}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FiveNodesRemoveLast) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FiveNodesRemoveFirst) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = s.removeNthFromEnd(head, 5);
    EXPECT_EQ(toVector(result), vector<int>({2, 3, 4, 5}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, FiveNodesRemoveMiddle) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = s.removeNthFromEnd(head, 3);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 4, 5}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, TenNodesRemoveLast) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i + 1;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 1);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, TenNodesRemoveFirst) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i + 1;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 10);
    vector<int> expected = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, TenNodesRemoveFifth) {
    Solution s;
    vector<int> vals(10);
    for (int i = 0; i < 10; i++) vals[i] = i + 1;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 5);
    vector<int> expected = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, AllSameValues) {
    Solution s;
    ListNode* head = createList({5, 5, 5, 5, 5});
    ListNode* result = s.removeNthFromEnd(head, 3);
    EXPECT_EQ(toVector(result), vector<int>({5, 5, 5, 5}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, IncreasingValues) {
    Solution s;
    ListNode* head = createList({10, 20, 30, 40, 50});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({10, 20, 30, 50}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, DecreasingValues) {
    Solution s;
    ListNode* head = createList({50, 40, 30, 20, 10});
    ListNode* result = s.removeNthFromEnd(head, 4);
    EXPECT_EQ(toVector(result), vector<int>({50, 30, 20, 10}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, MaxSize) {
    Solution s;
    vector<int> vals(30);
    for (int i = 0; i < 30; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 15);
    vector<int> expected;
    for (int i = 0; i < 30; i++) {
        if (i != 15) expected.push_back(i);
    }
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, MaxSizeRemoveFirst) {
    Solution s;
    vector<int> vals(30);
    for (int i = 0; i < 30; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 30);
    vector<int> expected;
    for (int i = 1; i < 30; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, MaxSizeRemoveLast) {
    Solution s;
    vector<int> vals(30);
    for (int i = 0; i < 30; i++) vals[i] = i;
    ListNode* head = createList(vals);
    ListNode* result = s.removeNthFromEnd(head, 1);
    vector<int> expected;
    for (int i = 0; i < 29; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(RemoveNthFromEnd, MaxValues) {
    Solution s;
    ListNode* head = createList({100, 100, 100, 100});
    ListNode* result = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(toVector(result), vector<int>({100, 100, 100}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, MinValues) {
    Solution s;
    ListNode* head = createList({0, 0, 0, 0});
    ListNode* result = s.removeNthFromEnd(head, 3);
    EXPECT_EQ(toVector(result), vector<int>({0, 0, 0}));
    deleteList(result);
}

TEST(RemoveNthFromEnd, Performance30Nodes) {
    Solution s;
    
    vector<int> vals(30);
    for (int i = 0; i < 30; i++) vals[i] = i;
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.removeNthFromEnd(head, 15);
    }, result);
    
    vector<int> expected;
    for (int i = 0; i < 30; i++) {
        if (i != 15) expected.push_back(i);
    }
    EXPECT_EQ(toVector(result), expected);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance30Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
