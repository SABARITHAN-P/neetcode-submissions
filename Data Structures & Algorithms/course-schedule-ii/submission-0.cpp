class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& topo) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int neighbor : adj[node]) {
            // Case 1: Neighbor is not visited at all -> run DFS
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, pathVisited, topo)) {
                    return true; // Cycle detected downstream
                }
            } 
            // Case 2: Neighbor is already in the current DFS path -> Cycle!
            else if (pathVisited[neighbor]) {
                return true;
            }
        }
        pathVisited[node] = 0;
        topo.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto req : prerequisites) {
            adj[req[0]].push_back(req[1]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<int> topo;

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited, topo)) {
                    return {}; // Cycle found
                }
            }
        }
        return topo;
    }
};