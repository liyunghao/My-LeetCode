/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/
 *	Runtime: 28ms
 *	language: C++
*/
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        vector<pair<int, char> > v;
        for (auto m : mp) {
            v.push_back({m.second, m.first});
        }
        sort(v.begin(), v.end(), [](const pair<int, char> a, const pair<int, char> b) {
            return a.first > b.first;
        });
        string res;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].first; j++) {
                res += v[i].second;
            }
        }
        return res;
    }
};
