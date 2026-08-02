class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp){
        if(i==0 and j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=solve(i,j-1,dp);
        int right=solve(i-1,j,dp);
        return dp[i][j]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //return solve(m-1,n-1,dp);
        dp[0][0]=1;
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;

        for(int j = 0; j < n; j++)
            dp[0][j] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int left=0;
                int right=0;
                if(j>0) left=dp[i][j-1];
                if(i>0) right=dp[i-1][j];
                dp[i][j]=left+right;
            }
        }
        return dp[m-1][n-1];
    }
};
