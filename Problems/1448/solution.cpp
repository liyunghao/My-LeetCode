/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 *	Runtime: 150ms
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
    int cnt = 0;
    void dfs(TreeNode* t, int m) {
        if (!t)
            return;
        cnt += m > t->val ? 0 : 1;
        m = max(m, t->val);
        dfs(t->left, m);
        dfs(t->right, m);
        return;
    }
    int goodNodes(TreeNode* root) {
        const int _min = -1e4-1;
        dfs(root, _min);
        return cnt;
    }
};
