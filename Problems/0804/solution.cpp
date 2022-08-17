/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/unique-morse-code-words/
 *	Runtime: 3ms
 *	language: C++
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for (auto word:words) {
            string cur;
            for (auto c:word) {
                cur += table[c-'a'];
            }
            st.insert(cur);
        }
        return st.size();
    }
};
