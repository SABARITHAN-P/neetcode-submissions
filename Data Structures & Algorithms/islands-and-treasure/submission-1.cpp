class Solution {
private:

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_row=row+drow[i];
                int new_col=col+dcol[i];
                if(new_row>=0 and new_row<n 
                    and new_col>=0 and new_col<m
                        and grid[new_row][new_col]!=-1 ){
                            int temp=grid[new_row][new_col];
                            if(dist+1<temp){
                                grid[new_row][new_col]=dist+1;
                                q.push({{new_row,new_col},dist+1});
                            }
                        }
            }
        }
    }
};
