class Solution {
private:
    void subset(vector<int>& ds, set<vector<int>>& temp,
                vector<int>& nums, int ind, int n) {

        temp.insert(ds);

        for(int i = ind; i < n; i++) {
            ds.push_back(nums[i]);
            subset(ds, temp, nums, i + 1, n);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        set<vector<int>> temp;
        vector<int> ds;

        subset(ds, temp, nums, 0, nums.size());

        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};