class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>>& dp){
        if(i==s1.length() and j<s2.length()){
            for(int l=j;l<s2.length();l++){
                if(s2[l]!=s3[k]) return false;
                k++;
            }
            return true;
        }

        if(i<s1.length() and j==s2.length()){
            for(int l=i;l<s1.length();l++){
                if(s1[l]!=s3[k]) return false;
                k++;
            }
            return true;
        }

        if(i==s1.length() and j==s2.length()){
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k] and s2[j]!=s3[k]) if(solve(s1,s2,s3,i+1,j,k+1,dp)) return dp[i][j]=true;
        if(s2[j]==s3[k] and s1[i]!=s3[k]) if(solve(s1,s2,s3,i,j+1,k+1,dp)) return dp[i][j]=true;
        if(s2[j]==s3[k] and s1[i]==s3[k]) return dp[i][j]=solve(s1,s2,s3,i+1,j,k+1,dp) || solve(s1,s2,s3,i,j+1,k+1,dp);

        return dp[i][j]=false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<vector<int>> dp(s1.length(),vector<int> (s2.length(),-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
