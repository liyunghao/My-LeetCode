/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/valid-sudoku/
 *	Runtime: 50ms
 *	language: C++
*/
clas Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> row[9], col[9], box[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 ; j++) {
                if (board[i][j] != '.' ) {
                    row[i].push_back(board[i][j]);
                    col[j].push_back(board[i][j]);  
                    int idx = int(i/3) * 3 + int(j/3);
                    box[idx].push_back(board[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            set<char> r(row[i].begin(), row[i].end());
            set<char> c(col[i].begin(), col[i].end());
            set<char> b(box[i].begin(), box[i].end());
            if (r.size() != row[i].size() || c.size() != col[i].size() || b.size() != box[i].size())
                return false;
        }
        return true;
    }
};s
