/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/unique-paths/
 *	Runtime: 4ms
 *	language: C++
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+2, vector<int>(n+2, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
