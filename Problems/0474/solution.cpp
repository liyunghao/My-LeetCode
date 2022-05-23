/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/ones-and-zeroes/
 *	Runtime: 70ms
 *	language: C++
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]{};
        for (auto s : strs) {
            int zero = count(s.begin(), s.end(), '0');
            int one = s.size() - zero;
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], 1+dp[i-zero][j-one]);
                }
            }
        }
        return dp[m][n];
    }

};
