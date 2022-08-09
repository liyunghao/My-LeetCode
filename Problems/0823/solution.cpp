/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/binary-trees-with-factors/
 *	Runtime: 273 ms
 *	language: C++
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int m = 1e9+7;
        int n = arr.size();
        unordered_map<int, long long int> dp;
        dp[arr[0]] = 1;
       
        for (int i = 1; i < n; i++) {
            long long int cnt = 1;
            for (auto x:dp) {
                int res = arr[i] % x.first;
                int fac = arr[i] / x.first;
                if (res == 0 && dp.find(fac) != dp.end()) {
                    cnt = (cnt + (dp[fac] * dp[x.first]) % m) % m;
                }
            }
            dp[arr[i]] = cnt;
        }
        int ans = 0;
        for (auto x:dp) {
            ans = (ans + x.second) % m;
        }
        return ans;
    }
};
