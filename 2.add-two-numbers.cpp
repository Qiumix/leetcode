// @leet start
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addTwoNumbers(l1, l2, 0);
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
    if (l1 != nullptr && l2 != nullptr) {
      int sum = l1->val + l2->val + carry;
      return new ListNode(sum % 10,
                          addTwoNumbers(l1->next, l2->next, sum / 10));
    }
    if (l1 == nullptr && l2 == nullptr) {
      if (carry > 0) {
        return new ListNode(carry);
      }
      return nullptr;
    }
    if (l1 == nullptr) {
      int sum = l2->val + carry;
      return new ListNode(sum % 10, addTwoNumbers(l1, l2->next, sum / 10));
    }
    int sum = l1->val + carry;
    return new ListNode(sum % 10, addTwoNumbers(l1->next, l2, sum / 10));
  }
};
// @leet end
