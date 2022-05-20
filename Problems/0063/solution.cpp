/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/unique-paths-ii/ 
 *	Runtime: 0ms
 *	language: C++
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[100][100]{};
        if (obstacleGrid[0][0])
            return 0;
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j])
                    continue;
                if (i == 0) {
                    if (j == 0) continue;
                    dp[i][j] = dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
                }
            }
        }   
        return dp[m-1][n-1];
    }

};
