/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0 || head->next == nullptr) {
            return head;
        }
        int size = 1;
        ListNode* p = head;
        ListNode* end;
        while (p->next != nullptr)
        {
            size++;
            p = p->next;
        }
        k = (size - k % size) % size;
        if (k == 0)
        {
            return head;
        }
        end = p;
        p = head;
        while (--k) {
            p = p->next;
        }
        ListNode* newP = p->next;
        p->next = nullptr;
        end->next = head;
        return newP;
    }
};
// @lc code=end

