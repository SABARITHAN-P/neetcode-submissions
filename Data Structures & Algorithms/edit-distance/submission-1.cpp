class Solution {
public:
    int solve(string s, string t,int i,int j,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j]=0+solve(s,t,i-1,j-1,dp);
        }
        return dp[i][j]=min(1+solve(s,t,i,j-1,dp),min(1+solve(s,t,i-1,j,dp),1+solve(s,t,i-1,j-1,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};
