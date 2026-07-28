class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& ds,
                vector<int>& candidates, int target, int sum, int ind) {

        if (sum == target) {
            ans.push_back(ds);
            return;
        }

        if (sum > target || ind >= candidates.size())
            return;

        // Take the current element (can take it again)
        ds.push_back(candidates[ind]);
        helper(ans, ds, candidates, target, sum + candidates[ind], ind);
        ds.pop_back();

        // Skip the current element
        helper(ans, ds, candidates, target, sum, ind + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        helper(ans, ds, candidates, target, 0, 0);

        return ans;
    }
};

