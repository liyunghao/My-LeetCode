/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/number-of-matching-subsequences/
 *	Runtime: 294ms
 *	language: C++
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> vec[26];
        for (int i = 0; i < s.size(); i++) {
            vec[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for (auto word:words) {
            int idx = -1;
            bool found = 0;
            int cnt = 0;
            for (auto c:word) {
                int ch = c-'a';
                auto it = upper_bound(vec[ch].begin(), vec[ch].end(), idx);
                if (it == vec[ch].end()) {
                    break;
                } else {
                    idx = *it;
                    if (++cnt == word.size())
                        found = 1;
                }
            }
            if (found)
                res++;
        }
        return res;
    }
};
