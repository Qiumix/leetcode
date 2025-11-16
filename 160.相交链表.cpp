/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(nullptr) {}
//   static ListNode *of(int *arr, int len) {
//     ListNode *h = new ListNode(arr[0]);
//     int i = 1;
//     ListNode *p = h;
//     while (i < len--) {
//       p->next = new ListNode(arr[i]);
//       p = p->next;
//     }
//     return h;
//   }
// };

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA, *p2 = headB;
    int m = 1, n = 1;
    while (p1->next) {
      p1 = p1->next;
      m++;
    }
    while (p2->next) {
      p2 = p2->next;
      n++;
    }
    if (p1 != p2)
      return nullptr;
    p1 = headA, p2 = headB;
    if (m < n) {
      n -= m;
      while (n--)
        p2 = p2->next;
    } else {
      m -= n;
      while (m--)
        p1 = p1->next;
    }
    while (p1->next != nullptr && p2->next != nullptr) {
      if (p1 == p2) {
        return p1;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    if (p1 == p2) {
      return p1;
    }
    return nullptr;
  }
};
// // @lc code=end

// int main(int argc, char const *argv[]) {
//   int a[] = {4, 1, 8, 4, 5};
//   int b[] = {5, 6, 1, 8, 4, 5};
//   ListNode *ha = ListNode::of(a, 5);
//   ListNode *hb = ListNode::of(b, 6);
//   Solution::getIntersectionNode(ha, hb);
//   return 0;
// }
