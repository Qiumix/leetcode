/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

 // struct ListNode {
 //     int val;
 //     ListNode* next;
 //     ListNode() : val(0), next(nullptr) {}
 //     ListNode(int x) : val(x), next(nullptr) {}
 //     ListNode(int x, ListNode* next) : val(x), next(next) {}
 // };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* sSmaller = new ListNode(0);
        ListNode* sBigger = new ListNode(0);
        ListNode* p1 = nullptr, * p2 = nullptr;
        ListNode* p;
        p1 = sSmaller;
        p2 = sBigger;
        p = head;
        while (p != nullptr) {
            if (p->val < x)
            {
                p1->next = p;
                p1 = p;
            }
            else {
                p2->next = p;
                p2 = p;
            }
            p = p->next;
        }
        p1->next = sBigger->next;
        head = sSmaller->next;
        p2->next = nullptr;
        delete(sSmaller);
        delete(sBigger);
        return head;
    }
};
// @lc code=end

