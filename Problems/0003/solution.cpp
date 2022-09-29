/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *	Runtime: 39ms
 *	language: C++
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int res = 0, cur = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = i;
                cur++;
            } else {
                start = max(start, mp[s[i]]);
                cur = i - start;
                mp[s[i]] = i;
                
            }
            res = max(res, cur);
        }
        return res;
    }
};
