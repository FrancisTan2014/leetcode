// tests/test_0206-reverse-linked-list.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
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

TEST(ReverseList, EmptyList) {
    Solution s;
    ListNode* head = nullptr;
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(result, nullptr);
}

TEST(ReverseList, SingleNode) {
    Solution s;
    ListNode* head = createList({1});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({1}));
    deleteList(result);
}

TEST(ReverseList, TwoNodes) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({2, 1}));
    deleteList(result);
}

TEST(ReverseList, ThreeNodes) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({3, 2, 1}));
    deleteList(result);
}

TEST(ReverseList, Example1) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({5, 4, 3, 2, 1}));
    deleteList(result);
}

TEST(ReverseList, FourNodes) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({4, 3, 2, 1}));
    deleteList(result);
}

TEST(ReverseList, SixNodes) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5, 6});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({6, 5, 4, 3, 2, 1}));
    deleteList(result);
}

TEST(ReverseList, NegativeValues) {
    Solution s;
    ListNode* head = createList({-1, -2, -3});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({-3, -2, -1}));
    deleteList(result);
}

TEST(ReverseList, MixedValues) {
    Solution s;
    ListNode* head = createList({-5, 0, 5});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({5, 0, -5}));
    deleteList(result);
}

TEST(ReverseList, AllSameValue) {
    Solution s;
    ListNode* head = createList({7, 7, 7, 7});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({7, 7, 7, 7}));
    deleteList(result);
}

TEST(ReverseList, LargeValues) {
    Solution s;
    ListNode* head = createList({5000, -5000, 0});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({0, -5000, 5000}));
    deleteList(result);
}

TEST(ReverseList, TenNodes) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({10, 9, 8, 7, 6, 5, 4, 3, 2, 1}));
    deleteList(result);
}

TEST(ReverseList, IncreasingSequence) {
    Solution s;
    vector<int> input = {0, 10, 20, 30, 40, 50};
    ListNode* head = createList(input);
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({50, 40, 30, 20, 10, 0}));
    deleteList(result);
}

TEST(ReverseList, DecreasingSequence) {
    Solution s;
    vector<int> input = {50, 40, 30, 20, 10, 0};
    ListNode* head = createList(input);
    ListNode* result = s.reverseList(head);
    EXPECT_EQ(toVector(result), vector<int>({0, 10, 20, 30, 40, 50}));
    deleteList(result);
}

TEST(ReverseList, Performance100Nodes) {
    Solution s;
    
    vector<int> vals(100);
    for (int i = 0; i < 100; i++) {
        vals[i] = i;
    }
    
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.reverseList(head);
    }, result);
    
    EXPECT_EQ(toVector(result).size(), 100);
    EXPECT_EQ(toVector(result)[0], 99);
    EXPECT_EQ(toVector(result)[99], 0);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance100Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(ReverseList, Performance5000Nodes) {
    Solution s;
    
    vector<int> vals(5000);
    for (int i = 0; i < 5000; i++) {
        vals[i] = i;
    }
    
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.reverseList(head);
    }, result);
    
    EXPECT_EQ(toVector(result).size(), 5000);
    EXPECT_EQ(toVector(result)[0], 4999);
    EXPECT_EQ(toVector(result)[4999], 0);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance5000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
