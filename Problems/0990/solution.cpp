/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/satisfiability-of-equality-equations/
 *	Runtime: 20ms
 *	language: C++
*/
class Solution {
public:
    struct dSet {
        int ds[26];
        dSet() {
            for (int i = 0; i < 26; i++) {
                ds[i] = i;
            }
        }
        void update(int a, int b) {
            ds[root(b)] = root(a);
        }
        int root(int a) {
            if (ds[a] == ds[ds[a]])
                return ds[a];
            return ds[a] = root(ds[a]);
        }

    };
    bool equationsPossible(vector<string>& equations) {
        dSet S;
        vector<pair<int, int>> v;
        for (auto equ:equations) {
            int a = equ[0]-'a', b = equ[3]-'a';
            if (equ[1] == '=')
                S.update(a, b);
            else
                v.push_back({a, b});
        }
        for (auto x:v) {
            if (S.root(x.first) == S.root(x.second))
                return false;
        }
        return true;
    }
};

