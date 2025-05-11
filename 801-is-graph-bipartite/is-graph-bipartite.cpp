class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = col;

        for (auto neighbor : graph[node]) {
            if (vis[neighbor] == -1) {
                if (!dfs(neighbor, 1 - col, graph, vis))
                    return false;
            } else if (vis[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, 0, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
