// @leet start
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode *sentinel = new ListNode(0, head);
    ListNode *p = sentinel;
    while (--left) {
      p = p->next;
    }
    p->next = helper(p->next, right - left);
    head = sentinel->next;
    delete sentinel;
    return head;
  }

private:
  ListNode *helper(ListNode *start, int count) {
    ListNode *pre = start, *cur = pre->next, *nxt = cur->next;
    while (count--) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    start->next = cur;
    return pre;
  }
};
