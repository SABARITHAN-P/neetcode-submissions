struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containKey(char ch) {
        return links[ch-'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for(char ch : word) {
            if(!curr->containKey(ch))
                curr->put(ch, new Node());

            curr = curr->get(ch);
        }

        curr->setEnd();
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string &word, int index, Node* node) {

        if (node == nullptr)
            return false;

        if (index == word.size())
            return node->isEnd();

        char ch = word[index];

        if (ch != '.') {

            if (!node->containKey(ch))
                return false;

            return dfs(word, index + 1, node->get(ch));
        }

        // ch == '.'
        for (int i = 0; i < 26; i++) {

            if (node->links[i] != nullptr) {

                if (dfs(word, index + 1, node->links[i]))
                    return true;
            }
        }

        return false;
    }
};