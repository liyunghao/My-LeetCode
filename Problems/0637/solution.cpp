/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/
 *	Runtime: 15ms
 *	language: C++
*/
/*
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
    vector<double> res;
    vector<int> cnt;
    void dfs(TreeNode* t, int d) {
        if (!t)
            return;
        if (res.size() <= d) {
            res.push_back(0.0);
            cnt.push_back(0);
        }
        res[d] += t->val;
        ++cnt[d];
        
        dfs(t->left, ++d);
        dfs(t->right, d);
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        int i;
        for (i = 0; i < res.size(); i++) {         
            res[i] /= cnt[i];
        }
        res.resize(i);
        return res;
    }
};*
