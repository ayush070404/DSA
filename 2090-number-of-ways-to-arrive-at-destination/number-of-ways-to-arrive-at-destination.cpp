class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Use long long for time
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        time[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            for (auto [v, w] : adj[node]) {
                if (t + w < time[v]) {
                    time[v] = t + w;
                    ways[v] = ways[node];
                    pq.push({time[v], v});
                } else if (t + w == time[v]) {
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
