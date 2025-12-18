// tests/test_0023-merge-k-sorted-lists.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

// Helper function to create a linked list from vector
ListNode* createList(const std::vector<int>& values) {
  if (values.empty()) return nullptr;
  
  ListNode* head = new ListNode(values[0]);
  ListNode* curr = head;
  for (size_t i = 1; i < values.size(); i++) {
    curr->next = new ListNode(values[i]);
    curr = curr->next;
  }
  return head;
}

// Helper function to convert linked list to vector
std::vector<int> toVector(ListNode* head) {
  std::vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

// Helper function to delete a linked list
void deleteList(ListNode* head) {
  while (head) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}

// Example 1: Three lists [1,4,5], [1,3,4], [2,6]
TEST(MergeKSortedLists, Example1) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({1, 4, 5}),
    createList({1, 3, 4}),
    createList({2, 6})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Example 2: Empty array
TEST(MergeKSortedLists, EmptyArray) {
  Solution s;
  std::vector<ListNode*> lists;
  
  ListNode* result = s.mergeKLists(lists);
  EXPECT_EQ(result, nullptr);
}

// Example 3: Array with one empty list
TEST(MergeKSortedLists, OneEmptyList) {
  Solution s;
  std::vector<ListNode*> lists = {nullptr};
  
  ListNode* result = s.mergeKLists(lists);
  EXPECT_EQ(result, nullptr);
}

// Multiple empty lists
TEST(MergeKSortedLists, MultipleEmptyLists) {
  Solution s;
  std::vector<ListNode*> lists = {nullptr, nullptr, nullptr};
  
  ListNode* result = s.mergeKLists(lists);
  EXPECT_EQ(result, nullptr);
}

// Single non-empty list
TEST(MergeKSortedLists, SingleList) {
  Solution s;
  std::vector<ListNode*> lists = {createList({1, 2, 3, 4, 5})};
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Two lists with no overlap
TEST(MergeKSortedLists, TwoListsNoOverlap) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({1, 2, 3}),
    createList({4, 5, 6})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Two lists with complete overlap in values
TEST(MergeKSortedLists, TwoListsOverlap) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({1, 3, 5}),
    createList({2, 4, 6})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Lists with different lengths
TEST(MergeKSortedLists, DifferentLengths) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({1}),
    createList({1, 3, 4}),
    createList({2, 6})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 1, 2, 3, 4, 6};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// All lists have single element
TEST(MergeKSortedLists, AllSingleElement) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({5}),
    createList({1}),
    createList({3}),
    createList({2})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 5};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Lists with negative numbers
TEST(MergeKSortedLists, NegativeNumbers) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({-5, -3, -1}),
    createList({-4, -2, 0}),
    createList({-6, 1, 2})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {-6, -5, -4, -3, -2, -1, 0, 1, 2};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Lists with duplicate values
TEST(MergeKSortedLists, DuplicateValues) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({1, 1, 2}),
    createList({1, 1, 2}),
    createList({1, 2, 3})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 1, 1, 1, 1, 2, 2, 2, 3};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Mix of empty and non-empty lists
TEST(MergeKSortedLists, MixedEmptyNonEmpty) {
  Solution s;
  std::vector<ListNode*> lists = {
    nullptr,
    createList({1, 3}),
    nullptr,
    createList({2, 4}),
    nullptr
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Large k value with small lists
TEST(MergeKSortedLists, ManySmallLists) {
  Solution s;
  std::vector<ListNode*> lists;
  for (int i = 0; i < 10; i++) {
    lists.push_back(createList({i, i + 10}));
  }
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Lists with zeros
TEST(MergeKSortedLists, WithZeros) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({-1, 0, 1}),
    createList({0, 0, 2}),
    createList({-2, 0, 3})
  };
  
  ListNode* result = s.mergeKLists(lists);
  // Lists have 4 zeros total: one from list 1, two from list 2, one from list 3
  std::vector<int> expected = {-2, -1, 0, 0, 0, 0, 1, 2, 3};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Boundary values
TEST(MergeKSortedLists, BoundaryValues) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({-10000, 0}),
    createList({-5000, 5000}),
    createList({0, 10000})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {-10000, -5000, 0, 0, 5000, 10000};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// One very long list with other short lists
TEST(MergeKSortedLists, OneLongList) {
  Solution s;
  std::vector<int> longListValues;
  for (int i = 0; i < 100; i += 2) {
    longListValues.push_back(i);
  }
  
  std::vector<ListNode*> lists = {
    createList(longListValues),
    createList({1}),
    createList({3})
  };
  
  ListNode* result = s.mergeKLists(lists);
  auto resultVec = toVector(result);
  EXPECT_EQ(resultVec.size(), 52);
  EXPECT_EQ(resultVec[0], 0);
  EXPECT_EQ(resultVec[1], 1);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}

// Lists in reverse sorted order (still individually sorted ascending)
TEST(MergeKSortedLists, ListsInReverseOrder) {
  Solution s;
  std::vector<ListNode*> lists = {
    createList({7, 8, 9}),
    createList({4, 5, 6}),
    createList({1, 2, 3})
  };
  
  ListNode* result = s.mergeKLists(lists);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(toVector(result), expected);
  
  // Only delete result since it reuses the original list nodes
  deleteList(result);
}
