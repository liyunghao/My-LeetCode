/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/jump-game
 *  Time complexity: O()
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (i + nums[i] >= idx)
                idx = i;
        }
        return idx == 0;
    }
};
