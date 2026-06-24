class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n:nums){
            if(mp[n]!=0) return true;
            mp[n]++;
        }
        return false;
    }
};