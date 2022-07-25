/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *	Runtime: 12ms
 *	language: C++
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int ul = 0, ur = nums.size();
        int ll = 0, lr = nums.size();
        int um = -1, lm = -1;
        while (ul != ur) {
            int u = (ul+ur) >> 1;
            if (nums[u] > target) {
                ur = u;
            } else if (nums[u] < target){
                ul = u+1;
            } else {
                ul = u+1;
                um = u;
            }            
        }
        while (ll != lr) {
            int l = (ll+lr) >> 1;
            if (nums[l] > target) {
                lr = l;
            } else if (nums[l] < target){
                ll = l+1;
            } else {
                lr = l;
                lm = l;
            }
        }
        return vector<int>({lm, um});
    }
}
