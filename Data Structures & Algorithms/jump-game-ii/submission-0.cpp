class Solution {
public:
    int jump(vector<int>& nums) {
        int far=0,l=0,r=0,cnt=0;
        int n=nums.size();
        while(r<n-1){
            far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+nums[i]);
            }  
            l=r+1;
            r=far;
            cnt++;

        }
        return cnt;
    }
};
