class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int timer=0;
        while(!q.empty()){
                int s=q.size();
            for(int j=0;j<s;j++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_row=row+drow[i];
                    int new_col=col+dcol[i];
                    if(new_row>=0 and new_row<n 
                        and new_col>=0 and new_col<m
                            and grid[new_row][new_col]==1 ){
                                grid[new_row][new_col]=2;
                                q.push({new_row,new_col});
                                fresh--;
                                }
                }
            }
            if(!q.empty()) timer++;
        }
        if(fresh>0) return -1;
        return timer;
    }
};
