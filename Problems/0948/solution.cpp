/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/bag-of-tokens/
 *	Runtime: 4ms
 *	language: C++
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int res = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1;
        int cur = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                cur++;
                res = max(res, cur);
            } else if (res > 0) {
                power += tokens[j--];
                cur--;
            } else {
                break;
            }
        }
        
        return res;
    }
};
