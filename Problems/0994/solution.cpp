/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: http://leetcode.com/problems/rotting-oranges/s
 *	Runtime: 10ms
 *	language: C++
*/
class Solution {
public:
    vector<vector<int>> dis;
    int m, n;
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dis.resize(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int curx = x+dx[i], cury = y+dy[i];
                if (curx < 0 || curx >= m || cury < 0 || cury >= n || grid[curx][cury] != 1)
                    continue;
                q.push({curx, cury});
                grid[curx][cury] = 2;
                dis[curx][cury] = dis[x][y]+1;
            }
        }
        int M = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
                M = max(M, dis[i][j]);
            }
        }
        return M;
    }
};
