/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/sort-the-matrix-diagonally/
 *	Runtime: 21ms
 *	language: C++
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int k = m + n - 1;
        int delta = m - 1;
        priority_queue<int, vector<int>, greater<int>> pq[k];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq[j-i+delta].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = pq[j-i+delta].top();
                pq[j-i+delta].pop();
            }
        }
        return mat;
    }
};
