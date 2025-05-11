class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &order) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfsCheck(neighbor, adj, vis, pathVis, order))
                    return true;
            }
            else if (pathVis[neighbor]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;
        order.push_back(node); // add to order after processing all dependencies
        return false;
    }

    vector<int> findOrder(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0]; // destination
            int v = edge[1]; // prerequisite
            adj[v].push_back(u); // edge: v → u
        }

        vector<int> vis(V, 0), pathVis(V, 0), order;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis, order)) {
                    return {}; // cycle detected → no valid order
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
