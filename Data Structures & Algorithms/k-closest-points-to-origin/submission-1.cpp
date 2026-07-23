class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int x1=0,y1=0;
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x2=points[i][0];
            int y2=points[i][1];
            double ans=0;
            ans=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
            pq.push({ans,i});
        }

        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};
