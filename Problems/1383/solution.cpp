/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/maximum-performance-of-a-team/
 *	Runtime: 173ms
 *	language: C++
*/
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        const int mod = 1e9+7;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> v;
        for (int i = 0; i < speed.size(); i++)
            v.push_back({eff[i], speed[i]});
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first;});
        long long int res = 0, total = 0;
        for (int i = 0; i < v.size(); i++) {
            if (pq.size() == k) {
                total -= pq.top();
                pq.pop();
            }
            pq.push(v[i].second);
            total += v[i].second;
            res = max(res, (total * v[i].first));
        }
        return res % mod;
    }
};

