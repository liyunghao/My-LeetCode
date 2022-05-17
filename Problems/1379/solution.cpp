/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 *	Runtime: 732 ms
 *	language: C++
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* dfs(TreeNode* cur, int val) {
        if (!cur)
            return nullptr;
        if (cur->val == val) 
            return cur;
        auto l = dfs(cur->left, val);
        auto r = dfs(cur->right, val);
        if (l) 
            return l;
        else if (r)
            return r;
        return nullptr;
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target->val);
    }

};
