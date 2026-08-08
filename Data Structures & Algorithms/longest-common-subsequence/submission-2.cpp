class Solution {
public:
    // int solve(string &s, string &t,int i,int j,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]) return 1+ solve(s,t,i-1,j-1,dp);
    //     return dp[i][j]= 0+max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
    // }
    // int longestCommonSubsequence(string &text1, string &text2){
    //     vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
    //     return solve(text1,text2,text1.length()-1,text2.length()-1,dp);
    // }


    int longestCommonSubsequence(string &text1, string &text2){
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j]=max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
