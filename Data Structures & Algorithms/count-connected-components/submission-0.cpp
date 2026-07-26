class Solution {
private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                cnt++;
            }
        }

        return cnt;
    }
};
