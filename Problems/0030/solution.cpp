/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 *	Runtime: 550ms
 *	language: C++
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size();
        int m = words.size();
        unordered_map<string, int> mp, tmp;
        for (auto x:words)
            mp[x]++;
        vector<int> res;
        if (s.size() < n*m)
            return res;
        for (int i = 0; i <= s.size()-n*m; i++) {
            tmp = mp;
            int cnt = 0;
            while (true) {
                string cmp = s.substr(i+cnt*n, n);
                if (tmp.count(cmp) && tmp[cmp]--)
                    cnt++;
                else 
                    break;
                if (cnt == m) {
                    res.push_back(i);
                    break;
                }
            }
            
        }
        return res;
    }
};
