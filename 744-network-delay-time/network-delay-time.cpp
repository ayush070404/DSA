class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1 );
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        queue<pair<int, int>> q;
        vector<int> time( n+1 , 1e9);
        time[k] = 0;
        q.push({k , 0});

        while(!q.empty()){
            int node = q.front().first;
            int t = q.front().second;
            q.pop();

            for(auto it: adj[node]){
                int v = it.first;
                int w = it.second;

                if(t + w < time[v]){
                    time[v] = t + w;
                    q.push({v, time[v]});
                }
            }
        }
          int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9) return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
    
};