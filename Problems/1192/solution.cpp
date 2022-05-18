/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/
 *	Runtime: 1245ms
 *	language: C++
*/

class Solution {
public:
	int cnt = 0;
    vector<bool> visited;
    vector<int> dfn, low;
    vector<vector<int> > result, g;
    void findBridge(int x, int p) {
        visited[x] = 1;
        dfn[x] = low[x] = cnt++;
        
        for (auto k : g[x]) {
            if (k == p) continue;
            if (visited[k])
                low[x] = min(low[x], dfn[k]);
            else {
                findBridge(k, x);
                low[x] = min(low[x], low[k]);
                if (low[k] > dfn[x]) {
                    result.push_back({x, k});
                }
            }
        }
        return;
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n);
        dfn.resize(n);
        low.resize(n);
        g.resize(n);
        for (auto x : connections) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        findBridge(0, -1); 
        return result;
    }

};
