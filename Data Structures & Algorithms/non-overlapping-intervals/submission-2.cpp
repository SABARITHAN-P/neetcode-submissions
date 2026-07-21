class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int cnt=0;
        //int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                cnt++;
                if(intervals[i][1]<end){
                    //start=intervals[i][0];
                    end=intervals[i][1];
                }
            }
            else{
                //start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return cnt;
    }
};
