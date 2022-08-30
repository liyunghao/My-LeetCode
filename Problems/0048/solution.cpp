/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/rotate-image/
 *	Runtime: 2ms
 *	language: C++
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n/2; j++)
                swap(matrix[i][j], matrix[i][n-j-1]);
    }
};
