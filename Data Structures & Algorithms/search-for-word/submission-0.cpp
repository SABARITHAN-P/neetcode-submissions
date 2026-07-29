class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j,
             string& word, int index) {

        // Entire word matched
        if (index == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        // Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Character mismatch
        if (board[i][j] != word[index])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};