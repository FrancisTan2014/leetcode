// tests/test_0148-sort-list.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <algorithm>
#include <random>
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

TEST(SortList, Example1) {
    Solution s;
    ListNode* head = createList({4, 2, 1, 3});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4}));
    deleteList(result);
}

TEST(SortList, Example2) {
    Solution s;
    ListNode* head = createList({-1, 5, 3, 4, 0});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({-1, 0, 3, 4, 5}));
    deleteList(result);
}

TEST(SortList, Example3) {
    Solution s;
    ListNode* head = createList({});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({}));
    deleteList(result);
}

TEST(SortList, EmptyList) {
    Solution s;
    ListNode* result = s.sortList(nullptr);
    EXPECT_EQ(toVector(result), vector<int>({}));
}

TEST(SortList, SingleNode) {
    Solution s;
    ListNode* head = createList({1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1}));
    deleteList(result);
}

TEST(SortList, TwoNodesAscending) {
    Solution s;
    ListNode* head = createList({1, 2});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2}));
    deleteList(result);
}

TEST(SortList, TwoNodesDescending) {
    Solution s;
    ListNode* head = createList({2, 1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2}));
    deleteList(result);
}

TEST(SortList, TwoNodesEqual) {
    Solution s;
    ListNode* head = createList({1, 1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 1}));
    deleteList(result);
}

TEST(SortList, ThreeNodesSorted) {
    Solution s;
    ListNode* head = createList({1, 2, 3});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(SortList, ThreeNodesReversed) {
    Solution s;
    ListNode* head = createList({3, 2, 1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(SortList, ThreeNodesUnsorted) {
    Solution s;
    ListNode* head = createList({2, 3, 1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(SortList, AllSameValues) {
    Solution s;
    ListNode* head = createList({5, 5, 5, 5, 5});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({5, 5, 5, 5, 5}));
    deleteList(result);
}

TEST(SortList, AlreadySorted) {
    Solution s;
    ListNode* head = createList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    deleteList(result);
}

TEST(SortList, ReverseSorted) {
    Solution s;
    ListNode* head = createList({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    deleteList(result);
}

TEST(SortList, WithDuplicates) {
    Solution s;
    ListNode* head = createList({3, 1, 2, 1, 3, 2});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 1, 2, 2, 3, 3}));
    deleteList(result);
}

TEST(SortList, NegativeValues) {
    Solution s;
    ListNode* head = createList({-5, -1, -3, -2, -4});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({-5, -4, -3, -2, -1}));
    deleteList(result);
}

TEST(SortList, MixedPositiveNegative) {
    Solution s;
    ListNode* head = createList({-3, 5, -1, 0, 2, -4, 3});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({-4, -3, -1, 0, 2, 3, 5}));
    deleteList(result);
}

TEST(SortList, MinMaxValues) {
    Solution s;
    ListNode* head = createList({100000, -100000, 0, 50000, -50000});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({-100000, -50000, 0, 50000, 100000}));
    deleteList(result);
}

TEST(SortList, EvenLength) {
    Solution s;
    ListNode* head = createList({8, 3, 5, 1, 9, 2, 7, 4});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 7, 8, 9}));
    deleteList(result);
}

TEST(SortList, OddLength) {
    Solution s;
    ListNode* head = createList({8, 3, 5, 1, 9, 2, 7});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 5, 7, 8, 9}));
    deleteList(result);
}

TEST(SortList, LargeList100) {
    Solution s;
    vector<int> vals;
    for (int i = 100; i > 0; i--) vals.push_back(i);
    ListNode* head = createList(vals);
    ListNode* result = s.sortList(head);
    vector<int> expected;
    for (int i = 1; i <= 100; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(SortList, RandomOrder) {
    Solution s;
    vector<int> vals = {45, 23, 78, 12, 67, 34, 89, 56, 90, 1};
    ListNode* head = createList(vals);
    ListNode* result = s.sortList(head);
    sort(vals.begin(), vals.end());
    EXPECT_EQ(toVector(result), vals);
    deleteList(result);
}

TEST(SortList, ManyDuplicates) {
    Solution s;
    ListNode* head = createList({5, 2, 3, 5, 1, 3, 2, 5, 1, 3});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 1, 2, 2, 3, 3, 3, 5, 5, 5}));
    deleteList(result);
}

TEST(SortList, AlternatingPattern) {
    Solution s;
    ListNode* head = createList({1, 10, 2, 9, 3, 8, 4, 7, 5, 6});
    ListNode* result = s.sortList(head);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    deleteList(result);
}

TEST(SortList, Performance1000Nodes) {
    Solution s;
    
    vector<int> vals(1000);
    for (int i = 0; i < 1000; i++) vals[i] = 1000 - i;
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.sortList(head);
    }, result);
    
    vector<int> expected;
    for (int i = 1; i <= 1000; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance1000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SortList, Performance10000Nodes) {
    Solution s;
    
    vector<int> vals(10000);
    for (int i = 0; i < 10000; i++) vals[i] = 10000 - i;
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.sortList(head);
    }, result);
    
    vector<int> expected;
    for (int i = 1; i <= 10000; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance10000Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}

TEST(SortList, Performance50000NodesRandom) {
    Solution s;
    
    vector<int> vals(50000);
    mt19937 gen(42);
    uniform_int_distribution<> dis(-100000, 100000);
    for (int i = 0; i < 50000; i++) vals[i] = dis(gen);
    
    vector<int> expected = vals;
    sort(expected.begin(), expected.end());
    
    ListNode* head = createList(vals);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.sortList(head);
    }, result);
    
    EXPECT_EQ(toVector(result), expected);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance50000NodesRandom");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
