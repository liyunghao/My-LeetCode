/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/pascals-triangle/
 *	Runtime: 0ms
 *	language: C++
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>(30, 0));
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i+1);
            res[i][0] = 1;
            res[i][i] = 1;
        }
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
