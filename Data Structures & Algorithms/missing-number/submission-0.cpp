class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum1^=i;
            sum2^=nums[i];
        }
        sum1^=n;
        return sum1^sum2;
    }
};
