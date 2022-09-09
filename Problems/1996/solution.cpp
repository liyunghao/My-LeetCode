/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/submissions/
 *	Runtime: 1496ms
 *	language: C++
*/
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b) { 
                if (a[0] == b[0])
                    return a[1] < b[1];
                return a[0] > b[0];
                }
            );
        int M = 0;
        for (int i = 0; i < properties.size(); i++) {
            if (properties[i][1] < M)
                res++;
            M = max(M, properties[i][1]);
        }
        
        return res;
    }
};
