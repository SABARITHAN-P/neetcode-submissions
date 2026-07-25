class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') visited[i][0]=1;
            if(board[i][m-1]=='O') visited[i][m-1]=1;
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') visited[0][i]=1;
            if(board[n-1][i]=='O') visited[n-1][i]=1;
        }

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=row+drow[i];
                int nc=col+dcol[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m and board[nr][nc]=='O' and !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
