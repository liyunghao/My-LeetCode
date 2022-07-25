/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
 *	Runtime: 154ms
 *	language: C++
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size()-1, c = 0;
        while (r >= 0 && c < matrix[0].size()) {
            if (matrix[r][c] < target) {
                c++;
            } else if (matrix[r][c] > target) {
                r--;
            } else {
                return true;
            }
        }
        return false;
    }
};
