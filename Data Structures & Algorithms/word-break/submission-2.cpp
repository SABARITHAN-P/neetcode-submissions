class Solution {
public:
    bool solve(string &s, vector<string>& wordDict, int ind, vector<int>& dp) {
        if (ind == s.length())
            return true;
        if(dp[ind]!=-1) return dp[ind];
        for (int i = ind; i < s.length(); i++) {

            string temp = s.substr(ind, i - ind + 1);
            if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                if (solve(s, wordDict, i + 1,dp))
                    return dp[ind]=true;
            }
        }

        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        return solve(s, wordDict, 0,dp);
    }
};