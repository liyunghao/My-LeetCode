/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/max-area-of-island/
 *	Runtime: 38ms
 *	language: C++
*/
class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int m, n;
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (!grid[x][y]) 
            return 0;
        grid[x][y] = 0;
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            if (x+dx[i] >= m || y+dy[i] >= n || x+dx[i] < 0 || y+dy[i] < 0)
                continue;
            sum += dfs(grid, x+dx[i], y+dy[i]);
        }
        return 1+sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(dfs(grid, i, j), res);
            }
        }
        return res;
    }
};
