class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        int len = r - l - 1;

        if (len > maxLen) {
            maxLen = len;
            start = l + 1;
        }
    }

    string longestPalindrome(string s) {

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);       
            expand(s, i, i + 1);   
        }

        return s.substr(start, maxLen);
    }
};