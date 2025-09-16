/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr) {
      if (fast->next == nullptr) {
        return nullptr;
      }
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        ListNode *p = head;
        while (p != slow) {
          p = p->next;
          slow = slow->next;
        }
        return p;
      }
    }
    return nullptr;
  }
};
// @lc code=end
