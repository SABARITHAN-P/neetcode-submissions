class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().second;
            int dis=q.front().first;
            q.pop();
            if(word==endWord) return dis;
            for(int i=0;i<word.length();i++){
                char original_letter=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push({dis+1,word});
                        st.erase(word);
                    }
                }
                word[i]=original_letter;
            }
        }
        return 0;
    }
};
