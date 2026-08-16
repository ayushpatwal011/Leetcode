class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // 1. Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto& t : times) {
            int u = t[0];
            int v = t[1];
            int time = t[2];

            adj[u].push_back({v, time});
        }

        // 2. Dijkstra
        vector<int> res(n + 1, INT_MAX);

        res[k] = 0;

        // {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while(!pq.empty()) {

            int udis = pq.top().first;
            int unode = pq.top().second;

            pq.pop();

            for(auto [vnode, time] : adj[unode]) {

                int newDist = udis + time;

                if(res[vnode] > newDist) {

                    res[vnode] = newDist;

                    pq.push({newDist, vnode});
                }
            }
        }

        // 3. Find maximum shortest distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(res[i] == INT_MAX)
                return -1;
            ans = max(ans, res[i]);
        }

        return ans;
    }
};