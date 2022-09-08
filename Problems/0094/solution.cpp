/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *	Runtime: 0ms
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
    vector<int> res;
    void dfs(TreeNode* t) {
        if (!t)
            return;
        dfs(t->left);
        res.push_back(t->val);
        dfs(t->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
