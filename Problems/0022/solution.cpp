/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/generate-parentheses/ 
 *	Runtime: 0ms
 *	language: C++
*/

class Solution {
public:
	void perm(int lcnt, int rcnt, string s, int n, vector<string>& vs) {
        if (lcnt + rcnt == 2*n) {
            vs.push_back(s);
            return;
        }
        if (lcnt > rcnt) {
            if (lcnt < n)
                perm(lcnt+1, rcnt, s+'(', n, vs);
            perm(lcnt, rcnt+1, s+')', n, vs);
        } else {
            perm(lcnt+1, rcnt, s+'(', n, vs);
        }
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        perm(0, 0, "", n, vs);
        
        return vs;
    }
};
