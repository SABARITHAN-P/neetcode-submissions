class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> len;
        vector<int> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int temp=intervals[i][1]-intervals[i][0]+1;
            len.push_back(temp);
        }
        int m=queries.size();
        for(int i=0;i<m;i++){
            int query=queries[i];
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(query>=intervals[j][0] and query<=intervals[j][1]){
                    mini=min(mini,len[j]);
                }
            }
            if(mini==INT_MAX)ans.push_back(-1);
            else ans.push_back(mini);
        }
        return ans;
    }
};
