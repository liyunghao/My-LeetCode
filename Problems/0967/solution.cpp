/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
 *	Runtime: 11ms
 *	language: C++
*/
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        queue<string> q;
        for (int i = 1; i <= 9; i++) {
            q.push(to_string(i));
        }
        
        while (!q.empty()) {
            int sz = q.size();
            int l = q.front().size();
            if (l == n) {
                for (int i = 0; i < sz; i++) {
                    res.push_back(stoi(q.front()));
                    q.pop();
                }
                return res;
            }
                
            for (int i = 0; i < sz; i++) {
                string tmp = q.front();
                q.pop();
                char c = tmp[l-1] - '0';
                if (c+k < 10 && k != 0)
                    q.push(tmp + to_string(c+k));
                if (c-k >= 0)
                    q.push(tmp + to_string(c-k));
            }
        }
        return res;
     }
};

