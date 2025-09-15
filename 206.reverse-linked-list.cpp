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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *ans = new ListNode(head->val), *p = head->next;
    while (p != nullptr) {
      ans = new ListNode(p->val, ans);
      p = p->next;
    }
    return ans;
  }
};
// @leet end
