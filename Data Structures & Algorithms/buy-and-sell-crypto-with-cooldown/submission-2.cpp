class Solution {
public:
    int solve(vector<int>& prices, int ind, bool canBuy,vector<vector<int>>& dp) {
        if (ind >= prices.size()) return 0;
        if(dp[ind][canBuy]!=-1) return dp[ind][canBuy];
        if (canBuy) {
            int buy=-prices[ind]+solve(prices,ind+1,false,dp);
            int skip = solve(prices, ind + 1, true,dp);
            return dp[ind][canBuy]=max(buy, skip);
        } 
        int sell = prices[ind]+solve(prices,ind+2,true,dp); 
        int skip = solve(prices, ind + 1, false,dp);
        return dp[ind][canBuy]=max(sell, skip);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices, 0, true,dp);
    }
};