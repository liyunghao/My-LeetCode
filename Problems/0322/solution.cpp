/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/coin-change/ 
 *	Runtime: 125ms
 *	language: C++
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e6);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        if (dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};
