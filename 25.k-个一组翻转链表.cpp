/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
#include <list>
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        std::list<ListNode *> d;
        ListNode *sentinel = new ListNode(0);
        ListNode *sp = sentinel;
        ListNode *p = head;
        int count;
        bool remain = false;
        while (p != nullptr)
        {
            for (int i = 0; i < k; i++)
            {
                if (p == nullptr)
                {
                    remain = true;
                    break;
                }
                d.push_back(p);
                p = p->next;
            }
            if (remain)
            {
                break;
            }
            for (int i = 0; i < k; i++)
            {
                sp->next = d.back();
                d.pop_back();
                sp = sp->next;
            }
        }
        while (d.size() > 0)
        {
            sp->next = d.front();
            d.pop_front();
            sp = sp->next;
        }
        sp->next = nullptr;
        head = sentinel->next;
        delete (sentinel);
        return head;
    }
};
// @lc code=end
