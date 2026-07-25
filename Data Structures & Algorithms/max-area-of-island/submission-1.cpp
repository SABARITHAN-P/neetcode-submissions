class Solution {
private:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col, int n,int m){
        visited[row][col]=1;
        int temp=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_row=row+drow[i];
            int new_col=col+dcol[i];

            if(new_row>=0 and new_row<n and 
                new_col>=0 and new_col<m and 
                grid[new_row][new_col]==1 and 
                !visited[new_row][new_col]) 
                {
                    temp+=dfs(grid,visited,new_row,new_col,n,m);
            }
        }
        return temp;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int area=0;
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                if(!visited[i][j]){
                    area=max(area,dfs(grid,visited,i,j,n,m));
                }
            }
        }
        return area;
    }
};
