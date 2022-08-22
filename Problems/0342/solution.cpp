/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/power-of-four/
 *	Runtime: 5ms
 *	language: C++
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !(n & (n-1)) && (n & 0x55555555);
    }
};
