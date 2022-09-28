/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *	Runtime: 11ms
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* cur = head;
        while (cur) {
            v.push_back(cur);
            cur = cur->next;
        }
        int sz = v.size();
        if (n == sz) {
            return head->next;
        } else {
            v[sz-n-1]->next = n == 1 ? NULL : v[sz-n+1];
            return head;
        }
    }
};
