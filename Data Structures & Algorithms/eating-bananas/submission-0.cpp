class Solution {
public:
    bool isValid(int mid,vector<int>& piles, int h){
        int cnt=0;
        for(int n:piles){
            cnt += (n + mid - 1) / mid;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(isValid(mid,piles,h)) {
                ans=min(ans,mid);
                high=mid-1;    
            }
            else low=mid+1;
        }
        return ans;
    }
};
