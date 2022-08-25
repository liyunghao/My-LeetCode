/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leecode.com/problems/ransom-note/t
 *	Runtime: 40ms
 *	language: C++
*/
class Soluton {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (auto x:magazine) {
            mp[x]++;
        }
        for (auto x:ransomNote) {
            if (mp.count(x) && mp[x] > 0)
                mp[x]--;
            else 
                return false;
        }
        return true;
    }
};i
