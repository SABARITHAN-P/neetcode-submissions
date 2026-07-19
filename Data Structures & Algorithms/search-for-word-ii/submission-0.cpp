class Solution {
    struct Node {
        Node* links[26] = {nullptr};
        bool flag = false;
        string word = "";

        bool containKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        void setEnd(string &s) {
            flag = true;
            word = s;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;
    vector<string> ans;

public:
    void addWords(vector<string>& words) {

        for (string &word : words) {

            Node* curr = root;

            for (char ch : word) {

                if (!curr->containKey(ch))
                    curr->put(ch, new Node());

                curr = curr->get(ch);
            }

            curr->setEnd(word);
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {

        char ch = board[i][j];

        if (ch == '#')
            return;

        if (!node->containKey(ch))
            return;

        node = node->get(ch);

        if (node->isEnd()) {
            ans.push_back(node->word);
            node->flag = false;      // Prevent duplicates
        }

        board[i][j] = '#';

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < board.size() &&
                nj >= 0 && nj < board[0].size()) {

                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        root = new Node();

        addWords(words);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};