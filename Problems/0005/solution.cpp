/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-palindromic-substring/ 
 *	Runtime: 320ms
 *	language: C++
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000] = {0};
        int res = 0;
        string ress;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (i == 0)
                    dp[j][j] = 1;
                else if (i == 1) {
                    dp[j][j+i] = s[j] == s[j+i] ? 2 : 0;
                } else {
                    dp[j][j+i] = s[j] == s[j+i] && dp[j+1][j+i-1] ? 2 + dp[j+1][j+i-1] : 0;
                }
                if (res < dp[j][j+i]) {
                    res = dp[j][j+i];
                    ress = s.substr(j, i+1);
                }
            }
        }
        return ress;
    }
};
