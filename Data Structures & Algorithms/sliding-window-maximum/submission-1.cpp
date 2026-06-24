class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        priority_queue<pair<int,int>> pq;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            if (i >= k - 1) {
                while (!pq.empty() && pq.top().second < left) {
                    pq.pop();
                }

                ans.push_back(pq.top().first);
                left++;
            }
        }

        return ans;
    }
};