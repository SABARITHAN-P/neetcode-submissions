class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (!dfs(neigh, node, adj, visited))
                    return false;
            }
            else if (neigh != parent) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);

        // Start DFS from node 0
        if (!dfs(0, -1, adj, visited))
            return false;

        // Check if all nodes were visited (graph is connected)
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};