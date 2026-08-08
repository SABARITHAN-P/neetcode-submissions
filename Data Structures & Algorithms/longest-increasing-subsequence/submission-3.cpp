class Solution {
public:
    int solve(vector<int>& nums, int i, int prevIndex, vector<vector<int>>& dp) {
        if(i < 0) return 0;

        if(dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];

        int pick = 0;
        if(prevIndex == -1 || nums[i] < nums[prevIndex])
            pick = 1 + solve(nums, i - 1, i, dp);

        int not_pick = solve(nums, i - 1, prevIndex, dp);

        return dp[i][prevIndex + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, n - 1, -1, dp);
    }
};