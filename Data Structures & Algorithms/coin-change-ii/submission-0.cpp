class Solution {
public:
    int solve(vector<int>& coins,int amount,int i,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i == 0){
            return (amount % coins[0] == 0);
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick= coins[i]<=amount?solve(coins,amount-coins[i],i,dp):0;
        int not_pick=solve(coins,amount,i-1,dp);
        return dp[i][amount]=pick+not_pick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,amount,coins.size()-1,dp);
    }
};
