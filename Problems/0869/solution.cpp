/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/reordered-power-of-2/
 *	Runtime: 7ms
 *	language: C++
*/
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int sz = int(log10(n));
        int cur = 1;
        vector<int> can;
        while (true) {
            int csz = int(log10(cur));
            if (csz == sz)
                can.push_back(cur);
            else if (csz > sz)
                break;
            cur *= 2;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (auto x:can) {
            string tmp = to_string(x);
            sort(tmp.begin(), tmp.end());
            if (s == tmp)
                return true;
        }
        return false;
    }
};
