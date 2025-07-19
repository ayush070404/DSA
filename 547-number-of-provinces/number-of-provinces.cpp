class Solution {
public:


    void dfs(int node , vector<int> adj[] , vector<int> &vis){
        vis[node] = 1;
        // ls.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];   // ✅ Correct

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(isConnected[i][j] == 1 ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        // vector<int> ls;

        int cnt = 0;

        for(int i = 0; i< n ; i++ ){
            if(!vis[i]){
                dfs(i , adj , vis );
                cnt++;
            }
        }
    return cnt;
    }
};