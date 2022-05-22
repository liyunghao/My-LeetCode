/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/palindromic-substrings/ 
 *	Runtime: 15ms
 *	language: C++
*/

class Solution {
public:
    bool dp[1000][1000]{};
    int countSubstrings(string s) {
        int n = s.size();
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                if (i == 0 || (i == 1 && s[j] ==s[j+i]) ) {
                    dp[j][j+i] = 1;
                    ans++;
                } else {
                    if (s[j] == s[j+i] && dp[j+1][j+i-1]) {
                        dp[j][j+i] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
