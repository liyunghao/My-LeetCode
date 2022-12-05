/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: 
 *  Time complexity: O(N)
 *	language: C++
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = nums[0];
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != cur) {
                nums[idx++] = nums[i];
                cur = nums[i];
            }
        }
        return idx;
    }
};
