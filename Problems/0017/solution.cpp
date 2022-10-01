/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *	Runtime: 2ms
 *	language: C++
*/
class Solution {
public:
    string mp[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        int idx = 0;
        vector<string> res;
        if (digits.size() == 0)
            return res;
        for (int i = 0; i < mp[digits[idx]-'2'].size(); i++) {
            string init;
            init += mp[digits[idx]-'2'][i];
            q.push(init);
        }
        ++idx;

        while (!q.empty()) {
            int sz = q.size();
            if (q.front().size() == digits.size())
                break;
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < mp[digits[idx]-'2'].size(); j++) {
                    string tmp = cur + mp[digits[idx]-'2'][j];
                    q.push(tmp);
                }
            }
            ++idx;
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;

    }
};
