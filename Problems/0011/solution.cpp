/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/container-with-most-water/submissions/
 *	Runtime: 267ms  
 *	language: C++
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0;
        while (l != r) {
            int sum = (r - l) * min(height[l], height[r]);
            res = max(res, sum);
            if (height[r] > height[l])
                ++l;
            else
                --r;
        }
        return res;
    }
};
