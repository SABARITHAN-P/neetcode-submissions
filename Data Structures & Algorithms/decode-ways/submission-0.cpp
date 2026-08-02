class Solution {
public:
    int solve(string &s, int ind, int n, vector<int>& dp) {
        if (ind == n)
            return 1;

        if (s[ind] == '0')
            return 0;

        if(dp[ind]!=-1) return dp[ind];
        int pick1 = solve(s, ind + 1, n,dp);

        int pick2 = 0;
        if (ind + 1 < n &&
            (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))) {
            pick2 = solve(s, ind + 2, n,dp);
        }

        return dp[ind]=pick1 + pick2;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return solve(s, 0, s.length(),dp);
    }
};