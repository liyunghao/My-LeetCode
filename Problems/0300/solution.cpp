/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
 *	Runtime: 11ms
 *	language: C++
*/
class Solution {
pblic:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto x:nums) {
            auto iter = lower_bound(res.begin(), res.end(), x);
            if (iter != res.end()) 
                *iter = x;
            else 
                res.push_back(x);
        }
        return res.size();
    }
};u
