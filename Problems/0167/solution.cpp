/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
 *	Runtime: 35ms
 *	language: C++
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            long long int sum = numbers[l] + numbers[r];
            if (sum == target) 
                return {l+1, r+1};
            if (sum > target) {
                --r;
            } else {
                ++l;
            }
        }
        return {};
    }
};
