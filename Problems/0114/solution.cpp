/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
 *	Runtime: 11ms
 *	language: C++
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* t, stack<TreeNode*>& st) {
        if (!t)
            return NULL;
        if (t->right) {
            st.push(t->right);
        }
        if (t->left) {
            t->right = t->left;
            t->left = NULL;
            return dfs(t->right, st);
        }
        return t;
    }
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = dfs(root, st);
        while (!st.empty()) {
            TreeNode* next = st.top();
            st.pop();
            cur->right = next;
            cur = dfs(next, st);
        }
        return;
        
    }
};

