/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/balanced-binary-tree/ 
 *	Time complexity: O()
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
    bool flag;
    int dfs(TreeNode* t) {
        if (!flag || !t)
            return 0;
        int hl = dfs(t->left);
        int hr = dfs(t->right);
        if (abs(hl - hr) >= 2) {
            flag = false;
            return 0;
        }
        //cout << t->val << ' ' << 1+max(hl, hr) << '\n';
        return 1+max(hl, hr);            
    }

    bool isBalanced(TreeNode* root) {
        flag = true;
        dfs(root);
        return flag;
    }
};
