/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/n-queens/
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    vector<vector<string> > res;
    vector<string> g;
    vector<bool> line[4];
    int N;

    void dfs(int r) {
        if (r == N) {
            res.push_back(g);
            return;
        }
        for (int c = 0; c < N; c++) {
            int diag1 = (r+c), diag2 = (r-c+N);
            if (!line[0][r] && !line[1][c] && !line[2][diag1] && !line[3][diag2]) { 
                g[r][c] = 'Q';
                line[0][r] = line[1][c] = line[2][diag1] = line[3][diag2] = 1;
                dfs(r+1);
                g[r][c] = '.';
                line[0][r] = line[1][c] = line[2][diag1] = line[3][diag2] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        string tmp;
        for (int i = 0; i < N; i++)
            tmp += '.';
        g.resize(N, tmp);
        for (int i = 0; i < 4; i++) 
            line[i].resize(2*N, 0);
        dfs(0);
        return res;
    }
};
