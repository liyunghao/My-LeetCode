/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/longest-valid-parentheses/
 *	Runtime: 7ms
 *	language: C++
*/

class Solution {
public:
	int longestValidParentheses(string s) {
        using pic = pair<int, char>;
        
        stack<pic> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(make_pair(i, s[i]));
            } else {
                if (st.empty()) {
                    st.push(make_pair(i, s[i]));
                    continue;
                }
                pic tmp = st.top();
                if (tmp.second == '(') {
                    st.pop();
                } else {
                    st.push(make_pair(i, s[i]));
                }
            }
        }
        int cur = s.size(), res = 0;
        while (!st.empty()) {
            pic tmp = st.top(); 
            st.pop();
            res = max(res, cur - tmp.first);
            cur = tmp.first;
        }
        res = max(res, cur+1);
        return res-1;
    }
};
