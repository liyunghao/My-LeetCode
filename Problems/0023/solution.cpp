/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        int n = lists.size();
        auto cmp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            if (lists[i])
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            if (tmp->next)
                pq.push(tmp->next);
            cur->next = tmp;
            cur = cur->next;
        }
        return res->next;
    }
};
