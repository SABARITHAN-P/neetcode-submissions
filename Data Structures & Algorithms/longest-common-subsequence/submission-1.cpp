class Solution {
public:
    int solve(string &s, string &t,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]) return 1+ solve(s,t,i-1,j-1,dp);
        return dp[i][j]= 0+max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
    }
    int longestCommonSubsequence(string &text1, string &text2){
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        return solve(text1,text2,text1.length()-1,text2.length()-1,dp);
    }
};
