/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leecode.com/problems/partition-list/t
 *	Runtime: 6ms 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *sm = new ListNode(), *lg = new ListNode();
        ListNode *smh, *lgh;
        smh = sm;
        lgh = lg;
        while (head) {
            if (head->val >= x) {
                lg->next = head;
                lg = head;
                head = head->next;
                lg->next = NULL;
            } else {
                sm->next = head;
                sm = head;
                head = head->next;
                sm->next = NULL;
            }
        }
        sm->next = lgh->next;
        return smh->next;
    }
};

