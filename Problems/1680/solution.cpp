/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
 *	Runtime: 150ms 
 *	language: C++
*/
class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res = 0;
        const int M = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            int len = log2(i)+1;
            res = (((res << len) % M ) + i) % M;
        }
        return res;
    }
};
