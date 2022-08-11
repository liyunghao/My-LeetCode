/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
 *	Runtime: 29ms
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
    vector<int> v;
    void dfs(TreeNode* t) {
        if (!t)
            return;
        dfs(t->left);
        v.push_back(t->val);
        dfs(t->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] >= v[i+1])
                return false;
        }
        return true;
    }
};
