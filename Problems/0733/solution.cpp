/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/flood-fill
 *  Time complexity: O()
 *	language: C++
*/
#define error(a, b) cout << a << ' ' << b << ' ' << image[a][b] << '\n';
#define derr(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
class Solution {
public:
    int m, n; 
    vector<vector<int>> visited;
    bool check (int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dir[5] = {1, 0, -1, 0, 1};
        m = image.size();
        n = image[0].size();
        visited.resize(m, vector<int>(n, 0));
        int orig = image[sr][sc];
        queue<pii > q;
        q.push(mp(sr, sc));

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            int curx = cur.F, cury = cur.S;
            visited[curx][cury] = 1;
            image[curx][cury] = color;
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i];
                int nexty = cury + dir[i+1];
                if (check(nextx, nexty) && image[nextx][nexty] == orig) {
                    q.push(mp(nextx, nexty));
                }
            } 
        }
        return image;
    }
};
