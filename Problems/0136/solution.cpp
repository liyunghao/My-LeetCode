/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/single-number/
 *	Runtime: 20ms
 *	language: C++
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto x:nums) {
            res ^= x;
        }
        return res;
    }
};
