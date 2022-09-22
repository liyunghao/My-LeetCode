/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 *	Runtime: 179ms
 *	language: C++
*/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long int sum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!(nums[i] % 2))
                sum += nums[i];
        }
        for (auto x : queries) {
            int val = x[0], idx = x[1];
            if (nums[idx] % 2) {
                nums[idx] += val;
                if (val % 2) {
                    sum += nums[idx];
                }
            } else {
                sum -= nums[idx];
                nums[idx] += val;
                if (!(val % 2)) {
                    sum += nums[idx];
                }
            }
            res.push_back(sum);
        }

        return res;
    }
};
