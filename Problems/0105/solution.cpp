/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *	Runtime: 59ms
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
    int idx;
    TreeNode* build(vector<int>& pre, vector<int>& in, int left, int right) {
        if (left == right)
            return NULL;
        int pivot = 0, val = 0;
        for (int i = left; i < right; i++) {
            if (pre[idx] == in[i]) {
                pivot = i;
                val = in[i];
                break;
            }
        }
        idx++;
        TreeNode* cur = new TreeNode(val);
        cur->left = build(pre, in, left, pivot);
        cur->right = build(pre, in, pivot+1, right);
        return cur;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        return build(preorder, inorder, 0, preorder.size());
    }
};*
