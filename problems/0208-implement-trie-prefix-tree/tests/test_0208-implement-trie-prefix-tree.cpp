#include <gtest/gtest.h>
#include "../solution.cpp"

class TrieTest : public ::testing::Test {
 protected:
  Trie* trie;
  
  void SetUp() override {
    trie = new Trie();
  }
  
  void TearDown() override {
    delete trie;
  }
};

// Example from problem description
TEST_F(TrieTest, Example1) {
  trie->insert("apple");
  EXPECT_TRUE(trie->search("apple"));
  EXPECT_FALSE(trie->search("app"));
  EXPECT_TRUE(trie->startsWith("app"));
  trie->insert("app");
  EXPECT_TRUE(trie->search("app"));
}

// Empty trie
TEST_F(TrieTest, EmptyTrie) {
  EXPECT_FALSE(trie->search("test"));
  EXPECT_FALSE(trie->startsWith("test"));
}

// Single character word
TEST_F(TrieTest, SingleCharacter) {
  trie->insert("a");
  EXPECT_TRUE(trie->search("a"));
  EXPECT_TRUE(trie->startsWith("a"));
  EXPECT_FALSE(trie->search("ab"));
}

// Multiple words with common prefix
TEST_F(TrieTest, CommonPrefix) {
  trie->insert("app");
  trie->insert("apple");
  trie->insert("application");
  
  EXPECT_TRUE(trie->search("app"));
  EXPECT_TRUE(trie->search("apple"));
  EXPECT_TRUE(trie->search("application"));
  EXPECT_TRUE(trie->startsWith("app"));
  EXPECT_TRUE(trie->startsWith("appl"));
  EXPECT_FALSE(trie->search("appl"));
}

// Word is prefix of another
TEST_F(TrieTest, WordAsPrefix) {
  trie->insert("apple");
  EXPECT_TRUE(trie->startsWith("app"));
  EXPECT_FALSE(trie->search("app"));
  
  trie->insert("app");
  EXPECT_TRUE(trie->search("app"));
  EXPECT_TRUE(trie->search("apple"));
}

// Multiple unrelated words
TEST_F(TrieTest, UnrelatedWords) {
  trie->insert("cat");
  trie->insert("dog");
  trie->insert("bird");
  
  EXPECT_TRUE(trie->search("cat"));
  EXPECT_TRUE(trie->search("dog"));
  EXPECT_TRUE(trie->search("bird"));
  EXPECT_FALSE(trie->search("cats"));
  EXPECT_FALSE(trie->search("do"));
}

// Prefix doesn't exist
TEST_F(TrieTest, PrefixDoesntExist) {
  trie->insert("hello");
  EXPECT_FALSE(trie->startsWith("world"));
  EXPECT_TRUE(trie->startsWith("he"));
  EXPECT_TRUE(trie->startsWith("hell"));
  EXPECT_TRUE(trie->startsWith("hello"));
}

// Same word inserted multiple times
TEST_F(TrieTest, DuplicateInserts) {
  trie->insert("test");
  trie->insert("test");
  trie->insert("test");
  
  EXPECT_TRUE(trie->search("test"));
  EXPECT_TRUE(trie->startsWith("tes"));
}

// Long word
TEST_F(TrieTest, LongWord) {
  string longWord = "abcdefghijklmnopqrstuvwxyz";
  trie->insert(longWord);
  
  EXPECT_TRUE(trie->search(longWord));
  EXPECT_TRUE(trie->startsWith("abcdefg"));
  EXPECT_FALSE(trie->search("abcdefg"));
}

// Words with similar endings
TEST_F(TrieTest, SimilarEndings) {
  trie->insert("bat");
  trie->insert("cat");
  trie->insert("rat");
  
  EXPECT_TRUE(trie->search("bat"));
  EXPECT_TRUE(trie->search("cat"));
  EXPECT_TRUE(trie->search("rat"));
  EXPECT_FALSE(trie->search("at"));
  EXPECT_TRUE(trie->startsWith("ba"));
  EXPECT_TRUE(trie->startsWith("ca"));
  EXPECT_TRUE(trie->startsWith("ra"));
}

// Nested prefixes
TEST_F(TrieTest, NestedPrefixes) {
  trie->insert("a");
  trie->insert("ab");
  trie->insert("abc");
  trie->insert("abcd");
  
  EXPECT_TRUE(trie->search("a"));
  EXPECT_TRUE(trie->search("ab"));
  EXPECT_TRUE(trie->search("abc"));
  EXPECT_TRUE(trie->search("abcd"));
  EXPECT_TRUE(trie->startsWith("a"));
  EXPECT_TRUE(trie->startsWith("ab"));
  EXPECT_TRUE(trie->startsWith("abc"));
  EXPECT_TRUE(trie->startsWith("abcd"));
  EXPECT_FALSE(trie->search("abcde"));
}

// Search for longer word than inserted
TEST_F(TrieTest, SearchLongerWord) {
  trie->insert("test");
  EXPECT_FALSE(trie->search("testing"));
  EXPECT_FALSE(trie->startsWith("testing"));
}

// All same character
TEST_F(TrieTest, AllSameCharacter) {
  trie->insert("aaa");
  trie->insert("aaaa");
  
  EXPECT_TRUE(trie->search("aaa"));
  EXPECT_TRUE(trie->search("aaaa"));
  EXPECT_FALSE(trie->search("aa"));
  EXPECT_TRUE(trie->startsWith("aa"));
  EXPECT_TRUE(trie->startsWith("aaa"));
  EXPECT_TRUE(trie->startsWith("aaaa"));
}

// Complex branching
TEST_F(TrieTest, ComplexBranching) {
  trie->insert("apple");
  trie->insert("apply");
  trie->insert("application");
  trie->insert("banana");
  trie->insert("band");
  
  EXPECT_TRUE(trie->search("apple"));
  EXPECT_TRUE(trie->search("apply"));
  EXPECT_TRUE(trie->search("application"));
  EXPECT_TRUE(trie->search("banana"));
  EXPECT_TRUE(trie->search("band"));
  
  EXPECT_TRUE(trie->startsWith("app"));
  EXPECT_TRUE(trie->startsWith("ban"));
  EXPECT_FALSE(trie->search("app"));
  EXPECT_FALSE(trie->search("ban"));
}

// Empty string edge case (if allowed by constraints)
TEST_F(TrieTest, MixedOperations) {
  trie->insert("word");
  EXPECT_TRUE(trie->search("word"));
  EXPECT_FALSE(trie->search("wor"));
  EXPECT_TRUE(trie->startsWith("wor"));
  
  trie->insert("words");
  EXPECT_TRUE(trie->search("word"));
  EXPECT_TRUE(trie->search("words"));
  EXPECT_TRUE(trie->startsWith("word"));
}

// Alphabet coverage
TEST_F(TrieTest, AlphabetCoverage) {
  trie->insert("abc");
  trie->insert("xyz");
  trie->insert("mno");
  
  EXPECT_TRUE(trie->search("abc"));
  EXPECT_TRUE(trie->search("xyz"));
  EXPECT_TRUE(trie->search("mno"));
  EXPECT_TRUE(trie->startsWith("ab"));
  EXPECT_TRUE(trie->startsWith("xy"));
  EXPECT_TRUE(trie->startsWith("mn"));
}

// Single branch path
TEST_F(TrieTest, SingleBranchPath) {
  trie->insert("abcdefghij");
  
  EXPECT_TRUE(trie->search("abcdefghij"));
  EXPECT_TRUE(trie->startsWith("abc"));
  EXPECT_TRUE(trie->startsWith("abcdef"));
  EXPECT_FALSE(trie->search("abc"));
  EXPECT_FALSE(trie->search("abcdef"));
}

// Star pattern (multiple words from same prefix)
TEST_F(TrieTest, StarPattern) {
  trie->insert("ta");
  trie->insert("tb");
  trie->insert("tc");
  trie->insert("td");
  
  EXPECT_TRUE(trie->search("ta"));
  EXPECT_TRUE(trie->search("tb"));
  EXPECT_TRUE(trie->search("tc"));
  EXPECT_TRUE(trie->search("td"));
  EXPECT_TRUE(trie->startsWith("t"));
  EXPECT_FALSE(trie->search("t"));
}
