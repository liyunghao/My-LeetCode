/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/3sum/
 *	Runtime: 350ms
 *	language: C++
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l+1<r && nums[l]==nums[l+1]) l++;
                    while(l<r-1 && nums[r]==nums[r-1]) r--;
                    l++; r--;
                } else if (nums[l] + nums[r] > -nums[i]) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());
        return res;
    }
};
