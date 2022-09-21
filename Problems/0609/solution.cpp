/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/find-duplicate-file-in-system/
 *	Runtime: 292ms
 *	language: C++
*/
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (auto s : paths) {
            stringstream ss(s);
            string prefix, file;
            ss >> prefix;
            while (ss >> file) {
                auto cut = file.find("(");
                string content = file.substr(cut);
                file.erase(cut);
                mp[content].push_back(prefix+'/'+file);
            }
        }
        for (auto x:mp) {
            if (x.second.size() > 1)
                res.push_back(x.second);
        }
        return res;
    }
};
