class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> right(n);
        right[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(prices[i],right[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prices[i]<right[i]){
                ans=max(ans,right[i]-prices[i]);
            }
        }
        return ans;
    }
};
