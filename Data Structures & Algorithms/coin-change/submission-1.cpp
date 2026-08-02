class Solution {
public:
    int solve(vector<int>& coins, int amount, int ind,vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (ind == coins.size()) return 1e9;
        if (amount < 0) return 1e9;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick = 1 + solve(coins, amount - coins[ind], ind,dp);

        int not_pick = solve(coins, amount, ind + 1,dp);

        return dp[ind][amount]=min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans = solve(coins, amount, 0, dp);

if (ans >= 1e9)
    return -1;

return ans;
    }
};