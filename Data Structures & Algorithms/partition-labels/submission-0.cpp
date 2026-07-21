class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s)
            freq[c]++;

        vector<int> ans;
        set<char> active;

        int len = 0;

        for (char c : s) {

            len++;

            active.insert(c);

            freq[c]--;

            // If this is the last occurrence of c,
            // remove it from active characters.
            if (freq[c] == 0)
                active.erase(c);

            // No active characters remain,
            // so we can end this partition.
            if (active.empty()) {
                ans.push_back(len);
                len = 0;
            }
        }

        return ans;
    }
};