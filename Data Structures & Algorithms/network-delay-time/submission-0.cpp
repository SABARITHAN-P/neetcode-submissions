class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();

            for(auto i:adj[node]){
                int adjNode=i.first;
                int wt=i.second;
                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dis+wt,adjNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
