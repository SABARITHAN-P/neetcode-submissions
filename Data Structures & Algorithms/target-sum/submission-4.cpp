class Solution {
public:
    int solve(vector<int>& nums, int target, int ind, vector<vector<int>>& dp) {
        
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int not_pick = solve(nums, target, ind-1, dp);
        
        int pick = 0;
        if(nums[ind] <= target)
            pick = solve(nums, target - nums[ind], ind-1, dp);
        
        return dp[ind][target] = pick + not_pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        for(int n : nums) tot += n;

        // invalid cases
        if(tot - target < 0 || (tot - target) % 2) return 0;

        int sum = (tot - target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return solve(nums, sum, nums.size()-1, dp);
    }
};