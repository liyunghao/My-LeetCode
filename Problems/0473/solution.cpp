/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/matchsticks-to-square/ 
 *	Runtime: 463ms
 *	language: C++
*/

class Solution {
public:
	int sum, mlen;
    vector<int> arr;
    bool dfs(int a, int b, int c, int d, int i) {
        if (a == b && b == c && c == d && d == sum) 
            return true;
        if (a > sum || b > sum || c > sum || d > sum || i >= mlen)
            return false;
        return dfs(a+arr[i], b, c, d, i+1) || dfs(a, b+arr[i], c, d, i+1) || dfs(a, b, c+arr[i], d, i+1) || dfs(a, b, c, d+arr[i], i+1);
    }

    bool makesquare(vector<int>& matchsticks) {
        sum = 0;
        mlen = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end(), std::greater<>());
        arr = matchsticks;
        for (auto x : matchsticks)
            sum += x;
        if (sum % 4)
            return false;
        sum /= 4;
        return dfs(0, 0, 0, 0, 0);
    }
};
