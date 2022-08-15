/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/roman-to-integer/
 *	Runtime: 19ms
 *	language: C++
*/
class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, 
                             {'V', 5},
                             {'X', 10},
                             {'L', 50}, 
                             {'C', 100},
                             {'D', 500}, 
                             {'M', 1000}};
        int sum = 0;
        for (int i = s.size()-2; i >= 0; i--) {
            if (mp[s[i]] < mp[s[i+1]])
                sum -= mp[s[i]];
            else 
                sum += mp[s[i]];
        }
        sum += mp[s.back()];
        return sum;
    }
};
