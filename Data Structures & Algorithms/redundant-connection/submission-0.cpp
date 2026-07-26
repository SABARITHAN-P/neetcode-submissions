class DSU {
public:
    vector<int> parent,unionSize;

    DSU(int n){
        parent.resize(n+1,0);
        unionSize.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int u_u=findParent(u);
        int u_v=findParent(v);
        if(u_v == u_u) return;
        if(unionSize[u_v]==unionSize[u_u]){
            parent[u_u]=u_v;
            unionSize[u_v]+=unionSize[u_u];
        }
        else if(unionSize[u_v]>unionSize[u_u]){
            parent[u_u]=u_v;
            unionSize[u_v]+=unionSize[u_u];
        }
        else{
            parent[u_v]=u_u;
            unionSize[u_u]+=unionSize[u_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            if(ds.findParent(u)==ds.findParent(v)) return{u,v};
            ds.unionBySize(u,v);
        }
        return {};
    }
};
