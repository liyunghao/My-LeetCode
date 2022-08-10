/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 *	Runtime: 22ms
 *	language: C++
*/
/**
 * Definitio for a binary tree node.
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
    TreeNode* convert(vector<int>& nums, int l, int r) {
        int m = (l+r) >> 1;
        if (l >= r)
            return NULL;
        TreeNode* rt = new TreeNode(nums[m]);
        rt->left = convert(nums, l, m);
        rt->right = convert(nums, m+1, r);
        return rt;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size());
    }
};n
