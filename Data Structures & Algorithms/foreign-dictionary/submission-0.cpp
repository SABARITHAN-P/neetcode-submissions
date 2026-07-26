class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& pathVis,
             vector<int>& topo) {

        visited[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, adj, visited, pathVis, topo))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        topo.push_back(node);
        return false;
    }

    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        // Mark all characters that appear
        for (auto &word : words) {
            for (char c : word)
                present[c - 'a'] = 1;
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length(), s2.length());

            // Invalid case: "abc" before "ab"
            if (s1.substr(0, len) == s2.substr(0, len) &&
                s1.length() > s2.length())
                return "";

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> visited(26, 0);
        vector<int> pathVis(26, 0);
        vector<int> topo;

        for (int i = 0; i < 26; i++) {

            if (present[i] && !visited[i]) {

                if (dfs(i, adj, visited, pathVis, topo))
                    return "";
            }
        }

        reverse(topo.begin(), topo.end());

        string ans = "";

        for (auto node : topo)
            ans += char(node + 'a');

        return ans;
    }
};