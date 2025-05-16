//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findDelayTime(int n, vector<vector<int>> &edges, int k) {
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        queue<pair<int, int>> q;
        vector<int> time( n, 1e9);
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
        for (int i = 0; i < n; i++) {
            if (time[i] == 1e9) return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e, src;
        cin >> v >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        cin >> src;

        Solution ob;
        int ans = ob.findDelayTime(v, edges, src);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends