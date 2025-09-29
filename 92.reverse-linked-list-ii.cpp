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
    while (count != 0) {
      count--;
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    start->next = cur;
    return pre;
  }
};
// #include <iostream>
// int main() { ListNode *head = new ListNode(3, new ListNode(5, nullptr));
//   Solution t;
//   head = t.reverseBetween(head, 1, 2);
//   std::cout << std::endl
//             << head->val << std::endl
//             << head->next->val << std::endl;
// }
// @leet end
