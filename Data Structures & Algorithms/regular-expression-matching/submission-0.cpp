class Solution {
public:
    bool solve(string &s, string &p, int i, int j) {

        // Both string and pattern finished
        if (i < 0 && j < 0) return true;

        // Pattern finished but string still left
        if (j < 0) return false;

        // String finished
        if (i < 0) {
            while (j >= 0) {
                if (p[j] != '*') return false;
                j -= 2;           // Skip x*
            }
            return true;
        }

        // Normal character or '.'
        if (p[j] != '*') {
            if (s[i] == p[j] || p[j] == '.')
                return solve(s, p, i - 1, j - 1);
            return false;
        }

        // Case 1: '*' represents zero occurrences
        if (solve(s, p, i, j - 2))
            return true;

        // Case 2: '*' represents one or more occurrences
        if (p[j - 1] == '.' || p[j - 1] == s[i])
            return solve(s, p, i - 1, j);

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, s.size() - 1, p.size() - 1);
    }
};