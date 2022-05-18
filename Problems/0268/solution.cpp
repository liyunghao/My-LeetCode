/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/missing-number/ 
 *	Runtime: 20ms 
 *	language: C++
*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
        int l = nums.size();
        int r = l;
        for (int i = 0; i < l; i++) {
            r ^= i;
            r ^= nums[i];
        }
        return r;
    }

};
