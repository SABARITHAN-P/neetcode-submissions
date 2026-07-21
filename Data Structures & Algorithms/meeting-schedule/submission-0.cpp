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
    static bool cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        if(n == 0) return true;
        int end = intervals[0].end;
        for(int i = 1; i < n; i++) {
            if(intervals[i].start < end)
                return false;
            end = intervals[i].end;
        }
        return true;
    }
};