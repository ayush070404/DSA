class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Step 1: Build reverse graph (Radj)
        vector<vector<int>> Radj(V);
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                Radj[v].push_back(u);  // reverse the edge
                indegree[u]++;         // count outgoing edges (not incoming)
            }
        }

        // Step 2: Kahn's algorithm starting from terminal nodes (outdegree 0)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : Radj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
