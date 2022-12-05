/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr)
                break;
            head = head->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        return head;
    }
};
