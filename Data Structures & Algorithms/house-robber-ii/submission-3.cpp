class Solution {
public:
    int f(vector<int>& nums,int ind,vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(nums,ind-2,dp);
        int not_pick=0+f(nums,ind-1,dp);
        return dp[ind]=max(pick,not_pick);
    }

    int f2(vector<int>& nums,int ind,vector<int>& dp2){
        if(ind==0) return 0;
        if(ind<0) return 0;
        if(dp2[ind]!=-1) return dp2[ind];
        int pick=nums[ind]+f2(nums,ind-2,dp2);
        int not_pick=0+f2(nums,ind-1,dp2);
        return dp2[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        int max1=f(nums,nums.size()-2,dp);
        int max2=f2(nums,nums.size()-1,dp2);
        return max(max1,max2);
    }
};
