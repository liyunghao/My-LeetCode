/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/group-anagrams/
 *	Runtime: 39ms
 *	language: C++
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s = strs;
        for (int i = 0; i < s.size(); i++) {
            sort(s[i].begin(), s[i].end());
        }
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        vector<vector<string>> res(mp.size(), vector<string>());
        int cnt = 0;
        for (auto x:mp) {
            for (int i = 0; i < x.second.size(); i++) {
                res[cnt].push_back(strs[x.second[i]]);
            }
            cnt++;
        }
        return res;
    }
};
