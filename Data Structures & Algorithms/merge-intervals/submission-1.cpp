class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.empty()) ans.push_back(intervals[i]);
            else{
                int end=ans.back()[1];
                if(end>=intervals[i][0]) ans.back()[1]=max(end,intervals[i][1]);
                else ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
