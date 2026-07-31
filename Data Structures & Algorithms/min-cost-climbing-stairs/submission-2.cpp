class Solution {
public:
    // int f(vector<int>& cost, int i,vector<int>& dp) {
    //     if (i >= cost.size())
    //         return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     return dp[i]=cost[i] + min(f(cost, i + 1,dp), f(cost, i + 2,dp));
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0);
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
};