/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }
        vector<int> res;
        for (auto q : queries) {
            int l = 0, r = n;
            int m;
            int sz = -1;
            while (l != r) {
                m = (l + r) >> 1;
                if (q >= nums[m]) {
                    l = m+1;
                    sz = m;
                } else {
                    r = m;
                }
            }
            res.push_back(sz+1);
        }
        return res;
    }
};
