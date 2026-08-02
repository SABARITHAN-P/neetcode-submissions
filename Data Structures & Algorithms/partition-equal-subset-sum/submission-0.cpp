class Solution {
public:
    bool solve(vector<int>& nums,int target,int ind){
        if(target==0) return  true;
        if(target<0 || ind == nums.size()) return false;
 
        if(solve(nums,target-nums[ind],ind+1)) return true;
        if(solve(nums,target,ind+1)) return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int n:nums) sum+=n;
        if(sum%2) return false;
        return solve(nums,sum/2,0);
    }
};
