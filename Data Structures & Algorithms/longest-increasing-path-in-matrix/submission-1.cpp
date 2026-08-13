class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int find(vector<vector<int>>& grid, int row, int col, int n, int m,vector<vector<int>>& dp) {
        int len = 1; 
        if(dp[row][col]!=-1) return dp[row][col];
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                grid[nr][nc] > grid[row][col]) {

                len = max(len, 1 + find(grid, nr, nc, n, m,dp));
            }
        }

        return dp[row][col]=len;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, find(grid, i, j, n, m,dp));
            }
        }

        return ans;
    }
};