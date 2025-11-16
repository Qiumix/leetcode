struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  static ListNode *of(int *arr, int len) {
    ListNode *h = new ListNode(arr[0]);
    int i = 1;
    ListNode *p = h;
    while (i < len) {
      p->next = new ListNode(arr[i++]);
      p = p->next;
    }
    return h;
  }
};
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start

class Solution {
public:
  static bool isPalindrome(ListNode *head) {
    int n = 0;
    ListNode *p = head;
    while (p) {
      n++;
      p = p->next;
    }
    int half;
    if (n % 2) {
      half = n / 2 + 1;
    } else {
      half = n / 2;
    }
    p = head;
    while (--half) {
      p = p->next;
    }
    p->next = reverse(p->next);
    ListNode *front = head, *end;
    if (n % 2) {
      end = p->next;
    } else {
      end = p->next;
    }
    half = n / 2;
    while (half--) {
      if (end->val != front->val) {
        return false;
      }
      end = end->next;
      front = front->next;
    }
    p->next = reverse(p->next);
    return true;
  }
  static ListNode *reverse(ListNode *head) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr, cur = head;
    while (cur) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 2, 1};
  ListNode *h = ListNode::of(a, 4);
  Solution::isPalindrome(h);
  int b[] = {1, 2, 3, 2, 1};
  h = ListNode::of(b, 5);
  Solution::isPalindrome(h);
  return 0;
}
