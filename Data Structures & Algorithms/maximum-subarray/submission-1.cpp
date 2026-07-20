class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=0;
        bool isP=false;
        int mini=INT_MIN;
        for(int n:nums){
            if(n>=0) isP=true;
            mini=max(mini,n);
            sum+=n;
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
        }
        return isP?maxi:mini;
    }
};
