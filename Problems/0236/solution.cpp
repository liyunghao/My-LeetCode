/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 *	Runtime: 36ms
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
    bool dfs(TreeNode* t, stack<TreeNode*>& st, TreeNode* target) {
        st.push(t);
        if (t == target) 
            return 1;
        
        if (t->left && dfs(t->left, st, target)) 
            return 1;
        
        if (t->right && dfs(t->right, st, target))
            return 1;
        st.pop();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pst, qst;
        dfs(root, pst, p);
        dfs(root, qst, q);
        if (pst.size() < qst.size()) 
            swap(pst, qst);
        while (pst.size() != qst.size())
            pst.pop();
        while (pst.top() != qst.top()) {
            pst.pop();
            qst.pop();
        }
        return pst.top();
            
    }
};

