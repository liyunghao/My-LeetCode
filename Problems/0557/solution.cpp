/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 *	Runtime: 18ms
 *	language: C++
*/
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res, tmp;
        while (ss >> tmp) {
            reverse(tmp.begin(), tmp.end());
            res += tmp + ' ';
        }
        res = res.substr(0, res.size()-1);
        return res;
    }
};
