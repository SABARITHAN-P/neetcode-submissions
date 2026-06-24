class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> row[9];
        vector<int> col[9];
        vector<int> box[9];

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') continue;

                int temp = board[i][j] - '0';
                int b = (i / 3) * 3 + (j / 3);

                if(find(row[i].begin(), row[i].end(), temp) != row[i].end())
                    return false;

                if(find(col[j].begin(), col[j].end(), temp) != col[j].end())
                    return false;

                if(find(box[b].begin(), box[b].end(), temp) != box[b].end())
                    return false;

                row[i].push_back(temp);
                col[j].push_back(temp);
                box[b].push_back(temp);
            }
        }

        return true;
    }
};