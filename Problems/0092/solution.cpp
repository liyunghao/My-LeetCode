/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/reverse-linked-list-ii/
 *	Runtime: 5ms
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        stack<int> st;
        ListNode* tmp = head;
        while (tmp) {
            if (idx >= left && idx <= right) {
                st.push(tmp->val);
            }
            if (idx == right)
                break;
            tmp = tmp->next;
            idx++;
        }
        tmp = head;
        idx = 1;
        while (!st.empty()) {
            if (idx >= left && idx <= right) {
                int val = st.top();
                st.pop();
                tmp->val = val;
            }
            tmp = tmp->next;
            idx++;
        }
        
        return head;
    }
};

