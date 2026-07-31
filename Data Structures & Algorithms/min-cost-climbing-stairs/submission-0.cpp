class Solution {
public:
    int f(vector<int>& cost, int i,vector<int>& dp) {
        if (i >= cost.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i] + min(f(cost, i + 1,dp), f(cost, i + 2,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(f(cost, 0, dp), f(cost, 1,dp));
    }
};