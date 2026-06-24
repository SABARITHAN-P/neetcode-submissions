class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        vector<int> ans;
        vector<pair<int,int>> temp(mp.begin(),mp.end());
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
