/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/out-of-boundary-paths/
 *	Runtime: 18ms
 *	language: C++
*/

class Solution {
public:
    int dp[55][55][55] = {0};
    const int mod = 1e9+7;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp[0][startRow+1][startColumn+1] = 1;
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    int tmp = dp[k-1][i][j];
                    dp[k][i+1][j] =  (dp[k][i+1][j] + tmp) % mod;
                    dp[k][i-1][j] =  (dp[k][i-1][j] + tmp) % mod;
                    dp[k][i][j+1] =  (dp[k][i][j+1] + tmp) % mod;
                    dp[k][i][j-1] =  (dp[k][i][j-1] + tmp) % mod;
                }
            }
        }
        int res = 0;
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 1; i <= m; i++) {
                res = (res + dp[k][i][0]) % mod;
                res = (res + dp[k][i][n+1]) % mod;
            }
            for (int j = 1; j <= n; j++) {
                res = (res + dp[k][0][j]) % mod;
                res = (res + dp[k][m+1][j]) % mod;
            }
        }
        return res; 
    }
};
