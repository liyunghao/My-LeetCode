/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/surrounded-regions/
 *	Runtime: 15ms
 *	language: C++
*/
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    vector<vector<int>> visited, flip;
    int M, N;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'X' || visited[x][y])
            return;
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int curx = x + dx[i], cury = y + dy[i];
            if (curx < 0 || curx >= M || cury < 0 || cury >= N)
                continue;
            flip[curx][cury] = 0;
            dfs(board, curx, cury);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        M = board.size(), N = board[0].size();
        visited.resize(M, vector<int>(N, 0));
        flip.resize(M, vector<int>(N, 1));
        for (int i = 0; i < M; i++) {
            flip[i][0] = flip[i][N-1] = 0;
            dfs(board, i, 0);
            dfs(board, i, N-1);
        }
        for (int i = 0; i < N; i++) {
            flip[0][i] = flip[M-1][i] = 0;
            dfs(board, 0, i);
            dfs(board, M-1, i);
        }
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) {
                if (flip[i][j])
                    board[i][j] = 'X';
                    
            }
        return ;
    }
};
