/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/number-of-islands/
 *	Runtime: 50ms
 *	language: C++
*/
class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int m, n;
    int dfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '0')
            return 0;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            dfs(nx, ny, grid);
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += dfs(i, j, grid);
            }
        }
        return res;
    }
};
