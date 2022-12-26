/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/n-queens-ii/
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    int res;
    vector<bool> line[4];
    int N;

    void dfs(int r) {
        if (r == N) {
            res++;
            return;
        }
        for (int c = 0; c < N; c++) {
            int diag1 = (r+c), diag2 = (r-c+N);
            if (!line[0][r] && !line[1][c] && !line[2][diag1] && !line[3][diag2]) {
                line[0][r] = line[1][c] = line[2][diag1] = line[3][diag2] = 1;
                dfs(r+1);
                line[0][r] = line[1][c] = line[2][diag1] = line[3][diag2] = 0;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        N = n;
        res = 0;
        for (int i = 0; i < 4; i++) 
            line[i].resize(2*N, 0);
        dfs(0);
        return res;
    }
};
