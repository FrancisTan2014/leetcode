// tests/test_0021-merge-two-sorted-lists.cpp
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

TEST(MergeTwoLists, Example1) {
    Solution s;
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 1, 2, 3, 4, 4}));
    deleteList(result);
}

TEST(MergeTwoLists, Example2) {
    Solution s;
    ListNode* list1 = createList({});
    ListNode* list2 = createList({});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({}));
    deleteList(result);
}

TEST(MergeTwoLists, Example3) {
    Solution s;
    ListNode* list1 = createList({});
    ListNode* list2 = createList({0});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({0}));
    deleteList(result);
}

TEST(MergeTwoLists, BothEmpty) {
    Solution s;
    ListNode* result = s.mergeTwoLists(nullptr, nullptr);
    EXPECT_EQ(toVector(result), vector<int>({}));
}

TEST(MergeTwoLists, FirstEmpty) {
    Solution s;
    ListNode* list2 = createList({1, 2, 3});
    ListNode* result = s.mergeTwoLists(nullptr, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(MergeTwoLists, SecondEmpty) {
    Solution s;
    ListNode* list1 = createList({1, 2, 3});
    ListNode* result = s.mergeTwoLists(list1, nullptr);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3}));
    deleteList(result);
}

TEST(MergeTwoLists, SingleNodeEach) {
    Solution s;
    ListNode* list1 = createList({1});
    ListNode* list2 = createList({2});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2}));
    deleteList(result);
}

TEST(MergeTwoLists, SingleNodeEachReverse) {
    Solution s;
    ListNode* list1 = createList({2});
    ListNode* list2 = createList({1});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2}));
    deleteList(result);
}

TEST(MergeTwoLists, SingleNodeEachEqual) {
    Solution s;
    ListNode* list1 = createList({1});
    ListNode* list2 = createList({1});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 1}));
    deleteList(result);
}

TEST(MergeTwoLists, AllFromFirst) {
    Solution s;
    ListNode* list1 = createList({1, 2, 3});
    ListNode* list2 = createList({4, 5, 6});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6}));
    deleteList(result);
}

TEST(MergeTwoLists, AllFromSecond) {
    Solution s;
    ListNode* list1 = createList({4, 5, 6});
    ListNode* list2 = createList({1, 2, 3});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6}));
    deleteList(result);
}

TEST(MergeTwoLists, Interleaved) {
    Solution s;
    ListNode* list1 = createList({1, 3, 5});
    ListNode* list2 = createList({2, 4, 6});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6}));
    deleteList(result);
}

TEST(MergeTwoLists, DifferentLengths) {
    Solution s;
    ListNode* list1 = createList({1, 2});
    ListNode* list2 = createList({3, 4, 5, 6});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6}));
    deleteList(result);
}

TEST(MergeTwoLists, DifferentLengthsReverse) {
    Solution s;
    ListNode* list1 = createList({1, 2, 3, 4});
    ListNode* list2 = createList({5, 6});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 3, 4, 5, 6}));
    deleteList(result);
}

TEST(MergeTwoLists, AllEqual) {
    Solution s;
    ListNode* list1 = createList({1, 1, 1});
    ListNode* list2 = createList({1, 1, 1});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 1, 1, 1, 1, 1}));
    deleteList(result);
}

TEST(MergeTwoLists, NegativeValues) {
    Solution s;
    ListNode* list1 = createList({-10, -5, 0});
    ListNode* list2 = createList({-8, -3, 5});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({-10, -8, -5, -3, 0, 5}));
    deleteList(result);
}

TEST(MergeTwoLists, MinMaxValues) {
    Solution s;
    ListNode* list1 = createList({-100, 0, 100});
    ListNode* list2 = createList({-99, 1, 99});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({-100, -99, 0, 1, 99, 100}));
    deleteList(result);
}

TEST(MergeTwoLists, DuplicatesInBoth) {
    Solution s;
    ListNode* list1 = createList({1, 2, 2, 3});
    ListNode* list2 = createList({2, 3, 3, 4});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vector<int>({1, 2, 2, 2, 3, 3, 3, 4}));
    deleteList(result);
}

TEST(MergeTwoLists, LongList1) {
    Solution s;
    vector<int> vals1(25);
    for (int i = 0; i < 25; i++) vals1[i] = i * 2;
    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList({5, 15, 25});
    ListNode* result = s.mergeTwoLists(list1, list2);
    vector<int> expected = {0, 2, 4, 5, 6, 8, 10, 12, 14, 15, 16, 18, 20, 22, 24, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48};
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(MergeTwoLists, LongList2) {
    Solution s;
    ListNode* list1 = createList({5, 15, 25});
    vector<int> vals2(25);
    for (int i = 0; i < 25; i++) vals2[i] = i * 2;
    ListNode* list2 = createList(vals2);
    ListNode* result = s.mergeTwoLists(list1, list2);
    vector<int> expected = {0, 2, 4, 5, 6, 8, 10, 12, 14, 15, 16, 18, 20, 22, 24, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48};
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(MergeTwoLists, MaxSize) {
    Solution s;
    vector<int> vals1(25);
    vector<int> vals2(25);
    for (int i = 0; i < 25; i++) {
        vals1[i] = i * 2;
        vals2[i] = i * 2 + 1;
    }
    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);
    ListNode* result = s.mergeTwoLists(list1, list2);
    vector<int> expected;
    for (int i = 0; i < 50; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    deleteList(result);
}

TEST(MergeTwoLists, MaxSizeAllFromFirst) {
    Solution s;
    vector<int> vals1(50);
    for (int i = 0; i < 50; i++) vals1[i] = i;
    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList({});
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vals1);
    deleteList(result);
}

TEST(MergeTwoLists, MaxSizeAllFromSecond) {
    Solution s;
    ListNode* list1 = createList({});
    vector<int> vals2(50);
    for (int i = 0; i < 50; i++) vals2[i] = i;
    ListNode* list2 = createList(vals2);
    ListNode* result = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(toVector(result), vals2);
    deleteList(result);
}

TEST(MergeTwoLists, Performance50Nodes) {
    Solution s;
    
    vector<int> vals1(25);
    vector<int> vals2(25);
    for (int i = 0; i < 25; i++) {
        vals1[i] = i * 2;
        vals2[i] = i * 2 + 1;
    }
    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);
    
    PerformanceMonitor monitor(100.0, 1024);
    ListNode* result;
    auto metrics = monitor.measureWithReturn([&]() {
        return s.mergeTwoLists(list1, list2);
    }, result);
    
    vector<int> expected;
    for (int i = 0; i < 50; i++) expected.push_back(i);
    EXPECT_EQ(toVector(result), expected);
    
    deleteList(result);
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance50Nodes");
    EXPECT_PERFORMANCE(metrics, 100.0, 1024);
}
