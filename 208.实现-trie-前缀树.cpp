/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Trie {
public:
  Trie() { sentinel = new Node(0); }

  void insert(string word) {
    Node *p = createToEnd(word);
    p->color = true;
  }

  bool search(string word) {
    Node *p = sentinel;
    for (int i = 0; i < word.length(); i++) {
      char cur = word[i];
      if (p->child.find(cur) == p->child.end()) {
        return false;
      }
      p = p->child[cur];
    }
    return p->color;
  }

  bool startsWith(string prefix) {
    Node *p = sentinel;
    for (int i = 0; i < prefix.length(); i++) {
      char cur = prefix[i];
      if (p->child.find(cur) == p->child.end()) {
        return false;
      }
      p = p->child[cur];
    }
    return true;
  }

private:
  class Node {
  public:
    bool color;
    char c;
    unordered_map<char, Node *> child;
    Node(char c) : c(c), color(false) {}
  };
  Node *sentinel;
  Node *createToEnd(string word) {
    Node *p = sentinel;
    for (int i = 0; i < word.length(); i++) {
      char cur = word[i];
      if (p->child.find(cur) == p->child.end()) {
        p->child[cur] = new Node(cur);
      }
      p = p->child[cur];
    }
    return p;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
