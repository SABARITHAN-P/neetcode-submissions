/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,char>> nums;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            nums.push_back({intervals[i].start,'E'});
            nums.push_back({intervals[i].end,'D'});
        }
        sort(nums.begin(),nums.end());
        n=nums.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i].second=='E') cnt++;
            else cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
