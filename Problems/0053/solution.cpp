/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/maximum-subarray/
 *	Runtime: 122
 *	language: C++
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -1e5, cur = 0;
        for (auto x:nums) {
            cur += x;
            res = cur > res ? cur : res;
            cur = cur > 0 ? cur : 0;
        }
        return res;
    }
};
