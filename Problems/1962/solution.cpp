/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total
 *	Time complexity: O()
 *	language: C++
*/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < piles.size(); i++) {
            pq.push(piles[i]);
        }

        for (int i = 0; i < k; i++) {
            int cur = pq.top();
            pq.pop();
            pq.push(cur-floor(cur/2));
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
