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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    return reverseList(addTwoNumbers(l1, l2, 0));
  }
  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = pre; // 把 cur 插在 pre 链表的前面（头插法）
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
    if (!l1 && !l2) {
      if (carry) {
        return new ListNode(carry);
      }
      return nullptr;
    }
    if (!l1) {
      int sum = l2->val + carry;
      return new ListNode(sum % 10, addTwoNumbers(l1, l2->next, sum / 10));
    }
    if (!l2) {
      int sum = l1->val + carry;
      return new ListNode(sum % 10, addTwoNumbers(l1->next, l2, sum / 10));
    }
    int sum = l1->val + carry + l2->val;
    return new ListNode(sum % 10, addTwoNumbers(l1->next, l2->next, sum / 10));
  }
};
// @leet end
