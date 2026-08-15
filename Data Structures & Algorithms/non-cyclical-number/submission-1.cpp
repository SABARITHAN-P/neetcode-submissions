class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        int sum=0;
        while(1){
            while(n!=0){
                int rem=n%10;
                sum+=pow(rem,2);
                n/=10;
            }
            if(sum==1) return true;
            if(mp[sum]!=0) return false;
            mp[sum]++;
            n=sum;
            sum=0;
        }
        return false;
    }
};
