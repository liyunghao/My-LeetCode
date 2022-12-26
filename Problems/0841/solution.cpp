/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/keys-and-rooms
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt = 0, N = rooms.size();
        vector<bool> visited(N, 0);
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            cnt++;
            visited[cur] = 1;
            for (int i = 0; i < rooms[cur].size(); i++) {
                q.push(rooms[cur][i]);
            }
        }
        return cnt == N;

    }
};
