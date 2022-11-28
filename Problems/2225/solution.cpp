/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
 *	Runtime: 1540ms
 *	language: C++
*/
class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    #define F first
    #define S second
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pii > mp;
        for (auto match : matches) {
            mp[match[0]].F++;
            mp[match[1]].S++;
        }
        vector<vector<int> > res(2, vector<int>());
        for (auto m : mp) {
            if (m.S.S == 0) {
                res[0].push_back(m.F);
            } else if (m.S.S == 1) {
                res[1].push_back(m.F);
            }
        }
        return res;
    }
};
