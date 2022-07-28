/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/add-two-numbers/
 *	Runtime: 43ms
 *	language: C++
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (true) {
            cur->next = new ListNode(0);
            cur = cur->next;
            if (l1) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            if (!l1 && !l2) {
                break;
            }
        }
        cur = res;
        while (cur) {
            if (cur->val >= 10) {
                cur->val -= 10;
                if (!cur->next) {
                    cur->next = new ListNode(1);
                } else {
                    cur->next->val++;
                }
            }
            cur = cur->next;
        }
        return res->next;
    }
};
