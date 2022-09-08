/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/construct-string-from-binary-tree/
 *	Runtime: 24ms
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
    string res;
    void dfs(TreeNode* t) {
        if (!t)
            return;
        res += to_string(t->val);
        if (t->left) {
            res += '(';
            dfs(t->left);
            res += ')';
        } else if (t->right) {
            res += "()";
        }        
        if (t->right) {
            res += '(';
            dfs(t->right);
            res += ')';
        }
        return;
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }
};
