class Solution {
public:
    int f(int n, int sum, vector<int>& dp) {
        if (sum == n)
            return 1;

        if (sum > n)
            return 0;

        if (dp[sum] != -1)
            return dp[sum];

        return dp[sum] = f(n, sum + 1, dp) + f(n, sum + 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, 0, dp);
    }
};