class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& ds,
                vector<int>& nums, vector<int>& vis) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (vis[i])
                continue;

            vis[i] = 1;
            ds.push_back(nums[i]);

            helper(ans, ds, nums, vis);

            ds.pop_back();
            vis[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(), 0);

        helper(ans, ds, nums, vis);

        return ans;
    }
};