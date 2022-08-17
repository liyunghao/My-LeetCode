/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/counting-bits/
 *	Runtime: 3ms
 *	language: C++
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 1);
        res[0] = 0;
        int cur = 2;
        for (int i = 3; i <= n; i++) {
            if (i == 2*cur) {
                cur *= 2;
                res[i] = 1;
            } else {
                res[i] = res[cur] + res[i-cur];
            }
        }
        return res;
    }
};
