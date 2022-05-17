/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link:  https://leetcode.com/problems/shortest-path-in-binary-matrix/
 *	Runtime: 82 ms	
 *	language: C++
*/

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int _x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int _y[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        bool visited[100][100];
        int dis[100][100];
        int n = grid.size()-1;
        memset(visited, 0, sizeof(visited));
        memset(dis, 0x3f3f3f3f, sizeof(dis));
        queue<pair<int, int> > q;
        
        if (grid[0][0] == 0)
            q.push(make_pair(0, 0));
        visited[0][0] = 1;
        dis[0][0] = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int curx = p.first, cury = p.second;
            if (curx == n && cury == n)
                return dis[n][n];
            for (int i = 0; i < 8; i++) {
                int nxtx = curx+_x[i], nxty = cury+_y[i];
                if ( nxtx < 0 || nxtx > n || nxty < 0 || nxty > n)
                    continue;
                if (grid[nxtx][nxty] == 0 && visited[nxtx][nxty] == 0) {
                    visited[nxtx][nxty] = 1;
                    q.push(make_pair(nxtx, nxty));
                    dis[nxtx][nxty] = min(dis[nxtx][nxty], dis[curx][cury]+1);
                }
            }
        }
        
        return -1;
    }	

};
