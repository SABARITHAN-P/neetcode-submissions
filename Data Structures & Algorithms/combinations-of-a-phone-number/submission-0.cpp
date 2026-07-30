class Solution {
public:
    void solve(vector<string>& ans, vector<string>& mp,
               string& digits, int ind, string& temp) {

        // Base case
        if (ind == digits.length()) {
            ans.push_back(temp);
            return;
        }

        // Letters corresponding to current digit
        string letters = mp[digits[ind] - '0'];

        // Try every letter
        for (char ch : letters) {
            temp.push_back(ch);                  // Choose
            solve(ans, mp, digits, ind + 1, temp); // Explore
            temp.pop_back();                     // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        solve(ans, mp, digits, 0, temp);

        return ans;
    }
};