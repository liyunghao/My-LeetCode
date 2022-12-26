/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-palindrome/
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) 
            mp[c]++;
        int sum = 0, odd = 0;
        for (auto m : mp) {
            if (m.second % 2) {
                odd = 1;
                sum += m.second ^ 1;
            } else {
                sum += m.second;
            }
        }
        sum += odd;
        return sum;
    }
};
