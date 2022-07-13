/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 *	Runtime: 0ms
 *	language: C++
*/

class Solution {
public:
	vector<vector<int>> res;
    int cnt;
    void dfs(TreeNode* t, int depth) {
        if (!t)
            return;
        cnt++;
        res[depth].push_back(t->val);
        dfs(t->left, depth+1);
        dfs(t->right, depth+1);
        return;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        cnt = 0;
        res.resize(1005, vector<int>());
        dfs(root, 0);
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            if (iter->size() == 0) {
                res.erase(iter, res.end());
                break;
            } 
        }
        return res;
    }

};
