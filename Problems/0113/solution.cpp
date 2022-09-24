/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/path-sum-ii/ 
 *	Runtime: 18ms
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
    vector<int> path;
    vector<vector<int>> res;
    void dfs(TreeNode* t, int curSum, int targetSum) {
        if (!t)
            return;
        curSum += t->val;
        path.push_back(t->val);
        if (!t->left && !t->right && curSum == targetSum) {
            res.push_back(path);
        }
            
        dfs(t->left, curSum, targetSum);
        dfs(t->right, curSum, targetSum);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return res;
    }
};
