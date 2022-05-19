/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ 
 *	Runtime: 81ms 
 *	language: C++
*/

class Solution {
public:
	int dp[200][200]{};
    int n, m;
    int dfs(int x, int y, int prev, vector<vector<int>>& mat) {
        if ( x >= n || x < 0 || y >= m || y < 0 || mat[x][y] <= prev) 
            return 0;
        if (dp[x][y])
            return dp[x][y];
        int res = max({ dfs(x+1, y, mat[x][y], mat), 
                       dfs(x, y+1, mat[x][y], mat),
                       dfs(x-1, y, mat[x][y], mat),
                       dfs(x, y-1, mat[x][y], mat)});
        dp[x][y] = 1 + res;
        return dp[x][y];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int M = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                M = max(M, dfs(i, j, -1, matrix));    
            }
        }
        return M;
    }
};
