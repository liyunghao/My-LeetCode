/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/top-k-frequent-elements/
 *	Runtime: 31ms
 *	language: C++
 *	Notes: Performance will be better if using bucket sort
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> res;
        for (auto x:mp) {
            res.push_back(pair(x.second, x.first));
        }
        sort(res.begin(), res.end(), [](pair<int, int> a, pair<int,int> b) { return a.first > b.first; });
        res.resize(k);
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(res[i].second);
        return ans;
    }
};
